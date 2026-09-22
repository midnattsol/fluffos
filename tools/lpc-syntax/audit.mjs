// Identifier audit over the grammar-driven LPC tokenizer. This deliberately
// reports candidates rather than claiming whole-program reachability: LPC can
// invoke public symbols by name through applies, add_action(), call_other(),
// call_out(), and function_exists().

import { tokenize } from './tokenizer.mjs';

const SPANISH_WORDS = new Set([
  'abrir', 'accion', 'acciones', 'ataque', 'ataques', 'arma', 'armas',
  'brazo', 'brazos', 'cabeza', 'cadena', 'camino', 'cerrar', 'contador',
  'cuerpo', 'derecha', 'destino', 'destreza', 'enemigo', 'enemigos',
  'fuerza', 'gremio', 'habilidad', 'habilidades', 'hechizo', 'hechizos',
  'indice', 'inteligencia', 'izquierda', 'jugador', 'jugadores', 'lista',
  'mano', 'manos', 'mapa', 'mensaje', 'mensajes', 'muerte', 'nivel',
  'nombre', 'objeto', 'objetos', 'origen', 'pie', 'pierna', 'piernas',
  'puerta', 'puertas', 'raza', 'sabiduria', 'sala', 'salas', 'verdadero',
  'vida',
]);

const DECL_MODIFIERS = new Set([
  'async', 'nomask', 'nosave', 'private', 'protected', 'public', 'static',
  'varargs',
]);

function matchingClose(tokens, openIndex, open, close) {
  let depth = 0;
  for (let index = openIndex; index < tokens.length; index++) {
    if (tokens[index].text === open) depth++;
    if (tokens[index].text === close && --depth === 0) return index;
  }
  return -1;
}

function declarationPrefix(tokens, identifierIndex) {
  let index = identifierIndex - 1;
  while (index >= 0 && tokens[index].text === '*') index--;
  if (index < 0 || tokens[index].kind !== 'type') return null;

  const modifiers = [];
  index--;
  while (index >= 0 && tokens[index].kind === 'modifier') {
    if (DECL_MODIFIERS.has(tokens[index].text)) modifiers.push(tokens[index].text);
    index--;
  }
  return { modifiers };
}

function stringMentions(source, name) {
  const escaped = name.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
  const pattern = new RegExp(`(^|[^A-Za-z0-9_])${escaped}([^A-Za-z0-9_]|$)`);
  return tokenize(source).filter((token) =>
    (token.kind === 'string' || token.kind === 'template' || token.kind === 'textblock') &&
    pattern.test(token.text)).length;
}

function spanishParts(name) {
  return name.toLowerCase().split('_').filter((part) => SPANISH_WORDS.has(part));
}

function diagnostic(declaration, rule, confidence, message) {
  return {
    rule,
    confidence,
    kind: declaration.kind,
    name: declaration.token.text,
    line: declaration.token.line,
    col: declaration.token.col,
    message,
  };
}

export function auditIdentifiers(source) {
  const allTokens = tokenize(source);
  const tokens = allTokens.filter((token) =>
    token.kind !== 'whitespace' && token.kind !== 'comment' && token.kind !== 'directive');
  const declarations = [];
  const identifierCounts = new Map();
  const argumentStarts = new Set();
  let braceDepth = 0;

  for (const token of tokens) {
    if (token.kind === 'identifier') {
      identifierCounts.set(token.text, (identifierCounts.get(token.text) ?? 0) + 1);
    }
  }

  for (let index = 0; index < tokens.length; index++) {
    const token = tokens[index];
    if (token.text === '}') braceDepth--;

    if (token.kind === 'identifier' && !argumentStarts.has(token.start)) {
      const prefix = declarationPrefix(tokens, index);
      if (prefix !== null) {
        const functionDeclaration = braceDepth === 0 && tokens[index + 1]?.text === '(';
        const functionClose = functionDeclaration ? matchingClose(tokens, index + 1, '(', ')') : -1;
        const prototype = functionDeclaration && functionClose !== -1 &&
          tokens[functionClose + 1]?.text === ';';
        declarations.push({
          token,
          kind: prototype ? 'prototype' : functionDeclaration ? 'function' :
            braceDepth === 0 ? 'global' : 'local',
          private: prefix.modifiers.includes('private') || prefix.modifiers.includes('static'),
        });

        if (functionDeclaration) {
          const closeIndex = functionClose;
          if (closeIndex !== -1) {
            for (let argIndex = index + 2; argIndex < closeIndex; argIndex++) {
              const arg = tokens[argIndex];
              if (arg.kind !== 'identifier') continue;
              const argPrefix = declarationPrefix(tokens, argIndex);
              if (argPrefix !== null) {
                argumentStarts.add(arg.start);
                if (!prototype) {
                  declarations.push({ token: arg, kind: 'argument', private: true });
                }
              }
            }
          }
        }
      }
    }

    if (token.text === '{') braceDepth++;
  }

  const findings = [];
  const seen = new Set();
  for (let index = 0; index < allTokens.length; index++) {
    const token = allTokens[index];
    if (!['identifier', 'unknown'].includes(token.kind)) continue;
    let endIndex = index;
    let text = token.text;
    while (endIndex + 1 < allTokens.length &&
           ['identifier', 'unknown'].includes(allTokens[endIndex + 1].kind) &&
           allTokens[endIndex].end === allTokens[endIndex + 1].start) {
      text += allTokens[++endIndex].text;
    }
    index = endIndex;
    if (!/[^\x00-\x7f]/.test(text) || !/^[\p{L}\p{N}_$]+$/u.test(text)) continue;
    findings.push({
      rule: 'non-ascii-code',
      confidence: 'high',
      kind: 'code',
      name: text,
      line: token.line,
      col: token.col,
      message: 'Non-ASCII LPC identifier; identifiers must be ASCII',
    });
  }
  for (const declaration of declarations) {
    const key = `${declaration.kind}:${declaration.token.start}`;
    if (seen.has(key)) continue;
    seen.add(key);

    const name = declaration.token.text;
    const parts = spanishParts(name);
    if (parts.length > 0) {
      findings.push(diagnostic(
        declaration,
        'spanish-identifier',
        'high',
        `Identifier contains Spanish word${parts.length === 1 ? '' : 's'}: ${parts.join(', ')}`,
      ));
    }
    if (/^[A-Za-z]$/.test(name)) {
      findings.push(diagnostic(
        declaration,
        'single-letter-name',
        'medium',
        'Single-letter declaration needs a context-specific name',
      ));
    }

    if ((identifierCounts.get(name) ?? 0) !== 1 || declaration.kind === 'prototype') continue;
    const dynamicReferences = stringMentions(source, name);
    if (dynamicReferences > 0) {
      findings.push(diagnostic(
        declaration,
        'dynamic-reference',
        'unknown',
        `No static use; name occurs in ${dynamicReferences} string literal(s)`,
      ));
    } else if (declaration.kind === 'local') {
      findings.push(diagnostic(
        declaration,
        'unused-local-candidate',
        'high',
        'Declaration has no other identifier-token occurrence in this file',
      ));
    } else if (declaration.kind === 'argument') {
      findings.push(diagnostic(
        declaration,
        'unused-argument-candidate',
        'medium',
        'Argument has no other identifier-token occurrence; callback signatures may require it',
      ));
    } else if (declaration.private) {
      findings.push(diagnostic(
        declaration,
        'possibly-unused-private',
        'medium',
        'Private declaration has no other identifier-token occurrence in this file',
      ));
    } else {
      findings.push(diagnostic(
        declaration,
        'possibly-unused-public',
        'low',
        'Public declaration has no in-file use; inheritance or dynamic callers may use it',
      ));
    }
  }

  return findings.sort((left, right) => left.line - right.line || left.col - right.col ||
    left.rule.localeCompare(right.rule));
}

#!/usr/bin/env node

import { readFileSync, readdirSync, statSync } from 'node:fs';
import { extname, resolve } from 'node:path';
import { auditIdentifiers } from '../audit.mjs';

const args = process.argv.slice(2);
const json = args.includes('--json');
const inputs = args.filter((arg) => arg !== '--json');

if (inputs.length === 0) {
  console.error('Usage: audit-identifiers.mjs [--json] <file-or-directory> [...]');
  process.exit(2);
}

function filesUnder(input) {
  const path = resolve(input);
  if (!statSync(path).isDirectory()) return [path];
  return readdirSync(path, { withFileTypes: true }).flatMap((entry) => {
    if (entry.name.startsWith('.') || entry.name === 'node_modules') return [];
    return filesUnder(`${path}/${entry.name}`);
  });
}

const files = inputs.flatMap(filesUnder)
  .filter((path) => ['.c', '.h', '.lpc'].includes(extname(path)))
  .sort();
const results = [];

for (const file of files) {
  const source = readFileSync(file, 'utf8');
  for (const finding of auditIdentifiers(source)) results.push({ file, ...finding });
}

if (json) {
  console.log(JSON.stringify(results, null, 2));
} else {
  for (const finding of results) {
    console.log(`${finding.file}:${finding.line}:${finding.col}: ${finding.confidence} ` +
      `${finding.rule}: ${finding.name}: ${finding.message}`);
  }
}

process.exitCode = results.some((finding) => finding.confidence === 'high') ? 1 : 0;

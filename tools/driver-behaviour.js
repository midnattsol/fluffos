#!/usr/bin/env node
// driver-behaviour.js -- check what only a live driver process can show.
//
//   node tools/driver-behaviour.js [driver]
//
// The LPC suite runs inside one driver with no player connected, so it cannot
// see process_input over telnet, a file's mode on disk, or the exit status after
// a signal. This boots a small mudlib in a temporary directory on a free port and
// checks them from outside. Registered with ctest as `driver-behaviour`.

'use strict';

const net = require('net');
const fs = require('fs');
const os = require('os');
const path = require('path');
const { spawn } = require('child_process');

const repoRoot = path.resolve(__dirname, '..');
const driverPath = path.resolve(process.argv[2] || path.join(repoRoot, 'build/src/driver'));
const root = fs.mkdtempSync(path.join(os.tmpdir(), 'fluffos-behaviour-'));
const lib = path.join(root, 'lib');

const ENDLESS_SQL =
  'WITH RECURSIVE n(x) AS (SELECT 1 UNION ALL SELECT x + 1 FROM n) SELECT count(*) FROM n';

const FILES = {
  'master.lpc': `
#pragma modern_types
object connect() { return new("/user"); }
int valid_read(string path, mixed caller, string fn) { return 1; }
int valid_write(string path, mixed caller, string fn) { return 1; }
string get_root_uid() { return "root"; }
string get_bb_uid() { return "bb"; }
string creator_file(string path) { return "root"; }
mixed valid_database(object ob, string action, mixed *info) {
  if (sizeof(info) && strsrch(info[0], "/*false*/") != -1) return false;
  if (sizeof(info) && strsrch(info[0], "/*null*/") != -1) return null;
  return true;
}
mixed valid_ffi(string op, mixed arg, object caller) {
  if (stringp(arg) && strsrch(arg, "ANSWER_FALSE") != -1) return false;
  if (stringp(arg) && strsrch(arg, "ANSWER_NULL") != -1) return null;
  return true;
}
`,
  'sefun.lpc': 'void placeholder() {}\n',
  'include/globals.h': '',
  'user.lpc': `
#pragma modern_types
private void report_denied(string name, mixed failure) {
  write(sprintf("%s=%s\\n", name,
    failure && strsrch(sprintf("%O", failure), "security violation") != -1 ? "denied" : "allowed"));
}

void logon() {
  enable_commands();
  add_action("do_hit", "hit");
  write("READY\\n");
}

int do_hit(string arg) {
  write("VERB RAN " + arg + "\\n");
  return 1;
}

void async_finished(mixed result) {
  debug_message("ASYNC DONE");
}

mixed process_input(string line) {
  int db;
  switch (line) {
    case "hit answer-true": return true;
    case "hit answer-one": return 1;
    case "hit answer-false": return false;
    case "hit answer-null": return null;
    case "hit answer-zero": return 0;
    case "files":
      file_write("/data/existing.txt", "new");
      file_write("/data/created.txt", "new");
      write("FILES DONE\\n");
      return 1;
    case "gates":
#if efun_defined(sqlite_query)
      db = db_connect("", "/data/gates.db", "", __USE_SQLITE3__);
      report_denied("database_true", catch(sqlite_query(db, "SELECT 1", ({}), 1, 16)));
      report_denied("database_false", catch(sqlite_query(db, "SELECT 1 /*false*/", ({}), 1, 16)));
      report_denied("database_null", catch(sqlite_query(db, "SELECT 1 /*null*/", ({}), 1, 16)));
      db_close(db);
#endif
#if efun_defined(ffi_load)
      report_denied("ffi_true", catch(ffi_load("/nonexistent/ANSWER_TRUE")));
      report_denied("ffi_false", catch(ffi_load("/nonexistent/ANSWER_FALSE")));
      report_denied("ffi_null", catch(ffi_load("/nonexistent/ANSWER_NULL")));
#endif
      write("GATES DONE\\n");
      return 1;
    case "sqlite?":
#if efun_defined(sqlite_query)
      write("SQLITE YES\\n");
#else
      write("SQLITE NO\\n");
#endif
      return 1;
#if efun_defined(sqlite_query)
    case "async-endless":
      db = db_connect("", "/data/async.db", "", __USE_SQLITE3__);
      async_db_exec(db, "${ENDLESS_SQL}", (: async_finished :));
      write("ASYNC STARTED\\n");
      return 1;
    case "endless":
      set_eval_limit(0x7fffffff);
      set_eval_limit(0);
      db = db_connect("", "/data/endless.db", "", __USE_SQLITE3__);
      debug_message("QUERY RUNNING");
      sqlite_query(db, "${ENDLESS_SQL}", ({}), 1, 16);
      return 1;
#endif
    case "mark":
      write("MARK\\n");
      return 1;
  }
  return 0;
}
`,
};

let failures = 0;
function check(condition, name, detail) {
  if (condition) {
    console.log(`ok   ${name}`);
  } else {
    failures++;
    console.log(`FAIL ${name}${detail === undefined ? '' : `: ${detail}`}`);
  }
}

function waitFor(read, needle, timeoutMs, what) {
  return new Promise((resolve, reject) => {
    const started = Date.now();
    const timer = setInterval(() => {
      if (read().includes(needle)) {
        clearInterval(timer);
        resolve();
      } else if (Date.now() - started > timeoutMs) {
        clearInterval(timer);
        reject(new Error(`timed out waiting for ${what || needle}; have:\n${read().slice(-600)}`));
      }
    }, 20);
  });
}

function freePort() {
  return new Promise((resolve, reject) => {
    const server = net.createServer();
    server.on('error', reject);
    server.listen(0, '127.0.0.1', () => {
      const { port } = server.address();
      server.close(() => resolve(port));
    });
  });
}

class Mud {
  constructor(port) {
    this.stdout = '';
    this.exit = null;
    this.child = spawn(driverPath, [path.join(root, 'config.toml')], {
      cwd: root,
      stdio: ['ignore', 'pipe', 'pipe'],
      env: { ...process.env, LC_ALL: 'C' },
    });
    this.child.stdout.on('data', (data) => { this.stdout += data; });
    this.child.stderr.on('data', (data) => { this.stdout += data; });
    this.exited = new Promise((resolve) => {
      this.child.on('exit', (code, signal) => {
        this.exit = { code, signal };
        resolve(this.exit);
      });
    });
    this.port = port;
  }

  async connect() {
    this.output = '';
    const started = Date.now();
    while (true) {
      try {
        this.socket = await new Promise((resolve, reject) => {
          const socket = net.connect(this.port, '127.0.0.1', () => resolve(socket));
          socket.on('error', reject);
        });
        break;
      } catch (error) {
        if (this.exit) throw new Error(`driver exited during boot:\n${this.stdout.slice(-800)}`);
        if (Date.now() - started > 20000) throw error;
        await new Promise((resolve) => setTimeout(resolve, 50));
      }
    }
    this.socket.on('data', (data) => { this.output += data.toString('latin1'); });
    this.socket.on('error', () => {});
    await waitFor(() => this.output, 'READY', 10000);
  }

  // Sends a line and returns only the output it produced, up to `until`.
  async send(line, until = 'MARK') {
    this.output = '';
    this.socket.write(`${line}\r\n`);
    if (until === 'MARK') this.socket.write('mark\r\n');
    await waitFor(() => this.output, until, 10000, `${until} after "${line}"`);
    return this.output;
  }

  stop() {
    if (!this.exit) this.child.kill('SIGKILL');
    if (this.socket) this.socket.destroy();
    return this.exited;
  }
}

async function exitsWithin(mud, milliseconds) {
  return Promise.race([
    mud.exited,
    new Promise((resolve) => setTimeout(() => resolve(null), milliseconds)),
  ]);
}

async function checkProcessInput(mud) {
  // A true answer means process_input handled the line, so the verb must not run.
  for (const [answer, runs] of [['true', false], ['one', false], ['false', true], ['null', true],
    ['zero', true]]) {
    const output = await mud.send(`hit answer-${answer}`);
    check(output.includes('VERB RAN') === runs,
      `process_input answering ${answer} ${runs ? 'falls through to the verb' : 'handles the line'}`,
      JSON.stringify(output));
  }
}

async function checkFileModes(mud) {
  const existing = path.join(lib, 'data/existing.txt');
  fs.writeFileSync(existing, 'old');
  fs.chmodSync(existing, 0o640);
  await mud.send('files', 'FILES DONE');
  const mode = (file) => fs.statSync(path.join(lib, 'data', file)).mode & 0o777;
  check(mode('existing.txt') === 0o640, 'file_write keeps the mode of a file it replaces',
    mode('existing.txt').toString(8));
  check(mode('created.txt') === (0o666 & ~process.umask()), 'file_write gives a new file the umask mode',
    mode('created.txt').toString(8));
  check(fs.readFileSync(existing, 'utf8') === 'new', 'file_write replaced the contents');
}

async function checkGates(mud, hasSqlite) {
  const output = await mud.send('gates', 'GATES DONE');
  const expect = (name, value) => check(output.includes(`${name}=${value}`), `${name} is ${value}`, output);
  if (hasSqlite) {
    expect('database_true', 'allowed');
    expect('database_false', 'denied');
    expect('database_null', 'denied');
  }
  if (output.includes('ffi_true')) {
    expect('ffi_true', 'allowed');
    expect('ffi_false', 'denied');
    expect('ffi_null', 'denied');
  }
}

async function checkAsyncDeadline(mud) {
  const started = Date.now();
  await mud.send('async-endless', 'ASYNC STARTED');
  const mark = await mud.send('mark', 'MARK');
  check(mark.includes('MARK'), 'driver answers while an endless async query runs');
  await waitFor(() => mud.stdout, 'ASYNC DONE', 20000, 'the async query deadline');
  check(Date.now() - started < 15000, 'an endless async query ends at its deadline');
}

async function checkSignalDuringQuery(mud) {
  mud.socket.write('endless\r\n');
  await waitFor(() => mud.stdout, 'QUERY RUNNING', 10000);
  await new Promise((resolve) => setTimeout(resolve, 300));
  mud.child.kill('SIGTERM');
  const exit = await exitsWithin(mud, 10000);
  check(exit && exit.code === 0, 'SIGTERM ends a driver stuck in an endless query', JSON.stringify(exit));
}

async function checkSignalWhenIdle(port) {
  const mud = new Mud(port);
  try {
    await mud.connect();
    mud.child.kill('SIGTERM');
    const exit = await exitsWithin(mud, 10000);
    check(exit && exit.code === 0, 'SIGTERM shuts an idle driver down cleanly', JSON.stringify(exit));
  } finally {
    await mud.stop();
  }
}

async function main() {
  for (const [name, contents] of Object.entries(FILES)) {
    const file = path.join(lib, name);
    fs.mkdirSync(path.dirname(file), { recursive: true });
    fs.writeFileSync(file, contents);
  }
  fs.mkdirSync(path.join(lib, 'data'));
  fs.mkdirSync(path.join(lib, 'log'));
  const port = await freePort();
  fs.writeFileSync(path.join(root, 'config.toml'), `
name = "behaviour"
mudlib_directory = ${JSON.stringify(lib)}
log_directory = "/log"
master_file = "/master.lpc"
simulated_efun_file = "/sefun.lpc"
global_include_file = "<globals.h>"
include_directories = ["/include"]
maximum_evaluation_cost = 2000000

[[ports]]
type = "telnet"
port = ${port}
`);

  const mud = new Mud(port);
  try {
    await mud.connect();
    const hasSqlite = (await mud.send('sqlite?', 'SQLITE')).includes('SQLITE YES');
    await checkProcessInput(mud);
    await checkFileModes(mud);
    await checkGates(mud, hasSqlite);
    if (hasSqlite) {
      await checkAsyncDeadline(mud);
      await checkSignalDuringQuery(mud);
    }
  } finally {
    await mud.stop();
  }
  await checkSignalWhenIdle(port);
}

main()
  .catch((error) => {
    failures++;
    console.log(`FAIL ${error.message}`);
  })
  .finally(() => {
    fs.rmSync(root, { recursive: true, force: true });
    console.log(failures ? `${failures} check(s) failed` : 'all checks passed');
    process.exit(failures ? 1 : 0);
  });

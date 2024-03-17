const path = require("path");
const net = require("net");
const { spawn } = require('child_process');

ExecutePath = __dirname;
    var cmd = (process.platform == 'darwin'? 'sh': process.platform == 'win32'? ExecutePath + '\\sphpserver\\sphpserver-win.exe': ExecutePath + '/sphpserver/sphpserver-linux');
async function findPort(ip, port) {
    let myself = this;
    let result = false;
    try {
        await new Promise((resolve, reject) => {
            const s = net.createConnection({ port: port, host: ip })
            s.on('connect', function () {
                s.end();
                reject();
            });
            s.on('error', err => {
                result = true;
                resolve();
            });
        });
        return result;
    } catch (e) {
        return false;
    }

}

async function findPort2(host = 'localhost') {
    let port = 0;
    for (let c = 8000; c < 8100; c++) {
        let v1 = await findPort(host, c);
        if (v1 === true) {
            port = c;
            break;
        }
    }
    return port;
}

async function runSphpServer(host = 'localhost', port = 0, ssl = 0, www = '') {
    let ls = null;
    try {
        if (port == 0) port = await findPort2(host);
        ls = spawn(cmd, ["--proj", www, "--host", host, "--port", port]);
        ls.stdin.setEncoding('utf-8');
        ls.stdout.setEncoding('utf-8');
        ls.stdout.on('data', function (line) {
            console.log(line);
        });
        ls.stderr.on('data', function (data) {
            console.error('stderr: ' + data);
        });

        ls.on('exit', function (code, signal) {
            console.log('exit code ' + code);
            process.exit();
        });

    } catch (e) {
        console.error(e);
        process.exit();
    } finally {
        return { "host": host, "port": port, "SphpServer": ls };
    }

}

module.exports = { "SphpServerPath": cmd, "run_sphp_server": runSphpServer };

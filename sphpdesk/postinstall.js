const path = require("path");
const net = require("net");
const { spawn } = require('child_process');

ExecutePath = __dirname;
    var cmd = (process.platform == 'darwin'? 'sh': process.platform == 'win32'? ExecutePath + '\\bin\\win-x32\\php\\php.exe': ExecutePath + '/bin/linux-x64/php/php');

async function install_composer_pack() {
    let ls = null;
    try {
        ls = spawn(cmd, [ExecutePath + "/bin/composer", "install"]);
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
    }

}
install_composer_pack();


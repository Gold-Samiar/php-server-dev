<?php

class apache2 extends Sphp\tools\NativeApp{
    private $childprocess = null;
    private $settings = array();
    
    public function onstart() {
        //$auth = new Auth();
        //$auth->AuthenticateSVAR("USERM");
        //SphpBase::sphp_request()->setUseServerVariables();
        //echo SphpBase::sphp_request()->session("logType");
        //$this->createProcess("php p5.php");
        //$this->createProcess("vlcpkg.exe");
        //$this->auth2 = "Yes";
        //$a1 = array(SphpBase::sphp_settings()->server_path . '/' .$this->apppath . "/njs/mobiledev/start.js","demodata");
        //$this->createProcess("node", $a1);
        $libfolder = realpath(SphpBase::sphp_settings()->server_path . '/lib');
        $libfolder = str_replace('\\','/',$libfolder);
        // write apache config
        $this->writeConfig($libfolder);
        // run apache        
        $this->createProcess($libfolder . '/apache2/bin/httpd.exe');
        $this->childprocess = "apache2";
    }
    public function page_event_stopapache2($evtp){
        $this->exitMe();
    }
    // sphpserver onprocesscreate event handler
    public function page_event_s_onprocesscreate($evtp,$bdata){
        $this->childprocess = "apache2";
        $alink = "http://localhost:8080";
        $this->JSServer->addJSONJSBlock('$("#btnap").attr("disabled","disabled");$("#btnap2").removeAttr("disabled");$("#alink").attr("href","'. $alink .'").html("'. $alink .'");');
        $this->send2UIConsole("Apache2 is Running");
    }
    /* Child Process event handler, here apache is not friendly exe.
    so it will not send back any data. so this will not trigger. no use
    */
    public function page_event_c_onprocessready($evtp,$bdata) {
        $this->send2UIConsole("Apache2 is Ready to Run");
    }
    // display everything on console of child process.
    public function onconsole($data2,$type) {
        //$wcon = $this->Client->request("bdata")["wcon"];
        //$cok = $this->Client->server("HTTP_SEC_WEBSOCKET_KEY");
        //$this->send2UIConsole($data2);
        
        $data = json_decode($data2,true);
        if(is_array($data) && isset($data["msg"])){
            $msg = $data["msg"];
        }else{
            $msg = $data2;
        }
        switch($type){
            case 'i':{
                //$this->JQuery->info($msg);
                $this->send2UIConsole($msg);
                break;
            }
            case 'e':{
                $this->send2UIConsole($msg);
                //$this->JQuery->error($msg);
                break;
            }
            case 'w':{
                $this->send2UIConsole($msg);
                //$this->JQuery->warn($msg);
                break;
            }
            default:{
                $this->JQuery->log($msg);
                break;
            }
        }
        $this->JSServer->addJSONReturnBlock("");
        $this->sendAll();
        
    }
    // WS new connection handler
    public function onwscon($conobj) {
        // return msg to Web Socket handler
        //$this->JSServer->addJSONReturnBlock("ret: new Connection " . $conobj['conid']);
        //$this->sendAll();
    }
    // WS disconnection handler
    public function onwsdiscon($conobj) {
        // return msg to Web Socket handler
        //$this->JSServer->addJSONReturnBlock("ret: DisConnection " . $conobj['conid']);
        //$this->sendAll();
    }
    // trigger on quit of native app
    public function onquit(){
        //$this->sendCommand("quit");
        $this->JSServer->addJSONJSBlock('$("#btnap2").attr("disabled","disabled");$("#btnap").removeAttr("disabled");');
        $this->send2UIConsole("Apache2 Manager Stopped");
      //  $this->JSServer->addJSONReturnBlock("quit");
    //    $this->JSServer->flush();
    }
    // trigger on quit of child process
    public function oncquit(){
            $this->childprocess = null;
            $this->send2UIConsole("Apache2 Process Stopped");
            $this->exitMe();
    }

    private function send2UIConsole($msg){
        $this->JSServer->addJSONReturnBlock($msg);
      //$this->JSServer->addJSONHTMLBlock("nconsole", '<p>' .$msg . '</p>');
        $this->sendAll();
    }
    public function writeConfig($libfolder) {
        $strData = file_get_contents($libfolder . "/settings/portablephp.json");
        $strData = str_replace("{path}", $libfolder,$strData);
        $this->settings = json_decode($strData,true);

        $this->writePHPConfig($libfolder);
        $this->writeMySQLConfig($libfolder);

        $strData = file_get_contents($libfolder . "/settings/httpd.conf");
        $strData = str_replace("{path}", $this->settings["binpath"],$strData);
        $strData = str_replace("{port}", $this->settings["http_port"],$strData);
        $strData = str_replace("{rootdir}",$this->settings["wwwdir"],$strData);
        file_put_contents($libfolder . "/apache2/conf/httpd.conf", $strData);
    }
    public function writePHPConfig($libfolder){
        $strData = file_get_contents($libfolder . "/settings/php.ini");
        $strData = str_replace("{path}", $this->settings["binpath"],$strData);
        $strData = str_replace("{mysqlport}", $this->settings["mysql_port"],$strData);
        file_put_contents($libfolder . "/php/php.ini", $strData);
    }
    public function writeMySQLConfig($libfolder)
    {
        $strData = file_get_contents($libfolder . "/settings/my.ini");
        $strData = str_replace("{path}", $this->settings["binpath"],$strData);
        $strData = str_replace("{port}",  $this->settings["mysql_port"],$strData);
        file_put_contents($libfolder . "/mysql/my.ini", $strData);
    }
}

<?php

class mysql2 extends Sphp\tools\NativeApp{
    private $childprocess = null;
    
    public function onstart() {
        $libfolder = realpath(SphpBase::sphp_settings()->server_path . '/lib');
        // run mysql 
        $a1 = array("--defaults-file=" .$libfolder . "/mysql/my.ini");
        $this->createProcess($libfolder . '/mysql/bin/mysqld.exe',$a1);
        $this->childprocess = "mysql";
    }
    public function page_event_stopmysql($evtp){
        $this->exitMe();
    }
    // sphpserver onprocesscreate event handler
    public function page_event_s_onprocesscreate($evtp,$bdata){
        $this->childprocess = "mysql";
        $this->send2UIConsole("Mysql is Running");
    }
    /* Child Process event handler, here apache is not friendly exe.
    so it will not send back any data. so this will not trigger. no use
    */
    public function page_event_c_onprocessready($evtp,$bdata) {
        $this->send2UIConsole("Mysql is Ready to Run");
    }
    // display everything on console of child process.
    public function onconsole($data2,$type) {
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
    public function onquit(){
        $this->send2UIConsole("Mysql Manager Stopped");
    }
    // trigger on quit of child process
    public function oncquit(){
            $this->childprocess = null;
            $this->send2UIConsole("Mysql Process Stopped");
            $this->exitMe();
    }

    private function send2UIConsole($msg){
        $this->JSServer->addJSONReturnBlock($msg);
        $this->sendAll();
    }
}

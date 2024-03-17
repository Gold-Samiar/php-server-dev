<?php
registerApp("index",__DIR__ ."/apps/index.app");

// native apps
registerApp("apache2",__DIR__ ."/apps/apache2.app");
registerApp("mysql",__DIR__ ."/apps/mysql2.app");


// find app in apps folder
if(!SphpBase::sphp_router()->isRegisterCurrentRequest()){
    $pth = PROJ_PATH . "/apps/" . SphpBase::sphp_router()->getCurrentRequest() . ".app";
    if(is_file($pth)) SphpBase::sphp_router()->registerCurrentRequest($pth);
}


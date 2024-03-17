<!DOCTYPE html>
<html>
    <head lang="en">
        <meta http-equiv="Content-Type" content="text/html; charset=utf8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <?php SphpBase::SphpJsM()::addBootStrap();  echo SphpBase::sphp_api()->getHeaderHTML(); ?>
    </head>
    <body>
        <div class="container-fluid">
            <div class="row"><div class="col">        
                <?php SphpBase::$dynData->render(); ?>
            </div></div>
        </div>

        <?php  echo SphpBase::sphp_api()->getFooterHTML(); 
        echo SphpBase::sphp_api()->traceError(true) . SphpBase::sphp_api()->traceErrorInner(true); ?>
    </body>
</html>
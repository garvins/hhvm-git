<?hh

require_once 'Gen.hh';
require_once 'Parser.hh';
require_once 'Type.hh';

$argv = $_SERVER['argv'];
$files = array();

$filePattern = "/.h$/";

if ($handle = opendir(dirname(__FILE__)."/../libgit2/include/git2")) {
    while (false !== ($entry = readdir($handle))) {
        if (preg_match($filePattern, $entry) && $entry != "inttypes.h") {
            $files[$entry] = dirname(__FILE__) ." /../libgit2/include/git2/" . $entry;
        }
    }
    closedir($handle);
}

if ($handle = opendir(dirname(__FILE__)."/../libgit2/include/git2/sys")) {
    while (false !== ($entry = readdir($handle))) {
        if (preg_match($filePattern, $entry)) {
            $files["sys_" . $entry] = dirname(__FILE__) ." /../libgit2/include/git2/sys/" . $entry;
        }
    }
    closedir($handle);
}

$parser = new Parser();
$fileConsts = array();
$fileFuncList = array();

foreach ($files as $file => $path)
{
    $fileContent = file_get_contents($path);
    
    $structs = $parser->parseStructs($fileContent);
    foreach ($structs as $name) {
        /* filter option structs */
        if (preg_match("/\w+_opt\w*/", $name)) {
            Type::$knownTypes[HackType::ARR][] = $name;
        } else if (in_array($name, Type::$knownTypes[HackType::RESOURCE])) {
            // todo handling double names ...
        } else {
            Type::$knownTypes[HackType::RESOURCE][] = $name;
        }
        
        // todo
    }
    
    $callbacks = $parser->parseCallbacks($fileContent);
    foreach ($callbacks as $name) {
        if (in_array($name, Type::$knownTypes[HackType::CALLABLE])) {
            // todo handling double names ...
        } else {
            Type::$knownTypes[HackType::CALLABLE][] = $name;
        }
        // todo
    }
    
    $consts = array();
    $constants = $parser->parseConstants($fileContent);
    /* add parsed constants to knownTypes */
    foreach ($constants as $name => $values) {
        if (in_array($name, Type::$knownTypes[HackType::INT])) {
            // todo handling double names ...
        } else {
            Type::$knownTypes[HackType::INT][] = $name;
        }
        
        $consts[$name] = $values;
    }
    $fileConsts[$file] = $consts;
    
    if(isset($argv[1]) && $argv[1] != $file) {
        continue;
    }
    
    $functions = $parser->parseFunctions($fileContent);
    
    if (count($functions)) {
        $fileFuncList[$file] = $functions;
    }
}

$generator = new Gen();
$generator->generateFuncFiles($fileFuncList);
$generator->generateExtRegFile($fileConsts);
$generator->generateExtHeader();
$generator->generateConfigCmake();
$generator->generateSysLib();
$generator->postUnkownTypes();

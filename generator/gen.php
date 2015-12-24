<?hh

require_once 'Gen.hh';
require_once 'Parser.hh';
require_once 'Type.hh';

$argv = $_SERVER['argv'];
$files = array();

$git2_h = (string) file_get_contents(dirname(__FILE__)."/../libgit2/include/git2.h");

$match = array();
if (preg_match_all("/#include \"[^\"]+\/([^\"]+?)\"/", $git2_h, $match)) {
    foreach ($match[1] as $fileName) {
        $files[$fileName] = "../libgit2/include/git2/".$fileName;
    }
}

$parser = new Parser();
$fileConsts = array();
$fileFuncList = array();

foreach ($files as $file => $path)
{
    $consts = array();
    $structs = $parser->parseStructs($file);
    
    foreach ($structs as $name) {
        if (in_array($name, Type::$knownTypes[HackType::RESOURCE])) {
            // todo handling double names ...
        } else {
            Type::$knownTypes[HackType::RESOURCE][] = $name;
        }
        // todo
    }
    
    $constants = $parser->parseConstants($file);
    
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
    
    $functions = $parser->parseFunctions($file);
    $fileFuncList[$file] = $functions;
}


$generator = new Gen();
$generator->generateFuncFiles($fileFuncList);
$generator->generateSysLib($fileConsts);
$generator->postUnkownTypes();

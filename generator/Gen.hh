<?hh //strict

require_once dirname(__FILE__) . '/Header.hh';
require_once dirname(__FILE__) . '/Source.hh';

class Gen {
    
    public function __construct() {
    }
    
    public function postUnkownTypes() : void {
        foreach (Type::$unknownTypes as $type) {
            echo $type ."\n";
        }
    }
    
    public function generateFuncFiles(array<string, array<Func>> $fileFuncList) : void {
        foreach ($fileFuncList as $file => $functions) {
            $header = new Header(preg_replace("/\.[\s\S]*/", "", $file));
            $header->setFunctions($functions);
            $header->print(true);
            
            $source = new Source(preg_replace("/\.[\s\S]*/", "", $file));
            $source->setFunctions($functions);
            $source->print();
        }
    }
    
    public function generateExtRegFile(array<string, array<string, array<string>>> $enums) : void {
        if ($handle = opendir(dirname(__FILE__)."/../src")) {
            $pattern = "/(\w+)\s+HHVM_FUNCTION\((\w+)((?:,[\s\S]+?)*)?\);/";
            $ignore = "/([^h]|[^\.]h)$/";
            
            $content = "#include \"ext_git2.h\"\n\n";
            
            $entries = $this->getFileList();
            
            foreach ($entries as $entry) {
                $content.= "#include \"src/". $entry ."\"\n";
            }
            
            // todo add preprocessor hhvm version check
            $content .= "\n#define HHVM_RC_INT_SAME(const_name)                  \\\n" .
            	"Native::registerConstant<KindOfInt64>(                \\\n" .
           	 	"makeStaticString(#const_name), (int64_t)const_name);\n\n" .
            	"namespace HPHP {\n\n" .
        		"IMPLEMENT_RESOURCE_ALLOCATION(Git2Resource)\n\n" .
            	"static class Git2Extension : public Extension  {\n" .
            	"  public:\n" .
            	"    Git2Extension() : Extension(\"git2\") {}\n" .
            	"    virtual void moduleInit() {\n";
            
            foreach ($entries as $entry) {
                $match = array();
                $file = file_get_contents(dirname(__FILE__)."/../src/".$entry);
                    
                if (preg_match_all($pattern, $file, $match)) {
                    $content .= "\n\n      // --------------- ". $entry . " ---------------\n";
                        
                    foreach ($match[3] as $k => $v) {
                        $content .= "      HHVM_FE(". $match[2][$k] .");\n";
                    }
                }
            }
            
            $content .= "\n\n      /*            ---- CONSTANTS ----\n" .
            	"       * register constants of all known enums in libgit2\n" .
            	"       * todo: register only necessary constants!!!\n" .
            	"       */\n";
            
            /* add constants to register file */
            foreach ($enums as $name => $enum) {
                if (count($enum) > 0) {
                    $content .= "\n\n      // --------------- " . $name . " ---------------\n";
                    
                    foreach ($enum as $enumName => $constants) {
                        $content .= "\n      // --------------- " . $enumName . " ---------------\n";
                        
                        foreach ($constants as $constant) {
                            $content .= "      HHVM_RC_INT_SAME(" . $constant . ");\n";
                        }
                    }
                }
            }
            
            $content .= "\n\n      loadSystemlib();\n" .
            	"  }\n\n" .
				"  virtual void requestInit() {\n" .
				"    git_threads_init();\n" .
				"  }\n\n" .
				"  virtual void requestShutdown() {\n" .
				"    git_threads_shutdown();\n" .
				"  }\n" .
            	"} s_git2_extension;\n\n" .
            	"HHVM_GET_MODULE(git2)\n} // namespace HPHP\n";
            
            file_put_contents(dirname(__FILE__)."/../ext_git2.cpp", $content);
        }
    }
        
	public function generateExtHeader() : void {
        /* build file for handeling of git2 resources */
        $content = "#ifndef EXT_GIT2_H\n" .
            "#define EXT_GIT2_H\n\n" .
            "#define HHVM_GIT2_V(git2, type) git2->type\n" .
        	"#define HHVM_GIT2_V_N(git2, type) (git2 && git2->type) ? git2->type : NULL\n\n" .
        	"#include \"hphp/runtime/ext/extension.h\"\n\n" .
            "#include \"git2.h\"\n" .
            "#include \"git2/cred_helpers.h\"\n" .
            "#include \"git2/odb_backend.h\"\n" .
            "#include \"git2/trace.h\"\n" .
            "#include \"git2/sys/commit.h\"\n" .
            "#include \"git2/sys/config.h\"\n" .
            "#include \"git2/sys/filter.h\"\n" .
            "#include \"git2/sys/index.h\"\n" .
            "#include \"git2/sys/odb_backend.h\"\n" .
            "#include \"git2/sys/refdb_backend.h\"\n" .
            "#include \"git2/sys/reflog.h\"\n" .
            "#include \"git2/sys/refs.h\"\n" .
            "#include \"git2/sys/repository.h\"\n\n" .
            "#include <stdlib.h>\n\n" .
            "enum hhvm_git2_resource_type {\n";
            
        foreach (Type::$knownTypes[HackType::RESOURCE] as $resName) {
            $content .= "\t" . strtoupper("HHVM_GIT2_TYPE_" . preg_replace("/^git_/", "", $resName)) . ",\n";
        }
        
        $content .= "};\n\n" .
            "\nnamespace HPHP {\n" .
            "class Git2Resource : public SweepableResourceData {\n" .
            "public:\n" .
        	"\tDECLARE_RESOURCE_ALLOCATION(Git2Resource)\n" .
        	"\tCLASSNAME_IS(\"git2\");\n" .
            "\tGit2Resource() {}\n" .
        	"\tvirtual ~Git2Resource() {}\n" .
        	"\tconst String& o_getClassNameHook() const override { return classnameof(); }\n" .
        	"\tvoid o_setResourceId(int64_t id) { hdr()->setRawId(id); }\n" .
            "\tenum hhvm_git2_resource_type type;\n" .
            "\tunion {\n";
            
        foreach (Type::$knownTypes[HackType::RESOURCE] as $resName) {
            $content .= "\t\t" . $resName . " " . preg_replace("/^git_/", "*", $resName) . ";\n";
        }
            
        $content .= "\t};\n" .
            "};\n" .
    		"}\n" .
            "#endif /* EXT_GIT2_H */\n";
            
        file_put_contents(dirname(__FILE__)."/../ext_git2.h", $content);
    }
    
    public function generateSysLib() : void {
        $entries = $this->getFileList();
        $pattern = "/(\w+)\s+HHVM_FUNCTION\((\w+)((?:,[\s\S]+?)*)?\);/";
        
        $content = "<?hh\n";
        
        foreach ($entries as $entry) {
            $match = array();
            $file = file_get_contents(dirname(__FILE__)."/../src/".$entry);
            
            if (preg_match_all($pattern, $file, $match)) {
                $content .= "\n\n// --------------- ". $entry . " ---------------\n";
                
                foreach ($match[3] as $k => $v) {
                    $v = ltrim($v, ',');
                    $v = explode(",\n", $v);
                    
                    $content .= "\n<<__Native>>\n";
                    $content .= "function ".$match[2][$k]."(";
                    $size = 10 + strlen($match[2][$k]);
                    
                    foreach ($v as $k1 => $v1) {
                        if($k1 > 0) {
                            $content .= ",\n" . str_repeat(" ", $size);
                        }
                        
                        $match2 = array();
                        
                        if (preg_match("/^([\s\S]+?)\s+\**(\w+)(\s*=\s*\w+)?$/", $v1, $match2)) {
							$hackType = Type::hhvmTypeToHack(trim($match2[1]));
							
							$content .= (count($match2) > 3 ? "?" : "") . $hackType . " $" . $match2[2];
							
							if (count($match2) > 3) {
								switch ($hackType) {
									case HackType::BOOL:
										$content .= " = false";break;
									case HackType::INT:
										$content .= " = 0";break;
									case HackType::FLOAT:
										$content .= " = 0.0";break;
									case HackType::STRING:
										$content .= " = \"\"";break;
									case HackType::ARR:
										$content .= " = array()";break;
									default:
										$content .= " = null";
								}
							}
                        } else {
                            if (strlen(trim($v1) > 0)) {
                                $content .= "ERROR";
                            }
                        }
                    }
                    
                    $content .= "): ". Type::hhvmTypeToHack(trim($match[1][$k])) . ";\n";
                }
            }
        }
        
        file_put_contents(dirname(__FILE__)."/../ext_git2.php", $content);
    }
    
    public function generateConfigCmake() : void {
        $entries = $this->getFileList();
        
        /* build config.cmake file */
        $content = "HHVM_ADD_INCLUDES(git2 ./libgit2/include ./ ./src/. ./../../../..)\n\n" .
        	"HHVM_EXTENSION(git2 ext_git2.cpp";
        
        foreach ($entries as $entry) {
            $content .= " src/" . str_replace(".h", ".cpp", $entry);
        }
        
        $content .= ")\n\n" .
        	"HHVM_SYSTEMLIB(git2 ext_git2.php)\n";
        $content .= "target_link_libraries(git2 \${CMAKE_SOURCE_DIR}/libgit2/build/libgit2.a)";
        file_put_contents(dirname(__FILE__)."/../config.cmake", $content);
    }
    
    private function getFileList() : array<string> {
        $entries = array();
        
        if ($handle = opendir(dirname(__FILE__)."/../src")) {
            $ignore = "/([^h]|[^\.]h)$/";
            
            while (false !== ($entry = readdir($handle))) {
                if (!preg_match($ignore, $entry)) {
                    $entries[] = $entry;
                }
            }
            
            closedir($handle);
        }
        
        return $entries;
    }
}
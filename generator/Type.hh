<?hh

enum HackType : string {
    VOID     = "void";
    BOOL     = "bool";
    INT      = "int";
    FLOAT    = "float";
    STRING   = "string";
    ARR      = "array";
    RESOURCE = "resource";
    CALLABLE = "???";
}

class Type {
    private string $type = "";
    
    public function __construct(string $type) {
        $this->type = $type;
    }
    
    private function typeToHackType() : HackType {
        $void      = array("void");
        $bool      = array("bool");
        $int       = array("int", "uint32_t");
        $float     = array();
        $string    = array("char");
        $arr       = array();
        $ressource = array();
        $callable  = array();
        
        if (in_array($this->type, $void)) {
            return HackType::VOID;
        } else if (in_array($this->type, $bool)) {
            return HackType::BOOL;
        } else if (in_array($this->type, $int)) {
            return HackType::INT;
        } else if (in_array($this->type, $string)) {
            return HackType::STRING;
        } else if (in_array($this->type, $arr)) {
            return HackType::ARR;
        } else if (in_array($this->type, $ressource)) {
            return HackType::RESOURCE;
        } else if (in_array($this->type, $callable)) {
            return HackType::CALLABLE;
        } else {
            echo "\n". $this->type . " is an unkown type.";
            return HackType::VOID;
        }
    }
    
    public function getType() : string {
        return $this->type;
    }
    
    public function setType($type) : this {
        $this->type = $type;
        return $this;
    }
    
    public function getHHVMType() : string {
        $hackType = $this->typeToHackType();
        $hhvmType = "";
        
        switch ($hackType) {
            case HackType::VOID :
                $hhvmType = "void"; break;
            case HackType::BOOL :
                $hhvmType = "bool"; break;
            case HackType::INT :
                $hhvmType = "int64_t"; break;
            case HackType::FLOAT :
                $hhvmType = "double"; break;
            case HackType::STRING :
                $hhvmType = "const String&"; break;
            case HackType::ARR :
                $hhvmType = "const Array&"; break;
            case HackType::RESOURCE :
                $hhvmType = "const Resource&"; break;
            case HackType::CALLABLE :
                $hhvmType = "???"; break;
        }
        
        return $hhvmType;
    }
    
    public function getHHVMReturnType() : string {
        $hackType = $this->typeToHackType();
        $hhvmType = "";
        
        switch ($hackType) {
            case HackType::VOID :
                $hhvmType = "void"; break;
            case HackType::BOOL :
                $hhvmType = "bool"; break;
            case HackType::INT :
                $hhvmType = "int64_t"; break;
            case HackType::FLOAT :
                $hhvmType = "double"; break;
            case HackType::STRING :
                $hhvmType = "String"; break;
            case HackType::ARR :
                $hhvmType = "Array"; break;
            case HackType::RESOURCE :
                $hhvmType = "Resource"; break;
            case HackType::CALLABLE :
                $hhvmType = "???"; break;
        }
        
        return $hhvmType;
    }
}

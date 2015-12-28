<?hh //strict

enum HackType : string {
    VOID     = "void";
    BOOL     = "bool";
    INT      = "int";
    FLOAT    = "float";
    STRING   = "string";
    ARR      = "array";
    RESOURCE = "resource";
    CALLABLE = "mixed";
}

class Type {
    public static array<HackType, array<string>> $knownTypes = array(
			HackType::VOID     => array("void"),
            HackType::BOOL     => array("bool"),
			HackType::INT      => array(
				"int", "int32_t", "int64_t",
				"size_t",
				"unsigned", "unsigned int", "uint32_t"),
            HackType::FLOAT    => array(),
            HackType::STRING   => array("char", "unsigned char"),
            HackType::ARR      => array(),
            HackType::RESOURCE => array(),
            HackType::CALLABLE => array(),
        );
    
    public static array<string, string> $unknownTypes = array();
    
    private string $type = "";
    
    public function __construct(string $type) {
        $this->type = $type;
    }
    
    public function getType() : string {
        return $this->type;
    }
    
    public function setType(string $type) : this {
        $this->type = $type;
        return $this;
    }
    
    public static function hhvmTypeToHack(string $hhvmType): HackType {
        $void      = array("void");
        $bool      = array("bool");
        $int       = array("int64_t");
        $float     = array("double");
        $string    = array("const String&", "String");
        $arr       = array("const Array&", "Array");
        $ressource = array("const Resource&", "Resource");
        $callable  = array("const Variant&", "Variant");
        
        if (in_array($hhvmType, $void)) {
            return HackType::VOID;
        } else if (in_array($hhvmType, $bool)) {
            return HackType::BOOL;
        } else if (in_array($hhvmType, $int)) {
            return HackType::INT;
        } else if (in_array($hhvmType, $string)) {
            return HackType::STRING;
        } else if (in_array($hhvmType, $arr)) {
            return HackType::ARR;
        } else if (in_array($hhvmType, $ressource)) {
            return HackType::RESOURCE;
        } else if (in_array($hhvmType, $callable)) {
            return HackType::CALLABLE;
        } else {
            Type::$unknownTypes[$hhvmType] = $hhvmType;
            return HackType::VOID;
        }
    }
    
    public function typeToHackType() : HackType {
        if (in_array($this->type, Type::$knownTypes[HackType::VOID])) {
            return HackType::VOID;
        } else if (in_array($this->type, Type::$knownTypes[HackType::BOOL])) {
            return HackType::BOOL;
        } else if (in_array($this->type, Type::$knownTypes[HackType::INT])) {
            return HackType::INT;
        } else if (in_array($this->type, Type::$knownTypes[HackType::FLOAT])) {
            return HackType::FLOAT;
        } else if (in_array($this->type, Type::$knownTypes[HackType::STRING])) {
            return HackType::STRING;
        } else if (in_array($this->type, Type::$knownTypes[HackType::ARR])) {
            return HackType::ARR;
        } else if (in_array($this->type, Type::$knownTypes[HackType::RESOURCE])) {
            return HackType::RESOURCE;
        } else if (in_array($this->type, Type::$knownTypes[HackType::CALLABLE])) {
            return HackType::CALLABLE;
        } else {
            Type::$unknownTypes[$this->type] = $this->type;
            return HackType::VOID;
        }
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
                $hhvmType = "const Variant&"; break;
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
                $hhvmType = "Variant"; break;
        }
        
        return $hhvmType;
    }
}

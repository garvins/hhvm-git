<?hh

require_once 'Parameter.hh';
require_once 'Type.hh';

class Func {
    private string $name = "";
    private Type $returnType;
    private array<Parameter> $params = array();

    public function __construct(string $name) {
        $this->name = $name;
		$this->returnType = new Type("void");
		$this->params = array();
    }

    public function getName() : string {
        return $this->name;
    }

    public function getReturnType() : Type {
        return $this->returnType;
    }

    public function getParams() : array<Parameter> {
        return $this->params;
    }

    public function setName(string $name) : this {
        $this->name = $name;
        return $this;
    }

    public function setReturnType(Type $returnType) : this {
        $this->returnType = $returnType;
        return $this;
    }

    public function setParams(array<Parameter> $params) : this {
        $this->params = params;
        return $this;
    }

    public function add2Params(Parameter $param) : this {
        if (is_array($this->params)) {
            $this->params[] = $param;
        } else {
            $this->params = array($param);
        }

        return $this;
    }
}

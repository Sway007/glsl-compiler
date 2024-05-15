interface IPassCodeGenResult {
  name: string;
  vertexSource: string;
  fragmentSource: string;
}

interface ISubShaderCodeGenResult {
  name: string;
  passList: IPassCodeGenResult[];
}

interface IShaderCodeGenResult {
  name: string;
  subShaderList: ISubShaderCodeGenResult[];
}

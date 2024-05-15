import { ASTNode } from './AST';
import SymbolTable from './SymbolTable';
import { RenderQueueType } from './engineType';

export enum EShaderDataType {
  Pass,
  SubShader,
  Shader,
}

export abstract class ShaderData {
  abstract dataType: EShaderDataType;

  settingRenderState?: ASTNode.GLRenderStateDeclarator;
  symbolTable: SymbolTable;

  renderQueueType: string | RenderQueueType;

  BlendState?: ASTNode.GLRenderStatePropList;
  DepthState?: ASTNode.GLRenderStatePropList;
  StencilState?: ASTNode.GLRenderStatePropList;
  RasterState?: ASTNode.GLRenderStatePropList;

  tags: Record<string, string | number | boolean> = {};
}

export class GLPassShaderData extends ShaderData {
  dataType = EShaderDataType.Pass;

  vertexMain: ASTNode.FunctionDefinition;
  fragmentMain: ASTNode.FunctionDefinition;
}

export class GLSubShaderData extends ShaderData {
  dataType = EShaderDataType.SubShader;

  passList: (ASTNode.GLUsePassDeclaration | ASTNode.GLPassProgram)[] = [];
}

export class GLShaderData extends ShaderData {
  dataType = EShaderDataType.Shader;

  subShaderList: ASTNode.GLSubShaderProgram[] = [];
}

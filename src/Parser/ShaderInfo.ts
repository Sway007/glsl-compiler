import { EKeyword } from '../Lexer/TokenType';
import { ASTNode } from './AST';
import { RenderQueueType } from './engineType';

export enum EShaderDataType {
  Pass,
  SubShader,
  Shader,
}

export abstract class ShaderData {
  abstract dataType: EShaderDataType;

  renderQueueType: string | RenderQueueType;

  settingRenderState?: ASTNode.GLRenderStateDeclarator;

  BlendState?: ASTNode.GLRenderStatePropList;
  DepthState?: ASTNode.GLRenderStatePropList;
  StencilState?: ASTNode.GLRenderStatePropList;
  RasterState?: ASTNode.GLRenderStatePropList;
}

export class GLPassShaderData extends ShaderData {
  dataType = EShaderDataType.Pass;

  vertexMain: ASTNode.FunctionProtoType;
  fragmentMain: ASTNode.FunctionProtoType;
}

export class GLSubShaderData extends ShaderData {
  dataType = EShaderDataType.SubShader;

  passList: (ASTNode.GLUsePassDeclaration | ASTNode.GLPassProgram)[] = [];
}

export class GLShaderData extends ShaderData {
  dataType = EShaderDataType.Shader;
}

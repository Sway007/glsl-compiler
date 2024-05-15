import { ENonTerminal } from '../Grammar/GrammarSymbol';
import Token from '../Lexer/Token';
import { EKeyword } from '../Lexer/TokenType';
import { Logger } from '../Logger';
import { ASTNode, TreeNode } from '../Parser/AST';
import { ESymbolType } from '../Parser/SymbolTable';
import { ParserUtils } from '../Parser/Utis';
import { NodeChild } from '../Parser/types';
import { VisitorContext } from './VisitorContext';

export abstract class CodeGenVisitor {
  logger = new Logger('CodeGen');
  context = new VisitorContext();

  abstract visitPassProgram(node: ASTNode.GLPassProgram): IPassCodeGenResult;

  defaultCodeGen(children: NodeChild[]) {
    let ret: string[] = [];
    for (const child of children) {
      if (child instanceof Token) {
        ret.push(child.lexeme);
      } else {
        ret.push(child.codeGen(this));
      }
    }
    return ret.join(' ');
  }

  visitShaderProgram(node: ASTNode.GLShaderProgram): IShaderCodeGenResult {
    const ret: IShaderCodeGenResult = { name: node.name, subShaderList: [] };
    for (const subShader of node.shaderData.subShaderList) {
      ret.subShaderList.push(this.visitSubShaderProgram(subShader));
    }
    return ret;
  }

  visitSubShaderProgram(
    node: ASTNode.GLSubShaderProgram
  ): ISubShaderCodeGenResult {
    const ret: ISubShaderCodeGenResult = { name: node.name, passList: [] };
    for (const pass of node.shaderData.passList) {
      if (pass instanceof ASTNode.GLPassProgram) {
        ret.passList.push(this.visitPassProgram(pass));
      }
    }
    return ret;
  }

  visitPostfixExpression(node: ASTNode.PostfixExpression) {
    if (node.children.length === 3) {
      const { context } = this;

      const postExpr = node.children[0] as ASTNode.PostfixExpression;

      const prop = node.children[2];

      if (prop instanceof Token) {
        if (context.isAttributeStruct(<string>postExpr.type)) {
          context.referenceAttribute(prop.lexeme);
          return prop.lexeme;
        } else if (context.isVaryingStruct(<string>postExpr.type)) {
          context.referenceVarying(prop.lexeme);
          return prop.lexeme;
        }

        return `${postExpr.codeGen(this)}.${prop.lexeme}`;
      } else {
        return `${postExpr.codeGen(this)}.${prop.codeGen(this)}`;
      }
    }
    return this.defaultCodeGen(node.children);
  }

  visitVariableIdentifier(node: ASTNode.VariableIdentifier): string {
    if (node.symbolInfo?.isGlobalVariable) {
      this.context.referenceGlobal(node.lexeme, ESymbolType.VAR);
    }
    return node.lexeme;
  }

  visitFunctionCall(node: ASTNode.FunctionCall): string {
    const call = node.children[0] as ASTNode.FunctionCallGeneric;
    if (call.fnSymbol) {
      this.context._referencedGlobals.set(call.fnSymbol.lexeme, call.fnSymbol);
    }
    return this.defaultCodeGen(node.children);
  }

  visitStatementList(node: ASTNode.StatementList): string {
    const children = node.children as TreeNode[];
    if (node.children.length === 1) {
      return children[0].codeGen(this);
    } else {
      return `${children[0].codeGen(this)}\n${children[1].codeGen(this)}`;
    }
  }

  visitSingleDeclaration(node: ASTNode.SingleDeclaration): string {
    const type = node.typeSpecifier.type;
    if (typeof type === 'string') {
      this.context.referenceGlobal(type, ESymbolType.STRUCT);
    }
    return this.defaultCodeGen(node.children);
  }

  visitDeclaration(node: ASTNode.Declaration): string {
    const child = node.children[0];
    if (
      child instanceof ASTNode.InitDeclaratorList &&
      child.typeInfo.typeLexeme === this.context.varyingStruct?.ident?.lexeme
    ) {
      return '';
    }
    return this.defaultCodeGen(node.children);
  }

  visitFunctionProtoType(node: ASTNode.FunctionProtoType): string {
    this.context._curFn = node;
    return this.defaultCodeGen(node.children);
  }

  visitFunctionDefinition(node: ASTNode.FunctionDefinition): string {
    this.context._curFn = undefined;
    return this.defaultCodeGen(node.children);
  }

  visitJumpStatement(node: ASTNode.JumpStatement): string {
    const cmd = node.children[0] as Token;
    if (cmd.type === EKeyword.RETURN) {
      const expr = node.children[1];
      if (expr instanceof ASTNode.Expression) {
        const returnVar =
          ParserUtils.unwrapNodeByType<ASTNode.VariableIdentifier>(
            expr,
            ENonTerminal.variable_identifier
          );
        if (
          returnVar?.typeInfo?.type ===
          this.context.varyingStruct?.ident?.lexeme
        ) {
          return '';
        }
      }
    }
    return this.defaultCodeGen(node.children);
  }

  visitFunctionIdentifier(node: ASTNode.FunctionIdentifier): string {
    return this.defaultCodeGen(node.children);
  }
}

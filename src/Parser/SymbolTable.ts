import Token from '../Lexer/Token';
import { Logger } from '../Logger';
import { ASTNode, TreeNode } from './AST';
import SematicAnalyzer from './SemanticAnalyzer';
import { SymbolType } from './types';

export enum ESymbolType {
  VAR,
  FN,
  STRUCT,
}

abstract class SymbolInfo {
  readonly symType: ESymbolType;
  /** variable type */
  readonly symDataType?: SymbolType;
  readonly astNode?: TreeNode;
  readonly lexeme: string;

  referenced = false;

  constructor(
    lexeme: string,
    type: ESymbolType,
    astNode?: TreeNode,
    dataType?: SymbolType
  ) {
    this.lexeme = lexeme;
    this.symType = type;
    this.symDataType = dataType;
    this.astNode = astNode;
  }
}

export class VarSymbol extends SymbolInfo {
  declare astNode?:
    | ASTNode.Initializer
    | ASTNode.GLRenderStateDeclaration
    | undefined;

  constructor(
    lexeme: string,
    dataType: SymbolType,
    initAst?: ASTNode.Initializer
  ) {
    super(lexeme, ESymbolType.VAR, initAst, dataType);
  }
}

export class FnSymbol extends SymbolInfo {
  declare astNode: ASTNode.FunctionProtoType;

  constructor(lexeme: string, astNode: ASTNode.FunctionProtoType) {
    super(lexeme, ESymbolType.FN, astNode);
  }
}

export class StructSymbol extends SymbolInfo {
  declare astNode: ASTNode.StructSpecifier;

  constructor(lexeme: string, astNode: ASTNode.StructSpecifier) {
    super(lexeme, ESymbolType.STRUCT, astNode);
  }
}

type SymbolTypeInfer<T extends ESymbolType> = T extends ESymbolType.FN
  ? FnSymbol
  : T extends ESymbolType.STRUCT
  ? StructSymbol
  : VarSymbol;

export default class SymbolTable {
  parent: SymbolTable | null = null;
  table: Map<string, SymbolInfo[]> = new Map();
  private functionProtoType?: ASTNode.FunctionProtoType;

  get returnType() {
    return this.functionProtoType?.returnType.type;
  }

  constructor(sa: SematicAnalyzer) {
    const lastSymbol = sa.semanticStack[sa.semanticStack.length - 1];
    if (lastSymbol instanceof ASTNode.FunctionProtoType) {
      this.functionProtoType = lastSymbol;
    }
  }

  private logger = new Logger('symbol table');

  insert(sm: SymbolInfo) {
    const { lexeme } = sm;

    const entry = this.table.get(lexeme) ?? [];
    if (
      sm.symType === ESymbolType.FN &&
      entry.findIndex(
        (item) =>
          // TODO: overload function signature equality check
          item.symType === ESymbolType.FN && item.symDataType === sm.symDataType
      ) !== -1
    ) {
      this.logger.log(Logger.RED, 'function symbol exist:', lexeme);
      return;
    } else if (entry.findIndex((item) => item.symType === sm.symType) !== -1) {
      this.logger.log(Logger.RED, 'symbol exist:', lexeme);
      return;
    }
    entry.push(sm);
    this.table.set(lexeme, entry);
  }

  lookup<T extends ESymbolType>(
    lexeme: string,
    type: T,
    signature?: T extends ESymbolType.FN ? string : never
  ): SymbolTypeInfer<T> | null {
    const entry = this.table.get(lexeme);
    if (entry?.length) {
      if (type !== ESymbolType.FN || signature == undefined) {
        const found = entry.find((item) => item.symType === type);
        if (found) {
          return found as any;
        }
      } else {
        // TODO: function signature equality check
        throw 'not implemented';
      }
    }
    if (this.parent) return this.parent.lookup(lexeme, type, signature);
    return null;
  }
}

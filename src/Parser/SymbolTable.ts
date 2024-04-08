import Token from '../Lexer/Token';
import { EType, TreeNode } from './AST';

export class SymbolInfo {
  readonly ast: TreeNode;
  readonly type: EType;

  constructor(type: EType, ast: TreeNode) {
    this.type = type;
    this.ast = ast;
  }
}

export default class SymbolTable {
  parent: SymbolTable | null = null;
  table: Map<string, SymbolInfo[]> = new Map();

  newSymbol(id: string, sm: SymbolInfo) {
    const entry = this.table.get(id) ?? [];
    const existSm = entry.find((item) => item.type === sm.type);
    if (existSm) {
      console.error('redefined at', existSm.ast.location);
    } else {
      entry.push(sm);
      this.table.set(id, entry);
    }
  }

  getSymbol(id: string, type?: EType): SymbolInfo | null {
    const entry = this.table.get(id);
    if (!entry?.length) {
      return this.parent?.getSymbol(id, type) ?? null;
    }
    if (type == undefined) return entry[0];
    const ret = entry.find((item) => item.type === type);
    if (!ret) {
      return this.parent?.getSymbol(id, type) ?? null;
    }
    return ret;
  }
}

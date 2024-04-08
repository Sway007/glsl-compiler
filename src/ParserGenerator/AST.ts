import { ENonTerminal, Terminal } from '../Grammar/GrammarSymbol';
import Production from '../Grammar/Production';

export class TreeNode {
  children: (TreeNode | Terminal)[] = [];
  get grammarSymbol(): ENonTerminal {
    return this.production.goal;
  }
  readonly production: Production;
  value: any;

  constructor(production: Production) {
    this.production = production;
  }

  addChild(node: TreeNode | Terminal) {
    this.children.push(node);
  }
}

export type Tree = TreeNode;

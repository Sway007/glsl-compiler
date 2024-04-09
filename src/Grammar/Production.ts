// import { ETokenType, opPrecedence } from '../Lexer/TokenType';
import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';
import GrammarUtils from './Utils';

export default class Production {
  private static _id = 0;
  static pool: Map<number, Production> = new Map();

  readonly goal: ENonTerminal;
  readonly derivation: GrammarSymbol[];
  readonly id: number;

  constructor(goal: ENonTerminal, derivation: GrammarSymbol[]) {
    this.goal = goal;
    this.derivation = derivation;
    this.id = Production._id++;
    Production.pool.set(this.id, this);
  }

  // getReducePrecedence() {
  //   for (let i = this.derivation.length - 1; i >= 0; i--) {
  //     if (opPrecedence.has(<ETokenType>this.derivation[i])) {
  //       return opPrecedence.get(<ETokenType>this.derivation[i]);
  //     }
  //   }
  // }

  toString() {
    const deriv = this.derivation
      .map((gs) => GrammarUtils.toString(gs))
      .join('|');
    return `${ENonTerminal[this.goal]} :=> ${deriv}`;
  }
}

import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';
import GrammarUtils from './Utils';

export default class Production {
  private static _id = 0;

  goal: ENonTerminal;
  derivation: GrammarSymbol[];
  id: number;

  constructor(goal: ENonTerminal, derivation: GrammarSymbol[]) {
    this.goal = goal;
    this.derivation = derivation;
    this.id = Production._id++;
  }

  toString() {
    const deriv = this.derivation
      .map((gs) => GrammarUtils.toString(gs))
      .join('|');
    return `${ENonTerminal[this.goal]} :=> ${deriv}`;
  }
}

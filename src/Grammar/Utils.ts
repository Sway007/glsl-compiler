import { EKeyword, ETokenType } from '../Lexer/TokenType';
import { TranslationRule } from '../Parser/SemanticAnalyzer';
import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';
import Production from './Production';

export default class GrammarUtils {
  static isTerminal(sm: GrammarSymbol) {
    return sm < ENonTerminal.START;
  }

  static toString(sm: GrammarSymbol) {
    if (this.isTerminal(sm)) {
      return ETokenType[sm] ?? EKeyword[sm];
    }
    return ENonTerminal[sm];
  }

  static createProductionWithOptions(
    goal: ENonTerminal,
    options: GrammarSymbol[][],
    rule: TranslationRule | null = null
  ) {
    const ret: [GrammarSymbol[], TranslationRule | null][] = [];
    for (const opt of options) {
      ret.push([[goal, ...opt], rule]);
    }
    return ret;
  }

  static createProductionOptions(
    common: GrammarSymbol[],
    position: number,
    opts: GrammarSymbol[][]
  ) {
    const ret: GrammarSymbol[][] = [];
    for (const opt of opts) {
      const list = common.slice(0, position);
      list.push(...opt);
      list.push(...common.slice(position));
      ret.push(list);
    }
    return ret;
  }
}

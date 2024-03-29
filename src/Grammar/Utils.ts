import { EKeyword, ETokenType } from '../Lexer/TokenType';
import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';

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
}

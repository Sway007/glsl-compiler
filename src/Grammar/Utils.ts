import { EKeyword, ETokenType } from '../Lexer/TokenType';
import { ASTNode } from '../Parser/AST';
import { TranslationRule } from '../Parser/SemanticAnalyzer';
import { ASTNodeConstructor } from '../Parser/types';
import { LocRange } from '../common/Position';
import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';

export default class GrammarUtils {
  static isTerminal(sm: GrammarSymbol) {
    return sm < ENonTerminal.START;
  }

  static toString(sm: GrammarSymbol) {
    if (this.isTerminal(sm)) {
      return ETokenType[sm] ?? EKeyword[sm];
    }
    if (ENonTerminal[sm] === 'constant_expression') debugger;
    return ENonTerminal[sm];
  }

  static createProductionWithOptionsV2(
    goal: ENonTerminal,
    options: GrammarSymbol[][],
    /** the ast node */
    astType: ASTNodeConstructor
  ) {
    const ret: [GrammarSymbol[], TranslationRule | undefined][] = [];
    for (const opt of options) {
      ret.push([
        [goal, ...opt],
        (sa, ...children) => {
          if (!children[0]) return;
          const start = children[0].location.start;
          const end = children[children.length - 1].location.end;
          const location = new LocRange(start, end);
          ASTNode.create(astType, sa, location, children);
        },
      ]);
    }
    return ret;
  }

  static createProductionWithOptions(
    goal: ENonTerminal,
    options: GrammarSymbol[][],
    rule: TranslationRule[] | TranslationRule | undefined = undefined
  ) {
    const ret: [GrammarSymbol[], TranslationRule | undefined][] = [];
    for (let i = 0; i < options.length; i++) {
      ret.push([[goal, ...options[i]], Array.isArray(rule) ? rule[i] : rule]);
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

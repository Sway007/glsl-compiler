import { ENonTerminal } from '../Grammar/GrammarSymbol';
import Token from '../Lexer/Token';
import { EKeyword } from '../Lexer/TokenType';
import { TreeNode } from './AST';
import { GalaceanDataType } from './types';

export class ParserUtils {
  static unwrapNodeByType<T = TreeNode>(
    node: TreeNode,
    type: ENonTerminal
  ): T | undefined {
    const child = node.children[0];
    if (child instanceof Token) return;
    if (child.nt === type) return child as T;
    return ParserUtils.unwrapNodeByType(child, type);
  }

  /**
   * Check if type tb is compatible with type ta.
   */
  static typeCompatible(
    ta: GalaceanDataType,
    tb: GalaceanDataType | undefined
  ) {
    if (tb == undefined) return true;
    if (ta === EKeyword.INT) {
      return ta === tb || tb === EKeyword.UINT;
    }
    return ta === tb;
  }
}

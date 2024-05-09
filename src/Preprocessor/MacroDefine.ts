import { LocRange } from '../common/Position';
import { MacroExpand } from './MacroExpand';
import PpToken from './Token';

export class MacroDefine extends MacroExpand {
  macro: PpToken;
  args?: PpToken[];
  body: PpToken;

  get isFunction() {
    return !!this.args?.length;
  }

  get macroLexeme() {
    return this.macro.lexeme;
  }

  constructor(macro: PpToken, body: PpToken, loc: LocRange, args?: PpToken[]) {
    super(loc);
    this.macro = macro;
    this.body = body;
    this.args = args;
  }

  expand(...args: string[]): string {
    if (this.isFunction) {
      const argsTextList = this.args!.map((item) => item.lexeme);

      if (args.length !== this.args?.length) {
        this.throw(this.location, 'mismatched function macro');
      }
      const replaceRegex = new RegExp(`\\b(${argsTextList.join('|')})\\b`, 'g');
      return this.body.lexeme.replaceAll(replaceRegex, (_, m) => {
        const idx = argsTextList.findIndex((item) => item === m);
        return args[idx];
      });
    }
    return this.body.lexeme;
  }
}

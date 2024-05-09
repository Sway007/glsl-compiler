import Position, { LocRange } from '../common/Position';
import { MacroExpand } from './MacroExpand';
import PpToken from './Token';
import { EPpToken } from './constants';

export class MacroBranch extends MacroExpand {
  readonly macroBody: PpToken<EPpToken.chunk>;

  constructor(body: PpToken<EPpToken.chunk>, loc: LocRange) {
    super(loc);
    this.macroBody = body;
  }

  override expand(): string {
    // TODO: recursive parse.
    return 'Method not implemented.';
  }
}

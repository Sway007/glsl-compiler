import { LocRange } from '../common/Position';
import { MacroExpand } from './MacroExpand';
import PpToken from './Token';

export class MacroInclude extends MacroExpand {
  readonly includeKey: PpToken;

  constructor(includeKey: PpToken, loc: LocRange) {
    super(loc);
    this.includeKey = includeKey;
  }

  expand(): string {
    return 'Not implemented.';
  }
}

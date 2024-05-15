import { LocRange } from '../common/Position';
import { PpError } from './PpError';

export abstract class MacroExpand extends PpError {
  readonly location: LocRange;

  constructor(loc: LocRange) {
    super();
    this.location = loc;
  }

  abstract expand(...args: any[]): string;
}

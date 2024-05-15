import Position, { LocRange } from '../common/Position';
import { EPpKeyword, EPpToken } from './constants';

type PpTokenType = EPpToken | EPpKeyword;

export default class PpToken<T extends PpTokenType = PpTokenType> {
  type: T;
  lexeme: string;
  position: Position;

  /** The length of lexeme */
  get length() {
    return this.lexeme.length;
  }

  get location(): LocRange {
    return new LocRange(this.position, this.position.offset(this.length));
  }

  constructor(type: T, lexeme: string, position: Position) {
    this.type = type;
    this.lexeme = lexeme;
    this.position = position;
  }

  toString() {
    return `<${EPpKeyword[this.type] ?? EPpToken[this.type]}, ${this.lexeme}>`;
  }
}

export const EOF = new PpToken(EPpToken.EOF, '/EOF', new Position(-1, -1, -1));

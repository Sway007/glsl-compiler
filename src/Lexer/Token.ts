import Position, { LocRange } from '../common/Position';
import { EKeyword, ETokenType, TokenType } from './TokenType';

export default class Token {
  type: TokenType;
  lexeme: string;
  position: Position;

  /** The length of lexeme */
  get length() {
    return this.lexeme.length;
  }

  get location(): LocRange {
    return new LocRange(this.position, this.position.offset(this.length));
  }

  constructor(type: TokenType, lexeme: string, position: Position) {
    this.type = type;
    this.lexeme = lexeme;
    this.position = position;
  }

  toString() {
    return `<${ETokenType[this.type] ?? EKeyword[this.type]}, ${this.lexeme}>`;
  }
}

export const EOF = new Token(ETokenType.EOF, '/EOF', new Position(-1, -1, -1));

import Position from '../common/Position';
import { EKeyword, ETokenType, TokenType } from './TokenType';

export default class Token {
  type: TokenType;
  lexeme: string;
  position: Position;

  constructor(type: TokenType, lexeme: string, position: Position) {
    this.type = type;
    this.lexeme = lexeme;
    this.position = position;
  }

  toString() {
    return `<${ETokenType[this.type] ?? EKeyword[this.type]}, ${this.lexeme}>`;
  }
}

export const EOF = new Token(ETokenType.EOF, '', new Position(-1, -1, -1));

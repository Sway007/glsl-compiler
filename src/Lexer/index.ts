import Position from '../common/Position';
import Token, { EOF } from './Token';
import { ETokenType, KeywordTable } from './TokenType';
import LexerUtils from './Utils';

export default class Lexer {
  private source: string;
  private current = 0;

  private line = 0;
  private column = 0;

  constructor(source: string) {
    this.source = source;
  }

  reset(source: string) {
    this.source = source;
    this.current = this.line = this.column = 0;
  }

  *tokenize() {
    let line = 0;
    while (!this.isEnd()) {
      const token = this.scanToken();
      if (token.position.line !== line) {
        line = token.position.line;
      }
      yield token;
    }
    return EOF;
  }

  private curChar() {
    return this.source[this.current];
  }

  private peek() {
    return this.source[this.current + 1];
  }

  private scanToken(): Token {
    this.skipSpace();
    this.skipComments();
    if (this.isEnd()) return EOF;

    if (LexerUtils.isAlpha(this.curChar())) {
      return this.scanWord();
    }
    if (LexerUtils.isNum(this.curChar())) {
      return this.scanNum();
    }
    if (this.isEnd()) return EOF;
    switch (this.curChar()) {
      case '<':
        this.advance();
        if (this.curChar() === '<') {
          this.advance();
          if (this.curChar() === '=') {
            this.advance();
            return new Token(
              ETokenType.LEFT_ASSIGN,
              '<<=',
              this.getPosition(3)
            );
          }
          return new Token(ETokenType.LEFT_OP, '<<', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.LE_OP, '<=', this.getPosition(2));
        }
        return new Token(ETokenType.LEFT_ANGLE, '<', this.getPosition());

      case '>':
        this.advance();
        if (this.curChar() === '>') {
          this.advance();
          if (this.curChar() === '=') {
            this.advance();
            return new Token(
              ETokenType.RIGHT_ASSIGN,
              '>>=',
              this.getPosition(3)
            );
          }
          return new Token(ETokenType.RIGHT_OP, '>>', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.GE_OP, '>=', this.getPosition(2));
        }
        return new Token(ETokenType.RIGHT_ANGLE, '>', this.getPosition());

      case '+':
        this.advance();
        if (this.curChar() === '+') {
          this.advance();
          return new Token(ETokenType.INC_OP, '++', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.ADD_ASSIGN, '+=', this.getPosition(2));
        }
        return new Token(ETokenType.PLUS, '+', this.getPosition());

      case '-':
        this.advance();
        if (this.curChar() === '-') {
          this.advance();
          return new Token(ETokenType.DEC_OP, '--', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.SUB_ASSIGN, '-=', this.getPosition(2));
        }
        return new Token(ETokenType.DASH, '-', this.getPosition());

      case '=':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.EQ_OP, '==', this.getPosition(2));
        }
        return new Token(ETokenType.EQUAL, '=', this.getPosition());

      case '!':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.NE_OP, '!=', this.getPosition(2));
        }
        return new Token(ETokenType.BANG, '!', this.getPosition());

      case '&':
        this.advance();
        if (this.curChar() === '&') {
          this.advance();
          return new Token(ETokenType.AND_OP, '&&', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.ADD_ASSIGN, '&=', this.getPosition(2));
        }
        return new Token(ETokenType.AMPERSAND, '&', this.getPosition());

      case '|':
        this.advance();
        if (this.curChar() === '|') {
          this.advance();
          return new Token(ETokenType.OR_OP, '||', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.OR_ASSIGN, '|=', this.getPosition(2));
        }
        return new Token(ETokenType.VERTICAL_BAR, '|', this.getPosition());

      case '^':
        this.advance();
        if (this.curChar() === '^') {
          this.advance();
          return new Token(ETokenType.XOR_OP, '^^', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.XOR_ASSIGN, '^=', this.getPosition(2));
        }
        return new Token(ETokenType.CARET, '^', this.getPosition());

      case '*':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.MUL_ASSIGN, '*=', this.getPosition(2));
        }
        return new Token(ETokenType.STAR, '*', this.getPosition());

      case '/':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.DIV_ASSIGN, '/=', this.getPosition(2));
        }
        return new Token(ETokenType.SLASH, '/', this.getPosition());

      case '%':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new Token(ETokenType.MOD_ASSIGN, '%=', this.getPosition(2));
        }
        return new Token(ETokenType.PERCENT, '%', this.getPosition());

      case '(':
        this.advance();
        return new Token(ETokenType.LEFT_PAREN, '(', this.getPosition());
      case ')':
        this.advance();
        return new Token(ETokenType.RIGHT_PAREN, ')', this.getPosition());
      case '{':
        this.advance();
        return new Token(ETokenType.LEFT_BRACE, '{', this.getPosition());
      case '}':
        this.advance();
        return new Token(ETokenType.RIGHT_BRACE, '}', this.getPosition());
      case '[':
        this.advance();
        return new Token(ETokenType.LEFT_BRACKET, '[', this.getPosition());
      case ']':
        this.advance();
        return new Token(ETokenType.RIGHT_BRACKET, ']', this.getPosition());
      case '.':
        this.advance();
        if (LexerUtils.isNum(this.curChar())) {
          return this.scanNumAfterDot();
        }
        return new Token(ETokenType.DOT, '.', this.getPosition());
      case ',':
        this.advance();
        return new Token(ETokenType.COMMA, ',', this.getPosition());
      case ':':
        this.advance();
        return new Token(ETokenType.COLON, ':', this.getPosition());
      case ';':
        this.advance();
        return new Token(ETokenType.SEMICOLON, ';', this.getPosition());
      case '~':
        this.advance();
        return new Token(ETokenType.TILDE, '~', this.getPosition());
      case '?':
        this.advance();
        return new Token(ETokenType.QUESTION, '?', this.getPosition());

      default:
        console.log('at position', this.getPosition());
        throw `Unexpected character.`;
    }
  }

  private scanWord() {
    const buffer: string[] = [this.curChar()];
    this.advance();
    while (LexerUtils.isLetter(this.curChar())) {
      buffer.push(this.curChar());
      this.advance();
    }
    const word = buffer.join('');
    const kt = KeywordTable.get(word);
    if (kt) {
      return new Token(kt, word, this.getPosition());
    }
    return new Token(ETokenType.ID, word, this.getPosition(buffer.length));
  }

  private scanNum() {
    const buffer: string[] = [];
    while (LexerUtils.isNum(this.curChar())) {
      buffer.push(this.curChar());
      this.advance();
    }
    if (this.curChar() === '.') {
      buffer.push(this.curChar());
      this.advance();
      while (LexerUtils.isNum(this.curChar())) {
        buffer.push(this.curChar());
        this.advance();
      }
      this.scanFloatSuffix(buffer);
      return new Token(
        ETokenType.FLOAT_CONSTANT,
        buffer.join(''),
        this.getPosition(buffer.length)
      );
    } else {
      if (this.curChar() === 'e' || this.curChar() === 'E') {
        this.scanFloatSuffix(buffer);
        return new Token(
          ETokenType.FLOAT_CONSTANT,
          buffer.join(''),
          this.getPosition(buffer.length)
        );
      } else {
        this.scanIntegerSuffix(buffer);
        return new Token(
          ETokenType.INT_CONSTANT,
          buffer.join(''),
          this.getPosition(buffer.length)
        );
      }
    }
  }

  private scanFloatSuffix(buffer: string[]) {
    if (this.curChar() === 'e' || this.curChar() === 'E') {
      buffer.push(this.curChar());
      this.advance();
      if (this.curChar() === '+' || this.curChar() === '-') {
        buffer.push(this.curChar());
        this.advance();
      }
      if (!LexerUtils.isNum(this.curChar()))
        throw 'lexing error, invalid exponent suffix.';
      while (LexerUtils.isNum(this.curChar())) {
        buffer.push(this.curChar());
        this.advance();
      }
    }
    if (this.curChar() === 'f' || this.curChar() === 'F') {
      buffer.push(this.curChar());
      this.advance();
    }
  }

  private scanIntegerSuffix(buffer: string[]) {
    if (this.curChar() === 'u' || this.curChar() === 'U') {
      buffer.push(this.curChar());
      this.advance();
    }
  }

  private scanNumAfterDot() {
    const buffer = ['.'];
    while (LexerUtils.isNum(this.curChar())) {
      buffer.push(this.curChar());
      this.advance();
    }
    return new Token(
      ETokenType.FLOAT_CONSTANT,
      buffer.join(''),
      this.getPosition(buffer.length)
    );
  }

  private advance() {
    if (this.isEnd()) return;
    if (this.curChar() === '\n') {
      this.line += 1;
      this.column = 0;
    } else {
      this.column += 1;
    }
    this.current++;
  }

  private isEnd() {
    return this.current >= this.source.length;
  }

  private skipSpace() {
    while ([' ', '\t', '\n'].indexOf(this.curChar()) != -1) {
      this.advance();
    }
  }

  private skipComments() {
    if (this.curChar() === '/') {
      if (this.peek() === '/') {
        // single line comments
        while (this.curChar() !== '\n') this.advance();
        this.advance();
      }
      // } else return;
      else if (this.peek() === '*') {
        //  multi-line comments
        this.advance();
        while (this.curChar() !== '*' || this.peek() !== '/') this.advance();
        this.advance();
        this.advance();
      } else return;
    } else return;
    this.skipSpace();
    this.skipComments();
  }

  private getPosition(offset /** offset from starting point */ = 1) {
    return new Position(this.current - offset, this.line, this.column);
  }
}

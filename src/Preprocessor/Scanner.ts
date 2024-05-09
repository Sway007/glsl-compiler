import LexerUtils from '../Lexer/Utils';
import { Logger } from '../Logger';
import Position, { LocRange } from '../common/Position';
import { PpError } from './PpError';
import PpToken, { EOF } from './Token';
import { EPpKeyword, EPpToken, PpKeyword } from './constants';

export type OnToken = (token: PpToken, scanner: PpScanner) => void;

export default class PpScanner extends PpError {
  private _source: string;
  get source() {
    return this._source;
  }

  private _current = 0;
  get current() {
    return this._current;
  }

  private line = 0;
  private column = 0;

  private macroLvl = 0;

  constructor(source: string) {
    super();
    this._source = source;
  }

  reset(source: string) {
    this._source = source;
    this._current = this.line = this.column = 0;
  }

  curChar() {
    return this._source[this._current];
  }

  isEnd() {
    return this._current >= this._source.length;
  }

  /**
   * @param nonLetterChar should not be space
   */
  scanWordsUntilChar(nonLetterChar: string): PpToken[] {
    const ret: PpToken[] = [];
    while (true) {
      this.skipSpace();
      if (LexerUtils.isLetter(this.curChar())) {
        ret.push(this.scanWord());
      } else if (this.curChar() === nonLetterChar) {
        this.advance();
        return ret;
      } else {
        this.advance();
      }
    }
  }

  /**
   * @returns end position
   */
  scanRemainMacro(): Position {
    const startLvl = this.macroLvl;
    let directive = this.scanDirective()!;
    while (
      directive.type !== EPpKeyword.endif ||
      startLvl - 1 !== this.macroLvl
    ) {
      directive = this.scanDirective()!;
    }
    return this.getPosition();
  }

  scanMacroBranchChunk(): {
    token: PpToken<EPpToken.chunk>;
    nextDirective: PpToken;
  } {
    const start = this._current;
    const position = this.getPosition();

    const startLvl = this.macroLvl;
    let directive = this.scanDirective()!;

    while (true) {
      if (directive.type === EPpKeyword.endif && startLvl - 1 === this.macroLvl)
        break;
      else if (
        [EPpKeyword.elif, EPpKeyword.else].includes(
          <EPpKeyword>directive.type
        ) &&
        startLvl === this.macroLvl
      )
        break;
      directive = this.scanDirective()!;
    }

    const chunk = this._source.slice(
      start,
      this._current - directive.length - 1
    );
    const token = new PpToken(EPpToken.chunk, chunk, position);
    return { token, nextDirective: directive };
  }

  scanWord(skipNonLetter = false): PpToken {
    if (skipNonLetter) {
      while (!LexerUtils.isLetter(this.curChar()) && !this.isEnd()) {
        this.advance();
      }
    } else {
      this.skipSpace();
    }

    if (this.isEnd()) return EOF;

    const start = this._current;
    while (LexerUtils.isLetter(this.curChar())) {
      this.advance();
    }
    const end = this._current;
    const word = this._source.slice(start, end);
    if (end === start) {
      this.throw(this.getPosition(), 'no word found.');
    }
    const kw = PpKeyword.get(word);
    if (kw) {
      return new PpToken(kw, word, this.getPosition());
    }

    return new PpToken(EPpToken.id, word, this.getPosition(word.length));
  }

  scanQuotedString(): PpToken<EPpToken.string_const> {
    this.skipSpace();
    if (this.curChar() !== '"') {
      this.throw(this.getPosition(), "unexpected char, expected '\"'");
    }
    const position = this.getPosition();
    this._advance();
    const start = this._current;
    while (this.curChar() !== '"' && !this.isEnd()) this._advance();
    if (this.isEnd()) {
      this.throw(this.getPosition(), "unexpected char, expected '\"'");
    }
    const word = this._source.slice(start, this._current);
    return new PpToken(EPpToken.string_const, word, position);
  }

  scanInteger() {
    const start = this._current;
    while (LexerUtils.isNum(this.curChar())) {
      this.advance();
    }
    if (this._current === start) {
      this.throw(this.getPosition(), 'no integer found');
    }
    const integer = this._source.slice(start, this._current);
    return new PpToken(EPpToken.int_constant, integer, this.getPosition());
  }

  scanToChar(char: string) {
    while (this.curChar() !== char && !this.isEnd()) {
      this.advance();
    }
  }

  /**
   * @param onToken callback when encounter a token
   * @returns token split by space
   */
  scanToken(onToken?: OnToken): PpToken | undefined {
    this.skipSpace();
    const start = this._current;
    while (/[\w#.]/.test(this.curChar()) && !this.isEnd()) {
      this._advance();
    }
    if (this.isEnd()) return;
    if (start === this._current) {
      this._advance();
      return this.scanToken(onToken);
    }
    const lexeme = this._source.slice(start, this._current);
    const ret = new PpToken(
      PpKeyword.get(lexeme) ?? EPpToken.id,
      lexeme,
      this.getPosition(this._current - start)
    );
    onToken?.(ret, this);
    return ret;
  }

  /**
   * Advance to directive
   * @param expandOnToken callback on encountering token.
   */
  scanDirective(expandOnToken?: OnToken) {
    const directive = this.advanceToDirective(expandOnToken)!;
    if (this.isEnd()) return;
    if (
      [EPpKeyword.if, EPpKeyword.ifdef, EPpKeyword.ifndef].includes(
        <any>directive.type
      )
    ) {
      this.macroLvl += 1;
    } else if (<any>directive.type === EPpKeyword.endif) {
      this.macroLvl -= 1;
    }
    return directive;
  }

  peekNonSpace() {
    let current = this._current;
    while (!/\s/.test(this._source[current])) {
      current += 1;
    }
    return this._source[current];
  }

  peek(offset = 1) {
    return this._source.slice(this._current, this._current + offset);
  }

  advance(count = 1) {
    for (let i = 0; i < count; i++) this._advance();
  }

  private _advance() {
    if (this.isEnd()) return;
    if (this.curChar() === '\n') {
      this.line += 1;
      this.column = 0;
    } else {
      this.column += 1;
    }
    this._current++;
  }

  scanLineRemain() {
    const start = this._current;
    while (this.curChar() !== '\n') {
      if (this.isEnd()) {
        const line = this._source.slice(start, this._current);
        return new PpToken(
          EPpToken.line_remain,
          line,
          this.getPosition(line.length)
        );
      }
      this.advance();
    }
    const line = this._source.slice(start, this._current);
    return new PpToken(
      EPpToken.line_remain,
      line,
      this.getPosition(line.length)
    );
  }

  skipSpace() {
    while ([' ', '\t', '\n'].indexOf(this.curChar()) != -1) {
      this.advance();
    }
  }

  getPosition(offset /** offset from starting point */ = 0) {
    return new Position(
      this._current - offset,
      this.line,
      this.column - offset
    );
  }

  scanOperator(): PpToken | undefined {
    this.skipSpace();
    switch (this.curChar()) {
      case '>':
        this.advance();
        if (this.curChar() === '>') {
          this.advance();
          return new PpToken(EPpToken.right_op, '>>', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new PpToken(EPpToken.ge, '>=', this.getPosition(2));
        }
        return new PpToken(EPpToken.right_angle, '>', this.getPosition());

      case '<':
        this.advance();
        if (this.curChar() === '<') {
          this.advance();
          return new PpToken(EPpToken.left_op, '<<', this.getPosition(2));
        } else if (this.curChar() === '=') {
          this.advance();
          return new PpToken(EPpToken.le, '<=', this.getPosition(2));
        }
        return new PpToken(EPpToken.left_angle, '<', this.getPosition());

      case '+':
        this.advance();
        return new PpToken(EPpToken.plus, '+', this.getPosition());

      case '-':
        this.advance();
        return new PpToken(EPpToken.dash, '-', this.getPosition());

      case '*':
        this.advance();
        return new PpToken(EPpToken.star, '*', this.getPosition());

      case '!':
        this.advance();
        if (this.curChar() === '=') {
          this.advance();
          return new PpToken(EPpToken.neq, '!=', this.getPosition(2));
        }
        return new PpToken(EPpToken.bang, '!', this.getPosition());

      case '/':
        if (this.peek() !== '/') {
          this.advance();
          return new PpToken(EPpToken.slash, '/', this.getPosition());
        }

      case '%':
        this.advance();
        return new PpToken(EPpToken.percent, '%', this.getPosition());

      case '+':
        this.advance();
        return new PpToken(EPpToken.plus, '+', this.getPosition());

      case '-':
        this.advance();
        return new PpToken(EPpToken.dash, '-', this.getPosition());

      case '=':
        if (this.peek() === '=') {
          this.advance();
          this.advance();
          return new PpToken(EPpToken.eq, '==', this.getPosition(2));
        }

      case '&':
        if (this.peek() === '&') {
          this.advance();
          this.advance();
          return new PpToken(EPpToken.and, '&&', this.getPosition(2));
        }

      case '|':
        if (this.peek() === '|') {
          this.advance();
          this.advance();
          return new PpToken(EPpToken.or, '||', this.getPosition(2));
        }

      case '(':
        this.advance();
        return new PpToken(EPpToken.left_paren, '(', this.getPosition());

      case ')':
        this.advance();
        return new PpToken(EPpToken.right_paren, ')', this.getPosition());

      default:
        return;
    }
  }

  private advanceToDirective(onToken?: OnToken): PpToken | undefined {
    while (true) {
      const token = this.scanToken(onToken)!;
      if (this.isEnd()) return;
      if (token.lexeme.startsWith('#')) return token;
    }
  }
}

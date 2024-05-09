/**
 * Recursive Descent Parser
 */

import LexerUtils from '../Lexer/Utils';
import Position, { LocRange } from '../common/Position';
import { MacroBranch } from './MacroBranch';
import { MacroDefine } from './MacroDefine';
import { MacroExpand } from './MacroExpand';
import { MacroInclude } from './MacroInclude';
import { PpError } from './PpError';
import PpScanner from './Scanner';
import PpToken from './Token';
import { EPpKeyword, EPpToken } from './constants';

interface ExpandSegment {
  range: LocRange;
  replace: string;
}

export default class PpParser extends PpError {
  private definedMacros: Map<string, MacroDefine> = new Map();
  private branchMacros: MacroExpand[] = [];
  private includeMacros: MacroExpand[] = [];
  private expandSegments: ExpandSegment[] = [];

  constructor() {
    super();
    const gl_es = new PpToken(EPpToken.id, 'GL_ES', Position.invalid());
    this.definedMacros.set(
      'GL_ES',
      new MacroDefine(
        gl_es,
        new PpToken(EPpToken.id, '1', Position.invalid()),
        LocRange.invalid()
      )
    );
  }

  parse(scanner: PpScanner) {
    while (!scanner.isEnd()) {
      const directive = scanner.scanDirective(this.expandToken.bind(this))!;
      if (scanner.isEnd()) break;
      switch (directive.type) {
        case EPpKeyword.define:
          this.parseDefine(scanner);
          break;

        case EPpKeyword.undef:
          this.parseUndef(scanner);
          break;

        case EPpKeyword.if:
          this.parseIf(scanner);
          break;

        case EPpKeyword.ifndef:
          this.parseIfNdef(scanner);
          break;

        case EPpKeyword.ifdef:
          this.parseIfDef(scanner);
          break;

        case EPpKeyword.include:
          this.parseInclude(scanner);
          break;
      }
    }
  }

  private expandToken(token: PpToken, scanner: PpScanner) {
    const macro = this.definedMacros.get(token.lexeme);
    if (macro) {
      let replace = macro.body.lexeme;
      if (macro.isFunction) {
        scanner.scanToChar('(');
        scanner.advance();
        const start = scanner.current;
        scanner.scanToChar(')');
        const end = scanner.current;
        const argsText = scanner.source.slice(start, end);
        const args = argsText.split(',');
        scanner.advance();
        const range = new LocRange(token.position, scanner.getPosition());
        replace = macro.expand(...args);
        this.expandSegments.push({ range, replace });
      } else {
        this.expandSegments.push({ range: token.location, replace });
      }
    }
  }

  private parseInclude(scanner: PpScanner) {
    const start = scanner.getPosition(7);

    scanner.skipSpace();
    const id = scanner.scanQuotedString();
    scanner.scanToChar('\n');
    const end = scanner.getPosition();
    const macroInclude = new MacroInclude(id, new LocRange(start, end));
    this.includeMacros.push(macroInclude);
  }

  private parseIfNdef(scanner: PpScanner) {
    const start = scanner.getPosition(6);

    const id = scanner.scanWord();
    const macro = this.definedMacros.get(id.lexeme);
    const { token: bodyChunk, nextDirective } = scanner.scanMacroBranchChunk();
    if (!macro) {
      const end =
        nextDirective.type === EPpKeyword.endif
          ? scanner.getPosition()
          : scanner.scanRemainMacro();
      const macroBranch = new MacroBranch(bodyChunk, new LocRange(start, end));
      this.branchMacros.push(macroBranch);
      return;
    }

    this.parseMacroBranch(start, <any>nextDirective.type, scanner);
  }

  private parseIfDef(scanner: PpScanner) {
    const start = scanner.getPosition(5);

    const id = scanner.scanWord();
    const macro = this.definedMacros.get(id.lexeme);
    scanner.skipSpace();
    const { token: bodyChunk, nextDirective } = scanner.scanMacroBranchChunk();
    if (!!macro) {
      const end =
        nextDirective.type === EPpKeyword.endif
          ? scanner.getPosition()
          : scanner.scanRemainMacro();
      const macroBranch = new MacroBranch(bodyChunk, new LocRange(start, end));
      this.branchMacros.push(macroBranch);
      return;
    }

    this.parseMacroBranch(start, <any>nextDirective.type, scanner);
  }

  private parseIf(scanner: PpScanner) {
    const start = scanner.getPosition(3);

    const constantExpr = this.parseConstantExpression(scanner);
    const { token: bodyChunk, nextDirective } = scanner.scanMacroBranchChunk();
    if (!!constantExpr) {
      const end =
        nextDirective.type === EPpKeyword.endif
          ? scanner.getPosition()
          : scanner.scanRemainMacro();
      const macroIf = new MacroBranch(bodyChunk, new LocRange(start, end));
      this.branchMacros.push(macroIf);
      return;
    }

    this.parseMacroBranch(start, <any>nextDirective.type, scanner);
  }

  private parseMacroBranch(
    start: Position,
    directive: EPpKeyword.elif | EPpKeyword.else | EPpKeyword.endif,
    scanner: PpScanner
  ) {
    if (directive === EPpKeyword.endif) return;

    if (directive === EPpKeyword.else) {
      const { token: elseChunk } = scanner.scanMacroBranchChunk();
      const macroIf = new MacroBranch(
        elseChunk,
        new LocRange(start, scanner.getPosition())
      );
      this.branchMacros.push(macroIf);
    } else if (directive === EPpKeyword.elif) {
      const constantExpr = this.parseConstantExpression(scanner);
      const { token: bodyChunk, nextDirective } =
        scanner.scanMacroBranchChunk();
      if (!!constantExpr) {
        const end = scanner.scanRemainMacro();
        const macroIf = new MacroBranch(bodyChunk, new LocRange(start, end));
        this.branchMacros.push(macroIf);
      } else {
        this.parseMacroBranch(start, <any>nextDirective.type, scanner);
      }
    }
  }

  private parseConstantExpression(scanner: PpScanner) {
    scanner.skipSpace();
    return this.parseLogicalOrExpression(scanner);
  }

  private parseLogicalOrExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseLogicalAndExpression(scanner);
    const operator = scanner.peek(2);
    if (operator && operator === '||') {
      scanner.advance(2);
      scanner.skipSpace();
      const operand2 = this.parseLogicalOrExpression(scanner);
      return operand1 || operand2;
    }
    return operand1;
  }

  private parseLogicalAndExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseEqualityExpression(scanner);
    const operator = scanner.peek(2);
    if (operator && operator === '&&') {
      scanner.advance(2);
      scanner.skipSpace();
      const operand2 = this.parseLogicalAndExpression(scanner);
      return operand1 && operand2;
    }
    return operand1;
  }

  private parseEqualityExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseRelationalExpression(scanner);
    const operator = scanner.peek(2);
    if (operator && ['==', '!='].includes(operator)) {
      scanner.advance(2);
      scanner.skipSpace();
      const operand2 = this.parseEqualityExpression(scanner);
      switch (operator) {
        case '==':
          return operand1 === operand2;
        case '!=':
          return operand1 !== operand2;
      }
    }
    return operand1;
  }

  private parseRelationalExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseShiftExpression(scanner) as number;
    let operator = scanner.peek(2);
    if (operator[1] !== '=') operator = operator[0];
    if (operator && ['>', '<', '>=', '<='].includes(operator)) {
      const opPos = scanner.getPosition();
      scanner.advance(operator.length);
      scanner.skipSpace();
      const operand2 = this.parseRelationalExpression(scanner) as number;
      if (typeof operand1 !== typeof operand2 && typeof operand1 !== 'number') {
        this.throw(opPos, 'invalid operator in relation expression.');
      }
      switch (operator) {
        case '>':
          return operand1 > operand2;
        case '<':
          return operand1 < operand2;
        case '>=':
          return operand1 >= operand2;
        case '<=':
          return operand1 <= operand2;
      }
    }
    return operand1;
  }

  private parseShiftExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseAdditiveExpression(scanner) as number;
    const operator = scanner.peek(2);
    if (operator && ['>>', '<<'].includes(operator)) {
      const opPos = scanner.getPosition();
      scanner.advance(2);
      scanner.skipSpace();
      const operand2 = this.parseShiftExpression(scanner) as number;
      if (typeof operand1 !== typeof operand2 && typeof operand1 !== 'number') {
        this.throw(opPos, 'invalid operator in shift expression.');
      }
      switch (operator) {
        case '>>':
          return operand1 >> operand2;
        case '<<':
          return operand1 << operand2;
      }
    }

    return operand1;
  }

  private parseAdditiveExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseMulticativeExpression(scanner) as number;
    if (['>', '<'].includes(scanner.curChar())) {
      const opPos = scanner.getPosition();
      scanner.advance();

      const operator = scanner.curChar();
      scanner.skipSpace();
      const operand2 = this.parseAdditiveExpression(scanner) as number;
      if (typeof operand1 !== typeof operand2 && typeof operand1 !== 'number') {
        this.throw(opPos, 'invalid operator.');
      }
      switch (operator) {
        case '+':
          return operand1 + operand2;
        case '-':
          return operand1 - operand2;
      }
    }
    return operand1;
  }

  private parseMulticativeExpression(scanner: PpScanner): PpConstant {
    const operand1 = this.parseUnaryExpression(scanner) as number;
    scanner.skipSpace();
    if (['*', '/', '%'].includes(scanner.curChar())) {
      const opPos = scanner.getPosition();
      const operator = scanner.curChar();
      scanner.skipSpace();
      const operand2 = this.parseMulticativeExpression(scanner) as number;
      if (typeof operand1 !== typeof operand2 && typeof operand1 !== 'number') {
        this.throw(opPos, 'invalid operator.');
      }
      switch (operator) {
        case '*':
          return operand1 * operand2;
        case '/':
          return operand1 / operand2;
        case '%':
          return operand1 % operand2;
      }
    }
    return operand1;
  }

  private parseUnaryExpression(scanner: PpScanner) {
    const operator = scanner.curChar();
    if (['+', '-', '!'].includes(operator)) {
      scanner.advance();
      const opPos = scanner.getPosition();
      const parenExpr = this.parseParenthesisExpression(scanner);
      if (
        (operator === '!' && typeof parenExpr !== 'boolean') ||
        (operator !== '!' && typeof parenExpr !== 'number')
      ) {
        this.throw(opPos, 'invalid operator.');
      }

      switch (operator) {
        case '+':
          return parenExpr;
        case '-':
          return -parenExpr;
        case '!':
          return !parenExpr;
      }
    }
    return this.parseParenthesisExpression(scanner);
  }

  private parseParenthesisExpression(scanner: PpScanner): PpConstant {
    if (scanner.curChar() === '(') {
      scanner.advance();
      scanner.skipSpace();
      const ret = this.parseConstant(scanner);
      scanner.scanToChar(')');
      scanner.advance();
      return ret;
    }
    return this.parseConstant(scanner);
  }

  private parseConstant(scanner: PpScanner): PpConstant {
    if (LexerUtils.isAlpha(scanner.curChar())) {
      const id = scanner.scanWord();
      if (id.type === EPpKeyword.defined) {
        const withParen = scanner.peekNonSpace() === '(';
        const macro = scanner.scanWord(true);
        if (withParen) {
          scanner.scanToChar(')');
          scanner.advance();
        }
        return !!this.definedMacros.get(macro.lexeme);
      } else {
        const macro = this.definedMacros.get(id.lexeme);
        if (!macro) {
          this.throw(id.location, 'undefined macro:', id.lexeme);
        }
        if (macro.isFunction) {
          this.throw(id.location, 'invalid function macro usage');
        }
        const value = Number(macro.body.lexeme);
        if (!Number.isInteger(value)) {
          this.throw(id.location, 'invalid const macro:', id.lexeme);
        }
        return value;
      }
    } else if (LexerUtils.isNum(scanner.curChar())) {
      const integer = scanner.scanInteger();
      return Number(integer.lexeme);
    } else {
      this.throw(scanner.getPosition(), 'invalid token');
    }
  }

  private parseUndef(scanner: PpScanner) {
    const macro = scanner.scanWord();
    this.definedMacros.delete(macro.lexeme);
  }

  private parseDefine(scanner: PpScanner) {
    const macro = scanner.scanWord();
    const start = macro.position;
    let end = macro.location.end;
    if (this.definedMacros.get(macro.lexeme)) {
      this.throw(macro.location, 'redefined macro:', macro.lexeme);
    }

    let macroArgs: PpToken[] | undefined;
    if (scanner.curChar() === '(') {
      macroArgs = scanner.scanWordsUntilChar(')');
      end = scanner.getPosition();
    }
    const macroBody = scanner.scanLineRemain();
    const macroDefine = new MacroDefine(
      macro,
      macroBody,
      new LocRange(start, end),
      macroArgs
    );
    this.definedMacros.set(macro.lexeme, macroDefine);
  }
}

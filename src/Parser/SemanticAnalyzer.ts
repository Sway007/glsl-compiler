import { ENonTerminal } from '../Grammar/GrammarSymbol';
import Token from '../Lexer/Token';
import SymbolTable from './SymbolTable';

type TranslationRule<T = any> = (
  sa: SematicAnalyzer,
  ...tokens: (Token | ENonTerminal)[]
) => T;

export default class SematicAnalyzer {
  private _scopeStack: SymbolTable[] = [new SymbolTable()];
  private translationRuleTable: Map<
    number /** production id */,
    TranslationRule
  > = new Map();
  acceptRule?: TranslationRule = undefined;
  semanticStack: any[] = [];

  get scope() {
    return this._scopeStack[this._scopeStack.length - 1];
  }

  newScope() {
    const scope = new SymbolTable();
    scope.parent = this.scope;
    this._scopeStack.push(scope);
  }

  dropScope() {
    return this._scopeStack.pop();
  }

  addTranslationRule(pid: number, rule: TranslationRule) {
    this.translationRuleTable.set(pid, rule);
  }

  getTranslationRule(pid: number) {
    return this.translationRuleTable.get(pid);
  }

  log(...params: any[]) {
    console.log('\x1B[38;5;45m[[static analyzer]', ...params, '\x1B[m');
  }
}

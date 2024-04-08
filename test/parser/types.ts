import Grammar from '../../src/Grammar';
import { ENonTerminal, Terminal } from '../../src/Grammar/GrammarSymbol';

export interface TestCase {
  createGrammar: () => Grammar;
  addTranslationRule: (grammar: Grammar) => void;
  printConfig: {
    terminalSymbols: Terminal[];
    nonTerminalSymbols: ENonTerminal[];
  };
  source: string;
}

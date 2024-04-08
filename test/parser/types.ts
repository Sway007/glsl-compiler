import Grammar from '../../src/Grammar';
import { ENonTerminal, Terminal } from '../../src/Grammar/GrammarSymbol';
import SematicAnalyzer from '../../src/Parser/SemanticAnalyzer';

export interface TestCase {
  createGrammar: () => Grammar;
  addTranslationRule: (sa: SematicAnalyzer) => void;
  printConfig: {
    terminalSymbols: Terminal[];
    nonTerminalSymbols: ENonTerminal[];
  };
  source: string;
}

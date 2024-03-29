import grammar, {
  nonTerminalSymbols,
  terminalSymbols,
} from './grammars/grammar6';
import LR1Parser from './LR1';

const lr1 = new LR1Parser();
lr1.computeFirstAndFollowSet(grammar);
lr1.printFirstSet();
lr1.printFollowSet();
console.log('building parsing table');
lr1.buildParsingTable(grammar);
lr1.printParsingTable({
  terminalSymbols: terminalSymbols,
  nonTerminalSymbols: nonTerminalSymbols,
});
console.log('done');

import {
  ENonTerminal,
  GrammarSymbol,
  Terminal,
} from '../../src/Grammar/GrammarSymbol';
import State from '../../src/Grammar/State';
import GrammarUtils from '../../src/Grammar/Utils';
import {
  EAction,
  StateActionTable,
  StateGotoTable,
} from '../../src/ParserGenerator/common';

export function printStatePool() {
  console.log('========== Parser Pool ==========');
  let tmp = '';
  for (const state of State.pool.values()) {
    tmp += `${state.id}: \n`.padEnd(4);
    for (const psItem of state.items) {
      tmp += '     ' + psItem.toString() + '\n';
    }
  }
  console.log(tmp);
}

export function printStateTable(
  info: {
    terminalSymbols: Terminal[];
    nonTerminalSymbols: ENonTerminal[];
  },
  parser: { actionTable: StateActionTable; gotoTable: StateGotoTable }
) {
  console.log('========== Parsing Table ==========');

  const terminalSymbols = info?.terminalSymbols;
  const nonTerminalSymbols = info?.nonTerminalSymbols;

  const unitPadding = 10;

  let str = '';
  const printCell = (text: string | number, unit: number) => {
    str += `| ${text}`.padEnd(unit * unitPadding);
  };
  let lineLength = 0;
  const printLineBreak = () => {
    str += '|\n|';
    for (let i = 1; i < lineLength - 1; i++) {
      str += '-';
    }
    str += '|\n';
  };

  printCell('State', 1);
  printCell('Action', terminalSymbols.length);
  printCell('GOTO', nonTerminalSymbols.length);
  lineLength = str.length + 1;
  printLineBreak();
  printCell('', 1);
  for (const sm of terminalSymbols) {
    printCell(GrammarUtils.toString(sm), 1);
  }
  for (const sm of nonTerminalSymbols) {
    printCell(ENonTerminal[sm], 1);
  }
  printLineBreak();

  for (const state of State.pool.values()) {
    printCell(state.id, 1);
    const actionTable = parser.actionTable.get(state.id)!;
    for (const terminal of terminalSymbols) {
      const action = actionTable.get(terminal);
      if (!action) printCell('', 1);
      else {
        if (action.action === EAction.Accept) {
          printCell('AC', 1);
        } else if (action.action === EAction.Reduce) {
          printCell(`R${action.target}`, 1);
        } else {
          printCell(`S${action.target}`, 1);
        }
      }
    }

    const gotoTable = parser.gotoTable.get(state.id)!;
    for (const nonTerminal of nonTerminalSymbols) {
      const state = gotoTable.get(nonTerminal);
      printCell(state ?? '', 1);
    }
    printLineBreak();
  }
  console.log(str);
}

export function printFirstSet(firstSet: Map<ENonTerminal, Set<Terminal>>) {
  console.log('========== First Set ==========');
  for (const [NT, set] of firstSet.entries()) {
    console.log(
      `${`First(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
        .map((item) => GrammarUtils.toString(item))
        .join(', ')}`
    );
  }
}

export function printFollowSet(
  followSet: Map<ENonTerminal, Set<GrammarSymbol>>
) {
  console.log('========== Follow Set ==========');
  for (const [NT, set] of followSet.entries()) {
    console.log(
      `${`Follow(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
        .map((item) => GrammarUtils.toString(item))
        .join(', ')}`
    );
  }
}

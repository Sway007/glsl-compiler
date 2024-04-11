import { createWriteStream } from 'fs';
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

export function printStatePool(logPath: string) {
  const logStream = createWriteStream(logPath);

  console.log('========== Parser Pool ==========');

  let count = 0;
  for (const state of State.pool.values()) {
    count++;
    let tmp = '';
    tmp += `${state.id}: \n`.padEnd(4);
    for (const psItem of state.items) {
      tmp += '     ' + psItem.toString() + '\n';
    }
    logStream.write(tmp);
  }
  logStream.end();
  logStream.close();
  console.log('state count:', count);
  return new Promise((res) => {
    logStream.on('finish', () => {
      res('');
    });
  });
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

  const unitPadding = 20;

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

export function printFirstSet(
  firstSet: Map<ENonTerminal, Set<Terminal>>,
  outPath: string
) {
  const logStream = createWriteStream(outPath);
  console.log('========== First Set ==========');
  for (const [NT, set] of firstSet.entries()) {
    logStream.write(
      `${`First(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
        .map((item) => GrammarUtils.toString(item))
        .join(', ')}\n`
    );
  }

  logStream.end();
  logStream.close();
  return new Promise((res) => {
    logStream.on('finish', () => {
      res('');
    });
  });
}

export function printFollowSet(
  followSet: Map<ENonTerminal, Set<GrammarSymbol>>,
  outPath: string
) {
  const logStream = createWriteStream(outPath);
  console.log('========== Follow Set ==========');
  for (const [NT, set] of followSet.entries()) {
    logStream.write(
      `${`Follow(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
        .map((item) => GrammarUtils.toString(item))
        .join(', ')}`
    );
  }

  logStream.end();
  logStream.close();
  return new Promise((res) => {
    logStream.on('finish', () => {
      res('');
    });
  });
}

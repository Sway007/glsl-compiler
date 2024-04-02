import Grammar from '../Grammar';
import { ENonTerminal, Terminal } from '../Grammar/GrammarSymbol';
import Parser from './Parser';
import {
  ActionInfo,
  ActionTable,
  EAction,
  ELALR_BIN_TABLE,
  GotoTable,
  StateActionTable,
  StateGotoTable,
} from './common';

export default class LRLoader {
  static load(bin: ArrayBuffer, grammar: Grammar) {
    const actionTable: StateActionTable = new Map();
    const gotoTable: StateGotoTable = new Map();

    const dataView = new DataView(bin);
    let curIdx = 0;
    const lb = '\n'.charCodeAt(0);

    const readU8 = () => {
      return dataView.getUint8(curIdx++);
    };

    const readU16 = () => {
      const byte = dataView.getUint16(curIdx);
      curIdx += 2;
      return byte;
    };

    const peekU8 = () => {
      return dataView.getUint8(curIdx);
    };

    const readAction = () => {
      const ret: ActionInfo = {} as any;
      ret.action = <EAction>readU8();
      if (ret.action !== EAction.Accept) {
        ret.target = readU16();
      }
      return ret;
    };

    let tableIndicator = readU8();
    if (tableIndicator !== ELALR_BIN_TABLE.ActionTable)
      throw 'no action table indicator';

    while (peekU8() !== lb) {
      const stateId = readU16();
      const actionTableRow: ActionTable = new Map();
      while (peekU8() !== lb) {
        const terminal = <Terminal>readU16();
        const action = readAction();
        actionTableRow.set(terminal, action);
      }
      curIdx++;
      actionTable.set(stateId, actionTableRow);
    }
    curIdx++;

    tableIndicator = readU8();
    if (tableIndicator !== ELALR_BIN_TABLE.GOTOTable)
      throw 'no goto table indicator';

    while (peekU8() !== lb) {
      const stateId = readU16();
      const gotoTableRow: GotoTable = new Map();
      while (peekU8() !== lb) {
        const NT = <ENonTerminal>readU16();
        const stateId = readU16();
        gotoTableRow.set(NT, stateId);
      }
      curIdx++;
      gotoTable.set(stateId, gotoTableRow);
    }

    return new Parser(actionTable, gotoTable, grammar);
  }
}

import { PathLike, writeFileSync } from 'fs';
import LALR1 from './LALR1';
import { ActionInfo, EAction, ELALR_BIN_TABLE } from './common';

export default class LREncoder {
  /**
   * actiontable\n
   * stateid:TERMINAL|ACTION{Sstateid/R/A};*\n*
   * gototable\n
   * stateid:NONTERMINAL|stateid;*\n*
   */
  static encode(out: PathLike, lalr1: LALR1) {
    let curSize = 256;
    let curBuffer = new ArrayBuffer(curSize);
    let dataView = new DataView(curBuffer);
    let lb = '\n'.charCodeAt(0);
    const newBuf = () => {
      curSize += 100;
      const newBuffer = new ArrayBuffer(curSize);
      const u8buf = new Uint8Array(newBuffer);
      const originU8Buf = new Uint8Array(curBuffer);
      for (let i = 0; i < originU8Buf.length; i++) {
        u8buf[i] = originU8Buf[i];
      }
      curBuffer = newBuffer;
      dataView = new DataView(curBuffer);
    };

    let curIdx = 0;
    const encodeU8 = (u8: number) => {
      if (curIdx + 1 >= curSize) newBuf();
      dataView.setUint8(curIdx, u8);
      curIdx += 1;
    };

    const encodeU16 = (u16: number) => {
      if (curIdx + 2 >= curSize) newBuf();
      dataView.setUint16(curIdx, u16);
      curIdx += 2;
    };

    const encodeAction = (action: ActionInfo) => {
      encodeU8(action.action);
      if (action.action !== EAction.Accept) encodeU16(action.target!);
    };

    encodeU8(ELALR_BIN_TABLE.ActionTable);
    for (const [stateId, AT] of lalr1.actionTable) {
      encodeU16(stateId);
      for (const [terminal, action] of AT) {
        encodeU16(terminal);
        encodeAction(action);
      }
      encodeU8(lb);
    }
    encodeU8(lb);

    encodeU8(ELALR_BIN_TABLE.GOTOTable);
    for (const [stateId, GT] of lalr1.gotoTable) {
      encodeU16(stateId);
      for (const [NT, stateId] of GT) {
        encodeU16(NT);
        encodeU16(stateId);
      }
      encodeU8(lb);
    }
    encodeU8(lb);
    writeFileSync(out, dataView);
  }
}

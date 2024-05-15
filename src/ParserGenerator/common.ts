import Grammar from '../Grammar';
import { ENonTerminal, Terminal } from '../Grammar/GrammarSymbol';

export type StateActionTable = Map<number /** state ID */, ActionTable>;
export type ActionTable = Map<Terminal, ActionInfo>;
export type StateGotoTable = Map<number /** state ID */, GotoTable>;
export type GotoTable = Map<ENonTerminal, number /** state ID */>;

export enum EAction {
  Shift = 0,
  Reduce,
  Accept,
}

export interface ActionInfo {
  action: EAction;
  target?: number;
}

export enum ELALR_BIN_TABLE {
  ActionTable = 0,
  GOTOTable,
}

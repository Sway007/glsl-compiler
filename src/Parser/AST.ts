import { ENonTerminal, Terminal } from '../Grammar/GrammarSymbol';
import Production from '../Grammar/Production';
import { EKeyword } from '../Lexer/TokenType';
import Position, { LocRange } from '../common/Position';

export enum EType {
  void = 1,
  bool,
  int,
  float,
  vec2,
  vec3,
  vec4,
  ivec2,
  ivec3,
  ivec4,
  bvec2,
  bvec3,
  bvec4,
  mat2,
  mat3,
  mat4,
  sampler2D,

  // =======================//
  // TEST

  // =======================//
}

type NodeType = EType | string /** custom type, e.g. array, struct */;

export abstract class TreeNode {
  /** The non-terminal in grammar. */
  readonly nt: ENonTerminal;
  type!: NodeType;
  readonly location?: LocRange;
  constructor(nt: ENonTerminal, loc?: LocRange) {
    this.nt = nt;
    this.location = loc;
  }
}

// =======================//
// TEST
export class ExpAst extends TreeNode {
  constructor(loc: LocRange) {
    super(ENonTerminal.exp, loc);
  }
}

/** type for token type which stand for type */
type TTT = EKeyword.BOOL | EKeyword.FLOAT | EKeyword.INT;

export class DeclarationAst extends TreeNode {
  readonly id: string;
  readonly tt: TTT;

  constructor(loc: LocRange, id: string, tt: TTT) {
    super(ENonTerminal.declaration, loc);
    this.id = id;
    this.tt = tt;
  }
}
// =======================//

export type Tree = TreeNode;

export enum ETokenType {
  ID = 1000,
  FLOAT_CONSTANT,
  INT_CONSTANT,
  /** << */
  LEFT_OP,
  /** \>> */
  RIGHT_OP,
  /** ++ */
  INC_OP,
  /** -- */
  DEC_OP,
  /** <= */
  LE_OP,
  /** \>= */
  GE_OP,
  /** == */
  EQ_OP,
  /** != */
  NE_OP,
  /** && */
  AND_OP,
  /** || */
  OR_OP,
  /** ^^ */
  XOR_OP,
  /** *= */
  MUL_ASSIGN,
  /** /= */
  DIV_ASSIGN,
  /** += */
  ADD_ASSIGN,
  /** -= */
  SUB_ASSIGN,
  /** %= */
  MOD_ASSIGN,
  /** <<= */
  LEFT_ASSIGN,
  /** >>= */
  RIGHT_ASSIGN,
  /** &= */
  AND_ASSIGN,
  /** ^= */
  XOR_ASSIGN,
  /** |= */
  OR_ASSIGN,
  /** ( */
  LEFT_PAREN,
  /** ) */
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  /** { */
  LEFT_BRACE,
  /** } */
  RIGHT_BRACE,
  /** . */
  DOT,
  COMMA,
  COLON,
  /** = */
  EQUAL,
  SEMICOLON,
  /** ! */
  BANG,
  /** \- */
  DASH,
  /** ~ */
  TILDE,
  PLUS,
  /** \* */
  STAR,
  /** / */
  SLASH,
  PERCENT,
  /** < */
  LEFT_ANGLE,
  /** \> */
  RIGHT_ANGLE,
  VERTICAL_BAR,
  /** ^ */
  CARET,
  AMPERSAND,
  QUESTION,

  /** ε */
  EPSILON = 1998,
  EOF = 1999,
}

export enum EKeyword {
  ATTRIBUTE = 0,
  CONST,
  BOOL,
  FLOAT,
  DOUBLE,
  INT,
  UINT,
  BREAK,
  CONTINUE,
  DO,
  ELSE,
  FOR,
  IF,
  DISCARD,
  RETURN,
  BVEC2,
  BVEC3,
  BVEC4,
  IVEC2,
  IVEC3,
  IVEC4,
  VEC2,
  VEC3,
  VEC4,
  MAT2,
  MAT3,
  MAT4,
  IN,
  OUT,
  INOUT,
  UNIFORM,
  VARYING,
  SAMPLER2D,
  SAMPLER_CUBE,
  STRUCT,
  VOID,
  TRUE,
  FALSE,
  PRECISION,
  PRECISE,
  HIGHP,
  MEDIUMP,
  LOWP,
  INVARIANT,
  SMOOTH,
  FLAT,
  NOPERSPECTIVE,
}

export type TokenType = ETokenType | EKeyword;

export const KeywordTable = new Map<string, EKeyword>([
  ['attribute', EKeyword.ATTRIBUTE],
  ['const', EKeyword.CONST],
  ['bool', EKeyword.BOOL],
  ['float', EKeyword.FLOAT],
  ['double', EKeyword.DOUBLE],
  ['int', EKeyword.INT],
  ['uint', EKeyword.UINT],
  ['break', EKeyword.BREAK],
  ['continue', EKeyword.CONTINUE],
  ['do', EKeyword.DO],
  ['else', EKeyword.ELSE],
  ['for', EKeyword.FOR],
  ['if', EKeyword.IF],
  ['discard', EKeyword.DISCARD],
  ['return', EKeyword.RETURN],
  ['bvec2', EKeyword.BVEC2],
  ['bvec3', EKeyword.BVEC3],
  ['bvec4', EKeyword.BVEC4],
  ['ivec2', EKeyword.IVEC2],
  ['ivec3', EKeyword.IVEC3],
  ['ivec4', EKeyword.IVEC4],
  ['vec2', EKeyword.VEC2],
  ['vec3', EKeyword.VEC3],
  ['vec4', EKeyword.VEC4],
  ['mat2', EKeyword.MAT2],
  ['mat3', EKeyword.MAT3],
  ['mat4', EKeyword.MAT4],
  ['in', EKeyword.IN],
  ['out', EKeyword.OUT],
  ['inout', EKeyword.INOUT],
  // DELETE
  ['uniform', EKeyword.UNIFORM],
  ['varying', EKeyword.VARYING],
  //
  ['sampler2D', EKeyword.SAMPLER2D],
  ['samplerCube', EKeyword.SAMPLER_CUBE],
  ['struct', EKeyword.STRUCT],
  ['void', EKeyword.VOID],
  ['true', EKeyword.TRUE],
  ['false', EKeyword.FALSE],
  ['precision', EKeyword.PRECISION],
  ['precise', EKeyword.PRECISE],
  ['highp', EKeyword.HIGHP],
  ['mediump', EKeyword.MEDIUMP],
  ['lowp', EKeyword.LOWP],
  ['invariant', EKeyword.INVARIANT],
  ['flat', EKeyword.FLAT],
  ['smooth', EKeyword.SMOOTH],
  ['noperspective', EKeyword.NOPERSPECTIVE],
  // ['layout', EKeyword.LAYOUT],
  // ['shared', EKeyword.SHARED],
  // ['centroid', EKeyword.CENTROID],
  // ['coherent', EKeyword.COHERENT],
]);

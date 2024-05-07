export enum ETokenType {
  ID = 1000,
  FLOAT_CONSTANT,
  INT_CONSTANT,
  STRING_CONST,
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
  /** , */
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
  /** % */
  PERCENT,
  /** < */
  LEFT_ANGLE,
  /** \> */
  RIGHT_ANGLE,
  VERTICAL_BAR,
  /** ^ */
  CARET,
  /** & */
  AMPERSAND,
  /** ? */
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
  WHILE,
  DISCARD,
  RETURN,
  BVEC2,
  BVEC3,
  BVEC4,
  IVEC2,
  IVEC3,
  IVEC4,
  UVEC2,
  UVEC3,
  UVEC4,
  VEC2,
  VEC3,
  VEC4,
  MAT2,
  MAT3,
  MAT4,
  MAT2X2,
  MAT2X3,
  MAT2X4,
  MAT3X2,
  MAT3X3,
  MAT3X4,
  MAT4X2,
  MAT4X3,
  MAT4X4,
  IN,
  OUT,
  INOUT,
  CENTROID,
  UNIFORM,
  VARYING,
  SAMPLER2D,
  SAMPLER3D,
  SAMPLER_CUBE,
  SAMPLER2D_SHADOW,
  SAMPLER_CUBE_SHADOW,
  SAMPLER2D_ARRAY,
  SAMPLER2D_ARRAY_SHADOW,
  I_SAMPLER2D,
  I_SAMPLER3D,
  I_SAMPLER_CUBE,
  I_SAMPLER2D_ARRAY,
  U_SAMPLER2D,
  U_SAMPLER3D,
  U_SAMPLER_CUBE,
  U_SAMPLER2D_ARRAY,
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

  // galacean
  GL_Shader,
  GL_SubShader,
  GL_Pass,
  GL_RenderQueueType,
  GL_BlendState,
  GL_DepthState,
  GL_StencilState,
  GL_RasterState,
  GL_EditorProperties,
  GL_EditorMacros,
  GL_Tags,
  GL_ReplacementTag,
  GL_LightMode,
  GL_UsePass,
  GL_VertexShader,
  GL_FragmentShader,

  GL_Vector2,
  GL_Vector3,
  GL_Vector4,
  GL_Color,
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
  ['while', EKeyword.WHILE],
  ['discard', EKeyword.DISCARD],
  ['return', EKeyword.RETURN],
  ['bvec2', EKeyword.BVEC2],
  ['bvec3', EKeyword.BVEC3],
  ['bvec4', EKeyword.BVEC4],
  ['ivec2', EKeyword.IVEC2],
  ['ivec3', EKeyword.IVEC3],
  ['ivec4', EKeyword.IVEC4],
  ['uvec2', EKeyword.UVEC2],
  ['uvec3', EKeyword.UVEC3],
  ['uvec4', EKeyword.UVEC4],
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
  ['sampler3D', EKeyword.SAMPLER3D],
  ['sampler2DShadow', EKeyword.SAMPLER2D_SHADOW],
  ['samplerCubeShadow', EKeyword.SAMPLER_CUBE_SHADOW],
  ['sampler2DArray', EKeyword.SAMPLER2D_ARRAY],
  ['sampler2DArrayShadow', EKeyword.SAMPLER2D_ARRAY_SHADOW],
  ['isampler2D', EKeyword.I_SAMPLER2D],
  ['isampler3D', EKeyword.I_SAMPLER3D],
  ['isamplerCube', EKeyword.I_SAMPLER_CUBE],
  ['isampler2DArray', EKeyword.I_SAMPLER2D_ARRAY],
  ['usampler2D', EKeyword.U_SAMPLER2D],
  ['usampler3D', EKeyword.U_SAMPLER3D],
  ['usamplerCube', EKeyword.U_SAMPLER_CUBE],
  ['usampler2DArray', EKeyword.U_SAMPLER2D_ARRAY],
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
  ['centroid', EKeyword.CENTROID],
  // ['coherent', EKeyword.COHERENT],

  // galacean
  ['Shader', EKeyword.GL_Shader],
  ['SubShader', EKeyword.GL_SubShader],
  ['Pass', EKeyword.GL_Pass],
  ['RenderQueueType', EKeyword.GL_RenderQueueType],
  ['BlendState', EKeyword.GL_BlendState],
  ['DepthState', EKeyword.GL_DepthState],
  ['StencilState', EKeyword.GL_StencilState],
  ['RasterState', EKeyword.GL_RasterState],
  ['EditorProperties', EKeyword.GL_EditorProperties],
  ['EditorMacros', EKeyword.GL_EditorMacros],
  ['Tags', EKeyword.GL_Tags],
  ['ReplacementTag', EKeyword.GL_ReplacementTag],
  ['LightMode', EKeyword.GL_LightMode],
  ['UsePass', EKeyword.GL_UsePass],
  ['VertexShader', EKeyword.GL_VertexShader],
  ['FragmentShader', EKeyword.GL_FragmentShader],

  ['Vector2', EKeyword.GL_Vector2],
  ['Vector3', EKeyword.GL_Vector3],
  ['Vector4', EKeyword.GL_Vector4],
  ['Color', EKeyword.GL_Color],
]);

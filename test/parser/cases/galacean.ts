import { readFileSync } from 'fs';
import Grammar from '../../../src/Grammar';
import {
  ENonTerminal,
  GrammarSymbol,
} from '../../../src/Grammar/GrammarSymbol';
import GrammarUtils from '../../../src/Grammar/Utils';
import Token from '../../../src/Lexer/Token';
import { EKeyword, ETokenType } from '../../../src/Lexer/TokenType';
import SematicAnalyzer, {
  TranslationRule,
} from '../../../src/Parser/SemanticAnalyzer';
import { SymbolInfo, VarSymbol } from '../../../src/Parser/SymbolTable';
import { LocRange } from '../../../src/common/Position';
import { TestCase } from '../types';
import { join } from 'path';
import { ASTNode } from '../../../src/Parser/AST';

const productionAndRules: [GrammarSymbol[], TranslationRule | undefined][] = [
  ...GrammarUtils.createProductionWithOptions(ENonTerminal.gl_shader_program, [
    [
      EKeyword.GL_Shader,
      ETokenType.STRING_CONST,
      ETokenType.LEFT_BRACE,
      ENonTerminal.gl_shader_global_declaration_list,
      ETokenType.RIGHT_BRACE,
    ],
  ]),

  // TODO:
  [
    [
      ENonTerminal.gl_editor_prop_declaration,
      EKeyword.GL_EditorProperties,
      ETokenType.LEFT_BRACE,
      // TODO:
      ETokenType.RIGHT_BRACE,
    ],
    undefined,
  ],

  [
    [
      ENonTerminal.gl_editor_macro_declaration,
      EKeyword.GL_EditorMacros,
      ETokenType.LEFT_BRACE,
      ETokenType.RIGHT_BRACE,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_common_global_declaration,
    [
      [ENonTerminal.gl_variable_declaration],
      [ENonTerminal.gl_render_queue_assignment],
      [ENonTerminal.gl_render_state_assignment],
      [ENonTerminal.struct_specifier],
      [ENonTerminal.function_definition],
      [ENonTerminal.gl_render_state_declaration],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_shader_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_editor_prop_declaration],
      [ENonTerminal.gl_editor_macro_declaration],
      [ENonTerminal.gl_subshader_program],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_shader_global_declaration_list,
    [
      [ETokenType.EPSILON],
      [
        ENonTerminal.gl_shader_global_declaration_list,
        ENonTerminal.gl_shader_global_declaration,
      ],
    ]
  ),

  [
    [
      ENonTerminal.gl_subshader_program,
      EKeyword.GL_SubShader,
      ETokenType.STRING_CONST,
      ENonTerminal.scope_brace,
      ENonTerminal.gl_subshader_global_declaration_list,
      ENonTerminal.scope_end_brace,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_subshader_global_declaration_list,
    [
      [ENonTerminal.gl_subshader_global_declaration],
      [
        ENonTerminal.gl_subshader_global_declaration_list,
        ENonTerminal.gl_subshader_global_declaration,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_subshader_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_tag_specifier],
      [ENonTerminal.gl_pass_program],
      [ENonTerminal.gl_use_pass_declaration],
    ]
  ),

  [
    [
      ENonTerminal.gl_tag_specifier,
      EKeyword.GL_Tags,
      ETokenType.LEFT_BRACE,
      ENonTerminal.gl_tag_assignment_list,
      ETokenType.RIGHT_BRACE,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_tag_assignment_list,
    [
      [ETokenType.EPSILON],
      [ENonTerminal.gl_tag_assignment],
      [
        ENonTerminal.gl_tag_assignment_list,
        ETokenType.SEMICOLON,
        ENonTerminal.gl_tag_assignment,
      ],
    ]
  ),

  [
    [
      ENonTerminal.gl_tag_assignment,
      ENonTerminal.gl_tag_id,
      ETokenType.EQUAL,
      ENonTerminal.gl_tag_value,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.gl_tag_id, [
    [EKeyword.GL_ReplacementTag],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.gl_tag_value, [
    [ETokenType.STRING_CONST],
    [ETokenType.INT_CONSTANT],
  ]),

  [
    [
      ENonTerminal.gl_pass_program,
      EKeyword.GL_Pass,
      ETokenType.STRING_CONST,
      ENonTerminal.scope_brace,
      ENonTerminal.gl_pass_global_declaration_list,
      ENonTerminal.scope_end_brace,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_pass_global_declaration_list,
    [
      [ENonTerminal.gl_pass_global_declaration],
      [
        ENonTerminal.gl_pass_global_declaration_list,
        ENonTerminal.gl_pass_global_declaration,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_pass_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_main_shader_assignment],
      [ENonTerminal.gl_tag_specifier],
    ]
  ),

  [
    [
      ENonTerminal.gl_use_pass_declaration,
      EKeyword.GL_UsePass,
      ETokenType.STRING_CONST,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_state_declaration,
    [
      [
        ENonTerminal.gl_render_state_declarator,
        ETokenType.ID,
        ETokenType.LEFT_BRACE,
        ENonTerminal.gl_render_state_prop_list,
        ETokenType.RIGHT_BRACE,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_state_prop_list,
    [
      [ETokenType.EPSILON],
      [
        ENonTerminal.gl_render_state_prop,
        ENonTerminal.gl_render_state_prop_list,
      ],
    ]
  ),

  // 语义分析检测key值
  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_state_prop,
    [
      [ETokenType.ID, ETokenType.EQUAL, EKeyword.TRUE, ETokenType.SEMICOLON],
      [ETokenType.ID, ETokenType.EQUAL, EKeyword.FALSE, ETokenType.SEMICOLON],
      [ETokenType.ID, ETokenType.EQUAL, ETokenType.ID, ETokenType.SEMICOLON],
      [
        ETokenType.ID,
        ETokenType.EQUAL,
        ETokenType.INT_CONSTANT,
        ETokenType.SEMICOLON,
      ],
      [
        ETokenType.ID,
        ETokenType.EQUAL,
        ETokenType.FLOAT_CONSTANT,
        ETokenType.SEMICOLON,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_state_declarator,
    [
      [EKeyword.GL_BlendState],
      [EKeyword.GL_DepthState],
      [EKeyword.GL_StencilState],
      [EKeyword.GL_RasterState],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_state_assignment,
    [
      [
        ENonTerminal.gl_render_state_declarator,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_declarator,
        ETokenType.LEFT_BRACE,
        ENonTerminal.gl_render_state_prop_list,
        ETokenType.RIGHT_BRACE,
      ],
    ]
  ),

  [
    [
      ENonTerminal.gl_main_shader_assignment,
      ENonTerminal.gl_main_shader_entry,
      ETokenType.EQUAL,
      ETokenType.ID,
      ETokenType.SEMICOLON,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_main_shader_entry,
    [[EKeyword.GL_VertexShader], [EKeyword.GL_FragmentShader]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.gl_render_queue_assignment,
    [
      [
        EKeyword.GL_RenderQueueType,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
      [
        EKeyword.GL_RenderQueueType,
        ETokenType.EQUAL,
        EKeyword.GL_RenderQueueType,
        ETokenType.DOT,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
    ]
  ),

  [
    [
      ENonTerminal.gl_variable_declaration,
      ENonTerminal.fully_specified_type,
      ETokenType.ID,
      ETokenType.SEMICOLON,
    ],
    undefined,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.ext_builtin_type_specifier_nonarray,
    [
      [EKeyword.VOID],
      [EKeyword.FLOAT],
      [EKeyword.BOOL],
      [EKeyword.INT],
      [EKeyword.UINT],
      [EKeyword.VEC2],
      [EKeyword.VEC3],
      [EKeyword.VEC4],
      [EKeyword.BVEC2],
      [EKeyword.BVEC3],
      [EKeyword.BVEC4],
      [EKeyword.IVEC2],
      [EKeyword.IVEC3],
      [EKeyword.IVEC4],
      [EKeyword.UVEC2],
      [EKeyword.UVEC3],
      [EKeyword.UVEC4],
      [EKeyword.MAT2],
      [EKeyword.MAT3],
      [EKeyword.MAT4],
      [EKeyword.MAT2X2],
      [EKeyword.MAT2X3],
      [EKeyword.MAT2X4],
      [EKeyword.MAT3X2],
      [EKeyword.MAT3X3],
      [EKeyword.MAT3X4],
      [EKeyword.MAT4X2],
      [EKeyword.MAT4X3],
      [EKeyword.MAT4X4],
      [EKeyword.SAMPLER2D],
      [EKeyword.SAMPLER3D],
      [EKeyword.SAMPLER_CUBE],
      [EKeyword.SAMPLER2D_SHADOW],
      [EKeyword.SAMPLER_CUBE_SHADOW],
      [EKeyword.SAMPLER2D_ARRAY],
      [EKeyword.SAMPLER2D_ARRAY_SHADOW],
      [EKeyword.I_SAMPLER2D],
      [EKeyword.I_SAMPLER3D],
      [EKeyword.I_SAMPLER_CUBE],
      [EKeyword.I_SAMPLER2D_ARRAY],
      [EKeyword.U_SAMPLER2D],
      [EKeyword.U_SAMPLER3D],
      [EKeyword.U_SAMPLER_CUBE],
      [EKeyword.U_SAMPLER2D_ARRAY],
    ],
    (sa, token) => {}
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.type_specifier_nonarray,
    [[ETokenType.ID], [ENonTerminal.ext_builtin_type_specifier_nonarray]],
    [(sa, id) => {}]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.fully_specified_type,
    [
      [ENonTerminal.type_specifier],
      [ENonTerminal.type_qualifier, ENonTerminal.type_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.type_specifier, [
    [ENonTerminal.type_specifier_nonarray],
    [
      ENonTerminal.ext_builtin_type_specifier_nonarray,
      ENonTerminal.array_specifier_list,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.type_qualifier, [
    [ENonTerminal.single_type_qualifier],
    [ENonTerminal.type_qualifier, ENonTerminal.single_type_qualifier],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.single_type_qualifier,
    [
      [ENonTerminal.storage_qualifier],
      [ENonTerminal.precision_qualifier],
      [ENonTerminal.interpolation_qualifier],
      [ENonTerminal.invariant_qualifier],
      [EKeyword.PRECISE],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.storage_qualifier, [
    [EKeyword.CONST],
    [EKeyword.IN],
    [EKeyword.INOUT],
    [EKeyword.OUT],
    [EKeyword.CENTROID],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.interpolation_qualifier,
    [[EKeyword.SMOOTH], [EKeyword.FLAT]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.invariant_qualifier,
    [[EKeyword.INVARIANT]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.precision_qualifier,
    [[EKeyword.HIGHP], [EKeyword.MEDIUMP], [EKeyword.LOWP]]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.struct_specifier, [
    [
      EKeyword.STRUCT,
      ETokenType.ID,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
    ],
    [
      EKeyword.STRUCT,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.struct_declaration_list,
    [
      [ENonTerminal.struct_declaration],
      [ENonTerminal.struct_declaration_list, ENonTerminal.struct_declaration],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.struct_declaration, [
    [
      ENonTerminal.type_specifier,
      ENonTerminal.struct_declarator_list,
      ETokenType.SEMICOLON,
    ],
    [
      ENonTerminal.type_qualifier,
      ENonTerminal.type_specifier,
      ENonTerminal.struct_declarator_list,
      ETokenType.SEMICOLON,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.struct_declarator_list,
    [
      [ENonTerminal.struct_declarator],
      [
        ENonTerminal.struct_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.struct_declarator,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.struct_declarator, [
    [ETokenType.ID],
    [ETokenType.ID, ENonTerminal.array_specifier_list],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.array_specifier_list,
    [
      [ENonTerminal.array_specifier],
      [ENonTerminal.array_specifier_list, ENonTerminal.array_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.array_specifier, [
    [ETokenType.LEFT_BRACKET, ETokenType.RIGHT_BRACKET],
    [
      ETokenType.LEFT_BRACKET,
      ENonTerminal.integer_constant_expression,
      ETokenType.RIGHT_BRACKET,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.integer_constant_expression_operator,
    [
      [ETokenType.PLUS],
      [ETokenType.DASH],
      [ETokenType.STAR],
      [ETokenType.SLASH],
      [ETokenType.PERCENT],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.integer_constant_expression,
    [
      [ETokenType.ID],
      [ETokenType.INT_CONSTANT],
      [
        ENonTerminal.integer_constant_expression,
        ENonTerminal.integer_constant_expression_operator,
        ETokenType.INT_CONSTANT,
      ],
      [
        ENonTerminal.integer_constant_expression,
        ENonTerminal.integer_constant_expression_operator,
        ETokenType.ID,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.conditional_expression,
    [
      [ENonTerminal.logical_or_expression],
      [
        ENonTerminal.logical_or_expression,
        ETokenType.QUESTION,
        ENonTerminal.expression,
        ETokenType.COLON,
        ENonTerminal.assignment_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.logical_or_expression,
    [
      [ENonTerminal.logical_xor_expression],
      [
        ENonTerminal.logical_or_expression,
        ETokenType.OR_OP,
        ENonTerminal.logical_xor_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.logical_xor_expression,
    [
      [ENonTerminal.logical_and_expression],
      [
        ENonTerminal.logical_xor_expression,
        ETokenType.XOR_OP,
        ENonTerminal.logical_and_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.logical_and_expression,
    [
      [ENonTerminal.inclusive_or_expression],
      [
        ENonTerminal.logical_and_expression,
        ETokenType.AND_OP,
        ENonTerminal.inclusive_or_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.inclusive_or_expression,
    [
      [ENonTerminal.exclusive_or_expression],
      [
        ENonTerminal.inclusive_or_expression,
        ETokenType.VERTICAL_BAR,
        ENonTerminal.exclusive_or_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.exclusive_or_expression,
    [
      [ENonTerminal.and_expression],
      [
        ENonTerminal.exclusive_or_expression,
        ETokenType.CARET,
        ENonTerminal.and_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.and_expression, [
    [ENonTerminal.equality_expression],
    [
      ENonTerminal.and_expression,
      ETokenType.AMPERSAND,
      ENonTerminal.equality_expression,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.equality_expression,
    [
      [ENonTerminal.relational_expression],
      [
        ENonTerminal.equality_expression,
        ETokenType.EQ_OP,
        ENonTerminal.relational_expression,
      ],
      [
        ENonTerminal.equality_expression,
        ETokenType.NE_OP,
        ENonTerminal.relational_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.relational_expression,
    [
      [ENonTerminal.shift_expression],
      [
        ENonTerminal.relational_expression,
        ETokenType.LEFT_ANGLE,
        ENonTerminal.shift_expression,
      ],
      [
        ENonTerminal.relational_expression,
        ETokenType.RIGHT_ANGLE,
        ENonTerminal.shift_expression,
      ],
      [
        ENonTerminal.relational_expression,
        ETokenType.LE_OP,
        ENonTerminal.shift_expression,
      ],
      [
        ENonTerminal.relational_expression,
        ETokenType.GE_OP,
        ENonTerminal.shift_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.shift_expression, [
    [ENonTerminal.additive_expression],
    [
      ENonTerminal.shift_expression,
      ETokenType.LEFT_OP,
      ENonTerminal.additive_expression,
    ],
    [
      ENonTerminal.shift_expression,
      ETokenType.RIGHT_OP,
      ENonTerminal.additive_expression,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.additive_expression,
    [
      [ENonTerminal.multiplicative_expression],
      [
        ENonTerminal.additive_expression,
        ETokenType.PLUS,
        ENonTerminal.multiplicative_expression,
      ],
      [
        ENonTerminal.additive_expression,
        ETokenType.DASH,
        ENonTerminal.multiplicative_expression,
      ],
    ]
  ),

  [
    [ENonTerminal.variable_identifier, ETokenType.ID],
    (sa, id) => {
      console.log('variable:', (<Token>id).lexeme);
    },
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.multiplicative_expression,
    [
      [ENonTerminal.unary_expression],
      [
        ENonTerminal.multiplicative_expression,
        ETokenType.STAR,
        ENonTerminal.unary_expression,
      ],
      [
        ENonTerminal.multiplicative_expression,
        ETokenType.SLASH,
        ENonTerminal.unary_expression,
      ],
      [
        ENonTerminal.multiplicative_expression,
        ETokenType.PERCENT,
        ENonTerminal.unary_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.unary_expression, [
    [ENonTerminal.postfix_expression],
    [ETokenType.INC_OP, ENonTerminal.unary_expression],
    [ETokenType.DEC_OP, ENonTerminal.unary_expression],
    [ENonTerminal.unary_operator, ENonTerminal.unary_expression],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.unary_operator, [
    [ETokenType.PLUS],
    [ETokenType.DASH],
    [ETokenType.BANG],
    [ETokenType.TILDE],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.postfix_expression, [
    [ENonTerminal.primary_expression],
    [
      ENonTerminal.postfix_expression,
      ETokenType.LEFT_BRACKET,
      ENonTerminal.expression,
      ETokenType.RIGHT_BRACKET,
    ],
    [ENonTerminal.function_call],
    [ENonTerminal.postfix_expression, ETokenType.DOT, ETokenType.ID],
    [
      ENonTerminal.postfix_expression,
      ETokenType.DOT,
      ENonTerminal.function_call,
    ],
    [ENonTerminal.postfix_expression, ETokenType.INC_OP],
    [ENonTerminal.postfix_expression, ETokenType.DEC_OP],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.primary_expression, [
    [ENonTerminal.variable_identifier],
    [ETokenType.INT_CONSTANT],
    [ETokenType.FLOAT_CONSTANT],
    [EKeyword.TRUE],
    [EKeyword.FALSE],
    [ETokenType.LEFT_PAREN, ENonTerminal.expression, ETokenType.RIGHT_PAREN],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.expression, [
    [ENonTerminal.assignment_expression],
    [
      ENonTerminal.expression,
      ETokenType.COMMA,
      ENonTerminal.assignment_expression,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.assignment_expression,
    [
      [ENonTerminal.conditional_expression],
      [
        ENonTerminal.unary_expression,
        ENonTerminal.assignment_operator,
        ENonTerminal.assignment_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.assignment_operator,
    [
      [ETokenType.EQUAL],
      [ETokenType.MUL_ASSIGN],
      [ETokenType.DIV_ASSIGN],
      [ETokenType.MOD_ASSIGN],
      [ETokenType.ADD_ASSIGN],
      [ETokenType.SUB_ASSIGN],
      [ETokenType.LEFT_ASSIGN],
      [ETokenType.RIGHT_ASSIGN],
      [ETokenType.AND_ASSIGN],
      [ETokenType.XOR_ASSIGN],
      [ETokenType.OR_ASSIGN],
    ]
  ),

  [[ENonTerminal.function_call, ENonTerminal.function_call_generic], undefined],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_generic,
    [
      [
        ENonTerminal.function_identifier,
        ETokenType.LEFT_PAREN,
        ENonTerminal.function_call_parameter_list,
        ETokenType.RIGHT_PAREN,
      ],
      [
        ENonTerminal.function_identifier,
        ETokenType.LEFT_PAREN,
        ETokenType.RIGHT_PAREN,
      ],
      [ENonTerminal.function_identifier, EKeyword.VOID, ETokenType.RIGHT_PAREN],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_parameter_list,
    [
      [ENonTerminal.assignment_expression],
      [
        ENonTerminal.function_call_parameter_list,
        ETokenType.COMMA,
        ENonTerminal.assignment_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_identifier,
    [[ENonTerminal.type_specifier]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_definition,
    [[ENonTerminal.function_prototype, ENonTerminal.compound_statement]]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.function_prototype, [
    [ENonTerminal.function_declarator, ETokenType.RIGHT_PAREN],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_declarator,
    [
      [ENonTerminal.function_header],
      [ENonTerminal.function_header, ENonTerminal.function_parameter_list],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.function_header, [
    [ENonTerminal.fully_specified_type, ETokenType.ID, ETokenType.LEFT_PAREN],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_parameter_list,
    [
      [ENonTerminal.parameter_declaration],
      [
        ENonTerminal.function_parameter_list,
        ETokenType.COMMA,
        ENonTerminal.parameter_declaration,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_declaration,
    [
      [ENonTerminal.type_qualifier, ENonTerminal.parameter_declarator],
      [ENonTerminal.parameter_declarator],
      [ENonTerminal.type_qualifier, ENonTerminal.type_specifier],
      [ENonTerminal.type_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_declarator,
    [
      [ENonTerminal.type_specifier, ETokenType.ID],
      [
        ENonTerminal.type_specifier,
        ETokenType.ID,
        ENonTerminal.array_specifier_list,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.statement_list, [
    [ENonTerminal.statement],
    [ENonTerminal.statement_list, ENonTerminal.statement],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.statement, [
    [ENonTerminal.compound_statement],
    [ENonTerminal.simple_statement],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.compound_statement, [
    [ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE],
    [
      ENonTerminal.scope_brace,
      ENonTerminal.statement_list,
      ENonTerminal.scope_end_brace,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.simple_statement, [
    [ENonTerminal.declaration],
    [ENonTerminal.expression_statement],
    [ENonTerminal.selection_statement],
    [ENonTerminal.iteration_statement],
    [ENonTerminal.jump_statement],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.declaration, [
    [ENonTerminal.function_prototype, ETokenType.SEMICOLON],
    [ENonTerminal.init_declarator_list, ETokenType.SEMICOLON],
    [
      EKeyword.PRECISION,
      ENonTerminal.precision_qualifier,
      ENonTerminal.ext_builtin_type_specifier_nonarray,
      ETokenType.SEMICOLON,
    ],
    [
      ENonTerminal.type_qualifier,
      ETokenType.ID,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
      ETokenType.SEMICOLON,
    ],
    [
      ENonTerminal.type_qualifier,
      ETokenType.ID,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
      ENonTerminal.decl_identifier,
      ETokenType.SEMICOLON,
    ],
    [
      ENonTerminal.type_qualifier,
      ETokenType.ID,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
      ENonTerminal.decl_identifier,
      ENonTerminal.array_specifier_list,
      ETokenType.SEMICOLON,
    ],
    [ENonTerminal.type_qualifier, ETokenType.ID, ETokenType.SEMICOLON],
    [
      ENonTerminal.type_qualifier,
      ETokenType.ID,
      ENonTerminal.identifier_list,
      ETokenType.SEMICOLON,
    ],
  ]),

  [[ENonTerminal.decl_identifier, ETokenType.ID], undefined],

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.identifier_list, [
    [ETokenType.COMMA, ENonTerminal.decl_identifier],
    [
      ENonTerminal.identifier_list,
      ETokenType.COMMA,
      ENonTerminal.decl_identifier,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.init_declarator_list,
    [
      [ENonTerminal.single_declaration],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.decl_identifier,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.decl_identifier,
        ENonTerminal.array_specifier_list,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.decl_identifier,
        ENonTerminal.array_specifier_list,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.decl_identifier,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.single_declaration,
    [
      [ENonTerminal.fully_specified_type, ENonTerminal.decl_identifier],
      [
        ENonTerminal.fully_specified_type,
        ENonTerminal.decl_identifier,
        ENonTerminal.array_specifier_list,
      ],
      [
        ENonTerminal.fully_specified_type,
        ENonTerminal.decl_identifier,
        ENonTerminal.array_specifier_list,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
      [
        ENonTerminal.fully_specified_type,
        ENonTerminal.decl_identifier,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ],
    []
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.initializer, [
    [ENonTerminal.assignment_expression],
    [
      ETokenType.LEFT_BRACE,
      ENonTerminal.initializer_list,
      ETokenType.RIGHT_BRACE,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.initializer_list, [
    [ENonTerminal.initializer],
    [ENonTerminal.initializer_list, ETokenType.COMMA, ENonTerminal.initializer],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.expression_statement,
    [[ETokenType.SEMICOLON], [ENonTerminal.expression, ETokenType.SEMICOLON]]
  ),

  // dangling else ambiguity
  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.selection_statement,
    [
      [
        EKeyword.IF,
        ETokenType.LEFT_PAREN,
        ENonTerminal.expression,
        ETokenType.RIGHT_PAREN,
        ENonTerminal.statement,
      ],
      [
        EKeyword.IF,
        ETokenType.LEFT_PAREN,
        ENonTerminal.expression,
        ETokenType.RIGHT_PAREN,
        ENonTerminal.statement,
        EKeyword.ELSE,
        ENonTerminal.statement,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.iteration_statement,
    [
      [
        EKeyword.WHILE,
        ETokenType.LEFT_PAREN,
        ENonTerminal.condition,
        ETokenType.RIGHT_PAREN,
        ENonTerminal.statement,
      ],
      [
        EKeyword.FOR,
        ETokenType.LEFT_PAREN,
        ENonTerminal.for_init_statement,
        ENonTerminal.for_rest_statement,
        ETokenType.RIGHT_PAREN,
        ENonTerminal.statement,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.for_init_statement, [
    [ENonTerminal.expression_statement],
    [ENonTerminal.declaration],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.condition, [
    [ENonTerminal.expression],
    [
      ENonTerminal.fully_specified_type,
      ENonTerminal.variable_identifier,
      ETokenType.EQUAL,
      ENonTerminal.initializer,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.for_rest_statement, [
    [ENonTerminal.conditionopt, ETokenType.SEMICOLON],
    [ENonTerminal.conditionopt, ETokenType.SEMICOLON, ENonTerminal.expression],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.conditionopt, [
    [ETokenType.EPSILON],
    [ENonTerminal.condition],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.jump_statement, [
    [EKeyword.CONTINUE, ETokenType.SEMICOLON],
    [EKeyword.BREAK, ETokenType.SEMICOLON],
    [EKeyword.RETURN, ETokenType.SEMICOLON],
    [EKeyword.RETURN, ENonTerminal.expression, ETokenType.SEMICOLON],
    [EKeyword.DISCARD, ETokenType.SEMICOLON],
  ]),

  [
    [ENonTerminal.scope_brace, ETokenType.LEFT_BRACE],
    (sa, leftBrace) => {
      const loc = new LocRange(
        (<Token>leftBrace).position,
        (<Token>leftBrace).position.offset(1)
      );
      ASTNode.create(ASTNode.ScopeBrace, sa, loc);
    },
  ],
  [
    [ENonTerminal.scope_end_brace, ETokenType.RIGHT_BRACE],
    (sa, rightBrace) => {
      const loc = new LocRange(
        (<Token>rightBrace).position,
        (<Token>rightBrace).position.offset(1)
      );
      ASTNode.create(ASTNode.ScopeEndBrace, sa, loc);
    },
  ],
];

const createGrammar = () =>
  Grammar.create(
    ENonTerminal.gl_shader_program,
    productionAndRules.map((item) => item[0])
  );

const addTranslationRule = (sa: SematicAnalyzer) => {
  for (let i = 0; i < productionAndRules.length; i++) {
    const rule = productionAndRules[i][1];
    if (rule) {
      sa.addTranslationRule(i, rule);
    }
  }
};

const source = readFileSync(join(__dirname, 'glsl/demo.gs')).toString();

const testCase: TestCase = {
  createGrammar,
  addTranslationRule,
  source,
};

export default testCase;

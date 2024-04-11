import { readFileSync } from 'fs';
import Grammar from '../../../src/Grammar';
import {
  ENonTerminal,
  GrammarSymbol,
} from '../../../src/Grammar/GrammarSymbol';
import GrammarUtils from '../../../src/Grammar/Utils';
import Token from '../../../src/Lexer/Token';
import { EKeyword, ETokenType } from '../../../src/Lexer/TokenType';
import { DeclarationAst, EType } from '../../../src/Parser/AST';
import SematicAnalyzer, {
  TranslationRule,
} from '../../../src/Parser/SemanticAnalyzer';
import { SymbolInfo } from '../../../src/Parser/SymbolTable';
import { LocRange } from '../../../src/common/Position';
import { TestCase } from '../types';
import { join } from 'path';

const productionAndRules: [GrammarSymbol[], TranslationRule | null][] = [
  ...GrammarUtils.createProductionWithOptions(ENonTerminal.translation_unit, [
    [ENonTerminal.external_declaration],
    [ENonTerminal.translation_unit, ENonTerminal.external_declaration],
  ]),

  [
    [ENonTerminal.variable_identifier, ENonTerminal.variable_identifier_node],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.primary_expression,
    [
      [ENonTerminal.variable_identifier],
      [EKeyword.TRUE],
      [EKeyword.FALSE],
      [ETokenType.INT_CONSTANT],
      [ETokenType.FLOAT_CONSTANT],
      [ETokenType.LEFT_PAREN, ENonTerminal.expression, ETokenType.RIGHT_PAREN],
    ],
    null
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.postfix_expression, [
    [ENonTerminal.primary_expression],
    [
      ENonTerminal.postfix_expression,
      ETokenType.LEFT_BRACKET,
      ENonTerminal.integer_expression,
      ETokenType.RIGHT_BRACKET,
    ],
    [ENonTerminal.function_call],
    [
      ENonTerminal.postfix_expression,
      ETokenType.DOT,
      ENonTerminal.field_selection,
    ],
    [ENonTerminal.postfix_expression, ETokenType.INC_OP],
    [ENonTerminal.postfix_expression, ETokenType.DEC_OP],
  ]),

  [[ENonTerminal.integer_expression, ENonTerminal.expression], null],

  [[ENonTerminal.function_call, ENonTerminal.function_call_generic], null],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_generic,
    [
      [
        ENonTerminal.function_call_header_with_parameters,
        ETokenType.RIGHT_PAREN,
      ],
      [ENonTerminal.function_call_header_no_parameters, ETokenType.RIGHT_PAREN],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_header_no_parameters,
    [
      [ENonTerminal.function_call_header, EKeyword.VOID],
      [ENonTerminal.function_call_header],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_header_with_parameters,
    [
      [ENonTerminal.function_call_header, ENonTerminal.assignment_expression],
      [
        ENonTerminal.function_call_header_with_parameters,
        ETokenType.COMMA,
        ENonTerminal.assignment_expression,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_call_header,
    [[ENonTerminal.function_identifier, ETokenType.LEFT_PAREN]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_identifier,
    [[ENonTerminal.constructor_identifier], [ETokenType.ID]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.constructor_identifier,
    [[ENonTerminal.basic_type]]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.unary_expression, [
    [ENonTerminal.postfix_expression],
    [ENonTerminal.unary_operator, ENonTerminal.unary_expression],
    [ETokenType.INC_OP, ENonTerminal.unary_expression],
    [ETokenType.DEC_OP, ENonTerminal.unary_expression],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.unary_operator, [
    [ETokenType.PLUS],
    [ETokenType.DASH],
    [ETokenType.BANG],
    [ETokenType.TILDE],
  ]),

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
    ]
  ),

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

  [[ENonTerminal.shift_expression, ENonTerminal.additive_expression], null],

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

  [[ENonTerminal.and_expression, ENonTerminal.equality_expression], null],

  [[ENonTerminal.inclusive_or_expression, ENonTerminal.and_expression], null],

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

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.expression, [
    [ENonTerminal.assignment_expression],
    [
      ENonTerminal.expression,
      ETokenType.COMMA,
      ENonTerminal.assignment_expression,
    ],
  ]),

  [
    [ENonTerminal.constant_expression, ENonTerminal.conditional_expression],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.declaration, [
    [ENonTerminal.function_prototype, ETokenType.SEMICOLON],
    [ENonTerminal.init_declarator_list, ETokenType.SEMICOLON],
    [
      EKeyword.PRECISION,
      ENonTerminal.precision_qualifier,
      ENonTerminal.type_specifier_no_prec,
      ETokenType.SEMICOLON,
    ],
  ]),

  [
    [
      ENonTerminal.function_prototype,
      ENonTerminal.function_declarator,
      ETokenType.RIGHT_PAREN,
    ],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_declarator,
    [
      [ENonTerminal.function_header],
      [ENonTerminal.function_header_with_parameters],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.function_header_with_parameters,
    [
      [ENonTerminal.function_header, ENonTerminal.parameter_declaration],
      [
        ENonTerminal.function_header_with_parameters,
        ETokenType.COMMA,
        ENonTerminal.parameter_declaration,
      ],
    ]
  ),

  [
    [
      ENonTerminal.function_header,
      ENonTerminal.fully_specified_type,
      ENonTerminal.function_identifier_node,
      ETokenType.LEFT_PAREN,
    ],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_declarator,
    [
      [ENonTerminal.type_specifier, ENonTerminal.variable_identifier_node],
      [
        ENonTerminal.type_specifier,
        ENonTerminal.variable_identifier_node,
        ETokenType.LEFT_BRACKET,
        ENonTerminal.constant_expression,
        ETokenType.RIGHT_BRACKET,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_declaration,
    [
      [
        ENonTerminal.type_qualifier,
        ENonTerminal.parameter_qualifier,
        ENonTerminal.parameter_declarator,
      ],
      [ENonTerminal.parameter_qualifier, ENonTerminal.parameter_declarator],
      [
        ENonTerminal.type_qualifier,
        ENonTerminal.parameter_qualifier,
        ENonTerminal.parameter_type_specifier,
      ],
      [ENonTerminal.parameter_qualifier, ENonTerminal.parameter_type_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_qualifier,
    [[EKeyword.IN], [EKeyword.OUT], [EKeyword.INOUT], [ETokenType.EPSILON]]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.parameter_type_specifier,
    [
      [ENonTerminal.type_specifier],
      [
        ENonTerminal.type_specifier,
        ETokenType.LEFT_BRACKET,
        ENonTerminal.constant_expression,
        ETokenType.RIGHT_BRACKET,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.init_declarator_list,
    [
      [ENonTerminal.single_declaration],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.variable_identifier_node,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.variable_identifier_node,
        ETokenType.LEFT_BRACKET,
        ENonTerminal.conditional_expression,
        ETokenType.RIGHT_BRACKET,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.variable_identifier_node,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.single_declaration, [
    [ENonTerminal.struct_specifier],
    [ENonTerminal.type_qualifier, ENonTerminal.struct_specifier],
    [ENonTerminal.fully_specified_type, ENonTerminal.variable_identifier_node],
    [
      ENonTerminal.fully_specified_type,
      ENonTerminal.variable_identifier_node,
      ETokenType.LEFT_BRACKET,
      ENonTerminal.constant_expression,
      ETokenType.RIGHT_BRACKET,
    ],
    [
      ENonTerminal.fully_specified_type,
      ENonTerminal.variable_identifier_node,
      ETokenType.EQUAL,
      ENonTerminal.initializer,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.fully_specified_type,
    [
      [ENonTerminal.type_specifier],
      [ENonTerminal.type_qualifier, ENonTerminal.type_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.type_qualifier, [
    [EKeyword.CONST],
    [EKeyword.ATTRIBUTE],
    [EKeyword.UNIFORM],
    [EKeyword.VARYING],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.type_specifier, [
    [ENonTerminal.type_specifier_no_prec],
    [ENonTerminal.precision_qualifier, ENonTerminal.type_specifier_no_prec],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.type_specifier_no_prec,
    [
      [ENonTerminal.basic_type],
      [ENonTerminal.typename_identifier_node],
      [ENonTerminal.struct_specifier],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.basic_type, [
    [EKeyword.FLOAT],
    [EKeyword.VEC2],
    [EKeyword.VEC3],
    [EKeyword.VEC4],
    [EKeyword.INT],
    [EKeyword.IVEC2],
    [EKeyword.IVEC3],
    [EKeyword.IVEC4],
    [EKeyword.BOOL],
    [EKeyword.BVEC2],
    [EKeyword.BVEC3],
    [EKeyword.BVEC4],
    [EKeyword.MAT2],
    [EKeyword.MAT3],
    [EKeyword.MAT4],
    [EKeyword.VOID],
    [EKeyword.SAMPLER2D],
    [EKeyword.SAMPLER_CUBE],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.struct_specifier, [
    [
      EKeyword.STRUCT,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declaration_list,
      ETokenType.RIGHT_BRACE,
    ],
    [
      EKeyword.STRUCT,
      ENonTerminal.typename_identifier_node,
      ETokenType.LEFT_BRACE,
      ENonTerminal.struct_declarator_list,
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

  [
    [
      ENonTerminal.struct_declaration,
      ENonTerminal.type_specifier,
      ENonTerminal.struct_declarator_list,
      ETokenType.SEMICOLON,
    ],
    null,
  ],

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
    [ENonTerminal.variable_identifier_node],
    [
      ENonTerminal.variable_identifier_node,
      ETokenType.LEFT_BRACKET,
      ENonTerminal.constant_expression,
      ETokenType.RIGHT_BRACKET,
    ],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.precision_qualifier,
    [[EKeyword.HIGHP], [EKeyword.MEDIUMP], [EKeyword.LOWP]]
  ),

  [[ENonTerminal.initializer, ENonTerminal.assignment_expression], null],

  [[ENonTerminal.declaration_statement, ENonTerminal.declaration], null],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.statement_no_new_scope,
    [
      [ENonTerminal.compound_statement_with_scope],
      [ENonTerminal.simple_statement],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.simple_statement, [
    [ENonTerminal.declaration_statement],
    [ENonTerminal.expression_statement],
    [ENonTerminal.selection_statement],
    [ENonTerminal.iteration_statement],
    [ENonTerminal.jump_statement],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.compound_statement_with_scope,
    [
      [ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE],
      [
        ETokenType.LEFT_BRACE,
        ENonTerminal.statement_list,
        ETokenType.RIGHT_BRACE,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.statement_with_scope,
    [
      [ENonTerminal.compound_statement_no_new_scope],
      [ENonTerminal.simple_statement],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.compound_statement_no_new_scope,
    [
      [ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE],
      [
        ETokenType.LEFT_BRACE,
        ENonTerminal.statement_list,
        ETokenType.RIGHT_BRACE,
      ],
    ]
  ),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.statement_list, [
    [ENonTerminal.statement_no_new_scope],
    [ENonTerminal.statement_list, ENonTerminal.statement_no_new_scope],
  ]),

  [
    [
      ENonTerminal.iteration_statement_no_new_scope,
      ENonTerminal.statement_no_new_scope,
    ],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.expression_statement,
    [[ETokenType.SEMICOLON], [ENonTerminal.expression, ETokenType.SEMICOLON]]
  ),

  [
    [
      ENonTerminal.selection_statement,
      EKeyword.IF,
      ETokenType.LEFT_PAREN,
      ENonTerminal.expression,
      ETokenType.RIGHT_PAREN,
      ENonTerminal.selection_rest_statement,
    ],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.selection_rest_statement,
    [
      [
        ENonTerminal.statement_with_scope,
        EKeyword.ELSE,
        ENonTerminal.statement_with_scope,
      ],
      [ENonTerminal.statement_with_scope],
    ]
  ),

  [[ENonTerminal.condition, ENonTerminal.expression], null],

  [
    [
      ENonTerminal.iteration_statement,
      EKeyword.FOR,
      ETokenType.LEFT_PAREN,
      ENonTerminal.for_init_statement,
      ENonTerminal.for_rest_statement,
      ETokenType.RIGHT_PAREN,
      ENonTerminal.iteration_statement_no_new_scope,
    ],
    null,
  ],

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.for_init_statement, [
    [ENonTerminal.expression_statement],
    [ENonTerminal.declaration_statement],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.for_rest_statement, [
    [ENonTerminal.condition, ETokenType.SEMICOLON],
    [ENonTerminal.condition, ETokenType.SEMICOLON, ENonTerminal.expression],
    [ETokenType.SEMICOLON, ENonTerminal.expression],
    [ETokenType.SEMICOLON],
  ]),

  ...GrammarUtils.createProductionWithOptions(ENonTerminal.jump_statement, [
    [EKeyword.CONTINUE, ETokenType.SEMICOLON],
    [EKeyword.BREAK, ETokenType.SEMICOLON],
    [EKeyword.RETURN, ETokenType.SEMICOLON],
    [EKeyword.RETURN, ENonTerminal.expression, ETokenType.SEMICOLON],
    [EKeyword.DISCARD, ETokenType.SEMICOLON],
  ]),

  ...GrammarUtils.createProductionWithOptions(
    ENonTerminal.external_declaration,
    [[ENonTerminal.function_definition], [ENonTerminal.declaration]]
  ),

  [
    [
      ENonTerminal.function_definition,
      ENonTerminal.function_prototype,
      ENonTerminal.compound_statement_no_new_scope,
    ],
    null,
  ],

  [[ENonTerminal.field_selection, ENonTerminal.variable_identifier_node], null],

  [[ENonTerminal.variable_identifier_node, ETokenType.ID], null],

  [[ENonTerminal.function_identifier_node, ETokenType.ID], null],

  [[ENonTerminal.typename_identifier_node, ETokenType.ID], null],
];

const createGrammar = () =>
  Grammar.create(
    ENonTerminal.translation_unit,
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

const source = readFileSync(join(__dirname, 'glsl/demo.glsl')).toString();

const testCase: TestCase = {
  createGrammar,
  addTranslationRule,
  source,
};

export default testCase;

import { TokenType } from '../Lexer/TokenType';

export type Terminal = TokenType;

export enum ENonTerminal {
  START = 2000,
  // galacean
  gl_shader_program,
  gl_editor_prop_declaration,
  gl_editor_macro_declaration,
  gl_common_global_declaration,
  gl_shader_global_declaration,
  gl_shader_global_declaration_list,
  gl_subshader_program,
  gl_subshader_global_declaration_list,
  gl_subshader_global_declaration,
  gl_tag_specifier,
  gl_tag_assignment_list,
  gl_tag_assignment,
  gl_tag_id,
  gl_tag_value,
  gl_pass_program,
  gl_pass_global_declaration_list,
  gl_pass_global_declaration,
  gl_use_pass_declaration,
  gl_render_state_declarator,
  gl_render_state_assignment,
  gl_render_state_declaration,
  gl_render_state_prop_list,
  gl_render_state_prop,
  gl_main_shader_entry,
  gl_main_shader_assignment,
  gl_render_queue_assignment,
  gl_variable_declaration,
  array_specifier_list,
  array_specifier,

  ext_builtin_type_specifier_nonarray,

  // glsl
  translation_unit,
  variable_identifier,
  variable_identifier_node,
  primary_expression,
  postfix_expression,
  integer_expression,
  function_call,
  function_call_generic,
  function_call_header_no_parameters,
  function_call_header_with_parameters,
  function_call_parameter_list,
  function_call_header,
  function_identifier,
  constructor_identifier,
  unary_expression,
  unary_operator,
  multiplicative_expression,
  additive_expression,
  shift_expression,
  relational_expression,
  equality_expression,
  and_expression,
  inclusive_or_expression,
  exclusive_or_expression,
  logical_and_expression,
  logical_xor_expression,
  logical_or_expression,
  conditional_expression,
  assignment_expression,
  assignment_operator,
  expression,
  constant_expression,
  declaration,
  function_prototype,
  function_declarator,
  function_header_with_parameters,
  function_header,
  function_parameter_list,
  parameter_declarator,
  parameter_declaration,
  parameter_qualifier,
  parameter_type_specifier,
  init_declarator_list,
  single_declaration,
  fully_specified_type,
  type_qualifier,
  single_type_qualifier,
  storage_qualifier,
  precision_qualifier,
  interpolation_qualifier,
  invariant_qualifier,
  type_specifier,
  type_specifier_nonarray,
  type_specifier_no_prec,
  basic_type,
  struct_specifier,
  struct_declaration_list,
  struct_declaration,
  struct_declarator_list,
  struct_declarator,
  identifier_list,
  decl_identifier,
  initializer,
  initializer_list,
  declaration_statement,
  simple_statement,
  compound_statement_with_scope,
  statement_with_scope,
  compound_statement,
  statement,
  statement_list,
  iteration_statement_no_new_scope,
  expression_statement,
  selection_statement,
  selection_rest_statement,
  condition,
  conditionopt,
  iteration_statement,
  for_init_statement,
  for_rest_statement,
  jump_statement,
  external_declaration,
  function_definition,
  field_selection,
  bool_constant,
  function_identifier_node,
  typename_identifier_node,

  // TEST:
  E,
  T,
  X,
  Y,
  S,
  A,
  F,
  C,
  B,
  D,
  G,
  L,
  R,
  exp,
  term,
  factor,
  program,
  statements,
  assignment,
  block,
  type,
  ifStmt,
  elsePart,
  init,
  relOp,
  logicExp,
  // TEST: end
}

export type GrammarSymbol = Terminal | ENonTerminal;

export type Derivation = GrammarSymbol[];

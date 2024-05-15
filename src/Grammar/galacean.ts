import { readFileSync } from 'fs';
import Grammar from '.';
import { ENonTerminal, GrammarSymbol } from './GrammarSymbol';
import GrammarUtils from './Utils';
import { EKeyword, ETokenType } from '../Lexer/TokenType';
import SematicAnalyzer, { TranslationRule } from '../Parser/SemanticAnalyzer';
import { TestCase } from '../../test/parser/types';
import { join } from 'path';
import { ASTNode } from '../Parser/AST';

const productionAndRules: [GrammarSymbol[], TranslationRule | undefined][] = [
  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_shader_program,
    [
      [
        EKeyword.GL_Shader,
        ETokenType.STRING_CONST,
        ETokenType.LEFT_BRACE,
        ENonTerminal.gl_shader_global_declaration_list,
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.GLShaderProgram
  ),

  // TODO:
  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_editor_prop_declaration,
    [
      [
        EKeyword.GL_EditorProperties,
        ETokenType.LEFT_BRACE,
        // TODO:
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.GLEditorPropDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_editor_macro_declaration,
    [[EKeyword.GL_EditorMacros, ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE]],
    ASTNode.GLEditorMacroDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_common_global_declaration,
    [
      [ENonTerminal.gl_variable_declaration],
      [ENonTerminal.gl_render_queue_assignment],
      [ENonTerminal.gl_render_state_assignment],
      [ENonTerminal.struct_specifier],
      [ENonTerminal.function_definition],
      [ENonTerminal.gl_render_state_declaration],
    ],
    ASTNode.GLCommonGlobalDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_shader_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_editor_prop_declaration],
      [ENonTerminal.gl_editor_macro_declaration],
      [ENonTerminal.gl_subshader_program],
    ],
    ASTNode.GLShaderGlobalDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_shader_global_declaration_list,
    [
      [ENonTerminal.gl_shader_global_declaration],
      [
        ENonTerminal.gl_shader_global_declaration_list,
        ENonTerminal.gl_shader_global_declaration,
      ],
    ],
    ASTNode.GLShaderGlobalDeclarationList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_subshader_program,
    [
      [
        EKeyword.GL_SubShader,
        ETokenType.STRING_CONST,
        ENonTerminal.subshader_scope_brace,
        ENonTerminal.gl_subshader_global_declaration_list,
        ENonTerminal.scope_end_brace,
      ],
    ],
    ASTNode.GLSubShaderProgram
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_subshader_global_declaration_list,
    [
      [ENonTerminal.gl_subshader_global_declaration],
      [
        ENonTerminal.gl_subshader_global_declaration_list,
        ENonTerminal.gl_subshader_global_declaration,
      ],
    ],
    ASTNode.GLSubShaderGlobalDeclarationList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_subshader_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_tag_specifier],
      [ENonTerminal.gl_pass_program],
      [ENonTerminal.gl_use_pass_declaration],
    ],
    ASTNode.GLSubShaderGlobalDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_tag_specifier,
    [
      [
        EKeyword.GL_Tags,
        ETokenType.LEFT_BRACE,
        ENonTerminal.gl_tag_assignment_list,
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.GLTagSpecifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_tag_assignment_list,
    [
      [ETokenType.EPSILON],
      [ENonTerminal.gl_tag_assignment],
      [
        ENonTerminal.gl_tag_assignment_list,
        ETokenType.COMMA,
        ENonTerminal.gl_tag_assignment,
      ],
    ],
    ASTNode.GLTagAssignmentList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_tag_assignment,
    [[ENonTerminal.gl_tag_id, ETokenType.EQUAL, ENonTerminal.gl_tag_value]],
    ASTNode.GLTagAssignment
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_tag_id,
    [
      [EKeyword.GL_ReplacementTag],
      [EKeyword.GL_LightMode],
      [EKeyword.GL_PipelineStage],
    ],
    ASTNode.GLTagId
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_tag_value,
    [
      [ETokenType.STRING_CONST],
      [ETokenType.INT_CONSTANT],
      [EKeyword.TRUE],
      [EKeyword.FALSE],
    ],
    ASTNode.GLTagValue
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_pass_program,
    [
      [
        EKeyword.GL_Pass,
        ETokenType.STRING_CONST,
        ENonTerminal.pass_scope_brace,
        ENonTerminal.gl_pass_global_declaration_list,
        ENonTerminal.scope_end_brace,
      ],
    ],
    ASTNode.GLPassProgram
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_pass_global_declaration_list,
    [
      [ENonTerminal.gl_pass_global_declaration],
      [
        ENonTerminal.gl_pass_global_declaration_list,
        ENonTerminal.gl_pass_global_declaration,
      ],
    ],
    ASTNode.GLPassGlobalDeclarationList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_pass_global_declaration,
    [
      [ENonTerminal.gl_common_global_declaration],
      [ENonTerminal.gl_main_shader_assignment],
      [ENonTerminal.gl_tag_specifier],
      [ENonTerminal.precision_specifier],
    ],
    ASTNode.GLPassGlobalDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_use_pass_declaration,
    [[EKeyword.GL_UsePass, ETokenType.STRING_CONST]],
    ASTNode.GLUsePassDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_state_declaration,
    [
      [
        ENonTerminal.gl_render_state_declarator,
        ETokenType.ID,
        ETokenType.LEFT_BRACE,
        ENonTerminal.gl_render_state_prop_list,
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.GLRenderStateDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_state_prop_list,
    [
      [ENonTerminal.gl_render_state_prop_assignment],
      [
        ENonTerminal.gl_render_state_prop_assignment,
        ENonTerminal.gl_render_state_prop_list,
      ],
    ],
    ASTNode.GLRenderStatePropList
  ),

  // 语义分析检测key值
  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_state_prop_assignment,
    [
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        EKeyword.TRUE,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        EKeyword.FALSE,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.DOT,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        ETokenType.INT_CONSTANT,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        ETokenType.FLOAT_CONSTANT,
        ETokenType.SEMICOLON,
      ],
      [
        ENonTerminal.gl_render_state_prop,
        ETokenType.EQUAL,
        ENonTerminal.gl_engine_type_init,
        ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.GLRenderStatePropAssignment
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_engine_type,
    [
      [EKeyword.GL_Vector2],
      [EKeyword.GL_Vector3],
      [EKeyword.GL_Vector4],
      [EKeyword.GL_Color],
    ],
    ASTNode.GLEngineType
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_engine_type_init,
    [
      [
        ENonTerminal.gl_engine_type,
        ETokenType.LEFT_PAREN,
        ENonTerminal.gl_engine_type_init_param_list,
        ETokenType.RIGHT_PAREN,
      ],
    ],
    ASTNode.GLEngineTypeInit
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_engine_type_init_param_list,
    [
      [ETokenType.INT_CONSTANT],
      [ETokenType.FLOAT_CONSTANT],
      [
        ENonTerminal.gl_engine_type_init_param_list,
        ETokenType.COMMA,
        ETokenType.INT_CONSTANT,
      ],
      [
        ENonTerminal.gl_engine_type_init_param_list,
        ETokenType.COMMA,
        ETokenType.FLOAT_CONSTANT,
      ],
    ],
    ASTNode.GLEngineTypeInitParamList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_state_prop,
    [
      [
        ETokenType.ID,
        ETokenType.LEFT_BRACKET,
        ETokenType.INT_CONSTANT,
        ETokenType.RIGHT_BRACKET,
      ],
      [ETokenType.ID],
    ],
    ASTNode.GLRenderStateProp
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_state_declarator,
    [
      [EKeyword.GL_BlendState],
      [EKeyword.GL_DepthState],
      [EKeyword.GL_StencilState],
      [EKeyword.GL_RasterState],
    ],
    ASTNode.GLRenderStateDeclarator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.GLRenderStateAssignment
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_main_shader_assignment,
    [
      [
        ENonTerminal.gl_main_shader_entry,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.GLMainShaderAssignment
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_main_shader_entry,
    [[EKeyword.GL_VertexShader], [EKeyword.GL_FragmentShader]],
    ASTNode.GLMainShaderEntry
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_render_queue_assignment,
    [
      [
        EKeyword.GL_RenderQueueType,
        ETokenType.EQUAL,
        ETokenType.ID,
        ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.GLRenderQueueAssignment
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.gl_variable_declaration,
    [
      [EKeyword.GL_RenderQueueType, ETokenType.ID, ETokenType.SEMICOLON],
      [ENonTerminal.fully_specified_type, ETokenType.ID, ETokenType.SEMICOLON],
    ],
    ASTNode.GLVariableDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ASTNode.ExtBuiltinTypeSpecifierNonArray
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.type_specifier_nonarray,
    [[ETokenType.ID], [ENonTerminal.ext_builtin_type_specifier_nonarray]],
    ASTNode.TypeSpecifierNonArray
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.fully_specified_type,
    [
      [ENonTerminal.type_specifier],
      [ENonTerminal.type_qualifier, ENonTerminal.type_specifier],
    ],
    ASTNode.FullySpecifiedType
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.type_specifier,
    [
      [ENonTerminal.type_specifier_nonarray],
      [
        ENonTerminal.ext_builtin_type_specifier_nonarray,
        ENonTerminal.array_specifier,
      ],
    ],
    ASTNode.TypeSpecifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.type_qualifier,
    [
      [ENonTerminal.single_type_qualifier],
      [ENonTerminal.type_qualifier, ENonTerminal.single_type_qualifier],
    ],
    ASTNode.TypeQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.single_type_qualifier,
    [
      [ENonTerminal.storage_qualifier],
      [ENonTerminal.precision_qualifier],
      [ENonTerminal.interpolation_qualifier],
      [ENonTerminal.invariant_qualifier],
      [EKeyword.PRECISE],
    ],
    ASTNode.SingleTypeQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.storage_qualifier,
    [
      [EKeyword.CONST],
      [EKeyword.IN],
      [EKeyword.INOUT],
      [EKeyword.OUT],
      [EKeyword.CENTROID],
    ],
    ASTNode.StorageQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.interpolation_qualifier,
    [[EKeyword.SMOOTH], [EKeyword.FLAT]],
    ASTNode.InterpolationQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.invariant_qualifier,
    [[EKeyword.INVARIANT]],
    ASTNode.InvariantQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.precision_qualifier,
    [[EKeyword.HIGHP], [EKeyword.MEDIUMP], [EKeyword.LOWP]],
    ASTNode.PrecisionQualifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.struct_specifier,
    [
      [
        EKeyword.STRUCT,
        ETokenType.ID,
        ETokenType.LEFT_BRACE,
        ENonTerminal.struct_declaration_list,
        ETokenType.RIGHT_BRACE,
        // ETokenType.SEMICOLON,
      ],
      [
        EKeyword.STRUCT,
        ETokenType.LEFT_BRACE,
        ENonTerminal.struct_declaration_list,
        ETokenType.RIGHT_BRACE,
        // ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.StructSpecifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.struct_declaration_list,
    [
      [ENonTerminal.struct_declaration],
      [ENonTerminal.struct_declaration_list, ENonTerminal.struct_declaration],
    ],
    ASTNode.StructDeclarationList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.struct_declaration,
    [
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
    ],
    ASTNode.StructDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.struct_declarator_list,
    [
      [ENonTerminal.struct_declarator],
      [
        ENonTerminal.struct_declarator_list,
        ETokenType.COMMA,
        ENonTerminal.struct_declarator,
      ],
    ],
    ASTNode.StructDeclaratorList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.struct_declarator,
    [[ETokenType.ID], [ETokenType.ID, ENonTerminal.array_specifier]],
    ASTNode.StructDeclarator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.array_specifier,
    [
      [ETokenType.LEFT_BRACKET, ETokenType.RIGHT_BRACKET],
      [
        ETokenType.LEFT_BRACKET,
        ENonTerminal.integer_constant_expression,
        ETokenType.RIGHT_BRACKET,
      ],
    ],
    ASTNode.ArraySpecifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.integer_constant_expression_operator,
    [
      [ETokenType.PLUS],
      [ETokenType.DASH],
      [ETokenType.STAR],
      [ETokenType.SLASH],
      [ETokenType.PERCENT],
    ],
    ASTNode.IntegerConstantExpressionOperator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.integer_constant_expression,
    [
      [ENonTerminal.variable_identifier],
      [ETokenType.INT_CONSTANT],
      [
        ENonTerminal.integer_constant_expression,
        ENonTerminal.integer_constant_expression_operator,
        ETokenType.INT_CONSTANT,
      ],
      [
        ENonTerminal.integer_constant_expression,
        ENonTerminal.integer_constant_expression_operator,
        ENonTerminal.variable_identifier,
      ],
    ],
    ASTNode.IntegerConstantExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.ConditionalExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.logical_or_expression,
    [
      [ENonTerminal.logical_xor_expression],
      [
        ENonTerminal.logical_or_expression,
        ETokenType.OR_OP,
        ENonTerminal.logical_xor_expression,
      ],
    ],
    ASTNode.LogicalOrExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.logical_xor_expression,
    [
      [ENonTerminal.logical_and_expression],
      [
        ENonTerminal.logical_xor_expression,
        ETokenType.XOR_OP,
        ENonTerminal.logical_and_expression,
      ],
    ],
    ASTNode.LogicalXorExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.logical_and_expression,
    [
      [ENonTerminal.inclusive_or_expression],
      [
        ENonTerminal.logical_and_expression,
        ETokenType.AND_OP,
        ENonTerminal.inclusive_or_expression,
      ],
    ],
    ASTNode.LogicalAndExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.inclusive_or_expression,
    [
      [ENonTerminal.exclusive_or_expression],
      [
        ENonTerminal.inclusive_or_expression,
        ETokenType.VERTICAL_BAR,
        ENonTerminal.exclusive_or_expression,
      ],
    ],
    ASTNode.InclusiveOrExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.exclusive_or_expression,
    [
      [ENonTerminal.and_expression],
      [
        ENonTerminal.exclusive_or_expression,
        ETokenType.CARET,
        ENonTerminal.and_expression,
      ],
    ],
    ASTNode.ExclusiveOrExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.and_expression,
    [
      [ENonTerminal.equality_expression],
      [
        ENonTerminal.and_expression,
        ETokenType.AMPERSAND,
        ENonTerminal.equality_expression,
      ],
    ],
    ASTNode.AndExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.EqualityExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.RelationalExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.shift_expression,
    [
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
    ],
    ASTNode.ShiftExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.AdditiveExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.MultiplicativeExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.unary_expression,
    [
      [ENonTerminal.postfix_expression],
      [ETokenType.INC_OP, ENonTerminal.unary_expression],
      [ETokenType.DEC_OP, ENonTerminal.unary_expression],
      [ENonTerminal.unary_operator, ENonTerminal.unary_expression],
    ],
    ASTNode.UnaryExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.unary_operator,
    [
      [ETokenType.PLUS],
      [ETokenType.DASH],
      [ETokenType.BANG],
      [ETokenType.TILDE],
    ],
    ASTNode.UnaryOperator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.postfix_expression,
    [
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
    ],
    ASTNode.PostfixExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.primary_expression,
    [
      [ENonTerminal.variable_identifier],
      [ETokenType.INT_CONSTANT],
      [ETokenType.FLOAT_CONSTANT],
      [EKeyword.TRUE],
      [EKeyword.FALSE],
      [ETokenType.LEFT_PAREN, ENonTerminal.expression, ETokenType.RIGHT_PAREN],
    ],
    ASTNode.PrimaryExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.expression,
    [
      [ENonTerminal.assignment_expression],
      [
        ENonTerminal.expression,
        ETokenType.COMMA,
        ENonTerminal.assignment_expression,
      ],
    ],
    ASTNode.Expression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.assignment_expression,
    [
      [ENonTerminal.conditional_expression],
      [
        ENonTerminal.unary_expression,
        ENonTerminal.assignment_operator,
        ENonTerminal.assignment_expression,
      ],
    ],
    ASTNode.AssignmentExpression
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.AssignmentOperator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_call,
    [[ENonTerminal.function_call_generic]],
    ASTNode.FunctionCall
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.FunctionCallGeneric
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_call_parameter_list,
    [
      [ENonTerminal.assignment_expression],
      [
        ENonTerminal.function_call_parameter_list,
        ETokenType.COMMA,
        ENonTerminal.assignment_expression,
      ],
    ],
    ASTNode.FunctionCallParameterList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_identifier,
    [[ENonTerminal.type_specifier]],
    ASTNode.FunctionIdentifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_definition,
    [
      [
        ENonTerminal.function_prototype,
        ENonTerminal.compound_statement_no_scope,
      ],
    ],
    ASTNode.FunctionDefinition
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_prototype,
    [[ENonTerminal.function_declarator, ETokenType.RIGHT_PAREN]],
    ASTNode.FunctionProtoType
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_declarator,
    [
      [ENonTerminal.function_header],
      [ENonTerminal.function_header, ENonTerminal.function_parameter_list],
    ],
    ASTNode.FunctionDeclarator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_header,
    [[ENonTerminal.fully_specified_type, ETokenType.ID, ETokenType.LEFT_PAREN]],
    ASTNode.FunctionHeader
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.function_parameter_list,
    [
      [ENonTerminal.parameter_declaration],
      [
        ENonTerminal.function_parameter_list,
        ETokenType.COMMA,
        ENonTerminal.parameter_declaration,
      ],
    ],
    ASTNode.FunctionParameterList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.parameter_declaration,
    [
      [ENonTerminal.type_qualifier, ENonTerminal.parameter_declarator],
      [ENonTerminal.parameter_declarator],
    ],
    ASTNode.ParameterDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.parameter_declarator,
    [
      [ENonTerminal.type_specifier, ETokenType.ID],
      [
        ENonTerminal.type_specifier,
        ETokenType.ID,
        ENonTerminal.array_specifier,
      ],
    ],
    ASTNode.ParameterDeclarator
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.statement_list,
    [
      [ENonTerminal.statement],
      [ENonTerminal.statement_list, ENonTerminal.statement],
    ],
    ASTNode.StatementList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.statement,
    [[ENonTerminal.compound_statement], [ENonTerminal.simple_statement]],
    ASTNode.Statement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.compound_statement_no_scope,
    [
      [ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE],
      [
        ETokenType.LEFT_BRACE,
        ENonTerminal.statement_list,
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.CompoundStatementNoScope
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.compound_statement,
    [
      [ETokenType.LEFT_BRACE, ETokenType.RIGHT_BRACE],
      [
        ENonTerminal.scope_brace,
        ENonTerminal.statement_list,
        ENonTerminal.scope_end_brace,
      ],
    ],
    ASTNode.CompoundStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.simple_statement,
    [
      [ENonTerminal.declaration],
      [ENonTerminal.expression_statement],
      [ENonTerminal.selection_statement],
      [ENonTerminal.iteration_statement],
      [ENonTerminal.jump_statement],
    ],
    ASTNode.SimpleStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.declaration,
    [
      [ENonTerminal.function_prototype, ETokenType.SEMICOLON],
      [ENonTerminal.init_declarator_list, ETokenType.SEMICOLON],
      [
        EKeyword.PRECISION,
        ENonTerminal.precision_qualifier,
        ENonTerminal.ext_builtin_type_specifier_nonarray,
        ETokenType.SEMICOLON,
      ],
      [ENonTerminal.type_qualifier, ETokenType.ID, ETokenType.SEMICOLON],
      [
        ENonTerminal.type_qualifier,
        ETokenType.ID,
        ENonTerminal.identifier_list,
        ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.Declaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.identifier_list,
    [
      [ETokenType.COMMA, ETokenType.ID],
      [ENonTerminal.identifier_list, ETokenType.COMMA, ETokenType.ID],
    ],
    ASTNode.IdentifierList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.init_declarator_list,
    [
      [ENonTerminal.single_declaration],
      [ENonTerminal.init_declarator_list, ETokenType.COMMA, ETokenType.ID],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ETokenType.ID,
        ENonTerminal.array_specifier,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ETokenType.ID,
        ENonTerminal.array_specifier,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
      [
        ENonTerminal.init_declarator_list,
        ETokenType.COMMA,
        ETokenType.ID,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ],
    ASTNode.InitDeclaratorList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.single_declaration,
    [
      [ENonTerminal.fully_specified_type, ETokenType.ID],
      [
        ENonTerminal.fully_specified_type,
        ETokenType.ID,
        ENonTerminal.array_specifier,
      ],
      [
        ENonTerminal.fully_specified_type,
        ETokenType.ID,
        ENonTerminal.array_specifier,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
      [
        ENonTerminal.fully_specified_type,
        ETokenType.ID,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ],
    ASTNode.SingleDeclaration
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.initializer,
    [
      [ENonTerminal.assignment_expression],
      [
        ETokenType.LEFT_BRACE,
        ENonTerminal.initializer_list,
        ETokenType.RIGHT_BRACE,
      ],
    ],
    ASTNode.Initializer
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.initializer_list,
    [
      [ENonTerminal.initializer],
      [
        ENonTerminal.initializer_list,
        ETokenType.COMMA,
        ENonTerminal.initializer,
      ],
    ],
    ASTNode.InitializerList
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.expression_statement,
    [[ETokenType.SEMICOLON], [ENonTerminal.expression, ETokenType.SEMICOLON]],
    ASTNode.ExpressionStatement
  ),

  // dangling else ambiguity
  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.SelectionStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
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
    ],
    ASTNode.IterationStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.precision_specifier,
    [
      [
        EKeyword.PRECISION,
        ENonTerminal.precision_qualifier,
        ENonTerminal.ext_builtin_type_specifier_nonarray,
        ETokenType.SEMICOLON,
      ],
    ],
    ASTNode.PrecisionSpecifier
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.for_init_statement,
    [[ENonTerminal.expression_statement], [ENonTerminal.declaration]],
    ASTNode.ForInitStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.condition,
    [
      [ENonTerminal.expression],
      [
        ENonTerminal.fully_specified_type,
        ETokenType.ID,
        ETokenType.EQUAL,
        ENonTerminal.initializer,
      ],
    ],
    ASTNode.Condition
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.for_rest_statement,
    [
      [ENonTerminal.conditionopt, ETokenType.SEMICOLON],
      [
        ENonTerminal.conditionopt,
        ETokenType.SEMICOLON,
        ENonTerminal.expression,
      ],
    ],
    ASTNode.ForRestStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.conditionopt,
    [[ETokenType.EPSILON], [ENonTerminal.condition]],
    ASTNode.ConditionOpt
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.jump_statement,
    [
      [EKeyword.CONTINUE, ETokenType.SEMICOLON],
      [EKeyword.BREAK, ETokenType.SEMICOLON],
      [EKeyword.RETURN, ETokenType.SEMICOLON],
      [EKeyword.RETURN, ENonTerminal.expression, ETokenType.SEMICOLON],
      [EKeyword.DISCARD, ETokenType.SEMICOLON],
    ],
    ASTNode.JumpStatement
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.scope_brace,
    [[ETokenType.LEFT_BRACE]],
    ASTNode.ScopeBrace
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.scope_end_brace,
    [[ETokenType.RIGHT_BRACE]],
    ASTNode.ScopeEndBrace
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.subshader_scope_brace,
    [[ENonTerminal.scope_brace]],
    ASTNode.SubShaderScopeBrace
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.pass_scope_brace,
    [[ENonTerminal.scope_brace]],
    ASTNode.PassScopeBrace
  ),

  ...GrammarUtils.createProductionWithOptionsV2(
    ENonTerminal.variable_identifier,
    [[ETokenType.ID]],
    ASTNode.VariableIdentifier
  ),
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

export { createGrammar, addTranslationRule };

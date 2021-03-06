%pure-parser
%parse-param	{ SPVM_COMPILER* compiler }
%lex-param	{ SPVM_COMPILER* compiler }

%{
  #include <stdio.h>
  
  #include "spvm_compiler.h"
  #include "spvm_yacc_util.h"
  #include "spvm_toke.h"
  #include "spvm_op.h"
  #include "spvm_dumper.h"
  #include "spvm_constant.h"
  #include "spvm_type.h"
  #include "spvm_block.h"
  #include "spvm_list.h"
  #include "spvm_package.h"
%}

%token <opval> PACKAGE HAS SUB OUR ENUM MY SELF USE REQUIRE
%token <opval> DESCRIPTOR
%token <opval> IF UNLESS ELSIF ELSE FOR WHILE LAST NEXT SWITCH CASE DEFAULT EVAL
%token <opval> NAME VAR_NAME CONSTANT PACKAGE_VAR_NAME EXCEPTION_VAR
%token <opval> UNDEF VOID BYTE SHORT INT LONG FLOAT DOUBLE STRING OBJECT
%token <opval> DOT3 FATCAMMA RW RO WO BEGIN NEW
%token <opval> RETURN WEAKEN CROAK CURRENT_PACKAGE UNWEAKEN '[' '{' '('

%type <opval> grammar
%type <opval> opt_packages packages package package_block
%type <opval> opt_declarations declarations declaration
%type <opval> enumeration enumeration_block opt_enumeration_values enumeration_values enumeration_value
%type <opval> sub anon_sub opt_args args arg invocant has use require our string_length
%type <opval> opt_descriptors descriptors sub_names opt_sub_names
%type <opval> opt_statements statements statement if_statement else_statement 
%type <opval> for_statement while_statement switch_statement case_statement default_statement
%type <opval> block eval_block begin_block if_require_statement
%type <opval> unary_op binary_op comparison_op num_comparison_op str_comparison_op isa logical_op
%type <opval> call_sub opt_vaarg
%type <opval> array_access field_access weaken_field unweaken_field isweak_field convert array_length
%type <opval> deref ref assign inc dec
%type <opval> new array_init
%type <opval> my_var var package_var_access
%type <opval> term opt_expressions expressions expression condition opt_expression
%type <opval> field_name sub_name
%type <opval> type basic_type array_type array_type_with_length ref_type  type_or_void

%right <opval> ASSIGN SPECIAL_ASSIGN
%left <opval> LOGICAL_OR
%left <opval> LOGICAL_AND
%left <opval> BIT_OR BIT_XOR
%left <opval> '&'
%nonassoc <opval> NUMEQ NUMNE STREQ STRNE
%nonassoc <opval> NUMGT NUMGE NUMLT NUMLE STRGT STRGE STRLT STRLE ISA
%left <opval> SHIFT
%left <opval> '+' '-' '.'
%left <opval> MULTIPLY DIVIDE REMAINDER
%right <opval> LOGICAL_NOT BIT_NOT '@' REF DEREF PLUS MINUS CONVERT SCALAR LENGTH ISWEAK
%nonassoc <opval> INC DEC
%left <opval> ARROW

%%

grammar
  : opt_packages
    {
      $$ = SPVM_OP_build_grammar(compiler, $1);
      compiler->op_grammar = $$;
    }

opt_packages
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	packages
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
  
packages
  : packages package
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $2);
      
      $$ = op_list;
    }
  | package

package
  : PACKAGE basic_type package_block
    {
      $$ = SPVM_OP_build_package(compiler, $1, $2, $3, NULL);
    }
  | PACKAGE basic_type ':' opt_descriptors package_block
    {
      $$ = SPVM_OP_build_package(compiler, $1, $2, $5, $4);
    }

package_block
  : '{' opt_declarations '}'
    {
      SPVM_OP* op_class_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CLASS_BLOCK, $1->file, $1->line);
      SPVM_OP_insert_child(compiler, op_class_block, op_class_block->last, $2);
      $$ = op_class_block;
    }

opt_declarations
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	declarations
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        $$ = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, $$, $$->last, $1);
      }
    }

declarations
  : declarations declaration
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $2);
      
      $$ = op_list;
    }
  | declaration

declaration
  : has
  | sub
  | enumeration
  | our ';'
  | use
  | begin_block

begin_block
  : BEGIN block
    { 
      SPVM_OP* op_sub = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_SUB, compiler->cur_file, compiler->cur_line);
      SPVM_OP* op_sub_name = SPVM_OP_new_op_name(compiler, "BEGIN", compiler->cur_file, compiler->cur_line);
      SPVM_OP* op_void_type = SPVM_OP_new_op_void_type(compiler, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_sub(compiler, op_sub, op_sub_name, op_void_type, NULL, NULL, $2, NULL, NULL, 1);
    }
    
use
  : USE basic_type ';'
    {
      $$ = SPVM_OP_build_use(compiler, $1, $2, NULL, 0);
    }
  | USE basic_type '(' opt_sub_names ')' ';'
    {
      $$ = SPVM_OP_build_use(compiler, $1, $2, $4, 0);
    }

require
  : REQUIRE basic_type
    {
      SPVM_OP* op_use = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_USE, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_use(compiler, op_use, $2, NULL, 1);
    }

enumeration
  : ENUM enumeration_block
    {
      $$ = SPVM_OP_build_enumeration(compiler, $1, $2);
    }

enumeration_block 
  : '{' opt_enumeration_values '}'
    {
      SPVM_OP* op_enum_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ENUM_BLOCK, $1->file, $1->line);
      SPVM_OP_insert_child(compiler, op_enum_block, op_enum_block->last, $2);
      $$ = op_enum_block;
    }

opt_enumeration_values
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	enumeration_values
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
    
enumeration_values
  : enumeration_values ',' enumeration_value 
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $3);
      
      $$ = op_list;
    }
  | enumeration_values ','
    {
      $$ = $1;
    }
  | enumeration_value
  
enumeration_value
  : sub_name
    {
      $$ = SPVM_OP_build_enumeration_value(compiler, $1, NULL);
    }
  | sub_name ASSIGN CONSTANT
    {
      $$ = SPVM_OP_build_enumeration_value(compiler, $1, $3);
    }

our
  : OUR PACKAGE_VAR_NAME ':' opt_descriptors type
    {
      $$ = SPVM_OP_build_our(compiler, $1, $2, $4, $5);
    }

has
  : HAS field_name ':' opt_descriptors type ';'
    {
      $$ = SPVM_OP_build_has(compiler, $1, $2, $4, $5);
    }

sub
  : opt_descriptors SUB sub_name ':' type_or_void '(' opt_args opt_vaarg')' block
     {
       $$ = SPVM_OP_build_sub(compiler, $2, $3, $5, $7, $1, $10, NULL, $8, 0);
     }
  | opt_descriptors SUB sub_name ':' type_or_void '(' opt_args opt_vaarg')' ';'
     {
       $$ = SPVM_OP_build_sub(compiler, $2, $3, $5, $7, $1, NULL, NULL, $8, 0);
     }

anon_sub
  : opt_descriptors SUB ':' type_or_void '(' opt_args opt_vaarg')' block
     {
       $$ = SPVM_OP_build_sub(compiler, $2, NULL, $4, $6, $1, $9, NULL, $7, 0);
     }
  | '[' args ']' opt_descriptors SUB ':' type_or_void '(' opt_args opt_vaarg')' block
     {
       SPVM_OP* op_list_args;
       if ($2->id == SPVM_OP_C_ID_LIST) {
         op_list_args = $2;
       }
       else {
         op_list_args = SPVM_OP_new_op_list(compiler, $2->file, $2->line);
         SPVM_OP_insert_child(compiler, op_list_args, op_list_args->last, $2);
       }
       
       $$ = SPVM_OP_build_sub(compiler, $5, NULL, $7, $9, $4, $12, op_list_args, $10, 0);
     }

opt_args
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	args
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
  | invocant
    {
       // Add invocant to arguments
       SPVM_OP* op_args = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
       SPVM_OP_insert_child(compiler, op_args, op_args->last, $1);
       
       $$ = op_args;
    }
  | invocant ',' args
    {
      // Add invocant to arguments
      SPVM_OP* op_args;
      if ($3->id == SPVM_OP_C_ID_LIST) {
        op_args = $3;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $3);
        op_args = op_list;
      }
      
      SPVM_OP_insert_child(compiler, op_args, op_args->first, $1);
       
      $$ = op_args;
    }

args
  : args ',' arg
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $3);
      
      $$ = op_list;
    }
  | arg

arg
  : var ':' type
    {
      $$ = SPVM_OP_build_arg(compiler, $1, $3);
    }

opt_vaarg
  : /* Empty */
    {
      $$ = NULL;
    }
  | DOT3

invocant
  : var ':' SELF
    {
      SPVM_TYPE* type = SPVM_TYPE_new(compiler);
      type->is_self = 1;
      SPVM_OP* op_type = SPVM_OP_new_op_type(compiler, type, $3->file, $3->line);
      
      $$ = SPVM_OP_build_arg(compiler, $1, op_type);
    }

opt_descriptors
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	descriptors
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
    
descriptors
  : descriptors DESCRIPTOR
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $2);
      
      $$ = op_list;
    }
  | DESCRIPTOR

opt_statements
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	statements
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
    
statements
  : statements statement 
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $2);
      
      $$ = op_list;
    }
  | statement

statement
  : if_statement
  | for_statement
  | while_statement
  | block
  | switch_statement
  | case_statement
  | default_statement
  | eval_block
  | if_require_statement
  | expression ';'
    {
      $$ = $1;
    }
  | LAST ';'
  | NEXT ';'
  | RETURN ';'
    {
      $$ = SPVM_OP_build_return(compiler, $1, NULL);
    }
  | RETURN expression ';'
    {
      $$ = SPVM_OP_build_return(compiler, $1, $2);
    }
  | CROAK ';'
    {
      $$ = SPVM_OP_build_croak(compiler, $1, NULL);
    }
  | CROAK expression ';'
    {
      $$ = SPVM_OP_build_croak(compiler, $1, $2);
    }
  | weaken_field ';'
  | unweaken_field ';'
  | ';'
    {
      $$ = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NULL, compiler->cur_file, compiler->cur_line);
    }

for_statement
  : FOR '(' opt_expression ';' term ';' opt_expression ')' block
    {
      $$ = SPVM_OP_build_for_statement(compiler, $1, $3, $5, $7, $9);
    }

while_statement
  : WHILE '(' term ')' block
    {
      $$ = SPVM_OP_build_while_statement(compiler, $1, $3, $5);
    }

switch_statement
  : SWITCH '(' expression ')' block
    {
      $$ = SPVM_OP_build_switch_statement(compiler, $1, $3, $5);
    }

case_statement
  : CASE expression ':'
    {
      $$ = SPVM_OP_build_case_statement(compiler, $1, $2);
    }

default_statement
  : DEFAULT ':'

if_require_statement
  : IF '(' require ')' block
    {
      SPVM_OP* op_if_require = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_IF_REQUIRE, compiler->cur_file, compiler->cur_line);
      
      $$ = SPVM_OP_build_if_require_statement(compiler, op_if_require, $3, $5);
    }

if_statement
  : IF '(' term ')' block else_statement
    {
      SPVM_OP* op_if = SPVM_OP_build_if_statement(compiler, $1, $3, $5, $6);
      
      // if is wraped with block to allow the following syntax
      //  if (my $var = 3) { ... }
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, $1->file, $1->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, op_if);
      
      $$ = op_block;
    }
  | UNLESS '(' term ')' block else_statement
    {
      SPVM_OP* op_if = SPVM_OP_build_if_statement(compiler, $1, $3, $5, $6);
      
      // if is wraped with block to allow the following syntax
      //  if (my $var = 3) { ... }
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, $1->file, $1->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, op_if);
      
      $$ = op_block;
    }

else_statement
  : /* NULL */
    {
      $$ = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NULL, compiler->cur_file, compiler->cur_line);
    };
  | ELSE block
    {
      $$ = $2;
    }
  | ELSIF '(' term ')' block else_statement
    {
      $$ = SPVM_OP_build_if_statement(compiler, $1, $3, $5, $6);
    }

block 
  : '{' opt_statements '}'
    {
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, $1->file, $1->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, $2);
      $$ = op_block;
    }

eval_block
  : EVAL block ';'
    {
      $$ = SPVM_OP_build_eval(compiler, $1, $2);
    }

opt_expressions
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	expressions
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }
    
term
  : expression
  | condition

opt_expression
  : /* Empty */
    {
      $$ = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NULL, compiler->cur_file, compiler->cur_line);
    }
  | expression

expression
  : var
  | EXCEPTION_VAR
  | package_var_access
  | CONSTANT
  | UNDEF
  | call_sub
  | field_access
  | array_access
  | convert
  | new
  | array_init
  | array_length
  | string_length
  | my_var
  | binary_op
  | unary_op
  | ref
  | deref
  | assign
  | inc
  | dec
  | '(' expressions ')'
    {
      if ($2->id == SPVM_OP_C_ID_LIST) {
			  SPVM_OP* op_term = $2->first;
	      SPVM_OP* op_sequence = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_SEQUENCE, compiler->cur_file, compiler->cur_line);
			  while ((op_term = SPVM_OP_sibling(compiler, op_term))) {
			    SPVM_OP* op_stab = SPVM_OP_cut_op(compiler, op_term);
  	      SPVM_OP_insert_child(compiler, op_sequence, op_sequence->last, op_term);
  	      op_term = op_stab;
			  }
			  $$ = op_sequence;
      }
      else {
        $$ = $2;
      }
    }
  | CURRENT_PACKAGE

expressions
  : expressions ',' expression
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $3);
      
      $$ = op_list;
    }
  | expressions ','
    {
      $$ = $1;
    }
  | expression
    {
      $$ = $1;
    }

unary_op
  : '+' expression %prec PLUS
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PLUS, $1->file, $1->line);
      $$ = SPVM_OP_build_unary_op(compiler, op, $2);
    }
  | '-' expression %prec MINUS
    {
      SPVM_OP* op_negate = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_MINUS, $1->file, $1->line);
      $$ = SPVM_OP_build_unary_op(compiler, op_negate, $2);
    }
  | BIT_NOT expression
    {
      $$ = SPVM_OP_build_unary_op(compiler, $1, $2);
    }

inc
  : INC expression
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PRE_INC, $1->file, $1->line);
      $$ = SPVM_OP_build_inc(compiler, op, $2);
    }
  | expression INC
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_POST_INC, $2->file, $2->line);
      $$ = SPVM_OP_build_inc(compiler, op, $1);
    }

dec
  : DEC expression
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PRE_DEC, $1->file, $1->line);
      $$ = SPVM_OP_build_dec(compiler, op, $2);
    }
  | expression DEC
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_POST_DEC, $2->file, $2->line);
      $$ = SPVM_OP_build_dec(compiler, op, $1);
    }

binary_op
  : expression '+' expression
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ADD, $2->file, $2->line);
      $$ = SPVM_OP_build_binary_op(compiler, op, $1, $3);
    }
  | expression '-' expression
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_SUBTRACT, $2->file, $2->line);
      $$ = SPVM_OP_build_binary_op(compiler, op, $1, $3);
    }
  | expression MULTIPLY expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression DIVIDE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression REMAINDER expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression BIT_XOR expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression '&' expression
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_BIT_AND, $2->file, $2->line);
      $$ = SPVM_OP_build_binary_op(compiler, op, $1, $3);
    }
  | expression BIT_OR expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression SHIFT expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression '.' expression
    {
      $$ = SPVM_OP_build_concat(compiler, $2, $1, $3);
    }

condition
  : comparison_op
  | logical_op
  | isweak_field ';'
  | '(' condition ')'
    {
      $$ = $2;
    }

comparison_op
  : num_comparison_op
  | str_comparison_op
  | isa

num_comparison_op
  : expression NUMEQ expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression NUMNE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression NUMGT expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression NUMGE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression NUMLT expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression NUMLE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }

str_comparison_op
  : expression STREQ expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression STRNE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression STRGT expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression STRGE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression STRLT expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
  | expression STRLE expression
    {
      $$ = SPVM_OP_build_binary_op(compiler, $2, $1, $3);
    }
    
isa
  : expression ISA type
    {
      $$ = SPVM_OP_build_isa(compiler, $2, $1, $3);
    }

logical_op
  : term LOGICAL_OR term
    {
      $$ = SPVM_OP_build_or(compiler, $2, $1, $3);
    }
  | term LOGICAL_AND term
    {
      $$ = SPVM_OP_build_and(compiler, $2, $1, $3);
    }
  | LOGICAL_NOT term
    {
      $$ = SPVM_OP_build_not(compiler, $1, $2);
    }

assign
  : expression ASSIGN expression
    {
      $$ = SPVM_OP_build_assign(compiler, $2, $1, $3);
    }
  | expression SPECIAL_ASSIGN expression
    {
      $$ = SPVM_OP_build_special_assign(compiler, $2, $1, $3);
    }

new
  : NEW basic_type
    {
      $$ = SPVM_OP_build_new(compiler, $1, $2, NULL);
    }
  | NEW array_type_with_length
    {
      $$ = SPVM_OP_build_new(compiler, $1, $2, NULL);
    }
  | anon_sub
    {
      // Package
      SPVM_OP* op_package = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PACKAGE, $1->file, $1->line);
      
      // Create class block
      SPVM_OP* op_class_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CLASS_BLOCK, $1->file, $1->line);
      SPVM_OP* op_list_declarations = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
      SPVM_OP_insert_child(compiler, op_list_declarations, op_list_declarations->last, $1);
      SPVM_OP_insert_child(compiler, op_class_block, op_class_block->last, op_list_declarations);
      
      // Build package
      SPVM_OP_build_package(compiler, op_package, NULL, op_class_block, NULL);

      // Type
      SPVM_OP* op_type = SPVM_OP_new_op_type(compiler, op_package->uv.package->op_type->uv.type, $1->file, $1->line);
      
      // New
      SPVM_OP* op_new = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NEW, $1->file, $1->line);
      $$ = SPVM_OP_build_new(compiler, op_new, op_type, NULL);
    }

array_init
  : '[' opt_expressions ']'
    {
      SPVM_OP* op_array_init = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_INIT, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_array_init(compiler, op_array_init, $2);
    }

convert
  : '(' type ')' expression %prec CONVERT
    {
      SPVM_OP* op_convert = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CONVERT, $2->file, $2->line);
      $$ = SPVM_OP_build_convert(compiler, op_convert, $2, $4);
    }

array_access
  : expression ARROW '[' expression ']'
    {
      $$ = SPVM_OP_build_array_access(compiler, $1, $4);
    }
  | array_access '[' expression ']'
    {
      $$ = SPVM_OP_build_array_access(compiler, $1, $3);
    }
  | field_access '[' expression ']'
    {
      $$ = SPVM_OP_build_array_access(compiler, $1, $3);
    }

call_sub
  : NAME '(' opt_expressions  ')'
    {
      $$ = SPVM_OP_build_call_sub(compiler, NULL, $1, $3);
    }
  | basic_type ARROW sub_name '(' opt_expressions  ')'
    {
      $$ = SPVM_OP_build_call_sub(compiler, $1, $3, $5);
    }
  | basic_type ARROW sub_name
    {
      SPVM_OP* op_expressions = SPVM_OP_new_op_list(compiler, $1->file, $2->line);
      $$ = SPVM_OP_build_call_sub(compiler, $1, $3, op_expressions);
    }
  | expression ARROW sub_name '(' opt_expressions ')'
    {
      $$ = SPVM_OP_build_call_sub(compiler, $1, $3, $5);
    }
  | expression ARROW sub_name
    {
      SPVM_OP* op_expressions = SPVM_OP_new_op_list(compiler, $1->file, $2->line);
      $$ = SPVM_OP_build_call_sub(compiler, $1, $3, op_expressions);
    }
  | expression ARROW '(' opt_expressions ')'
    {
      SPVM_OP* op_sub_name = SPVM_OP_new_op_name(compiler, "", $2->file, $2->line);
      $$ = SPVM_OP_build_call_sub(compiler, $1, op_sub_name, $4);
    }
field_access
  : expression ARROW '{' field_name '}'
    {
      $$ = SPVM_OP_build_field_access(compiler, $1, $4);
    }
  | field_access '{' field_name '}'
    {
      $$ = SPVM_OP_build_field_access(compiler, $1, $3);
    }
  | array_access '{' field_name '}'
    {
      $$ = SPVM_OP_build_field_access(compiler, $1, $3);
    }

weaken_field
  : WEAKEN field_access
    {
      $$ = SPVM_OP_build_weaken_field(compiler, $1, $2);
    }

unweaken_field
  : UNWEAKEN field_access
    {
      $$ = SPVM_OP_build_weaken_field(compiler, $1, $2);
    }

isweak_field
  : ISWEAK field_access
    {
      $$ = SPVM_OP_build_weaken_field(compiler, $1, $2);
    }

array_length
  : '@' expression
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_array_length(compiler, op_array_length, $2);
    }
  | '@' '{' expression '}'
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_array_length(compiler, op_array_length, $3);
    }
  | SCALAR '@' expression
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_array_length(compiler, op_array_length, $3);
    }
  | SCALAR '@' '{' expression '}'
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      $$ = SPVM_OP_build_array_length(compiler, op_array_length, $4);
    }

string_length
  : LENGTH expression
    {
      $$ = SPVM_OP_build_string_length(compiler, $1, $2);
    }
    
deref
  : DEREF var
    {
      $$ = SPVM_OP_build_deref(compiler, $1, $2);
    }

ref
  : REF var
    {
      SPVM_OP* op_ref = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_REF, $1->file, $1->line);
      $$ = SPVM_OP_build_ref(compiler, op_ref, $2);
    }

my_var
  : MY var ':' type
    {
      $$ = SPVM_OP_build_my(compiler, $1, $2, $4);
    }
  | MY var
    {
      $$ = SPVM_OP_build_my(compiler, $1, $2, NULL);
    }

var
  : VAR_NAME
    {
      $$ = SPVM_OP_build_var(compiler, $1);
    }

package_var_access
  : PACKAGE_VAR_NAME
    {
      $$ = SPVM_OP_build_package_var_access(compiler, $1);
    }

type
  : basic_type
  | array_type
  | ref_type

basic_type
  : NAME
    {
      $$ = SPVM_OP_build_basic_type(compiler, $1);
    }
  | BYTE
    {
      SPVM_OP* op_type = SPVM_OP_new_op_byte_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | SHORT
    {
      SPVM_OP* op_type = SPVM_OP_new_op_short_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | INT
    {
      SPVM_OP* op_type = SPVM_OP_new_op_int_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | LONG
    {
      SPVM_OP* op_type = SPVM_OP_new_op_long_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | FLOAT
    {
      SPVM_OP* op_type = SPVM_OP_new_op_float_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | DOUBLE
    {
      SPVM_OP* op_type = SPVM_OP_new_op_double_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | OBJECT
    {
      SPVM_OP* op_type = SPVM_OP_new_op_any_object_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }
  | STRING
    {
      SPVM_OP* op_type = SPVM_OP_new_op_string_type(compiler, $1->file, $1->line);
      
      $$ = op_type;
    }

ref_type
  : basic_type '&'
    {
      $$ = SPVM_OP_build_ref_type(compiler, $1);
    }

array_type
  : basic_type '[' ']'
    {
      $$ = SPVM_OP_build_array_type(compiler, $1, NULL);
    }
  | array_type '[' ']'
    {
      $$ = SPVM_OP_build_array_type(compiler, $1, NULL);
    }

array_type_with_length
  : basic_type '[' expression ']'
    {
      $$ = SPVM_OP_build_array_type(compiler, $1, $3);
    }
  | array_type '[' expression ']'
    {
      $$ = SPVM_OP_build_array_type(compiler, $1, $3);
    }

type_or_void
  : type
  | VOID
    {
      $$ = SPVM_OP_new_op_void_type(compiler, compiler->cur_file, compiler->cur_line);
    }

field_name
  : NAME

sub_name
  : NAME

opt_sub_names
  :	/* Empty */
    {
      $$ = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
  |	sub_names
    {
      if ($1->id == SPVM_OP_C_ID_LIST) {
        $$ = $1;
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
        $$ = op_list;
      }
    }

sub_names
  : sub_names ',' sub_name
    {
      SPVM_OP* op_list;
      if ($1->id == SPVM_OP_C_ID_LIST) {
        op_list = $1;
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, $1->file, $1->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, $1);
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, $3);
      
      $$ = op_list;
    }
  | sub_name

%%

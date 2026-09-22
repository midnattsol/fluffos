/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 39 "$REPO_ROOT$/src/compiler/internal/grammar.y"

#include "base/std.h"
#include "compiler/internal/grammar_rules.h"

/*
 * LPC grammar — parse-tree generator.
 *
 * Rules are ordered top-down: the entry point and high-level structure
 * appear first; details and primitives are defined further below.
 * All bison rules may forward-reference nonterminals defined later.
 *
 * `context` tracks nesting state used for semantic error checking:
 *   SWITCH_CONTEXT, LOOP_CONTEXT, SPECIAL_CONTEXT, SWITCH_STRINGS,
 *   SWITCH_NUMBERS, SWITCH_RANGES, SWITCH_DEFAULT.
 */
int context;
int num_refs;
int func_present;

void yyerror(void *yyscanner, const char *msg);

#line 93 "$BUILD_ROOT$/src/grammar.autogen.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.autogen.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_L_STRING = 3,                   /* L_STRING  */
  YYSYMBOL_L_NUMBER = 4,                   /* L_NUMBER  */
  YYSYMBOL_L_SCALAR_LITERAL = 5,           /* L_SCALAR_LITERAL  */
  YYSYMBOL_L_REAL = 6,                     /* L_REAL  */
  YYSYMBOL_L_TEMPLATE_HEAD = 7,            /* L_TEMPLATE_HEAD  */
  YYSYMBOL_L_TEMPLATE_MIDDLE = 8,          /* L_TEMPLATE_MIDDLE  */
  YYSYMBOL_L_TEMPLATE_TAIL = 9,            /* L_TEMPLATE_TAIL  */
  YYSYMBOL_L_BASIC_TYPE = 10,              /* L_BASIC_TYPE  */
  YYSYMBOL_L_TYPE_MODIFIER = 11,           /* L_TYPE_MODIFIER  */
  YYSYMBOL_L_DEFINED_NAME = 12,            /* L_DEFINED_NAME  */
  YYSYMBOL_L_IDENTIFIER = 13,              /* L_IDENTIFIER  */
  YYSYMBOL_L_EFUN = 14,                    /* L_EFUN  */
  YYSYMBOL_L_INC_DEC = 15,                 /* L_INC_DEC  */
  YYSYMBOL_L_ASSIGN = 16,                  /* L_ASSIGN  */
  YYSYMBOL_L_LAND = 17,                    /* L_LAND  */
  YYSYMBOL_L_LOR = 18,                     /* L_LOR  */
  YYSYMBOL_L_QUESTION_QUESTION = 19,       /* L_QUESTION_QUESTION  */
  YYSYMBOL_L_SHIFT = 20,                   /* L_SHIFT  */
  YYSYMBOL_L_EQ_NE = 21,                   /* L_EQ_NE  */
  YYSYMBOL_L_ORDER = 22,                   /* L_ORDER  */
  YYSYMBOL_L_IF = 23,                      /* L_IF  */
  YYSYMBOL_L_ELSE = 24,                    /* L_ELSE  */
  YYSYMBOL_L_SWITCH = 25,                  /* L_SWITCH  */
  YYSYMBOL_L_CASE = 26,                    /* L_CASE  */
  YYSYMBOL_L_DEFAULT = 27,                 /* L_DEFAULT  */
  YYSYMBOL_L_RANGE = 28,                   /* L_RANGE  */
  YYSYMBOL_L_DOT_DOT_DOT = 29,             /* L_DOT_DOT_DOT  */
  YYSYMBOL_L_WHILE = 30,                   /* L_WHILE  */
  YYSYMBOL_L_DO = 31,                      /* L_DO  */
  YYSYMBOL_L_FOR = 32,                     /* L_FOR  */
  YYSYMBOL_L_FOREACH = 33,                 /* L_FOREACH  */
  YYSYMBOL_L_IN = 34,                      /* L_IN  */
  YYSYMBOL_L_BREAK = 35,                   /* L_BREAK  */
  YYSYMBOL_L_CONTINUE = 36,                /* L_CONTINUE  */
  YYSYMBOL_L_RETURN = 37,                  /* L_RETURN  */
  YYSYMBOL_L_ARROW = 38,                   /* L_ARROW  */
  YYSYMBOL_L_INHERIT = 39,                 /* L_INHERIT  */
  YYSYMBOL_L_COLON_COLON = 40,             /* L_COLON_COLON  */
  YYSYMBOL_L_OPTIONAL_DOT = 41,            /* L_OPTIONAL_DOT  */
  YYSYMBOL_L_DOT_OPTIONAL = 42,            /* L_DOT_OPTIONAL  */
  YYSYMBOL_L_FUNCTION_OPEN = 43,           /* L_FUNCTION_OPEN  */
  YYSYMBOL_L_SSCANF = 44,                  /* L_SSCANF  */
  YYSYMBOL_L_CATCH = 45,                   /* L_CATCH  */
  YYSYMBOL_L_TRY = 46,                     /* L_TRY  */
  YYSYMBOL_L_AWAIT = 47,                   /* L_AWAIT  */
  YYSYMBOL_L_ACATCH = 48,                  /* L_ACATCH  */
  YYSYMBOL_L_PROMISE = 49,                 /* L_PROMISE  */
  YYSYMBOL_L_ARRAY = 50,                   /* L_ARRAY  */
  YYSYMBOL_L_REF = 51,                     /* L_REF  */
  YYSYMBOL_L_PARSE_COMMAND = 52,           /* L_PARSE_COMMAND  */
  YYSYMBOL_L_TIME_EXPRESSION = 53,         /* L_TIME_EXPRESSION  */
  YYSYMBOL_L_CLASS = 54,                   /* L_CLASS  */
  YYSYMBOL_L_NEW = 55,                     /* L_NEW  */
  YYSYMBOL_L_PARAMETER = 56,               /* L_PARAMETER  */
  YYSYMBOL_L_TREE = 57,                    /* L_TREE  */
  YYSYMBOL_LOWER_THAN_ELSE = 58,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_59_ = 59,                       /* '?'  */
  YYSYMBOL_60_ = 60,                       /* '|'  */
  YYSYMBOL_61_ = 61,                       /* '^'  */
  YYSYMBOL_62_ = 62,                       /* '&'  */
  YYSYMBOL_63_ = 63,                       /* '<'  */
  YYSYMBOL_64_ = 64,                       /* '+'  */
  YYSYMBOL_65_ = 65,                       /* '-'  */
  YYSYMBOL_66_ = 66,                       /* '*'  */
  YYSYMBOL_67_ = 67,                       /* '%'  */
  YYSYMBOL_68_ = 68,                       /* '/'  */
  YYSYMBOL_69_ = 69,                       /* '!'  */
  YYSYMBOL_70_ = 70,                       /* '~'  */
  YYSYMBOL_71_ = 71,                       /* ';'  */
  YYSYMBOL_72_ = 72,                       /* '('  */
  YYSYMBOL_73_ = 73,                       /* ')'  */
  YYSYMBOL_74_ = 74,                       /* '{'  */
  YYSYMBOL_75_ = 75,                       /* '}'  */
  YYSYMBOL_76_ = 76,                       /* ','  */
  YYSYMBOL_77_ = 77,                       /* ':'  */
  YYSYMBOL_78_ = 78,                       /* '$'  */
  YYSYMBOL_79_ = 79,                       /* '.'  */
  YYSYMBOL_80_ = 80,                       /* '['  */
  YYSYMBOL_81_ = 81,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_loop_start = 83,                /* loop_start  */
  YYSYMBOL_foreach_start = 84,             /* foreach_start  */
  YYSYMBOL_block_start = 85,               /* block_start  */
  YYSYMBOL_special_context_start = 86,     /* special_context_start  */
  YYSYMBOL_tree_context_start = 87,        /* tree_context_start  */
  YYSYMBOL_dollar_start = 88,              /* dollar_start  */
  YYSYMBOL_all = 89,                       /* all  */
  YYSYMBOL_program = 90,                   /* program  */
  YYSYMBOL_opt_semicolon = 91,             /* opt_semicolon  */
  YYSYMBOL_def = 92,                       /* def  */
  YYSYMBOL_function = 93,                  /* function  */
  YYSYMBOL_94_1 = 94,                      /* @1  */
  YYSYMBOL_95_2 = 95,                      /* @2  */
  YYSYMBOL_block_or_semi = 96,             /* block_or_semi  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL_try_body = 98,                  /* try_body  */
  YYSYMBOL_try_context_start = 99,         /* try_context_start  */
  YYSYMBOL_stmt_return = 100,              /* stmt_return  */
  YYSYMBOL_stmt_cond = 101,                /* stmt_cond  */
  YYSYMBOL_optional_else_part = 102,       /* optional_else_part  */
  YYSYMBOL_stmt_while = 103,               /* stmt_while  */
  YYSYMBOL_stmt_do = 104,                  /* stmt_do  */
  YYSYMBOL_stmt_for = 105,                 /* stmt_for  */
  YYSYMBOL_stmt_foreach = 106,             /* stmt_foreach  */
  YYSYMBOL_stmt_switch = 107,              /* stmt_switch  */
  YYSYMBOL_block = 108,                    /* block  */
  YYSYMBOL_statements = 109,               /* statements  */
  YYSYMBOL_local_decl_statement_header = 110, /* local_decl_statement_header  */
  YYSYMBOL_local_declaration_statement = 111, /* local_declaration_statement  */
  YYSYMBOL_local_decl_header = 112,        /* local_decl_header  */
  YYSYMBOL_local_declarations = 113,       /* local_declarations  */
  YYSYMBOL_comma_expr = 114,               /* comma_expr  */
  YYSYMBOL_expr = 115,                     /* expr  */
  YYSYMBOL_lvalue = 116,                   /* lvalue  */
  YYSYMBOL_primary_expr = 117,             /* primary_expr  */
  YYSYMBOL_call_open = 118,                /* call_open  */
  YYSYMBOL_function_call = 119,            /* function_call  */
  YYSYMBOL_sscanf = 120,                   /* sscanf  */
  YYSYMBOL_parse_command = 121,            /* parse_command  */
  YYSYMBOL_catch = 122,                    /* catch  */
  YYSYMBOL_acatch = 123,                   /* acatch  */
  YYSYMBOL_acatch_context_start = 124,     /* acatch_context_start  */
  YYSYMBOL_time_expression = 125,          /* time_expression  */
  YYSYMBOL_tree = 126,                     /* tree  */
  YYSYMBOL_switch_header = 127,            /* switch_header  */
  YYSYMBOL_switch_block = 128,             /* switch_block  */
  YYSYMBOL_case = 129,                     /* case  */
  YYSYMBOL_case_label = 130,               /* case_label  */
  YYSYMBOL_for_expr = 131,                 /* for_expr  */
  YYSYMBOL_for_init = 132,                 /* for_init  */
  YYSYMBOL_foreach_var = 133,              /* foreach_var  */
  YYSYMBOL_foreach_vars = 134,             /* foreach_vars  */
  YYSYMBOL_type_decl = 135,                /* type_decl  */
  YYSYMBOL_class_header = 136,             /* class_header  */
  YYSYMBOL_member_list = 137,              /* member_list  */
  YYSYMBOL_138_3 = 138,                    /* $@3  */
  YYSYMBOL_member_name_list = 139,         /* member_name_list  */
  YYSYMBOL_member_name = 140,              /* member_name  */
  YYSYMBOL_class_init = 141,               /* class_init  */
  YYSYMBOL_opt_class_init = 142,           /* opt_class_init  */
  YYSYMBOL_type = 143,                     /* type  */
  YYSYMBOL_type_modifier_list = 144,       /* type_modifier_list  */
  YYSYMBOL_opt_basic_type = 145,           /* opt_basic_type  */
  YYSYMBOL_basic_type = 146,               /* basic_type  */
  YYSYMBOL_opt_atomic_type = 147,          /* opt_atomic_type  */
  YYSYMBOL_atomic_type = 148,              /* atomic_type  */
  YYSYMBOL_arg_type = 149,                 /* arg_type  */
  YYSYMBOL_cast = 150,                     /* cast  */
  YYSYMBOL_optional_star = 151,            /* optional_star  */
  YYSYMBOL_identifier = 152,               /* identifier  */
  YYSYMBOL_new_local_name = 153,           /* new_local_name  */
  YYSYMBOL_efun_override = 154,            /* efun_override  */
  YYSYMBOL_function_name = 155,            /* function_name  */
  YYSYMBOL_inheritance = 156,              /* inheritance  */
  YYSYMBOL_modifier_change = 157,          /* modifier_change  */
  YYSYMBOL_argument = 158,                 /* argument  */
  YYSYMBOL_argument_list = 159,            /* argument_list  */
  YYSYMBOL_param_decl = 160,               /* param_decl  */
  YYSYMBOL_optional_default_arg_value = 161, /* optional_default_arg_value  */
  YYSYMBOL_local_name_list = 162,          /* local_name_list  */
  YYSYMBOL_new_local_def = 163,            /* new_local_def  */
  YYSYMBOL_single_new_local_def = 164,     /* single_new_local_def  */
  YYSYMBOL_single_new_local_def_with_init = 165, /* single_new_local_def_with_init  */
  YYSYMBOL_name_list = 166,                /* name_list  */
  YYSYMBOL_new_name = 167,                 /* new_name  */
  YYSYMBOL_lambda_return_type = 168,       /* lambda_return_type  */
  YYSYMBOL_functional_open = 169,          /* functional_open  */
  YYSYMBOL_assoc_pair = 170,               /* assoc_pair  */
  YYSYMBOL_spread_expr = 171,              /* spread_expr  */
  YYSYMBOL_arg_list = 172,                 /* arg_list  */
  YYSYMBOL_opt_arg_list = 173,             /* opt_arg_list  */
  YYSYMBOL_pair_list = 174,                /* pair_list  */
  YYSYMBOL_opt_pair_list = 175,            /* opt_pair_list  */
  YYSYMBOL_lvalue_list = 176,              /* lvalue_list  */
  YYSYMBOL_expr_or_block = 177,            /* expr_or_block  */
  YYSYMBOL_ref = 178,                      /* ref  */
  YYSYMBOL_string = 179,                   /* string  */
  YYSYMBOL_template_literal = 180,         /* template_literal  */
  YYSYMBOL_template_parts = 181,           /* template_parts  */
  YYSYMBOL_string_like = 182,              /* string_like  */
  YYSYMBOL_string_literal = 183,           /* string_literal  */
  YYSYMBOL_string_const = 184,             /* string_const  */
  YYSYMBOL_number = 185,                   /* number  */
  YYSYMBOL_real = 186,                     /* real  */
  YYSYMBOL_constant = 187                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#ifdef NDEBUG
# define YY_ASSERT(E) ((void) (0 && (E)))
#else
# include <assert.h> /* INFRINGES ON USER NAME SPACE */
# define YY_ASSERT(E) assert (E)
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  281
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  553

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,    78,    67,    62,     2,
      72,    73,    66,    64,    76,    65,    79,    68,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    71,
      63,     2,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,    60,    75,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   253,   253,   254,   255,   256,   257,   258,   267,   272,
     273,   278,   279,   290,   291,   292,   293,   294,   317,   319,
     316,   326,   327,   328,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   358,   367,   376,
     377,   382,   387,   388,   393,   399,   405,   411,   417,   429,
     435,   437,   439,   441,   447,   451,   457,   461,   463,   482,
     483,   487,   488,   489,   491,   492,   493,   494,   496,   497,
     498,   500,   501,   502,   504,   506,   513,   514,   515,   516,
     518,   519,   520,   521,   522,   523,   525,   527,   528,   529,
     530,   531,   532,   537,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   557,   561,   562,   567,   569,   571,   576,
     578,   580,   582,   584,   586,   588,   590,   592,   595,   597,
     602,   609,   611,   620,   622,   624,   628,   629,   639,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   679,   685,
     691,   700,   704,   708,   714,   716,   727,   733,   734,   735,
     741,   743,   745,   747,   749,   756,   757,   767,   768,   773,
     775,   781,   782,   783,   788,   790,   801,   807,   813,   814,
     814,   820,   821,   826,   831,   836,   837,   849,   854,   855,
     860,   861,   866,   867,   872,   873,   878,   879,   880,   884,
     885,   891,   892,   897,   902,   903,   913,   914,   919,   920,
     925,   926,   936,   937,   938,   939,   944,   950,   960,   962,
     963,   969,   971,   981,   983,   985,   991,   992,   997,   999,
    1005,  1007,  1013,  1019,  1030,  1031,  1036,  1037,  1048,  1056,
    1066,  1071,  1072,  1077,  1079,  1086,  1087,  1088,  1093,  1095,
    1102,  1103,  1104,  1109,  1110,  1115,  1116,  1121,  1122,  1132,
    1144,  1148,  1149,  1158,  1159,  1160,  1161,  1168,  1169,  1175,
    1176,  1177,  1181,  1182,  1190,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,
    1211,  1212
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "L_STRING", "L_NUMBER",
  "L_SCALAR_LITERAL", "L_REAL", "L_TEMPLATE_HEAD", "L_TEMPLATE_MIDDLE",
  "L_TEMPLATE_TAIL", "L_BASIC_TYPE", "L_TYPE_MODIFIER", "L_DEFINED_NAME",
  "L_IDENTIFIER", "L_EFUN", "L_INC_DEC", "L_ASSIGN", "L_LAND", "L_LOR",
  "L_QUESTION_QUESTION", "L_SHIFT", "L_EQ_NE", "L_ORDER", "L_IF", "L_ELSE",
  "L_SWITCH", "L_CASE", "L_DEFAULT", "L_RANGE", "L_DOT_DOT_DOT", "L_WHILE",
  "L_DO", "L_FOR", "L_FOREACH", "L_IN", "L_BREAK", "L_CONTINUE",
  "L_RETURN", "L_ARROW", "L_INHERIT", "L_COLON_COLON", "L_OPTIONAL_DOT",
  "L_DOT_OPTIONAL", "L_FUNCTION_OPEN", "L_SSCANF", "L_CATCH", "L_TRY",
  "L_AWAIT", "L_ACATCH", "L_PROMISE", "L_ARRAY", "L_REF",
  "L_PARSE_COMMAND", "L_TIME_EXPRESSION", "L_CLASS", "L_NEW",
  "L_PARAMETER", "L_TREE", "LOWER_THAN_ELSE", "'?'", "'|'", "'^'", "'&'",
  "'<'", "'+'", "'-'", "'*'", "'%'", "'/'", "'!'", "'~'", "';'", "'('",
  "')'", "'{'", "'}'", "','", "':'", "'$'", "'.'", "'['", "']'", "$accept",
  "loop_start", "foreach_start", "block_start", "special_context_start",
  "tree_context_start", "dollar_start", "all", "program", "opt_semicolon",
  "def", "function", "@1", "@2", "block_or_semi", "statement", "try_body",
  "try_context_start", "stmt_return", "stmt_cond", "optional_else_part",
  "stmt_while", "stmt_do", "stmt_for", "stmt_foreach", "stmt_switch",
  "block", "statements", "local_decl_statement_header",
  "local_declaration_statement", "local_decl_header", "local_declarations",
  "comma_expr", "expr", "lvalue", "primary_expr", "call_open",
  "function_call", "sscanf", "parse_command", "catch", "acatch",
  "acatch_context_start", "time_expression", "tree", "switch_header",
  "switch_block", "case", "case_label", "for_expr", "for_init",
  "foreach_var", "foreach_vars", "type_decl", "class_header",
  "member_list", "$@3", "member_name_list", "member_name", "class_init",
  "opt_class_init", "type", "type_modifier_list", "opt_basic_type",
  "basic_type", "opt_atomic_type", "atomic_type", "arg_type", "cast",
  "optional_star", "identifier", "new_local_name", "efun_override",
  "function_name", "inheritance", "modifier_change", "argument",
  "argument_list", "param_decl", "optional_default_arg_value",
  "local_name_list", "new_local_def", "single_new_local_def",
  "single_new_local_def_with_init", "name_list", "new_name",
  "lambda_return_type", "functional_open", "assoc_pair", "spread_expr",
  "arg_list", "opt_arg_list", "pair_list", "opt_pair_list", "lvalue_list",
  "expr_or_block", "ref", "string", "template_literal", "template_parts",
  "string_like", "string_literal", "string_const", "number", "real",
  "constant", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-448)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-243)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -448,    42,   178,  -448,    40,    -4,  -448,  -448,  -448,    16,
     130,  -448,  -448,  -448,  -448,  -448,   152,  -448,   267,     2,
      10,  -448,    23,    43,   323,  -448,  -448,  -448,   104,   108,
     328,  -448,  -448,  -448,  -448,   -10,  -448,    16,  -448,    23,
     206,   148,   161,   151,   157,   163,  -448,  -448,  -448,    16,
    1703,   174,   267,  -448,   138,  -448,    23,  -448,    16,  -448,
     215,   217,   267,   297,  -448,  -448,  -448,  1703,   277,    15,
      20,   285,   271,   267,  1773,   275,  -448,  1703,  -448,  -448,
     310,  -448,   322,  -448,   333,  -448,  1703,  1703,  1703,   717,
     337,  2089,   357,   250,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  1703,   358,   351,   351,   367,   359,   271,  -448,  -448,
      54,   206,  -448,  -448,   284,   387,  -448,  -448,   338,  -448,
      16,  -448,  1703,  1868,   267,  -448,  1323,    33,   795,  -448,
     282,  -448,   110,   369,  2089,   351,  1703,    59,  -448,    59,
    1703,    59,   394,  1323,  1703,   383,  -448,  -448,  -448,    26,
    1703,  1399,   577,   245,    16,  -448,  1703,  1703,  1703,  1703,
    1703,  1703,  1703,  1703,  1703,  1703,  1703,  1703,  1703,  1703,
    1703,  1703,  -448,  1703,   267,    56,   381,   267,  1177,  -448,
     267,  1323,  1323,   284,  1703,   403,  -448,  -448,  -448,  -448,
    -448,   142,    16,  -448,   410,     9,  -448,  -448,  -448,  2089,
    1703,  -448,  -448,  -448,  2076,  -448,   411,   418,  -448,  -448,
    1703,   428,  1703,   430,  1952,  1703,  -448,  -448,  -448,  -448,
    1972,  -448,   441,   431,   291,  -448,   292,   448,  1900,  -448,
     429,   435,  -448,   471,  1703,   545,  1071,   404,   286,  1291,
     196,  1920,   475,   755,  1215,   196,   236,   236,  -448,  -448,
    -448,  2089,   351,  1703,  -448,  1703,  -448,   482,  1703,     0,
    -448,   473,   476,   480,   379,  -448,  -448,   447,  -448,  -448,
     288,  1868,  -448,  1247,  -448,   398,  -448,  2089,  -448,  1703,
     298,   873,  1703,  -448,  -448,  -448,  -448,   351,   483,  1703,
     647,   484,  -448,   307,  1703,  1323,   164,   176,  1703,   132,
     437,   351,  -448,  -448,   383,  1703,   488,   491,    28,  -448,
    -448,  -448,   498,  2004,  -448,    -7,   501,   502,   503,  -448,
     514,   521,   523,   524,  1475,  -448,  -448,   873,   551,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,   522,    16,   873,
     147,   525,  -448,  2024,   320,   326,  1323,  -448,  2089,  -448,
    -448,  -448,  2089,   527,  -448,  -448,   191,   507,  -448,  1703,
    -448,   192,  1323,  -448,  -448,   555,  -448,  -448,  -448,  -448,
    -448,  -448,   271,   528,   873,  1703,  1703,  1703,  1025,  1101,
     346,  -448,  -448,  -448,   153,    59,  -448,   530,  -448,   447,
     532,   538,  -448,  -448,  -448,  1703,  -448,   267,  -448,   531,
    -448,  -448,  1703,  -448,   194,  1835,   201,  -448,   542,  1703,
     540,  -448,  -448,   331,   343,   344,   588,   543,  -448,   552,
      16,   610,  -448,  -448,  -448,   562,   593,  -448,  -448,  -448,
     271,   624,  -448,    16,   195,  2004,  -448,   554,  -448,   214,
    1845,  -448,  -448,  -448,  -448,   402,  -448,  1025,  -448,  -448,
     569,  1551,   447,  1703,   346,  1703,   570,  1703,  -448,   169,
     567,    16,   949,  -448,   572,  1703,  -448,  -448,   583,   639,
    1025,  1703,   594,  -448,  2089,  -448,  2056,   383,  2089,  -448,
      87,   660,   662,   663,    87,   -18,   604,   615,  -448,   598,
     949,   595,   949,  -448,  2089,  -448,  1025,  -448,  -448,   355,
    1627,  -448,  -448,   596,  -448,  -448,  -448,   324,    74,  -448,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,  -448,  -448,  -448,  -448,  -448,   600,   599,  1025,
    -448,  -448,  -448,   597,   126,   347,  1361,   311,   685,  1147,
    1285,   311,   366,   366,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  1025,  -448
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      10,     0,   178,     1,   178,    11,    13,    16,   168,   194,
     181,    15,    17,   179,    12,     9,   185,   195,     0,     0,
     224,   186,     0,   189,     0,   207,   177,   180,     0,   182,
       0,   166,   169,   196,   197,   226,    14,   194,   257,     0,
     259,     0,   185,   187,   188,     0,   183,   187,   188,   194,
       0,     0,     0,   225,     0,   258,     0,   206,   194,   167,
       0,   171,     0,     0,   262,   263,   264,     0,   228,    95,
      96,     0,     0,     0,     0,     0,     5,     0,   142,   247,
       0,     5,     0,    97,     6,   248,     0,     0,     0,     0,
       0,   227,     0,    87,    94,    88,    89,   100,   101,    90,
     102,     0,     0,     0,     0,     0,     0,     0,   253,   254,
      98,   249,    91,    92,   185,   226,   260,   261,     0,   170,
     194,   173,     0,     0,     0,   128,     0,     0,     0,    81,
      93,   203,    95,     0,    59,   229,     0,     0,    85,     0,
       0,     0,   128,     0,     0,     0,    84,    82,    83,   186,
       0,     0,     0,     0,   194,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,   185,     0,     0,    61,   255,   256,   199,
     198,   191,   194,   215,     0,   209,   211,   190,   172,    63,
       0,   251,   250,   204,   231,   233,   236,     0,   201,   200,
       0,     0,     0,     0,     0,     0,     4,   245,   140,   141,
       0,   143,     0,     0,     0,   144,     0,     0,     0,   238,
     241,     0,    99,     0,     0,    67,    66,    65,    74,    71,
      72,     0,    68,    69,    70,    73,    75,    76,    77,    78,
      79,    62,   104,     0,   106,     0,   105,     0,     0,     0,
     205,     0,     0,     0,     0,   121,   192,   213,    19,   210,
     185,     0,   232,     0,   133,     0,   123,    60,   125,     0,
       0,     0,     0,   175,   175,   130,   145,     0,     0,     0,
       0,     0,   193,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   129,   134,     0,     0,     0,   216,     0,   212,
     252,   234,     0,   243,   246,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    38,    33,     0,     0,    31,
      25,    26,    27,    28,    29,    30,    32,     0,   194,     0,
       0,     0,    54,     0,     0,     0,     0,   127,   230,   239,
     126,   103,    64,     0,   107,   108,     0,     0,   110,     0,
     115,     0,     0,   120,   122,     0,   214,    23,    22,    20,
      21,   124,     0,     0,     0,     0,     0,     0,     0,     0,
     185,    34,    35,    39,     0,     0,    51,     0,    49,     0,
       0,   218,    52,    24,    57,     0,   131,     0,   132,     0,
     136,   117,     0,   116,     0,    59,     0,   111,     0,     0,
     243,   138,    53,     0,     0,     0,     0,   158,   159,     0,
     194,     0,   160,   161,   163,   164,     0,   162,    40,    37,
       0,   220,    55,   194,   185,   243,   176,     0,   137,     0,
      59,   112,   119,   114,   135,     0,   244,     0,   146,     2,
       0,     0,     0,     0,   185,     0,     0,     0,   219,     0,
       0,   194,     0,    56,     0,     0,   113,   118,     0,    42,
       0,     0,     0,   222,   223,   165,     0,     0,   221,   278,
       0,     0,     0,     0,     0,     0,   156,   155,   154,     0,
       0,     0,     0,   139,   174,   217,     0,    41,    44,     0,
       0,     3,    36,     0,   279,   280,   281,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,   148,    48,   147,    43,     0,     0,     0,
     153,   277,   152,     0,     0,   271,   268,   269,   265,   266,
     267,   270,   272,   273,   274,   275,   276,    45,     2,    47,
     151,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -448,  -447,  -448,  -448,   603,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -315,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -114,  -291,  -448,  -448,
    -448,  -448,   -70,   -47,   -64,   -60,   -32,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -322,   251,  -383,  -430,
    -448,   232,  -448,  -448,  -448,  -448,  -448,   568,  -448,  -448,
     405,  -448,   689,  -448,    -5,  -448,  -448,  -347,  -448,     7,
      76,  -260,   622,  -448,  -448,  -448,   518,  -448,   427,  -448,
    -285,  -448,   329,  -448,   673,  -448,  -448,  -448,   421,  -131,
     -43,  -129,  -448,  -448,  -386,  -126,   535,   605,   623,   442,
    -448,   -22,   -21,  -448,  -448,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   378,   529,   281,   137,   145,   234,     1,     2,    15,
       5,     6,    51,   308,   369,   327,   328,   385,   329,   330,
     497,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     461,   434,   340,   134,    92,    93,   126,    94,    95,    96,
      97,    98,   139,    99,   100,   341,   491,   492,   485,   418,
     419,   425,   426,     7,     8,    16,    49,    60,    61,   436,
     344,     9,    10,    26,   191,    28,    29,   192,   101,   389,
     102,   193,   103,   104,    11,    12,   194,   195,   196,   366,
     390,   391,   427,   422,    19,    20,   105,   106,   229,   205,
     206,   207,   230,   231,   373,   218,   107,   108,   109,   202,
     110,   111,   486,   112,   113,   487
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    41,   470,    91,   133,    27,    50,   307,   129,   122,
     508,    32,   130,   219,   223,   221,    18,    40,    54,   153,
     123,   472,   227,   217,   446,   217,    38,   217,   300,   367,
     138,   225,   420,   420,    40,   117,   386,    58,   269,   146,
     147,   148,     3,   186,    52,    33,    34,   130,   392,   464,
     143,     4,   261,   262,   179,  -196,    62,    38,   153,   509,
    -197,    67,   -18,   416,   374,   118,   124,    14,    33,    34,
     528,   181,   182,    36,   224,   199,   212,    38,   479,   204,
     226,   301,    17,   412,   154,   270,    37,   125,   208,   214,
      38,   479,  -202,   220,    35,    39,   204,   503,  -228,   368,
      45,   551,   216,   181,   204,   228,    42,   420,   259,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   533,   251,    62,   115,   431,
     479,   215,   469,   216,   204,   204,   253,   204,   121,   481,
      21,   264,   311,   482,   483,   280,   484,   490,   458,   131,
    -196,   532,   481,   271,    46,   498,   482,   483,  -184,   484,
     357,   233,    21,   204,   293,   277,   353,   275,   523,    22,
     525,    21,    38,   479,   311,   490,   489,   490,    -8,    23,
    -185,   526,   125,   296,    24,   297,   210,   211,   299,     4,
     363,   481,   473,    79,   370,   482,   483,   480,   534,   267,
     203,    23,    56,   209,    85,    21,    30,    25,   212,    55,
      23,   116,    56,   358,   549,    30,   159,   399,   393,    57,
     295,   459,   460,   212,   428,  -196,   204,    31,   356,   212,
     361,  -197,   313,   408,   481,   343,   552,    59,   482,   483,
     212,   484,   348,   228,    23,   354,   114,   352,   204,    30,
     252,   254,   212,   256,   384,   346,   260,   355,   204,   429,
     167,   168,   169,   170,   171,   -93,   -93,   212,   212,   362,
     212,   217,   401,   407,    38,   441,   342,   212,    67,    33,
      34,    68,   443,    69,    70,    71,   119,   404,   174,   406,
     212,   175,   176,   120,    21,   466,   189,   190,    21,   204,
     189,   190,   169,   170,   171,   413,   414,   415,   410,   417,
     405,    73,   130,   122,    74,   204,    76,   124,   232,    78,
     174,   212,   342,   175,   176,   127,    82,    83,    84,   177,
     178,   510,   439,    23,   342,    43,    44,    23,    30,   445,
      47,    48,    30,   128,   510,   511,   512,   136,   435,    90,
     167,   168,   169,   170,   171,   440,    21,  -208,   423,   424,
     197,   177,   178,   502,   286,   287,   456,   212,   212,   342,
     130,   314,   172,   173,   212,   517,   518,   519,   520,   521,
     351,   417,   140,   212,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   396,   142,    23,   397,   531,   180,   398,
      30,   499,   397,    50,   447,   144,   474,   212,   476,   155,
     478,   517,   518,   519,   520,   521,   448,   449,   494,   212,
     212,   156,   157,   125,   159,   160,   161,   452,   527,   463,
     417,   212,   519,   520,   521,   184,   185,    40,    63,   183,
      38,    64,    65,    66,    67,   212,   213,    68,   222,    69,
      70,    71,    72,   283,   284,   305,   306,   216,    40,   189,
     190,   255,    40,    54,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   437,   305,   312,   265,    73,   212,   468,
      74,    75,    76,   268,    77,    78,    40,   273,    79,    80,
      81,   274,    82,    83,    84,   159,   160,   161,   507,    85,
     359,   276,    86,   278,   285,   290,    87,    88,    63,    89,
      38,    64,    65,    66,    67,    90,   291,    68,   360,    69,
      70,    71,    72,   288,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   164,   165,   166,   167,
     168,   169,   170,   171,   292,   298,   302,    73,   507,   303,
      74,    75,    76,   304,    77,    78,   347,   350,    79,    80,
      81,   364,    82,    83,    84,   159,   160,   161,   365,    85,
     402,   371,    86,   375,   376,   377,    87,    88,    63,    89,
      38,    64,    65,    66,    67,    90,   379,    68,   403,    69,
      70,    71,    72,   380,   381,   382,   387,   388,   409,   394,
     400,   411,   430,   432,   438,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   433,   444,   372,    73,   450,   212,
      74,    75,    76,   451,    77,    78,   453,   455,    79,    80,
      81,   465,    82,    83,    84,   510,   511,   512,   454,    85,
     457,   471,    86,   477,   488,   493,    87,    88,    63,    89,
      38,    64,    65,    66,    67,    90,   495,    68,  -240,    69,
      70,    71,    72,   496,   504,   500,   505,   506,    56,   522,
     524,   547,   548,   530,   550,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   141,   462,   475,    73,   198,   345,
      74,    75,    76,    13,    77,    78,   135,   309,    79,    80,
      81,   263,    82,    83,    84,   510,   511,   512,   421,    85,
      53,   349,    86,   310,     0,   187,    87,    88,    63,    89,
      38,    64,    65,    66,    67,    90,   266,   149,  -242,    69,
      70,    71,    72,   188,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,   515,   516,   517,
     518,   519,   520,   521,     0,     0,     0,    73,     0,     0,
      74,    75,    76,     0,    77,    78,    23,  -185,    79,    80,
      81,    30,    82,    83,    84,   159,   160,   161,     0,    85,
       0,     0,    86,   150,     0,     0,    87,    88,     0,    89,
       0,   151,     0,     0,     0,    90,    63,   152,    38,    64,
      65,    66,    67,     0,     0,    68,     0,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,    74,    75,
      76,     0,    77,    78,     0,     0,    79,    80,    81,     0,
      82,    83,    84,     0,     0,     0,     0,    85,     0,     0,
      86,   150,     0,     0,    87,    88,     0,    89,     0,   151,
       0,     0,     0,    90,   315,   152,    38,    64,    65,    66,
      67,     0,     0,   149,     0,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,   316,     0,   317,     0,
       0,     0,     0,   318,   319,   320,   321,     0,   322,   323,
     324,     0,     0,    73,     0,     0,    74,    75,    76,   325,
      77,    78,    23,  -185,    79,    80,    81,    30,    82,    83,
      84,     0,     0,     0,     0,    85,     0,     0,    86,     0,
       0,     0,    87,    88,   326,    89,     0,   216,   -50,     0,
      63,    90,    38,    64,    65,    66,    67,     0,     0,    68,
       0,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,   316,     0,   317,   459,   460,     0,     0,   318,
     319,   320,   321,     0,   322,   323,   324,     0,     0,    73,
       0,     0,    74,    75,    76,   325,    77,    78,     0,     0,
      79,    80,    81,     0,    82,    83,    84,     0,     0,     0,
       0,    85,     0,     0,    86,     0,     0,     0,    87,    88,
     326,    89,     0,   216,  -149,     0,    63,    90,    38,    64,
      65,    66,    67,     0,     0,    68,     0,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,   316,     0,
     317,     0,     0,     0,     0,   318,   319,   320,   321,     0,
     322,   323,   324,     0,     0,    73,     0,     0,    74,    75,
      76,   325,    77,    78,     0,     0,    79,    80,    81,     0,
      82,    83,    84,     0,     0,     0,     0,    85,   156,     0,
      86,   159,   160,   161,    87,    88,   326,    89,     0,   216,
       0,     0,    63,    90,    38,    64,    65,    66,    67,     0,
       0,   149,     0,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,    73,     0,     0,    74,    75,    76,     0,    77,    78,
      23,  -185,    79,    80,    81,    30,    82,    83,    84,     0,
       0,     0,     0,    85,     0,     0,    86,   510,   511,   512,
      87,    88,  -157,    89,     0,     0,     0,     0,    63,    90,
      38,    64,    65,    66,    67,     0,     0,    68,     0,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,     0,     0,   515,
     516,   517,   518,   519,   520,   521,     0,    73,     0,     0,
      74,    75,    76,     0,    77,    78,     0,     0,    79,    80,
      81,     0,    82,    83,    84,   159,   160,   161,     0,    85,
     258,     0,    86,     0,     0,     0,    87,    88,    63,    89,
      38,    64,    65,    66,    67,    90,     0,    68,     0,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   167,
     168,   169,   170,   171,     0,     0,     0,    73,     0,     0,
      74,    75,    76,     0,    77,    78,     0,     0,    79,    80,
      81,     0,    82,    83,    84,   510,   511,   512,     0,    85,
       0,   159,    86,   161,     0,     0,    87,    88,     0,    89,
    -237,     0,  -237,     0,    63,    90,    38,    64,    65,    66,
      67,     0,     0,    68,     0,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   516,   517,
     518,   519,   520,   521,   166,   167,   168,   169,   170,   171,
       0,     0,     0,    73,     0,     0,    74,    75,    76,     0,
      77,    78,     0,     0,    79,    80,    81,     0,    82,    83,
      84,   510,     0,   512,     0,    85,     0,     0,    86,     0,
       0,     0,    87,    88,     0,    89,  -235,     0,     0,     0,
      63,    90,    38,    64,    65,    66,    67,     0,     0,    68,
       0,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   516,   517,   518,   519,   520,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,    74,    75,    76,     0,    77,    78,     0,     0,
      79,    80,    81,     0,    82,    83,    84,     0,     0,     0,
       0,    85,     0,     0,    86,     0,     0,     0,    87,    88,
       0,    89,     0,     0,  -235,     0,    63,    90,    38,    64,
      65,    66,    67,     0,     0,    68,     0,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,    74,    75,
      76,     0,    77,    78,     0,     0,    79,    80,    81,     0,
      82,    83,    84,     0,     0,     0,     0,    85,     0,     0,
      86,     0,     0,     0,    87,    88,   383,    89,     0,     0,
       0,     0,    63,    90,    38,    64,    65,    66,    67,     0,
       0,    68,     0,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,    74,    75,    76,     0,    77,    78,
       0,     0,    79,    80,    81,     0,    82,    83,    84,     0,
       0,     0,     0,    85,     0,     0,    86,     0,     0,     0,
      87,    88,  -157,    89,     0,     0,     0,     0,    63,    90,
      38,    64,    65,    66,    67,     0,     0,    68,     0,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
      74,    75,    76,     0,    77,    78,     0,     0,    79,    80,
      81,     0,    82,    83,    84,     0,     0,     0,     0,    85,
       0,     0,    86,     0,     0,     0,    87,    88,     0,    89,
    -157,     0,     0,     0,    63,    90,    38,    64,    65,    66,
      67,     0,     0,    68,     0,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,    74,    75,    76,     0,
      77,    78,     0,     0,    79,    80,    81,     0,    82,    83,
      84,     0,     0,     0,     0,    85,     0,     0,    86,     0,
       0,     0,    87,    88,    63,    89,    38,    64,    65,    66,
      67,    90,     0,    68,     0,   132,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,    74,    75,    76,     0,
      77,    78,     0,     0,    79,    80,    81,     0,    82,    83,
      84,     0,     0,     0,     0,    85,     0,     0,    86,     0,
       0,     0,    87,    88,     0,    89,     0,     0,     0,     0,
       0,    90,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   201,     0,     0,
       0,     0,     0,     0,     0,   156,   157,   158,   159,   160,
     161,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,   442,   156,   157,   158,
     159,   160,   161,     0,     0,     0,   467,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   156,
     157,   158,   159,   160,   161,     0,     0,   289,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   156,
     157,   158,   159,   160,   161,     0,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   156,   157,   158,   159,   160,   161,     0,   279,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   156,   157,   158,   159,   160,   161,     0,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   156,   157,   158,   159,   160,   161,     0,
     372,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   156,   157,   158,   159,   160,   161,     0,
     395,     0,     0,     0,     0,   272,   156,   157,   158,   159,
     160,   161,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      22,    22,   449,    50,    74,    10,    16,   267,    72,    16,
      28,    16,    72,   139,   143,   141,     9,    39,    39,    89,
      67,   451,   151,   137,   410,   139,     3,   141,    28,     1,
      77,   145,   379,   380,    56,    56,   327,    42,    29,    86,
      87,    88,     0,   107,    37,    12,    13,   107,   339,   435,
      82,    11,   181,   182,   101,    40,    49,     3,   128,    77,
      40,     7,    72,   378,    71,    58,    40,    71,    12,    13,
     500,   103,   104,    71,   144,   122,    76,     3,     4,   126,
     150,    81,    66,   374,    89,    76,    76,    72,    55,   136,
       3,     4,    72,   140,    18,    72,   143,   480,    72,    71,
      24,   548,    74,   135,   151,   152,    63,   454,   178,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   508,   173,   120,    52,   389,
       4,    72,   447,    74,   181,   182,    80,   184,    62,    65,
      10,   184,   273,    69,    70,   215,    72,   462,   433,    73,
      40,    77,    65,   200,    50,   470,    69,    70,    50,    72,
      28,   154,    10,   210,   234,   212,   295,   210,   490,    39,
     492,    10,     3,     4,   305,   490,   461,   492,     0,    49,
      50,   496,    72,   253,    54,   255,    76,    77,   258,    11,
     304,    65,   452,    51,   308,    69,    70,    28,    72,   192,
     124,    49,    64,   127,    62,    10,    54,    77,    76,     3,
      49,    73,    64,    81,   529,    54,    20,   346,    71,    71,
     252,    26,    27,    76,    71,    74,   273,    75,   298,    76,
     300,    74,   279,   362,    65,   282,   551,    74,    69,    70,
      76,    72,   289,   290,    49,    81,    72,   294,   295,    54,
     174,   175,    76,   177,   324,   287,   180,    81,   305,   385,
      64,    65,    66,    67,    68,    15,    16,    76,    76,   301,
      76,   385,    81,    81,     3,    81,   281,    76,     7,    12,
      13,    10,    81,    12,    13,    14,    71,   357,    38,   359,
      76,    41,    42,    76,    10,    81,    12,    13,    10,   346,
      12,    13,    66,    67,    68,   375,   376,   377,   372,   379,
     357,    40,   372,    16,    43,   362,    45,    40,    73,    48,
      38,    76,   327,    41,    42,    40,    55,    56,    57,    79,
      80,    20,   402,    49,   339,    12,    13,    49,    54,   409,
      12,    13,    54,    72,    20,    21,    22,    72,   395,    78,
      64,    65,    66,    67,    68,   402,    10,    73,    12,    13,
      22,    79,    80,   477,    73,    73,   430,    76,    76,   374,
     430,    73,    15,    16,    76,    64,    65,    66,    67,    68,
      73,   451,    72,    76,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    73,    72,    49,    76,    73,    40,    73,
      54,   471,    76,    16,    73,    72,   453,    76,   455,    72,
     457,    64,    65,    66,    67,    68,    73,    73,   465,    76,
      76,    17,    18,    72,    20,    21,    22,   420,    73,   434,
     500,    76,    66,    67,    68,    76,    77,   459,     1,    72,
       3,     4,     5,     6,     7,    76,    77,    10,    54,    12,
      13,    14,    15,    12,    13,    76,    77,    74,   480,    12,
      13,    80,   484,   484,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   397,    76,    77,    73,    40,    76,    77,
      43,    44,    45,    73,    47,    48,   508,    76,    51,    52,
      53,    73,    55,    56,    57,    20,    21,    22,   484,    62,
      63,    73,    65,    73,    73,    76,    69,    70,     1,    72,
       3,     4,     5,     6,     7,    78,    81,    10,    81,    12,
      13,    14,    15,    75,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,    61,    62,    63,    64,
      65,    66,    67,    68,    73,    63,    73,    40,   534,    73,
      43,    44,    45,    73,    47,    48,    73,    73,    51,    52,
      53,    73,    55,    56,    57,    20,    21,    22,    77,    62,
      63,    73,    65,    72,    72,    72,    69,    70,     1,    72,
       3,     4,     5,     6,     7,    78,    72,    10,    81,    12,
      13,    14,    15,    72,    71,    71,    45,    75,    43,    74,
      73,    73,    72,    71,    73,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    76,    73,    76,    40,    30,    76,
      43,    44,    45,    71,    47,    48,    16,    34,    51,    52,
      53,    77,    55,    56,    57,    20,    21,    22,    76,    62,
      16,    72,    65,    73,    77,    73,    69,    70,     1,    72,
       3,     4,     5,     6,     7,    78,    73,    10,    81,    12,
      13,    14,    15,    24,     4,    71,     4,     4,    64,    71,
      75,    71,    73,    77,    77,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    81,   434,   454,    40,   120,   284,
      43,    44,    45,     4,    47,    48,    74,   270,    51,    52,
      53,   183,    55,    56,    57,    20,    21,    22,   379,    62,
      37,   290,    65,   271,    -1,   110,    69,    70,     1,    72,
       3,     4,     5,     6,     7,    78,   191,    10,    81,    12,
      13,    14,    15,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    20,    21,    22,    -1,    62,
      -1,    -1,    65,    66,    -1,    -1,    69,    70,    -1,    72,
      -1,    74,    -1,    -1,    -1,    78,     1,    80,     3,     4,
       5,     6,     7,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    -1,    47,    48,    -1,    -1,    51,    52,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,    66,    -1,    -1,    69,    70,    -1,    72,    -1,    74,
      -1,    -1,    -1,    78,     1,    80,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    -1,    74,    75,    -1,
       1,    78,     3,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    52,    53,    -1,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,    70,
      71,    72,    -1,    74,    75,    -1,     1,    78,     3,     4,
       5,     6,     7,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    17,    -1,
      65,    20,    21,    22,    69,    70,    71,    72,    -1,    74,
      -1,    -1,     1,    78,     3,     4,     5,     6,     7,    -1,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    40,    -1,    -1,    43,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    20,    21,    22,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,     1,    78,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    40,    -1,    -1,
      43,    44,    45,    -1,    47,    48,    -1,    -1,    51,    52,
      53,    -1,    55,    56,    57,    20,    21,    22,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    69,    70,     1,    72,
       3,     4,     5,     6,     7,    78,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    -1,    47,    48,    -1,    -1,    51,    52,
      53,    -1,    55,    56,    57,    20,    21,    22,    -1,    62,
      -1,    20,    65,    22,    -1,    -1,    69,    70,    -1,    72,
      73,    -1,    75,    -1,     1,    78,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    -1,
      47,    48,    -1,    -1,    51,    52,    53,    -1,    55,    56,
      57,    20,    -1,    22,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    72,    73,    -1,    -1,    -1,
       1,    78,     3,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    43,    44,    45,    -1,    47,    48,    -1,    -1,
      51,    52,    53,    -1,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,    70,
      -1,    72,    -1,    -1,    75,    -1,     1,    78,     3,     4,
       5,     6,     7,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    -1,    47,    48,    -1,    -1,    51,    52,    53,    -1,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,    -1,    -1,    -1,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,     1,    78,     3,     4,     5,     6,     7,    -1,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    43,    44,    45,    -1,    47,    48,
      -1,    -1,    51,    52,    53,    -1,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,     1,    78,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    -1,    47,    48,    -1,    -1,    51,    52,
      53,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,    72,
      73,    -1,    -1,    -1,     1,    78,     3,     4,     5,     6,
       7,    -1,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    -1,
      47,    48,    -1,    -1,    51,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,     1,    72,     3,     4,     5,     6,
       7,    78,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    -1,
      47,    48,    -1,    -1,    51,    52,    53,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    81,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    81,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    17,
      18,    19,    20,    21,    22,    -1,    -1,    77,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    17,
      18,    19,    20,    21,    22,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    17,    18,    19,    20,    21,    22,    -1,    76,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    17,    18,    19,    20,    21,    22,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    17,    18,    19,    20,    21,    22,    -1,
      76,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    17,    18,    19,    20,    21,    22,    -1,
      76,    -1,    -1,    -1,    -1,    29,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,     0,    11,    92,    93,   135,   136,   143,
     144,   156,   157,   144,    71,    91,   137,    66,   151,   166,
     167,    10,    39,    49,    54,    77,   145,   146,   147,   148,
      54,    75,   146,    12,    13,   152,    71,    76,     3,    72,
     183,   184,    63,    12,    13,   152,    50,    12,    13,   138,
      16,    94,   151,   166,   184,     3,    64,    71,   146,    74,
     139,   140,   151,     1,     4,     5,     6,     7,    10,    12,
      13,    14,    15,    40,    43,    44,    45,    47,    48,    51,
      52,    53,    55,    56,    57,    62,    65,    69,    70,    72,
      78,   115,   116,   117,   119,   120,   121,   122,   123,   125,
     126,   150,   152,   154,   155,   168,   169,   178,   179,   180,
     182,   183,   185,   186,    72,   152,    73,   184,   151,    71,
      76,   152,    16,   115,    40,    72,   118,    40,    72,   116,
     117,   152,    12,   114,   115,   154,    72,    86,   115,   124,
      72,    86,    72,   118,    72,    87,   115,   115,   115,    10,
      66,    74,    80,   114,   146,    72,    17,    18,    19,    20,
      21,    22,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    15,    16,    38,    41,    42,    79,    80,   115,
      40,   118,   118,    72,    76,    77,   116,   179,   180,    12,
      13,   146,   149,   153,   158,   159,   160,    22,   139,   115,
       8,     9,   181,   152,   115,   171,   172,   173,    55,   152,
      76,    77,    76,    77,   115,    72,    74,   108,   177,   177,
     115,   177,    54,   173,   114,   108,   114,   173,   115,   170,
     174,   175,    73,   151,    88,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   152,    80,   152,    80,   152,    28,    63,   114,
     152,   173,   173,   158,   172,    73,   178,   151,    73,    29,
      76,   115,    29,    76,    73,   172,    73,   115,    73,    76,
     114,    85,    76,    12,    13,    73,    73,    73,    75,    77,
      76,    81,    73,   114,    77,   118,   114,   114,    63,   114,
      28,    81,    73,    73,    73,    76,    77,   153,    95,   160,
     181,   171,    77,   115,    73,     1,    23,    25,    30,    31,
      32,    33,    35,    36,    37,    46,    71,    97,    98,   100,
     101,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     114,   127,   146,   115,   142,   142,   118,    73,   115,   170,
      73,    73,   115,   173,    81,    81,   114,    28,    81,    63,
      81,   114,   118,   108,    73,    77,   161,     1,    71,    96,
     108,    73,    76,   176,    71,    72,    72,    72,    83,    72,
      72,    71,    71,    71,   114,    99,   109,    45,    75,   151,
     162,   163,   109,    71,    74,    76,    73,    76,    73,   173,
      73,    81,    63,    81,   114,   115,   114,    81,   173,    43,
     116,    73,   109,   114,   114,   114,    97,   114,   131,   132,
     149,   164,   165,    12,    13,   133,   134,   164,    71,   177,
      72,   153,    71,    76,   113,   115,   141,   152,    73,   114,
     115,    81,    81,    81,    73,   114,   176,    73,    73,    73,
      30,    71,   151,    16,    76,    34,   116,    16,   162,    26,
      27,   112,   129,   146,   176,    77,    81,    81,    77,    97,
      83,    72,   131,   153,   115,   133,   115,    73,   115,     4,
      28,    65,    69,    70,    72,   130,   184,   187,    77,   162,
      97,   128,   129,    73,   115,    73,    24,   102,    97,   114,
      71,    73,   108,   130,     4,     4,     4,   187,    28,    77,
      20,    21,    22,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    71,   128,    75,   128,    97,    73,   131,    84,
      77,    73,    77,   130,    72,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,    71,    73,    97,
      77,    83,    97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    94,    95,
      93,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    99,   100,
     100,   101,   102,   102,   103,   104,   105,   106,   107,   108,
     109,   109,   109,   109,   110,   111,   112,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     122,   123,   124,   125,   126,   126,   127,   128,   128,   128,
     129,   129,   129,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   134,   134,   135,   136,   137,   138,
     137,   139,   139,   140,   141,   142,   142,   143,   144,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   148,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   155,   155,   156,   157,   158,   158,
     158,   159,   159,   160,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   165,   166,   166,   167,   167,   168,   169,
     170,   171,   171,   172,   172,   173,   173,   173,   174,   174,
     175,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     180,   181,   181,   182,   182,   182,   182,   183,   183,   184,
     184,   184,   185,   185,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,     1,     3,
       0,     0,     1,     1,     3,     1,     1,     1,     0,     0,
       9,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     6,     3,     0,     2,
       3,     6,     0,     2,     6,     8,    10,     8,     6,     4,
       0,     2,     2,     3,     1,     3,     1,     0,     4,     1,
       3,     2,     3,     3,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     5,     3,     3,     3,     5,     5,     4,
       5,     6,     7,     8,     7,     5,     6,     6,     8,     7,
       5,     3,     5,     4,     6,     4,     5,     5,     1,     4,
       4,     6,     6,     4,     4,     7,     6,     7,     7,     9,
       3,     3,     0,     3,     3,     4,     4,     2,     2,     0,
       3,     5,     4,     4,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     0,     0,
       5,     1,     3,     2,     3,     0,     3,     2,     0,     2,
       1,     0,     1,     2,     1,     0,     1,     2,     2,     1,
       5,     1,     2,     4,     0,     1,     1,     1,     1,     1,
       3,     3,     1,     2,     3,     3,     4,     2,     0,     1,
       2,     1,     3,     2,     4,     1,     0,     5,     1,     3,
       2,     4,     3,     3,     1,     3,     2,     4,     1,     2,
       3,     1,     2,     1,     3,     0,     1,     2,     1,     3,
       0,     1,     2,     0,     3,     1,     3,     1,     1,     1,
       3,     1,     3,     1,     1,     2,     2,     1,     2,     1,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, yyscanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, yyscanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* yyscanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (yyscanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* yyscanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, yyscanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void* yyscanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), yyscanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, yyscanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    yy_state_t yyesa[20];
    yy_state_t *yyes;
    YYPTRDIFF_T yyes_capacity;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yypstate* yyps;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypstate_expected_tokens (yypstate *yyps,
                          yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}


/* Similar to the previous function.  */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
}


#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void* yyscanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (yyscanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yystacksize yyps->yystacksize
#define yyesa yyps->yyesa
#define yyes yyps->yyes
#define yyes_capacity yyps->yyes_capacity

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yyes = yyesa;
  yyes_capacity = 20;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      if (yyes != yyesa)
        YYSTACK_FREE (yyes);
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc, void* yyscanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = *yypushed_loc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* loop_start: %empty  */
#line 253 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                   { (yyval.number) = rule_loop_open(); }
#line 2693 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 3: /* foreach_start: %empty  */
#line 254 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                      { (yyval.number) = rule_foreach_open(); }
#line 2699 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 4: /* block_start: %empty  */
#line 255 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                    { (yyval.number) = rule_block_open(); }
#line 2705 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 5: /* special_context_start: %empty  */
#line 256 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                              { (yyval.number) = rule_special_context_open(); }
#line 2711 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 6: /* tree_context_start: %empty  */
#line 257 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                           { (yyval.number) = rule_tree_context_open(); }
#line 2717 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 7: /* dollar_start: %empty  */
#line 258 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                     { (yyval.contextp) = rule_dollar_open(); }
#line 2723 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 8: /* all: program  */
#line 267 "$REPO_ROOT$/src/compiler/internal/grammar.y"
           { rule_program((yyvsp[0].node)); }
#line 2729 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 9: /* program: program def opt_semicolon  */
#line 272 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { rule_program_append(&(yyval.node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2735 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 10: /* program: %empty  */
#line 273 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { (yyval.node) = 0; }
#line 2741 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 12: /* opt_semicolon: ';'  */
#line 279 "$REPO_ROOT$/src/compiler/internal/grammar.y"
         { rule_opt_semicolon(); }
#line 2747 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 14: /* def: type name_list ';'  */
#line 291 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                        { rule_def_global_var((yyvsp[-2].number)); (yyval.node) = 0; }
#line 2753 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 18: /* @1: %empty  */
#line 317 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.number) = rule_func_type((yyvsp[-2].number), (yyvsp[-1].number), (yyvsp[0].string)); }
#line 2759 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 19: /* @2: %empty  */
#line 319 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.number) = rule_func_proto((yyvsp[-3].number), (yyvsp[-5].number), (yyvsp[-4].string), &(yyvsp[-4].shared_string), (yyvsp[-1].argument)); }
#line 2765 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 20: /* function: type optional_star identifier @1 '(' argument ')' @2 block_or_semi  */
#line 321 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_func(&(yyval.node), (yyvsp[-5].number), (yyvsp[-7].number), (yyvsp[-6].shared_string), (yyvsp[-3].argument), &(yyvsp[-1].number), &(yyvsp[0].node)); }
#line 2771 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 21: /* block_or_semi: block  */
#line 326 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { (yyval.node) = rule_block_or_semi((yyvsp[0].decl).node); }
#line 2777 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 22: /* block_or_semi: ';'  */
#line 327 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { (yyval.node) = 0; }
#line 2783 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 23: /* block_or_semi: error  */
#line 328 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { (yyval.node) = 0; }
#line 2789 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 24: /* statement: comma_expr ';'  */
#line 338 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_expr((yyvsp[-1].node)); }
#line 2795 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 28: /* statement: stmt_for  */
#line 342 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_compound_stmt((yyvsp[0].decl)); }
#line 2801 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 29: /* statement: stmt_foreach  */
#line 343 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_compound_stmt((yyvsp[0].decl)); }
#line 2807 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 32: /* statement: block  */
#line 346 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_compound_stmt((yyvsp[0].decl)); }
#line 2813 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 33: /* statement: ';'  */
#line 347 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = 0; }
#line 2819 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 34: /* statement: L_BREAK ';'  */
#line 348 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_break(); }
#line 2825 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 35: /* statement: L_CONTINUE ';'  */
#line 349 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_statement_continue(); }
#line 2831 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 36: /* statement: try_body L_CATCH '(' lvalue ')' block  */
#line 350 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                          {
      parse_node_t* assignment;
      rule_expr_assign(&assignment, (yyvsp[-2].node), F_ASSIGN, (yyvsp[-5].node));
      CREATE_IF((yyval.node), assignment, rule_statement_compound_stmt((yyvsp[0].decl)), nullptr);
    }
#line 2841 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 37: /* try_body: L_TRY try_context_start expr_or_block  */
#line 358 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                        {
    if (compiling_async_function && !current_function_context)
      rule_acatch(&(yyval.node), (yyvsp[0].node), (yyvsp[-1].number));
    else
      rule_catch(&(yyval.node), (yyvsp[0].node), (yyvsp[-1].number));
  }
#line 2852 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 38: /* try_context_start: %empty  */
#line 367 "$REPO_ROOT$/src/compiler/internal/grammar.y"
         {
    (yyval.number) = compiling_async_function && !current_function_context ?
         rule_acatch_context_open() : rule_special_context_open();
  }
#line 2861 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 39: /* stmt_return: L_RETURN ';'  */
#line 376 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_return_void(&(yyval.node)); }
#line 2867 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 40: /* stmt_return: L_RETURN comma_expr ';'  */
#line 377 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_return_expr(&(yyval.node), (yyvsp[-1].node)); }
#line 2873 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 41: /* stmt_cond: L_IF '(' comma_expr ')' statement optional_else_part  */
#line 383 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_cond(&(yyval.node), (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2879 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 42: /* optional_else_part: %empty  */
#line 387 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                { (yyval.node) = 0; }
#line 2885 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 43: /* optional_else_part: L_ELSE statement  */
#line 388 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2891 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 44: /* stmt_while: L_WHILE '(' comma_expr ')' loop_start statement  */
#line 394 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_while(&(yyval.node), (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 2897 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 45: /* stmt_do: L_DO loop_start statement L_WHILE '(' comma_expr ')' ';'  */
#line 400 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_do(&(yyval.node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-6].number)); }
#line 2903 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 46: /* stmt_for: L_FOR '(' for_init ';' for_expr ';' for_expr ')' loop_start statement  */
#line 406 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_for(&(yyval.decl), &(yyvsp[-7].decl), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 2909 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 47: /* stmt_foreach: L_FOREACH '(' foreach_vars L_IN expr ')' foreach_start statement  */
#line 412 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_foreach(&(yyval.decl), &(yyvsp[-5].decl), (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 2915 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 48: /* stmt_switch: switch_header '{' local_declarations case switch_block '}'  */
#line 418 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_switch(&(yyval.node), (yyvsp[-5].switch_header).expr, &(yyvsp[-3].decl), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[-5].switch_header).saved_context, (yyvsp[-5].switch_header).saved_cases_size); }
#line 2921 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 49: /* block: '{' block_start statements '}'  */
#line 430 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_block(&(yyval.decl), (yyvsp[-1].decl).node, (yyvsp[-2].number)); }
#line 2927 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 50: /* statements: %empty  */
#line 436 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_block_statements_empty(&(yyval.decl)); }
#line 2933 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 51: /* statements: statement statements  */
#line 438 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_block_statements_stmt(&(yyval.decl), (yyvsp[-1].node), &(yyvsp[0].decl)); }
#line 2939 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 52: /* statements: local_declaration_statement statements  */
#line 440 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_block_statements_decl(&(yyval.decl), &(yyvsp[-1].decl), &(yyvsp[0].decl)); }
#line 2945 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 53: /* statements: error ';' statements  */
#line 442 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_block_statements_error(&(yyval.decl), &(yyvsp[0].decl)); }
#line 2951 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 54: /* local_decl_statement_header: basic_type  */
#line 447 "$REPO_ROOT$/src/compiler/internal/grammar.y"
              { rule_local_declaration_statement_set_type((yyvsp[0].number)); (yyval.number) = (yyvsp[0].number); }
#line 2957 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 55: /* local_declaration_statement: local_decl_statement_header local_name_list ';'  */
#line 452 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_local_declaration_statement(&(yyval.decl), &(yyvsp[-1].decl)); }
#line 2963 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 56: /* local_decl_header: basic_type  */
#line 457 "$REPO_ROOT$/src/compiler/internal/grammar.y"
              { rule_local_declarations_set_type((yyvsp[0].number)); (yyval.number) = (yyvsp[0].number); }
#line 2969 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 57: /* local_declarations: %empty  */
#line 462 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.decl).node = 0; (yyval.decl).num = 0; }
#line 2975 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 58: /* local_declarations: local_declarations local_decl_header local_name_list ';'  */
#line 464 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_local_declarations(&(yyval.decl), &(yyvsp[-3].decl), &(yyvsp[-1].decl)); }
#line 2981 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 60: /* comma_expr: comma_expr ',' expr  */
#line 483 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                { rule_comma_expr(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2987 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 61: /* expr: ref lvalue  */
#line 487 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                      { rule_expr_ref(&(yyval.node), (yyvsp[0].node)); }
#line 2993 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 62: /* expr: lvalue L_ASSIGN expr  */
#line 488 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                      { rule_expr_assign(&(yyval.node), (yyvsp[-2].node), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 2999 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 63: /* expr: error L_ASSIGN expr  */
#line 489 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                      { rule_expr_assign_error(&(yyval.node), (yyvsp[0].node)); }
#line 3005 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 64: /* expr: expr '?' expr ':' expr  */
#line 491 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                            { rule_expr_ternary(&(yyval.node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3011 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 65: /* expr: expr L_QUESTION_QUESTION expr  */
#line 492 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { rule_expr_nullish(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3017 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 66: /* expr: expr L_LOR expr  */
#line 493 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { rule_expr_lor(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3023 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 67: /* expr: expr L_LAND expr  */
#line 494 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { rule_expr_land(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3029 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 68: /* expr: expr '|' expr  */
#line 496 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                              { rule_expr_or(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3035 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 69: /* expr: expr '^' expr  */
#line 497 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                              { rule_expr_xor(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3041 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 70: /* expr: expr '&' expr  */
#line 498 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                              { rule_expr_and(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3047 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 71: /* expr: expr L_EQ_NE expr  */
#line 500 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_expr_eq_ne(&(yyval.node), (yyvsp[-1].number), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3053 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 72: /* expr: expr L_ORDER expr  */
#line 501 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { rule_expr_order(&(yyval.node), (yyvsp[-2].node), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3059 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 73: /* expr: expr '<' expr  */
#line 502 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { rule_expr_lt(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3065 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 74: /* expr: expr L_SHIFT expr  */
#line 504 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_expr_shift(&(yyval.node), (yyvsp[-1].number), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3071 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 75: /* expr: expr '+' expr  */
#line 506 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             {
        rule_set_operand_ranges((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yylsp[-2]).last_column,
                                (yylsp[-1]).first_line, (yylsp[-1]).first_column,
                                (yylsp[0]).first_line, (yylsp[0]).first_column, (yylsp[0]).last_column);
        rule_expr_add(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node));
        rule_clear_operand_ranges();
    }
#line 3083 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 76: /* expr: expr '-' expr  */
#line 513 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_expr_sub(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3089 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 77: /* expr: expr '*' expr  */
#line 514 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_expr_mul(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3095 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 78: /* expr: expr '%' expr  */
#line 515 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_expr_mod(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3101 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 79: /* expr: expr '/' expr  */
#line 516 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_expr_div(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3107 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 80: /* expr: cast expr  */
#line 518 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { rule_expr_cast(&(yyval.node), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3113 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 81: /* expr: L_INC_DEC lvalue  */
#line 519 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_expr_pre_incdec(&(yyval.node), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3119 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 82: /* expr: '!' expr  */
#line 520 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                    { rule_expr_not(&(yyval.node), (yyvsp[0].node)); }
#line 3125 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 83: /* expr: '~' expr  */
#line 521 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                    { rule_expr_compl(&(yyval.node), (yyvsp[0].node)); }
#line 3131 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 84: /* expr: '-' expr  */
#line 522 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { rule_expr_neg(&(yyval.node), (yyvsp[0].node)); }
#line 3137 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 85: /* expr: L_AWAIT expr  */
#line 523 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { rule_expr_await(&(yyval.node), (yyvsp[0].node)); }
#line 3143 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 86: /* expr: lvalue L_INC_DEC  */
#line 525 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                          { rule_expr_post_incdec(&(yyval.node), (yyvsp[0].number), (yyvsp[-1].node)); }
#line 3149 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 93: /* lvalue: primary_expr  */
#line 537 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                { (yyval.node) = rule_lvalue((yyvsp[0].node)); }
#line 3155 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 95: /* primary_expr: L_DEFINED_NAME  */
#line 547 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_primary_expr_defined_name(&(yyval.node), (yyvsp[0].ihe)); }
#line 3161 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 96: /* primary_expr: L_IDENTIFIER  */
#line 548 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_primary_expr_identifier(&(yyval.node), (yyvsp[0].string)); }
#line 3167 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 97: /* primary_expr: L_PARAMETER  */
#line 549 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_primary_expr_parameter(&(yyval.node), (yyvsp[0].number)); }
#line 3173 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 99: /* primary_expr: '(' comma_expr ')'  */
#line 551 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { (yyval.node) = (yyvsp[-1].node); }
#line 3179 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 103: /* primary_expr: '$' '(' dollar_start comma_expr ')'  */
#line 558 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_dollar_expr(&(yyval.node), (yyvsp[-2].contextp), (yyvsp[-1].node)); }
#line 3185 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 104: /* primary_expr: primary_expr L_ARROW identifier  */
#line 561 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                 { rule_primary_expr_member_arrow(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].string)); }
#line 3191 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 105: /* primary_expr: primary_expr '.' identifier  */
#line 562 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                 { rule_primary_expr_member_dot(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].string)); }
#line 3197 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 106: /* primary_expr: primary_expr L_OPTIONAL_DOT identifier  */
#line 568 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_member_optional(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].string)); }
#line 3203 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 107: /* primary_expr: primary_expr L_OPTIONAL_DOT '[' comma_expr ']'  */
#line 570 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_index_optional(&(yyval.node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3209 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 108: /* primary_expr: primary_expr L_DOT_OPTIONAL '[' comma_expr ']'  */
#line 572 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_index_optional(&(yyval.node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3215 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 109: /* primary_expr: primary_expr '[' comma_expr ']'  */
#line 577 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_index(&(yyval.node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3221 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 110: /* primary_expr: primary_expr '[' '<' comma_expr ']'  */
#line 579 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_index_r(&(yyval.node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3227 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 111: /* primary_expr: primary_expr '[' comma_expr L_RANGE comma_expr ']'  */
#line 581 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_nn(&(yyval.node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3233 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 112: /* primary_expr: primary_expr '[' '<' comma_expr L_RANGE comma_expr ']'  */
#line 583 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_rn(&(yyval.node), (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3239 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 113: /* primary_expr: primary_expr '[' '<' comma_expr L_RANGE '<' comma_expr ']'  */
#line 585 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_rr(&(yyval.node), (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3245 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 114: /* primary_expr: primary_expr '[' comma_expr L_RANGE '<' comma_expr ']'  */
#line 587 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_nr(&(yyval.node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3251 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 115: /* primary_expr: primary_expr '[' comma_expr L_RANGE ']'  */
#line 589 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_ne(&(yyval.node), (yyvsp[-4].node), (yyvsp[-2].node)); }
#line 3257 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 116: /* primary_expr: primary_expr '[' '<' comma_expr L_RANGE ']'  */
#line 591 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_re(&(yyval.node), (yyvsp[-5].node), (yyvsp[-2].node)); }
#line 3263 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 117: /* primary_expr: primary_expr '[' L_RANGE '<' comma_expr ']'  */
#line 593 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_nr(&(yyval.node), (yyvsp[-5].node), 0, (yyvsp[-1].node)); }
#line 3269 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 118: /* primary_expr: primary_expr '[' '<' comma_expr L_RANGE '<' expr ']'  */
#line 596 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_rr(&(yyval.node), (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 3275 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 119: /* primary_expr: primary_expr '[' '<' comma_expr L_RANGE expr ']'  */
#line 598 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_range_rn(&(yyval.node), (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3281 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 120: /* primary_expr: lambda_return_type '(' argument ')' block  */
#line 603 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_anon_func(&(yyval.node), &(yyvsp[-4].func_block), &(yyvsp[-2].argument), &(yyvsp[0].decl)); }
#line 3287 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 121: /* primary_expr: functional_open ':' ')'  */
#line 610 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_functional_1(&(yyval.node), (yyvsp[-2].number)); }
#line 3293 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 122: /* primary_expr: functional_open ',' arg_list ':' ')'  */
#line 612 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_functional_2(&(yyval.node), (yyvsp[-4].number), (yyvsp[-2].node)); }
#line 3299 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 123: /* primary_expr: L_FUNCTION_OPEN L_DEFINED_NAME ':' ')'  */
#line 621 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_functional_1(&(yyval.node), rule_functional_ref((yyvsp[-2].ihe))); }
#line 3305 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 124: /* primary_expr: L_FUNCTION_OPEN L_DEFINED_NAME ',' arg_list ':' ')'  */
#line 623 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_functional_2(&(yyval.node), rule_functional_ref((yyvsp[-4].ihe)), (yyvsp[-2].node)); }
#line 3311 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 125: /* primary_expr: L_FUNCTION_OPEN comma_expr ':' ')'  */
#line 625 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_primary_expr_functional_3(&(yyval.node), (yyvsp[-2].node)); }
#line 3317 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 126: /* primary_expr: '(' '[' opt_pair_list ']' ')'  */
#line 628 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                    { rule_primary_expr_mapping(&(yyval.node), (yyvsp[-2].node)); }
#line 3323 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 127: /* primary_expr: '(' '{' opt_arg_list '}' ')'  */
#line 629 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                    { rule_primary_expr_array(&(yyval.node), (yyvsp[-2].node)); }
#line 3329 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 128: /* call_open: '('  */
#line 639 "$REPO_ROOT$/src/compiler/internal/grammar.y"
       { rule_call_open(&(yyval.call_open).saved_context, &(yyval.call_open).saved_refs); }
#line 3335 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 129: /* function_call: efun_override call_open opt_arg_list ')'  */
#line 653 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_efun(&(yyval.node), (yyvsp[-3].number), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3341 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 130: /* function_call: L_NEW call_open opt_arg_list ')'  */
#line 655 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_new(&(yyval.node), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3347 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 131: /* function_call: L_NEW '(' L_CLASS L_DEFINED_NAME opt_class_init ')'  */
#line 657 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_new_class(&(yyval.node), (yyvsp[-2].ihe), (yyvsp[-1].node)); }
#line 3353 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 132: /* function_call: L_NEW '(' L_CLASS L_IDENTIFIER opt_class_init ')'  */
#line 659 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_new_class_undef(&(yyval.node), (yyvsp[-2].string), (yyvsp[-1].node)); }
#line 3359 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 133: /* function_call: L_DEFINED_NAME call_open opt_arg_list ')'  */
#line 661 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_defined_name(&(yyval.node), (yyvsp[-3].ihe), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3365 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 134: /* function_call: function_name call_open opt_arg_list ')'  */
#line 663 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_name(&(yyval.node), (yyvsp[-3].string), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3371 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 135: /* function_call: primary_expr '[' comma_expr ']' call_open opt_arg_list ')'  */
#line 665 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_indexed(&(yyval.node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3377 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 136: /* function_call: primary_expr L_ARROW identifier call_open opt_arg_list ')'  */
#line 667 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_arrow(&(yyval.node), (yyvsp[-5].node), (yyvsp[-3].string), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3383 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 137: /* function_call: '(' '*' comma_expr ')' call_open opt_arg_list ')'  */
#line 669 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_function_call_star(&(yyval.node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-2].call_open).saved_context, (yyvsp[-2].call_open).saved_refs); }
#line 3389 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 138: /* sscanf: L_SSCANF '(' expr ',' expr lvalue_list ')'  */
#line 680 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_sscanf(&(yyval.node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 3395 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 139: /* parse_command: L_PARSE_COMMAND '(' expr ',' expr ',' expr lvalue_list ')'  */
#line 686 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_parse_command(&(yyval.node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 3401 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 140: /* catch: L_CATCH special_context_start expr_or_block  */
#line 692 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_catch(&(yyval.node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 3407 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 141: /* acatch: L_ACATCH acatch_context_start expr_or_block  */
#line 701 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_acatch(&(yyval.node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 3413 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 142: /* acatch_context_start: %empty  */
#line 704 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { (yyval.number) = rule_acatch_context_open(); }
#line 3419 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 143: /* time_expression: L_TIME_EXPRESSION special_context_start expr_or_block  */
#line 709 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_time_expression(&(yyval.node), (yyvsp[0].node), (yyvsp[-1].number)); }
#line 3425 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 144: /* tree: L_TREE tree_context_start block  */
#line 715 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_tree_block(&(yyval.node), (yyvsp[0].decl), (yyvsp[-1].number)); }
#line 3431 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 145: /* tree: L_TREE '(' comma_expr ')'  */
#line 717 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_tree_expr(&(yyval.node), (yyvsp[-1].node)); }
#line 3437 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 146: /* switch_header: L_SWITCH '(' comma_expr ')'  */
#line 728 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.switch_header).expr = (yyvsp[-1].node); rule_switch_pre(&(yyval.switch_header).saved_context, &(yyval.switch_header).saved_cases_size); }
#line 3443 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 147: /* switch_block: case switch_block  */
#line 733 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { rule_switch_block_case(&(yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3449 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 148: /* switch_block: statement switch_block  */
#line 734 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { rule_switch_block_stmt(&(yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3455 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 149: /* switch_block: %empty  */
#line 735 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                            { rule_switch_block_empty(&(yyval.node)); }
#line 3461 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 150: /* case: L_CASE case_label ':'  */
#line 742 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_case_single(&(yyval.node), (yyvsp[-1].node)); }
#line 3467 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 151: /* case: L_CASE case_label L_RANGE case_label ':'  */
#line 744 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_case_range(&(yyval.node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3473 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 152: /* case: L_CASE case_label L_RANGE ':'  */
#line 746 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_case_range_from(&(yyval.node), (yyvsp[-2].node)); }
#line 3479 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 153: /* case: L_CASE L_RANGE case_label ':'  */
#line 748 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_case_range_to(&(yyval.node), (yyvsp[-1].node)); }
#line 3485 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 154: /* case: L_DEFAULT ':'  */
#line 750 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_case_default(&(yyval.node)); }
#line 3491 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 155: /* case_label: constant  */
#line 756 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_case_label_constant(&(yyval.node), (yyvsp[0].number)); }
#line 3497 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 156: /* case_label: string_const  */
#line 757 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_case_label_string(&(yyval.node), (yyvsp[0].string)); }
#line 3503 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 157: /* for_expr: %empty  */
#line 767 "$REPO_ROOT$/src/compiler/internal/grammar.y"
              { (yyval.node) = 0; }
#line 3509 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 159: /* for_init: for_expr  */
#line 774 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_for_init_expr(&(yyval.decl), (yyvsp[0].node)); }
#line 3515 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 160: /* for_init: single_new_local_def_with_init  */
#line 776 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_for_init_local(&(yyval.decl), (yyvsp[0].node)); }
#line 3521 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 161: /* foreach_var: L_DEFINED_NAME  */
#line 781 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                          { rule_foreach_var_defined(&(yyval.decl), (yyvsp[0].ihe)); }
#line 3527 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 162: /* foreach_var: single_new_local_def  */
#line 782 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                          { rule_foreach_var_new_local(&(yyval.decl), (yyvsp[0].number)); }
#line 3533 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 163: /* foreach_var: L_IDENTIFIER  */
#line 783 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                          { rule_foreach_var_identifier(&(yyval.decl), (yyvsp[0].string)); }
#line 3539 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 164: /* foreach_vars: foreach_var  */
#line 789 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_foreach_vars_single(&(yyval.decl), &(yyvsp[0].decl)); }
#line 3545 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 165: /* foreach_vars: foreach_var ',' foreach_var  */
#line 791 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_foreach_vars_double(&(yyval.decl), &(yyvsp[-2].decl), &(yyvsp[0].decl)); }
#line 3551 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 166: /* type_decl: class_header member_list '}'  */
#line 802 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_define_class_members((yyvsp[-2].class_header).ihe, (yyvsp[-2].class_header).classname_index); (yyval.node) = 0; }
#line 3557 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 167: /* class_header: type_modifier_list L_CLASS identifier '{'  */
#line 808 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.class_header).ihe = rule_define_class(&(yyval.class_header).classname_index, (yyvsp[-1].string)); }
#line 3563 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 169: /* $@3: %empty  */
#line 814 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                           { rule_member_list_set_type((yyvsp[0].number)); }
#line 3569 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 173: /* member_name: optional_star identifier  */
#line 826 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                            { rule_member_name((yyvsp[-1].number), (yyvsp[0].string)); }
#line 3575 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 174: /* class_init: identifier ':' expr  */
#line 831 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                       { (yyval.node) = rule_class_init((yyvsp[-2].string), (yyvsp[0].node)); }
#line 3581 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 175: /* opt_class_init: %empty  */
#line 836 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { (yyval.node) = rule_opt_class_init_empty(); }
#line 3587 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 176: /* opt_class_init: opt_class_init ',' class_init  */
#line 837 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                         { (yyval.node) = rule_opt_class_init((yyvsp[-2].node), (yyvsp[0].node)); }
#line 3593 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 177: /* type: type_modifier_list opt_basic_type  */
#line 849 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { (yyval.number) = rule_type((yyvsp[-1].number), (yyvsp[0].number)); }
#line 3599 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 178: /* type_modifier_list: %empty  */
#line 854 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                         { (yyval.number) = 0; }
#line 3605 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 179: /* type_modifier_list: L_TYPE_MODIFIER type_modifier_list  */
#line 855 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                               { (yyval.number) = rule_type_modifier_list((yyvsp[-1].number), (yyvsp[0].number)); }
#line 3611 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 181: /* opt_basic_type: %empty  */
#line 861 "$REPO_ROOT$/src/compiler/internal/grammar.y"
            { (yyval.number) = rule_opt_basic_type_empty(); }
#line 3617 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 183: /* basic_type: opt_atomic_type L_ARRAY  */
#line 867 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { (yyval.number) = (yyvsp[-1].number) | TYPE_MOD_ARRAY; }
#line 3623 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 185: /* opt_atomic_type: %empty  */
#line 873 "$REPO_ROOT$/src/compiler/internal/grammar.y"
            { (yyval.number) = rule_opt_basic_type_empty(); }
#line 3629 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 187: /* atomic_type: L_CLASS L_DEFINED_NAME  */
#line 879 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                            { (yyval.number) = rule_atomic_type_class((yyvsp[0].ihe)); }
#line 3635 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 188: /* atomic_type: L_CLASS L_IDENTIFIER  */
#line 880 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                            { (yyval.number) = rule_atomic_type_class_identifier((yyvsp[0].string)); }
#line 3641 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 189: /* atomic_type: L_PROMISE  */
#line 884 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                           { (yyval.number) = rule_atomic_type_promise(); }
#line 3647 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 190: /* atomic_type: L_PROMISE '<' basic_type optional_star L_ORDER  */
#line 886 "$REPO_ROOT$/src/compiler/internal/grammar.y"
      { (yyval.number) = rule_atomic_type_promise_of((yyvsp[-2].number) | (yyvsp[-1].number), (yyvsp[0].number)); }
#line 3653 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 192: /* arg_type: basic_type ref  */
#line 892 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                    { (yyval.number) = (yyvsp[-1].number) | LOCAL_MOD_REF; }
#line 3659 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 193: /* cast: '(' basic_type optional_star ')'  */
#line 897 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                    { (yyval.number) = rule_cast((yyvsp[-2].number), (yyvsp[-1].number)); }
#line 3665 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 194: /* optional_star: %empty  */
#line 902 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { (yyval.number) = 0; }
#line 3671 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 195: /* optional_star: '*'  */
#line 903 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { (yyval.number) = TYPE_MOD_ARRAY; }
#line 3677 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 196: /* identifier: L_DEFINED_NAME  */
#line 913 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { (yyval.string) = rule_identifier_defined_name((yyvsp[0].ihe)); }
#line 3683 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 199: /* new_local_name: L_DEFINED_NAME  */
#line 920 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                    { (yyval.string) = rule_new_local_name_redefine((yyvsp[0].ihe)); }
#line 3689 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 200: /* efun_override: L_EFUN L_COLON_COLON identifier  */
#line 925 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { (yyval.number) = rule_efun_override((yyvsp[0].string)); }
#line 3695 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 201: /* efun_override: L_EFUN L_COLON_COLON L_NEW  */
#line 926 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { (yyval.number) = rule_efun_override_new(); }
#line 3701 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 203: /* function_name: L_COLON_COLON identifier  */
#line 937 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                           { (yyval.string) = rule_function_name_colon_colon((yyvsp[0].string)); }
#line 3707 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 204: /* function_name: L_BASIC_TYPE L_COLON_COLON identifier  */
#line 938 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                           { (yyval.string) = rule_function_name_type((yyvsp[-2].number), (yyvsp[0].string)); }
#line 3713 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 205: /* function_name: identifier L_COLON_COLON identifier  */
#line 939 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                    { (yyval.string) = rule_function_name_obj((yyvsp[-2].string), (yyvsp[0].string)); }
#line 3719 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 206: /* inheritance: type_modifier_list L_INHERIT string_const ';'  */
#line 945 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { if (rule_inheritence(&(yyval.node), (yyvsp[-3].number), (yyvsp[-1].string))) { YYACCEPT; } }
#line 3725 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 207: /* modifier_change: type_modifier_list ':'  */
#line 950 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                          { (yyval.node) = rule_modifier_change((yyvsp[-1].number)); }
#line 3731 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 208: /* argument: %empty  */
#line 961 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.argument).num_arg = 0; (yyval.argument).flags = 0; }
#line 3737 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 210: /* argument: argument_list L_DOT_DOT_DOT  */
#line 964 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_argument_varargs(&(yyval.argument), &(yyvsp[-1].argument)); }
#line 3743 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 211: /* argument_list: param_decl  */
#line 970 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_argument_list_single(&(yyval.argument), (yyvsp[0].number)); }
#line 3749 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 212: /* argument_list: argument_list ',' param_decl  */
#line 972 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_argument_list_multi(&(yyval.argument), &(yyvsp[-2].argument), (yyvsp[0].number)); }
#line 3755 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 213: /* param_decl: arg_type optional_star  */
#line 982 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.number) = rule_param_decl_typed((yyvsp[-1].number) | (yyvsp[0].number)); }
#line 3761 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 214: /* param_decl: arg_type optional_star new_local_name optional_default_arg_value  */
#line 984 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.number) = rule_param_decl_typed_name((yyvsp[-3].number) | (yyvsp[-2].number), (yyvsp[-1].string), (yyvsp[0].node)); }
#line 3767 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 215: /* param_decl: new_local_name  */
#line 986 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.number) = rule_param_decl_untyped_name((yyvsp[0].string)); }
#line 3773 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 216: /* optional_default_arg_value: %empty  */
#line 991 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                          { (yyval.node) = 0; }
#line 3779 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 217: /* optional_default_arg_value: ':' L_FUNCTION_OPEN comma_expr ':' ')'  */
#line 992 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                            { (yyval.node) = rule_default_arg_value((yyvsp[-2].node)); }
#line 3785 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 218: /* local_name_list: new_local_def  */
#line 998 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_local_name_list_single(&(yyval.decl), (yyvsp[0].node)); }
#line 3791 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 219: /* local_name_list: new_local_def ',' local_name_list  */
#line 1000 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_local_name_list_multi(&(yyval.decl), (yyvsp[-2].node), &(yyvsp[0].decl)); }
#line 3797 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 220: /* new_local_def: optional_star new_local_name  */
#line 1006 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.node) = rule_new_local_def((yyvsp[0].string), (yyvsp[-1].number)); }
#line 3803 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 221: /* new_local_def: optional_star new_local_name L_ASSIGN expr  */
#line 1008 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.node) = rule_new_local_def_with_init((yyvsp[-2].string), (yyvsp[-3].number), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3809 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 222: /* single_new_local_def: arg_type optional_star new_local_name  */
#line 1014 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_single_new_local_def(&(yyval.number), (yyvsp[-2].number) | (yyvsp[-1].number), (yyvsp[0].string)); }
#line 3815 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 223: /* single_new_local_def_with_init: single_new_local_def L_ASSIGN expr  */
#line 1020 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { (yyval.node) = rule_single_new_local_def_with_init((yyvsp[-2].number), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3821 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 226: /* new_name: optional_star identifier  */
#line 1036 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                         { rule_new_name((yyvsp[-1].number), (yyvsp[0].string)); }
#line 3827 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 227: /* new_name: optional_star identifier L_ASSIGN expr  */
#line 1037 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                           { rule_new_name_with_init((yyvsp[-3].number), (yyvsp[-2].string), (yyvsp[-1].number), (yyvsp[0].node)); }
#line 3833 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 228: /* lambda_return_type: L_BASIC_TYPE  */
#line 1048 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                { rule_lambda_return_type(&(yyval.func_block), (yyvsp[0].number)); }
#line 3839 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 229: /* functional_open: L_FUNCTION_OPEN efun_override  */
#line 1056 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                 { (yyval.number) = rule_functional_open((yyvsp[0].number)); }
#line 3845 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 230: /* assoc_pair: expr ':' expr  */
#line 1066 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_assoc_pair(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3851 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 231: /* spread_expr: expr  */
#line 1071 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                        { rule_spread_expr_normal(&(yyval.node), (yyvsp[0].node)); }
#line 3857 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 232: /* spread_expr: expr L_DOT_DOT_DOT  */
#line 1072 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                        { rule_spread_expr_dots(&(yyval.node), (yyvsp[-1].node)); }
#line 3863 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 233: /* arg_list: spread_expr  */
#line 1078 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_arg_list_single(&(yyval.node), (yyvsp[0].node)); }
#line 3869 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 234: /* arg_list: arg_list ',' spread_expr  */
#line 1080 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_arg_list_multi(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3875 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 235: /* opt_arg_list: %empty  */
#line 1086 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_opt_arg_list_empty(&(yyval.node)); }
#line 3881 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 236: /* opt_arg_list: arg_list  */
#line 1087 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_opt_arg_list(&(yyval.node), (yyvsp[0].node)); }
#line 3887 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 237: /* opt_arg_list: arg_list ','  */
#line 1088 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_opt_arg_list(&(yyval.node), (yyvsp[-1].node)); }
#line 3893 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 238: /* pair_list: assoc_pair  */
#line 1094 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_pair_list_single(&(yyval.node), (yyvsp[0].node)); }
#line 3899 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 239: /* pair_list: pair_list ',' assoc_pair  */
#line 1096 "$REPO_ROOT$/src/compiler/internal/grammar.y"
    { rule_pair_list_multi(&(yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 3905 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 240: /* opt_pair_list: %empty  */
#line 1102 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                   { rule_opt_pair_list_empty(&(yyval.node)); }
#line 3911 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 241: /* opt_pair_list: pair_list  */
#line 1103 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                   { rule_opt_pair_list(&(yyval.node), (yyvsp[0].node)); }
#line 3917 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 242: /* opt_pair_list: pair_list ','  */
#line 1104 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                   { rule_opt_pair_list(&(yyval.node), (yyvsp[-1].node)); }
#line 3923 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 243: /* lvalue_list: %empty  */
#line 1109 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                            { (yyval.node) = rule_lvalue_list_empty(); }
#line 3929 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 244: /* lvalue_list: ',' lvalue lvalue_list  */
#line 1110 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { (yyval.node) = rule_lvalue_list((yyvsp[-1].node), (yyvsp[0].node)); }
#line 3935 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 245: /* expr_or_block: block  */
#line 1115 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_expr_or_block_block((yyvsp[0].decl)); }
#line 3941 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 246: /* expr_or_block: '(' comma_expr ')'  */
#line 1116 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                         { (yyval.node) = rule_expr_or_block_expr((yyvsp[-1].node)); }
#line 3947 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 249: /* string: string_literal  */
#line 1132 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                  { rule_string(&(yyval.node), (yyvsp[0].string)); }
#line 3953 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 250: /* template_literal: L_TEMPLATE_HEAD expr template_parts  */
#line 1144 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { rule_template_literal(&(yyval.node), (yyvsp[-2].string), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3959 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 251: /* template_parts: L_TEMPLATE_TAIL  */
#line 1148 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                      { rule_template_parts_tail(&(yyval.node), (yyvsp[0].string)); }
#line 3965 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 252: /* template_parts: L_TEMPLATE_MIDDLE expr template_parts  */
#line 1149 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                       { rule_template_parts_middle(&(yyval.node), (yyvsp[-2].string), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3971 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 255: /* string_like: string_like string  */
#line 1160 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                               { rule_string_like_concat(&(yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3977 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 256: /* string_like: string_like template_literal  */
#line 1161 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { rule_string_like_concat(&(yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 3983 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 258: /* string_literal: string_literal L_STRING  */
#line 1169 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                   { (yyval.string) = rule_string_literal_concat((yyvsp[-1].string), (yyvsp[0].string)); }
#line 3989 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 260: /* string_const: '(' string_const ')'  */
#line 1176 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                        { (yyval.string) = (yyvsp[-1].string); }
#line 3995 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 261: /* string_const: string_const '+' string_const  */
#line 1177 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                                { (yyval.string) = rule_string_literal_concat((yyvsp[-2].string), (yyvsp[0].string)); }
#line 4001 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 262: /* number: L_NUMBER  */
#line 1181 "$REPO_ROOT$/src/compiler/internal/grammar.y"
            { rule_number(&(yyval.node), (yyvsp[0].number)); }
#line 4007 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 263: /* number: L_SCALAR_LITERAL  */
#line 1182 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                     {
      CREATE_OPCODE((yyval.node), (yyvsp[0].number) == 2 ? F_PUSH_NULL :
                        (yyvsp[0].number) ? F_PUSH_TRUE : F_PUSH_FALSE,
                        (yyvsp[0].number) == 2 ? TYPE_NULL : TYPE_BOOLEAN);
    }
#line 4017 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 264: /* real: L_REAL  */
#line 1190 "$REPO_ROOT$/src/compiler/internal/grammar.y"
          { rule_real(&(yyval.node), (yyvsp[0].real)); }
#line 4023 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 265: /* constant: constant '|' constant  */
#line 1196 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_constant_or(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4029 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 266: /* constant: constant '^' constant  */
#line 1197 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_constant_xor(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4035 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 267: /* constant: constant '&' constant  */
#line 1198 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                     { rule_constant_and(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4041 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 268: /* constant: constant L_EQ_NE constant  */
#line 1199 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                             { rule_constant_eq_ne(&(yyval.number), (yyvsp[-1].number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4047 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 269: /* constant: constant L_ORDER constant  */
#line 1200 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                         { rule_constant_order(&(yyval.number), (yyvsp[-2].number), (yyvsp[-1].number), (yyvsp[0].number)); }
#line 4053 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 270: /* constant: constant '<' constant  */
#line 1201 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_lt(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4059 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 271: /* constant: constant L_SHIFT constant  */
#line 1202 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                             { rule_constant_shift(&(yyval.number), (yyvsp[-1].number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4065 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 272: /* constant: constant '+' constant  */
#line 1203 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_add(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4071 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 273: /* constant: constant '-' constant  */
#line 1204 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_sub(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4077 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 274: /* constant: constant '*' constant  */
#line 1205 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_mul(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4083 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 275: /* constant: constant '%' constant  */
#line 1206 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_mod(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4089 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 276: /* constant: constant '/' constant  */
#line 1207 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                       { rule_constant_div(&(yyval.number), (yyvsp[-2].number), (yyvsp[0].number)); }
#line 4095 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 277: /* constant: '(' constant ')'  */
#line 1208 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                                  { (yyval.number) = (yyvsp[-1].number); }
#line 4101 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 278: /* constant: L_NUMBER  */
#line 1209 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { (yyval.number) = (yyvsp[0].number); }
#line 4107 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 279: /* constant: '-' L_NUMBER  */
#line 1210 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_constant_neg(&(yyval.number), (yyvsp[0].number)); }
#line 4113 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 280: /* constant: '!' L_NUMBER  */
#line 1211 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_constant_not(&(yyval.number), (yyvsp[0].number)); }
#line 4119 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;

  case 281: /* constant: '~' L_NUMBER  */
#line 1212 "$REPO_ROOT$/src/compiler/internal/grammar.y"
                             { rule_constant_compl(&(yyval.number), (yyvsp[0].number)); }
#line 4125 "$BUILD_ROOT$/src/grammar.autogen.cc"
    break;


#line 4129 "$BUILD_ROOT$/src/grammar.autogen.cc"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyps, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yyscanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, yyscanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, yyscanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, yyscanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, yyscanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, yyscanner);
      YYPOPSTACK (1);
    }
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yylsa
#undef yyls
#undef yylsp
#undef yystacksize
#undef yyesa
#undef yyes
#undef yyes_capacity
#line 1215 "$REPO_ROOT$/src/compiler/internal/grammar.y"


// Public accessor for the parser's symbol-name table: maps a raw yylex
// token number (what lpcc --tokens prints) to its grammar spelling
// ("L_IDENTIFIER", "'{'"). Lives in the epilogue because yysymbol_name()
// and YYTRANSLATE are file-static in the generated parser; consumed by
// the lpcc --json staged outputs (stage_output.cc).
const char* lpc_token_name(int token) {
  return yysymbol_name(YY_CAST(yysymbol_kind_t, YYTRANSLATE(token)));
}
/* FluffOS generated-from grammar.y sha256=e9fe2193bbf6328015bbcc384a05af9eee38c58e481e1c12db8da35ff3e7e050 */

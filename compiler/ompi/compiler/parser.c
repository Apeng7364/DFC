/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

/*
  OMPi OpenMP Compiler
  == Copyright since 2001 the OMPi Team
  == Dept. of Computer Science & Engineering, University of Ioannina

  This file is part of OMPi.

  OMPi is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  OMPi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OMPi; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* parser.y */

/*
 * 2010/11/10:
 *   dropped OpenMP-specific for parsing; fewer rules, less code
 * 2009/05/11:
 *   added AUTO schedule type
 * 2009/05/03:
 *   added ATNODE ompix clause
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdarg.h>
#include <ctype.h>
#include <assert.h>
#include "scanner.h"
#include "boolean.h"
#include "ompi.h"
#include "ast.h"
#include "symtab.h"
#include "ast_free.h"
#include "ast_copy.h"
#include "ast_vars.h"
#include "x_arith.h"

void    check_uknown_var(char *name);
void    parse_error(int exitvalue, char *format, ...);
void    parse_warning(char *format, ...);
void    yyerror(const char *s);
void    check_for_main_and_declare(astspec s, astdecl d);
void    add_declaration_links(astspec s, astdecl d);
astdecl fix_known_typename(astspec s);

/* DF-C */
struct dfc_insert_detail
{
  aststmt body;
  astdecl inParams;
  astdecl outParams;
  int in_params_count;
  int out_params_count;
  char *func_name;
};

int __has_dfc = 0;
void dfc_insert_active_data_decl_and_update_persize(struct dfc_insert_detail *detail);
void dfc_insert_get_active_data_call(struct dfc_insert_detail *detail);
void dfc_insert_get_item_index(struct dfc_insert_detail *detail,char* name);
void dfc_insert_update_active_data_call(struct dfc_insert_detail *detail);

void dfc_use_detail_to_fill_main_ad_and_fn_init(struct dfc_insert_detail *detail);
char* use_params_to_get_spec_name(astdecl params);

aststmt pastree = NULL;       /* The generated AST */
aststmt pastree_stmt = NULL;  /* For when parsing statment strings */
astexpr pastree_expr = NULL;  /* For when parsing expression strings */
int     checkDecls = 1;       /* 0 when scanning strings (no context check) */
int     tempsave;
int     isTypedef  = 0;       /* To keep track of typedefs */

char    *parsingstring;       /* For error reporting when parsing string */

int     __has_target = 0;
char*     use_for_df_count;

//TODO this is not 100% correct (e.g. if returns lies in a dead code area).
/* Return and goto statements that lead outside the outlined region constitute
 * programmer errors and so we should stop the compilation. When simply 
 * analyzing vars (and not outlining) we ignore this rule.
 */
int     errorOnReturn = 0;

#line 170 "parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START_SYMBOL_EXPRESSION = 258,
    START_SYMBOL_BLOCKLIST = 259,
    START_SYMBOL_TRANSUNIT = 260,
    IDENTIFIER = 261,
    TYPE_NAME = 262,
    CONSTANT = 263,
    STRING_LITERAL = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    AND_OP = 274,
    OR_OP = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    LEFT_ASSIGN = 281,
    RIGHT_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    SIZEOF = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    RESTRICT = 292,
    CHAR = 293,
    SHORT = 294,
    INT = 295,
    LONG = 296,
    SIGNED = 297,
    UNSIGNED = 298,
    FLOAT = 299,
    DOUBLE = 300,
    CONST = 301,
    VOLATILE = 302,
    VOID = 303,
    INLINE = 304,
    UBOOL = 305,
    UCOMPLEX = 306,
    UIMAGINARY = 307,
    STRUCT = 308,
    UNION = 309,
    ENUM = 310,
    ELLIPSIS = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    __BUILTIN_VA_ARG = 324,
    __BUILTIN_OFFSETOF = 325,
    __BUILTIN_TYPES_COMPATIBLE_P = 326,
    __ATTRIBUTE__ = 327,
    PRAGMA_OMP = 328,
    PRAGMA_OMP_THREADPRIVATE = 329,
    OMP_PARALLEL = 330,
    OMP_SECTIONS = 331,
    OMP_NOWAIT = 332,
    OMP_ORDERED = 333,
    OMP_SCHEDULE = 334,
    OMP_STATIC = 335,
    OMP_DYNAMIC = 336,
    OMP_GUIDED = 337,
    OMP_RUNTIME = 338,
    OMP_AUTO = 339,
    OMP_SECTION = 340,
    OMP_AFFINITY = 341,
    OMP_SINGLE = 342,
    OMP_MASTER = 343,
    OMP_CRITICAL = 344,
    OMP_BARRIER = 345,
    OMP_ATOMIC = 346,
    OMP_FLUSH = 347,
    OMP_PRIVATE = 348,
    OMP_FIRSTPRIVATE = 349,
    OMP_LASTPRIVATE = 350,
    OMP_SHARED = 351,
    OMP_DEFAULT = 352,
    OMP_NONE = 353,
    OMP_REDUCTION = 354,
    OMP_COPYIN = 355,
    OMP_NUMTHREADS = 356,
    OMP_COPYPRIVATE = 357,
    OMP_FOR = 358,
    OMP_IF = 359,
    OMP_TASK = 360,
    OMP_UNTIED = 361,
    OMP_TASKWAIT = 362,
    OMP_COLLAPSE = 363,
    OMP_FINAL = 364,
    OMP_MERGEABLE = 365,
    OMP_TASKYIELD = 366,
    OMP_READ = 367,
    OMP_WRITE = 368,
    OMP_CAPTURE = 369,
    OMP_UPDATE = 370,
    OMP_MIN = 371,
    OMP_MAX = 372,
    OMP_PROCBIND = 373,
    OMP_CLOSE = 374,
    OMP_SPREAD = 375,
    OMP_SIMD = 376,
    OMP_INBRANCH = 377,
    OMP_NOTINBRANCH = 378,
    OMP_UNIFORM = 379,
    OMP_LINEAR = 380,
    OMP_ALIGNED = 381,
    OMP_SIMDLEN = 382,
    OMP_SAFELEN = 383,
    OMP_DECLARE = 384,
    OMP_TARGET = 385,
    OMP_DATA = 386,
    OMP_DEVICE = 387,
    OMP_MAP = 388,
    OMP_ALLOC = 389,
    OMP_TO = 390,
    OMP_FROM = 391,
    OMP_TOFROM = 392,
    OMP_END = 393,
    OMP_TEAMS = 394,
    OMP_DISTRIBUTE = 395,
    OMP_NUMTEAMS = 396,
    OMP_THREADLIMIT = 397,
    OMP_DISTSCHEDULE = 398,
    OMP_DEPEND = 399,
    OMP_IN = 400,
    OMP_OUT = 401,
    OMP_INOUT = 402,
    OMP_TASKGROUP = 403,
    OMP_SEQ_CST = 404,
    OMP_CANCEL = 405,
    OMP_INITIALIZER = 406,
    PRAGMA_OMP_CANCELLATIONPOINT = 407,
    PRAGMA_OMPIX = 408,
    OMPIX_TASKDEF = 409,
    OMPIX_IN = 410,
    OMPIX_OUT = 411,
    OMPIX_INOUT = 412,
    OMPIX_TASKSYNC = 413,
    OMPIX_UPONRETURN = 414,
    OMPIX_ATNODE = 415,
    OMPIX_DETACHED = 416,
    OMPIX_ATWORKER = 417,
    OMPIX_TASKSCHEDULE = 418,
    OMPIX_STRIDE = 419,
    OMPIX_START = 420,
    OMPIX_SCOPE = 421,
    OMPIX_NODES = 422,
    OMPIX_WORKERS = 423,
    OMPIX_LOCAL = 424,
    OMPIX_GLOBAL = 425,
    OMPIX_TIED = 426
  };
#endif
/* Tokens.  */
#define START_SYMBOL_EXPRESSION 258
#define START_SYMBOL_BLOCKLIST 259
#define START_SYMBOL_TRANSUNIT 260
#define IDENTIFIER 261
#define TYPE_NAME 262
#define CONSTANT 263
#define STRING_LITERAL 264
#define PTR_OP 265
#define INC_OP 266
#define DEC_OP 267
#define LEFT_OP 268
#define RIGHT_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define AND_OP 274
#define OR_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define SIZEOF 286
#define TYPEDEF 287
#define EXTERN 288
#define STATIC 289
#define AUTO 290
#define REGISTER 291
#define RESTRICT 292
#define CHAR 293
#define SHORT 294
#define INT 295
#define LONG 296
#define SIGNED 297
#define UNSIGNED 298
#define FLOAT 299
#define DOUBLE 300
#define CONST 301
#define VOLATILE 302
#define VOID 303
#define INLINE 304
#define UBOOL 305
#define UCOMPLEX 306
#define UIMAGINARY 307
#define STRUCT 308
#define UNION 309
#define ENUM 310
#define ELLIPSIS 311
#define CASE 312
#define DEFAULT 313
#define IF 314
#define ELSE 315
#define SWITCH 316
#define WHILE 317
#define DO 318
#define FOR 319
#define GOTO 320
#define CONTINUE 321
#define BREAK 322
#define RETURN 323
#define __BUILTIN_VA_ARG 324
#define __BUILTIN_OFFSETOF 325
#define __BUILTIN_TYPES_COMPATIBLE_P 326
#define __ATTRIBUTE__ 327
#define PRAGMA_OMP 328
#define PRAGMA_OMP_THREADPRIVATE 329
#define OMP_PARALLEL 330
#define OMP_SECTIONS 331
#define OMP_NOWAIT 332
#define OMP_ORDERED 333
#define OMP_SCHEDULE 334
#define OMP_STATIC 335
#define OMP_DYNAMIC 336
#define OMP_GUIDED 337
#define OMP_RUNTIME 338
#define OMP_AUTO 339
#define OMP_SECTION 340
#define OMP_AFFINITY 341
#define OMP_SINGLE 342
#define OMP_MASTER 343
#define OMP_CRITICAL 344
#define OMP_BARRIER 345
#define OMP_ATOMIC 346
#define OMP_FLUSH 347
#define OMP_PRIVATE 348
#define OMP_FIRSTPRIVATE 349
#define OMP_LASTPRIVATE 350
#define OMP_SHARED 351
#define OMP_DEFAULT 352
#define OMP_NONE 353
#define OMP_REDUCTION 354
#define OMP_COPYIN 355
#define OMP_NUMTHREADS 356
#define OMP_COPYPRIVATE 357
#define OMP_FOR 358
#define OMP_IF 359
#define OMP_TASK 360
#define OMP_UNTIED 361
#define OMP_TASKWAIT 362
#define OMP_COLLAPSE 363
#define OMP_FINAL 364
#define OMP_MERGEABLE 365
#define OMP_TASKYIELD 366
#define OMP_READ 367
#define OMP_WRITE 368
#define OMP_CAPTURE 369
#define OMP_UPDATE 370
#define OMP_MIN 371
#define OMP_MAX 372
#define OMP_PROCBIND 373
#define OMP_CLOSE 374
#define OMP_SPREAD 375
#define OMP_SIMD 376
#define OMP_INBRANCH 377
#define OMP_NOTINBRANCH 378
#define OMP_UNIFORM 379
#define OMP_LINEAR 380
#define OMP_ALIGNED 381
#define OMP_SIMDLEN 382
#define OMP_SAFELEN 383
#define OMP_DECLARE 384
#define OMP_TARGET 385
#define OMP_DATA 386
#define OMP_DEVICE 387
#define OMP_MAP 388
#define OMP_ALLOC 389
#define OMP_TO 390
#define OMP_FROM 391
#define OMP_TOFROM 392
#define OMP_END 393
#define OMP_TEAMS 394
#define OMP_DISTRIBUTE 395
#define OMP_NUMTEAMS 396
#define OMP_THREADLIMIT 397
#define OMP_DISTSCHEDULE 398
#define OMP_DEPEND 399
#define OMP_IN 400
#define OMP_OUT 401
#define OMP_INOUT 402
#define OMP_TASKGROUP 403
#define OMP_SEQ_CST 404
#define OMP_CANCEL 405
#define OMP_INITIALIZER 406
#define PRAGMA_OMP_CANCELLATIONPOINT 407
#define PRAGMA_OMPIX 408
#define OMPIX_TASKDEF 409
#define OMPIX_IN 410
#define OMPIX_OUT 411
#define OMPIX_INOUT 412
#define OMPIX_TASKSYNC 413
#define OMPIX_UPONRETURN 414
#define OMPIX_ATNODE 415
#define OMPIX_DETACHED 416
#define OMPIX_ATWORKER 417
#define OMPIX_TASKSCHEDULE 418
#define OMPIX_STRIDE 419
#define OMPIX_START 420
#define OMPIX_SCOPE 421
#define OMPIX_NODES 422
#define OMPIX_WORKERS 423
#define OMPIX_LOCAL 424
#define OMPIX_GLOBAL 425
#define OMPIX_TIED 426

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 101 "parser.y"

  char      name[2048];  /* A general string */
  int       type;        /* A general integer */
  char     *string;      /* A dynamically allocated string (only for 2 rules) */
  symbol    symb;        /* A symbol */
  astexpr   expr;        /* An expression node in the AST */
  astspec   spec;        /* A declaration specifier node in the AST */
  astdecl   decl;        /* A declarator node in the AST */
  aststmt   stmt;        /* A statement node in the AST */
  ompcon    ocon;        /* An OpenMP construct */
  ompdir    odir;        /* An OpenMP directive */
  ompclause ocla;        /* An OpenMP clause */

  oxcon     xcon;        /* OMPi extensions */
  oxdir     xdir;
  oxclause  xcla;

#line 582 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  217
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  321
/* YYNRULES -- Number of rules.  */
#define YYNRULES  796
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1335

#define YYUNDEFTOK  2
#define YYMAXUTOK   426


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     196,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   185,     2,     2,     2,   187,   180,     2,
     172,   173,   181,   182,   179,   183,   176,   186,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   193,   195,
     188,   194,   189,   192,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   174,     2,   175,   190,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   177,   191,   178,   184,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   474,   474,   475,   476,   477,   494,   515,   519,   542,
     564,   568,   572,   580,   584,   594,   626,   644,   648,   652,
     656,   665,   669,   673,   677,   681,   685,   693,   697,   705,
     709,   713,   717,   724,   728,   737,   742,   747,   756,   760,
     764,   768,   772,   776,   784,   788,   796,   800,   804,   808,
     816,   820,   824,   832,   836,   840,   848,   852,   856,   860,
     864,   872,   876,   880,   888,   892,   900,   904,   912,   916,
     924,   928,   936,   940,   948,   952,   960,   964,   972,   976,
     980,   984,   988,   992,   996,  1000,  1004,  1008,  1012,  1020,
    1024,  1032,  1046,  1061,  1068,  1073,  1077,  1081,  1089,  1093,
    1097,  1101,  1105,  1109,  1113,  1117,  1125,  1129,  1143,  1160,
    1159,  1182,  1187,  1191,  1195,  1199,  1207,  1211,  1215,  1219,
    1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,  1255,  1259,
    1263,  1271,  1275,  1279,  1294,  1301,  1308,  1319,  1323,  1331,
    1335,  1343,  1347,  1355,  1359,  1363,  1367,  1375,  1379,  1387,
    1391,  1395,  1403,  1407,  1419,  1423,  1435,  1447,  1451,  1459,
    1463,  1471,  1475,  1479,  1487,  1495,  1499,  1512,  1516,  1524,
    1528,  1532,  1536,  1540,  1544,  1548,  1552,  1556,  1560,  1564,
    1568,  1573,  1578,  1583,  1588,  1596,  1600,  1604,  1608,  1616,
    1620,  1628,  1632,  1640,  1644,  1652,  1656,  1660,  1668,  1672,
    1680,  1684,  1692,  1696,  1700,  1708,  1712,  1716,  1720,  1724,
    1728,  1732,  1736,  1740,  1744,  1748,  1756,  1764,  1768,  1772,
    1780,  1784,  1788,  1792,  1800,  1808,  1812,  1820,  1824,  1828,
    1842,  1846,  1850,  1854,  1858,  1862,  1866,  1871,  1880,  1884,
    1894,  1898,  1902,  1910,  1914,  1914,  1925,  1929,  1938,  1942,
    1946,  1951,  1960,  1964,  1973,  1977,  1981,  1990,  1994,  1998,
    2002,  2006,  2010,  2014,  2018,  2022,  2026,  2030,  2034,  2038,
    2042,  2046,  2054,  2059,  2063,  2067,  2074,  2091,  2095,  2103,
    2107,  2114,  2126,  2127,  2132,  2131,  2177,  2176,  2199,  2198,
    2218,  2217,  2242,  2246,  2261,  2265,  2273,  2282,  2286,  2293,
    2297,  2301,  2305,  2309,  2313,  2317,  2321,  2325,  2329,  2334,
    2339,  2343,  2347,  2351,  2355,  2359,  2363,  2367,  2371,  2375,
    2379,  2383,  2387,  2391,  2395,  2399,  2403,  2407,  2411,  2415,
    2420,  2436,  2440,  2445,  2450,  2455,  2460,  2467,  2474,  2482,
    2490,  2493,  2497,  2504,  2508,  2512,  2516,  2520,  2524,  2531,
    2535,  2535,  2540,  2540,  2546,  2551,  2551,  2559,  2566,  2574,
    2577,  2581,  2588,  2592,  2596,  2600,  2604,  2608,  2615,  2619,
    2623,  2623,  2631,  2630,  2642,  2649,  2653,  2657,  2661,  2665,
    2669,  2674,  2681,  2689,  2692,  2696,  2703,  2707,  2711,  2715,
    2719,  2726,  2733,  2738,  2742,  2749,  2756,  2763,  2771,  2774,
    2778,  2785,  2789,  2793,  2797,  2804,  2804,  2813,  2821,  2829,
    2832,  2836,  2844,  2848,  2852,  2856,  2860,  2868,  2880,  2884,
    2892,  2896,  2904,  2904,  2913,  2913,  2922,  2922,  2931,  2934,
    2942,  2950,  2954,  2962,  2970,  2973,  2977,  2986,  2998,  3002,
    3006,  3010,  3018,  3026,  3034,  3037,  3041,  3048,  3052,  3060,
    3068,  3076,  3079,  3083,  3090,  3094,  3102,  3110,  3118,  3121,
    3125,  3132,  3136,  3140,  3148,  3148,  3157,  3157,  3162,  3162,
    3171,  3175,  3179,  3183,  3191,  3191,  3202,  3210,  3213,  3217,
    3224,  3228,  3235,  3239,  3247,  3255,  3262,  3266,  3270,  3277,
    3281,  3285,  3292,  3292,  3297,  3297,  3306,  3313,  3320,  3328,
    3336,  3344,  3347,  3351,  3358,  3362,  3366,  3370,  3374,  3378,
    3386,  3386,  3392,  3392,  3401,  3409,  3417,  3420,  3424,  3431,
    3435,  3439,  3443,  3450,  3454,  3454,  3463,  3472,  3480,  3483,
    3487,  3494,  3498,  3502,  3510,  3519,  3527,  3530,  3534,  3541,
    3545,  3553,  3562,  3570,  3573,  3577,  3584,  3588,  3596,  3604,
    3612,  3615,  3619,  3626,  3630,  3638,  3646,  3654,  3657,  3661,
    3668,  3672,  3676,  3684,  3692,  3700,  3703,  3707,  3714,  3718,
    3722,  3726,  3734,  3742,  3750,  3753,  3757,  3764,  3768,  3776,
    3784,  3793,  3796,  3801,  3809,  3813,  3821,  3830,  3839,  3842,
    3847,  3855,  3859,  3867,  3876,  3884,  3887,  3891,  3898,  3902,
    3910,  3919,  3927,  3930,  3934,  3941,  3945,  3953,  3962,  3970,
    3973,  3977,  3984,  3988,  3996,  4005,  4014,  4017,  4021,  4029,
    4033,  4037,  4041,  4045,  4053,  4057,  4057,  4062,  4066,  4071,
    4079,  4083,  4087,  4094,  4102,  4110,  4113,  4117,  4124,  4128,
    4132,  4136,  4140,  4144,  4148,  4152,  4159,  4167,  4175,  4178,
    4182,  4189,  4193,  4197,  4201,  4205,  4209,  4213,  4220,  4227,
    4234,  4241,  4245,  4252,  4259,  4267,  4275,  4283,  4291,  4298,
    4309,  4317,  4320,  4324,  4328,  4332,  4341,  4344,  4351,  4355,
    4362,  4362,  4370,  4377,  4385,  4389,  4393,  4400,  4404,  4408,
    4412,  4420,  4427,  4427,  4427,  4435,  4435,  4435,  4442,  4447,
    4451,  4455,  4459,  4463,  4467,  4471,  4475,  4479,  4483,  4490,
    4494,  4502,  4505,  4510,  4521,  4525,  4530,  4537,  4537,  4545,
    4545,  4553,  4553,  4561,  4561,  4569,  4569,  4577,  4577,  4585,
    4600,  4611,  4618,  4628,  4635,  4639,  4646,  4653,  4653,  4658,
    4658,  4666,  4670,  4678,  4682,  4686,  4698,  4716,  4742,  4746,
    4754,  4762,  4761,  4774,  4777,  4781,  4788,  4792,  4796,  4800,
    4804,  4811,  4815,  4819,  4823,  4830,  4834,  4843,  4842,  4859,
    4868,  4867,  4880,  4883,  4887,  4894,  4898,  4902,  4906,  4913,
    4917,  4924,  4929,  4937,  4945,  4953,  4961,  4964,  4968,  4975,
    4979,  4983,  4987,  4991,  4995,  5002,  5008
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START_SYMBOL_EXPRESSION",
  "START_SYMBOL_BLOCKLIST", "START_SYMBOL_TRANSUNIT", "IDENTIFIER",
  "TYPE_NAME", "CONSTANT", "STRING_LITERAL", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "SIZEOF", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "INLINE", "UBOOL",
  "UCOMPLEX", "UIMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "__BUILTIN_VA_ARG", "__BUILTIN_OFFSETOF",
  "__BUILTIN_TYPES_COMPATIBLE_P", "__ATTRIBUTE__", "PRAGMA_OMP",
  "PRAGMA_OMP_THREADPRIVATE", "OMP_PARALLEL", "OMP_SECTIONS", "OMP_NOWAIT",
  "OMP_ORDERED", "OMP_SCHEDULE", "OMP_STATIC", "OMP_DYNAMIC", "OMP_GUIDED",
  "OMP_RUNTIME", "OMP_AUTO", "OMP_SECTION", "OMP_AFFINITY", "OMP_SINGLE",
  "OMP_MASTER", "OMP_CRITICAL", "OMP_BARRIER", "OMP_ATOMIC", "OMP_FLUSH",
  "OMP_PRIVATE", "OMP_FIRSTPRIVATE", "OMP_LASTPRIVATE", "OMP_SHARED",
  "OMP_DEFAULT", "OMP_NONE", "OMP_REDUCTION", "OMP_COPYIN",
  "OMP_NUMTHREADS", "OMP_COPYPRIVATE", "OMP_FOR", "OMP_IF", "OMP_TASK",
  "OMP_UNTIED", "OMP_TASKWAIT", "OMP_COLLAPSE", "OMP_FINAL",
  "OMP_MERGEABLE", "OMP_TASKYIELD", "OMP_READ", "OMP_WRITE", "OMP_CAPTURE",
  "OMP_UPDATE", "OMP_MIN", "OMP_MAX", "OMP_PROCBIND", "OMP_CLOSE",
  "OMP_SPREAD", "OMP_SIMD", "OMP_INBRANCH", "OMP_NOTINBRANCH",
  "OMP_UNIFORM", "OMP_LINEAR", "OMP_ALIGNED", "OMP_SIMDLEN", "OMP_SAFELEN",
  "OMP_DECLARE", "OMP_TARGET", "OMP_DATA", "OMP_DEVICE", "OMP_MAP",
  "OMP_ALLOC", "OMP_TO", "OMP_FROM", "OMP_TOFROM", "OMP_END", "OMP_TEAMS",
  "OMP_DISTRIBUTE", "OMP_NUMTEAMS", "OMP_THREADLIMIT", "OMP_DISTSCHEDULE",
  "OMP_DEPEND", "OMP_IN", "OMP_OUT", "OMP_INOUT", "OMP_TASKGROUP",
  "OMP_SEQ_CST", "OMP_CANCEL", "OMP_INITIALIZER",
  "PRAGMA_OMP_CANCELLATIONPOINT", "PRAGMA_OMPIX", "OMPIX_TASKDEF",
  "OMPIX_IN", "OMPIX_OUT", "OMPIX_INOUT", "OMPIX_TASKSYNC",
  "OMPIX_UPONRETURN", "OMPIX_ATNODE", "OMPIX_DETACHED", "OMPIX_ATWORKER",
  "OMPIX_TASKSCHEDULE", "OMPIX_STRIDE", "OMPIX_START", "OMPIX_SCOPE",
  "OMPIX_NODES", "OMPIX_WORKERS", "OMPIX_LOCAL", "OMPIX_GLOBAL",
  "OMPIX_TIED", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'\\n'", "$accept",
  "start_trick", "enumeration_constant", "string_literal",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "$@1", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "typedef_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "statement_for_labeled", "labeled_statement",
  "compound_statement", "@2", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "iteration_statement_for", "jump_statement", "translation_unit",
  "external_declaration", "function_definition",
  "normal_function_definition", "$@3", "$@4",
  "oldstyle_function_definition", "$@5", "$@6", "declaration_list",
  "declaration_definition", "function_statement",
  "declarations_definitions_seq", "openmp_construct", "openmp_directive",
  "structured_block", "parallel_construct", "parallel_directive",
  "parallel_clause_optseq", "parallel_clause", "unique_parallel_clause",
  "$@7", "$@8", "$@9", "for_construct", "for_directive",
  "for_clause_optseq", "for_clause", "unique_for_clause", "$@10", "$@11",
  "schedule_kind", "sections_construct", "sections_directive",
  "sections_clause_optseq", "sections_clause", "section_scope",
  "section_sequence", "section_directive", "single_construct",
  "single_directive", "single_clause_optseq", "single_clause",
  "unique_single_clause", "$@12", "simd_construct", "simd_directive",
  "simd_clause_optseq", "simd_clause", "unique_simd_clause",
  "inbranch_clause", "uniform_clause", "$@13", "linear_clause", "$@14",
  "aligned_clause", "$@15", "optional_expression",
  "declare_simd_construct", "declare_simd_directive_seq",
  "declare_simd_directive", "declare_simd_clause_optseq",
  "declare_simd_clause", "for_simd_construct", "for_simd_directive",
  "for_simd_clause_optseq", "for_simd_clause",
  "parallel_for_simd_construct", "parallel_for_simd_directive",
  "parallel_for_simd_clause_optseq", "parallel_for_simd_clause",
  "target_data_construct", "target_data_directive",
  "target_data_clause_optseq", "target_data_clause", "device_clause",
  "$@16", "map_clause", "$@17", "$@18", "map_type", "target_construct",
  "@19", "target_directive", "target_clause_optseq", "target_clause",
  "unique_target_clause", "target_update_construct",
  "target_update_directive", "target_update_clause_seq",
  "target_update_clause", "motion_clause", "$@20", "$@21",
  "declare_target_construct", "declare_target_directive",
  "end_declare_target_directive", "teams_construct", "teams_directive",
  "teams_clause_optseq", "teams_clause", "unique_teams_clause", "$@22",
  "$@23", "distribute_construct", "distribute_directive",
  "distribute_clause_optseq", "distribute_clause",
  "unique_distribute_clause", "$@24", "distribute_simd_construct",
  "distribute_simd_directive", "distribute_simd_clause_optseq",
  "distribute_simd_clause", "distribute_parallel_for_construct",
  "distribute_parallel_for_directive",
  "distribute_parallel_for_clause_optseq",
  "distribute_parallel_for_clause",
  "distribute_parallel_for_simd_construct",
  "distribute_parallel_for_simd_directive",
  "distribute_parallel_for_simd_clause_optseq",
  "distribute_parallel_for_simd_clause", "target_teams_construct",
  "target_teams_directive", "target_teams_clause_optseq",
  "target_teams_clause", "teams_distribute_construct",
  "teams_distribute_directive", "teams_distribute_clause_optseq",
  "teams_distribute_clause", "teams_distribute_simd_construct",
  "teams_distribute_simd_directive", "teams_distribute_simd_clause_optseq",
  "teams_distribute_simd_clause", "target_teams_distribute_construct",
  "target_teams_distribute_directive",
  "target_teams_distribute_clause_optseq",
  "target_teams_distribute_clause",
  "target_teams_distribute_simd_construct",
  "target_teams_distribute_simd_directive",
  "target_teams_distribute_simd_clause_optseq",
  "target_teams_distribute_simd_clause",
  "teams_distribute_parallel_for_construct",
  "teams_distribute_parallel_for_directive",
  "teams_distribute_parallel_for_clause_optseq",
  "teams_distribute_parallel_for_clause",
  "target_teams_distribute_parallel_for_construct",
  "target_teams_distribute_parallel_for_directive",
  "target_teams_distribute_parallel_for_clause_optseq",
  "target_teams_distribute_parallel_for_clause",
  "teams_distribute_parallel_for_simd_construct",
  "teams_distribute_parallel_for_simd_directive",
  "teams_distribute_parallel_for_simd_clause_optseq",
  "teams_distribute_parallel_for_simd_clause",
  "target_teams_distribute_parallel_for_simd_construct",
  "target_teams_distribute_parallel_for_simd_directive",
  "target_teams_distribute_parallel_for_simd_clause_optseq",
  "target_teams_distribute_parallel_for_simd_clause", "task_construct",
  "task_directive", "task_clause_optseq", "task_clause",
  "unique_task_clause", "$@25", "dependence_type",
  "parallel_for_construct", "parallel_for_directive",
  "parallel_for_clause_optseq", "parallel_for_clause",
  "parallel_sections_construct", "parallel_sections_directive",
  "parallel_sections_clause_optseq", "parallel_sections_clause",
  "master_construct", "master_directive", "critical_construct",
  "critical_directive", "region_phrase", "barrier_directive",
  "taskwait_directive", "taskgroup_construct", "taskgroup_directive",
  "taskyield_directive", "atomic_construct", "atomic_directive",
  "atomic_clause_opt", "seq_cst_clause_opt", "flush_directive",
  "flush_vars", "$@26", "ordered_construct", "ordered_directive",
  "cancel_directive", "construct_type_clause",
  "cancellation_point_directive", "threadprivate_directive", "$@27",
  "$@28", "declare_reduction_directive", "$@29", "$@30",
  "reduction_identifier", "reduction_type_list", "initializer_clause_opt",
  "data_default_clause", "data_privatization_clause", "$@31",
  "data_privatization_in_clause", "$@32", "data_privatization_out_clause",
  "$@33", "data_sharing_clause", "$@34", "data_reduction_clause", "$@35",
  "if_clause", "$@36", "collapse_clause", "array_section", "variable_list",
  "variable_array_section_list", "array_section_subscript", "$@37", "$@38",
  "array_section_plain", "procbind_clause", "thrprv_variable_list",
  "ompix_directive", "ox_tasksync_directive", "ox_taskschedule_directive",
  "$@39", "ox_taskschedule_clause_optseq", "ox_taskschedule_clause",
  "ox_scope_spec", "ompix_construct", "ox_taskdef_construct", "$@40",
  "ox_taskdef_directive", "$@41", "ox_taskdef_clause_optseq",
  "ox_taskdef_clause", "ox_variable_size_list", "ox_variable_size_elem",
  "ox_task_construct", "ox_task_directive", "ox_task_clause_optseq",
  "ox_task_clause", "ox_funccall_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    40,    41,    91,    93,    46,   123,   125,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,    10
};
# endif

#define YYPACT_NINF (-1104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-768)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2759,  2539,  1423,  2828, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,   107,
     -52, -1104,   -55,    33,   139,   102, -1104,   100,  4503,  4503,
   -1104,   103, -1104,  4503,  4503,   -17,    22,   122, -1104,  2828,
   -1104, -1104, -1104, -1104, -1104,  3128, -1104, -1104,  2909, -1104,
   -1104, -1104,  3209,   -50, -1104, -1104,  2605,  2605,  2658,    23,
     114,   157,  1979, -1104, -1104, -1104, -1104, -1104, -1104,   323,
   -1104,   357,   810,  2539, -1104,   294,   -20,   637,   163,   796,
     195,   288,   283,   524,    24, -1104, -1104,   336,   149,  2539,
     377,   400,   437,   441,  1493,   449,   619,   435,   452,  1117,
    3906,   396,   284,   476, -1104,   -90, -1104,   100, -1104, -1104,
   -1104,  1423, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  1493, -1104,   602, -1104,   505, -1104,  1493, -1104,   602,
   -1104,   602, -1104,   602, -1104,  1493, -1104, -1104, -1104, -1104,
   -1104,  1493, -1104,   602, -1104,   602, -1104,   602, -1104,  1493,
   -1104,  1493, -1104,   602, -1104,   602, -1104,   602, -1104,   602,
   -1104,   602, -1104,   602, -1104,   602, -1104,   602, -1104,  1493,
   -1104,   602, -1104,   505, -1104,  1493, -1104,  1493, -1104, -1104,
   -1104,  1493, -1104, -1104,  1154, -1104, -1104,  1493, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104,   680,  2828,   514,   706,
     261,   533, -1104,   560, -1104, -1104,   139, -1104, -1104,   179,
   -1104,   592, -1104, -1104,   558,  2882,   568, -1104, -1104,   573,
    4117,  1683,  1889,    22, -1104,   662,    33, -1104, -1104, -1104,
   -1104, -1104, -1104,  2978,    33, -1104,   616,  1511,  1979, -1104,
   -1104,  1979, -1104,  2539,  4476,  4476,    20,  4476,    17,  4476,
     629, -1104,   671, -1104, -1104,  2146,  2539,   850, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  2539,
   -1104, -1104,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  1493, -1104,   655,  1110,  2539,  2539,  2539,  3998,
     -19,   742,  1590,   658, -1104, -1104, -1104,   199,    51, -1104,
     664, -1104,   669,   -72,   674,   994,   -43,   770, -1104,   709,
     712, -1104,   298,   773,    16,   729,   396, -1104, -1104, -1104,
   -1104,   738, -1104,   746, -1104, -1104,  1423, -1104,   727, -1104,
   -1104, -1104, -1104,  1641, -1104, -1104, -1104, -1104, -1104, -1104,
    1493, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,   778,   750,   706, -1104,   771,   699, -1104,
     811, -1104,   795,  1006, -1104, -1104, -1104, -1104,    33, -1104,
   -1104,   573,  4117,  4476, -1104,  3032, -1104,   132,  4476, -1104,
   -1104,  3375, -1104, -1104,  3446,   165,   854,   205, -1104,   130,
    2098, -1104,   825,   848,  2029,   910,   864,   410, -1104, -1104,
   -1104,   573, -1104,   253, -1104,   888,   890,   887,   899,   906,
   -1104, -1104,  3278,  2164,   444, -1104,   601, -1104,  2194, -1104,
   -1104, -1104,   338,   232, -1104, -1104, -1104, -1104, -1104, -1104,
     294,   294,   -20,   -20,   637,   637,   637,   637,   163,   163,
     796,   195,   288,   283,   524,   147, -1104, -1104,  1110,  3972,
   -1104, -1104, -1104,   368,   373,   424,   916,  1733,   209,  1770,
   -1104, -1104, -1104,   974,  1659,   277, -1104,   328, -1104,  1104,
   -1104,   924, -1104, -1104, -1104, -1104, -1104,   975, -1104, -1104,
     940, -1104,  1003,   961, -1104, -1104,   600,   213, -1104,   999,
     -29,    21,   893,  1043, -1104,   707, -1104,   -22, -1104,   237,
   -1104, -1104,  1354,  3993, -1104,    -6,  1493, -1104,  2263, -1104,
     759,  2539, -1104,    59,   779,   684, -1104, -1104,   461,   500,
   -1104,  2329, -1104,  3375,  3228, -1104, -1104,  2539, -1104,   214,
   -1104,   958,  3297, -1104, -1104, -1104,   464,  3059, -1104,   117,
   -1104, -1104,  4453,  3470, -1104,  1147,  1009,  2098, -1104, -1104,
    2539, -1104,  1014,  1015,  1065, -1104, -1104,  2539,  1019,  1019,
    4476,  1195,  4476, -1104,  1029,  1027,  1046, -1104,  1045,  1051,
     601,  3521,  2350,  2115, -1104, -1104, -1104,  2539, -1104,  1493,
    1493,  1493,  2539,  2380,   256,  1799,  2395,   337,   788, -1104,
    2652, -1104, -1104, -1104, -1104,  1049,  1055, -1104,  1059,  1061,
    1066,  2561, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,   492, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,   412, -1104, -1104, -1104, -1104, -1104,  1067,
   -1104, -1104,  1047,  1241, -1104,  1151, -1104, -1104,  1076,  1077,
     660, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
    1088, -1104,  1089,  1174, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1093,  1419, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104,  1097, -1104, -1104, -1104,   469,
   -1104, -1104, -1104,   496,    26,   361,  1101,   423, -1104, -1104,
   -1104, -1104, -1104, -1104,  1171, -1104,  1062,  1103,  1109,  1226,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  1164,  1778,
    1116,   502, -1104, -1104, -1104, -1104, -1104, -1104,  1192, -1104,
    1112, -1104,  1139, -1104,  1141, -1104,   603, -1104, -1104,   355,
   -1104,  1119,  1232, -1104,  1493, -1104, -1104,   488, -1104,    79,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1128, -1104, -1104, -1104,  1152,  1008,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104,  1321,  1156,  1157,
    1159,  1160,   -11, -1104, -1104,  2115, -1104, -1104, -1104, -1104,
   -1104,   142, -1104,  2539, -1104, -1104,  4503, -1104, -1104, -1104,
     489, -1104, -1104,  1158,  1165, -1104, -1104,  1211, -1104,  1172,
    1175,  1177, -1104, -1104, -1104, -1104, -1104,  1180, -1104,  1169,
    1184,  2539,   946, -1104,   797,  2329,   274, -1104, -1104,  1304,
   -1104, -1104,   497,  1493,   501,  2421,  2447,   398,  1493,   508,
    2468,  1696, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  3275,  1749, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,  1198,  1199,  1200,  1201,   347,   779,  1202,
   -1104, -1104,    -5, -1104,  1203, -1104,  1204, -1104, -1104, -1104,
   -1104,   542,  3878, -1104, -1104, -1104, -1104,   761,  2539, -1104,
   -1104,   945, -1104,  1205,  1206,  2539, -1104, -1104,  1207,  1208,
     213, -1104, -1104,   423, -1104, -1104, -1104, -1104, -1104,  1278,
   -1104,  3846,  1210, -1104, -1104, -1104, -1104,  1221, -1104,  1262,
    3806,  1766, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104,  3767,   823, -1104, -1104, -1104, -1104, -1104,  1330, -1104,
    1218, -1104,  2672,  2539, -1104, -1104,  1254,  1261,  1264, -1104,
     536, -1104, -1104, -1104, -1104, -1104, -1104,  4525,  1265,  2539,
   -1104,  1242, -1104,   779,  1433,  1433,  1433, -1104,   817, -1104,
   -1104, -1104, -1104, -1104,  1244, -1104, -1104, -1104, -1104, -1104,
   -1104,  1266, -1104, -1104, -1104,  2046, -1104, -1104, -1104,  1493,
    1247, -1104,  1493,  1493,   543,  1493,   561,  2515, -1104,  1493,
    1493,   570, -1104,  4300, -1104, -1104, -1104, -1104, -1104,  1241,
    1241,  1241,  1241,  1270,  1271,  1272, -1104,  1241,  2539,  2539,
    1273,  1274,  1275,  1241,  1241, -1104,  1443, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1300,   610,   611,  2539, -1104, -1104,
   -1104,  1257,  1241,  1241,   648,  2539,  1445,  1445, -1104, -1104,
    1331,  3787,  4339, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104,  1445,  1260, -1104,  3713,  4316, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  2539,  2539,  3662,  4273, -1104, -1104,
   -1104, -1104, -1104,   649, -1104,  1310,  1322,  1325,  2539,  2539,
     885, -1104, -1104,   260,  1241,   650, -1104,  1307,  1329,   673,
   -1104,   688,   695, -1104,  2072, -1104, -1104, -1104, -1104,  2329,
   -1104, -1104, -1104, -1104,  1493, -1104,  1493,  1493,   696, -1104,
   -1104,  1493, -1104,   700,   720,   721,   725, -1104, -1104, -1104,
    1315,   736,   753,   757, -1104, -1104, -1104,   762,   784, -1104,
   -1104, -1104, -1104, -1104,   785,  1445,   388,   388, -1104,   798,
    1335, -1104,   801,   806, -1104,  3606,  3095, -1104, -1104, -1104,
   -1104, -1104,   815, -1104,  3555,  1114, -1104, -1104, -1104, -1104,
   -1104,   826,   830,  4237, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1337,  1338, -1104,  1334,  1342,  4525,
   -1104,   840, -1104,  1433,  1823, -1104,  1433, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  1493, -1104, -1104, -1104, -1104, -1104,
    1241, -1104, -1104, -1104, -1104, -1104,  2539,  2539, -1104,   841,
    2539,  1343,  1348, -1104, -1104,  1351, -1104,  1522, -1104,  3499,
    4186, -1104, -1104, -1104, -1104, -1104, -1104,  1445,  4150, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104,  2539, -1104, -1104,
     930, -1104, -1104,  2539, -1104,   842,  1523,  1355, -1104, -1104,
     857,   866,   869, -1104,   336, -1104, -1104,  2539, -1104,  1335,
   -1104,  4099, -1104, -1104, -1104, -1104, -1104,   871, -1104,   889,
   -1104, -1104,   900, -1104,  1358, -1104, -1104, -1104, -1104,   397,
    1365,  2539, -1104, -1104, -1104, -1104, -1104,  2539, -1104,  1366,
    1392,   336, -1104,  1374,  1352,  1547, -1104,   183,  2539,  2539,
     904,  1394,  1395, -1104, -1104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,   167,   216,   111,   112,   113,   114,
     115,   162,   117,   118,   119,   120,   123,   124,   121,   122,
     161,   163,   116,   164,   125,   126,   127,   137,   138,     0,
       0,   692,     0,     0,   185,     0,   280,     0,    98,   100,
     128,     0,   129,   102,   104,   290,   165,     0,   130,     2,
     277,   279,   282,   283,    95,     0,   431,    96,     0,    94,
      97,   281,     0,     9,    10,     7,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    11,
      13,    29,    44,     0,    46,    50,    53,    56,    61,    64,
      66,    68,    70,    72,    74,    76,    89,     3,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   252,     0,   248,     0,   249,   230,
     231,     4,   246,   232,   233,   234,   259,   235,   236,   250,
     299,     0,   300,     0,   301,     0,   302,     0,   310,     0,
     311,     0,   312,     0,   313,     0,   314,   474,   315,   484,
     316,     0,   317,     0,   318,     0,   319,     0,   320,     0,
     321,     0,   322,     0,   323,     0,   324,     0,   325,     0,
     326,     0,   327,     0,   328,     0,   329,     0,   309,     0,
     303,     0,   304,     0,   305,     0,   306,     0,   331,   333,
     330,     0,   334,   307,     0,   332,   308,     0,   335,   336,
     251,   748,   749,   237,   765,   766,     0,     5,   156,     0,
       0,     0,   770,     0,   189,   187,   186,     1,    92,     0,
     106,   288,    99,   101,   135,     0,   136,   103,   105,     0,
       0,     0,     0,   166,   278,     0,     0,   296,   430,   432,
     295,   294,   297,     0,     0,   286,   769,     0,     0,    30,
      31,     0,    33,     0,     0,     0,     0,   143,   200,   145,
       0,     8,     0,    23,    24,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    78,     0,
      44,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,   275,     0,   340,   383,
       0,   398,     0,     0,     0,   671,     0,   359,   616,     0,
       0,   409,   477,   501,   516,     0,     0,   687,   688,   689,
     690,     0,   786,     0,   751,   243,     0,   253,   108,   247,
     337,   338,   357,     0,   381,   396,   407,   442,   449,   456,
       0,   499,   514,   526,   534,   541,   548,   555,   563,   572,
     579,   586,   593,   600,   607,   614,   633,   646,   658,   660,
     666,   669,   682,     0,     0,     0,     6,   159,     0,   157,
       0,   434,     0,     0,   772,   168,   190,   188,     0,    93,
     109,     0,     0,     0,   132,     0,   139,     0,     0,   287,
     292,     0,   198,   179,     0,   196,     0,   191,   193,     0,
       0,   169,    39,     0,     0,     0,   288,     0,   298,   496,
     284,     0,    15,     0,    27,     0,     0,     0,     0,     0,
      12,   144,     0,     0,   202,   201,   203,   146,     0,    20,
      22,    17,     0,     0,    19,    21,    77,    47,    48,    49,
      51,    52,    54,    55,    59,    60,    57,    58,    62,    63,
      65,    67,    69,    71,    73,     0,    90,   240,     0,     0,
     238,   242,   239,     0,     0,     0,     0,     0,     0,     0,
     272,   276,   648,   635,     0,     0,   683,     0,   659,     0,
     661,     0,   664,   672,   673,   675,   674,   676,   680,   678,
       0,   444,     0,     0,   665,   668,     0,     0,   458,   550,
       0,   557,     0,     0,   528,     0,   667,     0,   691,     0,
     750,   753,     0,     0,   392,     0,     0,   475,     0,   784,
       0,     0,   152,     0,     0,     0,   497,   746,     0,     0,
     107,     0,   285,     0,     0,   131,   140,     0,   142,     0,
     147,   149,     0,   293,   291,   184,     0,     0,   195,   202,
     197,   178,     0,     0,   180,     0,     0,     0,   176,   171,
       0,   170,    39,     0,     0,   768,    16,     0,     0,    34,
       0,     0,     0,   212,     0,   191,     0,   206,    39,     0,
     204,     0,     0,     0,    45,    18,    14,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   451,
       0,   355,   717,   719,   723,     0,     0,   352,     0,     0,
       0,     0,   339,   341,   343,   344,   345,   346,   347,   348,
     349,   354,   390,   721,     0,   382,   384,   386,   387,   388,
     389,   404,   405,     0,   397,   399,   401,   402,   403,     0,
     662,   677,     0,     0,   679,     0,   367,   368,     0,     0,
       0,   358,   360,   362,   363,   364,   365,   366,   374,   627,
       0,   628,     0,     0,   615,   617,   619,   620,   621,   622,
     623,   624,   424,   426,     0,     0,   408,   410,   412,   418,
     419,   413,   414,   415,   416,     0,   492,   494,   490,     0,
     486,   489,   491,     0,   574,     0,     0,     0,   476,   482,
     483,   478,   480,   481,     0,   565,     0,     0,     0,     0,
     500,   502,   504,   505,   506,   507,   508,   509,   536,     0,
       0,     0,   515,   517,   522,   519,   520,   521,     0,   684,
       0,   793,     0,   794,     0,   792,     0,   785,   787,     0,
     245,     0,     0,   391,     0,   393,   795,     0,   153,     0,
     160,   154,   158,   698,   705,   706,   707,   708,   702,   700,
     699,   701,   703,   704,     0,   420,   421,   422,     0,     0,
     433,   441,   440,   438,   439,   435,   693,     0,     0,     0,
       0,     0,     0,   771,   773,     0,   217,   110,   289,   133,
     151,     0,   141,     0,   134,   182,     0,   192,   194,   183,
       0,   199,   173,     0,     0,   177,   172,     0,    28,     0,
       0,     0,   214,   205,   210,   208,   213,     0,   207,    39,
       0,     0,     0,   220,     0,     0,     0,   225,    75,   254,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,   651,   649,   652,   653,   654,   655,   656,
     657,     0,     0,   634,   638,   639,   636,   640,   641,   642,
     643,   644,   645,     0,     0,     0,     0,     0,     0,     0,
     350,   727,     0,   342,     0,   385,     0,   400,   663,   670,
     731,     0,     0,   443,   447,   448,   445,     0,     0,   361,
     625,     0,   618,     0,     0,     0,   411,   464,     0,     0,
       0,   485,   487,     0,   457,   459,   461,   462,   463,     0,
     581,     0,     0,   549,   553,   554,   551,   468,   479,   588,
       0,     0,   556,   560,   561,   558,   562,   510,   512,   503,
     543,     0,     0,   527,   533,   531,   529,   532,     0,   518,
       0,   685,     0,     0,   788,   760,     0,     0,     0,   759,
       0,   752,   754,   395,   394,   796,   155,     0,     0,     0,
     436,     0,   747,     0,     0,     0,     0,   774,     0,   148,
     150,   181,   174,   175,     0,    35,    36,    37,   215,   211,
     209,     0,   228,   229,    25,     0,   221,   224,   226,     0,
       0,   260,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   650,     0,   450,   455,   452,   454,   637,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,     0,   681,     0,   446,   380,   375,
     376,   377,   378,   379,     0,     0,     0,     0,   630,   631,
     632,     0,     0,     0,     0,     0,     0,     0,   488,   460,
     595,     0,     0,   573,   577,   578,   575,   552,   470,   471,
     472,   473,     0,     0,   602,     0,     0,   564,   568,   571,
     566,   569,   570,   559,     0,     0,     0,     0,   535,   539,
     537,   540,   530,     0,   686,    39,     0,     0,     0,     0,
       0,   755,   709,     0,     0,     0,   694,     0,   781,     0,
     779,     0,     0,   218,     0,   498,   227,    26,   222,     0,
     255,   258,   263,   262,     0,   261,     0,     0,     0,   270,
     269,     0,   453,     0,     0,     0,     0,   716,   714,   715,
       0,     0,     0,     0,   743,   744,   745,     0,     0,   732,
     372,   369,   370,   729,     0,     0,   428,   428,   417,     0,
     733,   734,     0,     0,   609,     0,     0,   580,   584,   585,
     582,   576,     0,   466,     0,     0,   587,   591,   592,   589,
     567,     0,     0,     0,   542,   547,   546,   544,   538,   523,
     524,   789,   790,   791,     0,     0,   761,   762,     0,     0,
     695,     0,   437,     0,     0,   775,     0,   776,   777,   219,
     223,   266,   265,   264,     0,   271,   356,   718,   720,   724,
       0,   353,   351,   728,   722,   406,     0,     0,   626,     0,
       0,     0,     0,   465,   739,   730,   493,     0,   495,     0,
       0,   594,   598,   599,   596,   583,   469,     0,     0,   601,
     605,   606,   603,   590,   511,   513,   545,     0,   756,   757,
       0,   758,   710,     0,   423,     0,     0,     0,   780,   267,
       0,     0,     0,   629,   429,   425,   427,     0,   737,   735,
     736,     0,   608,   612,   613,   610,   597,     0,   604,     0,
     764,   763,     0,   778,     0,   783,   726,   373,   371,   742,
       0,     0,   611,   467,   525,   696,   782,     0,   740,     0,
     711,   741,   738,     0,     0,     0,   697,     0,     0,     0,
       0,     0,     0,   712,   713
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1104, -1104, -1104, -1104, -1104, -1104,  -259,   -65, -1104,   -14,
     818,   827,   962,   851,  1276,  1269,  1277,  1279,  1280, -1104,
     -95,  -185, -1104,    -1,  -511,   401,    35, -1104,  1185, -1104,
   -1104,   -67, -1104, -1104,   -18,  -262,  -118, -1104,   758, -1104,
    1187,  -521,   792, -1104,     8,   -39,    25,  -211,  -221,  -217,
    -543, -1104,  -228,  -202,  -386,   -24,  -535,   765,  -944, -1104,
     732,    13,  1095, -1104,  -134, -1104,  1238,  -112,  1391, -1104,
   -1104,  4448, -1104,  1583,     1,     2,  1525, -1104, -1104, -1104,
   -1104, -1104,  1186,  1346, -1104, -1104, -1104,  -263,   137, -1104,
   -1104, -1104,   959,  -482, -1104, -1104, -1104, -1104, -1104, -1104,
    -464,  -501, -1104, -1104, -1104, -1104, -1104, -1104,   947,  1409,
   -1104,  1058, -1104, -1104, -1104,   941, -1104, -1104, -1104, -1104,
   -1104,  -483,  -461, -1104, -1104, -1104,  -514, -1104,  -513, -1104,
     442, -1104, -1104,  1555, -1104,   822, -1104, -1104, -1104,   710,
   -1104, -1104, -1104,  -760, -1104, -1104, -1104,   690,  -454, -1104,
    -662, -1104, -1104, -1104, -1104, -1104, -1104, -1104,  -507,  -863,
   -1104, -1104, -1104,  -666, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104,  -469,  -174, -1104, -1104, -1104, -1104, -1104,
     873,  -433, -1104, -1104, -1104, -1104,  -699, -1104, -1104, -1104,
    -897, -1104, -1104, -1104, -1020, -1104, -1104, -1104,   683, -1104,
   -1104, -1104,  -701, -1104, -1104, -1104,  -885, -1104, -1104, -1104,
     544, -1104, -1104, -1104,   443, -1104, -1104, -1104, -1019, -1104,
   -1104, -1104,   367, -1104, -1104, -1104, -1103, -1104, -1104, -1104,
     329, -1104, -1104, -1104,   965, -1104, -1104, -1104, -1104, -1104,
   -1104,  -601, -1104, -1104, -1104,   790, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104, -1104,  1318, -1104, -1104, -1104,
   -1104, -1104, -1104, -1104,  -824, -1104, -1104,  -382,   -12, -1104,
      41, -1104,  -488, -1104,    15, -1104,    66, -1104,  -352, -1104,
    -314,   408,  -911,  -995, -1104, -1104, -1104,   345, -1104, -1104,
   -1104, -1104, -1104, -1104, -1104,   687, -1104, -1104,    49, -1104,
   -1104, -1104, -1104,   856,  -949,   446, -1104, -1104, -1104,   911,
   -1104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,   387,    79,    80,    81,   433,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   279,   115,   304,    36,   117,   219,   220,   551,
      38,    39,    40,    41,   405,   406,   258,   559,   560,    42,
     388,   389,    43,    44,    45,    46,    47,   216,   594,   595,
     418,   419,   260,   596,   446,    48,   843,   844,   845,   846,
     847,   350,   481,   119,   120,   346,   121,   122,   123,   124,
     125,   126,   127,    49,    50,    51,    52,   401,   229,    53,
     402,   230,   411,   242,   238,   243,   128,   129,   351,   130,
     131,   494,   633,   874,  1038,   889,   883,   132,   133,   512,
     904,   875,  1237,  1236,  1055,   134,   135,   495,   646,   354,
     535,   536,   136,   137,   497,   655,   656,   896,   138,   139,
     516,   954,   698,   791,   792,   978,   699,   913,   700,   914,
    1241,    54,    55,    56,   545,   795,   140,   141,   665,   906,
     142,   143,   871,  1195,   144,   145,   713,   925,   719,  1065,
     720,  1257,  1082,  1083,   146,   360,   147,   520,   934,   722,
     148,   149,   709,   710,   711,   918,   919,    57,    58,   429,
     150,   151,   522,   943,   732,  1094,  1095,   152,   153,   525,
     743,   955,  1267,   154,   155,   739,  1089,   156,   157,   951,
    1188,   158,   159,  1096,  1261,   160,   161,   715,   936,   162,
     163,   726,  1075,   164,   165,   940,  1179,   166,   167,   931,
    1076,   168,   169,  1071,  1180,   170,   171,  1085,  1253,   172,
     173,  1175,  1254,   174,   175,  1184,  1294,   176,   177,  1249,
    1295,   178,   179,   513,   685,   686,  1057,  1061,   180,   181,
     620,  1027,   182,   183,   618,   864,   184,   185,   186,   187,
     501,   188,   189,   190,   191,   192,   193,   194,   507,   662,
     195,   510,   663,   196,   197,   198,   341,   199,    59,   211,
     981,    60,  1273,  1320,   784,  1113,  1324,   877,   878,   884,
     879,   885,   880,   894,   881,   886,   882,  1150,   640,  1039,
     678,  1171,   901,  1172,  1245,  1311,  1287,  1310,   641,   548,
     200,   201,   202,   531,   759,   972,  1208,   203,   204,   431,
      62,   394,   549,   804,  1119,  1120,   205,   206,   529,   758,
     384
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   249,   250,   252,   303,   257,   452,   649,   233,   349,
     416,   673,   634,   721,   417,   118,   807,   226,   280,   876,
     435,   424,   772,   436,   676,   945,   438,   439,   702,   818,
     770,   793,   794,   697,   280,    37,  1121,  1122,    37,     4,
     956,   213,   482,   922,   299,   221,   810,   423,   672,    61,
     234,   927,    61,   731,  1100,  1090,   445,   237,   600,   215,
     241,  1129,   434,   708,  1036,   386,  1189,   762,   437,   281,
     245,   256,  1173,   222,   223,   629,  1197,   210,   227,   228,
     434,  1262,   629,  1040,    37,   386,   342,  1182,   798,   301,
     236,   523,   744,    37,   456,   409,   724,   244,    61,   212,
     499,   929,   217,   705,   716,   347,     4,   407,   317,   224,
       5,  1026,   635,   208,  1041,  1042,   476,   311,  1143,  1144,
    1145,  1146,   247,     4,   500,   348,  1151,   492,     4,   508,
     868,   687,  1157,  1158,   118,   212,   863,   524,     4,   441,
     733,   447,   725,   556,   799,   800,   801,   930,     4,   634,
     717,  1166,  1167,   509,   493,  1298,   649,   748,   257,  1117,
    -286,   691,   285,   286,   673,   712,  1263,   718,   723,   673,
    1239,     4,   763,  1266,   749,   750,    11,   676,   289,   290,
    1129,   257,   676,   600,   257,    20,    21,   257,   257,   442,
     257,   443,   257,   440,   231,   253,   232,   566,    34,   301,
    1198,  1190,   704,  1211,   905,    33,   909,   702,   234,   577,
     938,   747,   916,   570,    34,   482,   300,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   576,   865,   771,   450,   583,
    1093,   397,    37,   455,   426,   241,   935,   256,   772,   635,
     256,   702,   430,  1102,  1068,   708,    61,   976,   599,   926,
     949,   927,  1297,  1142,  1275,   453,   415,   552,   457,   458,
     459,  1028,    33,   818,   355,   793,   794,   564,    37,   767,
     225,    34,   359,   444,   209,   407,   254,   407,   361,   567,
     407,   443,   556,   944,    33,   218,   365,   585,   366,   475,
     556,   687,   990,   574,    33,   483,   484,   485,   744,   575,
    1006,   488,  1252,    34,    33,   477,   375,   629,   480,  1280,
      34,   247,   378,    34,   379,   557,   301,   558,   380,   255,
    1001,   691,   261,   733,   382,   557,   257,   567,   257,   443,
     607,   257,   302,   751,   733,   705,    34,   733,   706,   707,
    1101,   291,   292,   434,   642,  1328,   820,   712,   398,   118,
     390,   928,   829,   723,   831,   723,   806,   262,   263,   264,
     622,   623,   643,   868,   399,   295,   626,  1329,   301,   863,
     837,   704,   391,   280,   572,   554,  1293,  1252,   301,   342,
     562,   392,   823,   811,   491,   824,   960,   752,   753,   754,
     573,   673,   828,   116,   615,   651,   348,   606,   755,   812,
    1025,   301,   946,   517,   676,   561,   756,   840,   806,   808,
     349,   622,   623,   568,  1074,   704,   586,   747,  1293,   518,
     652,  1033,   587,   757,   604,   301,   407,   519,   212,  1209,
     569,   905,   343,  1034,   407,  1035,   303,   344,   841,   415,
     842,   855,   702,  1210,   622,   623,   644,   624,   625,   240,
     626,   965,   303,   935,   702,   629,   708,   444,  1007,   926,
    1128,   337,   338,   645,   297,   282,   280,   415,   296,   865,
     283,   284,   636,   647,  1101,   657,   614,   257,   617,   651,
     534,   480,   280,   705,   716,   257,  1101,   537,   944,   339,
     674,   688,   727,   728,   701,   622,   623,   653,   944,   638,
     734,   605,   848,   745,   652,   301,   301,   587,  1099,   966,
     967,   968,   116,   257,   654,   257,   969,   629,   690,   265,
     233,   266,   860,   267,   970,   637,   648,   736,   658,   210,
     932,   609,   280,   298,   340,   118,   610,   301,   584,   733,
     733,   971,   301,   675,   689,   705,   716,   933,  1091,   733,
     639,   650,  1025,   735,  1178,  1074,   746,  1046,   712,   642,
     305,   928,   306,   629,  1101,   213,   301,   301,   677,   723,
     723,  1240,   703,   702,  1101,   622,   623,   643,   737,  1128,
    1317,   626,   569,  1017,  1220,   622,   623,   611,   702,   798,
     629,   705,   415,   301,   706,   707,   866,   415,   415,   307,
     669,   852,   854,   308,   857,   859,   442,   946,   443,   636,
     806,   312,   849,   850,   851,   313,   704,   946,   705,   716,
     314,   410,   647,   869,   796,  1025,   415,   815,   704,   944,
     797,   657,   965,   816,   240,   740,   638,   315,   920,  1101,
     287,   288,  1099,   674,   345,   799,   800,   801,   674,   867,
     806,   975,   991,  1196,  1099,   921,   105,   587,   816,  1178,
    1010,   688,   637,   765,  1012,   923,   301,   449,     5,   802,
     301,  1019,   353,   701,   870,   648,   383,   301,   702,  1091,
     733,   385,   924,   622,   658,   643,   803,   639,   690,   626,
     966,   967,   968,   734,  1091,   393,   675,   969,   669,   751,
     650,   675,   386,   489,   734,  1045,  1134,   734,   303,   723,
     723,  1046,   301,  1025,   689,   692,   693,   701,   694,   745,
     736,   677,  1025,   395,  1136,   403,   677,   666,   667,   668,
     301,   736,  1099,  1141,   736,   408,   303,   116,   280,   301,
     113,  1196,  1099,   622,   623,   643,   735,   704,   946,   626,
    1196,   703,  1048,   752,   753,   754,  1088,   735,   669,  -284,
     735,  -108,   704,   601,   755,   602,   280,  1106,  1107,   695,
     957,   737,   746,  1161,  1163,   773,   400,  -108,  1025,  1162,
     301,   425,   737,  -767,  1091,   737,   696,  1025,   774,   775,
     622,   623,   448,   410,   486,   703,   785,   786,   787,   692,
     693,   788,   563,   293,   294,   669,  1196,  1099,  1003,   561,
     806,  1168,  1199,  1212,   723,  1196,   214,   301,  1200,   301,
    1025,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,  1049,  1050,  1051,  1052,  1053,  1215,  1054,   478,   866,
     740,   415,  1216,   490,  1014,  1016,   454,     5,  1196,  1021,
     496,  1217,   704,   789,   259,   498,  1011,  1216,  1218,  1224,
     502,  1018,   621,  1226,  1216,   301,   869,   542,   543,  1046,
     790,   622,   623,   643,   624,   625,   741,   626,   627,   628,
     674,   511,   629,  1227,  1228,   776,   777,  1088,  1229,  1046,
    1046,   974,   867,   742,  1046,   514,   630,  1056,   515,  1231,
    1112,  1187,  1088,   521,  1064,  1046,   622,   623,   643,   734,
     734,   400,   626,  1204,  1205,   526,  1232,   870,   701,   734,
    1233,   669,   301,   116,   528,  1234,   301,   768,   769,   806,
     701,  1046,   530,   675,   806,   539,   736,   736,   692,   693,
     538,   694,  1002,     5,   563,  1092,   736,  1235,  1238,   778,
     779,   780,   781,  1046,   301,   541,   740,   861,   677,   782,
     783,  1243,   735,   735,  1246,  1004,  1005,   301,  1115,  1248,
    1247,   957,   735,   544,   862,  1247,   622,   623,  1256,   624,
     625,   546,   626,   957,  1247,  1123,  1124,   737,   737,  1264,
     578,  1187,  1088,  1265,   278,   301,   703,   737,   396,   301,
    1260,  1187,   547,  1274,  1283,  1303,  1138,   259,   703,  1046,
    1247,  1216,  1130,   579,   214,  1132,  1133,   571,  1135,  1277,
    1306,   391,  1139,  1140,   727,   728,  1046,  1152,  1153,  1307,
     259,  -284,  1308,   259,  1313,   301,   259,   259,   301,   259,
    1247,   259,  1206,  1207,   622,   623,  1164,   624,   625,   701,
     734,   588,  1314,   589,  1169,   629,   590,   679,   301,  1330,
     680,   681,   729,  1315,   701,  1260,  1187,  1332,   591,   301,
     666,   667,   668,   587,  1260,   592,  1092,   736,   612,   730,
    1058,  1059,  1060,  1191,  1192,   619,   622,   623,   643,  1300,
    1301,  1092,   626,   460,   461,   682,   503,   504,   505,   506,
     659,   669,   957,   735,   462,   463,    98,  1260,    64,    65,
     660,    66,    67,    63,   661,    64,    65,   957,    66,    67,
     785,   786,   787,   692,   693,   788,   664,   703,   737,   714,
     683,    68,  1272,   434,   468,   469,   738,  1221,    68,  1222,
    1223,   813,   703,   821,  1225,   622,   623,   684,   624,   625,
      63,   626,    64,    65,   701,    66,    67,    99,   100,   101,
     669,   102,   103,   104,   105,   106,   107,   108,   109,    69,
      70,    71,   670,   479,   822,    68,    69,    70,    71,   825,
     826,  1092,   667,   668,   827,   259,   603,   259,   621,   671,
     259,   830,   832,   727,   728,   740,   572,   622,   623,   643,
     624,   625,   214,   626,   627,   628,   396,   957,   629,   833,
     834,   887,   669,    69,    70,    71,   835,   888,   666,   667,
     668,   890,   630,   891,  1331,  1281,  1282,  1279,   892,  1284,
     898,   941,   703,   899,   622,   623,   643,   900,   907,   908,
     626,   464,   465,   466,   467,   727,   728,   740,   942,   669,
     910,   911,   111,   310,   280,   915,  1299,   622,   623,   917,
     624,   625,  1302,   937,   939,   947,   692,   693,   629,   694,
     679,   948,    72,   680,   681,   950,  1309,   113,   958,    72,
      73,    74,    75,    76,    77,    78,   629,    73,    74,    75,
      76,    77,    78,   622,   623,   114,   624,   625,   961,   626,
    1309,   962,   316,   963,   629,   973,  1321,   761,   682,   622,
     623,   977,   624,   625,   979,   626,    72,   982,   983,   984,
     902,   985,   986,   992,    73,    74,    75,    76,    77,    78,
     993,   994,   705,   716,   999,   995,   259,   903,   996,   114,
     997,   727,   728,   998,   259,  1078,  1079,  1080,  1081,  1000,
      98,     5,    64,    65,  1009,    66,    67,   727,   728,   396,
    1029,  1030,  1031,  1032,  1037,  1043,  1044,  1062,  1063,  1066,
    1067,  1070,   259,  1084,   259,    68,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    1103,    99,   100,   101,  1104,   102,   103,   104,   105,   106,
     107,   108,   109,    69,    70,    71,  1108,   110,    31,    98,
       5,    64,    65,  1109,    66,    67,  1110,  1114,  1116,  1118,
    1125,  1126,  1131,  1147,  1148,  1149,  1154,  1155,  1156,  1159,
    1165,  1170,  1174,  1183,    68,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,  1160,
      99,   100,   101,  1201,   102,   103,   104,   105,   106,   107,
     108,   109,    69,    70,    71,  1202,   110,    31,  1203,    98,
    1213,    64,    65,  1214,    66,    67,   111,   112,  1230,  1244,
    1268,  1269,   622,  1270,   643,  1271,  1285,    63,   626,    64,
      65,  1286,    66,    67,    68,  1288,    72,   669,  1289,  1304,
    1305,   113,   760,  1316,    73,    74,    75,    76,    77,    78,
    1318,  1322,    68,  1323,   692,   693,  1325,   694,  1326,   114,
      99,   100,   101,  1327,   102,   103,   104,   105,   106,   107,
     108,   109,    69,    70,    71,   471,   309,  1333,  1334,   989,
     988,   470,   540,   608,   472,   111,   112,   473,  1008,   474,
      69,    70,    71,   550,   532,   381,   207,   246,   553,   428,
     893,   895,   377,   764,   897,    72,    63,     5,    64,    65,
     113,    66,    67,    73,    74,    75,    76,    77,    78,  1242,
     239,   980,  1047,  1069,   959,  1077,  1181,  1296,   114,  1255,
    1312,    68,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,   310,    98,   912,    64,
      65,  1022,    66,    67,   527,  1290,  1319,  1111,   987,    69,
      70,    71,  1278,    30,    31,    72,     0,   964,     0,     0,
     113,     0,    68,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    72,   432,     0,     0,     0,   114,   412,
       5,    73,    74,    75,    76,    77,    78,     0,    99,   100,
     101,     0,   102,   103,   104,   105,   106,   107,   108,   109,
      69,    70,    71,     0,   533,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    63,
       0,    64,    65,   621,    66,    67,     0,     0,     0,     0,
       0,     0,   622,   623,     0,   624,   625,     0,   626,   627,
     628,     0,    72,   629,    68,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    63,   630,    64,    65,
     621,    66,    67,     0,     0,   487,     0,     0,     0,   622,
     623,   643,   624,   625,   310,   626,   627,   628,     0,     0,
     629,    68,    69,    70,    71,    63,     0,    64,    65,     0,
      66,    67,     0,    72,   630,     0,     0,     0,   113,     0,
       0,    73,    74,    75,    76,    77,    78,   667,   668,    63,
      68,    64,    65,   621,    66,    67,   114,     0,   631,    69,
      70,    71,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,    68,   632,   413,   669,     0,   622,
     623,     0,   624,   625,     0,   626,     0,   630,    69,    70,
      71,   622,   623,   643,   669,     0,     0,   626,   414,     0,
       0,     0,     0,     0,     0,     0,   669,     0,     0,     0,
       0,     0,    69,    70,    71,    63,     0,    64,    65,     0,
      66,    67,     0,   692,   693,    72,   694,   727,   728,   740,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
      68,   740,     0,   420,     0,     0,    11,     0,   613,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,   952,    69,    70,
      71,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,    72,     0,     0,   953,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    63,     5,    64,    65,     0,
      66,    67,     0,     0,   856,    72,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
      68,     0,     0,     0,     0,  1276,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    24,
      25,    26,    27,    28,    29,    63,     0,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,    69,    70,
      71,     0,    63,     0,    64,    65,     0,    66,    67,     0,
      68,    72,     0,   580,   421,     0,    11,     0,     0,    73,
     422,    75,    76,    77,    78,    20,    21,    68,    63,     0,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,     0,     0,    68,    63,     0,    64,    65,     0,    66,
      67,     0,     0,     0,     0,    69,    70,    71,     0,     0,
       0,    63,     0,    64,    65,     0,    66,    67,     0,    68,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    69,    70,    71,    20,    21,    68,     0,     0,     0,
       0,    72,    63,     0,    64,    65,     0,    66,    67,    73,
      74,    75,    76,    77,    78,     0,     0,    69,    70,    71,
      63,     0,    64,    65,     0,    66,    67,    68,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
      63,    72,    64,    65,   581,    66,    67,     0,     0,    73,
     582,    75,    76,    77,    78,    69,    70,    71,    72,     0,
     841,     0,   842,   805,  1127,    68,    73,    74,    75,    76,
      77,    78,     0,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,   841,     0,   842,   805,
    1219,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,    69,    70,    71,     0,     0,     0,    63,
      72,    64,    65,     0,    66,    67,     0,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    72,     0,   841,
       0,   842,   805,     0,    68,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,   451,
       0,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    69,    70,    71,    63,    72,    64,    65,   597,
      66,    67,     0,     0,    73,   598,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,    63,     0,    64,    65,
      68,    66,    67,     0,     0,     0,    72,     0,     0,     0,
       0,   603,     0,     0,    73,    74,    75,    76,    77,    78,
       0,    68,     0,     0,     0,     0,    63,     0,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,    69,    70,
      71,    63,     0,    64,    65,     0,    66,    67,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,     0,     0,     0,     0,    68,    63,     0,    64,
      65,     0,    66,    67,     0,    72,   766,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    69,
      70,    71,    68,    63,     0,    64,    65,     0,    66,    67,
       0,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,    65,    68,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,     0,     0,     0,     0,     0,     0,    68,
       0,    72,     0,     0,     0,     0,   805,     0,     0,    73,
      74,    75,    76,    77,    78,     0,    69,    70,    71,     0,
       0,    63,    72,    64,    65,   838,    66,    67,     0,     0,
      73,   839,    75,    76,    77,    78,     0,    69,    70,    71,
       0,     0,     0,     0,     0,    63,    68,    64,    65,     0,
      66,    67,    72,   853,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,    72,   858,     0,
      68,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,    72,  1013,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,    69,    70,
      71,    63,     0,    64,    65,     0,    66,    67,     0,    72,
    1015,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    68,     0,     0,     0,
      72,  1020,     0,     0,     0,   621,     0,     0,    73,    74,
      75,    76,    77,    78,   622,   623,     0,   624,   625,     0,
     626,   627,   628,     0,    63,   629,    64,    65,     0,    66,
      67,     0,     0,     0,    69,    70,    71,     0,    63,   630,
      64,    65,     0,    66,    67,     0,     0,    72,  1137,    68,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,    69,    70,    71,
     667,   668,     0,     0,     0,     0,   621,     0,     0,     0,
       0,    69,    70,    71,     0,   622,   623,   643,   624,   625,
       0,   626,   627,   628,     0,     0,   629,     0,     0,     0,
     669,     0,     1,     2,     3,     4,     5,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,   872,    30,    31,     4,     5,     0,     0,    73,    74,
      75,    76,    77,    78,    72,     0,     0,     0,   873,     0,
       0,     0,    73,  1105,    75,    76,    77,    78,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     4,     5,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    33,    24,    25,    26,    27,    28,    29,     0,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    30,    31,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,    31,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     4,     5,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    33,    24,    25,    26,    27,    28,    29,     0,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,     0,     0,     0,     0,   629,
       0,   235,     0,   669,     0,     0,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     4,     5,     0,     0,     0,
     692,   693,     0,   694,     0,     0,     0,   705,   716,     0,
       0,   567,   593,   443,     0,     5,   727,   728,   740,     0,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    24,    25,
      26,    27,    28,    29,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     5,     0,     0,     0,     0,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,    24,    25,    26,
      27,    28,    29,   667,   668,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,   627,   628,     0,     0,   629,
       0,    33,     5,   669,     0,     0,     0,     0,     0,     0,
      34,     0,     0,   630,     0,     0,     0,     0,     0,     0,
     692,   693,     0,   694,     0,     0,   809,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
     442,   593,   443,     5,  1023,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1024,     0,     0,     0,   814,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   667,   668,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,   565,
       0,     0,     0,     0,   692,   693,     0,   694,     0,     0,
       0,   705,   716,   667,   668,     0,     0,     0,     0,   621,
     727,   728,   740,   819,     0,     0,     0,     0,   622,   623,
     643,   624,   625,     0,   626,   627,   628,     0,     0,   629,
       0,     0,     0,   669,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,     0,     0,     0,  1291,     0,
     692,   693,     0,   694,   667,   668,     0,     0,     0,     0,
     621,     0,     0,     0,   836,  1292,   727,   728,   740,   622,
     623,   643,   624,   625,     0,   626,   627,   628,     0,     0,
     629,     0,     0,     0,   669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1258,     0,     0,     0,   705,   716,
     667,   668,     0,     0,     0,     0,   621,   727,   728,   740,
       0,  1259,     0,     0,     0,   622,   623,   643,   624,   625,
       0,   626,   627,   628,     0,     0,   629,     0,     0,     0,
     669,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,  1250,     0,   692,   693,     0,
     694,   667,   668,     0,     0,     0,     0,   621,     0,     0,
       0,     0,  1251,     0,     0,   740,   622,   623,   643,   624,
     625,     0,   626,   627,   628,     0,     0,   629,     0,     0,
       0,   669,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1193,     0,     0,     0,   667,   668,     0,     0,     0,
       0,   621,     0,     0,   727,   728,   740,     0,  1194,     0,
     622,   623,   643,   624,   625,     0,   626,   627,   628,     0,
       0,   629,     0,     0,     0,   669,     0,     0,     0,     0,
     622,   623,   643,   624,   625,   630,   626,     0,     0,     0,
       0,   629,  1185,     0,     0,   669,     0,     0,     0,   622,
     623,   643,   624,   625,     0,   626,     0,     0,     0,  1186,
     740,     0,   692,   693,   669,   694,     0,     0,     0,   705,
     716,     0,     0,     0,     0,     0,     0,     0,   727,   728,
     740,   692,   693,     0,   694,     0,     0,     0,     0,   622,
     623,     0,   624,   625,     0,   626,  1097,   727,   728,   740,
     629,     0,     0,     0,   669,   666,   667,   668,     0,     0,
       0,     0,     0,  1098,     0,     0,  1176,     0,     0,     0,
       0,   622,   623,   643,     0,     0,     0,   626,   705,   716,
       0,   318,   319,  1177,   320,  1086,   669,   727,   728,   740,
       0,     0,     0,   321,   322,   323,   324,   325,   326,     0,
       0,     0,  1087,   692,   693,     0,   694,     0,     0,   327,
       0,   328,     0,   329,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,     0,  1072,     0,   331,     0,     0,
       0,     0,     0,     0,     0,   210,   332,     0,     0,     0,
       0,     0,  1073,     0,     0,   333,   334,   318,   319,     0,
     320,     0,     0,     0,   335,     0,   336,     0,     0,   321,
     322,   323,   324,   325,   326,     0,     0,     0,   318,   319,
       0,   320,     0,   318,   319,   327,   320,   328,   761,   329,
     321,   322,   323,   330,   325,   321,   322,   323,     0,   325,
       0,     0,     0,   331,     0,     0,   327,     0,   328,     0,
       0,   327,   332,   328,     0,     0,     0,     0,     0,     0,
       0,   333,   334,     0,   331,     0,     0,     0,     0,   331,
     335,     0,   336,   332,     5,     0,     0,     0,   332,     0,
       0,     0,   333,   334,     0,     0,     0,   333,   334,     0,
       0,   335,     0,     0,     0,     0,   335,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,   667,   668,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
      30,    31,   622,   623,   643,   624,   625,     0,   626,   627,
     628,     0,     0,   629,     0,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,     0,   692,   693,     0,   694,   667,   668,
       0,   705,   716,     0,   621,     0,     0,     0,     0,     0,
     727,   728,   740,   622,   623,   643,   624,   625,     0,   626,
     627,   628,     0,     0,   629,     0,     0,     0,   669,     0,
       0,     0,     0,     0,   667,   668,     0,     0,   630,     0,
     621,     0,     0,     0,     0,   692,   693,     0,   694,   622,
     623,   643,   624,   625,     0,   626,   627,   628,     0,     0,
     629,   727,   728,   740,   669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   667,   668,     0,   705,   716,
       0,   621,     0,     0,     0,     0,     0,   727,   728,   740,
     622,   623,   643,   624,   625,     0,   626,   627,   628,     0,
       0,   629,     0,     0,     0,   669,     0,     0,     0,     0,
       0,   667,   668,     0,     0,   630,     0,   621,     0,     0,
       0,     0,   692,   693,     0,   694,   622,   623,   643,   624,
     625,     0,   626,   627,   628,     0,     0,   629,   667,   668,
     740,   669,     0,     0,   621,     0,     0,     0,     0,     0,
       0,   630,     0,   622,   623,   643,   624,   625,     0,   626,
     627,   628,     0,     0,   629,     0,     0,     0,   669,   622,
     623,   643,   624,   625,     0,   626,   740,     0,   630,     0,
       0,     0,     0,     0,   669,   692,   693,     0,   694,     0,
       0,     0,   622,   623,     0,   624,   625,     0,   626,     0,
       0,   692,   693,   629,   694,     0,     0,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   727,   728,   740,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   705,   716,     0,     0,     0,     0,     0,     0,     0,
     727,   728,   740,     5,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,   817,
       5,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    24,    25,    26,    27,
      28,    29,     5,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,    22,     0,    24,    25,    26,    27,    28,
      29,   352,     0,     0,     0,     0,     0,   356,     0,   357,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,     0,   363,     0,   364,     0,     0,     0,     0,
       0,   367,     0,   368,     0,   369,     0,   370,     0,   371,
       0,   372,     0,   373,     0,   374,     0,     0,     0,   376
};

static const yytype_int16 yycheck[] =
{
       1,    66,    67,    68,    99,    72,   265,   495,    47,   121,
     231,   512,   494,   520,   231,     2,   551,    41,    83,   620,
     248,   232,   543,   251,   512,   726,   254,   255,   516,   572,
     541,   545,   545,   516,    99,     0,   985,   986,     3,     6,
     739,    33,   305,   709,    20,    37,   557,   232,   512,     0,
      49,   713,     3,   522,   951,   940,   258,    55,   444,    34,
      58,  1005,   247,   517,   888,     6,  1085,    73,   253,    83,
      62,    72,  1067,    38,    39,   104,  1096,   129,    43,    44,
     265,  1184,   104,    88,    49,     6,   105,  1082,    99,   179,
      55,    75,   525,    58,   279,   229,    75,    62,    49,   154,
     172,    75,     0,   132,   133,   195,     6,   225,   109,     6,
       7,   871,   494,     6,   119,   120,   301,   104,  1029,  1030,
    1031,  1032,   172,     6,   196,   117,  1037,    76,     6,   172,
     618,   513,  1043,  1044,   121,   154,   618,   121,     6,   257,
     522,   259,   121,   405,   155,   156,   157,   121,     6,   631,
     179,  1062,  1063,   196,   103,  1258,   644,   179,   225,   983,
     177,   513,   182,   183,   665,   517,  1185,   196,   520,   670,
    1165,     6,   178,  1193,   196,   527,    37,   665,    15,    16,
    1124,   248,   670,   569,   251,    46,    47,   254,   255,   172,
     257,   174,   259,   173,   172,   172,   174,   414,   181,   179,
    1097,  1086,   516,  1114,   665,   172,   670,   695,   207,   420,
     717,   525,   695,   415,   181,   478,   192,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   420,   618,   178,   262,   424,
     941,   216,   207,   267,   236,   243,   715,   248,   769,   631,
     251,   739,   244,   952,   920,   709,   207,   178,   443,   713,
     729,   923,  1257,  1023,  1213,   266,   231,   401,   282,   283,
     284,   872,   172,   816,   137,   789,   789,   411,   243,   538,
     177,   181,   145,   258,   177,   403,   172,   405,   151,   172,
     408,   174,   554,   726,   172,   195,   159,   431,   161,   300,
     562,   683,   813,   173,   172,   306,   307,   308,   741,   179,
     845,   312,  1175,   181,   172,   302,   179,   104,   305,  1230,
     181,   172,   185,   181,   187,   193,   179,   195,   191,   172,
     841,   683,     9,   715,   197,   193,   403,   172,   405,   174,
     193,   408,   193,   106,   726,   132,   181,   729,   135,   136,
     951,   188,   189,   538,    77,   172,   573,   709,   179,   346,
      99,   713,   590,   715,   592,   717,   551,    10,    11,    12,
      93,    94,    95,   861,   195,   180,    99,   194,   179,   861,
     601,   695,   121,   448,   179,   403,  1249,  1250,   179,   105,
     408,   130,   577,   179,   195,   580,   748,   160,   161,   162,
     195,   902,   587,     2,   195,    77,   398,   175,   171,   195,
     871,   179,   726,   115,   902,   407,   179,   602,   603,   553,
     532,    93,    94,   415,   931,   739,   173,   741,  1291,   131,
     102,    84,   179,   196,   448,   179,   554,   139,   154,   179,
     415,   902,   158,    96,   562,    98,   541,   163,   174,   414,
     176,   195,   940,   193,    93,    94,   179,    96,    97,    58,
      99,   106,   557,   932,   952,   104,   920,   442,   194,   923,
    1005,    75,    76,   196,   191,   181,   541,   442,   190,   861,
     186,   187,   494,   495,  1085,   497,   487,   554,   489,    77,
     353,   478,   557,   132,   133,   562,  1097,   360,   931,   103,
     512,   513,   141,   142,   516,    93,    94,   179,   941,   494,
     522,   173,   607,   525,   102,   179,   179,   179,   951,   164,
     165,   166,   121,   590,   196,   592,   171,   104,   513,   172,
     569,   174,   195,   176,   179,   494,   495,   522,   497,   129,
     179,   173,   607,    19,   148,   532,   173,   179,   138,   931,
     932,   196,   179,   512,   513,   132,   133,   196,   940,   941,
     494,   495,  1023,   522,  1071,  1072,   525,   179,   920,    77,
     193,   923,   172,   104,  1175,   567,   179,   179,   512,   931,
     932,   193,   516,  1071,  1185,    93,    94,    95,   522,  1124,
     193,    99,   567,   195,  1129,    93,    94,   173,  1086,    99,
     104,   132,   567,   179,   135,   136,   618,   572,   573,   172,
     108,   612,   613,   172,   615,   616,   172,   931,   174,   631,
     805,   172,   609,   610,   611,     6,   940,   941,   132,   133,
     195,   230,   644,   618,   173,  1096,   601,   173,   952,  1072,
     179,   653,   106,   179,   243,   143,   631,   195,   179,  1250,
      13,    14,  1085,   665,   178,   155,   156,   157,   670,   618,
     845,   173,   173,  1096,  1097,   196,    64,   179,   179,  1176,
     173,   683,   631,   536,   173,   179,   179,     6,     7,   179,
     179,   173,   177,   695,   618,   644,     6,   179,  1176,  1071,
    1072,   177,   196,    93,   653,    95,   196,   631,   683,    99,
     164,   165,   166,   715,  1086,   172,   665,   171,   108,   106,
     644,   670,     6,   312,   726,   173,   173,   729,   813,  1071,
    1072,   179,   179,  1184,   683,   125,   126,   739,   128,   741,
     715,   665,  1193,   173,   173,   177,   670,    77,    78,    79,
     179,   726,  1175,   173,   729,   177,   841,   346,   813,   179,
     177,  1184,  1185,    93,    94,    95,   715,  1071,  1072,    99,
    1193,   695,     1,   160,   161,   162,   940,   726,   108,   177,
     729,   179,  1086,   172,   171,   174,   841,   962,   963,   179,
     739,   715,   741,   173,   173,     6,   194,   195,  1249,   179,
     179,   129,   726,   177,  1176,   729,   196,  1258,    19,    20,
      93,    94,   173,   402,    62,   739,   122,   123,   124,   125,
     126,   127,   411,    17,    18,   108,  1249,  1250,   842,   811,
    1005,   173,   173,   173,  1176,  1258,    34,   179,   179,   179,
    1291,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    80,    81,    82,    83,    84,   173,    86,   193,   861,
     143,   816,   179,   195,   855,   856,     6,     7,  1291,   860,
     196,   173,  1176,   179,    72,   196,   853,   179,   173,   173,
     196,   858,    84,   173,   179,   179,   861,   178,   179,   179,
     196,    93,    94,    95,    96,    97,   179,    99,   100,   101,
     902,   121,   104,   173,   173,   116,   117,  1071,   173,   179,
     179,   764,   861,   196,   179,   196,   118,   908,   196,   173,
     977,  1085,  1086,   140,   915,   179,    93,    94,    95,   931,
     932,   194,    99,  1108,  1109,   196,   173,   861,   940,   941,
     173,   108,   179,   532,   196,   173,   179,   178,   179,  1124,
     952,   179,   196,   902,  1129,   195,   931,   932,   125,   126,
     172,   128,     6,     7,   553,   940,   941,   173,   173,   180,
     181,   182,   183,   179,   179,   194,   143,   179,   902,   190,
     191,   173,   931,   932,   173,   178,   179,   179,   979,   173,
     179,   940,   941,   172,   196,   179,    93,    94,   173,    96,
      97,   196,    99,   952,   179,   178,   179,   931,   932,   173,
     175,  1175,  1176,   173,   194,   179,   940,   941,   216,   179,
    1184,  1185,     6,   173,   173,   173,  1017,   225,   952,   179,
     179,   179,  1009,   175,   232,  1012,  1013,   173,  1015,  1214,
     173,   121,  1019,  1020,   141,   142,   179,  1038,  1039,   173,
     248,   177,   173,   251,   173,   179,   254,   255,   179,   257,
     179,   259,   167,   168,    93,    94,  1057,    96,    97,  1071,
    1072,   173,   173,   173,  1065,   104,   179,   106,   179,  1328,
     109,   110,   179,   173,  1086,  1249,  1250,   173,   179,   179,
      77,    78,    79,   179,  1258,   179,  1071,  1072,   172,   196,
     145,   146,   147,  1094,  1095,   121,    93,    94,    95,   169,
     170,  1086,    99,   285,   286,   144,   112,   113,   114,   115,
       6,   108,  1071,  1072,   287,   288,     6,  1291,     8,     9,
     196,    11,    12,     6,   149,     8,     9,  1086,    11,    12,
     122,   123,   124,   125,   126,   127,   196,  1071,  1072,   140,
     179,    31,  1209,  1328,   293,   294,   103,  1134,    31,  1136,
    1137,   193,  1086,     6,  1141,    93,    94,   196,    96,    97,
       6,    99,     8,     9,  1176,    11,    12,    57,    58,    59,
     108,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   179,    73,   175,    31,    69,    70,    71,   175,
     175,  1176,    78,    79,   129,   403,   177,   405,    84,   196,
     408,     6,   173,   141,   142,   143,   179,    93,    94,    95,
      96,    97,   420,    99,   100,   101,   424,  1176,   104,   173,
     175,   172,   108,    69,    70,    71,   175,   172,    77,    78,
      79,   172,   118,   172,  1329,  1236,  1237,  1224,   172,  1240,
     173,   179,  1176,   196,    93,    94,    95,     6,   172,   172,
      99,   289,   290,   291,   292,   141,   142,   143,   196,   108,
     172,   172,   152,   153,  1329,   172,  1267,    93,    94,   172,
      96,    97,  1273,   172,   103,   172,   125,   126,   104,   128,
     106,   172,   172,   109,   110,   121,  1287,   177,   172,   172,
     180,   181,   182,   183,   184,   185,   104,   180,   181,   182,
     183,   184,   185,    93,    94,   195,    96,    97,   196,    99,
    1311,   172,   195,   172,   104,   196,  1317,    85,   144,    93,
      94,   193,    96,    97,   172,    99,   172,     6,   172,   172,
     179,   172,   172,   175,   180,   181,   182,   183,   184,   185,
     175,   130,   132,   133,   175,   173,   554,   196,   173,   195,
     173,   141,   142,   173,   562,   134,   135,   136,   137,   175,
       6,     7,     8,     9,    60,    11,    12,   141,   142,   577,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   103,   590,   121,   592,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      80,    57,    58,    59,   196,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   172,    73,    74,     6,
       7,     8,     9,   172,    11,    12,   172,   172,   196,     6,
     196,   175,   195,   173,   173,   173,   173,   173,   173,     6,
     193,     6,   121,   193,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,   179,
      57,    58,    59,   173,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   173,    73,    74,   173,     6,
     193,     8,     9,   174,    11,    12,   152,   153,   193,   174,
     173,   173,    93,   179,    95,   173,   173,     6,    99,     8,
       9,   173,    11,    12,    31,   174,   172,   108,     6,     6,
     175,   177,   178,   175,   180,   181,   182,   183,   184,   185,
     175,   175,    31,   151,   125,   126,   172,   128,   196,   195,
      57,    58,    59,     6,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   296,    73,   173,   173,   811,
     805,   295,   385,   478,   297,   152,   153,   298,   846,   299,
      69,    70,    71,   398,   346,   194,     3,    62,   402,   243,
     631,   644,   183,   535,   653,   172,     6,     7,     8,     9,
     177,    11,    12,   180,   181,   182,   183,   184,   185,  1167,
      55,   789,   902,   923,   741,   932,  1072,  1250,   195,  1176,
    1291,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   153,     6,   683,     8,
       9,   861,    11,    12,   336,  1247,  1311,   970,   802,    69,
      70,    71,  1216,    73,    74,   172,    -1,   756,    -1,    -1,
     177,    -1,    31,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,   195,     6,
       7,   180,   181,   182,   183,   184,   185,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     6,
      -1,     8,     9,    84,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,   100,
     101,    -1,   172,   104,    31,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,     6,   118,     8,     9,
      84,    11,    12,    -1,    -1,   195,    -1,    -1,    -1,    93,
      94,    95,    96,    97,   153,    99,   100,   101,    -1,    -1,
     104,    31,    69,    70,    71,     6,    -1,     8,     9,    -1,
      11,    12,    -1,   172,   118,    -1,    -1,    -1,   177,    -1,
      -1,   180,   181,   182,   183,   184,   185,    78,    79,     6,
      31,     8,     9,    84,    11,    12,   195,    -1,   179,    69,
      70,    71,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    31,   196,   173,   108,    -1,    93,
      94,    -1,    96,    97,    -1,    99,    -1,   118,    69,    70,
      71,    93,    94,    95,   108,    -1,    -1,    99,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,     6,    -1,     8,     9,    -1,
      11,    12,    -1,   125,   126,   172,   128,   141,   142,   143,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    -1,
      31,   143,    -1,    34,    -1,    -1,    37,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,   179,    69,    70,
      71,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,   196,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,   195,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    -1,
      31,    -1,    -1,    -1,    -1,   192,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,     6,    -1,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,     6,    -1,     8,     9,    -1,    11,    12,    -1,
      31,   172,    -1,    34,   175,    -1,    37,    -1,    -1,   180,
     181,   182,   183,   184,   185,    46,    47,    31,     6,    -1,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,    31,     6,    -1,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,     6,    -1,     8,     9,    -1,    11,    12,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    46,    47,    31,    -1,    -1,    -1,
      -1,   172,     6,    -1,     8,     9,    -1,    11,    12,   180,
     181,   182,   183,   184,   185,    -1,    -1,    69,    70,    71,
       6,    -1,     8,     9,    -1,    11,    12,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
       6,   172,     8,     9,   175,    11,    12,    -1,    -1,   180,
     181,   182,   183,   184,   185,    69,    70,    71,   172,    -1,
     174,    -1,   176,   177,   178,    31,   180,   181,   182,   183,
     184,   185,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,     6,
     172,     8,     9,    -1,    11,    12,    -1,    -1,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,   172,    -1,   174,
      -1,   176,   177,    -1,    31,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,    69,    70,    71,     6,   172,     8,     9,   175,
      11,    12,    -1,    -1,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      31,    11,    12,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,   180,   181,   182,   183,   184,   185,
      -1,    31,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,     6,    -1,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    -1,    31,     6,    -1,     8,
       9,    -1,    11,    12,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,   184,   185,    69,
      70,    71,    31,     6,    -1,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,     8,     9,    31,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,
     181,   182,   183,   184,   185,    -1,    69,    70,    71,    -1,
      -1,     6,   172,     8,     9,   175,    11,    12,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,     6,    31,     8,     9,    -1,
      11,    12,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,    -1,   172,   173,    -1,
      31,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,   184,   185,    -1,    69,    70,
      71,     6,    -1,     8,     9,    -1,    11,    12,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    31,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,    84,    -1,    -1,   180,   181,
     182,   183,   184,   185,    93,    94,    -1,    96,    97,    -1,
      99,   100,   101,    -1,     6,   104,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    69,    70,    71,    -1,     6,   118,
       8,     9,    -1,    11,    12,    -1,    -1,   172,   173,    31,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,    -1,    -1,    69,    70,    71,
      78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    69,    70,    71,    -1,    93,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   179,    73,    74,     6,     7,    -1,    -1,   180,   181,
     182,   183,   184,   185,   172,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,     6,     7,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   172,    50,    51,    52,    53,    54,    55,    -1,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    73,    74,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   172,    50,    51,    52,    53,    54,    55,    -1,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,   104,
      -1,    73,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,    -1,
      -1,   172,   173,   174,    -1,     7,   141,   142,   143,    -1,
     181,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,   181,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    78,    79,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
      -1,   172,     7,   108,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,    -1,   128,    -1,    -1,   178,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
     172,   173,   174,     7,   179,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   178,    -1,     7,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   173,
      -1,    -1,    -1,    -1,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,    78,    79,    -1,    -1,    -1,    -1,    84,
     141,   142,   143,   173,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,   179,    -1,
     125,   126,    -1,   128,    78,    79,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,   173,   196,   141,   142,   143,    93,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   132,   133,
      78,    79,    -1,    -1,    -1,    -1,    84,   141,   142,   143,
      -1,   196,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,   179,    -1,   125,   126,    -1,
     128,    78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,   196,    -1,    -1,   143,    93,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    84,    -1,    -1,   141,   142,   143,    -1,   196,    -1,
      93,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,   118,    99,    -1,    -1,    -1,
      -1,   104,   179,    -1,    -1,   108,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,   196,
     143,    -1,   125,   126,   108,   128,    -1,    -1,    -1,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   125,   126,    -1,   128,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    97,    -1,    99,   179,   141,   142,   143,
     104,    -1,    -1,    -1,   108,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    99,   132,   133,
      -1,    75,    76,   196,    78,   179,   108,   141,   142,   143,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,   196,   125,   126,    -1,   128,    -1,    -1,   103,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,   139,   140,    75,    76,    -1,
      78,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    75,    76,
      -1,    78,    -1,    75,    76,   103,    78,   105,    85,   107,
      87,    88,    89,   111,    91,    87,    88,    89,    -1,    91,
      -1,    -1,    -1,   121,    -1,    -1,   103,    -1,   105,    -1,
      -1,   103,   130,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,   121,    -1,    -1,    -1,    -1,   121,
     148,    -1,   150,   130,     7,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   139,   140,    -1,
      -1,   148,    -1,    -1,    -1,    -1,   148,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,    -1,   128,    78,    79,
      -1,   132,   133,    -1,    84,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,   118,    -1,
      84,    -1,    -1,    -1,    -1,   125,   126,    -1,   128,    93,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   141,   142,   143,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,   132,   133,
      -1,    84,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      93,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,    78,    79,    -1,    -1,   118,    -1,    84,    -1,    -1,
      -1,    -1,   125,   126,    -1,   128,    93,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,    78,    79,
     143,   108,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    93,
      94,    95,    96,    97,    -1,    99,   143,    -1,   118,    -1,
      -1,    -1,    -1,    -1,   108,   125,   126,    -1,   128,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,    -1,
      -1,   125,   126,   104,   128,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,     7,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       7,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,     7,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,   133,    -1,    -1,    -1,    -1,    -1,   139,    -1,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,   155,    -1,   157,    -1,    -1,    -1,    -1,
      -1,   163,    -1,   165,    -1,   167,    -1,   169,    -1,   171,
      -1,   173,    -1,   175,    -1,   177,    -1,    -1,    -1,   181
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,     4,     5,     6,     7,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      73,    74,   153,   172,   181,   198,   222,   223,   227,   228,
     229,   230,   236,   239,   240,   241,   242,   243,   252,   270,
     271,   272,   273,   276,   328,   329,   330,   364,   365,   465,
     468,   505,   507,     6,     8,     9,    11,    12,    31,    69,
      70,    71,   172,   180,   181,   182,   183,   184,   185,   200,
     201,   202,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   220,     6,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      73,   152,   153,   177,   195,   220,   222,   223,   258,   260,
     261,   263,   264,   265,   266,   267,   268,   269,   283,   284,
     286,   287,   294,   295,   302,   303,   309,   310,   315,   316,
     333,   334,   337,   338,   341,   342,   351,   353,   357,   358,
     367,   368,   374,   375,   380,   381,   384,   385,   388,   389,
     392,   393,   396,   397,   400,   401,   404,   405,   408,   409,
     412,   413,   416,   417,   420,   421,   424,   425,   428,   429,
     435,   436,   439,   440,   443,   444,   445,   446,   448,   449,
     450,   451,   452,   453,   454,   457,   460,   461,   462,   464,
     497,   498,   499,   504,   505,   513,   514,   270,     6,   177,
     129,   466,   154,   241,   239,   243,   244,     0,   195,   224,
     225,   241,   223,   223,     6,   177,   252,   223,   223,   275,
     278,   172,   174,   242,   271,    73,   223,   272,   281,   330,
     222,   272,   280,   282,   223,   241,   273,   172,   172,   204,
     204,   172,   204,   172,   172,   172,   220,   228,   233,   239,
     249,     9,    10,    11,    12,   172,   174,   176,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   194,   219,
     204,   206,   181,   186,   187,   182,   183,    13,    14,    15,
      16,   188,   189,    17,    18,   180,   190,   191,    19,    20,
     192,   179,   193,   217,   221,   193,   172,   172,   172,    73,
     153,   258,   172,     6,   195,   195,   195,   220,    75,    76,
      78,    87,    88,    89,    90,    91,    92,   103,   105,   107,
     111,   121,   130,   139,   140,   148,   150,    75,    76,   103,
     148,   463,   105,   158,   163,   178,   262,   195,   241,   264,
     258,   285,   268,   177,   306,   285,   268,   268,   268,   285,
     352,   285,   268,   268,   268,   285,   285,   268,   268,   268,
     268,   268,   268,   268,   268,   285,   268,   306,   285,   285,
     285,   265,   285,     6,   517,   177,     6,   199,   237,   238,
      99,   121,   130,   172,   508,   173,   239,   243,   179,   195,
     194,   274,   277,   177,   178,   231,   232,   233,   177,   261,
     222,   279,     6,   173,   195,   223,   245,   246,   247,   248,
      34,   175,   181,   218,   244,   129,   241,    73,   280,   366,
     241,   506,   173,   203,   218,   249,   249,   218,   249,   249,
     173,   233,   172,   174,   243,   250,   251,   233,   173,     6,
     252,   173,   203,   220,     6,   252,   218,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   209,   210,   210,
     211,   212,   213,   214,   215,   220,   218,   258,   193,    73,
     258,   259,   284,   220,   220,   220,    62,   195,   220,   222,
     195,   195,    76,   103,   288,   304,   196,   311,   196,   172,
     196,   447,   196,   112,   113,   114,   115,   455,   172,   196,
     458,   121,   296,   430,   196,   196,   317,   115,   131,   139,
     354,   140,   369,    75,   121,   376,   196,   463,   196,   515,
     196,   500,   263,    73,   285,   307,   308,   285,   172,   195,
     237,   194,   178,   179,   172,   331,   196,     6,   496,   509,
     225,   226,   261,   279,   231,   178,   232,   193,   195,   234,
     235,   241,   231,   222,   261,   173,   246,   172,   241,   243,
     250,   173,   179,   195,   173,   179,   218,   244,   175,   175,
      34,   175,   181,   218,   138,   261,   173,   179,   173,   173,
     179,   179,   179,   173,   245,   246,   250,   175,   181,   218,
     251,   172,   174,   177,   206,   173,   175,   193,   259,   173,
     173,   173,   172,   195,   220,   195,   195,   220,   441,   121,
     437,    84,    93,    94,    96,    97,    99,   100,   101,   104,
     118,   179,   196,   289,   290,   474,   475,   477,   481,   483,
     485,   495,    77,    95,   179,   196,   305,   475,   477,   479,
     483,    77,   102,   179,   196,   312,   313,   475,   477,     6,
     196,   149,   456,   459,   196,   335,    77,    78,    79,   108,
     179,   196,   297,   298,   475,   477,   479,   483,   487,   106,
     109,   110,   144,   179,   196,   431,   432,   474,   475,   477,
     481,   485,   125,   126,   128,   179,   196,   318,   319,   323,
     325,   475,   479,   483,   487,   132,   135,   136,   345,   359,
     360,   361,   485,   343,   140,   394,   133,   179,   196,   345,
     347,   355,   356,   485,    75,   121,   398,   141,   142,   179,
     196,   370,   371,   474,   475,   477,   481,   483,   103,   382,
     143,   179,   196,   377,   378,   475,   477,   487,   179,   196,
     485,   106,   160,   161,   162,   171,   179,   196,   516,   501,
     178,    85,    73,   178,   308,   285,   173,   203,   178,   179,
     221,   178,   238,     6,    19,    20,   116,   117,   180,   181,
     182,   183,   190,   191,   471,   122,   123,   124,   127,   179,
     196,   320,   321,   323,   325,   332,   173,   179,    99,   155,
     156,   157,   179,   196,   510,   177,   218,   253,   261,   178,
     221,   179,   195,   193,   178,   173,   179,    56,   247,   173,
     246,     6,   175,   218,   218,   175,   175,   129,   218,   249,
       6,   249,   173,   173,   175,   175,   173,   245,   175,   181,
     218,   174,   176,   253,   254,   255,   256,   257,   217,   258,
     258,   258,   220,   173,   220,   195,   195,   220,   173,   220,
     195,   179,   196,   290,   442,   474,   475,   477,   479,   481,
     483,   339,   179,   196,   290,   298,   438,   474,   475,   477,
     479,   481,   483,   293,   476,   478,   482,   172,   172,   292,
     172,   172,   172,   289,   480,   305,   314,   312,   173,   196,
       6,   489,   179,   196,   297,   319,   336,   172,   172,   297,
     172,   172,   431,   324,   326,   172,   318,   172,   362,   363,
     179,   196,   360,   179,   196,   344,   345,   347,   485,    75,
     121,   406,   179,   196,   355,   370,   395,   172,   355,   103,
     402,   179,   196,   370,   378,   399,   487,   172,   172,   370,
     121,   386,   179,   196,   318,   378,   383,   477,   172,   377,
     485,   196,   172,   172,   516,   106,   164,   165,   166,   171,
     179,   196,   502,   196,   285,   173,   178,   193,   322,   172,
     332,   467,     6,   172,   172,   172,   172,   510,   254,   235,
     221,   173,   175,   175,   130,   173,   173,   173,   173,   175,
     175,   221,     6,   252,   178,   179,   253,   194,   257,    60,
     173,   258,   173,   173,   220,   173,   220,   195,   258,   173,
     173,   220,   442,   179,   196,   319,   340,   438,   438,   172,
     172,   172,   172,    84,    96,    98,   471,   172,   291,   486,
      88,   119,   120,   172,   172,   173,   179,   336,     1,    80,
      81,    82,    83,    84,    86,   301,   220,   433,   145,   146,
     147,   434,   172,   172,   220,   346,   172,   172,   360,   344,
     103,   410,   179,   196,   355,   399,   407,   395,   134,   135,
     136,   137,   349,   350,   121,   414,   179,   196,   371,   383,
     403,   474,   481,   399,   372,   373,   390,   179,   196,   378,
     387,   438,   383,    80,   196,   181,   218,   218,   172,   172,
     172,   502,   228,   472,   172,   220,   196,   471,     6,   511,
     512,   511,   511,   178,   179,   196,   175,   178,   253,   255,
     258,   195,   258,   258,   173,   258,   173,   173,   220,   258,
     258,   173,   340,   489,   489,   489,   489,   173,   173,   173,
     484,   489,   220,   220,   173,   173,   173,   489,   489,     6,
     179,   173,   179,   173,   220,   193,   489,   489,   173,   220,
       6,   488,   490,   490,   121,   418,   179,   196,   355,   403,
     411,   407,   490,   193,   422,   179,   196,   371,   387,   415,
     403,   220,   220,   179,   196,   340,   378,   391,   387,   173,
     179,   173,   173,   173,   218,   218,   167,   168,   503,   179,
     193,   489,   173,   193,   174,   173,   179,   173,   173,   178,
     253,   258,   258,   258,   173,   258,   173,   173,   173,   173,
     193,   173,   173,   173,   173,   173,   300,   299,   173,   490,
     193,   327,   327,   173,   174,   491,   173,   179,   173,   426,
     179,   196,   356,   415,   419,   411,   173,   348,   179,   196,
     371,   391,   423,   415,   173,   173,   391,   379,   173,   173,
     179,   173,   228,   469,   173,   511,   192,   218,   512,   258,
     489,   220,   220,   173,   220,   173,   173,   493,   174,     6,
     488,   179,   196,   356,   423,   427,   419,   490,   423,   220,
     169,   170,   220,   173,     6,   175,   173,   173,   173,   220,
     494,   492,   427,   173,   173,   173,   175,   193,   175,   494,
     470,   220,   175,   151,   473,   172,   196,     6,   172,   194,
     203,   217,   173,   173,   173
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   197,   198,   198,   198,   198,   199,   200,   200,   201,
     201,   201,   201,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   206,   206,   207,   207,   207,   207,
     208,   208,   208,   209,   209,   209,   210,   210,   210,   210,
     210,   211,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   221,   222,   222,   222,   222,   222,   222,   223,   223,
     223,   223,   223,   223,   223,   223,   224,   224,   225,   226,
     225,   227,   227,   227,   227,   227,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   229,   229,   229,   229,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   239,   240,   241,   241,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   243,   243,   243,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   248,   248,
     249,   249,   250,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   253,   253,   253,
     254,   254,   254,   254,   255,   256,   256,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   261,   262,   261,   263,   263,   264,   264,
     264,   264,   265,   265,   266,   266,   266,   267,   267,   267,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   269,   269,   269,   269,   269,   270,   270,   271,
     271,   271,   272,   272,   274,   273,   275,   273,   277,   276,
     278,   276,   279,   279,   280,   280,   281,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   284,   284,   285,   286,   287,
     288,   288,   288,   289,   289,   289,   289,   289,   289,   290,
     291,   290,   292,   290,   290,   293,   290,   294,   295,   296,
     296,   296,   297,   297,   297,   297,   297,   297,   298,   298,
     299,   298,   300,   298,   298,   301,   301,   301,   301,   301,
     301,   302,   303,   304,   304,   304,   305,   305,   305,   305,
     305,   306,   307,   307,   307,   308,   309,   310,   311,   311,
     311,   312,   312,   312,   312,   314,   313,   315,   316,   317,
     317,   317,   318,   318,   318,   318,   318,   319,   319,   319,
     320,   320,   322,   321,   324,   323,   326,   325,   327,   327,
     328,   329,   329,   330,   331,   331,   331,   332,   332,   332,
     332,   332,   333,   334,   335,   335,   335,   336,   336,   337,
     338,   339,   339,   339,   340,   340,   341,   342,   343,   343,
     343,   344,   344,   344,   346,   345,   348,   347,   349,   347,
     350,   350,   350,   350,   352,   351,   353,   354,   354,   354,
     355,   355,   356,   356,   357,   358,   359,   359,   359,   360,
     360,   360,   362,   361,   363,   361,   364,   365,   366,   367,
     368,   369,   369,   369,   370,   370,   370,   370,   370,   370,
     372,   371,   373,   371,   374,   375,   376,   376,   376,   377,
     377,   377,   377,   378,   379,   378,   380,   381,   382,   382,
     382,   383,   383,   383,   384,   385,   386,   386,   386,   387,
     387,   388,   389,   390,   390,   390,   391,   391,   392,   393,
     394,   394,   394,   395,   395,   396,   397,   398,   398,   398,
     399,   399,   399,   400,   401,   402,   402,   402,   403,   403,
     403,   403,   404,   405,   406,   406,   406,   407,   407,   408,
     409,   410,   410,   410,   411,   411,   412,   413,   414,   414,
     414,   415,   415,   416,   417,   418,   418,   418,   419,   419,
     420,   421,   422,   422,   422,   423,   423,   424,   425,   426,
     426,   426,   427,   427,   428,   429,   430,   430,   430,   431,
     431,   431,   431,   431,   432,   433,   432,   432,   432,   432,
     434,   434,   434,   435,   436,   437,   437,   437,   438,   438,
     438,   438,   438,   438,   438,   438,   439,   440,   441,   441,
     441,   442,   442,   442,   442,   442,   442,   442,   443,   444,
     445,   446,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   455,   455,   455,   455,   456,   456,   457,   457,
     459,   458,   460,   461,   462,   462,   462,   463,   463,   463,
     463,   464,   466,   467,   465,   469,   470,   468,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   472,
     472,   473,   473,   473,   474,   474,   474,   476,   475,   478,
     477,   480,   479,   482,   481,   484,   483,   486,   485,   487,
     488,   489,   489,   490,   490,   490,   490,   492,   491,   493,
     491,   494,   494,   495,   495,   495,   496,   496,   497,   497,
     498,   500,   499,   501,   501,   501,   502,   502,   502,   502,
     502,   503,   503,   503,   503,   504,   504,   506,   505,   505,
     508,   507,   509,   509,   509,   510,   510,   510,   510,   511,
     511,   512,   512,   512,   513,   514,   515,   515,   515,   516,
     516,   516,   516,   516,   516,   517,   517
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     3,     1,     4,     3,     4,     3,     4,     3,
       3,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       2,     2,     2,     2,     4,     6,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     5,     5,     2,     2,     1,     1,     1,
       2,     3,     2,     1,     2,     1,     2,     1,     3,     1,
       3,     2,     4,     5,     5,     6,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     3,     3,
       4,     4,     5,     5,     6,     6,     4,     5,     4,     3,
       4,     6,     5,     5,     4,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       3,     4,     2,     3,     3,     4,     1,     1,     3,     4,
       1,     2,     3,     4,     2,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     0,     4,     1,     2,     1,     1,
       1,     1,     1,     2,     5,     7,     5,     5,     7,     1,
       6,     7,     7,     7,     8,     8,     8,     9,     6,     7,
       7,     8,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     3,     0,     5,
       0,     4,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     1,     0,     5,     2,     4,     0,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     7,     0,     7,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     0,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     3,     2,     4,     0,     2,
       3,     1,     1,     1,     1,     0,     5,     2,     4,     0,
       2,     3,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     0,     5,     0,     6,     0,     6,     0,     2,
       2,     1,     2,     5,     0,     2,     3,     4,     1,     1,
       1,     1,     2,     5,     0,     2,     3,     1,     1,     2,
       6,     0,     2,     3,     1,     1,     2,     5,     0,     2,
       3,     1,     1,     1,     0,     5,     0,     7,     0,     5,
       1,     1,     1,     1,     0,     3,     4,     0,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     2,     3,     1,
       1,     1,     0,     5,     0,     5,     3,     4,     5,     2,
       4,     0,     2,     3,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     5,     2,     4,     0,     2,     3,     1,
       1,     1,     1,     4,     0,     7,     2,     5,     0,     2,
       3,     1,     1,     1,     2,     6,     0,     2,     3,     1,
       1,     2,     7,     0,     2,     3,     1,     1,     2,     5,
       0,     2,     3,     1,     1,     2,     5,     0,     2,     3,
       1,     1,     1,     2,     6,     0,     2,     3,     1,     1,
       1,     1,     2,     6,     0,     2,     3,     1,     1,     2,
       7,     0,     2,     3,     1,     1,     2,     7,     0,     2,
       3,     1,     1,     2,     8,     0,     2,     3,     1,     1,
       2,     8,     0,     2,     3,     1,     1,     2,     9,     0,
       2,     3,     1,     1,     2,     4,     0,     2,     3,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     1,     6,
       1,     1,     1,     2,     5,     0,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     3,     4,     3,     3,     3,     2,     3,     3,     2,
       5,     0,     1,     1,     1,     1,     0,     1,     3,     4,
       0,     4,     2,     3,     4,     5,     6,     1,     1,     1,
       1,     3,     0,     0,     7,     0,     0,    14,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     6,     7,     4,     4,     4,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     7,     0,     5,     4,
       2,     1,     3,     1,     1,     3,     3,     0,     5,     0,
       4,     3,     1,     4,     4,     4,     1,     3,     1,     1,
       3,     0,     5,     0,     2,     3,     4,     4,     4,     1,
       1,     1,     1,     3,     3,     1,     1,     0,     4,     2,
       0,     5,     0,     2,     3,     4,     4,     4,     6,     1,
       3,     1,     5,     4,     3,     4,     0,     2,     3,     4,
       4,     4,     1,     1,     1,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 474 "parser.y"
                                            { /* to avoid warnings */ }
#line 3568 "parser.c"
    break;

  case 3:
#line 475 "parser.y"
                                            { pastree_expr = (yyvsp[0].expr); }
#line 3574 "parser.c"
    break;

  case 4:
#line 476 "parser.y"
                                            { pastree_stmt = (yyvsp[0].stmt); }
#line 3580 "parser.c"
    break;

  case 5:
#line 477 "parser.y"
                                            { pastree_stmt = (yyvsp[0].stmt); }
#line 3586 "parser.c"
    break;

  case 6:
#line 495 "parser.y"
    {
      symbol s = Symbol((yyvsp[0].name));
      if (checkDecls)
      {
        if ( symtab_get(stab, s, LABELNAME) )  /* NOT a type name */
          parse_error(-1, "enum symbol '%s' is already in use.", (yyvsp[0].name));
        symtab_put(stab, s, LABELNAME);
      }
      (yyval.symb) = s;
    }
#line 3601 "parser.c"
    break;

  case 7:
#line 516 "parser.y"
    {
      (yyval.string) = strdup((yyvsp[0].name));
    }
#line 3609 "parser.c"
    break;

  case 8:
#line 520 "parser.y"
    {
      /* Or we could leave it as is (as a SpaceList) */
      if (((yyvsp[-1].string) = realloc((yyvsp[-1].string), strlen((yyvsp[-1].string)) + strlen((yyvsp[0].name)))) == NULL)
        parse_error(-1, "string out of memory\n");
      strcpy(((yyvsp[-1].string))+(strlen((yyvsp[-1].string))-1),((yyvsp[0].name))+1);  /* Catenate on the '"' */
      (yyval.string) = (yyvsp[-1].string);
    }
#line 3621 "parser.c"
    break;

  case 9:
#line 543 "parser.y"
    {
      symbol  id = Symbol((yyvsp[0].name));
      stentry e;
      bool    chflag = false;

      if (checkDecls)
      {
        check_uknown_var((yyvsp[0].name));
        /* The parser constructs the original AST; this is the only
         * place it doesn't (actually there is one more place, when replacing
         * the "main" function): threadprivate variables are replaced on the
         * fly by pointers. This makes the job of later stages much smoother,
         * but the produced AST is semantically incorrect.
         */
        if ((e = symtab_get(stab, id, IDNAME)) != NULL) /* could be enum name */
          if (istp(e) && threadmode)
            chflag = true;
      }
      (yyval.expr) = chflag ? Parenthesis(UnaryOperator(UOP_star, Identifier(id)))
                  : Identifier(id);
    }
#line 3647 "parser.c"
    break;

  case 10:
#line 565 "parser.y"
    {
      (yyval.expr) = Constant( strdup((yyvsp[0].name)) );
    }
#line 3655 "parser.c"
    break;

  case 11:
#line 569 "parser.y"
    {
      (yyval.expr) = String((yyvsp[0].string));
    }
#line 3663 "parser.c"
    break;

  case 12:
#line 573 "parser.y"
    {
      (yyval.expr) = Parenthesis((yyvsp[-1].expr));
    }
#line 3671 "parser.c"
    break;

  case 13:
#line 581 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3679 "parser.c"
    break;

  case 14:
#line 585 "parser.y"
    {
      (yyval.expr) = ArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr));
    }
#line 3687 "parser.c"
    break;

  case 15:
#line 595 "parser.y"
    {
      /* Catch calls to "main()" (unlikely but possible) */
      // NOTE(luobin): Catch calls to DF_Source_Stop(), too.
      do
      {
      if(strcmp((yyvsp[-2].name), "DF_Run") == 0)
      {
        (yyval.expr) = FunctionCall(IdentName((yyvsp[-2].name)), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      IdentName("DF_COUNT") ) );
                                      break;
      }

      if(strcmp((yyvsp[-2].name), "DF_Source_Stop") == 0)
      {
        (yyval.expr) = FunctionCall(IdentName((yyvsp[-2].name)), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      IdentName("DF_FN_item_index") ) );
                                      break;
      }

      (yyval.expr) = strcmp((yyvsp[-2].name), "main") ?
              FunctionCall(IdentName((yyvsp[-2].name)), NULL) :
              FunctionCall(IdentName(MAIN_NEWNAME), NULL);
      }
      while(0);

    }
#line 3722 "parser.c"
    break;

  case 16:
#line 627 "parser.y"
    {
      //wcy
      if(strcmp((yyvsp[-3].name), "DF_Run") == 0)
      {
        (yyval.expr) = FunctionCall(IdentName((yyvsp[-3].name)), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      (yyvsp[-1].expr)));
                                      //wcy
                                      use_for_df_count=(yyvsp[-1].expr)->u.str;
                                      break;
      }
      /* Catch calls to "main()" (unlikely but possible) */
      (yyval.expr) = strcmp((yyvsp[-3].name), "main") ?
             FunctionCall(IdentName((yyvsp[-3].name)), (yyvsp[-1].expr)) :
             FunctionCall(IdentName(MAIN_NEWNAME), (yyvsp[-1].expr));
    }
#line 3744 "parser.c"
    break;

  case 17:
#line 645 "parser.y"
    {
      (yyval.expr) = FunctionCall((yyvsp[-2].expr), NULL);
    }
#line 3752 "parser.c"
    break;

  case 18:
#line 649 "parser.y"
    {
      (yyval.expr) = FunctionCall((yyvsp[-3].expr), (yyvsp[-1].expr));
    }
#line 3760 "parser.c"
    break;

  case 19:
#line 653 "parser.y"
    {
      (yyval.expr) = DotField((yyvsp[-2].expr), Symbol((yyvsp[0].name)));
    }
#line 3768 "parser.c"
    break;

  case 20:
#line 657 "parser.y"
    {
      (yyval.expr) = PtrField((yyvsp[-2].expr), Symbol((yyvsp[0].name)));
    }
#line 3776 "parser.c"
    break;

  case 21:
#line 666 "parser.y"
    {
      (yyval.expr) = DotField((yyvsp[-2].expr), (yyvsp[0].symb));
    }
#line 3784 "parser.c"
    break;

  case 22:
#line 670 "parser.y"
    {
      (yyval.expr) = PtrField((yyvsp[-2].expr), (yyvsp[0].symb));
    }
#line 3792 "parser.c"
    break;

  case 23:
#line 674 "parser.y"
    {
      (yyval.expr) = PostOperator((yyvsp[-1].expr), UOP_inc);
    }
#line 3800 "parser.c"
    break;

  case 24:
#line 678 "parser.y"
    {
      (yyval.expr) = PostOperator((yyvsp[-1].expr), UOP_dec);
    }
#line 3808 "parser.c"
    break;

  case 25:
#line 682 "parser.y"
    {
      (yyval.expr) = CastedExpr((yyvsp[-4].decl), BracedInitializer((yyvsp[-1].expr)));
    }
#line 3816 "parser.c"
    break;

  case 26:
#line 686 "parser.y"
    {
      (yyval.expr) = CastedExpr((yyvsp[-5].decl), BracedInitializer((yyvsp[-2].expr)));
    }
#line 3824 "parser.c"
    break;

  case 27:
#line 694 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3832 "parser.c"
    break;

  case 28:
#line 698 "parser.y"
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3840 "parser.c"
    break;

  case 29:
#line 706 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3848 "parser.c"
    break;

  case 30:
#line 710 "parser.y"
    {
      (yyval.expr) = PreOperator((yyvsp[0].expr), UOP_inc);
    }
#line 3856 "parser.c"
    break;

  case 31:
#line 714 "parser.y"
    {
      (yyval.expr) = PreOperator((yyvsp[0].expr), UOP_dec);
    }
#line 3864 "parser.c"
    break;

  case 32:
#line 718 "parser.y"
    {
      if ((yyvsp[-1].type) == -1)
        (yyval.expr) = (yyvsp[0].expr);                    /* simplify */
      else
        (yyval.expr) = UnaryOperator((yyvsp[-1].type), (yyvsp[0].expr));
    }
#line 3875 "parser.c"
    break;

  case 33:
#line 725 "parser.y"
    {
      (yyval.expr) = Sizeof((yyvsp[0].expr));
    }
#line 3883 "parser.c"
    break;

  case 34:
#line 729 "parser.y"
    {
      (yyval.expr) = Sizeoftype((yyvsp[-1].decl));
    }
#line 3891 "parser.c"
    break;

  case 35:
#line 738 "parser.y"
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_va_arg"),
                        CommaList((yyvsp[-3].expr), TypeTrick((yyvsp[-1].decl))));
    }
#line 3900 "parser.c"
    break;

  case 36:
#line 743 "parser.y"
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_offsetof"),
                        CommaList(TypeTrick((yyvsp[-3].decl)), IdentName((yyvsp[-1].name))));
    }
#line 3909 "parser.c"
    break;

  case 37:
#line 748 "parser.y"
    {
      (yyval.expr) = FunctionCall(IdentName("__builtin_types_compatible_p"),
                        CommaList(TypeTrick((yyvsp[-3].decl)), TypeTrick((yyvsp[-1].decl))));
    }
#line 3918 "parser.c"
    break;

  case 38:
#line 757 "parser.y"
    {
      (yyval.type) = UOP_addr;
    }
#line 3926 "parser.c"
    break;

  case 39:
#line 761 "parser.y"
    {
      (yyval.type) = UOP_star;
    }
#line 3934 "parser.c"
    break;

  case 40:
#line 765 "parser.y"
    {
      (yyval.type) = -1;         /* Ingore this one */
    }
#line 3942 "parser.c"
    break;

  case 41:
#line 769 "parser.y"
    {
      (yyval.type) = UOP_neg;
    }
#line 3950 "parser.c"
    break;

  case 42:
#line 773 "parser.y"
    {
      (yyval.type) = UOP_bnot;
    }
#line 3958 "parser.c"
    break;

  case 43:
#line 777 "parser.y"
    {
      (yyval.type) = UOP_lnot;
    }
#line 3966 "parser.c"
    break;

  case 44:
#line 785 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3974 "parser.c"
    break;

  case 45:
#line 789 "parser.y"
    {
      (yyval.expr) = CastedExpr((yyvsp[-2].decl), (yyvsp[0].expr));
    }
#line 3982 "parser.c"
    break;

  case 46:
#line 797 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 3990 "parser.c"
    break;

  case 47:
#line 801 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_mul, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 3998 "parser.c"
    break;

  case 48:
#line 805 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_div, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4006 "parser.c"
    break;

  case 49:
#line 809 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_mod, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4014 "parser.c"
    break;

  case 50:
#line 817 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4022 "parser.c"
    break;

  case 51:
#line 821 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_add, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4030 "parser.c"
    break;

  case 52:
#line 825 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_sub, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4038 "parser.c"
    break;

  case 53:
#line 833 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4046 "parser.c"
    break;

  case 54:
#line 837 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_shl, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4054 "parser.c"
    break;

  case 55:
#line 841 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_shr, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4062 "parser.c"
    break;

  case 56:
#line 849 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4070 "parser.c"
    break;

  case 57:
#line 853 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_lt, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4078 "parser.c"
    break;

  case 58:
#line 857 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_gt, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4086 "parser.c"
    break;

  case 59:
#line 861 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_leq, (yyvsp[-2].expr), (yyvsp[0].expr));
     }
#line 4094 "parser.c"
    break;

  case 60:
#line 865 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_geq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4102 "parser.c"
    break;

  case 61:
#line 873 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4110 "parser.c"
    break;

  case 62:
#line 877 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_eqeq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4118 "parser.c"
    break;

  case 63:
#line 881 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_neq, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4126 "parser.c"
    break;

  case 64:
#line 889 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4134 "parser.c"
    break;

  case 65:
#line 893 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_band, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4142 "parser.c"
    break;

  case 66:
#line 901 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4150 "parser.c"
    break;

  case 67:
#line 905 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_xor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4158 "parser.c"
    break;

  case 68:
#line 913 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4166 "parser.c"
    break;

  case 69:
#line 917 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_bor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4174 "parser.c"
    break;

  case 70:
#line 925 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4182 "parser.c"
    break;

  case 71:
#line 929 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_land, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4190 "parser.c"
    break;

  case 72:
#line 937 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4198 "parser.c"
    break;

  case 73:
#line 941 "parser.y"
    {
      (yyval.expr) = BinaryOperator(BOP_lor, (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4206 "parser.c"
    break;

  case 74:
#line 949 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4214 "parser.c"
    break;

  case 75:
#line 953 "parser.y"
    {
      (yyval.expr) = ConditionalExpr((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4222 "parser.c"
    break;

  case 76:
#line 961 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4230 "parser.c"
    break;

  case 77:
#line 965 "parser.y"
    {
      (yyval.expr) = Assignment((yyvsp[-2].expr), (yyvsp[-1].type), (yyvsp[0].expr));
    }
#line 4238 "parser.c"
    break;

  case 78:
#line 973 "parser.y"
    {
      (yyval.type) = ASS_eq;  /* Need fix here! */
    }
#line 4246 "parser.c"
    break;

  case 79:
#line 977 "parser.y"
    {
      (yyval.type) = ASS_mul;
    }
#line 4254 "parser.c"
    break;

  case 80:
#line 981 "parser.y"
    {
      (yyval.type) = ASS_div;
    }
#line 4262 "parser.c"
    break;

  case 81:
#line 985 "parser.y"
    {
      (yyval.type) = ASS_mod;
    }
#line 4270 "parser.c"
    break;

  case 82:
#line 989 "parser.y"
    {
      (yyval.type) = ASS_add;
    }
#line 4278 "parser.c"
    break;

  case 83:
#line 993 "parser.y"
    {
      (yyval.type) = ASS_sub;
    }
#line 4286 "parser.c"
    break;

  case 84:
#line 997 "parser.y"
    {
      (yyval.type) = ASS_shl;
    }
#line 4294 "parser.c"
    break;

  case 85:
#line 1001 "parser.y"
    {
      (yyval.type) = ASS_shr;
    }
#line 4302 "parser.c"
    break;

  case 86:
#line 1005 "parser.y"
    {
      (yyval.type) = ASS_and;
    }
#line 4310 "parser.c"
    break;

  case 87:
#line 1009 "parser.y"
    {
      (yyval.type) = ASS_xor;
    }
#line 4318 "parser.c"
    break;

  case 88:
#line 1013 "parser.y"
    {
      (yyval.type) = ASS_or;
    }
#line 4326 "parser.c"
    break;

  case 89:
#line 1021 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4334 "parser.c"
    break;

  case 90:
#line 1025 "parser.y"
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 4342 "parser.c"
    break;

  case 91:
#line 1033 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 4350 "parser.c"
    break;

  case 92:
#line 1047 "parser.y"
    {
      /* There is a special case which wrongly uses this rule:
       *   typedef xxx already_known_user_type.
       * In this case the already_known_user_type (T) is re-defined,
       * and because T is known, it is not considered as a declarator,
       * but a "typedef_name", and is part of the specifier.
       * We fix it here.
       */
      if (isTypedef && (yyvsp[-1].spec)->type == SPECLIST)
        (yyval.stmt) = Declaration((yyvsp[-1].spec), fix_known_typename((yyvsp[-1].spec)));
      else
        (yyval.stmt) = Declaration((yyvsp[-1].spec), NULL);
      isTypedef = 0;
    }
#line 4369 "parser.c"
    break;

  case 93:
#line 1062 "parser.y"
    {
      (yyval.stmt) = Declaration((yyvsp[-2].spec), (yyvsp[-1].decl));
      if (checkDecls) add_declaration_links((yyvsp[-2].spec), (yyvsp[-1].decl));
      isTypedef = 0;

    }
#line 4380 "parser.c"
    break;

  case 94:
#line 1069 "parser.y"
    {
      (yyval.stmt) = OmpStmt(OmpConstruct(DCTHREADPRIVATE, (yyvsp[0].odir), NULL));
    }
#line 4388 "parser.c"
    break;

  case 95:
#line 1074 "parser.y"
    {
      //$$ = OmpStmt(OmpConstruct(DCTHREADPRIVATE, $1, NULL)); TODO
    }
#line 4396 "parser.c"
    break;

  case 96:
#line 1078 "parser.y"
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
    }
#line 4404 "parser.c"
    break;

  case 97:
#line 1082 "parser.y"
    {
      //$$ = OmpStmt(OmpConstruct(DCTHREADPRIVATE, $1, NULL)); TODO
    }
#line 4412 "parser.c"
    break;

  case 98:
#line 1090 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4420 "parser.c"
    break;

  case 99:
#line 1094 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4428 "parser.c"
    break;

  case 100:
#line 1098 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4436 "parser.c"
    break;

  case 101:
#line 1102 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4444 "parser.c"
    break;

  case 102:
#line 1106 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4452 "parser.c"
    break;

  case 103:
#line 1110 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4460 "parser.c"
    break;

  case 104:
#line 1114 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4468 "parser.c"
    break;

  case 105:
#line 1118 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4476 "parser.c"
    break;

  case 106:
#line 1126 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4484 "parser.c"
    break;

  case 107:
#line 1130 "parser.y"
    {
      (yyval.decl) = DeclList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 4492 "parser.c"
    break;

  case 108:
#line 1144 "parser.y"
    {
      astdecl s = decl_getidentifier((yyvsp[0].decl));
      int     declkind = decl_getkind((yyvsp[0].decl));
      stentry e;

      if (!isTypedef && declkind == DFUNC && strcmp(s->u.id->name, "main") == 0)
        s->u.id = Symbol(MAIN_NEWNAME);       /* Catch main()'s declaration */
      if (checkDecls)
      {
        e = symtab_put(stab, s->u.id, (isTypedef) ? TYPENAME :
                                       (declkind == DFUNC) ? FUNCNAME : IDNAME);
        e->isarray = (declkind == DARRAY);
      }
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4512 "parser.c"
    break;

  case 109:
#line 1160 "parser.y"
    {
      astdecl s = decl_getidentifier((yyvsp[-1].decl));
      int     declkind = decl_getkind((yyvsp[-1].decl));
      stentry e;

      if (!isTypedef && declkind == DFUNC && strcmp(s->u.id->name, "main") == 0)
        s->u.id = Symbol(MAIN_NEWNAME);         /* Catch main()'s declaration */
      if (checkDecls)
      {
        e = symtab_put(stab, s->u.id, (isTypedef) ? TYPENAME :
                                       (declkind == DFUNC) ? FUNCNAME : IDNAME);
        e->isarray = (declkind == DARRAY);
      }
    }
#line 4531 "parser.c"
    break;

  case 110:
#line 1175 "parser.y"
    {
      (yyval.decl) = InitDecl((yyvsp[-3].decl), (yyvsp[0].expr));
    }
#line 4539 "parser.c"
    break;

  case 111:
#line 1183 "parser.y"
    {
      (yyval.spec) = StClassSpec(SPEC_typedef);    /* Just a string */
      isTypedef = 1;
    }
#line 4548 "parser.c"
    break;

  case 112:
#line 1188 "parser.y"
    {
      (yyval.spec) = StClassSpec(SPEC_extern);
    }
#line 4556 "parser.c"
    break;

  case 113:
#line 1192 "parser.y"
    {
      (yyval.spec) = StClassSpec(SPEC_static);
    }
#line 4564 "parser.c"
    break;

  case 114:
#line 1196 "parser.y"
    {
      (yyval.spec) = StClassSpec(SPEC_auto);
    }
#line 4572 "parser.c"
    break;

  case 115:
#line 1200 "parser.y"
    {
      (yyval.spec) = StClassSpec(SPEC_register);
    }
#line 4580 "parser.c"
    break;

  case 116:
#line 1208 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_void);
    }
#line 4588 "parser.c"
    break;

  case 117:
#line 1212 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_char);
    }
#line 4596 "parser.c"
    break;

  case 118:
#line 1216 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_short);
    }
#line 4604 "parser.c"
    break;

  case 119:
#line 1220 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_int);
    }
#line 4612 "parser.c"
    break;

  case 120:
#line 1224 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_long);
    }
#line 4620 "parser.c"
    break;

  case 121:
#line 1228 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_float);
    }
#line 4628 "parser.c"
    break;

  case 122:
#line 1232 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_double);
    }
#line 4636 "parser.c"
    break;

  case 123:
#line 1236 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_signed);
    }
#line 4644 "parser.c"
    break;

  case 124:
#line 1240 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_unsigned);
    }
#line 4652 "parser.c"
    break;

  case 125:
#line 1244 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_ubool);
    }
#line 4660 "parser.c"
    break;

  case 126:
#line 1248 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_ucomplex);
    }
#line 4668 "parser.c"
    break;

  case 127:
#line 1252 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_uimaginary);
    }
#line 4676 "parser.c"
    break;

  case 128:
#line 1256 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4684 "parser.c"
    break;

  case 129:
#line 1260 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4692 "parser.c"
    break;

  case 130:
#line 1264 "parser.y"
    {
      (yyval.spec) = Usertype((yyvsp[0].symb));
    }
#line 4700 "parser.c"
    break;

  case 131:
#line 1272 "parser.y"
    {
      (yyval.spec) = SUdecl((yyvsp[-3].type), NULL, (yyvsp[-1].decl));
    }
#line 4708 "parser.c"
    break;

  case 132:
#line 1276 "parser.y"
    {
      (yyval.spec) = SUdecl((yyvsp[-2].type), NULL, NULL);
    }
#line 4716 "parser.c"
    break;

  case 133:
#line 1280 "parser.y"
    {
      symbol s = Symbol((yyvsp[-3].name));
      /* Well, struct & union names have their own name space, and
       * their own scopes. I.e. they can be re-declare in nested
       * scopes. We don't do any kind of duplicate checks.
       */
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-4].type), s, (yyvsp[-1].decl));
    }
#line 4731 "parser.c"
    break;

  case 134:
#line 1295 "parser.y"
    {
      symbol s = (yyvsp[-3].symb);
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-4].type), s, (yyvsp[-1].decl));
    }
#line 4742 "parser.c"
    break;

  case 135:
#line 1302 "parser.y"
    {
      symbol s = Symbol((yyvsp[0].name));
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-1].type), s, NULL);
    }
#line 4753 "parser.c"
    break;

  case 136:
#line 1309 "parser.y"
    {
      symbol s = (yyvsp[0].symb);
      if (checkDecls)
        symtab_put(stab, s, SUNAME);
      (yyval.spec) = SUdecl((yyvsp[-1].type), s, NULL);
    }
#line 4764 "parser.c"
    break;

  case 137:
#line 1320 "parser.y"
    {
      (yyval.type) = SPEC_struct;
    }
#line 4772 "parser.c"
    break;

  case 138:
#line 1324 "parser.y"
    {
      (yyval.type) = SPEC_union;
    }
#line 4780 "parser.c"
    break;

  case 139:
#line 1332 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4788 "parser.c"
    break;

  case 140:
#line 1336 "parser.y"
    {
      (yyval.decl) = StructfieldList((yyvsp[-1].decl), (yyvsp[0].decl));
    }
#line 4796 "parser.c"
    break;

  case 141:
#line 1344 "parser.y"
    {
      (yyval.decl) = StructfieldDecl((yyvsp[-2].spec), (yyvsp[-1].decl));
    }
#line 4804 "parser.c"
    break;

  case 142:
#line 1348 "parser.y"
    {
      (yyval.decl) = StructfieldDecl((yyvsp[-1].spec), NULL);
    }
#line 4812 "parser.c"
    break;

  case 143:
#line 1356 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4820 "parser.c"
    break;

  case 144:
#line 1360 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4828 "parser.c"
    break;

  case 145:
#line 1364 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4836 "parser.c"
    break;

  case 146:
#line 1368 "parser.y"
    {
      (yyval.spec) = Speclist_right((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 4844 "parser.c"
    break;

  case 147:
#line 1376 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4852 "parser.c"
    break;

  case 148:
#line 1380 "parser.y"
    {
      (yyval.decl) = DeclList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 4860 "parser.c"
    break;

  case 149:
#line 1388 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 4868 "parser.c"
    break;

  case 150:
#line 1392 "parser.y"
    {
      (yyval.decl) = BitDecl((yyvsp[-2].decl), (yyvsp[0].expr));
    }
#line 4876 "parser.c"
    break;

  case 151:
#line 1396 "parser.y"
    {
      (yyval.decl) = BitDecl(NULL, (yyvsp[0].expr));
    }
#line 4884 "parser.c"
    break;

  case 152:
#line 1404 "parser.y"
    {
      (yyval.spec) = Enumdecl(NULL, (yyvsp[-1].spec));
    }
#line 4892 "parser.c"
    break;

  case 153:
#line 1408 "parser.y"
    {
      symbol s = Symbol((yyvsp[-3].name));

      if (checkDecls)
      {
        if (symtab_get(stab, s, ENUMNAME))
          parse_error(-1, "enum name '%s' is already in use.", (yyvsp[-3].name));
        symtab_put(stab, s, ENUMNAME);
      }
      (yyval.spec) = Enumdecl(s, (yyvsp[-1].spec));
    }
#line 4908 "parser.c"
    break;

  case 154:
#line 1420 "parser.y"
    {
      (yyval.spec) = Enumdecl(NULL, (yyvsp[-2].spec));
    }
#line 4916 "parser.c"
    break;

  case 155:
#line 1424 "parser.y"
    {
      symbol s = Symbol((yyvsp[-4].name));

      if (checkDecls)
      {
        if (symtab_get(stab, s, ENUMNAME))
          parse_error(-1, "enum name '%s' is already in use.", (yyvsp[-4].name));
        symtab_put(stab, s, ENUMNAME);
      }
      (yyval.spec) = Enumdecl(s, (yyvsp[-2].spec));
    }
#line 4932 "parser.c"
    break;

  case 156:
#line 1436 "parser.y"
    {
      /*
      if (symtab_get(stab, s, ENUMNAME))
        parse_error(-1, "enum name '%s' is unknown.", $2);
      */
      (yyval.spec) = Enumdecl(Symbol((yyvsp[0].name)), NULL);
    }
#line 4944 "parser.c"
    break;

  case 157:
#line 1448 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 4952 "parser.c"
    break;

  case 158:
#line 1452 "parser.y"
    {
      (yyval.spec) = Enumbodylist((yyvsp[-2].spec), (yyvsp[0].spec));
    }
#line 4960 "parser.c"
    break;

  case 159:
#line 1460 "parser.y"
    {
      (yyval.spec) = Enumerator((yyvsp[0].symb), NULL);
    }
#line 4968 "parser.c"
    break;

  case 160:
#line 1464 "parser.y"
    {
      (yyval.spec) = Enumerator((yyvsp[-2].symb), (yyvsp[0].expr));
    }
#line 4976 "parser.c"
    break;

  case 161:
#line 1472 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_const);
    }
#line 4984 "parser.c"
    break;

  case 162:
#line 1476 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_restrict);
    }
#line 4992 "parser.c"
    break;

  case 163:
#line 1480 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_volatile);
    }
#line 5000 "parser.c"
    break;

  case 164:
#line 1488 "parser.y"
    {
      (yyval.spec) = Declspec(SPEC_inline);
    }
#line 5008 "parser.c"
    break;

  case 165:
#line 1496 "parser.y"
    {
      (yyval.decl) = Declarator(NULL, (yyvsp[0].decl));
    }
#line 5016 "parser.c"
    break;

  case 166:
#line 1500 "parser.y"
    {
      (yyval.decl) = Declarator((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5024 "parser.c"
    break;

  case 167:
#line 1513 "parser.y"
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 5032 "parser.c"
    break;

  case 168:
#line 1517 "parser.y"
    {
      /* Try to simplify a bit: (ident) -> ident */
      if ((yyvsp[-1].decl)->spec == NULL && (yyvsp[-1].decl)->decl->type == DIDENT)
        (yyval.decl) = (yyvsp[-1].decl)->decl;
      else
        (yyval.decl) = ParenDecl((yyvsp[-1].decl));
    }
#line 5044 "parser.c"
    break;

  case 169:
#line 1525 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-2].decl), NULL, NULL);
    }
#line 5052 "parser.c"
    break;

  case 170:
#line 1529 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), (yyvsp[-1].spec), NULL);
    }
#line 5060 "parser.c"
    break;

  case 171:
#line 1533 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), NULL, (yyvsp[-1].expr));
    }
#line 5068 "parser.c"
    break;

  case 172:
#line 1537 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), (yyvsp[-2].spec), (yyvsp[-1].expr));
    }
#line 5076 "parser.c"
    break;

  case 173:
#line 1541 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), StClassSpec(SPEC_static), (yyvsp[-1].expr));
    }
#line 5084 "parser.c"
    break;

  case 174:
#line 1545 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-5].decl), Speclist_right( StClassSpec(SPEC_static), (yyvsp[-2].spec) ), (yyvsp[-1].expr));
    }
#line 5092 "parser.c"
    break;

  case 175:
#line 1549 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-5].decl), Speclist_left( (yyvsp[-3].spec), StClassSpec(SPEC_static) ), (yyvsp[-1].expr));
    }
#line 5100 "parser.c"
    break;

  case 176:
#line 1553 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), Declspec(SPEC_star), NULL);
    }
#line 5108 "parser.c"
    break;

  case 177:
#line 1557 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-4].decl), Speclist_left( (yyvsp[-2].spec), Declspec(SPEC_star) ), NULL);
    }
#line 5116 "parser.c"
    break;

  case 178:
#line 1561 "parser.y"
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5124 "parser.c"
    break;

  case 179:
#line 1565 "parser.y"
    {
      (yyval.decl) = FuncDecl((yyvsp[-2].decl), NULL);
    }
#line 5132 "parser.c"
    break;

  case 180:
#line 1569 "parser.y"
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5140 "parser.c"
    break;

  case 181:
#line 1574 "parser.y"
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-5].decl), DfcMakeVars((yyvsp[-3].decl), (yyvsp[-1].decl)));
    }
#line 5149 "parser.c"
    break;

  case 182:
#line 1579 "parser.y"
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-4].decl), DfcMakeVars(NULL, (yyvsp[-1].decl)));
    }
#line 5158 "parser.c"
    break;

  case 183:
#line 1584 "parser.y"
    {
      __has_dfc = 1;
      (yyval.decl) = DfcFuncDecl((yyvsp[-4].decl), DfcMakeVars((yyvsp[-2].decl), NULL));
    }
#line 5167 "parser.c"
    break;

  case 184:
#line 1589 "parser.y"
    {
      (yyval.decl) = DfcFuncDecl((yyvsp[-3].decl), DfcMakeVars(NULL, NULL));
    }
#line 5175 "parser.c"
    break;

  case 185:
#line 1597 "parser.y"
    {
      (yyval.spec) = Pointer();
    }
#line 5183 "parser.c"
    break;

  case 186:
#line 1601 "parser.y"
    {
      (yyval.spec) = Speclist_right(Pointer(), (yyvsp[0].spec));
    }
#line 5191 "parser.c"
    break;

  case 187:
#line 1605 "parser.y"
    {
      (yyval.spec) = Speclist_right(Pointer(), (yyvsp[0].spec));
    }
#line 5199 "parser.c"
    break;

  case 188:
#line 1609 "parser.y"
    {
      (yyval.spec) = Speclist_right( Pointer(), Speclist_left((yyvsp[-1].spec), (yyvsp[0].spec)) );
    }
#line 5207 "parser.c"
    break;

  case 189:
#line 1617 "parser.y"
    {
      (yyval.spec) = (yyvsp[0].spec);
    }
#line 5215 "parser.c"
    break;

  case 190:
#line 1621 "parser.y"
    {
      (yyval.spec) = Speclist_left((yyvsp[-1].spec), (yyvsp[0].spec));
    }
#line 5223 "parser.c"
    break;

  case 191:
#line 1629 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 5231 "parser.c"
    break;

  case 192:
#line 1633 "parser.y"
    {
      (yyval.decl) = ParamList((yyvsp[-2].decl), Ellipsis());
    }
#line 5239 "parser.c"
    break;

  case 193:
#line 1641 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 5247 "parser.c"
    break;

  case 194:
#line 1645 "parser.y"
    {
      (yyval.decl) = ParamList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 5255 "parser.c"
    break;

  case 195:
#line 1653 "parser.y"
    {
      (yyval.decl) = ParamDecl((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5263 "parser.c"
    break;

  case 196:
#line 1657 "parser.y"
    {
      (yyval.decl) = ParamDecl((yyvsp[0].spec), NULL);
    }
#line 5271 "parser.c"
    break;

  case 197:
#line 1661 "parser.y"
    {
      (yyval.decl) = ParamDecl((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5279 "parser.c"
    break;

  case 198:
#line 1669 "parser.y"
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 5287 "parser.c"
    break;

  case 199:
#line 1673 "parser.y"
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 5295 "parser.c"
    break;

  case 200:
#line 1681 "parser.y"
    {
      (yyval.decl) = Casttypename((yyvsp[0].spec), NULL);
    }
#line 5303 "parser.c"
    break;

  case 201:
#line 1685 "parser.y"
    {
      (yyval.decl) = Casttypename((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5311 "parser.c"
    break;

  case 202:
#line 1693 "parser.y"
    {
      (yyval.decl) = AbstractDeclarator((yyvsp[0].spec), NULL);
    }
#line 5319 "parser.c"
    break;

  case 203:
#line 1697 "parser.y"
    {
      (yyval.decl) = AbstractDeclarator(NULL, (yyvsp[0].decl));
    }
#line 5327 "parser.c"
    break;

  case 204:
#line 1701 "parser.y"
    {
      (yyval.decl) = AbstractDeclarator((yyvsp[-1].spec), (yyvsp[0].decl));
    }
#line 5335 "parser.c"
    break;

  case 205:
#line 1709 "parser.y"
    {
      (yyval.decl) = ParenDecl((yyvsp[-1].decl));
    }
#line 5343 "parser.c"
    break;

  case 206:
#line 1713 "parser.y"
    {
      (yyval.decl) = ArrayDecl(NULL, NULL, NULL);
    }
#line 5351 "parser.c"
    break;

  case 207:
#line 1717 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-2].decl), NULL, NULL);
    }
#line 5359 "parser.c"
    break;

  case 208:
#line 1721 "parser.y"
    {
      (yyval.decl) = ArrayDecl(NULL, NULL, (yyvsp[-1].expr));
    }
#line 5367 "parser.c"
    break;

  case 209:
#line 1725 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), NULL, (yyvsp[-1].expr));
    }
#line 5375 "parser.c"
    break;

  case 210:
#line 1729 "parser.y"
    {
      (yyval.decl) = ArrayDecl(NULL, Declspec(SPEC_star), NULL);
    }
#line 5383 "parser.c"
    break;

  case 211:
#line 1733 "parser.y"
    {
      (yyval.decl) = ArrayDecl((yyvsp[-3].decl), Declspec(SPEC_star), NULL);
    }
#line 5391 "parser.c"
    break;

  case 212:
#line 1737 "parser.y"
    {
      (yyval.decl) = FuncDecl(NULL, NULL);
    }
#line 5399 "parser.c"
    break;

  case 213:
#line 1741 "parser.y"
    {
      (yyval.decl) = FuncDecl((yyvsp[-2].decl), NULL);
    }
#line 5407 "parser.c"
    break;

  case 214:
#line 1745 "parser.y"
    {
      (yyval.decl) = FuncDecl(NULL, (yyvsp[-1].decl));
    }
#line 5415 "parser.c"
    break;

  case 215:
#line 1749 "parser.y"
    {
      (yyval.decl) = FuncDecl((yyvsp[-3].decl), (yyvsp[-1].decl));
    }
#line 5423 "parser.c"
    break;

  case 216:
#line 1757 "parser.y"
    {
      (yyval.symb) = Symbol((yyvsp[0].name));
    }
#line 5431 "parser.c"
    break;

  case 217:
#line 1765 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5439 "parser.c"
    break;

  case 218:
#line 1769 "parser.y"
    {
      (yyval.expr) = BracedInitializer((yyvsp[-1].expr));
    }
#line 5447 "parser.c"
    break;

  case 219:
#line 1773 "parser.y"
    {
      (yyval.expr) = BracedInitializer((yyvsp[-2].expr));
    }
#line 5455 "parser.c"
    break;

  case 220:
#line 1781 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5463 "parser.c"
    break;

  case 221:
#line 1785 "parser.y"
    {
      (yyval.expr) = Designated((yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 5471 "parser.c"
    break;

  case 222:
#line 1789 "parser.y"
    {
      (yyval.expr) = CommaList((yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 5479 "parser.c"
    break;

  case 223:
#line 1793 "parser.y"
    {
      (yyval.expr) = CommaList((yyvsp[-3].expr), Designated((yyvsp[-1].expr), (yyvsp[0].expr)));
    }
#line 5487 "parser.c"
    break;

  case 224:
#line 1801 "parser.y"
    {
      (yyval.expr) = (yyvsp[-1].expr);
    }
#line 5495 "parser.c"
    break;

  case 225:
#line 1809 "parser.y"
    {
      (yyval.expr) = (yyvsp[0].expr);
    }
#line 5503 "parser.c"
    break;

  case 226:
#line 1813 "parser.y"
    {
      (yyval.expr) = SpaceList((yyvsp[-1].expr), (yyvsp[0].expr));
    }
#line 5511 "parser.c"
    break;

  case 227:
#line 1821 "parser.y"
    {
      (yyval.expr) = IdxDesignator((yyvsp[-1].expr));
    }
#line 5519 "parser.c"
    break;

  case 228:
#line 1825 "parser.y"
    {
      (yyval.expr) = DotDesignator( Symbol((yyvsp[0].name)) );
    }
#line 5527 "parser.c"
    break;

  case 229:
#line 1829 "parser.y"
    {
      (yyval.expr) = DotDesignator((yyvsp[0].symb));
    }
#line 5535 "parser.c"
    break;

  case 230:
#line 1843 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5543 "parser.c"
    break;

  case 231:
#line 1847 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5551 "parser.c"
    break;

  case 232:
#line 1851 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5559 "parser.c"
    break;

  case 233:
#line 1855 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5567 "parser.c"
    break;

  case 234:
#line 1859 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5575 "parser.c"
    break;

  case 235:
#line 1863 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5583 "parser.c"
    break;

  case 236:
#line 1867 "parser.y"
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5592 "parser.c"
    break;

  case 237:
#line 1872 "parser.y"
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
      (yyval.stmt)->l = (yyvsp[0].xcon)->l;
    }
#line 5601 "parser.c"
    break;

  case 238:
#line 1881 "parser.y"
    { 
      (yyval.stmt) = (yyvsp[0].stmt); 
    }
#line 5609 "parser.c"
    break;

  case 239:
#line 1885 "parser.y"
    {       
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5618 "parser.c"
    break;

  case 240:
#line 1895 "parser.y"
    {
      (yyval.stmt) = Labeled( Symbol((yyvsp[-2].name)), (yyvsp[0].stmt) );
    }
#line 5626 "parser.c"
    break;

  case 241:
#line 1899 "parser.y"
    {
      (yyval.stmt) = Case((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5634 "parser.c"
    break;

  case 242:
#line 1903 "parser.y"
    {
      (yyval.stmt) = Default((yyvsp[0].stmt));
    }
#line 5642 "parser.c"
    break;

  case 243:
#line 1911 "parser.y"
    {
      (yyval.stmt) = Compound(NULL);
    }
#line 5650 "parser.c"
    break;

  case 244:
#line 1914 "parser.y"
         { (yyval.type) = sc_original_line()-1; scope_start(stab); }
#line 5656 "parser.c"
    break;

  case 245:
#line 1916 "parser.y"
    {
      (yyval.stmt) = Compound((yyvsp[-1].stmt));
      scope_end(stab);
      (yyval.stmt)->l = (yyvsp[-2].type);     /* Remember 1st line */
    }
#line 5666 "parser.c"
    break;

  case 246:
#line 1926 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5674 "parser.c"
    break;

  case 247:
#line 1930 "parser.y"
    {
      (yyval.stmt) = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
      (yyval.stmt)->l = (yyvsp[-1].stmt)->l;
    }
#line 5683 "parser.c"
    break;

  case 248:
#line 1939 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5691 "parser.c"
    break;

  case 249:
#line 1943 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5699 "parser.c"
    break;

  case 250:
#line 1947 "parser.y"
    {
      (yyval.stmt) = OmpStmt((yyvsp[0].ocon));
      (yyval.stmt)->l = (yyvsp[0].ocon)->l;
    }
#line 5708 "parser.c"
    break;

  case 251:
#line 1952 "parser.y"
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
      (yyval.stmt)->l = (yyvsp[0].xcon)->l;
    }
#line 5717 "parser.c"
    break;

  case 252:
#line 1961 "parser.y"
    {
      (yyval.stmt) = Expression(NULL);
    }
#line 5725 "parser.c"
    break;

  case 253:
#line 1965 "parser.y"
    {
      (yyval.stmt) = Expression((yyvsp[-1].expr));
      (yyval.stmt)->l = (yyvsp[-1].expr)->l;
    }
#line 5734 "parser.c"
    break;

  case 254:
#line 1974 "parser.y"
    {
      (yyval.stmt) = If((yyvsp[-2].expr), (yyvsp[0].stmt), NULL);
    }
#line 5742 "parser.c"
    break;

  case 255:
#line 1978 "parser.y"
    {
      (yyval.stmt) = If((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
    }
#line 5750 "parser.c"
    break;

  case 256:
#line 1982 "parser.y"
    {
      (yyval.stmt) = Switch((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5758 "parser.c"
    break;

  case 257:
#line 1991 "parser.y"
    {
      (yyval.stmt) = While((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5766 "parser.c"
    break;

  case 258:
#line 1995 "parser.y"
    {
      (yyval.stmt) = Do((yyvsp[-5].stmt), (yyvsp[-2].expr));
    }
#line 5774 "parser.c"
    break;

  case 260:
#line 2003 "parser.y"
    {
      (yyval.stmt) = For(NULL, NULL, NULL, (yyvsp[0].stmt));
    }
#line 5782 "parser.c"
    break;

  case 261:
#line 2007 "parser.y"
    {
      (yyval.stmt) = For(Expression((yyvsp[-4].expr)), NULL, NULL, (yyvsp[0].stmt));
    }
#line 5790 "parser.c"
    break;

  case 262:
#line 2011 "parser.y"
    {
      (yyval.stmt) = For(NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5798 "parser.c"
    break;

  case 263:
#line 2015 "parser.y"
    {
      (yyval.stmt) = For(NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5806 "parser.c"
    break;

  case 264:
#line 2019 "parser.y"
    {
      (yyval.stmt) = For(Expression((yyvsp[-5].expr)), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5814 "parser.c"
    break;

  case 265:
#line 2023 "parser.y"
    {
      (yyval.stmt) = For(Expression((yyvsp[-5].expr)), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5822 "parser.c"
    break;

  case 266:
#line 2027 "parser.y"
    {
      (yyval.stmt) = For(NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5830 "parser.c"
    break;

  case 267:
#line 2031 "parser.y"
    {
      (yyval.stmt) = For(Expression((yyvsp[-6].expr)), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5838 "parser.c"
    break;

  case 268:
#line 2035 "parser.y"
    {
      (yyval.stmt) = For((yyvsp[-3].stmt), NULL, NULL, (yyvsp[0].stmt));
    }
#line 5846 "parser.c"
    break;

  case 269:
#line 2039 "parser.y"
    {
      (yyval.stmt) = For((yyvsp[-4].stmt), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt));
    }
#line 5854 "parser.c"
    break;

  case 270:
#line 2043 "parser.y"
    {
      (yyval.stmt) = For((yyvsp[-4].stmt), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5862 "parser.c"
    break;

  case 271:
#line 2047 "parser.y"
    {
      (yyval.stmt) = For((yyvsp[-5].stmt), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 5870 "parser.c"
    break;

  case 272:
#line 2055 "parser.y"
    {
      /* We don't keep track of labels -- we leave it to the native compiler */
      (yyval.stmt) = Goto( Symbol((yyvsp[-1].name)) );
    }
#line 5879 "parser.c"
    break;

  case 273:
#line 2060 "parser.y"
    {
      (yyval.stmt) = Continue();
    }
#line 5887 "parser.c"
    break;

  case 274:
#line 2064 "parser.y"
    {
      (yyval.stmt) = Break();
    }
#line 5895 "parser.c"
    break;

  case 275:
#line 2068 "parser.y"
    {
      //TODO: simple hack, not 100% correct, does not cover goto
      if (errorOnReturn)
        parse_error(1, "return statement not allowed in an outlined region\n");
      (yyval.stmt) = Return(NULL);
    }
#line 5906 "parser.c"
    break;

  case 276:
#line 2075 "parser.y"
    {
      //TODO: simple hack, not 100% correct, does not cover goto
      if (errorOnReturn)
        parse_error(1, "return statement not allowed in an outlined region\n");
      (yyval.stmt) = Return((yyvsp[-1].expr));
    }
#line 5917 "parser.c"
    break;

  case 277:
#line 2092 "parser.y"
    {
      (yyval.stmt) = pastree = (yyvsp[0].stmt);
    }
#line 5925 "parser.c"
    break;

  case 278:
#line 2096 "parser.y"
    {
      (yyval.stmt) = pastree = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 5933 "parser.c"
    break;

  case 279:
#line 2104 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5941 "parser.c"
    break;

  case 280:
#line 2108 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 5949 "parser.c"
    break;

  case 281:
#line 2115 "parser.y"
    {
      (yyval.stmt) = OmpixStmt((yyvsp[0].xcon));
    }
#line 5957 "parser.c"
    break;

  case 282:
#line 2126 "parser.y"
                                 { (yyval.stmt) = (yyvsp[0].stmt); }
#line 5963 "parser.c"
    break;

  case 283:
#line 2127 "parser.y"
                                 { (yyval.stmt) = (yyvsp[0].stmt); }
#line 5969 "parser.c"
    break;

  case 284:
#line 2132 "parser.y"
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      ast_declare_function_params((yyvsp[0].decl));
    }
#line 5984 "parser.c"
    break;

  case 285:
#line 2143 "parser.y"
    {
      scope_end(stab);
        
      if( (yyvsp[-2].decl)->decl->type == DFUNC)
      {
        check_for_main_and_declare((yyvsp[-3].spec), (yyvsp[-2].decl));
        (yyval.stmt) = FuncDef((yyvsp[-3].spec), (yyvsp[-2].decl), NULL, (yyvsp[0].stmt));
      }
      else /* DDFCFUNC */
      {
        char *func_name = decl_getidentifier((yyvsp[-2].decl))->u.id->name;
        aststmt body = Verbatim(strdup("{"));
        
        struct dfc_insert_detail detail = {};
        detail.body = body;
        detail.inParams = (yyvsp[-2].decl)->decl->u.dfcvars->inParams;
        detail.outParams = (yyvsp[-2].decl)->decl->u.dfcvars->outParams;
        detail.func_name = func_name;
        
        dfc_insert_active_data_decl_and_update_persize(&detail);
        dfc_insert_get_active_data_call(&detail);
        dfc_insert_get_item_index(&detail,func_name);
        detail.body = BlockList(detail.body, (yyvsp[0].stmt));
        dfc_insert_update_active_data_call(&detail);
        
        detail.body = BlockList(detail.body, Verbatim(strdup("\n}")));

        (yyval.stmt) = FuncDef((yyvsp[-3].spec), (yyvsp[-2].decl), NULL, detail.body);

        // NOTE(luobin): It's convenient to prepare for 'append_new_main()' here.
        dfc_use_detail_to_fill_main_ad_and_fn_init(&detail);
      }
    }
#line 6022 "parser.c"
    break;

  case 286:
#line 2177 "parser.y"
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      ast_declare_function_params((yyvsp[0].decl));
    }
#line 6037 "parser.c"
    break;

  case 287:
#line 2188 "parser.y"
    {
      astspec s = Declspec(SPEC_int);  /* return type defaults to "int" */

      scope_end(stab);
      check_for_main_and_declare(s, (yyvsp[-2].decl));
      (yyval.stmt) = FuncDef(s, (yyvsp[-2].decl), NULL, (yyvsp[0].stmt));
    }
#line 6049 "parser.c"
    break;

  case 288:
#line 2199 "parser.y"
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      /* Notice here that the function parameters are declared through
       * the declaration_list and we need to do nothing else!
       */
    }
#line 6066 "parser.c"
    break;

  case 289:
#line 2212 "parser.y"
    {
      scope_end(stab);
      check_for_main_and_declare((yyvsp[-4].spec), (yyvsp[-3].decl));
      (yyval.stmt) = FuncDef((yyvsp[-4].spec), (yyvsp[-3].decl), (yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 6076 "parser.c"
    break;

  case 290:
#line 2218 "parser.y"
    {
      if (isTypedef ||
          ((yyvsp[0].decl)->decl->type != DFUNC && /* DF-C function */ (yyvsp[0].decl)->decl->type != DDFCFUNC))
        parse_error(1, "function definition cannot be parsed.\n");
      if (symtab_get(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol((yyvsp[0].decl)), FUNCNAME);

      scope_start(stab);
      /* Notice here that the function parameters are declared through
       * the declaration_list and we need to do nothing else!
       */
    }
#line 6093 "parser.c"
    break;

  case 291:
#line 2231 "parser.y"
    {
      astspec s = Declspec(SPEC_int);  /* return type defaults to "int" */

      scope_end(stab);
      check_for_main_and_declare(s, (yyvsp[-3].decl));
      (yyval.stmt) = FuncDef(s, (yyvsp[-3].decl), (yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 6105 "parser.c"
    break;

  case 292:
#line 2243 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6113 "parser.c"
    break;

  case 293:
#line 2247 "parser.y"
    {
      (yyval.stmt) = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));         /* Same as block list */
    }
#line 6121 "parser.c"
    break;

  case 294:
#line 2262 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6129 "parser.c"
    break;

  case 295:
#line 2266 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6137 "parser.c"
    break;

  case 296:
#line 2274 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6145 "parser.c"
    break;

  case 297:
#line 2283 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6153 "parser.c"
    break;

  case 298:
#line 2287 "parser.y"
    {
      (yyval.stmt) = pastree = BlockList((yyvsp[-1].stmt), (yyvsp[0].stmt));
    }
#line 6161 "parser.c"
    break;

  case 299:
#line 2294 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6169 "parser.c"
    break;

  case 300:
#line 2298 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6177 "parser.c"
    break;

  case 301:
#line 2302 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6185 "parser.c"
    break;

  case 302:
#line 2306 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6193 "parser.c"
    break;

  case 303:
#line 2310 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6201 "parser.c"
    break;

  case 304:
#line 2314 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6209 "parser.c"
    break;

  case 305:
#line 2318 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6217 "parser.c"
    break;

  case 306:
#line 2322 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6225 "parser.c"
    break;

  case 307:
#line 2326 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6233 "parser.c"
    break;

  case 308:
#line 2330 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6241 "parser.c"
    break;

  case 309:
#line 2335 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6249 "parser.c"
    break;

  case 310:
#line 2340 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6257 "parser.c"
    break;

  case 311:
#line 2344 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6265 "parser.c"
    break;

  case 312:
#line 2348 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6273 "parser.c"
    break;

  case 313:
#line 2352 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6281 "parser.c"
    break;

  case 314:
#line 2356 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6289 "parser.c"
    break;

  case 315:
#line 2360 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6297 "parser.c"
    break;

  case 316:
#line 2364 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6305 "parser.c"
    break;

  case 317:
#line 2368 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6313 "parser.c"
    break;

  case 318:
#line 2372 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6321 "parser.c"
    break;

  case 319:
#line 2376 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6329 "parser.c"
    break;

  case 320:
#line 2380 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6337 "parser.c"
    break;

  case 321:
#line 2384 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6345 "parser.c"
    break;

  case 322:
#line 2388 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6353 "parser.c"
    break;

  case 323:
#line 2392 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6361 "parser.c"
    break;

  case 324:
#line 2396 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6369 "parser.c"
    break;

  case 325:
#line 2400 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6377 "parser.c"
    break;

  case 326:
#line 2404 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6385 "parser.c"
    break;

  case 327:
#line 2408 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6393 "parser.c"
    break;

  case 328:
#line 2412 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6401 "parser.c"
    break;

  case 329:
#line 2416 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6409 "parser.c"
    break;

  case 330:
#line 2421 "parser.y"
    {
      (yyval.ocon) = (yyvsp[0].ocon);
    }
#line 6417 "parser.c"
    break;

  case 331:
#line 2437 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCBARRIER, (yyvsp[0].odir), NULL);
    }
#line 6425 "parser.c"
    break;

  case 332:
#line 2441 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCFLUSH, (yyvsp[0].odir), NULL);
    }
#line 6433 "parser.c"
    break;

  case 333:
#line 2446 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTASKWAIT, (yyvsp[0].odir), NULL);
    }
#line 6441 "parser.c"
    break;

  case 334:
#line 2451 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTASKYIELD, (yyvsp[0].odir), NULL);
    }
#line 6449 "parser.c"
    break;

  case 335:
#line 2456 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCCANCEL, (yyvsp[0].odir), NULL);
    }
#line 6457 "parser.c"
    break;

  case 336:
#line 2461 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCCANCELLATIONPOINT, (yyvsp[0].odir), NULL);
    }
#line 6465 "parser.c"
    break;

  case 337:
#line 2468 "parser.y"
    {
      (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 6473 "parser.c"
    break;

  case 338:
#line 2475 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCPARALLEL, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 6482 "parser.c"
    break;

  case 339:
#line 2483 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCPARALLEL, (yyvsp[-1].ocla));
    }
#line 6490 "parser.c"
    break;

  case 340:
#line 2490 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 6498 "parser.c"
    break;

  case 341:
#line 2494 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6506 "parser.c"
    break;

  case 342:
#line 2498 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6514 "parser.c"
    break;

  case 343:
#line 2505 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6522 "parser.c"
    break;

  case 344:
#line 2509 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6530 "parser.c"
    break;

  case 345:
#line 2513 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6538 "parser.c"
    break;

  case 346:
#line 2517 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6546 "parser.c"
    break;

  case 347:
#line 2521 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6554 "parser.c"
    break;

  case 348:
#line 2525 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6562 "parser.c"
    break;

  case 349:
#line 2532 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6570 "parser.c"
    break;

  case 350:
#line 2535 "parser.y"
                       { sc_pause_openmp(); }
#line 6576 "parser.c"
    break;

  case 351:
#line 2536 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = NumthreadsClause((yyvsp[-1].expr));
    }
#line 6585 "parser.c"
    break;

  case 352:
#line 2540 "parser.y"
               { sc_pause_openmp(); }
#line 6591 "parser.c"
    break;

  case 353:
#line 2541 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCCOPYIN, (yyvsp[-1].decl));
    }
#line 6600 "parser.c"
    break;

  case 354:
#line 2547 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6608 "parser.c"
    break;

  case 355:
#line 2551 "parser.y"
             { sc_pause_openmp(); }
#line 6614 "parser.c"
    break;

  case 356:
#line 2552 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCAUTO, (yyvsp[-1].decl));
    }
#line 6623 "parser.c"
    break;

  case 357:
#line 2560 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCFOR, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6631 "parser.c"
    break;

  case 358:
#line 2567 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCFOR, (yyvsp[-1].ocla));
    }
#line 6639 "parser.c"
    break;

  case 359:
#line 2574 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 6647 "parser.c"
    break;

  case 360:
#line 2578 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6655 "parser.c"
    break;

  case 361:
#line 2582 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6663 "parser.c"
    break;

  case 362:
#line 2589 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6671 "parser.c"
    break;

  case 363:
#line 2593 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6679 "parser.c"
    break;

  case 364:
#line 2597 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6687 "parser.c"
    break;

  case 365:
#line 2601 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6695 "parser.c"
    break;

  case 366:
#line 2605 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6703 "parser.c"
    break;

  case 367:
#line 2609 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 6711 "parser.c"
    break;

  case 368:
#line 2616 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCORDERED);
    }
#line 6719 "parser.c"
    break;

  case 369:
#line 2620 "parser.y"
    {
      (yyval.ocla) = ScheduleClause((yyvsp[-1].type), NULL);
    }
#line 6727 "parser.c"
    break;

  case 370:
#line 2623 "parser.y"
                                       { sc_pause_openmp(); }
#line 6733 "parser.c"
    break;

  case 371:
#line 2624 "parser.y"
    {
      sc_start_openmp();
      if ((yyvsp[-4].type) == OC_runtime)
        parse_error(1, "\"runtime\" schedules may not have a chunksize.\n");
      (yyval.ocla) = ScheduleClause((yyvsp[-4].type), (yyvsp[-1].expr));
    }
#line 6744 "parser.c"
    break;

  case 372:
#line 2631 "parser.y"
    {  /* non-OpenMP schedule */
      tempsave = checkDecls;
      checkDecls = 0;   /* Because the index of the loop is usualy involved */
      sc_pause_openmp();
    }
#line 6754 "parser.c"
    break;

  case 373:
#line 2637 "parser.y"
    {
      sc_start_openmp();
      checkDecls = tempsave;
      (yyval.ocla) = ScheduleClause(OC_affinity, (yyvsp[-1].expr));
    }
#line 6764 "parser.c"
    break;

  case 374:
#line 2643 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6772 "parser.c"
    break;

  case 375:
#line 2650 "parser.y"
    {
      (yyval.type) = OC_static;
    }
#line 6780 "parser.c"
    break;

  case 376:
#line 2654 "parser.y"
    {
      (yyval.type) = OC_dynamic;
    }
#line 6788 "parser.c"
    break;

  case 377:
#line 2658 "parser.y"
    {
      (yyval.type) = OC_guided;
    }
#line 6796 "parser.c"
    break;

  case 378:
#line 2662 "parser.y"
    {
      (yyval.type) = OC_runtime;
    }
#line 6804 "parser.c"
    break;

  case 379:
#line 2666 "parser.y"
    {
      (yyval.type) = OC_auto;
    }
#line 6812 "parser.c"
    break;

  case 380:
#line 2669 "parser.y"
          { parse_error(1, "invalid openmp schedule type.\n"); }
#line 6818 "parser.c"
    break;

  case 381:
#line 2675 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCSECTIONS, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6826 "parser.c"
    break;

  case 382:
#line 2682 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCSECTIONS, (yyvsp[-1].ocla));
    }
#line 6834 "parser.c"
    break;

  case 383:
#line 2689 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 6842 "parser.c"
    break;

  case 384:
#line 2693 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6850 "parser.c"
    break;

  case 385:
#line 2697 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6858 "parser.c"
    break;

  case 386:
#line 2704 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6866 "parser.c"
    break;

  case 387:
#line 2708 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6874 "parser.c"
    break;

  case 388:
#line 2712 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6882 "parser.c"
    break;

  case 389:
#line 2716 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6890 "parser.c"
    break;

  case 390:
#line 2720 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 6898 "parser.c"
    break;

  case 391:
#line 2727 "parser.y"
    {
      (yyval.stmt) = Compound((yyvsp[-1].stmt));
    }
#line 6906 "parser.c"
    break;

  case 392:
#line 2734 "parser.y"
    {
      /* Make it look like it had a section pragma */
      (yyval.stmt) = OmpStmt( OmpConstruct(DCSECTION, OmpDirective(DCSECTION,NULL), (yyvsp[0].stmt)) );
    }
#line 6915 "parser.c"
    break;

  case 393:
#line 2739 "parser.y"
    {
      (yyval.stmt) = OmpStmt( OmpConstruct(DCSECTION, (yyvsp[-1].odir), (yyvsp[0].stmt)) );
    }
#line 6923 "parser.c"
    break;

  case 394:
#line 2743 "parser.y"
    {
      (yyval.stmt) = BlockList((yyvsp[-2].stmt), OmpStmt( OmpConstruct(DCSECTION, (yyvsp[-1].odir), (yyvsp[0].stmt)) ));
    }
#line 6931 "parser.c"
    break;

  case 395:
#line 2750 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCSECTION, NULL);
    }
#line 6939 "parser.c"
    break;

  case 396:
#line 2757 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCSINGLE, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 6947 "parser.c"
    break;

  case 397:
#line 2764 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCSINGLE, (yyvsp[-1].ocla));
    }
#line 6955 "parser.c"
    break;

  case 398:
#line 2771 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 6963 "parser.c"
    break;

  case 399:
#line 2775 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 6971 "parser.c"
    break;

  case 400:
#line 2779 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 6979 "parser.c"
    break;

  case 401:
#line 2786 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6987 "parser.c"
    break;

  case 402:
#line 2790 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 6995 "parser.c"
    break;

  case 403:
#line 2794 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7003 "parser.c"
    break;

  case 404:
#line 2798 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCNOWAIT);
    }
#line 7011 "parser.c"
    break;

  case 405:
#line 2804 "parser.y"
                     { sc_pause_openmp(); }
#line 7017 "parser.c"
    break;

  case 406:
#line 2805 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCCOPYPRIVATE, (yyvsp[-1].decl));
    }
#line 7026 "parser.c"
    break;

  case 407:
#line 2814 "parser.y"
    {
      //$$ = OmpConstruct(DCSIMD, $1, $2); TODO DCSIMD
    }
#line 7034 "parser.c"
    break;

  case 408:
#line 2822 "parser.y"
    {
      //$$ = OmpDirective(DCSIMD, $3); TODO DCSIMD
    }
#line 7042 "parser.c"
    break;

  case 409:
#line 2829 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7050 "parser.c"
    break;

  case 410:
#line 2833 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7058 "parser.c"
    break;

  case 411:
#line 2837 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7066 "parser.c"
    break;

  case 412:
#line 2845 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7074 "parser.c"
    break;

  case 413:
#line 2849 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7082 "parser.c"
    break;

  case 414:
#line 2853 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7090 "parser.c"
    break;

  case 415:
#line 2857 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7098 "parser.c"
    break;

  case 416:
#line 2861 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7106 "parser.c"
    break;

  case 417:
#line 2869 "parser.y"
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in simdlen() clause.\n");
      //$$ = CollapseClause(n); //TODO SAFELEN
    }
#line 7122 "parser.c"
    break;

  case 418:
#line 2881 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7130 "parser.c"
    break;

  case 419:
#line 2885 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7138 "parser.c"
    break;

  case 420:
#line 2893 "parser.y"
    {
      //$$ = PlainClause(OCINBRANCH); TODO ast
    }
#line 7146 "parser.c"
    break;

  case 421:
#line 2897 "parser.y"
    {
      //$$ = PlainClause(OCNOTINBRANCH); TODO ast
    }
#line 7154 "parser.c"
    break;

  case 422:
#line 2904 "parser.y"
                { sc_pause_openmp(); }
#line 7160 "parser.c"
    break;

  case 423:
#line 2905 "parser.y"
    {
      sc_start_openmp();
      //$$ = VarlistClause(OCUNIFORM, $4); TODO ast
    }
#line 7169 "parser.c"
    break;

  case 424:
#line 2913 "parser.y"
               { sc_pause_openmp(); }
#line 7175 "parser.c"
    break;

  case 425:
#line 2914 "parser.y"
    {
      sc_start_openmp();
      // TODO ast
    }
#line 7184 "parser.c"
    break;

  case 426:
#line 2922 "parser.y"
                { sc_pause_openmp(); }
#line 7190 "parser.c"
    break;

  case 427:
#line 2923 "parser.y"
    {
      sc_start_openmp();
      // TODO ast
    }
#line 7199 "parser.c"
    break;

  case 428:
#line 2931 "parser.y"
    {
      (yyval.expr) = NULL;
    }
#line 7207 "parser.c"
    break;

  case 429:
#line 2935 "parser.y"
    {
      // TODO ast
    }
#line 7215 "parser.c"
    break;

  case 430:
#line 2943 "parser.y"
    {
      //$$ = OmpConstruct(DCDECLSIMD, $1, $2); TODO DCDECLSIMD or change it to stmt
    }
#line 7223 "parser.c"
    break;

  case 431:
#line 2951 "parser.y"
    {
      //TODO
    }
#line 7231 "parser.c"
    break;

  case 432:
#line 2955 "parser.y"
    {
        //TODO
    }
#line 7239 "parser.c"
    break;

  case 433:
#line 2963 "parser.y"
    {
      //$$ = OmpDirective(DCDECLSIMD, $4); TODO DCDECLSIMD
    }
#line 7247 "parser.c"
    break;

  case 434:
#line 2970 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7255 "parser.c"
    break;

  case 435:
#line 2974 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7263 "parser.c"
    break;

  case 436:
#line 2978 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7271 "parser.c"
    break;

  case 437:
#line 2987 "parser.y"
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in simdlen() clause.\n");
      //$$ = CollapseClause(n); //TODO SIMDLEN
    }
#line 7287 "parser.c"
    break;

  case 438:
#line 2999 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7295 "parser.c"
    break;

  case 439:
#line 3003 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7303 "parser.c"
    break;

  case 440:
#line 3007 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7311 "parser.c"
    break;

  case 441:
#line 3011 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7319 "parser.c"
    break;

  case 442:
#line 3019 "parser.y"
    {
      //$$ = OmpConstruct(DCFORSIMD, $1, $2); TODO DCFORSIMD
    }
#line 7327 "parser.c"
    break;

  case 443:
#line 3027 "parser.y"
    {
      //$$ = OmpDirective(DCFORSIMD, $4); TODO DCFORSIMD
    }
#line 7335 "parser.c"
    break;

  case 444:
#line 3034 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7343 "parser.c"
    break;

  case 445:
#line 3038 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7351 "parser.c"
    break;

  case 446:
#line 3042 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7359 "parser.c"
    break;

  case 447:
#line 3049 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7367 "parser.c"
    break;

  case 448:
#line 3053 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7375 "parser.c"
    break;

  case 449:
#line 3061 "parser.y"
    {
      //$$ = OmpConstruct(DCPARFORSIMD, $1, $2); TODO DCPARFORSIMD
    }
#line 7383 "parser.c"
    break;

  case 450:
#line 3069 "parser.y"
    {
      //$$ = OmpDirective(DCPARFORSIMD, $5); TODO DCFORSIMD
    }
#line 7391 "parser.c"
    break;

  case 451:
#line 3076 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7399 "parser.c"
    break;

  case 452:
#line 3080 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7407 "parser.c"
    break;

  case 453:
#line 3084 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7415 "parser.c"
    break;

  case 454:
#line 3091 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7423 "parser.c"
    break;

  case 455:
#line 3095 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7431 "parser.c"
    break;

  case 456:
#line 3103 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTARGETDATA, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 7439 "parser.c"
    break;

  case 457:
#line 3111 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTARGETDATA, (yyvsp[-1].ocla));
    }
#line 7447 "parser.c"
    break;

  case 458:
#line 3118 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7455 "parser.c"
    break;

  case 459:
#line 3122 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7463 "parser.c"
    break;

  case 460:
#line 3126 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7471 "parser.c"
    break;

  case 461:
#line 3133 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7479 "parser.c"
    break;

  case 462:
#line 3137 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7487 "parser.c"
    break;

  case 463:
#line 3141 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7495 "parser.c"
    break;

  case 464:
#line 3148 "parser.y"
                   { sc_pause_openmp(); }
#line 7501 "parser.c"
    break;

  case 465:
#line 3149 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = DeviceClause((yyvsp[-1].expr));
    }
#line 7510 "parser.c"
    break;

  case 466:
#line 3157 "parser.y"
                             { sc_pause_openmp(); }
#line 7516 "parser.c"
    break;

  case 467:
#line 3158 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = MapClause((yyvsp[-4].type), (yyvsp[-1].decl));
    }
#line 7525 "parser.c"
    break;

  case 468:
#line 3162 "parser.y"
                { sc_pause_openmp(); }
#line 7531 "parser.c"
    break;

  case 469:
#line 3163 "parser.y"
    {
      sc_start_openmp();
    (yyval.ocla) = MapClause(OC_tofrom, (yyvsp[-1].decl));
    }
#line 7540 "parser.c"
    break;

  case 470:
#line 3172 "parser.y"
    {
      (yyval.type) = OC_alloc;
    }
#line 7548 "parser.c"
    break;

  case 471:
#line 3176 "parser.y"
    {
      (yyval.type) = OC_to;
    }
#line 7556 "parser.c"
    break;

  case 472:
#line 3180 "parser.y"
    {
      (yyval.type) = OC_from;
    }
#line 7564 "parser.c"
    break;

  case 473:
#line 3184 "parser.y"
    {
      (yyval.type) = OC_tofrom;
    }
#line 7572 "parser.c"
    break;

  case 474:
#line 3191 "parser.y"
                     { (yyval.type) = errorOnReturn;  errorOnReturn = 1; }
#line 7578 "parser.c"
    break;

  case 475:
#line 3193 "parser.y"
    {
      errorOnReturn = (yyvsp[-1].type);
      (yyval.ocon) = OmpConstruct(DCTARGET, (yyvsp[-2].odir), (yyvsp[0].stmt));
      __has_target = 1;
    }
#line 7588 "parser.c"
    break;

  case 476:
#line 3203 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTARGET, (yyvsp[-1].ocla));
    }
#line 7596 "parser.c"
    break;

  case 477:
#line 3210 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7604 "parser.c"
    break;

  case 478:
#line 3214 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7612 "parser.c"
    break;

  case 479:
#line 3218 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7620 "parser.c"
    break;

  case 480:
#line 3225 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7628 "parser.c"
    break;

  case 481:
#line 3229 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7636 "parser.c"
    break;

  case 482:
#line 3236 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7644 "parser.c"
    break;

  case 483:
#line 3240 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7652 "parser.c"
    break;

  case 484:
#line 3248 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTARGETUPD, (yyvsp[0].odir), NULL);
    }
#line 7660 "parser.c"
    break;

  case 485:
#line 3256 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTARGETUPD, (yyvsp[-1].ocla));
    }
#line 7668 "parser.c"
    break;

  case 486:
#line 3263 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7676 "parser.c"
    break;

  case 487:
#line 3267 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7684 "parser.c"
    break;

  case 488:
#line 3271 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7692 "parser.c"
    break;

  case 489:
#line 3278 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7700 "parser.c"
    break;

  case 490:
#line 3282 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7708 "parser.c"
    break;

  case 491:
#line 3286 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7716 "parser.c"
    break;

  case 492:
#line 3292 "parser.y"
           { sc_pause_openmp(); }
#line 7722 "parser.c"
    break;

  case 493:
#line 3293 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCTO, (yyvsp[-1].decl));
    }
#line 7731 "parser.c"
    break;

  case 494:
#line 3297 "parser.y"
             { sc_pause_openmp(); }
#line 7737 "parser.c"
    break;

  case 495:
#line 3298 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCFROM, (yyvsp[-1].decl));
    }
#line 7746 "parser.c"
    break;

  case 496:
#line 3307 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCDECLTARGET, (yyvsp[-2].odir), (yyvsp[-1].stmt));
    }
#line 7754 "parser.c"
    break;

  case 497:
#line 3314 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCDECLTARGET, NULL);
    }
#line 7762 "parser.c"
    break;

  case 498:
#line 3321 "parser.y"
    {
      //$$ = OmpDirective(DCENDDECLTARGET, NULL); TODO DCENDDECLTARGET
    }
#line 7770 "parser.c"
    break;

  case 499:
#line 3329 "parser.y"
    {
      //$$ = OmpConstruct(DCTEAMS, $1, $2); TODO DCTEAMS
    }
#line 7778 "parser.c"
    break;

  case 500:
#line 3337 "parser.y"
    {
      //$$ = OmpDirective(DCTEAMS, $3); TODO DCTEAMS
    }
#line 7786 "parser.c"
    break;

  case 501:
#line 3344 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7794 "parser.c"
    break;

  case 502:
#line 3348 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7802 "parser.c"
    break;

  case 503:
#line 3352 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7810 "parser.c"
    break;

  case 504:
#line 3359 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7818 "parser.c"
    break;

  case 505:
#line 3363 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7826 "parser.c"
    break;

  case 506:
#line 3367 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7834 "parser.c"
    break;

  case 507:
#line 3371 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7842 "parser.c"
    break;

  case 508:
#line 3375 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7850 "parser.c"
    break;

  case 509:
#line 3379 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7858 "parser.c"
    break;

  case 510:
#line 3386 "parser.y"
                     { sc_pause_openmp(); }
#line 7864 "parser.c"
    break;

  case 511:
#line 3387 "parser.y"
    {
      sc_start_openmp();
      //$$ = NumthreadsClause($4); //TODO check if numthreads is good or if I should make something new
    }
#line 7873 "parser.c"
    break;

  case 512:
#line 3392 "parser.y"
                        { sc_pause_openmp(); }
#line 7879 "parser.c"
    break;

  case 513:
#line 3393 "parser.y"
    {
      sc_start_openmp();
      //$$ = NumthreadsClause($4); //TODO check if numthreads is good or if I should make something new
    }
#line 7888 "parser.c"
    break;

  case 514:
#line 3402 "parser.y"
    {
      //$$ = OmpConstruct(DCDISTRIBUTE, $1, $2); TODO DCDISTRIBUTE
    }
#line 7896 "parser.c"
    break;

  case 515:
#line 3410 "parser.y"
    {
      //$$ = OmpDirective(DCDISTRIBUTE, $3); TODO DCDISTRIBUTE
    }
#line 7904 "parser.c"
    break;

  case 516:
#line 3417 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 7912 "parser.c"
    break;

  case 517:
#line 3421 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 7920 "parser.c"
    break;

  case 518:
#line 3425 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 7928 "parser.c"
    break;

  case 519:
#line 3432 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7936 "parser.c"
    break;

  case 520:
#line 3436 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7944 "parser.c"
    break;

  case 521:
#line 3440 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7952 "parser.c"
    break;

  case 522:
#line 3444 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 7960 "parser.c"
    break;

  case 523:
#line 3451 "parser.y"
    {
      (yyval.ocla) = ScheduleClause(OC_static, NULL);
    }
#line 7968 "parser.c"
    break;

  case 524:
#line 3454 "parser.y"
                                        { sc_pause_openmp(); }
#line 7974 "parser.c"
    break;

  case 525:
#line 3455 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = ScheduleClause(OC_static, (yyvsp[-1].expr));
    }
#line 7983 "parser.c"
    break;

  case 526:
#line 3464 "parser.y"
    {
      //$$ = OmpConstruct(DCDISTSIMD, $1, $2); TODO DCDISTSIMD
      //$$->l = $1->l;
    }
#line 7992 "parser.c"
    break;

  case 527:
#line 3473 "parser.y"
    {
      //$$ = OmpDirective(DCDISTSIMD, $4); TODO DCDISTSIMD
    }
#line 8000 "parser.c"
    break;

  case 528:
#line 3480 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8008 "parser.c"
    break;

  case 529:
#line 3484 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8016 "parser.c"
    break;

  case 530:
#line 3488 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8024 "parser.c"
    break;

  case 531:
#line 3495 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8032 "parser.c"
    break;

  case 532:
#line 3499 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8040 "parser.c"
    break;

  case 533:
#line 3503 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8048 "parser.c"
    break;

  case 534:
#line 3511 "parser.y"
    {
      //$$ = OmpConstruct(DCDISTPARFOR, $1, $2); TODO DCDISTPARFOR
      //$$->l = $1->l;
    }
#line 8057 "parser.c"
    break;

  case 535:
#line 3520 "parser.y"
    {
      //$$ = OmpDirective(DCDISTPARFOR, $5); TODO DCDISTPARFOR
    }
#line 8065 "parser.c"
    break;

  case 536:
#line 3527 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8073 "parser.c"
    break;

  case 537:
#line 3531 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8081 "parser.c"
    break;

  case 538:
#line 3535 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8089 "parser.c"
    break;

  case 539:
#line 3542 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8097 "parser.c"
    break;

  case 540:
#line 3546 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8105 "parser.c"
    break;

  case 541:
#line 3554 "parser.y"
    {
      //$$ = OmpConstruct(DCDISTPARFORSIMD, $1, $2); TODO DCDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8114 "parser.c"
    break;

  case 542:
#line 3563 "parser.y"
    {
      //$$ = OmpDirective(DCDISTPARFORSIMD, $6); TODO DCDISTPARFORSIMD
    }
#line 8122 "parser.c"
    break;

  case 543:
#line 3570 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8130 "parser.c"
    break;

  case 544:
#line 3574 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8138 "parser.c"
    break;

  case 545:
#line 3578 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8146 "parser.c"
    break;

  case 546:
#line 3585 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8154 "parser.c"
    break;

  case 547:
#line 3589 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8162 "parser.c"
    break;

  case 548:
#line 3597 "parser.y"
    {
      //$$ = OmpConstruct(DCTARGETTEAMS, $1, $2); TODO DCTARGETTEAMS
    }
#line 8170 "parser.c"
    break;

  case 549:
#line 3605 "parser.y"
    {
      //$$ = OmpDirective(DCTARGETTEAMS, $4); TODO DCTARGETTEAMS
    }
#line 8178 "parser.c"
    break;

  case 550:
#line 3612 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8186 "parser.c"
    break;

  case 551:
#line 3616 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8194 "parser.c"
    break;

  case 552:
#line 3620 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8202 "parser.c"
    break;

  case 553:
#line 3627 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8210 "parser.c"
    break;

  case 554:
#line 3631 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8218 "parser.c"
    break;

  case 555:
#line 3639 "parser.y"
    {
      //$$ = OmpConstruct(DCTEAMSDIST, $1, $2); TODO DCTEAMSDIST
    }
#line 8226 "parser.c"
    break;

  case 556:
#line 3647 "parser.y"
    {
      //$$ = OmpDirective(DCTEAMSDIST, $4); TODO DCTEAMSDIST
    }
#line 8234 "parser.c"
    break;

  case 557:
#line 3654 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8242 "parser.c"
    break;

  case 558:
#line 3658 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8250 "parser.c"
    break;

  case 559:
#line 3662 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8258 "parser.c"
    break;

  case 560:
#line 3669 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8266 "parser.c"
    break;

  case 561:
#line 3673 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8274 "parser.c"
    break;

  case 562:
#line 3677 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8282 "parser.c"
    break;

  case 563:
#line 3685 "parser.y"
    {
      //$$ = OmpConstruct(DCTEAMSDISTSIMD, $1, $2); TODO DCTEAMSDISTSIMD
    }
#line 8290 "parser.c"
    break;

  case 564:
#line 3693 "parser.y"
    {
      //$$ = OmpDirective(DCTEAMSDISTSIMD, $5); TODO DCTEAMSDISTSIMD
    }
#line 8298 "parser.c"
    break;

  case 565:
#line 3700 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8306 "parser.c"
    break;

  case 566:
#line 3704 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8314 "parser.c"
    break;

  case 567:
#line 3708 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8322 "parser.c"
    break;

  case 568:
#line 3715 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8330 "parser.c"
    break;

  case 569:
#line 3719 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8338 "parser.c"
    break;

  case 570:
#line 3723 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8346 "parser.c"
    break;

  case 571:
#line 3727 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8354 "parser.c"
    break;

  case 572:
#line 3735 "parser.y"
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDIST, $1, $2); TODO DCTARGETTEAMSDIST
    }
#line 8362 "parser.c"
    break;

  case 573:
#line 3743 "parser.y"
    {
      //$$ = OmpDirective(DCTARGETTEAMSDIST, $5); TODO DCTARGETTEAMSDIST
    }
#line 8370 "parser.c"
    break;

  case 574:
#line 3750 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8378 "parser.c"
    break;

  case 575:
#line 3754 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8386 "parser.c"
    break;

  case 576:
#line 3758 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8394 "parser.c"
    break;

  case 577:
#line 3765 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8402 "parser.c"
    break;

  case 578:
#line 3769 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8410 "parser.c"
    break;

  case 579:
#line 3777 "parser.y"
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTSIMD, $1, $2); TODO DCTARGETTEAMSDISTSIMD
    }
#line 8418 "parser.c"
    break;

  case 580:
#line 3786 "parser.y"
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTSIMD, $6); TODO DCTARGETTEAMSDISTSIMD
    }
#line 8426 "parser.c"
    break;

  case 581:
#line 3793 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8434 "parser.c"
    break;

  case 582:
#line 3798 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8442 "parser.c"
    break;

  case 583:
#line 3803 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8450 "parser.c"
    break;

  case 584:
#line 3810 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8458 "parser.c"
    break;

  case 585:
#line 3814 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8466 "parser.c"
    break;

  case 586:
#line 3822 "parser.y"
    {
      //$$ = OmpConstruct(DCTEAMSDISTPARFOR, $1, $2); TODO DCTEAMSDISTPARFOR
      //$$->l = $1->l;
    }
#line 8475 "parser.c"
    break;

  case 587:
#line 3832 "parser.y"
    {
      //$$ = OmpDirective(DCTEAMSDISTPARFOR, $3); TODO DCTEAMSDISTPARFOR
    }
#line 8483 "parser.c"
    break;

  case 588:
#line 3839 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8491 "parser.c"
    break;

  case 589:
#line 3844 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8499 "parser.c"
    break;

  case 590:
#line 3849 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8507 "parser.c"
    break;

  case 591:
#line 3856 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8515 "parser.c"
    break;

  case 592:
#line 3860 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8523 "parser.c"
    break;

  case 593:
#line 3868 "parser.y"
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTPARFOR, $1, $2); TODO DCTARGETTEAMSDISTPARFOR
      //$$->l = $1->l;
    }
#line 8532 "parser.c"
    break;

  case 594:
#line 3877 "parser.y"
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTPARFOR, $7); TODO DCTARGETTEAMSDISTPARFOR
    }
#line 8540 "parser.c"
    break;

  case 595:
#line 3884 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8548 "parser.c"
    break;

  case 596:
#line 3888 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8556 "parser.c"
    break;

  case 597:
#line 3892 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8564 "parser.c"
    break;

  case 598:
#line 3899 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8572 "parser.c"
    break;

  case 599:
#line 3903 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8580 "parser.c"
    break;

  case 600:
#line 3911 "parser.y"
    {
      //$$ = OmpConstruct(DCTEAMSDISTPARFORSIMD, $1, $2); TODO DCTEAMSDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8589 "parser.c"
    break;

  case 601:
#line 3920 "parser.y"
    {
      //$$ = OmpDirective(DCTEAMSDISTPARFORSIMD, $7); TODO DCTEAMSDISTPARFORSIMD
    }
#line 8597 "parser.c"
    break;

  case 602:
#line 3927 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8605 "parser.c"
    break;

  case 603:
#line 3931 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8613 "parser.c"
    break;

  case 604:
#line 3935 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8621 "parser.c"
    break;

  case 605:
#line 3942 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8629 "parser.c"
    break;

  case 606:
#line 3946 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8637 "parser.c"
    break;

  case 607:
#line 3954 "parser.y"
    {
      //$$ = OmpConstruct(DCTARGETTEAMSDISTPARFORSIMD, $1, $2); TODO DCTARGETTEAMSDISTPARFORSIMD
      //$$->l = $1->l;
    }
#line 8646 "parser.c"
    break;

  case 608:
#line 3963 "parser.y"
    {
      //$$ = OmpDirective(DCTARGETTEAMSDISTPARFORSIMD, $8); TODO DCTARGETTEAMSDISTPARFORSIMD
    }
#line 8654 "parser.c"
    break;

  case 609:
#line 3970 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8662 "parser.c"
    break;

  case 610:
#line 3974 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8670 "parser.c"
    break;

  case 611:
#line 3978 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8678 "parser.c"
    break;

  case 612:
#line 3985 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8686 "parser.c"
    break;

  case 613:
#line 3989 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8694 "parser.c"
    break;

  case 614:
#line 3997 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTASK, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8703 "parser.c"
    break;

  case 615:
#line 4006 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTASK, (yyvsp[-1].ocla));
    }
#line 8711 "parser.c"
    break;

  case 616:
#line 4014 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8719 "parser.c"
    break;

  case 617:
#line 4018 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8727 "parser.c"
    break;

  case 618:
#line 4022 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8735 "parser.c"
    break;

  case 619:
#line 4030 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8743 "parser.c"
    break;

  case 620:
#line 4034 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8751 "parser.c"
    break;

  case 621:
#line 4038 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8759 "parser.c"
    break;

  case 622:
#line 4042 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8767 "parser.c"
    break;

  case 623:
#line 4046 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8775 "parser.c"
    break;

  case 624:
#line 4054 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8783 "parser.c"
    break;

  case 625:
#line 4057 "parser.y"
                  { sc_pause_openmp(); }
#line 8789 "parser.c"
    break;

  case 626:
#line 4058 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = FinalClause((yyvsp[-1].expr));
    }
#line 8798 "parser.c"
    break;

  case 627:
#line 4063 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCUNTIED);
    }
#line 8806 "parser.c"
    break;

  case 628:
#line 4067 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCMERGEABLE);
    }
#line 8814 "parser.c"
    break;

  case 629:
#line 4072 "parser.y"
    {
      //$$ = VarlistClause(OCPRIVATE, $6); TODO find out how to do this. It needs type OCDEPEND subtype from $3 and a list from $6
    }
#line 8822 "parser.c"
    break;

  case 630:
#line 4080 "parser.y"
    {
      //$$ = OC_in; TODO OC_in
    }
#line 8830 "parser.c"
    break;

  case 631:
#line 4084 "parser.y"
    {
      //$$ = OC_out; TODO OC_out
    }
#line 8838 "parser.c"
    break;

  case 632:
#line 4088 "parser.y"
    {
      //$$ = OC_inout; TODO OC_inout
    }
#line 8846 "parser.c"
    break;

  case 633:
#line 4095 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCPARFOR, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8855 "parser.c"
    break;

  case 634:
#line 4103 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCPARFOR, (yyvsp[-1].ocla));
    }
#line 8863 "parser.c"
    break;

  case 635:
#line 4110 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8871 "parser.c"
    break;

  case 636:
#line 4114 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8879 "parser.c"
    break;

  case 637:
#line 4118 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8887 "parser.c"
    break;

  case 638:
#line 4125 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8895 "parser.c"
    break;

  case 639:
#line 4129 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8903 "parser.c"
    break;

  case 640:
#line 4133 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8911 "parser.c"
    break;

  case 641:
#line 4137 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8919 "parser.c"
    break;

  case 642:
#line 4141 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8927 "parser.c"
    break;

  case 643:
#line 4145 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8935 "parser.c"
    break;

  case 644:
#line 4149 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8943 "parser.c"
    break;

  case 645:
#line 4153 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 8951 "parser.c"
    break;

  case 646:
#line 4160 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCPARSECTIONS, (yyvsp[-1].odir), (yyvsp[0].stmt));
      (yyval.ocon)->l = (yyvsp[-1].odir)->l;
    }
#line 8960 "parser.c"
    break;

  case 647:
#line 4168 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCPARSECTIONS, (yyvsp[-1].ocla));
    }
#line 8968 "parser.c"
    break;

  case 648:
#line 4175 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 8976 "parser.c"
    break;

  case 649:
#line 4179 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-1].ocla), (yyvsp[0].ocla));
    }
#line 8984 "parser.c"
    break;

  case 650:
#line 4183 "parser.y"
    {
      (yyval.ocla) = OmpClauseList((yyvsp[-2].ocla), (yyvsp[0].ocla));
    }
#line 8992 "parser.c"
    break;

  case 651:
#line 4190 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9000 "parser.c"
    break;

  case 652:
#line 4194 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9008 "parser.c"
    break;

  case 653:
#line 4198 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9016 "parser.c"
    break;

  case 654:
#line 4202 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9024 "parser.c"
    break;

  case 655:
#line 4206 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9032 "parser.c"
    break;

  case 656:
#line 4210 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9040 "parser.c"
    break;

  case 657:
#line 4214 "parser.y"
    {
      (yyval.ocla) = (yyvsp[0].ocla);
    }
#line 9048 "parser.c"
    break;

  case 658:
#line 4221 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCMASTER, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9056 "parser.c"
    break;

  case 659:
#line 4228 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCMASTER, NULL);
    }
#line 9064 "parser.c"
    break;

  case 660:
#line 4235 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCCRITICAL, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9072 "parser.c"
    break;

  case 661:
#line 4242 "parser.y"
    {
      (yyval.odir) = OmpCriticalDirective(NULL);
    }
#line 9080 "parser.c"
    break;

  case 662:
#line 4246 "parser.y"
    {
      (yyval.odir) = OmpCriticalDirective((yyvsp[-1].symb));
    }
#line 9088 "parser.c"
    break;

  case 663:
#line 4253 "parser.y"
    {
      (yyval.symb) = Symbol((yyvsp[-1].name));
    }
#line 9096 "parser.c"
    break;

  case 664:
#line 4260 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCBARRIER, NULL);
    }
#line 9104 "parser.c"
    break;

  case 665:
#line 4268 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTASKWAIT, NULL);
    }
#line 9112 "parser.c"
    break;

  case 666:
#line 4276 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCTASKGROUP, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9120 "parser.c"
    break;

  case 667:
#line 4284 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTASKGROUP, NULL);
    }
#line 9128 "parser.c"
    break;

  case 668:
#line 4292 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCTASKYIELD, NULL);
    }
#line 9136 "parser.c"
    break;

  case 669:
#line 4299 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCATOMIC, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9144 "parser.c"
    break;

  case 670:
#line 4310 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCATOMIC, NULL);  //TODO Check how to do it since it now has 2 clauses
    }
#line 9152 "parser.c"
    break;

  case 671:
#line 4317 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 9160 "parser.c"
    break;

  case 672:
#line 4321 "parser.y"
    {
      //$$ = TODO
    }
#line 9168 "parser.c"
    break;

  case 673:
#line 4325 "parser.y"
    {
      //$$ = TODO
    }
#line 9176 "parser.c"
    break;

  case 674:
#line 4329 "parser.y"
    {
      //$$ = TODO
    }
#line 9184 "parser.c"
    break;

  case 675:
#line 4333 "parser.y"
    {
      //$$ = TODO
    }
#line 9192 "parser.c"
    break;

  case 676:
#line 4341 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 9200 "parser.c"
    break;

  case 677:
#line 4345 "parser.y"
    {
      //$$ = TODO
    }
#line 9208 "parser.c"
    break;

  case 678:
#line 4352 "parser.y"
    {
      (yyval.odir) = OmpFlushDirective(NULL);
    }
#line 9216 "parser.c"
    break;

  case 679:
#line 4356 "parser.y"
    {
      (yyval.odir) = OmpFlushDirective((yyvsp[-1].decl));
    }
#line 9224 "parser.c"
    break;

  case 680:
#line 4362 "parser.y"
        { sc_pause_openmp(); }
#line 9230 "parser.c"
    break;

  case 681:
#line 4363 "parser.y"
    {
      sc_start_openmp();
      (yyval.decl) = (yyvsp[-1].decl);
    }
#line 9239 "parser.c"
    break;

  case 682:
#line 4371 "parser.y"
    {
      (yyval.ocon) = OmpConstruct(DCORDERED, (yyvsp[-1].odir), (yyvsp[0].stmt));
    }
#line 9247 "parser.c"
    break;

  case 683:
#line 4378 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCORDERED, NULL);
    }
#line 9255 "parser.c"
    break;

  case 684:
#line 4386 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCCANCEL, (yyvsp[-1].ocla));
    }
#line 9263 "parser.c"
    break;

  case 685:
#line 4390 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCCANCEL, OmpClauseList((yyvsp[-2].ocla), (yyvsp[-1].ocla)));
    }
#line 9271 "parser.c"
    break;

  case 686:
#line 4394 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCCANCEL, OmpClauseList((yyvsp[-3].ocla), (yyvsp[-1].ocla)));
    }
#line 9279 "parser.c"
    break;

  case 687:
#line 4401 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCPARALLEL);
    }
#line 9287 "parser.c"
    break;

  case 688:
#line 4405 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCSECTIONS);
    }
#line 9295 "parser.c"
    break;

  case 689:
#line 4409 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCFOR);
    }
#line 9303 "parser.c"
    break;

  case 690:
#line 4413 "parser.y"
    {
      (yyval.ocla) = PlainClause(OCTASKGROUP);
    }
#line 9311 "parser.c"
    break;

  case 691:
#line 4421 "parser.y"
    {
      (yyval.odir) = OmpDirective(DCCANCELLATIONPOINT, (yyvsp[-1].ocla));
    }
#line 9319 "parser.c"
    break;

  case 692:
#line 4427 "parser.y"
                             { sc_pause_openmp(); }
#line 9325 "parser.c"
    break;

  case 693:
#line 4427 "parser.y"
                                                                                 { sc_start_openmp(); }
#line 9331 "parser.c"
    break;

  case 694:
#line 4428 "parser.y"
    {
      (yyval.odir) = OmpThreadprivateDirective((yyvsp[-3].decl));
    }
#line 9339 "parser.c"
    break;

  case 695:
#line 4435 "parser.y"
                                                                                              { sc_pause_openmp(); }
#line 9345 "parser.c"
    break;

  case 696:
#line 4435 "parser.y"
                                                                                                                                    { sc_start_openmp(); }
#line 9351 "parser.c"
    break;

  case 697:
#line 4436 "parser.y"
    {
      //$$ = TODO
    }
#line 9359 "parser.c"
    break;

  case 698:
#line 4443 "parser.y"
    {
      //$$ = OC_identifier TODO
      //Symbol($2);  TODO
    }
#line 9368 "parser.c"
    break;

  case 699:
#line 4448 "parser.y"
    {
      (yyval.type) = OC_plus;
    }
#line 9376 "parser.c"
    break;

  case 700:
#line 4452 "parser.y"
    {
      (yyval.type) = OC_times;
    }
#line 9384 "parser.c"
    break;

  case 701:
#line 4456 "parser.y"
    {
      (yyval.type) = OC_minus;
    }
#line 9392 "parser.c"
    break;

  case 702:
#line 4460 "parser.y"
    {
      (yyval.type) = OC_band;
    }
#line 9400 "parser.c"
    break;

  case 703:
#line 4464 "parser.y"
    {
      (yyval.type) = OC_xor;
    }
#line 9408 "parser.c"
    break;

  case 704:
#line 4468 "parser.y"
    {
      (yyval.type) = OC_bor;
    }
#line 9416 "parser.c"
    break;

  case 705:
#line 4472 "parser.y"
    {
      (yyval.type) = OC_land;
    }
#line 9424 "parser.c"
    break;

  case 706:
#line 4476 "parser.y"
    {
      (yyval.type) = OC_lor;
    }
#line 9432 "parser.c"
    break;

  case 707:
#line 4480 "parser.y"
    {
      (yyval.type) = OC_min;
    }
#line 9440 "parser.c"
    break;

  case 708:
#line 4484 "parser.y"
    {
      (yyval.type) = OC_max;
    }
#line 9448 "parser.c"
    break;

  case 709:
#line 4491 "parser.y"
    {
      //TODO
    }
#line 9456 "parser.c"
    break;

  case 710:
#line 4495 "parser.y"
    {
      //TODO
    }
#line 9464 "parser.c"
    break;

  case 711:
#line 4502 "parser.y"
    {
      (yyval.ocla) = NULL;
    }
#line 9472 "parser.c"
    break;

  case 712:
#line 4506 "parser.y"
    {
        //TODO must check if identifier is omp_priv and that conditional
        //expression contains only omp_priv and omp_orig variables
    }
#line 9481 "parser.c"
    break;

  case 713:
#line 4511 "parser.y"
    {
      //TODO in argument_expression_list one of the variables must be &omp_priv
      // TODO check ox_funccall_expression
      //$$ = strcmp($1, "main") ?
      //       FunctionCall(IdentName($1), $3) :
      //       FunctionCall(IdentName(MAIN_NEWNAME), $3);
    }
#line 9493 "parser.c"
    break;

  case 714:
#line 4522 "parser.y"
    {
      (yyval.ocla) = DefaultClause(OC_defshared);
    }
#line 9501 "parser.c"
    break;

  case 715:
#line 4526 "parser.y"
    {
      (yyval.ocla) = DefaultClause(OC_defnone);
    }
#line 9509 "parser.c"
    break;

  case 716:
#line 4531 "parser.y"
    {
      (yyval.ocla) = DefaultClause(OC_auto); //I'm using the existing subtype (Alexandros)
    }
#line 9517 "parser.c"
    break;

  case 717:
#line 4537 "parser.y"
                { sc_pause_openmp(); }
#line 9523 "parser.c"
    break;

  case 718:
#line 4538 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCPRIVATE, (yyvsp[-1].decl));
    }
#line 9532 "parser.c"
    break;

  case 719:
#line 4545 "parser.y"
                     { sc_pause_openmp(); }
#line 9538 "parser.c"
    break;

  case 720:
#line 4546 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCFIRSTPRIVATE, (yyvsp[-1].decl));
    }
#line 9547 "parser.c"
    break;

  case 721:
#line 4553 "parser.y"
                    { sc_pause_openmp(); }
#line 9553 "parser.c"
    break;

  case 722:
#line 4554 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCLASTPRIVATE, (yyvsp[-1].decl));
    }
#line 9562 "parser.c"
    break;

  case 723:
#line 4561 "parser.y"
               { sc_pause_openmp(); }
#line 9568 "parser.c"
    break;

  case 724:
#line 4562 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = VarlistClause(OCSHARED, (yyvsp[-1].decl));
    }
#line 9577 "parser.c"
    break;

  case 725:
#line 4569 "parser.y"
                                           { sc_pause_openmp(); }
#line 9583 "parser.c"
    break;

  case 726:
#line 4570 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = ReductionClause((yyvsp[-4].type), (yyvsp[-1].decl));
    }
#line 9592 "parser.c"
    break;

  case 727:
#line 4577 "parser.y"
               { sc_pause_openmp(); }
#line 9598 "parser.c"
    break;

  case 728:
#line 4578 "parser.y"
    {
      sc_start_openmp();
      (yyval.ocla) = IfClause((yyvsp[-1].expr));
    }
#line 9607 "parser.c"
    break;

  case 729:
#line 4586 "parser.y"
    {
      int n = 0, er = 0;
      if (xar_expr_is_constant((yyvsp[-1].expr)))
      {
        n = xar_calc_int_expr((yyvsp[-1].expr), &er);
        if (er) n = 0;
      }
      if (n <= 0)
        parse_error(1, "invalid number in collapse() clause.\n");
      (yyval.ocla) = CollapseClause(n);
    }
#line 9623 "parser.c"
    break;

  case 730:
#line 4601 "parser.y"
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[-1].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[-1].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[-1].name)) );
      parse_warning("Array section not supported yet. Ignored.\n");
    }
#line 9635 "parser.c"
    break;

  case 731:
#line 4612 "parser.y"
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9646 "parser.c"
    break;

  case 732:
#line 4619 "parser.y"
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9657 "parser.c"
    break;

  case 733:
#line 4629 "parser.y"
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9668 "parser.c"
    break;

  case 734:
#line 4636 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 9676 "parser.c"
    break;

  case 735:
#line 4640 "parser.y"
    {
      if (checkDecls)
        if (symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME) == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9687 "parser.c"
    break;

  case 736:
#line 4647 "parser.y"
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 9695 "parser.c"
    break;

  case 737:
#line 4653 "parser.y"
                                { sc_pause_openmp(); }
#line 9701 "parser.c"
    break;

  case 738:
#line 4654 "parser.y"
    {
      sc_start_openmp();
      //TODO
    }
#line 9710 "parser.c"
    break;

  case 739:
#line 4658 "parser.y"
        { sc_pause_openmp(); }
#line 9716 "parser.c"
    break;

  case 740:
#line 4659 "parser.y"
    {
      sc_start_openmp();
      //TODO
    }
#line 9725 "parser.c"
    break;

  case 741:
#line 4667 "parser.y"
    {
      //TODO
    }
#line 9733 "parser.c"
    break;

  case 742:
#line 4671 "parser.y"
    {
      //TODO
    }
#line 9741 "parser.c"
    break;

  case 743:
#line 4679 "parser.y"
    {
      (yyval.ocla) = ProcBindClause(OC_bindmaster);
    }
#line 9749 "parser.c"
    break;

  case 744:
#line 4683 "parser.y"
    {
      (yyval.ocla) = ProcBindClause(OC_bindclose);
    }
#line 9757 "parser.c"
    break;

  case 745:
#line 4687 "parser.y"
    {
      (yyval.ocla) = ProcBindClause(OC_bindspread);
    }
#line 9765 "parser.c"
    break;

  case 746:
#line 4699 "parser.y"
    {
      if (checkDecls)
      {
        stentry e = symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME);
        if (e == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
        if (e->scopelevel != stab->scopelevel)
          parse_error(-1, "threadprivate directive appears at different "
                          "scope level\nfrom the one `%s' was declared.\n", (yyvsp[0].name));
        if (stab->scopelevel > 0)    /* Don't care for globals */
          if (speclist_getspec(e->spec, STCLASSSPEC, SPEC_static) == NULL)
            parse_error(-1, "threadprivate variable `%s' does not have static "
                            "storage type.\n", (yyvsp[0].name));
        e->isthrpriv = true;   /* Mark */
      }
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
    }
#line 9787 "parser.c"
    break;

  case 747:
#line 4717 "parser.y"
    {
      if (checkDecls)
      {
        stentry e = symtab_get(stab, Symbol((yyvsp[0].name)), IDNAME);
        if (e == NULL)
          parse_error(-1, "unknown identifier `%s'.\n", (yyvsp[0].name));
        if (e->scopelevel != stab->scopelevel)
          parse_error(-1, "threadprivate directive appears at different "
                          "scope level\nfrom the one `%s' was declared.\n", (yyvsp[0].name));
        if (stab->scopelevel > 0)    /* Don't care for globals */
          if (speclist_getspec(e->spec, STCLASSSPEC, SPEC_static) == NULL)
            parse_error(-1, "threadprivate variable `%s' does not have static "
                            "storage type.\n", (yyvsp[0].name));
        e->isthrpriv = true;   /* Mark */
      }
      (yyval.decl) = IdList((yyvsp[-2].decl), IdentifierDecl( Symbol((yyvsp[0].name)) ));
    }
#line 9809 "parser.c"
    break;

  case 748:
#line 4743 "parser.y"
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASKSYNC, (yyvsp[0].xdir), NULL);
    }
#line 9817 "parser.c"
    break;

  case 749:
#line 4747 "parser.y"
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASKSCHEDULE, (yyvsp[0].xdir), NULL);
    }
#line 9825 "parser.c"
    break;

  case 750:
#line 4755 "parser.y"
    {
      (yyval.xdir) = OmpixDirective(OX_DCTASKSYNC, NULL);
    }
#line 9833 "parser.c"
    break;

  case 751:
#line 4762 "parser.y"
    {
      scope_start(stab);
    }
#line 9841 "parser.c"
    break;

  case 752:
#line 4766 "parser.y"
    {
      scope_end(stab);
      (yyval.xdir) = OmpixDirective(OX_DCTASKSCHEDULE, (yyvsp[-1].xcla));
    }
#line 9850 "parser.c"
    break;

  case 753:
#line 4774 "parser.y"
    {
      (yyval.xcla) = NULL;
    }
#line 9858 "parser.c"
    break;

  case 754:
#line 4778 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 9866 "parser.c"
    break;

  case 755:
#line 4782 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 9874 "parser.c"
    break;

  case 756:
#line 4789 "parser.y"
    {
      (yyval.xcla) = OmpixStrideClause((yyvsp[-1].expr));
    }
#line 9882 "parser.c"
    break;

  case 757:
#line 4793 "parser.y"
    {
      (yyval.xcla) = OmpixStartClause((yyvsp[-1].expr));
    }
#line 9890 "parser.c"
    break;

  case 758:
#line 4797 "parser.y"
    {
      (yyval.xcla) = OmpixScopeClause((yyvsp[-1].type));
    }
#line 9898 "parser.c"
    break;

  case 759:
#line 4801 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCTIED);
    }
#line 9906 "parser.c"
    break;

  case 760:
#line 4805 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCUNTIED);
    }
#line 9914 "parser.c"
    break;

  case 761:
#line 4812 "parser.y"
    {
      (yyval.type) = OX_SCOPE_NODES;
    }
#line 9922 "parser.c"
    break;

  case 762:
#line 4816 "parser.y"
    {
      (yyval.type) = OX_SCOPE_WGLOBAL;
    }
#line 9930 "parser.c"
    break;

  case 763:
#line 4820 "parser.y"
    {
      (yyval.type) = OX_SCOPE_WGLOBAL;
    }
#line 9938 "parser.c"
    break;

  case 764:
#line 4824 "parser.y"
    {
      (yyval.type) = OX_SCOPE_WLOCAL;
    }
#line 9946 "parser.c"
    break;

  case 765:
#line 4831 "parser.y"
    {
      (yyval.xcon) = (yyvsp[0].xcon);
    }
#line 9954 "parser.c"
    break;

  case 766:
#line 4835 "parser.y"
    {
      (yyval.xcon) = (yyvsp[0].xcon);
    }
#line 9962 "parser.c"
    break;

  case 767:
#line 4843 "parser.y"
    {
      /* Should put the name of the callback function in the stab, too
      if (symtab_get(stab, decl_getidentifier_symbol($2->u.declaration.decl),
            FUNCNAME) == NULL)
        symtab_put(stab, decl_getidentifier_symbol($2->u.declaration.spec),
            FUNCNAME);
      */
      scope_start(stab);   /* re-declare the arguments of the task function */
      ast_declare_function_params((yyvsp[0].stmt)->u.declaration.decl);
    }
#line 9977 "parser.c"
    break;

  case 768:
#line 4854 "parser.y"
    {
      scope_end(stab);
      (yyval.xcon) = OmpixTaskdef((yyvsp[-3].xdir), (yyvsp[-2].stmt), (yyvsp[0].stmt));
      (yyval.xcon)->l = (yyvsp[-3].xdir)->l;
    }
#line 9987 "parser.c"
    break;

  case 769:
#line 4860 "parser.y"
    {
      (yyval.xcon) = OmpixTaskdef((yyvsp[-1].xdir), (yyvsp[0].stmt), NULL);
      (yyval.xcon)->l = (yyvsp[-1].xdir)->l;
    }
#line 9996 "parser.c"
    break;

  case 770:
#line 4868 "parser.y"
    {
      scope_start(stab);
    }
#line 10004 "parser.c"
    break;

  case 771:
#line 4872 "parser.y"
    {
      scope_end(stab);
      (yyval.xdir) = OmpixDirective(OX_DCTASKDEF, (yyvsp[-1].xcla));
    }
#line 10013 "parser.c"
    break;

  case 772:
#line 4880 "parser.y"
    {
      (yyval.xcla) = NULL;
    }
#line 10021 "parser.c"
    break;

  case 773:
#line 4884 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 10029 "parser.c"
    break;

  case 774:
#line 4888 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 10037 "parser.c"
    break;

  case 775:
#line 4895 "parser.y"
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCIN, (yyvsp[-1].decl));
    }
#line 10045 "parser.c"
    break;

  case 776:
#line 4899 "parser.y"
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCOUT, (yyvsp[-1].decl));
    }
#line 10053 "parser.c"
    break;

  case 777:
#line 4903 "parser.y"
    {
      (yyval.xcla) = OmpixVarlistClause(OX_OCINOUT, (yyvsp[-1].decl));
    }
#line 10061 "parser.c"
    break;

  case 778:
#line 4907 "parser.y"
    {
      (yyval.xcla) = OmpixReductionClause((yyvsp[-3].type), (yyvsp[-1].decl));
    }
#line 10069 "parser.c"
    break;

  case 779:
#line 4914 "parser.y"
    {
      (yyval.decl) = (yyvsp[0].decl);
    }
#line 10077 "parser.c"
    break;

  case 780:
#line 4918 "parser.y"
    {
      (yyval.decl) = IdList((yyvsp[-2].decl), (yyvsp[0].decl));
    }
#line 10085 "parser.c"
    break;

  case 781:
#line 4925 "parser.y"
    {
      (yyval.decl) = IdentifierDecl( Symbol((yyvsp[0].name)) );
      symtab_put(stab, Symbol((yyvsp[0].name)), IDNAME);
    }
#line 10094 "parser.c"
    break;

  case 782:
#line 4930 "parser.y"
    {
      if (checkDecls) check_uknown_var((yyvsp[-1].name));
      /* Use extern to differentiate */
      (yyval.decl) = ArrayDecl(IdentifierDecl( Symbol((yyvsp[-4].name)) ), StClassSpec(SPEC_extern),
                     IdentName((yyvsp[-1].name)));
      symtab_put(stab, Symbol((yyvsp[-4].name)), IDNAME);
    }
#line 10106 "parser.c"
    break;

  case 783:
#line 4938 "parser.y"
    {
      (yyval.decl) = ArrayDecl(IdentifierDecl( Symbol((yyvsp[-3].name)) ), NULL, (yyvsp[-1].expr));
      symtab_put(stab, Symbol((yyvsp[-3].name)), IDNAME);
    }
#line 10115 "parser.c"
    break;

  case 784:
#line 4946 "parser.y"
    {
      (yyval.xcon) = OmpixConstruct(OX_DCTASK, (yyvsp[-2].xdir), Expression((yyvsp[-1].expr)));
      (yyval.xcon)->l = (yyvsp[-2].xdir)->l;
    }
#line 10124 "parser.c"
    break;

  case 785:
#line 4954 "parser.y"
    {
      (yyval.xdir) = OmpixDirective(OX_DCTASK, (yyvsp[-1].xcla));
    }
#line 10132 "parser.c"
    break;

  case 786:
#line 4961 "parser.y"
    {
      (yyval.xcla) = NULL;
    }
#line 10140 "parser.c"
    break;

  case 787:
#line 4965 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-1].xcla), (yyvsp[0].xcla));
    }
#line 10148 "parser.c"
    break;

  case 788:
#line 4969 "parser.y"
    {
      (yyval.xcla) = OmpixClauseList((yyvsp[-2].xcla), (yyvsp[0].xcla));
    }
#line 10156 "parser.c"
    break;

  case 789:
#line 4976 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCATALL);
    }
#line 10164 "parser.c"
    break;

  case 790:
#line 4980 "parser.y"
    {
      (yyval.xcla) = OmpixAtnodeClause((yyvsp[-1].expr));
    }
#line 10172 "parser.c"
    break;

  case 791:
#line 4984 "parser.y"
    {
      (yyval.xcla) = OmpixAtworkerClause((yyvsp[-1].expr));
    }
#line 10180 "parser.c"
    break;

  case 792:
#line 4988 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCTIED);
    }
#line 10188 "parser.c"
    break;

  case 793:
#line 4992 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCUNTIED);
    }
#line 10196 "parser.c"
    break;

  case 794:
#line 4996 "parser.y"
    {
      (yyval.xcla) = OmpixPlainClause(OX_OCDETACHED);
    }
#line 10204 "parser.c"
    break;

  case 795:
#line 5003 "parser.y"
    {
      (yyval.expr) = strcmp((yyvsp[-2].name), "main") ?
             FunctionCall(IdentName((yyvsp[-2].name)), NULL) :
             FunctionCall(IdentName(MAIN_NEWNAME), NULL);
    }
#line 10214 "parser.c"
    break;

  case 796:
#line 5009 "parser.y"
    {
      (yyval.expr) = strcmp((yyvsp[-3].name), "main") ?
             FunctionCall(IdentName((yyvsp[-3].name)), (yyvsp[-1].expr)) :
             FunctionCall(IdentName(MAIN_NEWNAME), (yyvsp[-1].expr));
    }
#line 10224 "parser.c"
    break;


#line 10228 "parser.c"

      default: break;
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 5016 "parser.y"



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 *     CODE                                                      *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void yyerror(const char *s)
{
  fprintf(stderr, "(file %s, line %d, column %d):\n\t%s\n",
                  sc_original_file(), sc_original_line(), sc_column(), s);
}


/* Check whether the identifier is known or not
 */
void check_uknown_var(char *name)
{
  /* Hack for DF-C */
  if(strncmp(name, "DF", 2) == 0)
    return;

  symbol s = Symbol(name);
  if (symtab_get(stab, s, IDNAME) == NULL &&
      symtab_get(stab, s, LABELNAME) == NULL &&
      symtab_get(stab, s, FUNCNAME) == NULL)
    parse_error(-1, "unknown identifier `%s'.\n", name);
}



/* See the "declaration" rule: if the last element of the list
 * is a user typename, we remove it, and we return it as an
 * identifier declarator.
 * The list should have 3 elements (typedef xxx type).
 */
astdecl fix_known_typename(astspec s)
{
  astspec prev;
  astdecl d;

  if (s->type != SPECLIST || s->u.next->type != SPECLIST) return (NULL);

  for (; s->u.next->type == SPECLIST; prev = s, s = s->u.next)
    ;   /* goto last list node */
  if (s->u.next->type != USERTYPE)         /* nope */
    return (NULL);

  prev->u.next = s->body;

  d = Declarator(NULL, IdentifierDecl(s->u.next->name));
  if (checkDecls)
    symtab_put(stab, s->u.next->name, TYPENAME);
  free(s);
  return (d);
}


void check_for_main_and_declare(astspec s, astdecl d)
{
  astdecl n = decl_getidentifier(d);

  assert(d->type == DECLARATOR);
  assert(d->decl->type == DFUNC ||
         /* DF-C */ d->decl->type == DDFCFUNC);

  if (strcmp(n->u.id->name, "main") == 0)
  {
    n->u.id = Symbol(MAIN_NEWNAME);         /* Catch main()'s definition */
    hasMainfunc = 1;

    /* Now check for return type and # parameters */
    /* It d != NULL then its parameters is either (id or idlist) or
     * (paramtype or parmatypelist). If it is a list, assume the
     * standard 2 params, otherwise, we guess the single argument
     * must be the type "void" which means no params.
     * In any case, we always force main have (argc, argv[]).
     */
    if(!__has_dfc)
    {
      if (d->decl->u.params == NULL || d->decl->u.params->type != DLIST)
        d->decl->u.params =
            ParamList(
              ParamDecl(
                Declspec(SPEC_int),
                Declarator( NULL, IdentifierDecl( Symbol("_argc_ignored") ) )
              ),
              ParamDecl(
                Declspec(SPEC_char),
                Declarator(Speclist_right( Pointer(), Pointer() ),
                          IdentifierDecl( Symbol("_argv_ignored") ))
              )
            );
    }
    
    mainfuncRettype = 0; /* int */
    if (s != NULL)
    {
      for (; s->type == SPECLIST && s->subtype == SPEC_Rlist; s = s->u.next)
        if (s->body->type == SPEC && s->body->subtype == SPEC_void)
        {
          s = s->body;
          break;
        };
      if (s->type == SPEC && s->subtype == SPEC_void)
        mainfuncRettype = 1; /* void */
    }
  }
  if (symtab_get(stab, n->u.id, FUNCNAME) == NULL)/* From earlier declaration */
    symtab_put(stab, n->u.id, FUNCNAME);
}


/* For each variable/typename in the given declaration, add pointers in the
 * symbol table entries back to the declaration nodes.
 */
void add_declaration_links(astspec s, astdecl d)
{
  astdecl ini = NULL;

  if (d->type == DLIST && d->subtype == DECL_decllist)
  {
    add_declaration_links(s, d->u.next);
    d = d->decl;
  }
  if (d->type == DINIT) d = (ini = d)->decl;   /* Skip the initializer */
  assert(d->type == DECLARATOR);
  if (d->decl != NULL && d->decl->type != ABSDECLARATOR)
  {
    symbol  t = decl_getidentifier_symbol(d->decl);
    stentry e = isTypedef ?
                symtab_get(stab,t,TYPENAME) :
                symtab_get(stab,t,(decl_getkind(d)==DFUNC) ? FUNCNAME : IDNAME);
    e->spec  = s;
    e->decl  = d;
    e->idecl = ini;
  }
}


void parse_error(int exitvalue, char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  fprintf(stderr, "(%s, line %d)\n\t", sc_original_file(), sc_original_line());
  vfprintf(stderr, format, ap);
  va_end(ap);
  if (strcmp(sc_original_file(), "injected_code") == 0)
    fprintf(stderr, "\n>>>>>>>\n%s\n>>>>>>>\n", parsingstring);
  _exit(exitvalue);
}


void parse_warning(char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  fprintf(stderr, "[warning] ");
  vfprintf(stderr, format, ap);
  va_end(ap);
}


aststmt parse_file(char *fname, int *error)
{
  *error = 0;
  if ( (yyin = fopen(fname, "r")) == NULL )
    return (NULL);
  sc_set_filename(fname);      /* Inform the scanner */
  *error = yyparse();
  // if(yyin)
    fclose(yyin);                /* No longer needed */
  return (pastree);
}


#define PARSE_STRING_SIZE 8192


astexpr parse_expression_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_EXPRESSION);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_expr );
}


aststmt parse_blocklist_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_BLOCKLIST);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


aststmt parse_and_declare_blocklist_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_BLOCKLIST);

  savecD = checkDecls;
  checkDecls = 1;         /* Do check identifiers & do declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


aststmt parse_transunit_string(char *format, ...)
{
  static char s[PARSE_STRING_SIZE];
  int    savecD;

  va_list ap;
  va_start(ap, format);
  vsnprintf(s, PARSE_STRING_SIZE-1, format, ap);
  va_end(ap);
  parsingstring = s;
  sc_scan_string(s);
  sc_set_start_token(START_SYMBOL_TRANSUNIT);

  savecD = checkDecls;
  checkDecls = 0;         /* Don't check identifiers & don't declare them */
  yyparse();
  checkDecls = savecD;    /* Reset it */
  return ( pastree_stmt );
}


void dfc_insert_active_data_decl_and_update_persize(struct dfc_insert_detail *detail)
{

  //ljr:  定义变量和记录开始时间
  if(sched_info)
  {
    (*detail).body = BlockList((*detail).body, verbit("  struct timeval begin;"));
    (*detail).body = BlockList((*detail).body, verbit("  struct timeval end;"));
    (*detail).body = BlockList((*detail).body, verbit("  gettimeofday(&begin,NULL);\n"));    
  }



  if(detail->inParams == NULL)
  {
    (*detail).body = BlockList((*detail).body, verbit("  int DF_count;\n"));
  }
  else
  {
    astdecl params = detail->inParams;

    while(params->type == DPARAM || 
        (params->type == DLIST && params->subtype == DECL_paramlist))
    {
      char *name;
      name = dfc_get_decl_identifier_name(params);
      (*detail).body = BlockList((*detail).body, 
                               (params->type == DPARAM ? 
                 Declaration(params->spec, params->decl) :
                 Declaration(params->decl->spec, params->decl->decl)));
      (*detail).body = BlockList((*detail).body, verbit("  DF_persize_%s = sizeof(%s);",
                                 name, name));
      ++(*detail).in_params_count;
      
    if(params->type == DPARAM)
      {
        break;
      }
        
      else if(params->type == DLIST && params->subtype == DECL_paramlist)
      {
        params = params->u.next;
      }
      else
        parse_error(68, "dfc func def broken.\n");
    }
  }

  if(detail->outParams)
  {
    astdecl params = detail->outParams;

    while(params->type == DPARAM || 
        (params->type == DLIST && params->subtype == DECL_paramlist))
    {
      char *name;
      name = dfc_get_decl_identifier_name(params);
      (*detail).body = BlockList((*detail).body, 
                               (params->type == DPARAM ?
                 Declaration(params->spec, params->decl) :
                 Declaration(params->decl->spec, params->decl->decl)));
      (*detail).body = BlockList((*detail).body, verbit("  DF_persize_%s = sizeof(%s);",
                                 name, name));
      ++(*detail).out_params_count;

    if(params->type == DPARAM)
      {
        break;
      }
        
      else if(params->type == DLIST && params->subtype == DECL_paramlist)
      {
        params = params->u.next;
      }
      else
        parse_error(68, "dfc func def broken.\n");
    }
  }

  /*ljr:没必要
  if(detail->in_params_count == 0)
  {
    (*detail).body = BlockList((*detail).body,
                       verbit("  int DF_FN_item_index = DF_FN_%s.item_index;\n", 
                    detail->func_name));
  }
  */
}


void dfc_insert_get_active_data_call(struct dfc_insert_detail *detail)
{
  char str[1024];
  int strLength = 0;

  if(detail->in_params_count == 0)
    snprintf(str+strLength, 1023-strLength, 
             "  DF_SOURCE_Get_And_Update(&DF_FN_%s, &DF_count);", detail->func_name);
  else
  {
    snprintf(str+strLength, 1023-strLength, "  int DF_count = DF_AD_GetData(&DF_FN_%s", detail->func_name);
    strLength = strlen(str);
    
    astdecl params = detail->inParams;
    for(int Counter = 0; 
        Counter < detail->in_params_count; 
        ++Counter, params = params->u.next)
    {
      snprintf(str+strLength, 1023-strLength, 
                 ", &%s, DF_persize_%s", 
                 dfc_get_decl_identifier_name(params),
                 dfc_get_decl_identifier_name(params));
      
      strLength = strlen(str);
    }
    
    snprintf(str+strLength, 1023-strLength, ");");
  }
  
  (*detail).body = BlockList((*detail).body, verbit(str));
  

} 

//wcy
void dfc_insert_get_item_index(struct dfc_insert_detail *detail,char* name)
{
  //wcy
  if(detail->inParams==NULL)
    (*detail).body = BlockList((*detail).body, verbit("int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,\"%s\");"
                ,name));
}

void dfc_insert_update_active_data_call(struct dfc_insert_detail *detail)
{
  char str[1024];
  int strLength = 0;

  snprintf(str+strLength, 1023-strLength, 
           "  DF_AD_UpData(DF_count,&DF_TFL_TABLE, &DF_FN_%s",
           detail->func_name);
  strLength = strlen(str);
  
  astdecl params = detail->outParams;
  for(int Counter = 0; 
      Counter < detail->out_params_count; 
      ++Counter, params = params->u.next)
  {
    snprintf(str+strLength, 1023-strLength, 
             ", &%s, DF_persize_%s", 
             dfc_get_decl_identifier_name(params),
             dfc_get_decl_identifier_name(params));
    
    strLength = strlen(str);
  }
  
  snprintf(str+strLength, 1023-strLength, ");");
  
  (*detail).body = BlockList((*detail).body, verbit(str));

  //ljr: 输出调度信息
  if(sched_info)
  {
    (*detail).body = BlockList((*detail).body, verbit("  gettimeofday(&end,NULL);"));
    (*detail).body = BlockList((*detail).body, verbit("  int tid = gettid();//获取线程号"));
    (*detail).body = BlockList((*detail).body, verbit("  long start_time, end_time;\n"));
    (*detail).body = BlockList((*detail).body, verbit("  start_time = (begin.tv_sec - program_start.tv_sec) *1000000 + (begin.tv_usec - program_start.tv_usec);"));
    (*detail).body = BlockList((*detail).body, verbit("  end_time = (end.tv_sec - program_start.tv_sec) *1000000 + (end.tv_usec - program_start.tv_usec);"));
    (*detail).body = BlockList((*detail).body, verbit("  char s[20];\n"
                                                      "  sprintf(s, \"/proc/%%d/stat\", tid);\n"
                                                      "  FILE *fp_temp = fopen(s, \"r\");\n"
                                                      "  for(int i=0; i<39; i++)\n"
                                                      "    fscanf(fp_temp,\"%%s\",&s);\n"
                                                      "  fclose(fp_temp);"));
    (*detail).body = BlockList((*detail).body, verbit("  pthread_mutex_lock(&sched_info_mutex);\n"));
    (*detail).body = BlockList((*detail).body, verbit("  fprintf(fp_sche, \"func:%%s, pass:%%d, tid:%%d, core:%%s, start:%%ldus, end:%%ldus\\n\","
                                                      "  __FUNCTION__, DF_count, tid, s,start_time, end_time);\n"));
    (*detail).body = BlockList((*detail).body, verbit("  pthread_mutex_unlock(&sched_info_mutex);\n"));   
  }

}
        
void dfc_use_detail_to_fill_main_ad_and_fn_init(struct dfc_insert_detail *detail)
{

  astdecl params = detail->outParams;
  for(int Counter = 0; Counter < detail->out_params_count; ++Counter, params = params->u.next)
  {
    char *name;
    //ljr
    name = dfc_get_decl_identifier_name(params);
    //wcy
    dfc_main_subtree_for_ad = BlockList(dfc_main_subtree_for_ad, 
                                          verbit("DF_ADInit(&DF_AD_%s, sizeof(%s), DF_fanout_%s);\n",
                                                 dfc_get_decl_identifier_name(params),
                                                 (params->type == DPARAM) ? use_params_to_get_spec_name(params) :use_params_to_get_spec_name(params->decl) ,
                                                 dfc_get_decl_identifier_name(params)));
  }  


                                
              
  char str[1024];
  int strLength = 0;
  
  str[0] = '\0';
  params = detail->outParams;
  for(int Counter = 0;
      Counter < detail->out_params_count;
      ++Counter, params = params->u.next)
  {
    char *name;
  name = dfc_get_decl_identifier_name(params);
  snprintf(str+strLength, 1023-strLength, ", &DF_AD_%s", 
                                          dfc_get_decl_identifier_name(params));
  strLength = strlen(str);
  }
  
  dfc_main_subtree_for_fn = BlockList(dfc_main_subtree_for_fn,
                                      verbit("DF_FNInit2(&DF_FN_%s, %d%s);\n",
                                             detail->func_name, detail->out_params_count, str));
  
  str[0] = '\0';
  strLength = 0;
  params = detail->inParams;
  for(int Counter = 0;
      Counter < detail->in_params_count;
      ++Counter, params = params->u.next)
  {
    char *name;
  name = dfc_get_decl_identifier_name(params);
  snprintf(str+strLength, 1023-strLength, ", &DF_AD_%s", 
                                          dfc_get_decl_identifier_name(params));
  strLength = strlen(str);      
  }

  dfc_main_subtree_for_fn = BlockList(dfc_main_subtree_for_fn,
                                      verbit("DF_FNInit1(&DF_FN_%s, &%s, \"%s\", %d%s);\n",
                                             detail->func_name, 
                       detail->func_name, 
                       detail->func_name, 
                                             detail->in_params_count,
                                             str));
}


//wcy
char* use_params_to_get_spec_name(astdecl params)
{
  char* name=(char *)malloc(200);
  //wcy
  memset(name,0,200); 
  char* tmp_name;
  if(params->spec!=NULL)
  {
    tmp_name=SPEC_symbols[params->spec->subtype];
  }

  //SPEC
  if(params->spec->type==1)
  {
    strcat(name,tmp_name);
    if(params->spec->subtype==16)
    {
    }
    /*
    else if
    ...
    */
    else//一些常见子类型
    {
    }
  }

  //其他五大类
  else
  {
    //SUE
    if(params->spec->type==4)
    {
      strcat(name,tmp_name);
      if(params->spec->subtype==SPEC_struct)//类型为struct的情况
      {
        char* sub_name=params->spec->name->name;
        strcat(name," ");
        strcat(name,sub_name);
      }
    }

    //SPECLIST
    if(params->spec->type==6)
    {
      astspec tmp_spec=params->spec;
      strcat(name,SPEC_symbols[tmp_spec->body->subtype]);
      strcat(name," ");//spec链的情况下空格放在后面

      astdecl tmp_decl=ParamDecl(tmp_spec->u.next,NULL);
      strcat(name,use_params_to_get_spec_name(tmp_decl));

      //while(tmp_spec->u.next!=NULL)
      //{
      //  tmp_spec=tmp_spec->u.next; 
      //  char* sub_name=SPEC_symbols[tmp_spec->subtype];
      //  strcat(name," ");
      //  strcat(name,sub_name);
      //}
    }

  }

  /*需要考虑一些子结点不存在的情况*/
  if(params->decl!=NULL&&params->decl->spec!=NULL&&params->decl->spec->subtype==SPEC_star)//类型为指针的情况
  {
    char* sub_name=SPEC_symbols[params->decl->spec->subtype];
    strcat(name," ");
    strcat(name,sub_name);
  }


  if(name==NULL)
  {
    return "NULL";
  }
  return name;
}

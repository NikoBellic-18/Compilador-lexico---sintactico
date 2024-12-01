/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPILERSINTACTIC_TAB_H_INCLUDED
# define YY_YY_COMPILERSINTACTIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    IFR = 259,                     /* IFR  */
    STG = 260,                     /* STG  */
    FLT = 261,                     /* FLT  */
    MAS = 262,                     /* MAS  */
    MEN = 263,                     /* MEN  */
    MUL = 264,                     /* MUL  */
    DIV = 265,                     /* DIV  */
    TRUE = 266,                    /* TRUE  */
    FALSE = 267,                   /* FALSE  */
    VARS = 268,                    /* VARS  */
    VARI = 269,                    /* VARI  */
    VARF = 270,                    /* VARF  */
    VARB = 271,                    /* VARB  */
    CDO = 272,                     /* CDO  */
    CWHILE = 273,                  /* CWHILE  */
    FWHILE = 274,                  /* FWHILE  */
    CFOR = 275,                    /* CFOR  */
    FFOR = 276,                    /* FFOR  */
    CIF = 277,                     /* CIF  */
    FIF = 278,                     /* FIF  */
    CEL = 279,                     /* CEL  */
    FUN = 280,                     /* FUN  */
    RET = 281,                     /* RET  */
    STH = 282,                     /* STH  */
    CASE = 283,                    /* CASE  */
    BRK = 284,                     /* BRK  */
    DUT = 285,                     /* DUT  */
    TRY = 286,                     /* TRY  */
    CATCH = 287,                   /* CATCH  */
    ASIG = 288,                    /* ASIG  */
    IGU = 289,                     /* IGU  */
    DIF = 290,                     /* DIF  */
    MEQ = 291,                     /* MEQ  */
    MAQ = 292,                     /* MAQ  */
    MEIQ = 293,                    /* MEIQ  */
    MAIQ = 294,                    /* MAIQ  */
    AND = 295,                     /* AND  */
    NEG = 296,                     /* NEG  */
    OR = 297,                      /* OR  */
    MOD = 298,                     /* MOD  */
    APT = 299,                     /* APT  */
    CPT = 300,                     /* CPT  */
    ACH = 301,                     /* ACH  */
    CCH = 302,                     /* CCH  */
    ENDVAR = 303,                  /* ENDVAR  */
    TWP = 304,                     /* TWP  */
    COMA = 305                     /* COMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 146 "compilersintactic.y"

    int intval;
    float floatval;
    char *strval;
    int boolval;

#line 121 "compilersintactic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COMPILERSINTACTIC_TAB_H_INCLUDED  */

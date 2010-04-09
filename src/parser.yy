%{ /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include "comando.h"
#include "comando_write.h"
#include "expressao.h"
#include "fator.h"
#include "exp_aritmetica.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="tiny"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN TOKENS ***/

%union {
    char				charVal;
    double				doubleVal;
	class Expressao *	expVal;
	std::string		*	strVal;
	class Comando	*	cmdVal;
}

%token					END	     0	"end of file"
%token					SQRT		"square root"
%token					WRITESTR	"writeStr"
%token					WRITEVAR	"writeVar"
%token					WRITELN		"writeln"
%token					OR			"or operator"
%token					AND			"and operator"
%token					NOT			"not operator"
%token	<doubleVal> 	DOUBLE		"double"
%token	<strVal>		STRING		"string"
%token	<charVal>		VARNAME		"variable name"

%type	<cmdVal>		comando
%type	<expVal>		exp_arit
%type	<expVal>		exp_mul
%type	<expVal>		fator

%left '+'

/* start symbol is named "start" */
%start program

 /*** END TOKENS ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

program: exp_arit					{ driver.exp_aritmetica = $1; }
	   | comando					{ driver.comando = $1; }
;

comando: WRITESTR '(' STRING ')'	{ $$ = new ComandoWrite(writeStr, $3); }
	   | WRITEVAR '(' VARNAME ')'	{ $$ = new ComandoWrite(writeVar,NULL,$3); }
	   | WRITELN					{ $$ = new ComandoWrite(writeln); }

exp_arit: exp_arit '+' exp_mul	{ $$ = new ExpressaoAritmetica($1, $3, Adicao);}
		| exp_arit '-' exp_mul	{ $$ = new ExpressaoAritmetica($1, $3, 
											Subtracao); 
								}
		| exp_mul				{ $$ = $1; }
;

exp_mul: exp_mul '*' fator	{ $$ = new ExpressaoAritmetica($1, $3, 
											Multiplicacao); 
							}
	   | exp_mul '/' fator	{ $$ = new ExpressaoAritmetica($1, $3, Divisao); }
	   | fator				{ $$ = $1; }
;

fator: DOUBLE				{ $$ = new Fator(Numero, $1); }
	 | VARNAME				{ $$ = new Fator(Variavel, 0.0, NULL, $1); }
	 | '(' exp_arit ')'			{ $$ = new Fator(Parentesis, 0.0, $2); }
	 | SQRT '(' exp_arit ')'	{ $$ = new Fator(RaizQuadrada, 0.0, $3);}
;

%% /*** Additional Code ***/

void tiny::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

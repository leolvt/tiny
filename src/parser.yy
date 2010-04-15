%code requires{ 
/*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include "comando.h"
#include "lista_comandos.h"
#include "comando_write.h"
#include "comando_read.h"
#include "comando_atribuicao.h"
#include "expressao.h"
#include "expressaoBool.h"
#include "expressaoRel.h"
#include "exp_aritmetica.h"
#include "fator.h"
#include "boolean.h"
#include "exp_booleana.h"
#include "exp_relacional.h"

}

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
	std::string		*	strVal;
	ListaComandos	*	listaVal;
	Expressao		*	expVal;
	Comando			*	cmdVal;
}

%token					END	     0	"end of file"
%token					SQRT		"square root"
%token					WRITESTR	"writeStr"
%token					WRITEVAR	"writeVar"
%token					WRITELN		"writeln"
%token					READ		"read"
%token					OR			"or operator"
%token					AND			"and operator"
%token					NOT			"not operator"
%token					GTE			">="
%token					LTE			"<="
%token					ATRIBUI		":="
%token					ENDP		"endp"
%token	<doubleVal> 	DOUBLE		"double"
%token	<boolVal> 	BOOL		"bool"
%token	<strVal>		STRING		"string"
%token	<charVal>		VARNAME		"variable name"

%type	<listaVal>		lista_comandos
%type	<cmdVal>		comando
%type	<expVal>		exp_arit
%type	<expVal>		exp_mul
%type	<expVal>		fator
%type	<expVal>		exp_bool
%type	<expVal>		exp_rel
%type	<expVal>		bool

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

program:  lista_comandos ENDP		{ driver.programa = $1; }
;

lista_comandos: comando ';'			{ $$ = new ListaComandos($1); }
			  | lista_comandos comando ';' 
									{ $$ = $1; $1->AdicionaComando($2); }
;

comando: WRITESTR '(' STRING ')'	{ $$ = new ComandoWrite(writeStr, $3); }
	   | WRITEVAR '(' VARNAME ')'	{ $$ = new ComandoWrite(writeVar,NULL,$3); }
	   | WRITELN					{ $$ = new ComandoWrite(writeln); }
	   | READ '(' VARNAME ')'		{ $$ = new ComandoRead($3); }
	   | VARNAME ATRIBUI exp_arit	{ $$ = new ComandoAtribuicao($1, $3); }
;

exp_bool: exp_rel			{ $$ = $1; }
	| exp_bool OR exp_rel		{ $$ = new ExpressaoBooleana($1, $3, op_or); }
	| exp_bool AND exp_rel		{ $$ = new ExpressaoBooleana($1, $3, op_and); }
	| NOT exp_bool			{ $$ = new ExpressaoBooleana($1, NULL, op_not); }
;

exp_rel: exp_arit '>' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_>); }
	| exp_arit GTE exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_>=); }
	| exp_arit '<' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_<); }
	| exp_arit LTE exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_<=); }
	| exp_arit '=' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_=); }
	| boolean			{ $$ = $1 }
;
	
boolean: BOOL			{ $$ = new Boolean(Valor, $1); }
	| '(' exp_bool ')'	{ $$ = new Boolean(Parentesis, false, $2); }
;

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

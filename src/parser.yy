%{ 
/*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <vector>
#include "boolean.h"
#include "comando.h"
#include "procedimento.h"
#include "comando_atribuicao.h"
#include "comando_for.h"
#include "comando_call.h"
#include "comando_global.h"
#include "comando_if.h"
#include "comando_local.h"
#include "comando_read.h"
#include "comando_write.h"
#include "comando_while.h"
#include "expressao.h"
#include "expressaoBool.h"
#include "exp_aritmetica.h"
#include "exp_booleana.h"
#include "exp_relacional.h"
#include "fator.h"
#include "lista_comandos.h"
#include "lista_expressoes.h"
#include "lista_procedimentos.h"
#include "lista_variaveis.h"
#include "programa.h"

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
    char							charVal;
    double							doubleVal;
    bool							boolVal;
	std::string					*	strVal;
	class Comando				*	cmdVal;
	class Expressao				*	expVal;
	class ExpressaoBool			*	expBool;
	class ListaComandos			*	listaCmdVal;
	class ListaProcedimentos	*	listaProcVal;
	class ListaExpressoes		*	listaExpVal;
	class ListaVariaveis		*	listaVar;
	class Procedimento			*	proced;
	class Programa				*	prog;
}

%token					FIM		0	"end of file"
%token					ENDP		"endp"
%token					SQRT		"square root"
%token					WRITESTR	"writeStr"
%token					WRITEVAR	"writeVar"
%token					WRITELN		"writeln"
%token					READ		"read"
%token					AND			"and operator"
%token					OR			"or operator"
%token					NOT			"not operator"
%token					GTE			">="
%token					LTE			"<="
%token					NEQ			"<>"
%token					ATRIBUI		":="
%token					FOR			"for"
%token					TO			"to"
%token					DOWNTO		"downto"
%token					DO			"do"
%token					IF			"if"
%token					THEN		"then"
%token					ELSE		"else"
%token					ENDIF		"endif"
%token					WHILE		"while"
%token					ENDW		"endw"
%token					END			"end of block"
%token					ENDFOR		"endfor"
%token					GLOBAL		"global declaration"
%token					LOCAL		"local declaration"
%token					PROC		"proc"
%token					ENDPROC		"endproc"
%token					CALL		"function call"
%token	<doubleVal> 	DOUBLE		"double"
%token	<boolVal>		BOOL		"bool"
%token	<strVal>		ID			"identifier"
%token	<strVal>		STRING		"string"
%token	<charVal>		VARNAME		"variable name"

%type	<prog>			programa
%type	<listaCmdVal>	lista_comandos
%type	<listaProcVal>	lista_procedimentos
%type	<listaExpVal>	lista_expressoes
%type	<listaVar>		lista_param_formais
%type	<listaExpVal>	lista_param_reais
%type 	<listaVar>		lista_variaveis
%type	<proced>		procedimento
%type	<cmdVal>		comando
%type	<cmdVal>		comando_call
%type	<cmdVal>		comando_for
%type	<cmdVal>		comando_local
%type	<cmdVal>		comando_global
%type	<cmdVal>		comando_if
%type	<cmdVal>		comando_while
%type	<expVal>		exp_arit
%type	<expVal>		exp_mul
%type	<expVal>		fator
%type	<expBool>		exp_bool
%type	<expBool>		exp_and
%type	<expBool>		exp_not
%type	<expBool>		exp_or
%type	<expBool>		exp_rel
%type	<expBool>		boolean

/* start symbol is named "start" */
%start start

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

start: programa	{driver.programa = $1;}
;

programa: comando_global ';' lista_procedimentos ENDP 		
		{ $$ = new Programa($1,$3); }
;

lista_procedimentos: procedimento	{ $$ = new ListaProcedimentos($1); }
		           | lista_procedimentos procedimento	
							{ $$ = $1; $1->AdicionaProcedimento($2); }
;

procedimento:	PROC ID '(' lista_param_formais ')' comando_local lista_comandos	ENDPROC
						{ $$ = new Procedimento($2, $4, $6, $7); }
;

lista_comandos: comando ';'			{ $$ = new ListaComandos($1); }
			  | lista_comandos comando ';' 
									{ $$ = $1; $1->AdicionaComando($2); }
;

lista_expressoes: exp_arit			{ $$ = new ListaExpressoes($1); }
				| lista_expressoes ',' exp_arit
									{ $$ = $1; $1->AdicionaExpressao($3); }
;

lista_variaveis: VARNAME			{ $$ = new ListaVariaveis($1); }
				| lista_variaveis ',' VARNAME
									{ $$ = $1; $1->adicionaVar($3); }
;

lista_param_formais: /* empty */	{ $$ = new ListaVariaveis(); }
				   | lista_variaveis { $$ = $1;}

lista_param_reais: /* empty */		{ $$ = NULL; }
				 | lista_expressoes { $$ = $1; }
;

comando: WRITESTR '(' STRING ')'	{ $$ = new ComandoWrite(writeStr, $3); }
	   | WRITEVAR '(' VARNAME ')'	{ $$ = new ComandoWrite(writeVar,NULL,$3); }
	   | WRITELN					{ $$ = new ComandoWrite(writeln); }
	   | READ '(' VARNAME ')'		{ $$ = new ComandoRead($3); }
	   | VARNAME ATRIBUI exp_arit	{ $$ = new ComandoAtribuicao($1, $3); }
	   | comando_for				{ $$ = $1; }
	   | comando_if					{ $$ = $1; }
	   | comando_while				{ $$ = $1; }
	   | comando_call				{ $$ = $1; }
;

comando_call: CALL ID '(' lista_param_reais ')'
			{ $$ = new ComandoCall($2, $4); }
;

comando_local: /* empty */				{ $$ = new ComandoLocal(); }
			  | LOCAL lista_variaveis ';'	{ $$ = new ComandoLocal($2); }
;

comando_global: /* empty */				{ $$ = new ComandoGlobal(); }
			  | GLOBAL lista_variaveis	{ $$ = new ComandoGlobal($2); }
;

comando_for: FOR VARNAME ATRIBUI exp_arit TO exp_arit DO lista_comandos END 
			{ $$ = new ComandoFor(up, $2, $4, $6, $8); }
	| FOR VARNAME ATRIBUI exp_arit DOWNTO exp_arit DO lista_comandos END
			{ $$ = new ComandoFor(down, $2, $4, $6, $8); }
	| FOR VARNAME ATRIBUI exp_arit TO exp_arit DO lista_comandos ENDFOR
			{ $$ = new ComandoFor(up, $2, $4, $6, $8); }
	| FOR VARNAME ATRIBUI exp_arit DOWNTO exp_arit DO lista_comandos ENDFOR
			{ $$ = new ComandoFor(down, $2, $4, $6, $8); }
;

comando_if: IF exp_bool THEN lista_comandos END				{ $$ = new ComandoIf($2, $4); }
	| IF exp_bool THEN lista_comandos ELSE lista_comandos END	{ $$ = new ComandoIf($2, $4, $6); }
	| IF exp_bool THEN lista_comandos ENDIF				{ $$ = new ComandoIf($2, $4); }
	| IF exp_bool THEN lista_comandos ELSE lista_comandos ENDIF	{ $$ = new ComandoIf($2, $4, $6); }
;

comando_while: WHILE exp_bool DO lista_comandos END	{ $$ = new ComandoWhile($2, $4); }
		| WHILE exp_bool DO lista_comandos ENDW	{ $$ = new ComandoWhile($2, $4); }
;

exp_bool: exp_or	{ $$ = $1; }
;

exp_or: exp_or OR exp_and	{ $$ = new ExpressaoBooleana($1, $3, op_or); }
	| exp_and		{ $$ = $1; }
;

exp_and: exp_and AND exp_not	{ $$ = new ExpressaoBooleana($1, $3, op_and); }
	| exp_not		{ $$ = $1; }
;

exp_not: NOT exp_rel	{ $$ = new ExpressaoBooleana($2, NULL, op_not); }
	| exp_rel	{ $$ = $1; }
;

exp_rel: exp_arit '>' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_GT); }
	| exp_arit GTE exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_GTE); }
	| exp_arit '<' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_LT); }
	| exp_arit LTE exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_LTE); }
	| exp_arit '=' exp_arit		{ $$ = new ExpressaoRelacional($1, $3, op_EQ); }
	| exp_arit 'NEQ' exp_arit	{ $$ = new ExpressaoRelacional($1, $3, op_NEQ); }
	| '(' exp_bool ')'		{ $$ = $2; }
	| boolean			{ $$ = $1; }
;
	
boolean: BOOL			{ $$ = new Boolean($1); }	
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

fator: /* empty 			{ $$ = new Fator(Numero, 0.0); } */
	  DOUBLE				{ $$ = new Fator(Numero, $1); }
	 | VARNAME				{ $$ = new Fator(Variavel, 0.0, NULL, $1); }
	 | '-' VARNAME				{ $$ = new ExpressaoAritmetica(
										new Fator(Numero, 0.0, NULL),
										new Fator(Variavel, 0.0, NULL, $2),
										Subtracao);  }
	 | '(' exp_arit ')'			{ $$ = new Fator(Parentesis, 0.0, $2); }
	 | '-' '(' exp_arit ')'			{ $$ = new ExpressaoAritmetica(
											new Fator(Numero, 0.0),
											new Fator(Parentesis, 0.0, $3),
											Subtracao); }
	 | SQRT '(' exp_arit ')'	{ $$ = new Fator(RaizQuadrada, 0.0, $3);}
	 | '-' SQRT '(' exp_arit ')'	{ $$ = new ExpressaoAritmetica(
											new Fator(Numero, 0.0),
											new Fator(RaizQuadrada, 0.0, $4),
											Subtracao); 
									}
;

%% /*** Additional Code ***/

void tiny::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

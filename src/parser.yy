%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start start

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
    int  			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
}

%token				END	     0	"end of file"
%token				EOL			"end of line"
%token <integerVal> INTEGER		"integer"
%token <doubleVal> 	DOUBLE		"double"

%type <doubleVal>	exp

%left '+'

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


start: END
	 | line start
;

line: EOL
	| exp EOL { std::cout << "> " << $1 << std::endl; }
	| exp END { std::cout << "> " << $1 << std::endl; }
;

exp: DOUBLE		{ $$ = $1; }
   | exp '+' exp { $$ = $1 + $3; }
;

%% /*** Additional Code ***/

void tiny::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

%{ /*** C/C++ Declarations ***/

#include <iostream>
#include <string>
#include <cstring>
#include "scanner.h"

using namespace std;

/* import the parser's token type into a local typedef */
typedef tiny::Parser::token token;
typedef tiny::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "TinyFlexLexer" */
%option prefix="Tiny"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option noyywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

D	[0-9]
L	[a-zA-Z_]
H	[a-fA-F0-9]
E	[Ee][+-]?{D}+

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN RULES ***/

 /* reserved words */
"sqrt"		{ return token::SQRT; }
"or"		{ return token::OR; }
"and"		{ return token::AND; }
"not"		{ return token::NOT; }
">="		{ return token::GTE; }
"<="		{ return token::LTE; }
"<>"		{ return token::NEQ; }
"writeStr"	{ return token::WRITESTR; }
"writeVar"	{ return token::WRITEVAR; }
"writeln"	{ return token::WRITELN; }
"read"		{ return token::READ; }
"end"		{ return token::END; }
"endfor"	{ return token::ENDFOR; }
"endp"		{ return token::ENDP; }
":="		{ return token::ATRIBUI; }
"for"		{ return token::FOR; }
"to"		{ return token::TO; }
"downto"	{ return token::DOWNTO; }
"do"		{ return token::DO; }
"if"		{ return token::IF; }
"then"		{ return token::THEN; }
"else"		{ return token::ELSE; }
"endif"		{ return token::ENDIF; }
"while"		{ return token::WHILE; }
"endw"		{ return token::ENDW; }
"local"		{ return token::LOCAL; }
"global"	{ return token::GLOBAL; }
"proc"		{ return token::PROC; }
"endproc"	{ return token::ENDPROC; }
"call"		{ return token::CALL; }


 /* Floating Point Number */
(({D}+"."{D}*)|("."{D}+)|({D}+)){E}? {
    yylval->doubleVal = atof(yytext);
    return token::DOUBLE;
}

 /* Boolean value */
"true"|"false" {
    yylval->boolVal = (0 == strcmp( "true", yytext ) );
    return token::BOOL;
}

 /* string literal */
"\""([^"\""])*"\"" {
	yylval->strVal = new std::string(yytext);
	return token::STRING;
}

 /* Identifiers */
{L}({L}|{D}|"_")+	{
	yylval->strVal = new std::string(yytext);
	return token::ID;
}

 /* Variables */
{L} {
	yylval->charVal = yytext[0];
	return token::VARNAME;
}

 /* gobble up empty spaces */
[ \t\v\f\r]+ {
    yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
/*    return token::EOL; */
}

<<EOF>>	{ return token::FIM; }

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}

 /*** END RULES ***/

%% /*** Additional Code ***/

namespace tiny {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : TinyFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of TinyFlexLexer::yylex() is required to fill the
 * vtable of the class TinyFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int TinyFlexLexer::yylex()
{
    std::cerr << "in TinyFlexLexer::yylex() !" << std::endl;
    return 0;
}


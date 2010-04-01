%{ /*** C/C++ Declarations ***/

#include <iostream>

#include "scanner.h"

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
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN RULES ***/

 /* Floating Point Number */
([0-9]+"."[0-9]*)|("."[0-9]*) {
    yylval->doubleVal = atof(yytext);
    return token::DOUBLE;
}

sqrt	{
	return token::SQRT;
}

 /* Variables */
[A-Za-z] {
	yylval->charVal = yytext[0];
	return token::VARNAME;
}

 /* gobble up empty spaces */
[ \t\r]+ {
    yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
/*    return token::EOL; */
}

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

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int TinyFlexLexer::yywrap()
{
    return 1;
}

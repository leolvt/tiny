#ifndef TINY_SCANNER_H
#define TINY_SCANNER_H

// Flex expects the signature of yylex to be defined in the macro YY_DECL, and
// the C++ parser expects it to be declared. We can factor both as follows.

#ifndef YY_DECL

#define	YY_DECL						\
    tiny::Parser::token_type				\
    tiny::Scanner::lex(				\
	tiny::Parser::semantic_type* yylval,		\
	tiny::Parser::location_type* yylloc		\
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer TinyFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#include "parser.h"

namespace tiny {

/** Scanner is a derived class to add some extra function to the scanner
 * class. Flex itself creates a class named yyFlexLexer, which is renamed using
 * macros to TinyFlexLexer. However we change the context of the generated
 * yylex() function to be contained within the Scanner class. This is required
 * because the yylex() defined in TinyFlexLexer has no parameters. */
class Scanner : public TinyFlexLexer
{
public:
    /** Create a new scanner object. The streams arg_yyin and arg_yyout default
     * to cin and cout, but that assignment is only made when initializing in
     * yylex(). */
    Scanner(std::istream* arg_yyin = 0,
	    std::ostream* arg_yyout = 0);

    /** Required for virtual functions */
    virtual ~Scanner();

    /** This is the main lexing function. It is generated by flex according to
     * the macro declaration YY_DECL above. The generated bison parser then
     * calls this virtual function to fetch new tokens. */
    virtual Parser::token_type lex(
	Parser::semantic_type* yylval,
	Parser::location_type* yylloc
	);

    /** Enable debug output (via arg_yyout) if compiled into the scanner. */
    void set_debug(bool b);
};

} // namespace tiny

#endif // TINY_SCANNER_H

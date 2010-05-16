#ifndef		TINY_DEFS_H
#define		TINY_DEFS_H

#include <map>
#include <stack>
#include <string>

namespace tiny {

class Procedimento;

class Erro
{
	private:
		std::string msg;

	public:
		Erro(std::string msg);
		std::string obtemMsg();
};

typedef std::map<std::string, Procedimento *> Procedimentos;
typedef std::map<char,double> Variaveis;
typedef std::stack<Variaveis> Pilha;

} /*namespace tiny */

#endif		/* TINY_DEFS_H */

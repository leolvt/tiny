#ifndef		TINY_LISTA_VARIAVEIS_H
#define		TINY_LISTA_VARIAVEIS_H

#include <vector>

namespace tiny {

class ListaVariaveis
{
	private:
		std::vector<char> lista_de_vars;

	public:
		ListaVariaveis(char c);
		void adicionaVar(char var_name);
		char operator[] ( unsigned int n );
		int tamanho();
};

} /* namespace tiny */

#endif		/* TINY_LISTA_VARIAVEIS_H */

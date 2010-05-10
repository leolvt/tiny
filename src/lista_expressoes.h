#ifndef		TINY_LISTA_EXPRESSOES_H
#define		TINY_LISTA_EXPRESSOES_H

#include <vector>
#include "expressao.h"

namespace tiny {

class ListaExpressoes
{
	private:
		std::vector<Expressao *> lista_de_expressoes;

	public:
		ListaExpressoes(Expressao * E);
		~ListaExpressoes();
		void AdicionaExpressao(Expressao * E);
		std::vector<double> Avalia(Contexto& C);
};

} /* namespace tiny */

#endif		/* TINY_LISTA_EXPRESSOES_H */

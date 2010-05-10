#include <vector>
#include "lista_expressoes.h"

namespace tiny {

/* ========================================================================== */

ListaExpressoes::ListaExpressoes(Expressao * E)
{
	if (E != NULL)
		lista_de_expressoes.push_back(E);
}

/* ========================================================================== */

ListaExpressoes::~ListaExpressoes()
{
	unsigned int i;
    for( i = 0 ; i < lista_de_expressoes.size() ; i++)
        delete lista_de_expressoes[i];
    lista_de_expressoes.clear();
}

/* ========================================================================== */

void ListaExpressoes::AdicionaExpressao(Expressao * E)
{
	this->lista_de_expressoes.push_back( E );
}

/* ========================================================================== */

std::vector<double> ListaExpressoes::Avalia(Contexto& C)
{
	/* Cria vetor de doubles */
	int num_exp = lista_de_expressoes.size();
	std::vector<double> resultado( num_exp ,0.0);

	unsigned int i;
	for (i = 0 ; i < lista_de_expressoes.size() ; i++ )
		resultado[i] = lista_de_expressoes[i]->Calcula(C);

	return resultado;
}

/* ========================================================================== */

} /* namespace tiny */

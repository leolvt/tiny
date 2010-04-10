#ifndef		TINY_COMANDO_ATRIBUICAO_H
#define		TINY_COMANDO_ATRIBUICAO_H

#include "comando.h"
#include "expressao.h"

namespace tiny {

class ComandoAtribuicao: public Comando
{
	private:
		char nomeVar;
		Expressao * exp;
	public:
		ComandoAtribuicao(char Var, Expressao * E);
		~ComandoAtribuicao();

		void Interpreta(Contexto& C);
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_ATRIBUICAO_H */

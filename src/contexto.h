#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <map>
#include <stack>
#include "registro_ativacao.h"

namespace tiny {

class Contexto 
{
	private:
		std::map<char,double> variaveis_globais;
		std::stack<RegistroAtivacao> pilha_chamada;

	public:
		Contexto();
		~Contexto();
		
		double obtemVariavel(char nomeVar);
		void defineVariavel(char nomeVar, double valor);
		void adicionaVariavel(char nomeVar, double valor);
		void adicionaRA(RegistroAtivacao RA);
		void removeRA();
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

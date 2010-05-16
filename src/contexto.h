#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <string>
#include "defs.h"

namespace tiny {

class Procedimento;

class Contexto 
{
	private:
		Procedimentos * procedimentos_do_prog;
		Variaveis variaveis_globais;
		Pilha pilha_chamada;

	public:
		Contexto();
		~Contexto();
		
		double obtemVariavel(char nomeVar);
		void defineVariavel(char nomeVar, double valor);
		void adicionaVariavel(char nomeVar, double valor);
		void adicionaRA();
		void removeRA();
		
		Procedimento * obtemProcedimento(std::string nome_procedimento);
		void defineProcedimentos(Procedimentos * procedimentos_do_prog);
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

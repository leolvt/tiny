#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <map>
#include <stack>
#include <string>
#include "procedimento.h"

namespace tiny {

class Erro
{
	private:
		std::string msg;

	public:
		Erro(std::string msg);
		std::string obtemMsg();
};

typedef std::map<char,double> Variaveis;

class Contexto 
{
	private:
		ListaProcedimentos * procedimentos_do_prog;
		Variaveis variaveis_globais;
		std::stack<Variaveis> pilha_chamada;

	public:
		Contexto();
		~Contexto();
		
		double obtemVariavel(char nomeVar);
		void defineVariavel(char nomeVar, double valor);
		void adicionaVariavel(char nomeVar, double valor);
		void adicionaRA();
		void removeRA();
		
		Procedimento * obtemProcedimento(std::string nome_procedimento);
		void defineProcedimentos(ListaProcedimentos * procedimentos_do_prog);
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

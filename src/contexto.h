#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <map>
#include <stack>
#include <string>

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
		std::map<char,double> variaveis_globais;
		std::stack<Variaveis> pilha_chamada;

	public:
		Contexto();
		~Contexto();
		
		double obtemVariavel(char nomeVar);
		void defineVariavel(char nomeVar, double valor);
		void adicionaVariavel(char nomeVar, double valor);
		void adicionaRA(Variaveis v);
		void removeRA();
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

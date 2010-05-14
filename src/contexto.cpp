#include <map>
#include <cctype>
#include <iostream>

#include "contexto.h"

namespace tiny {

/* ========================================================================== */
	
Erro::Erro(std::string msg)
{
	this->msg = msg;
}

/* ========================================================================== */

std::string Erro::obtemMsg()
{
	return this->msg;
}

/* ========================================================================== */

/* Construtor */
Contexto::Contexto() 
{
} 

/* ========================================================================== */

/* Destrutor
 * Esvazia as variáveis */
Contexto::~Contexto()
{
	this->variaveis_globais.clear();
}

/* ========================================================================== */

/* obtemVariavel
 * retorna o valor da variável 'nomeVar' */
double Contexto::obtemVariavel(char nomeVar )
{
	if ( isalpha(nomeVar) )
	{
		std::map<char,double>::iterator it;

		/* Primeira Tentativa: Variável Local */
		if ( !pilha_chamada.empty() )
		{
			it = pilha_chamada.top().find(nomeVar);
			if (it != pilha_chamada.top().end()) 
				return it->second;
		}
		
		/* Segunda Tentativa: Variável Global */
	    it = variaveis_globais.find(nomeVar);
		if ( it != variaveis_globais.end() ) 
			return it->second;
		else throw Erro("\nVariável inexistente: "+nomeVar);
	}
	else
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

/* defineVariavel
 * atribui 'valor' à variável 'nomeVar' */
void Contexto::defineVariavel(char nomeVar, double valor)
{
	if ( isalpha(nomeVar) )
	{
		/* Primeira Tentativa: Variáveis locais */
		if ( !pilha_chamada.empty() )
		{
			std::map<char,double>& vars = pilha_chamada.top();
			if ( vars.find(nomeVar) != vars.end() )
			{
				vars[nomeVar] = valor;
				return;
			}
		}
		
		/* Segunda Tentativa: Variáveis Globais */
		if ( variaveis_globais.find(nomeVar) != variaveis_globais.end() )
			variaveis_globais[nomeVar] = valor;
		else 
			throw Erro("\nVariável inexistente: "+nomeVar);
	}
	else
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

void Contexto::adicionaVariavel(char nomeVar, double valor)
{
	if ( isalpha(nomeVar) )
	{
		std::pair<char,double>  new_var(nomeVar,valor);
		bool OK = false;

		/* Primeira Tentativa: Variáveis Locais */
		if ( !pilha_chamada.empty() )
		{
			OK = pilha_chamada.top().insert(new_var).second;
			if (OK) return;
			else throw Erro("\nVariável já existe: "+nomeVar); 
		}

		/* Segunda Tentativa: Variáveis Globais */
		OK = variaveis_globais.insert(new_var).second;
		if ( !OK ) throw Erro("\nVariável global já existe: "+nomeVar);
	} 
	else 
		throw Erro("\nVariável inválida: "+nomeVar);
}

/* ========================================================================== */

void Contexto::adicionaRA(Variaveis v)
{
	pilha_chamada.push(v);
}

/* ========================================================================== */

void Contexto::removeRA()
{
	pilha_chamada.pop();
}

/* ========================================================================== */

} /* namespace tiny */


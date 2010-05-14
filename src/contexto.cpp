#include <map>
#include <cctype>
#include <iostream>

#include "contexto.h"

namespace tiny {

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
			it = pilha_chamada.top().obtemVars().find(nomeVar);
			if (it != pilha_chamada.top().obtemVars().end()) 
				return it->second;
		}
		
		/* Segunda Tentativa: Variável Global */
	    it = variaveis_globais.find(nomeVar);
		if ( it != variaveis_globais.end() ) 
			return it->second;
		else throw std::string("Erro!");
	}
	else
	{
		std::cerr << "Variavel a ser obtida é inválida: " << nomeVar 
			<< std::endl;
		return 0.0;
	}
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
			std::map<char,double>& vars = pilha_chamada.top().obtemVars();
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
			throw std::string("Erro!!");
	}
	else
	{
		std::cerr << "Variavel a ser definida é inválida: " << nomeVar 
			<< std::endl;
	}
}

/* ========================================================================== */

void Contexto::adicionaVariavel(char nomeVar, double valor)
{
	if ( isalpha(nomeVar) )
	{
		bool success = variaveis_globais.insert( 
				std::pair<char,double>(nomeVar,valor)
		).second;

		if ( !success )
		{
			std::cerr << "Variável já existe!" << std::endl;
		}
	} 
	else 
	{
		std::cerr << "Erro!!!" << std::endl;
	}
}

/* ========================================================================== */

void Contexto::adicionaRA(RegistroAtivacao RA)
{
	pilha_chamada.push(RA);
}

/* ========================================================================== */

void Contexto::removeRA()
{
	pilha_chamada.pop();
}

/* ========================================================================== */

} /* namespace tiny */


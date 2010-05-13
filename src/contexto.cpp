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
		return this->variaveis_globais[nomeVar];
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
		std::map<char,double>::iterator it;
		it = variaveis_globais.find(nomeVar);
		if ( it != variaveis_globais.end() )
			this->variaveis_globais[nomeVar] = valor;
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

} /* namespace tiny */


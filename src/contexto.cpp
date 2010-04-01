#include <vector>
#include <cctype>
#include <iostream>

#include "contexto.h"

namespace tiny {

/* ========================================================================== */

/* Construtor 
 * Inicia as 26 variáveis com valor nulo */
Contexto::Contexto()
{
	this->variaveis.resize(26, 1.3);
}

/* ========================================================================== */

/* Destrutor
 * Esvazia as variáveis */
Contexto::~Contexto()
{
	this->variaveis.clear();
}

/* ========================================================================== */

/* obtemVariavel
 * retorna o valor da variável 'nomeVar' */
double Contexto::obtemVariavel(char nomeVar )
{
	if ( isalpha(nomeVar) )
	{
		return this->variaveis[tolower(nomeVar) - 'a'];
	}
	else
	{
		std::cerr << "Variavel Inválida" << std::endl;
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
		this->variaveis[ tolower(nomeVar) - 'a' ] = valor;
	}
	else
	{
		std::cerr << "Variavel Inválida" << std::endl;
	}
}

/* ========================================================================== */

} /* namespace tiny */


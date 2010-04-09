#include <iostream>
#include "comando_read.h"

namespace tiny {

/* ========================================================================== */

ComandoRead::ComandoRead(char nomeVar)
{
	this->nomeVar = nomeVar;
}

/* ========================================================================== */

ComandoRead::~ComandoRead()
{
	this->nomeVar = '0';
}

/* ========================================================================== */

void ComandoRead::Interpreta(Contexto& C)
{
	double valor;
	std::cin >> valor;
	C.defineVariavel(this->nomeVar, valor);
}

/* ========================================================================== */

} /* namespace tiny */

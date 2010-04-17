#include <cmath>

#include "fator.h"

namespace tiny {

/* ========================================================================== */

Fator::Fator(TipoFator tipo, double numero, Expressao * Exp, char nomeVar )
{
	this->Exp = Exp;
	this->nomeVar = nomeVar;
	this->numero = numero;
	this->tipoFator = tipo;
}

/* ========================================================================== */

Fator::~Fator()
{
	if (this->Exp) delete Exp;
}

/* ========================================================================== */

double Fator::Calcula(Contexto& C)
{
	double res;

	switch (this->tipoFator)
	{
		case Numero:
			res = this->numero;
			break;
		case Variavel:
			res = C.obtemVariavel(this->nomeVar);
			break;
		case Parentesis:
			res = this->Exp->Calcula(C);
			break;
		case RaizQuadrada:
			res = sqrt(this->Exp->Calcula(C));
			break;
		case NumNeg:
			res = 0 - this->Exp->Calcula(C);
			break;
		default:
			res = 0.0;
			break;
	}

	return res;
}

/* ========================================================================== */

} /* namespace tiny */

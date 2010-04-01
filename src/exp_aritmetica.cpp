#include "exp_aritmetica.h"

namespace tiny {

/* ========================================================================== */

ExpressaoAritmetica::ExpressaoAritmetica( Expressao * Op1, Expressao * Op2, 
		TipoOper O )
{
	this->Oper1 = Op1;
	this->Oper2 = Op2;
	this->Op = O;
}

/* ========================================================================== */

ExpressaoAritmetica::~ExpressaoAritmetica()
{
	if ( this->Oper1 ) delete this->Oper1;
	if ( this->Oper2 ) delete this->Oper2;
}

/* ========================================================================== */

double ExpressaoAritmetica::Calcula(Contexto& C) 
{
	double res;

	switch (this->Op)
	{
		case Adicao: 
			res = this->Oper1->Calcula(C) + this->Oper2->Calcula(C);
			break;
		case Subtracao: 
			res = this->Oper1->Calcula(C) - this->Oper2->Calcula(C);
			break;
		case Multiplicacao: 
			res = this->Oper1->Calcula(C) * this->Oper2->Calcula(C);
			break;
		case Divisao: 
			res = this->Oper1->Calcula(C) / this->Oper2->Calcula(C);
			break;
		default:
			res = 0.0;
	}

	return res;
}

/* ========================================================================== */

} /* namespace tiny */


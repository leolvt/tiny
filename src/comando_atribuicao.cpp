#include "comando_atribuicao.h"

namespace tiny {

/* ========================================================================== */

ComandoAtribuicao::ComandoAtribuicao(char Var, Expressao * E)
{
	this->nomeVar = Var;
	this->exp = E;
}

/* ========================================================================== */

ComandoAtribuicao::~ComandoAtribuicao()
{
	if (this->exp) delete this->exp;
}

/* ========================================================================== */

void ComandoAtribuicao::Interpreta(Contexto& C)
{
	double res_exp = this->exp->Calcula(C);
	C.defineVariavel(this->nomeVar, res_exp);
}

/* ========================================================================== */

} /* namespace tiny */

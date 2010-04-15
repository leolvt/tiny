#include "exp_relacional.h"
#include "expressao.h"

namespace tiny{

/* ========================================================================== */

ExpressaoRelacional::ExpressaoRelacionalExpressao *Oper1, Expressao *Oper2, 
				TipoOperRel tipoOp){
	this->Oper1 = Oper1;
	this->Oper2 = Oper2;
	this->tipoOp = tipoOp;
}

/* ========================================================================== */

ExpressaoRelacional::~ExpressaoRelacional(){
	if (this->Oper1) delete this->Oper1;
	if (this->Oper2) delete this->Oper2;
}

/* ========================================================================== */

bool ExpressaoRelacional::Relaciona(Contexto& C){
	bool res;
	
	switch (this->tipoOp){
		case op_>:
			res = ( this->Oper1->Calcula(C) > this->Oper2->Calcula(C) );
			break;
		case op_>=:
			res = ( this->Oper1->Calcula(C) >= this->Oper2->Calcula(C) );
			break;
		case op_<:
			res = ( this->Oper1->Calcula(C) < this->Oper2->Calcula(C) );
			break;
		case op_<=:
			res = ( this->Oper1->Calcula(C) <= this->Oper2->Calcula(C) );
			break;
		case op_=:
			res = ( this->Oper1->Calcula(C) == this->Oper2->Calcula(C) );
			break;
		default:
			res = false;
			break;
	}
	
	return res;
}

} /* namespace tiny */

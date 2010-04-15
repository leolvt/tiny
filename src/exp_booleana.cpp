#include "exp_booleana.h"

namespace tiny{

/* ========================================================================== */

ExpressaoBooleana::ExpressaoBooleana(ExpressaoBool *Oper1, ExpressaoBool *Oper2, 
				TipoOper tipoOp){
	this->Oper1 = Oper1;
	this->Oper2 = Oper2;
	this->tipoOp = tipoOp;
}

/* ========================================================================== */

ExpressaoBooleana::~ExpressaoBooleana(){
	if (this->Oper1) delete this->Oper1;
	if (this->Oper2) delete this->Oper2;
}

/* ========================================================================== */

bool ExpressaoBooleana::Avalia(){
	bool res;
	
	switch(this->tipoOp){
		case op_or:
			res = this->Oper1->Avalia() || this->Oper2->Avalia();
			break;
		case op_and:
			res = this->Oper1->Avalia() && this->Oper2->Avalia();
			break;
		case op_not:
			res = ! (this->Oper1->Avalia());
			break;
		default:
			res = false;
			break
	}
	
	return res;
}

/* ========================================================================== */

} /* namespace tiny */

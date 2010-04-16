#include "boolean.h"

namespace tiny{

Boolean::Boolean(TipoBoolean tipoBoolean, bool valor, ExpressaoBool * Expb){
	this->tipoBoolean = tipoBoolean;
	this->valor = valor;
	this->Expb = Expb;
}

/* ========================================================================== */

Boolean::~Boolean()
{
	if (this->Expb) delete Expb;
}

/* ========================================================================== */

bool Boolean::Avalia(Contexto& C){
	bool res;
	
	switch (this->tipoBoolean){
		case Valor:
			res = this->valor;
			break;
		case Parenteses:
			res = this->Expb->Avalia(C);
			break;
		default:
			res = false;
			break;
	}
	
	return res;
}

/* ========================================================================== */

} /* namespace tiny */

#include "boolean.h"

namespace tiny{

Boolean::Boolean(TipoFator tipo, bool valor, ExpressaoBool * Expb){
	this->tipo = tipo;
	this->valor = valor;
	this->Expb = Expb;
}

/* ========================================================================== */

Boolean::~Boolean()
{
	if (this->Expb) delete Expb;
}

/* ========================================================================== */

bool Avalia(){
	bool res;
	
	switch (this->tipoBoolean){
		case Valor:
			res = this->valor;
			break;
		case Parenteses:
			res = this->Expb->Avalia();
			break;
		default:
			res = false;
			break;
	}
	
	return res;
}

/* ========================================================================== */

} /* namespace tiny */

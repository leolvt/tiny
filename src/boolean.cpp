#include "boolean.h"

namespace tiny{

Boolean::Boolean(bool valor){
	this->valor = valor;
}

/* ========================================================================== */

Boolean::~Boolean()
{
}

/* ========================================================================== */

bool Boolean::Avalia(Contexto& C){
	bool res;
	
	res = this->valor;
			
	return res;
}

/* ========================================================================== */

} /* namespace tiny */

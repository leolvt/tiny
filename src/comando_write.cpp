#include <string>
#include <iostream>
#include "comando_write.h"

namespace tiny {

/* ========================================================================== */

ComandoWrite::ComandoWrite( TipoWrite t, std::string * s, char nomevar)
{
	this->tipo = t;
	this->str = s;
	this->var = nomevar;
}

/* ========================================================================== */

ComandoWrite::~ComandoWrite()
{
	if (this->str) delete this->str;
}

/* ========================================================================== */

void ComandoWrite::Interpreta(Contexto& C)
{
	switch (this->tipo)
	{
		case writeStr:
			std::cout << *(this->str);
			break;
		case writeVar:
			std::cout << C.obtemVariavel(this->var);
			break;
		case writeln:
			std::cout << std::endl;
			break;
	}
}

/* ========================================================================== */

}	/* namespace tiny */

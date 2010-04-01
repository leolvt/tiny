#ifndef		TINY_EXPRESSAO_H
#define		TINY_EXPRESSAO_H

#include "contexto.h"

namespace tiny {

class Expressao
{
	public: 
		virtual ~Expressao() {};
		virtual double Calcula(Contexto& C) = 0;
};

} /* namespace tiny */

#endif		/* TINY_EXPRESSAO_H */

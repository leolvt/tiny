#ifndef		TINY_COMANDO_H
#define		TINY_COMANDO_H

#include "contexto.h"

namespace tiny {

class Comando
{
	public:
		virtual ~Comando() {};
		virtual void Interpreta( Contexto& C ) = 0;
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_H */

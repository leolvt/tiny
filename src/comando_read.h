#ifndef		TINY_COMANDO_READ_H
#define		TINY_COMANDO_READ_H

#include "contexto.h"
#include "comando.h"

namespace tiny {

class ComandoRead : public Comando
{
	char nomeVar;
	public:
		ComandoRead(char nomeVar);
		~ComandoRead();

		void Interpreta(Contexto& C);
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_READ_H */

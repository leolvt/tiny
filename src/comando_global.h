#ifndef		TINY_COMANDO_GLOBAL_H
#define		TINY_COMANDO_GLOBAL_H

#include "comando.h"
#include "contexto.h"
#include "lista_variaveis.h"

namespace tiny {

class ComandoGlobal: public Comando
{
	private:
		ListaVariaveis * lista;

	public:
		ComandoGlobal();
		ComandoGlobal(ListaVariaveis * l);
		~ComandoGlobal();

		void Interpreta( Contexto& C );
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_GLOBAL_H */

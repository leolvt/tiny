#ifndef 	TINY_COMANDO_LOCAL_H
#define		TINY_COMANDO_LOCAL_H

#include "comando.h"
#include "contexto.h"
#include "lista_variaveis.h"

namespace tiny {

class ComandoLocal: public Comando {

	private:
		ListaVariaveis * lista;
	
	public:
		ComandoLocal();
		ComandoLocal(ListaVariaveis * l);
		~ComandoLocal();

		void Interpreta( Contexto& C );

}

} /* namespace tiny */

#endif		/* TINY_COMANDO_LOCAL_H */

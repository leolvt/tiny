#ifndef		TINY_COMANDO_CALL_H
#define		TINY_COMANDO_CALL_H

#include <string>
#include "comando.h"
#include "contexto.h"
#include "lista_expressoes.h"

namespace tiny {

class ComandoCall : public Comando
{
	private:
		std::string * identificador;
		ListaExpressoes * param_reais;
	public:
		ComandoCall(std::string * id, ListaExpressoes * le);
		~ComandoCall();
		void Interpreta( Contexto& C );
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_CALL_H */

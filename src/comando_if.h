#ifndef TINY_COMANDO_IF_H
#define TINY_COMANDO_IF_H

#include "lista_comandos.h"
#include "expressaoBool.h"

namespace tiny{

class ComandoIf : public Comando {
	private:
		ExpressaoBool *teste;
		ListaComandos *listaComThen;
		ListaComandos *listaComElse;
	public:
		ComandoIf(ExpressaoBool *teste, ListaComandos *listaComThen, 
				ListaComandos *listaComElse = NULL);
		~ComandoIf();
		void Interpreta(Contexto& C);
};

} /* namespace tiny */

#endif /* TINY_COMANDO_IF_H */

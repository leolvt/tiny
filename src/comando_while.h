#ifndef COMANDO_WHILE_H
#define COMANDO_WHILE_H

#include "expressaoBool.h"
#include "lista_comandos.h"

namespace tiny{

class ComandoWhile : public comando {
	private:
		ExpressaoBool *teste;
		ListaComandos *lista_cmds;
	public:
		ComandoWhile(ExpressaoBool *teste, ListaComandos *lista_cmds);
		~ComandoWhile();
		void Interpreta(Contexto& C);
};

} /* namespace tiny */

#endif /* COMANDO_WHILE_H */

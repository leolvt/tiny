#ifndef		TINY_LISTA_COMANDOS_H
#define		TINY_LISTA_COMANDOS_H

#include <vector>
#include "contexto.h"
#include "comando.h"

namespace tiny {

class ListaComandos
{
	private:
		std::vector<Comando *> lista_de_comandos;

	public:
		ListaComandos(Comando * C);
		~ListaComandos();
		void AdicionaComando(Comando * C);
		void Interpreta(Contexto& C);

};

} /* namespace tiny */

#endif		/* TINY_LISTA_COMANDOS_H */

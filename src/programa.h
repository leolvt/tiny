#ifndef		TINY_PROGRAMA_H
#define		TINY_PROGRAMA_H

#include "contexto.h"
#include "comando_global.h"
#include "lista_procedimentos.h"

namespace tiny {

class Programa {
	
	private:
		Comando * cmd_global;
		ListaProcedimentos * procedimentos;

	public:
		Programa(Comando * g, ListaProcedimentos * p);
		~Programa();

		void Executa(Contexto& C);
};

} /* namespace tiny */

#endif		/* TINY_PROGRAMA_H */

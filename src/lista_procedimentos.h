#ifndef TINY_LISTA_PROCEDIMENTOS
#define TINY_LISTA_PROCEDIMENTOS

#include <vector>
#include "contexto.h"
#include "procedimento.h"
#include "comando_global.h"

namespace tiny {


class ListaProcedimentos {
	
	private:
		ComandoGlobal * global;
		Procedimentos * procedimentos_do_prog;
	
	public:
		ListaProcedimentos(ComandoGlobal * global, Procedimento * P);
		~ListaProcedimentos();
		void AdicionaProcedimento(Procedimento * P);
		void Interpreta(Contexto& C);
		
};

} /* namespace tiny */

#endif	/* TINY_LISTA_PROCEDIMENTOS */

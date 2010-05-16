#ifndef TINY_LISTA_PROCEDIMENTOS
#define TINY_LISTA_PROCEDIMENTOS

#include "defs.h"
#include "procedimento.h"

namespace tiny {

class ListaProcedimentos {
	
	private:
		Procedimentos * procedimentos_do_prog;
	
	public:
		ListaProcedimentos(Procedimento * P);
		~ListaProcedimentos();
		void AdicionaProcedimento(Procedimento * P);
		Procedimentos * obtemProcedimentos();
		
};

} /* namespace tiny */

#endif	/* TINY_LISTA_PROCEDIMENTOS */

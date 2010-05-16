#ifndef TINY_LISTA_PROCEDIMENTOS
#define TINY_LISTA_PROCEDIMENTOS

#include <vector>
#include "contexto.h"
#include "Procedimento.h"

namespace tiny {

typedef std::map<std::string, Procedimento *> Procedimentos;

class ListaProcedimentos {
	
	private:
		Procedimentos procedimentos_do_prog;
	
	public:
		ListaProcedimentos(Procedimento * P);
		~ListaProcedimentos();
		void AdicionaProcedimento(Procedimento * P);
		void obtemProcedimento(std::string nome_procedimento);
		
};

} /* namespace tiny */

#endif	/* TINY_LISTA_PROCEDIMENTOS */

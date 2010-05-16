#ifndef TINY_LISTA_PROCEDIMENTOS
#define TINY_LISTA_PROCEDIMENTOS

#include <vector>
#include "contexto.h"
#include "procedimento.h"
#include "comando_global.h"

namespace tiny {

typedef std::map<std::string, Procedimento *> Procedimentos;

class ListaProcedimentos {
	
	private:
		ComandoGlobal * global;
		Procedimentos * procedimentos_do_prog;
	
	public:
		ListaProcedimentos(ComandoGlobal * global, Procedimento * P);
		~ListaProcedimentos();
		void AdicionaProcedimento(Procedimento * P);
		Procedimento * obtemProcedimento(std::string nome_procedimento);
		void Interpreta(Contexto& C);
		
};

} /* namespace tiny */

#endif	/* TINY_LISTA_PROCEDIMENTOS */

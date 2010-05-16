#include "lista_procedimentos.h"

namespace tiny {

/* ========================================================================== */

ListaProcedimentos::ListaProcedimentos(Procedimento * P) {
	
	this->procedimentos_do_prog = new Procedimentos;	
	std::pair<std::string, Procedimento *> new_proc(P->obtemNome(), P);
	this->procedimentos_do_prog->insert(new_proc);
}

/* ========================================================================== */

ListaProcedimentos::~ListaProcedimentos() {

	if (this->procedimentos_do_prog) 
	{
		procedimentos_do_prog->clear();
		delete this->procedimentos_do_prog;
	}
	
}

/* ========================================================================== */

void ListaProcedimentos::AdicionaProcedimento(Procedimento * P) {
	

	std::pair<std::string, Procedimento *> new_proc(P->obtemNome(), P);
	bool OK = false;
	
	OK = this->procedimentos_do_prog->insert(new_proc).second;
	if (OK) return;
	else throw Erro("\nProcedimento declarado duas vezes"+P->obtemNome());
		
}

/* ========================================================================== */

Procedimentos * ListaProcedimentos::obtemProcedimentos()
{
	return this->procedimentos_do_prog;
}

/* ========================================================================== */

} /* namespace tiny */

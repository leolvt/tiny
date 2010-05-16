#include "lista_procedimentos.h"

namespace tiny {

/* ========================================================================== */

ListaProcedimentos::ListaProcedimentos(ComandoGlobal * global, Procedimento * P) {
	this->global = global;
	this->procedimentos = P;
}

/* ========================================================================== */

ListaProcedimentos::~ListaProcedimentos() {

	procedimentos_do_prog->clear();
	
}

/* ========================================================================== */

void ListaProcedimentos::AdicionaProcedimento(Procedimento * P) {
	

	std::pair<std::string, Procedimento *> new_proc(P.obtemNome(), P);
	bool OK = false;
	
	OK = this->procedimentos_do_prog->insert(new_proc).second;
	if (OK) return;
	else throw Erro("\nProcedimento declarado duas vezes"+P.obtemNome());
		
}

/* ========================================================================== */

void ListaProcedimentos::Interpreta(Contexto& C) {
	C.defineProcedimentos(this->procedimentos_do_prog);	//informa ao Contexto quais são os procedimentos
	
	this->global->Interpreta(C);
	
	Procedimento * main = C.obtemProcedimento("main");
	
	main->Interpreta(C);
}

/* ========================================================================== */

} /* namespace tiny */

#include "lista_procedimentos.h"

namespace tiny {

/* ========================================================================== */

ListaProcedimentos::ListaProcedimentos(Procedimento * P) {	
}

/* ========================================================================== */

ListaProcedimentos::~ListaProcedimentos() {

	procedimentos_do_prog.clear();
	
}

/* ========================================================================== */

ListaProcedimentos::AdicionaProcedimento(Procedimento * P) {
	

	std::pair<std::string, Procedimento *> new_proc(P.obtemNome(), P);
	bool OK = false;
	
	OK = this->procedimentos_do_prog.insert(new_proc).second;
	if (OK) return;
	else throw Erro("\nProcedimento declarado duas vezes"+P.obtemNome());
		
}

/* ========================================================================== */

ListaProcedimentos::obtemProcedimento(std::string nome_procedimento) {
	
	std::map<std::string, Procedimento *>::iterator it;

	it = this->procedimentos_do_prog.find(nome_procedimento);
	if (it != this->procedimentos_do_prog.end()) 
		return it->second;
	else
		throw Erro("\nNão foi possível encontrar procedimento"+nome_procedimento);
	
}

/* ========================================================================== */

} /* namespace tiny */

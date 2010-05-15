#include "procedimento.h"

namespace tiny {

/* ========================================================================== */

Procedimento::Procedimento(	std::string nome_processo, 
				ListaVariaveis * parametros, 
				ComandoLocal * cmd_local, 
				ListaComandos * lista_cmds){
	
	this->nome_processo = nome_processo;
	this->parametros = parametros;
	this->cmd_local = cmd_local;
	this->lista_cmds = lista_cmds;
	
}
	
/* ========================================================================== */

Procedimento::~Procedimento() {
	
	if (this->nome_processo) delete this->nome_processo;
	if (this->parametros) delete this->parametros;
	if (this->cmd_local) delete this->cmd_local;
	if (this->lista_cmds) delete this->lista_cmds;
	
}

/* ========================================================================== */

std::string obtemNome() {
	return this->nome;
}

/* ========================================================================== */

ListaVariaveis * obtemParametros() {
	return this->parametros;
}

/* ========================================================================== */

ComandoLocal * obtemLocal() {
	return this->cmd_local;
}

/* ========================================================================== */

ListaComandos * obtemComandos() {
	return this->lista_cmds;
}

/* ========================================================================== */

} /* namespace tiny */

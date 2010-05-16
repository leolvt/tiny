#include "programa.h"
#include "comando_call.h"

namespace tiny {

/* ========================================================================== */

Programa::Programa(Comando * g, ListaProcedimentos * p)
{
	this->cmd_global = g;
	this->procedimentos = p;
}

/* ========================================================================== */

Programa::~Programa()
{
	if (this->cmd_global) delete this->cmd_global;
	if (this->procedimentos) delete this->procedimentos;
}

/* ========================================================================== */

void Programa::Executa(Contexto& C)
{
	//informa ao Contexto quais são os procedimentos
	C.defineProcedimentos(this->procedimentos->obtemProcedimentos());	
	
	// Interpreta as variáveis globais
	this->cmd_global->Interpreta(C);
	
	// Cria chamada de procedimento
	std::string * id = new std::string("main");
	ListaExpressoes * exp = new ListaExpressoes();
	ComandoCall cmd_call = ComandoCall(id,exp);
	cmd_call.Interpreta(C);
	
}

/* ========================================================================== */

}; /* namespace tiny */

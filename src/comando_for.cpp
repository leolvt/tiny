#include "comando_for.h"

namespace tiny {

/* ========================================================================== */

ComandoFor::ComandoFor(char vn, Expressao * min, Expressao * max, 
		ListaComandos * lista)
{
	this->nome_var = vn;
	this->exp_min = min;
	this->exp_max = max;
	this->lista_cmds = lista;
}

/* ========================================================================== */

ComandoFor::~ComandoFor()
{
	if (this->exp_min) delete this->exp_min;
	if (this->exp_max) delete this->exp_max;
	if (this->lista_cmds) delete this->lista_cmds;
}

/* ========================================================================== */

void ComandoFor::Interpreta( Contexto& C )
{
	// Define valor inicial
	C.defineVariavel( this->nome_var , this->exp_min->Calcula(C) );

	// Enquanto Variavel for menor ou igual a valor maximo
	while ( C.obtemVariavel(this->nome_var) <= this->exp_max->Calcula(C) )
	{
		// Executa comandos
		this->lista_cmds->Interpreta(C);
		// Incrementa Variavel
		C.defineVariavel( nome_var , C.obtemVariavel(nome_var)+1.0 );
	}
}

/* ========================================================================== */

} /* namespace tiny */

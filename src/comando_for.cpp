#include "comando_for.h"

namespace tiny {

/* ========================================================================== */

ComandoFor::ComandoFor(TipoFor tipo, char vn, Expressao * min, Expressao * max, 
		ListaComandos * lista)
{
	this->tipo = tipo;
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
	C.defineVariavel( nome_var , exp_min->Calcula(C) );
	double i = exp_min->Calcula(C);

	// Loop For crescente
	if (tipo == up)
	{
		for ( ; i >= exp_max->Calcula(C) ; i = C.obtemVariavel(nome_var) )
		{
			lista_cmds->Interpreta(C);
			C.defineVariavel( nome_var, i-1.0 );
		}
	} 
	// Loop for decrescente
	else 
	{
		for ( ; i <= exp_max->Calcula(C) ; i = C.obtemVariavel(nome_var) )
		{
			lista_cmds->Interpreta(C);
			C.defineVariavel( nome_var, i+1.0 );
		}
	}

}

/* ========================================================================== */

} /* namespace tiny */

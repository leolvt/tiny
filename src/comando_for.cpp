#include "comando_for.h"

namespace tiny {

/* ========================================================================== */

ComandoFor::ComandoFor(TipoFor tipo, char vn, Expressao * val_inicial, 
		Expressao * val_final, ListaComandos * lista)
{
	this->tipo = tipo;
	this->nome_var = vn;
	this->exp_val_inicial = val_inicial;
	this->exp_val_final = val_final;
	this->lista_cmds = lista;
}

/* ========================================================================== */

ComandoFor::~ComandoFor()
{
	if (this->exp_val_inicial) delete this->exp_val_inicial;
	if (this->exp_val_final) delete this->exp_val_final;
	if (this->lista_cmds) delete this->lista_cmds;
}

/* ========================================================================== */

void ComandoFor::Interpreta( Contexto& C )
{

	// Define valor inicial
	C.defineVariavel( nome_var , exp_val_inicial->Calcula(C) );
	double i = exp_val_inicial->Calcula(C);

	// Loop For crescente
	if (tipo == up)
	{
		while ( C.obtemVariavel(nome_var) <= exp_val_final->Calcula(C) )
		{
			lista_cmds->Interpreta(C);
			C.defineVariavel( nome_var, i+1.0 );
			i+=1.0;
		}
	} 
	// Loop for decrescente
	else 
	{
		while ( C.obtemVariavel(nome_var) >= exp_val_final->Calcula(C) )
		{
			lista_cmds->Interpreta(C);
			C.defineVariavel( nome_var, i-1.0 );
			i-=1.0;
		}
	}

}

/* ========================================================================== */

} /* namespace tiny */

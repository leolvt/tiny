#include "comando_call.h"
#include "procedimento.h"

namespace tiny {

/* ========================================================================== */

ComandoCall::ComandoCall(std::string * id, ListaExpressoes * le)
{
	this->identificador = id;
	this->param_reais = le;
}

/* ========================================================================== */

ComandoCall::~ComandoCall()
{
	if (!this->identificador) delete this->identificador;
	if (!this->param_reais) delete this->param_reais;
}

/* ========================================================================== */

void ComandoCall::Interpreta( Contexto& C )
{
	if ( (!identificador) || (!param_reais) )
		throw Erro("\nUnexpected NULL pointer.");

	/* Obtém Procedimento */
	Procedimento * P = C.obtemProcedimento(*identificador);
	
	/* Checa número de Parâmetros */
	ListaVariaveis * params = P->obtemParametros();
	if ( params->tamanho() != param_reais->tamanho() )
		throw Erro("\nProcedimento inválido: número de parâmetros errado");
	
	/* Atribui parâmetros e adiciona as variáveis no RA */
	int i;
	std::vector<double> p_reais = param_reais->Avalia(C);
	
	/* Adiciona novo Registro de Ativação */
	C.adicionaRA();
	for (i = 0; i < params->tamanho() ; i++)
	{
		C.adicionaVariavel((*params)[i], p_reais[i]);
	}

	/* Executa Procedimento */
	Comando * comandoLocal = P->obtemLocal();
	comandoLocal->Interpreta(C);
	ListaComandos * cmds = P->obtemComandos();
	cmds->Interpreta(C);

	/* Remove Registro de Ativação */
	C.removeRA();
}

/* ========================================================================== */

} /* namespace tiny */

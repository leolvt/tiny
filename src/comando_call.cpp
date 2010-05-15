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
	Procedimento P = C.obtemProcedimento(*identificador);
	
	/* Checa número de Parâmetros */
	ListaVariaveis params = P.obtemParametros();
	std::vector<double> params_reais = param_reais->Avalia(C);
	if ( params.tamanho() != param_reais.tamanho() )
		throw Erro("\nProcedimento inválido: número de parâmetros errado");
	
	/* Adiciona novo Registro de Ativação */
	C.adicionaRA();
	
	/* Atribui parâmetros e adiciona as variáveis no RA */
	int i;
	for (i = 0; i < params.tamanho() ; i++)
		C.adicionaVariavel(params[i], params_reais[i]);

	/* Executa Procedimento */
	ComandoLocal * comandoLocal = P.obtemLocal();
	comandoLocal->Interpreta(C);
	ListaComandos cmds = P.obtemComandos();
	cmds->Interpreta(C);

	/* Remove Registro de Ativação */
	C.removeRA();
}

/* ========================================================================== */

} /* namespace tiny */

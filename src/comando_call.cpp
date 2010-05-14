#include "comando_call.h"

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
		throw std::string("Erro!");

	/* Obtém Procedimento */
//	Procedimento P = C.obtemProcedimento(*identificador);
	
	/* Checa número de Parâmetros */
//	ListaVariaveis params = P.obtemParametros();
//	std::vector<double> params_reais = param_reais->Avalia(C);
//	if ( params.tamanho() != param_reais.tamanho() )
//		throw std::string("Erro!");
//	
//	/* Atribui parâmetros */
//	map<char,double> vars;
//	int i;
//	for (i = 0; i < params.tamanho() ; i++)
//		vars.insert( std::pair<char,double>(params[i],params_reais[i]) );
//	
//	/* Adiciona Variáveis na Pilha de Ativação */
//	C.adicionaRA(vars);
//
//	/* Executa Procedimento */
//	ListaComandos cmds = P.obtemComandos();
//	cmds->Interpreta();
//
//	/* Remove Registro de Ativação */
//	C.removeRA();
}

/* ========================================================================== */

} /* namespace tiny */

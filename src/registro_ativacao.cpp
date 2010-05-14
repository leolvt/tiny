#include "registro_ativacao.h"

namespace tiny {

/* ========================================================================== */

RegistroAtivacao::RegistroAtivacao(ListaVariaveis l)
{
	int i;
	for (i = 0 ; i < l.tamanho() ; i++)
		variaveis[ l[i] ] = 0.0;
}

/* ========================================================================== */

RegistroAtivacao::~RegistroAtivacao()
{
	variaveis.clear();
}

/* ========================================================================== */

std::map<char,double>& RegistroAtivacao::obtemVars()
{
	return variaveis;
}

/* ========================================================================== */

} /* namespace tiny */

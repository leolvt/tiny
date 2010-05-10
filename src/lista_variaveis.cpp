#include "lista_variaveis.h"

namespace tiny {

/* ========================================================================== */

void ListaVariaveis::adicionaVar(char var_name)
{
	this->lista_de_vars.push_back(var_name);
}

/* ========================================================================== */

char ListaVariaveis::operator[] ( unsigned int n )
{
	return lista_de_vars[n];
}

/* ========================================================================== */

} /* namespace tiny */

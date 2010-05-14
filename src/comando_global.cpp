#include "comando_global.h"

namespace tiny {

/* ========================================================================== */

ComandoGlobal::ComandoGlobal()
{
	lista = NULL;
}

/* ========================================================================== */

ComandoGlobal::ComandoGlobal(ListaVariaveis * l)
{
	lista = l;
}

/* ========================================================================== */

ComandoGlobal::~ComandoGlobal()
{
	if (lista != NULL) delete lista;
}

/* ========================================================================== */

void ComandoGlobal::Interpreta( Contexto& C )
{
	if (lista == NULL) return;

	int i;
	for ( i = 0 ; i < lista->tamanho() ; i++ )
		C.adicionaVariavel( (*lista)[i] , 0.0);
}

/* ========================================================================== */

} /* namespace tiny */

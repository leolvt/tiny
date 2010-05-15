#include "comando_local.h"

namespace tiny {

/* ========================================================================== */

ComandoLocal::ComandoLocal() {
	lista = NULL;
}

/* ========================================================================== */

ComandoLocal::ComandoLocal(ListaVariaveis * l) {
	lista = l;
}

/* ========================================================================== */

ComandoLocal::~ComandoLocal(){
	if (lista != NULL) delete lista;
}

/* ========================================================================== */

ComandoLocal::Interpreta(Contexto& C) {
	int i;
	for ( i = 0 ; i < lista->tamanho() ; i++ )
		C.adicionaVariavel( (*lista)[i] , 0.0);
}

/* ========================================================================== */

}

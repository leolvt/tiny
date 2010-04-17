#include "comando_while.h"

namespace tiny{

/* ========================================================================== */

ComandoWhile::ComandoWhile(ExpressaoBool *teste, ListaComandos *lista_cmds){
	this->teste=teste;
	this->lista_cmds=lista_cmds;
}

/* ========================================================================== */

ComandoWhile::~ComandoWhile(){
	if (this->teste) delete this->teste;
	if (this->lista_cmds) delete this->lista_cmds;
}

/* ========================================================================== */

void ComandoWhile::Interpreta(Contexto& C){

	while( teste->Avalia(C) ){
	
		lista_cmds->Interpreta(C);
	
	}

}

} /* namespace tiny */

#include "comando_if.h"

namespace tiny{

/* ========================================================================== */

ComandoIf::ComandoIf(ExpressaoBool *teste, ListaComandos *listaComThen, 
				ListaComandos *listaComElse){
	this->teste = teste;
	this->listaComThen = listaComThen;
	this->listaComElse = listaComElse;
}

/* ========================================================================== */

ComandoIf::~ComandoIf(){
	if (this->teste) delete this->teste;
	if (this->listaComThen) delete this->listaComThen;
	if (this->listaComElse) delete this->listaComElse;
}

/* ========================================================================== */

void ComandoIf::Interpreta(Contexto& C){
	
	if( teste->Avalia(C) )

		listaComThen->Interpreta(C);
		
	else{
	
		//Verifica por uma expressão if-then-else, pois se if-then, 
		//então listaComElse == NULL
		if( this->listaComElse ) listaComElse->Interpreta(C);
	
	}
	
}

/* ========================================================================== */

} /* namespace tiny */

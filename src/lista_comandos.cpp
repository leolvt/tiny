#include "lista_comandos.h"

namespace tiny {

/* ========================================================================== */

ListaComandos::ListaComandos(Comando * C)
{
	if (C != NULL)
		this->lista_de_comandos.push_back(C);
}

/* ========================================================================== */

ListaComandos::~ListaComandos()
{
	unsigned int i;
    for( i = 0 ; i < lista_de_comandos.size() ; i++)
        delete lista_de_comandos[i];
    lista_de_comandos.clear();
}

/* ========================================================================== */

void ListaComandos::AdicionaComando(Comando * C)
{
	this->lista_de_comandos.push_back( C );
}

/* ========================================================================== */

void ListaComandos::Interpreta(Contexto& C)
{
	unsigned int i;
	for (i = 0 ; i < lista_de_comandos.size() ; i++ )
		lista_de_comandos[i]->Interpreta(C);

}

/* ========================================================================== */

} /* namespace tiny */


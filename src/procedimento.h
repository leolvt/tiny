#ifndef		TINY_PROCEDIMENTO_H
#define		TINY_PROCEDIMENTO_H

#include <string>
#include "lista_variaveis.h"
#include "comando_local.h"
#include "lista_comandos.h"

namespace tiny {

class Procedimento {
	private:
		std::string nome_processo;
		ListaVariaveis * parametros;
		ComandoLocal * cmd_local;
		ListaComandos * lista_cmds;
	
	public:
		Procedimento(	std::string nome_processo, 
				ListaVariaveis * parametros, 
				ComandoLocal * cmd_local, 
				ListaComandos * lista_cmds);
		~Procedimento();
		std::string obtemNome();
		ListaVariaveis * obtemParametros();
		ComandoLocal * obtemLocal();
		ListaComandos * obtemComandos();
};

} /* namespace tiny */

#endif		/* TINY_PROCEDIMENTO_H */

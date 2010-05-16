#ifndef		TINY_PROCEDIMENTO_H
#define		TINY_PROCEDIMENTO_H

#include <string>
#include "lista_variaveis.h"
#include "lista_comandos.h"
#include "comando.h"

namespace tiny {

class Procedimento {
	private:
		std::string * nome_processo;
		ListaVariaveis * parametros;
		Comando * cmd_local;
		ListaComandos * lista_cmds;
	
	public:
		Procedimento(	std::string * nome_processo, 
				ListaVariaveis * parametros, 
				Comando * cmd_local, 
				ListaComandos * lista_cmds);
		~Procedimento();
		std::string obtemNome();
		ListaVariaveis * obtemParametros();
		Comando * obtemLocal();
		ListaComandos * obtemComandos();
};

} /* namespace tiny */

#endif		/* TINY_PROCEDIMENTO_H */

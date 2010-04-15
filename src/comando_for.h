#ifndef		TINY_COMANDO_FOR_H
#define		TINY_COMANDO_FOR_H

#include "comando.h"
#include "contexto.h"
#include "lista_comandos.h"
#include "expressao.h"

namespace tiny {

class ComandoFor : public Comando
{
	private:
		char nome_var;
		Expressao * exp_min;
		Expressao * exp_max;
		ListaComandos * lista_cmds;
	public:
		ComandoFor(char vn, Expressao * min, Expressao * max, 
				ListaComandos * lista);
		~ComandoFor();
		void Interpreta( Contexto& C );
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_FOR_H */

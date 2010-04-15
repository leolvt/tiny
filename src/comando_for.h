#ifndef		TINY_COMANDO_FOR_H
#define		TINY_COMANDO_FOR_H

#include "comando.h"
#include "contexto.h"
#include "lista_comandos.h"
#include "expressao.h"

namespace tiny {

typedef enum { up, down } TipoFor;

class ComandoFor : public Comando
{
	private:
		TipoFor tipo;
		char nome_var;
		Expressao * exp_min;
		Expressao * exp_max;
		ListaComandos * lista_cmds;
	public:
		ComandoFor(TipoFor tipo, char vn, Expressao * min, Expressao * max, 
				ListaComandos * lista);
		~ComandoFor();
		void Interpreta( Contexto& C );
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_FOR_H */

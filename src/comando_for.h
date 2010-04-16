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
		Expressao * exp_val_inicial;
		Expressao * exp_val_final;
		ListaComandos * lista_cmds;
	public:
		ComandoFor(TipoFor tipo, char vn, Expressao * val_inicial, 
				Expressao * val_final, ListaComandos * lista);
		~ComandoFor();
		void Interpreta( Contexto& C );
};

} /* namespace tiny */

#endif		/* TINY_COMANDO_FOR_H */

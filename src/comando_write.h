#ifndef		TINY_COMANDO_WRITE_H
#define		TINY_COMANDO_WRITE_H

#include <string>
#include "comando.h"
#include "contexto.h"

namespace tiny {

typedef enum {
	writeStr,
	writeVar,
	writeln
} TipoWrite;

class ComandoWrite: public Comando
{
	private:
		TipoWrite tipo;
		std::string	* str;
		char var;
	public:
		ComandoWrite( TipoWrite t, std::string * s = NULL, char nomevar = '0' );
		~ComandoWrite();
		void Interpreta(Contexto& C);
};

}	/* namespace tiny */

#endif		/* TINY_COMANDO_WRITE_H */

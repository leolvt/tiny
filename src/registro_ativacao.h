#ifndef		TINY_REGISTRO_ATIVACAO_H
#define		TINY_REGISTRO_ATIVACAO_H

#include <map>
#include "lista_variaveis.h"

namespace tiny {

class RegistroAtivacao 
{
	private:
		std::map<char,double> variaveis;

	public:
		RegistroAtivacao(ListaVariaveis l);
		~RegistroAtivacao();

		std::map<char,double>& obtemVars();
};

} /* namespace tiny */

#endif		/* TINY_REGISTRO_ATIVACAO_H */

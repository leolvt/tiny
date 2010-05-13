#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <map>

namespace tiny {

class Contexto 
{
	private:
		std::map<char,double> variaveis_globais;

	public:
		Contexto();
		~Contexto();
		
		double	obtemVariavel(char nomeVar);
		void	defineVariavel(char nomeVar, double valor);
		void	adicionaVariavel(char nomeVar, double valor);
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

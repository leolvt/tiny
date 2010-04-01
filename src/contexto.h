#ifndef		TINY_CONTEXTO_H
#define		TINY_CONTEXTO_H

#include <vector>

namespace tiny {

class Contexto 
{
	private:
		std::vector<double> variaveis;

	public:
		Contexto();
		~Contexto();
		
		double	obtemVariavel(char nomeVar);
		void	defineVariavel(char nomeVar, double valor);
};

} /* namespace tiny */

#endif		/* TINY_CONTEXTO_H */

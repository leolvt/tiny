#ifndef		TINY_FATOR_H
#define		TINY_FATOR_H

#include "expressao.h"
#include "contexto.h"

namespace tiny {

typedef enum
{
	RaizQuadrada,
	Variavel,
	Numero,
	Parentesis
} TipoFator;

class Fator : public Expressao
{
	private:
		char nomeVar;
		Expressao * Exp;
		double numero;
		TipoFator tipoFator;
	public: 
		Fator(TipoFator tipo, double numero = 0.0, Expressao * Exp = NULL, 
				char nomeVar = '0' );
		virtual ~Fator();
		virtual double Calcula(Contexto& C);
};

} /* namespace tiny */

#endif		/* TINY_EXPRESSAO_H */

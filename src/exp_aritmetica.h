#ifndef		TINY_EXP_ARITMETICA_H
#define		TINY_EXP_ARITMETICA_H

#include "contexto.h"
#include "expressao.h"

namespace tiny {

typedef enum {
	Adicao,
	Subtracao,
	Multiplicacao,
	Divisao
} TipoOper;

class ExpressaoAritmetica : public Expressao
{
	private:
		Expressao * Oper1;	
		Expressao * Oper2;	
		TipoOper Op;

	public:
		ExpressaoAritmetica( Expressao * Op1, Expressao * Op2, 
				TipoOper O );
		virtual ~ExpressaoAritmetica();
		virtual double Calcula(Contexto& C);

};

} /* namespace tiny */

#endif		/* TINY_EXP_ARITMETICA_H */

#ifndef TINY_EXP_RELACIONAL_H
#define TINY_EXP_RELACIONAL_H

#include "expressaoRel.h"

namespace tiny{

typedef enum{
	op_GT,
	op_GTE,
	op_LT,
	op_LTE,
	op_EQ,
	op_DIF
} TipoOperRel;

class ExpressaoRelacional : public ExpressaoRel {
	private:
		Expressao *Oper1;
		Expressao *Oper2;
		TipoOperRel tipoOp;
	public:
		ExpressaoRelacional(Expressao *Oper1, Expressao *Oper2, 
				TipoOperRel tipoOp);
		virtual ~ExpressaoRelacional();
		virtual bool Relaciona(Contexto& C);
};

} /* namespace tiny */

#endif

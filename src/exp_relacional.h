#ifndef TINY_EXP_RELACIONAL_H
#define TINY_EXP_RELACIONAL_H

#include "expressaoBool.h"
#include "expressao.h"

namespace tiny{

typedef enum{
	op_GT,
	op_GTE,
	op_LT,
	op_LTE,
	op_EQ,
	op_DIF
} TipoOperRel;

class ExpressaoRelacional : public ExpressaoBool {
	private:
		Expressao *Oper1;
		Expressao *Oper2;
		TipoOperRel tipoOp;
	public:
		ExpressaoRelacional(Expressao *Oper1, Expressao *Oper2, 
				TipoOperRel tipoOp);
		virtual ~ExpressaoRelacional();
		virtual bool Avalia(Contexto& C);
};

} /* namespace tiny */

#endif

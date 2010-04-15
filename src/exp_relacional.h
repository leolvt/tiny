#ifndef TINY_EXP_RELACIONAL_H
#define TINY_EXP_RELACIONAL_H

#include "expressaoRel.h"

namespace tiny{

typedef enum{
	op_>,
	op_>=,
	op_<,
	op_<=,
	op_=,
	op_!=
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

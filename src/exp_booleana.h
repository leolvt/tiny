#ifndef TINY_EXP_BOOLEANA_H
#define TINY_EXP_BOOLEANA_H

#include "expressaoBool.h"

namespace tiny{

typedef enum {
	op_or,
	op_and,
	op_not
} TipoOperBool;

class ExpressaoBooleana : public ExpressaoBool {
	private:
		ExpressaoBool *Oper1;
		ExpressaoBool *Oper2;
		TipoOperBool tipoOp;
	public:
		ExpressaoBooleana(ExpressaoBool *Oper1, ExpressaoBool *Oper2, 
				TipoOper tipoOp);
		virtual ~ExpressaoBooleana();
		virtual bool Avalia();
}

} /* namespace tiny */

#endif /* TINY_EXP_BOOLEANA_H */

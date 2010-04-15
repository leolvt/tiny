#ifndef TINY_BOOLEAN_H
#define TINY_BOOLEAN_H

#include "expressaoBool.h"
#include "contexto.h"

namespace tiny {


typedef enum {
	Valor,
	Parentesis
} TipoBoolean;

class Boolean : public ExpressaoBool {
	private:
		TipoBoolean tipoBoolean;
		bool valor;
		ExpressaoBool *Expb;
	public:
		Boolean(TipoBoolean tipo, bool valor = false, ExpressaoBool * Expb = NULL);
		virtual ~Boolean();
		virtual bool Avalia();
};


} /* namespace tiny */

#endif	/* TINY_BOOLEAN_H */
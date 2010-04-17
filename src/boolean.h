#ifndef TINY_BOOLEAN_H
#define TINY_BOOLEAN_H

#include "expressaoBool.h"
#include "contexto.h"

namespace tiny {


class Boolean : public ExpressaoBool {
	private:
		bool valor;
	public:
		Boolean(bool valor = false);
		virtual ~Boolean();
		virtual bool Avalia(Contexto& C);
};


} /* namespace tiny */

#endif	/* TINY_BOOLEAN_H */

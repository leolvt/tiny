#ifndef TINY_EXPRESSAOREL_H
#define TINY_EXPRESSAOREL_H

#include "contexto.h"

namespace tiny{

class ExpressaoRel{
	public:
		virtual ~ExpressaoRel() {};
		virtual bool Relaciona(Contexto& C) = 0;
};

} /* namespace tiny */

#endif /* TINY_EXPRESSAOREL_H */

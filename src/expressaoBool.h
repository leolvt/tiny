#ifndef TINY_EXPRESSAOBOOL_H
#define TINY_EXPRESSAOBOOL_H

#include "contexto.h"

namespace tiny{

class ExpressaoBool{
	public:
		virtual ~ExpressaoBool() {};
		virtual bool Avalia (Contexto& C) = 0;
};

} /* namespace tiny */


#endif /* TINY_EXPRESSAOBOOL_H */

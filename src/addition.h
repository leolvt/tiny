#ifndef		ADDITION_H
#define		ADDITION_H

#include "expression.h"

class Addition: public Expression
{
	private:
		Expression * Oper1;
		Expression * Oper2;
	public: 
		Addition(Expression * Op1, Expression * Op2);
		~Addition();

		double Interpret();
};

#endif		/* ADDITION_H */

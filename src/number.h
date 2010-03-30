#ifndef		NUMBER_H
#define		NUMBER_H

#include "expression.h"

class Number: public Expression
{
	private:
		double Num;
	public: 
		Number(double value);
		~Number();

		double Interpret();
};

#endif		/* NUMBER_H */

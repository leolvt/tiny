#include "addition.h"

Addition::Addition(Expression * Op1, Expression * Op2)
{
	this->Oper1 = Op1;
	this->Oper2 = Op2;
}

Addition::~Addition()
{

}

double Addition::Interpret()
{
	return Oper1->Interpret() + Oper2->Interpret();
}

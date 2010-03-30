#include "number.h"

Number::Number(double value)
{
	this->Num = value;
}

Number::~Number()
{

}

double Number::Interpret()
{
	return this->Num;
}

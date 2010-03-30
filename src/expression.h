#ifndef		EXPRESSION_H
#define		EXPRESSION_H

class Expression
{
	public: 
		virtual ~Expression() {};
		virtual double Interpret() = 0;
};

#endif		/* EXPRESSION_H */

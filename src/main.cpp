#include <iostream>
#include "driver.h"
using namespace tiny;

#include "contexto.h"
#include "expressao.h"
#include "exp_aritmetica.h"
#include "fator.h"

#if 1
int main()
{
	Contexto Ctx;

	std::cout << "Definindo Variaveis" << std::endl;

	Ctx.defineVariavel('a', 5.0);
	Ctx.defineVariavel('b', 3.0);

	std::cout << "Montando Expressão" << std::endl;

	Expressao * Exp = new ExpressaoAritmetica(
			new Fator(Numero, 2.0),
			new ExpressaoAritmetica(
					new ExpressaoAritmetica(
						new Fator(Numero, 3.0),
						new Fator(Parentesis, 
							0.0,
							new ExpressaoAritmetica(
								new Fator(Variavel, 0.0, NULL, 'a'),
								new Fator(RaizQuadrada,
									0.0,
									new Fator(Variavel, 0.0, NULL, 'b')
								),
								Adicao
							)
						),
						Multiplicacao
					),
					new Fator(Numero, 4.0),
					Divisao
			),
			Subtracao
	);

	std::cout << "Resultado: " << Exp->Calcula(Ctx) << std::endl;

	delete Exp;

	return 0;
}
#endif


#if 0
int main(int argc, char * argv[])
{
	Driver driver;

	std::cout << "Reading from stdin" << std::endl;

    std::string line;
    while( std::cout << "input: " &&  std::getline(std::cin, line) &&
	   !line.empty() )
    {
	
		bool result = driver.parse_string(line, "input");

		if (result)
		{
			// Do something!
		}
    }

	return 0;
}
#endif

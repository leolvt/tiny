#include <iostream>
#include "driver.h"
#include "contexto.h"
#include "expressao.h"
using namespace tiny;

#if 1
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
			Contexto Ctx;
			if (driver.exp_aritmetica)
			{
				std::cout << "Resultado: "; 
				std::cout << driver.exp_aritmetica->Calcula(Ctx) << std::endl;
			}
			if (driver.comando)
			{
				std::cout << "Executando Comando " << std::endl;
				driver.comando->Interpreta(Ctx);
			}
		}
		else
		{
			std::cout << "Erro!!" << std::endl;
		}
    }

	return 0;
}
#endif

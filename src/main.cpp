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
	Contexto Ctx;
    while( std::cout << "input: " &&  std::getline(std::cin, line) &&
	   !line.empty() )
    {
	
		bool result = driver.parse_string(line, "input");

		if (result)
		{
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

#include <iostream>
#include <vector>
#include "driver.h"
#include "contexto.h"
using namespace tiny;
using namespace std;

#if 1
int main(int argc, char * argv[])
{
	Driver driver;
	Contexto Ctx;

	if (argc > 1)
	{
		string file = string(argv[1]);
		driver.parse_file(file);
		driver.programa->Interpreta(Ctx);

		return 0;
	}

	std::cout << "Reading from stdin" << std::endl;

    std::string line;
    while( std::cout << "input: " &&  std::getline(std::cin, line) &&
	   !line.empty() )
    {
	
		bool result = driver.parse_string(line, "input");

		if (result)
		{
			if (driver.programa)
			{
				std::cout << "Executando Comando " << std::endl;
				driver.programa->Interpreta(Ctx);
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

#include <iostream>
#include <fstream>
#include <vector>

#include "driver.h"
#include "contexto.h"

using namespace tiny;

#if 0
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
		
		line = line + " endp";
		
		bool result = driver.parse_string(line, "input");

		if (result)
		{
			if (driver.programa)
			{
				driver.programa->Interpreta(Ctx);
				std::cout << std::endl;
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

int main(int argc, char *argv[])
{
    Contexto Ctx;
    Driver driver;
    bool readfile = false;

    for(int ai = 1; ai < argc; ++ai)
    {
        if (argv[ai] == std::string ("-p")) {
            driver.trace_parsing = true;
        }
        else if (argv[ai] == std::string ("-s")) {
            driver.trace_scanning = true;
        }
        else
        {
            // Lendo de um arquivo

            std::fstream infile(argv[ai]);
            if (!infile.good())
            {
                std::cerr << "Erro ao abrir arquivo: " << argv[ai] << std::endl;
                return 0;
            }

            bool result = driver.parse_stream(infile, argv[ai]);
            if (result)
            {
                if (driver.programa) driver.programa->Interpreta(Ctx);
                else std::cerr << "Erro ao processar o código" << std::endl;
				std::cout << std::endl;
            }

            readfile = true;
        }
    }

    if (readfile) return 0;
   
    std::cout << "Lendo programa da entrada padrão: " << std::endl;

    std::string line;
    while( std::cout << "entrada: " &&
           std::getline(std::cin, line) &&
           !line.empty() )
    {
        bool result = driver.parse_string(line, "entrada");

        if (result)
        {
            if (driver.programa) driver.programa->Interpreta(Ctx);
            else std::cerr << "Erro ao processar o código" << std::endl;
			std::cout << std::endl;
			delete driver.programa;
        }
    }
}

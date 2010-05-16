#include <iostream>
#include <fstream>
#include <vector>

#include "driver.h"
#include "contexto.h"

using namespace tiny;
#if 0
#include "lista_variaveis.h"
int main()
{
	ListaVariaveis lv;
	lv.adicionaVar('a');
	lv.adicionaVar('b');
	lv.adicionaVar('c');

	std::cout << lv[0] << std::endl;
	std::cout << lv[1] << std::endl;
	std::cout << lv[3] << std::endl;
}

#else
int main(int argc, char *argv[])
{
    Contexto Ctx;
    Driver driver;

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
                if (driver.programa) 
				{
					try {
						driver.programa->Executa(Ctx);
					} catch (Erro e)
					{
						std::cerr << e.obtemMsg() << std::endl;
						return 1;
					}
				}
                else 
				{
					std::cerr << "Erro ao processar o código" << std::endl;
					std::cout << std::endl;
				}
            }

        }
    }

    return 0;
}

#endif

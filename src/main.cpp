#include <iostream>
#include "driver.h"
using namespace tiny;

#include "contexto.h"

int main()
{
	return 0;
}

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

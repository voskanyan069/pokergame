#include <iostream>
#include <log/print.h>

void error(std::string e)
{
	std::cout << "\n\033[1;31m" << e << "\033[0m\n\n";
}

void warning(std::string w)
{
	std::cout << "\n\033[1;33m" << w << "\033[0m\n\n";
}

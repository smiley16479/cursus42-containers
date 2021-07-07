#include <stddef.h>
#include <iostream>
#include <memory> // std::length_error is here

void throwLength_error  (void)
{
	if ( 1 )
		throw std::length_error ("_M_fill_insert");
}

int main(int argc, char const *argv[])
{
	std::cout << a << std::endl;
	try
	{
		throwLength_error();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

#include <iostream>

int main(int argc, char const *argv[])
{
	char* str1 = "hello";
	char* str2 = "hella";
	std::string strg1 =  "hello";
	std::string strg2 =  "hello";

	if (strg1 == strg2)
		std::cout << "coucou\n";
	return 0;
}

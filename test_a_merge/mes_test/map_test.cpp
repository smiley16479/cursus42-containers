
#include "map.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <vector>
#include <iostream>

int map_test()
{
	ClassTest a(4);
	ClassTest b(5);
	ClassTest c(6);
	
	std::cout << GREEN "Map Declaration" RESET << std::endl;
	ft::map<std::string, std::int32_t> map1;
	// ft::map<std::string, std::int32_t> map1(a, b);

	std::cout << GREEN "Ended Normaly" RESET << std::endl;
	return 0;
}

int main(void)
{
	map_test();
	return 0;
}


#include "map.hpp" // friend_directory/solalDunckel/includes/
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
	ft::map</* const */ char, int> map1;
	// ft::map<std::string, std::int32_t> map1(a, b);
	// std::cout << map1;

	ft::pair<  char , int> val('B' , 2);
	// ft::map<char*, int>::iterator it(); //<- tu devrais avoir le msg de construction d'un iterator
	std::cout << GREEN "Map Insert" RESET << std::endl;
	std::cout << "mapTree _ptr : " << map1.getTree() << std::endl;

	map1.insert(val);
	val.first = 'g';
	val.second = 3;
	map1.insert(val);
	val.first = 'h';
	val.second = 3;
	map1.insert(val);
	std::cout << "first : " << map1.getTree()->myPair.first << " second : " << map1.getTree()->myPair.second << std::endl;

	// std::cout << "first :\n"; 
	// std::cout << "first : " << map1.getTree()->right->myPair.first
	// << " second : "<< map1.getTree()->right->myPair.second << std::endl;

	std::cout << GREEN "Map print_inorder" RESET << std::endl;
	map1.print_inorder(map1.getTree());
	std::cout << GREEN "Ended Normaly" RESET << std::endl;
	return 0;
}

#ifndef test
int main(void)
{
	map_test();
	return 0;
}
#endif

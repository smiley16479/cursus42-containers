
#include "map.hpp" // friend_directory/solalDunckel/includes/
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <map>
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

	ft::pair<char , int> val('m', 109);
	// ft::map<char*, int>::iterator it(); //<- tu devrais avoir le msg de construction d'un iterator
	std::cout << GREEN "Map Insert" RESET << std::endl;
	std::cout << "mapTree _ptr : " << map1.getTree() << std::endl;

	map1.insert(val);
	val.first = 'b';
	val.second = 98;
	map1.insert(val);
	val.first = 'a';
	val.second = 97;
	map1.insert(val);
	val.first = 'd';
	val.second = 100;
	map1.insert(val);
	val.first = 'c';
	val.second = 99;
	map1.insert(val);

	std::cout << MAGENTA "first : " << map1.getTree()->myPair.first <<
	" second : " << map1.getTree()->myPair.second << RESET << std::endl;

	// std::cout << "first :\n"; 
	// std::cout << "first : " << map1.getTree()->right->myPair.first
	// << " second : "<< map1.getTree()->right->myPair.second << std::endl;

	std::cout << GREEN "Map print_inorder" RESET << std::endl;
	map1.print_inorder(map1.getTree());
	// std::cout << GREEN "Map print_preorder" RESET << std::endl;
	// map1.print_preorder(map1.getTree());
	// std::cout << GREEN "Map print_postorder" RESET << std::endl;
	// map1.print_postorder(map1.getTree());

/* 	int i = 0;
	// ft::map<char , int>::iterator end = map1.end(); std::cout << "end_ptr : " << end.getPtr() << std::endl;
	for (ft::map<char , int>::iterator it = map1.begin(), end = map1.end(); it != end && i < 5; ++it, ++i) {
		std::cout << "le petit it nous donne : " << it->first << "::" << it->second << "\n";
	} */

//Verification d'it avec une map officielle
	std::map<char,int> off_map1;
	std::pair<char , int> off_val('c' , 3);
	off_map1.insert(off_val);
	off_val.first = 'b';
	off_val.second = 2;
	off_map1.insert(off_val);
	off_val.first = 'a';
	off_val.second = 1;
	off_map1.insert(off_val);
	// std::map<char, int>::iterator it = off_map1.begin();
	std::map<char , int>::iterator end = off_map1.end();
	std::cout << end._M_node->_M_parent << std::endl;
	std::cout << end._M_node->_M_right << std::endl;
	std::cout << end._M_node->_M_left << std::endl;
	std::map<char , int>::iterator it = off_map1.begin();
	for (std::map<char , int>::iterator /* it = off_map1.begin(),  */end = off_map1.end(); it != end; ++it) {
		std::cout << "le petit it nous donne : " <<  it->second << "\n";
	}
	off_val.first = 'd';
	off_val.second = 4;
	off_map1.insert(off_val);
	// --it;
	// --it;
	// --it;
	// ++it;
	std::cout << "le petit it nous donne : " <<  it->first << "::" <<  it->second << "\n";


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

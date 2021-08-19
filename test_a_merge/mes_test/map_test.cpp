
#include "map copy.hpp" // friend_directory/solalDunckel/includes/
// #include "map.hpp" // friend_directory/solalDunckel/includes/
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <map>
#include <iostream>

int my_mapList_test()
{
	std::cout << GREEN "Map Declaration" RESET << std::endl;
	ft::map<int, int> map1;
	// ft::map<std::string, std::int32_t> map1(a, b);
	// std::cout << map1;

	// ft::map<char*, int>::iterator it(); //<- tu devrais avoir le msg de construction d'un iterator
	std::cout << GREEN "Map Insert" RESET << std::endl;

	ft::pair<int , int> val(100, 100);
 	map1.insert(val);
	val.first = 200;
	val.second = 200;
	map1.insert(val);
	val.first = 400;
	val.second = 400;
	map1.insert(val);
	val.first = 800;
	val.second = 800;
	map1.insert(val);
	val.first = 50;
	val.second = 50;
	map1.insert(val);
	val.first = 25;
	val.second = 25;
	map1.insert(val);
	val.first = 75;
	val.second = 75;
	map1.insert(val).first;
	val.first = 37;
	val.second = 37;
	ft::map<int , int>::iterator it_to_erase2 = map1.insert(val).first;
	val.first = 33;
	val.second = 33;
	map1.insert(val).first;
	std::cout << GREEN "Map Insert (should be 9) : " RESET << map1.size() << std::endl;

	val.first = 35;
	val.second = 35;
	ft::map<int , int>::iterator it_to_erase1 = map1.insert(val).first;
	val.first = 43;
	val.second = 43;
	map1.insert(val);
	val.first = 28;
	val.second = 28;
	map1.insert(val);
	val.first = 39;
	val.second = 39;
	map1.insert(val);
	val.first = 47;
	val.second = 47;
	map1.insert(val).first;
	val.first = 30;
	val.second = 30;
	map1.insert(val);
	val.first = 32;
	val.second = 32;
	map1.insert(val);
	val.first = 31;
	val.second = 31;
	map1.insert(val).first;
	
	map1.printList();
	std::cout << "map1[500] : " << map1[500] << std::endl;
	map1[500] = 2;
	map1.printList();
	std::cout << "map1[500] : " << map1[500] << std::endl;
	ft::map<int, int>::iterator it = map1.find(500);
	std::cout << "it_finded :" << (*it).second << std::endl;

	std::cout << MAGENTA "Tests: " << RESET << std::endl;
	map1.printList();


	map1.erase (it_to_erase1, it_to_erase2);

	std::cout << MAGENTA "map(map &x) constructor " << RESET << std::endl;

	ft::map<int, int> map2(map1);
	map2.printList();
	std::cout << MAGENTA "LowerBound(35) :" << map2.lower_bound(35)->first << RESET << std::endl;
	std::cout << MAGENTA "upperBound(35) :" << map2.upper_bound(35)->first << RESET << std::endl;
	std::cout << MAGENTA "count 801 : " << map1.count(801) << RESET << std::endl;


	std::cout << GREEN "CONST_ITERATOR TEST :" RESET << std::endl;

	std::map<int, int> map_off;
	for (size_t i = 1; i <= 10; i++)
		map_off.insert(std::make_pair(i,i));	
	ft::map<int, int>::const_iterator const_my_it = map1.begin();
	std::map<int, int>::const_iterator const_of_it = map_off.begin();
	std::cout << "my_const_iterator : " << const_my_it._ptr->myPair.second << std::endl;
	std::cout << "of_const_iterator : " << const_of_it->second << std::endl;
	(*const_my_it).second; //  <- OK
	// const_my_it->second; // <- NE FONCTIONNE PAS !
	const_my_it._ptr->myPair.second = 24;
	// const_of_it->first = 24;
	std::cout << "const_iterator : " << const_my_it._ptr->myPair.second << std::endl;
	// count
	// lower_bound 
	// upper_bound
	// equal_range

	// std::cout << "first :\n"; 
	// std::cout << "first : " << map1.getTree()->right->myPair.first	
	// << " second : "<< map1.getTree()->right->myPair.second << std::endl;

	// int i = 0;
	// ft::map<int , int>::iterator it = map1.begin();
	// ft::map<char , int>::iterator end = map1.end(); std::cout << "end_ptr : " << end.getPtr() << std::endl;
	// for (ft::map<int , int>::iterator it = map1.begin(), end = map1.end(); it != end && i < 19; ++it, ++i) {
		// std::cout << "le petit it nous donne : " << it->first << "::" << it->second << "\n";
	// }
	// ft::map_iterator<int , int>::node_pointer try_it = it.getPtr();
	// std::cout << "Puis le petit it nous donne : " << try_it->myPair.first << "::" << try_it->myPair.second << "\n";
	// try_it = it.getLowest(try_it);
	// ++it;
	// std::cout << "Puis le petit it nous donne : " << it->first << "::" << it->second << "\n";



	std::cout << GREEN "Ended Normaly" RESET << std::endl;
	return 0;
}

/* int my_mapTree_test()
{
	ClassTest a(4);
	ClassTest b(5);
	ClassTest c(6);
	
	std::cout << GREEN "Map Declaration" RESET << std::endl;
	ft::map<int, int> map1;
	// ft::map<std::string, std::int32_t> map1(a, b);
	// std::cout << map1;

	// ft::map<char*, int>::iterator it(); //<- tu devrais avoir le msg de construction d'un iterator
	std::cout << GREEN "Map Insert" RESET << std::endl;
	std::cout << "mapTree _ptr : " << map1.getTree() << std::endl;

	ft::pair<int , int> val(100, 100);
 	map1.insert(val);
	val.first = 200;
	val.second = 200;
	map1.insert(val);
	val.first = 400;
	val.second = 400;
	map1.insert(val);
	val.first = 800;
	val.second = 800;
	map1.insert(val);
	val.first = 50;
	val.second = 50;
	map1.insert(val);
	val.first = 25;
	val.second = 25;
	map1.insert(val);
	val.first = 75;
	val.second = 75;
	map1.insert(val).first;
	val.first = 37;
	val.second = 37;
	ft::map<int , int>::iterator it_to_erase2 = map1.insert(val).first;
	val.first = 33;
	val.second = 33;
	map1.insert(val).first;
	val.first = 35;
	val.second = 35;
	ft::map<int , int>::iterator it_to_erase1 = map1.insert(val).first;
	val.first = 43;
	val.second = 43;
	map1.insert(val);
	val.first = 28;
	val.second = 28;
	map1.insert(val);
	val.first = 39;
	val.second = 39;
	map1.insert(val);
	val.first = 47;
	val.second = 47;
	map1.insert(val).first;
	val.first = 30;
	val.second = 30;
	map1.insert(val);
	val.first = 32;
	val.second = 32;
	map1.insert(val);
	val.first = 31;
	val.second = 31;
	map1.insert(val).first;
	map1.print2dTree(map1.getTree(), 0);
	
	std::cout << MAGENTA "first : " << map1.getTree()->myPair.first <<
	" second : " << map1.getTree()->myPair.second << RESET << std::endl;

	// map1.erase(it_to_erase1);
	// map1.print2dTree(map1.getTree(), 0);


	// ft::s_tree<ft::map<int, int>::value_type> * test = map1.nodeExist(map1.getTree(), 800);
	// std::cout << "test : " << test->myPair.second << std::endl; 
	// std::cout << "map1.upper_bound(41) : " << map1.upper_bound(41)->first << std::endl; 

	map1.erase (it_to_erase1, it_to_erase2);
	map1.print2dTree(map1.getTree(), 0);

	// count
	// lower_bound 
	// upper_bound
	// equal_range

	// std::cout << "first :\n"; 
	// std::cout << "first : " << map1.getTree()->right->myPair.first
	// << " second : "<< map1.getTree()->right->myPair.second << std::endl;

	std::cout << GREEN "Map print_inorder" RESET << std::endl;
	map1.print_inorder(map1.getTree());
	// std::cout << GREEN "Map print_preorder" RESET << std::endl;
	// map1.print_preorder(map1.getTree());
	// std::cout << GREEN "Map print_postorder" RESET << std::endl;
	// map1.print_postorder(map1.getTree());

	int i = 0;
	ft::map<int , int>::iterator it = map1.begin();
	// ft::map<char , int>::iterator end = map1.end(); std::cout << "end_ptr : " << end.getPtr() << std::endl;
	for (ft::map<int , int>::iterator end = map1.end(); it != end && i < 19; ++it, ++i) {
		std::cout << "le petit it nous donne : " << it->first << "::" << it->second << "\n";
	}
	// ft::map_iterator<int , int>::node_pointer try_it = it.getPtr();
	// std::cout << "Puis le petit it nous donne : " << try_it->myPair.first << "::" << try_it->myPair.second << "\n";
	// try_it = it.getLowest(try_it);
	++it;
	std::cout << "Puis le petit it nous donne : " << it->first << "::" << it->second << "\n";



	std::cout << GREEN "Ended Normaly" RESET << std::endl;
	return 0;
}
 */

#define test
#ifdef test

void offcial_map_test();

int main(void)
{
	my_mapList_test();
	// offcial_map_test();

	return 0;
}


void offcial_map_test()
{//Verification d'it avec une map officielle
	std::map<int,int> off_map1;
	std::pair<int , int> off_val(100, 100);
 	off_map1.insert(off_val);
	off_val.first = 200;
	off_val.second = 200;
	off_map1.insert(off_val);
	off_val.first = 400;
	off_val.second = 400;
	off_map1.insert(off_val);
	off_val.first = 800;
	off_val.second = 800;
	off_map1.insert(off_val);
	off_val.first = 50;
	off_val.second = 50;
	off_map1.insert(off_val);
	off_val.first = 25;
	off_val.second = 25;
	off_map1.insert(off_val);
	off_val.first = 75;
	off_val.second = 75;
	std::map<int , int>::iterator it_to_erase2 = off_map1.insert(off_val).first;
	off_val.first = 37;
	off_val.second = 37;
	off_map1.insert(off_val);
	off_val.first = 33;
	off_val.second = 33;
	off_map1.insert(off_val).first;
	off_val.first = 35;
	off_val.second = 35;
	off_map1.insert(off_val).first;
	off_val.first = 43;
	off_val.second = 43;
	off_map1.insert(off_val);
	off_val.first = 28;
	off_val.second = 28;
	off_map1.insert(off_val);
	off_val.first = 39;
	off_val.second = 39;
	off_map1.insert(off_val);
	off_val.first = 47;
	off_val.second = 47;
	off_map1.insert(off_val);
	off_val.first = 30;
	off_val.second = 30;
	off_map1.insert(off_val);
	off_val.first = 32;
	off_val.second = 32;
	off_map1.insert(off_val);
	off_val.first = 31;
	off_val.second = 31;
	off_map1.insert(off_val);
	off_val.first = 38;
	off_val.second = 38;
	std::map<int , int>::iterator it_to_erase1 =  off_map1.insert(off_val).first;
	off_val.first = 40;
	off_val.second = 40;
	off_map1.insert(off_val);

	off_map1.erase (it_to_erase1, it_to_erase2);


	std::map<int, int> map2(off_map1);
	std::cout << MAGENTA "LowerBound(35) :" << map2.lower_bound(35)->first << RESET << std::endl;
	std::cout << MAGENTA "upperBound(35) :" << map2.upper_bound(35)->first << RESET << std::endl;

	// std::map<char, int>::iterator it = off_map1.begin();
	std::map<int , int>::iterator end = off_map1.end();
	std::cout << end._M_node->_M_parent << std::endl;
	std::cout << end._M_node->_M_right << std::endl;
	std::cout << end._M_node->_M_left << std::endl;
	std::map<int , int>::iterator off_it = off_map1.begin();
	for (std::map<int , int>::iterator end = off_map1.end(); off_it != end; ++off_it) {
		std::cout << "le petit off_it nous donne : " <<  off_it->second << "\n";
	}
	// off_val.first = 'd';
	// off_val.second = 4;
	// off_map1.insert(off_val);
	// --off_it;
	// ++off_it;
	// off_it = std::map<char , int>::iterator();
	std::cout << "le petit off_it nous donne : " <<  off_it->first << "::" <<  off_it->second << "\n";
}



#endif

// #define test

// #include "ClassTest.hpp"
#include "colors.h"
#include <map>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <fstream>
// #include "map copy.hpp"
#include "map.hpp" // friend_directory/solalDunckel/includes/
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"

#ifdef binary_out
	std::ofstream myfile;
#endif

template <typename T1, typename T2>
void insert(T1* lhs, T2* rhs, size_t insertedElem)
{
	ft::pair<int , int> pair(100, 100);
	lhs->insert(pair);
	std::pair<int , int> of_pair(100, 100);
	rhs->insert(of_pair);

 	for (size_t i = 1; i < insertedElem; i++)
	{
		int item = rand() /* % lhs->size() */;
		// std::cout << "item : " << item << "\n";
		pair.first = item;
		pair.second = item;
		of_pair.first = item;
		of_pair.second = item;
		rhs->insert(of_pair);
		lhs->insert(pair);
	}
	return ;	 
}


template <typename T1, typename T2>
int is_equal(T1& lhs, T2& rhs, std::string str)
{
	(void)rhs;(void)str;
	int item = rand();
#ifndef binary_out
	if (lhs.size() != rhs.size()) {
		std::cout << RED "[KO] size(1) - lhs : " << lhs.size() <<  ", rhs : " << rhs.size() << RESET << std::endl; return 0;}
	if (lhs.lower_bound(item)._ptr && lhs.lower_bound(item)->first != rhs.lower_bound(item)->first) {
		std::cout << RED "[KO] lower_bound() - lhs : " << lhs.lower_bound(item)->first <<  ", rhs : " << rhs.lower_bound(item)->first << RESET << std::endl; return 0;}
	if (lhs.find(item)._ptr && (lhs.find(item)->second != rhs.find(item)->second)) {
		std::cout << RED "[KO] find() - lhs : " << lhs.find(item)->second <<  ", rhs : " << rhs.find(item)->second  << RESET << std::endl; return 0;}
	if (lhs.erase(item) != rhs.erase(item)) {
		std::cout << RED "[KO] erase() - lhs : " << lhs.erase(item) <<  ", rhs : " << rhs.erase(item) << RESET << std::endl; return 0;}
	if (lhs.size() != rhs.size()) {
		std::cout << RED "[KO] size(2) - lhs : " << lhs.size() <<  ", rhs : " << rhs.size() << RESET << std::endl; return 0;}

	typename T1::iterator T1_b_it = lhs.begin(), T1_e_it = lhs.end();
	typename T2::iterator T2_b_it = rhs.begin(), T2_e_it = rhs.end();
	for (; T1_b_it != T1_e_it; ++T1_b_it, ++T2_b_it)
		if (T1_b_it->first != T2_b_it->first || T1_b_it->second != T2_b_it->second)
			return 0;
	if (T2_b_it != T2_e_it)
		return 0;
	std::cout << GREEN << str << std::setw(55 - str.length()) << " ✅" RESET << std::endl;
	return 1;
#else
	myfile << lhs.size() << lhs.lower_bound(item)->first << lhs.find(item)->second << lhs.erase(item) << lhs.size();
	return 1;
#endif
}

template <typename T1, typename T2>
void IS_EQUAL(T1 lhs, T2 rhs, std::string str)
{
	(void)rhs;(void)str;
#ifndef binary_out
	if (lhs == rhs)
		std::cout << GREEN << str << std::setw(55 - str.length()) << " ✅" RESET << std::endl;
	else
		std::cout << RED "[KO] lhs : " << lhs <<  ", rhs : " << rhs << RESET << std::endl;
	return ;
#else
	myfile << lhs;
#endif
}

void map_constructor()
{
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	insert(&map1, &off_map1, 100);
	ft::map<int, int> map2(map1.begin(), map1.end());
	std::map<int, int> off_map2(off_map1.begin(), off_map1.end());
	ft::map<int, int> map3 = map2;
	std::map<int, int> off_map3 = off_map2;
	ft::map<int, int> map4 = map3;
	std::map<int, int> off_map4 = off_map3;

	// typename ft::map<int, int>::iterator T1_b_it = map1.begin();
	// typename std::map<int, int>::iterator T2_b_it = off_map1.begin();
	// std::cout << "T1->first : " << T1_b_it->first << ", T2->first : " << T2_b_it->first << std::endl;
	// std::cout << "map1.lower_bound().first : " << map1.lower_bound(10)->first << ", T2.lower_bound().first : " << off_map1.lower_bound(10)->first << std::endl;

	bool good = is_equal(map1, off_map1, "constructor empty (1)") ||
	is_equal(map2, off_map2, "constructor range (2)") ||
	is_equal(map3, off_map3, "constructor copy (3)") ||
	is_equal(map3, off_map3, "constructor copy (3) 'type ='");
	std::cout << (good ? YELLOW : RED) << "Map Declaration " <<  (good ? "✅" : "❌") << RESET << std::endl;
}

void map_capacity()
{
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	insert(&map1, &off_map1, 100);
	IS_EQUAL(map1.empty(), off_map1.empty(), "Capacity empty()  TEST 1");
	IS_EQUAL(map1.size(), off_map1.size(), "Capacity size()   TEST 1");
	insert(&map1, &off_map1, 100);
	IS_EQUAL(map1.empty(), off_map1.empty(), "Capacity empty()  TEST 2");
	IS_EQUAL(map1.size(), off_map1.size(), "Capacity size()   TEST 2");
	insert(&map1, &off_map1, 100);
	IS_EQUAL(map1.empty(), off_map1.empty(), "Capacity empty()  TEST 3");
	IS_EQUAL(map1.size(), off_map1.size(), "Capacity size()   TEST 3");
	std::cout << YELLOW "Map Capacity ✅" RESET << std::endl;

	return ;
}

void map_acces()
{
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	for (size_t i = 1; i <= 1000; i++)
	{
		int item = rand() % INT32_MAX;
		map1[item] = item;
#ifndef binary_out
		off_map1[item] = item;
		if (map1[item] == off_map1[item]) {
			std::cout << "\e[1A\e["; // remise en début de ligne pour incrémentation de compteur
			std::cout << GREEN "row : "<< i << std::setw(55 - 10) << " ✅" RESET << std::endl;
		}
		else
			std::cout << RED "[KO] map1[" << item << "] : " << map1[item] <<  ", off_map1[" 
			<< item << "] : " << off_map1[item] << RESET << std::endl;
#else
	myfile << map1[item];
#endif
	}
	std::cout << YELLOW "Map Acces Element ✅" RESET << std::endl;

	return ;
}

void map_modifiers()
{
	// insert erase swap clear
	std::cout << YELLOW "Map Modifiers : " RESET << std::endl;
	std::cout << YELLOW "___Map Insert : [OK]" RESET << std::endl;
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	insert(&map1, &off_map1, 100/* 3 */);

	ft::pair<int , int> pair(100, 100);
	std::pair<int , int> of_pair(100, 100);
	ft::map<int, int> map2;
	map2.insert(map2.begin(), pair);
	std::map<int, int> off_map2;
	off_map2.insert(off_map2.begin(), of_pair);
	
	ft::map<int, int> map3(map2.begin(), map2.end());
	std::map<int, int> off_map3(off_map2.begin(), off_map2.end());
// std::cout << "ICI !! " << map2.size() << ":" << off_map2.size() << "/" << map1.begin()->first << std::endl;
	is_equal(map1, off_map1, "insert (1)");
	is_equal(map2, off_map2, "insert (2)");
	is_equal(map3, off_map3, "insert (3)");
	std::cout << YELLOW "___Map Erase : [OK]" RESET << std::endl;

	map1.erase(map1.begin()); off_map1.erase(off_map1.begin());
	is_equal(map1, off_map1, "void erase (1) (iterator position)");
	map1.erase(map1.begin()->first); off_map1.erase(off_map1.begin()->first);
	is_equal(map1, off_map1, "size_type erase (2) (const key_type& k)");
	map1.erase(map1.begin(), map1.end()); off_map1.erase(off_map1.begin(), off_map1.end()); // <- problem
	is_equal(map1, off_map1, "void erase (3) (iterator first, iterator last)");
	std::cout << YELLOW "___Map Swap : [OK]" RESET << std::endl;
	map1.swap(map2); off_map1.swap(off_map2);
	is_equal(map1, off_map1, "void swap (map& x)");
	is_equal(map2, off_map2, "comparaison avec l'elem objet du swap");

	map3.clear(); off_map3.clear();
	std::cout << YELLOW "___Map Clear : [OK]" RESET << std::endl;
	// std::cout << "map3.lower_bound(10)._ptr : " << map3.lower_bound(10)._ptr << "\n";
	is_equal(map3, off_map3, "void Clear()");
	std::cout << YELLOW "Map Modifiers ✅" RESET << std::endl;

	return ;
}

void map_operations()
{
	// find count lower/upper_bound equal_range
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	insert(&map1, &off_map1, 100);

	std::cout << YELLOW "___Map find() count() lower/upper_bound() equal_range() : [OK]" RESET << std::endl << std::endl;
	for (size_t i = 1; i <= 100; i++)
	{
		int item = rand() % INT32_MAX;
#ifndef binary_out
		if (// fisrt is not used as if it is not found the data depends on the type
			// map1.find(item)->first == off_map1.find(item)->first && 
			map1.find(item)->second == off_map1.find(item)->second && 
			map1.count(item) == off_map1.count(item)  &&
			// map1.lower_bound(item)->first == off_map1.lower_bound(item)->first && 
			map1.lower_bound(item)->second == off_map1.lower_bound(item)->second && 
			// map1.upper_bound(item)->first == off_map1.upper_bound(item)->first &&
			map1.upper_bound(item)->second == off_map1.upper_bound(item)->second && 
			// map1.equal_range(item).first->first == off_map1.equal_range(item).first->first && 
			map1.equal_range(item).first->second == off_map1.equal_range(item).first->second && 
			// map1.equal_range(item).second->first == off_map1.equal_range(item).second->first && 
			map1.equal_range(item).second->second == off_map1.equal_range(item).second->second
			){
			std::cout << "\e[1A\e["; // remise en début de ligne pour incrémentation de compteur
			std::cout << GREEN "row : "<< i << std::setw(46) << " ✅" RESET << std::endl;
		}
		else
			std::cout << RED "[KO] map1.find(item)->first : " << map1.find(item)->first <<
			", off_map1.find(item)->first : " << off_map1.find(item)->first << RESET << std::endl;
#else
	myfile << map1.find(item)->second << map1.find(item)->second << map1.count(item) << map1.lower_bound(item)->second
	<< map1.upper_bound(item)->second << map1.equal_range(item).first->second << map1.equal_range(item).second->second;
#endif
	}
	std::cout << YELLOW "Map Operations ✅" RESET << std::endl;

	return ;
}

template<typename T1, typename T2>
void full_fill(T1 *map1, T2 *off_map1)
{
	ft::pair<int,int> val(100, 100);
 	map1->insert(val);
	val.first = 200;
	val.second = 200;
	map1->insert(val);
	val.first = 400;
	val.second = 400;
	map1->insert(val);
	val.first = 800;
	val.second = 800;
	map1->insert(val);
	val.first = 50;
	val.second = 50;
	map1->insert(val);
	val.first = 25;
	val.second = 25;
	map1->insert(val);
	val.first = 75;
	val.second = 75;
	map1->insert(val).first;
	val.first = 37;
	val.second = 37;
	map1->insert(val).first;
	val.first = 33;
	val.second = 33;
	map1->insert(val).first;
	// std::cout << YELLOW "Map Insert (should be 9) : " RESET << map1->size() << std::endl;
	val.first = 35;
	val.second = 35;
	map1->insert(val).first;
	val.first = 43;
	val.second = 43;
	map1->insert(val);
	val.first = 28;
	val.second = 28;
	map1->insert(val);
	val.first = 39;
	val.second = 39;
	map1->insert(val);
	val.first = 47;
	val.second = 47;
	map1->insert(val).first;
	val.first = 30;
	val.second = 30;
	map1->insert(val);
	val.first = 32;
	val.second = 32;
	map1->insert(val);
	val.first = 31;
	val.second = 31;
	map1->insert(val).first;

	std::pair<int,int> off_val(100, 100);
 	off_map1->insert(off_val);
	off_val.first = 200;
	off_val.second = 200;
	off_map1->insert(off_val);
	off_val.first = 400;
	off_val.second = 400;
	off_map1->insert(off_val);
	off_val.first = 800;
	off_val.second = 800;
	off_map1->insert(off_val);
	off_val.first = 50;
	off_val.second = 50;
	off_map1->insert(off_val);
	off_val.first = 25;
	off_val.second = 25;
	off_map1->insert(off_val);
	off_val.first = 75;
	off_val.second = 75;
	off_map1->insert(off_val).first;
	off_val.first = 37;
	off_val.second = 37;
	off_map1->insert(off_val).first;
	off_val.first = 33;
	off_val.second = 33;
	off_map1->insert(off_val).first;
	// std::cout << YELLOW "Map Insert (should be 9) : " RESET << off_map1->size() << std::endl;
	off_val.first = 35;
	off_val.second = 35;
	off_map1->insert(off_val).first;
	off_val.first = 43;
	off_val.second = 43;
	off_map1->insert(off_val);
	off_val.first = 28;
	off_val.second = 28;
	off_map1->insert(off_val);
	off_val.first = 39;
	off_val.second = 39;
	off_map1->insert(off_val);
	off_val.first = 47;
	off_val.second = 47;
	off_map1->insert(off_val).first;
	off_val.first = 30;
	off_val.second = 30;
	off_map1->insert(off_val);
	off_val.first = 32;
	off_val.second = 32;
	off_map1->insert(off_val);
	off_val.first = 31;
	off_val.second = 31;
	off_map1->insert(off_val).first;
}

/* void map_iterator()
{
	ft::map<int, int> map1;
	std::map<int, int> off_map1;
	full_fill(&map1, &off_map1);

	{ft::map<int, int>::iterator it = map1.begin(), end = map1.end();
	for (; it != end; it++)
#ifdef binary_out
	myfile << it->second << std::endl;
#else
	std::cout << it->second << std::endl;
#endif
}
	std::cout << YELLOW "Map iterator ✅" RESET << std::endl;
	{ft::map<int, int>::const_iterator cons_it = map1.begin(), const_end = map1.end();
	for (; cons_it != const_end; cons_it++)
#ifdef binary_out
	myfile << cons_it->second << std::endl;
#else
	std::cout << cons_it->second << std::endl;
#endif
}
	std::cout << YELLOW "Map const_iterator ✅" RESET << std::endl;

	{ft::map<int, int>::reverse_iterator it = map1.rbegin(), end = map1.rend();
	for (; it != end; it++)
#ifdef binary_out
	myfile << it->second << std::endl;
#else
	std::cout << it->second << std::endl;
#endif
}
	std::cout << YELLOW "Map reverse_iterator ✅" RESET << std::endl;

	{ft::map<int, int>::const_reverse_iterator it = map1.rbegin(), end = map1.rend();
	for (; it != end; it++)
#ifdef binary_out
	myfile << it->second << std::endl;
#else
	std::cout << it->second << std::endl;
#endif
}
	std::cout << YELLOW "Map const_revese_iterator ✅" RESET << std::endl;
	return ;
} */


void offcial_map_test();

#ifdef test
int main()
{
#else
int map_test()
{
#endif
	std::cout << GREEN "Correction des Maps" RESET << std::endl;
#ifdef binary_out
	#ifdef off
			myfile.open("mapTest_off.txt");
			namespace ft = std;
	#else
			myfile.open("mapTest_perso.txt");
	#endif
#endif
	// map_constructor();
	// map_capacity();
	// map_acces();
	// map_modifiers();
	map_operations();
	// map_iterator();

	// offcial_map_test();
#ifdef binary_out
	myfile.close();
#endif
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
	std::cout << end._M_node->_M_parent << ":" << end->first << std::endl;
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

/* int my_mapTree_test()
{
	ClassTest a(4);
	ClassTest b(5);
	ClassTest c(6);
	
	std::cout << YELLOW "Map Declaration" RESET << std::endl;
	ft::map<int, int> map1;
	// ft::map<std::string, std::int32_t> map1(a, b);
	// std::cout << map1;

	// ft::map<char*, int>::iterator it(); //<- tu devrais avoir le msg de construction d'un iterator
	std::cout << YELLOW "Map Insert" RESET << std::endl;
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

	std::cout << YELLOW "Map print_inorder" RESET << std::endl;
	map1.print_inorder(map1.getTree());
	// std::cout << YELLOW "Map print_preorder" RESET << std::endl;
	// map1.print_preorder(map1.getTree());
	// std::cout << YELLOW "Map print_postorder" RESET << std::endl;
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



	std::cout << YELLOW "Ended Normaly" RESET << std::endl;
	return 0;
}
 */

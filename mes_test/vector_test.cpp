
#include "ClassTest.hpp"
#include "vector.hpp"
#include "colors.h"
#include <iostream>
#include <fstream>
#include <vector>

std::ofstream file_out;


void constructors_test()
{
	ft::vector<int> vec1(10,5);
	for (const auto& i : vec1)
#ifdef binary_out
		file_out << i << "\n";
#else
 		std::cout << i << "\n";
#endif

	ft::vector<int> vec1_bis(vec1);
	for (const auto& i : vec1_bis)
#ifdef binary_out
		file_out << i << "\n";
#else
 		std::cout << i << "\n";
#endif

	std::vector<int> vec2(10,5);
	std::vector<int>::iterator off_it = vec2.begin();
	std::vector<int>::iterator off_it_end = vec2.end();
	ft::vector<int> my_vec(off_it, off_it_end);
	for (ft::vector<int>::iterator it = my_vec.begin(), end = my_vec.end(); it != end; it++)
#ifdef binary_out
		file_out << *it << "\n";
#else
		std::cout << "*it : " << *it << std::endl;
#endif

	ft::vector<int> vec3 = vec1;
	for (const auto& i : vec3)
#ifdef binary_out
		file_out << i << "\n";
#else
 		std::cout << i << "\n";
#endif
	std::cout << YELLOW "vector constructor type(1, 2, 3, 4) ✅" << RESET << std::endl;

	return ;
}


void reverse_it_test()
{
	ft::vector<int> my_vec(10, 10);
	for (size_t i = 1; i <= 10; i++)
		my_vec.push_back(i);
	for (ft::vector<int>::reverse_iterator my_it = my_vec.rbegin(), my_it_end = my_vec.rend(); my_it != my_it_end; ++my_it)
#ifdef binary_out
		file_out << *my_it << "\n";
#else
		std::cout << "*rev_it : " << *my_it << std::endl;
#endif
	for (ft::vector<int>::const_reverse_iterator const_rev_it = my_vec.rbegin(), const_rev_end = my_vec.rend(); const_rev_it != const_rev_end; ++const_rev_it)
#ifdef binary_out
		file_out << *const_rev_it << "\n";
#else
		std::cout << "*const_rev_it : " << *const_rev_it << std::endl;
#endif
	std::cout << YELLOW "vector reverse_it & const_reverse_it test ✅" << RESET << std::endl;

	return ;
}

void it_test()
{
	ft::vector<int> my_vec(10, 10);
	for (size_t i = 1; i <= 10; i++)
		my_vec.push_back(i);
	// Cpp source :"If a reallocation happens, all iterators, pointers and references related to the container are invalidated."
	ft::vector<int>::const_iterator const_it = my_vec.begin(), const_end = my_vec.end();
	for (; const_it != const_end; ++const_it)
#ifdef binary_out
		file_out << *const_it << "\n";
#else
		std::cout << "*const_it : " << *const_it << std::endl;
#endif
	ft::vector<int>::iterator it = my_vec.begin(), end = my_vec.end();
	for (; it != end; ++it)
#ifdef binary_out
		file_out << *it << "\n";
#else
		std::cout << "*it : " << *it << std::endl;
#endif
	std::cout << YELLOW "vector it & const_it test ✅" << RESET << std::endl;
	return ;
}

void capacity_test()
{
// size_type size(void) const
// size_type	max_size(void) const
// void		resize(size_type n, _T val)
// size_type capacity() const; // implementé differement ds le mien 
// bool empty() const;
// void reserve (size_type n);
	ft::vector<int> my_vec(10, 10);
#ifdef binary_out
		file_out << my_vec.size() << "\n";
		file_out << my_vec.max_size() << "\n";
		my_vec.resize( 18, int(18));
		file_out << my_vec.size() << "\n";
		file_out << my_vec.empty() << "\n";
		my_vec.reserve (0);
		file_out << my_vec.size() << "\n";
#else
		std::cout << "my_vec.size() : " << my_vec.size() << std::endl;
		std::cout << "my_vec.max_size() : " << my_vec.max_size() << std::endl;
		my_vec.resize( 18, int(18));
		std::cout << "apres my_vec.resize( 18, int(18)) : " << my_vec.size() << std::endl;
		std::cout << my_vec.empty() << "\n";
		my_vec.reserve (0);
		std::cout << my_vec.size() << "\n";
#endif
	std::cout << YELLOW "vector capacity_test ✅" << RESET << std::endl;
	return ;
}


void element_acces()
{
			// reference	operator[] (size_type n);
		// const_reference operator[] (size_type n) const;
		// reference at (size_type n);
		// const_reference at (size_type n) const;
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
	ft::vector<int> my_vec;
	for (size_t i = 0; i < 100; i++)
		my_vec.push_back(i)	;

#ifdef binary_out
	file_out << my_vec[10] << "\n";
	file_out << my_vec[20] << "\n";
	file_out << my_vec[30] << "\n";
	file_out << my_vec[40] << "\n";
	file_out << my_vec[99] << "\n";
	file_out << my_vec.at(99) << "\n";
	// file_out << my_vec.at(199) << "\n";
	file_out << my_vec.front() << "\n";
	file_out << my_vec.back() << "\n";
#else
	std::cout << my_vec[10] << "\n";
	std::cout << my_vec[20] << "\n";
	std::cout << my_vec[30] << "\n";
	std::cout << my_vec[40] << "\n";
	std::cout << my_vec[99] << "\n";
	std::cout << my_vec.at(99) << "\n";
	// std::cout << my_vec.at(199) << "\n";
	std::cout << my_vec.front() << "\n";
	std::cout << my_vec.back() << "\n";
#endif
	std::cout << YELLOW "vector element_acces_test ✅" << RESET << std::endl;
	return ;
}

void modifier_test()
{
	// // template <class InputIterator>  void assign (InputIterator first, InputIterator last); //range (1) 🔥
	// // void assign (size_type n, const value_type& val); //fill (2) 🔥
	// void push_back (const value_type& val);
	// void pop_back();
	// iterator insert (iterator position, const value_type& val); // single element (1)	
    // void insert (iterator position, size_type n, const value_type& val); // fill (2)
	// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); //range (3)
	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
	// void swap (vector& x);
	// void clear();
	ft::vector<int> my_vec2;
	for (size_t i = 0; i < 100; i++)
		my_vec2.push_back(i)	;
	ft::vector<int>::iterator it = my_vec2.begin(), end = my_vec2.end();
	ft::vector<int> my_vec;
	my_vec.assign(it, end);

#ifdef binary_out
	file_out << my_vec[10] << "\n";
	file_out << my_vec[20] << "\n";
	file_out << my_vec[30] << "\n";
	file_out << my_vec[40] << "\n";
	file_out << my_vec[99] << "\n";
	file_out << my_vec.at(99) << "\n";
	// file_out << my_vec.at(199) << "\n";
	file_out << my_vec.front() << "\n";
	file_out << my_vec.back() << "\n";
#else
	std::cout << my_vec[10] << "\n";
	std::cout << my_vec[20] << "\n";
	std::cout << my_vec[30] << "\n";
	std::cout << my_vec[40] << "\n";
	std::cout << my_vec[99] << "\n";
	std::cout << my_vec.at(99) << "\n";
	// std::cout << my_vec.at(199) << "\n";
	std::cout << my_vec.front() << "\n";
	std::cout << my_vec.back() << "\n";
#endif

	my_vec.insert(my_vec.begin() + 2, 10);
	my_vec.pop_back();
	// my_vec.pop_back(); // <- at will throw if pop_back() again
#ifdef binary_out
	file_out << my_vec[2] << "\n";
	file_out << my_vec[10] << "\n";
	file_out << my_vec[20] << "\n";
	file_out << my_vec[30] << "\n";
	file_out << my_vec[40] << "\n";
	file_out << my_vec[99] << "\n";
	file_out << my_vec.at(99) << "\n";
	// file_out << my_vec.at(199) << "\n";
	file_out << my_vec.front() << "\n";
	file_out << my_vec.back() << "\n";
#else
	std::cout << my_vec[2] << "\n";
	std::cout << my_vec[10] << "\n";
	std::cout << my_vec[20] << "\n";
	std::cout << my_vec[30] << "\n";
	std::cout << my_vec[40] << "\n";
	std::cout << my_vec[99] << "\n";
	std::cout << my_vec.at(99) << "\n";
	// std::cout << my_vec.at(199) << "\n";
	std::cout << my_vec.front() << "\n";
	std::cout << my_vec.back() << "\n";
#endif
	my_vec.erase(my_vec.begin() + 50, my_vec.end());
#ifdef binary_out
	file_out << my_vec[2] << "\n";
#else
	std::cout << " test : "<< my_vec[2] << "\n";
#endif
std::cout << YELLOW "vector modifier_test ✅" << RESET << std::endl;
	return ;
}

void non_member_function()
{
	ft::vector<int> my_vec2;
	for (size_t i = 0; i < 100; i++)
		my_vec2.push_back(i)	;
	ft::vector<int>::iterator it = my_vec2.begin(), end = my_vec2.end();
	ft::vector<int> my_vec;
	my_vec.assign(it, end);

	#ifdef binary_out
	file_out << (my_vec == my_vec2) << "\n";
	file_out << (my_vec != my_vec2) << "\n";
	file_out << (my_vec <  my_vec2) << "\n";
	file_out << (my_vec <= my_vec2) << "\n";
	file_out << (my_vec >  my_vec2) << "\n";
	file_out << (my_vec >= my_vec2) << "\n";
#else
	std::cout << (my_vec == my_vec2) << "\n";
	std::cout << (my_vec != my_vec2) << "\n";
	std::cout << (my_vec <  my_vec2) << "\n";
	std::cout << (my_vec <= my_vec2) << "\n";
	std::cout << (my_vec >  my_vec2) << "\n";
	std::cout << (my_vec >= my_vec2) << "\n";
#endif
	my_vec2.insert(it + 10, 100);
	#ifdef binary_out
	file_out << (my_vec == my_vec2) << "\n";
	file_out << (my_vec != my_vec2) << "\n";
	file_out << (my_vec <  my_vec2) << "\n";
	file_out << (my_vec <= my_vec2) << "\n";
	file_out << (my_vec >  my_vec2) << "\n";
	file_out << (my_vec >= my_vec2) << "\n";
#else
	std::cout << (my_vec == my_vec2) << "\n";
	std::cout << (my_vec != my_vec2) << "\n";
	std::cout << (my_vec <  my_vec2) << "\n";
	std::cout << (my_vec <= my_vec2) << "\n";
	std::cout << (my_vec >  my_vec2) << "\n";
	std::cout << (my_vec >= my_vec2) << "\n";
#endif
	std::cout << YELLOW "vector non_member_function_test ✅" << RESET << std::endl;
	return ;
}

void vector_test()
{
#ifdef binary_out
#ifdef off
		file_out.open("vectorTest_off.txt");
		std::cout << MAGENTA "Correction des Container OFFICIEL" RESET << std::endl;
		namespace ft = std;
#else
		std::cout << MAGENTA "Correction de mes Container" RESET << std::endl;
		file_out.open("vectorTest_perso.txt");
#endif
#endif
	ClassTest b(5);
	ClassTest c(6);
	std::cout << GREEN "Correction des Vecteurs" RESET << std::endl;
	constructors_test();
	element_acces();
	capacity_test();
	modifier_test();
	non_member_function();
	reverse_it_test();
	it_test();

	return ;
}

#ifdef test
int main(void)
{
	vector_test();
	// reverse_it_test();

	return 0;
}
#endif

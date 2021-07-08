
#include "vector.hpp"
#include "stack.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <vector>
#include <iostream>

int stack_test()
{
	ClassTest b(5);
	ClassTest c(6);
	std::cout << GREEN "Correction de Stack" RESET << std::endl;
	ft::stack<ClassTest> stack1;
	stack1.push(b);
	std::cout << GREEN "Correction de Stack_top()" RESET << std::endl;
	std::cout << "Stack_top()" << stack1.top() << std::endl;

	std::cout << GREEN "Correction des Vecteurs" RESET << std::endl;

	ft::vector<ClassTest> vec(2, c);
	ft::vector<ClassTest> vec2(2, b);
	std::cout << YELLOW "Correction operator ==" RESET << std::endl;
	std::cout << "(vec == vec2) : " << (vec == vec2)  << std::endl;
	std::cout << "(vec < vec2) : " << (vec2 < vec)  << std::endl;
	std::cout << vec.capacity() << std::endl;
	// vec.resize(18);

	// std::cout << YELLOW "Correction de vec1=vec2" RESET << std::endl;
	// ft::vector<ClassTest> vect(2, 8); // not implemented yet
	// vec = vect;

	// std::cout << YELLOW "Correction Iterator" RESET << std::endl;

	// for (auto i : vec)
	// 	std::cout << i << "\n";

	// for (ft::vector<ClassTest>::Iterator it = vec.begin(), end = vec.end(); it != end; ++it)
	// 	std::cout << *it << "\n";

	// std::cout << YELLOW "Correction de resize()" RESET << std::endl;
	// vec.resize(1);
	// std::cout << YELLOW "Correction de operator[]" RESET << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i].getNb() << std::endl;

	// std::cout << YELLOW "Correction de at" RESET << std::endl;
	// try
	// {
	// 	vec.at(3);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	std::cout << YELLOW "Correction de max_size()" RESET << std::endl;
	std::cout << "vec.max_size() : " << vec.max_size() << std::endl;
	// vec.getNb();
	std::cout << YELLOW "Correction de push_back()" RESET << std::endl;
	vec.push_back(b);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

	// std::cout << YELLOW "Correction de pop()" RESET << std::endl;
	// vec.pop_back();
	// for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
	// 	std::cout << *it << "\n";

	std::cout << YELLOW "Correction de insert()" RESET << std::endl;
	std::cout << GREEN "_Rsize : " RESET << vec.capacity() << std::endl;
	ft::vector<ClassTest>::iterator it = vec.begin();
	++it;
	// std::cout << "test \n" << it << std::endl;
	vec.insert(++it, 4);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";
	it = vec.begin();
	vec.insert(++it, 4);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";
	it = vec.begin();
	vec.insert(it, 4, b);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

	std::cout << YELLOW "Correction de erase()" RESET << std::endl;

	it = vec.begin();
	for (size_t i = 0; i < 4; i++)
		++it;
	ft::vector<ClassTest>::iterator end = vec.end();
	std::cout << "size : " << vec.size() << "\n";
	vec.erase(it, end);
	std::cout << "size : " << vec.size() << "\n";

	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

	std::cout << YELLOW "Correction de erase() unitaire" RESET << std::endl;

	// //Erase Merdouille
	it = vec.begin();
	for (size_t i = 0; i < 4; i++)
		vec.erase(it);

	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

	std::cout << YELLOW "Correction de clear()" RESET << std::endl;
	vec.clear();
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

/* 	std::cout << GREEN "Vecteur2 insert" RESET << std::endl;
	ft::vector<ClassTest> vec2(2,c);
	it = vec.begin();
	for (size_t i = 0; i < 3; i++)
		++it;
	ft::vector<ClassTest>::iterator end = vec.end();
	ft::vector<ClassTest>::iterator vec2begin = vec2.begin();
	vec2.insert(++vec2begin, it, end);
	for (ft::vector<ClassTest>::iterator it = vec2.begin(), end = vec2.end(); it != end; ++it)
		std::cout << *it << "\n"; */

/*	std::cout << GREEN "Vecteur officiel" RESET << std::endl;

 	std::vector<ClassTest> vec1(2, 8);
	std::cout << vec1[0].getNb() << std::endl;
	std::cout << vec1[1].getNb() << std::endl;
	// vec1.push_back(2);
	std::cout << "vec.max_size() : " << vec1.max_size() << std::endl;
	// std::cout << vec1.size() << std::endl;
	// std::cout << vec1.capacity() << std::endl; */
	std::cout << GREEN "Ended Normaly" RESET << std::endl;
	return 0;
}



/* 	// exception constructor
#include <iostream>       // std::cout
#include <exception>      // std::exception

struct ooops : std::exception {
  const char* what() const noexcept {return "Ooops!\n";}
};

int main () {
  ooops e;
  std::exception* p = &e;
  try {
      throw e;       // throwing copy-constructs: ooops(e)
  } catch (std::exception& ex) {
      std::cout << ex.what();
  }
  try {
      throw *p;      // throwing copy-constructs: std::exception(*p)
  } catch (std::exception& ex) {
      std::cout << ex.what();
  }
  return 0;
}
 */

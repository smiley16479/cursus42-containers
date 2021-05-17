// #include "vector.tpp"
#include "vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <vector>
#include <iostream>

int main()
{
	ClassTest c(6);

	std::cout << GREEN "Correction des Vecteurs" RESET << std::endl;

	ft::vector<ClassTest> vec(2, c);
	std::cout << vec.capacity() << std::endl;
	// vec.resize(18);

	// std::cout << YELLOW "Correction de vec1=vec2" RESET << std::endl;
	// ft::vector<ClassTest> vect(2, 8); // not implemented yet
	// vec = vect;

	std::cout << YELLOW "Correction Iterator" RESET << std::endl;

	// for (auto i : vec)
	// 	std::cout << i << "\n";

	// for (ft::vector<ClassTest>::Iterator it = vec.begin(), end = vec.end(); it != end; ++it)
	// 	std::cout << *it << "\n";

	// std::cout << YELLOW "Correction de resize()" RESET << std::endl;
	// vec.resize(1);
	// std::cout << YELLOW "Correction de operator[]" RESET << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i].getNb() << std::endl;

	std::cout << YELLOW "Correction de at" RESET << std::endl;
	try
	{
		vec.at(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << YELLOW "Correction de max_size()" RESET << std::endl;
	std::cout << "vec.max_size() : " << vec.max_size() << std::endl;
	// vec.getNb();
	std::cout << YELLOW "Correction de push_back()" RESET << std::endl;
	ClassTest b(5);
	vec.push_back(b);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

	// std::cout << YELLOW "Correction de pop()" RESET << std::endl;
	// vec.pop_back();
	// for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
	// 	std::cout << *it << "\n";

	std::cout << YELLOW "Correction de insert()" RESET << std::endl;
	ft::vector<ClassTest>::iterator it = vec.begin();
	++it;
	std::cout << it << std::endl;
	vec.insert(++it, b);
	for (ft::vector<ClassTest>::iterator it = vec.begin(), end = vec.end(); it != end; ++it)
		std::cout << *it << "\n";

/*	std::cout << GREEN "Vecteur officiel" RESET << std::endl;

 	std::vector<ClassTest> vec1(2, 8);
	std::cout << vec1[0].getNb() << std::endl;
	std::cout << vec1[1].getNb() << std::endl;
	// vec1.push_back(2);
	std::cout << "vec.max_size() : " << vec1.max_size() << std::endl;
	// std::cout << vec1.size() << std::endl;
	// std::cout << vec1.capacity() << std::endl; */
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

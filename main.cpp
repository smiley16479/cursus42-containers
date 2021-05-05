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

int main(/* int argc, char const *argv[] */)
{
	ClassTest c(6);
	std::cout << GREEN "Correction des Vecteurs" RESET << std::endl;

	ft::vector<ClassTest> vec(2, c);
	std::cout << vec.capacity() << std::endl;
	// vec.resize(18);

	// ft::vector<ClassTest> vect(2, 8);
	// vec = vect;
	std::cout << vec[0].getNb() << std::endl;
	std::cout << vec[1].getNb() << std::endl;
	std::cout << "vec.max_size() : " << vec.max_size() << std::endl;
	// vec.getNb();

	std::cout << GREEN "Vecteur officiel" RESET << std::endl;

	std::vector<ClassTest> vec1(2, 8);
	std::cout << vec1[0].getNb() << std::endl;
	std::cout << vec1[1].getNb() << std::endl;
	// vec1.push_back(2);
	std::cout << "vec.max_size() : " << vec1.max_size() << std::endl;
	// std::cout << vec1.size() << std::endl;
	// std::cout << vec1.capacity() << std::endl;
	return 0;
}


#include "vector.hpp"
#include "stack.hpp"
#include <stack>
// #include "./test/friend_directory/solalDunckel/includes/vector.hpp"
// #include "./test/friend_directory/solalDunckel/includes/vector_iterator.hpp"
// #include "./test/friend_directory/ska42/Vector.hpp"
// #include "./test/friend_directory/ska42/IteratorVector.hpp"
#include "ClassTest.hpp"
#include "colors.h"
#include <vector>
#include <iostream>
#include <fstream>

void stack_test(/* std::ofstream file_out */)
{
	std::cout << GREEN "Correction des Stack" RESET << std::endl;
#ifdef binary_out
		std::ofstream file_out;
#ifdef off
		file_out.open("stackTest_off.txt");
		namespace ft = std;
#else
		file_out.open("stackTest_perso.txt");
#endif
#endif
// explicit stack (const container_type& ctnr = container_type());
// bool empty() const; // Test whether container is empty
// size_type size() const; // Return size
// (1) value_type& top();
// (2) const value_type& top() const;  // Access next element
// void push (const value_type& val); // Insert element
// void pop(); // Remove top element
	ClassTest b(5);
	ClassTest c(6);
	ft::stack<ClassTest> stack1;
	ft::stack<int, std::deque<int> > stack2;
	std::cout << YELLOW "stack constructor ✅" RESET << std::endl;

#ifdef binary_out
	file_out << stack1.empty() << std::endl;
#else
	std::cout << stack1.empty();
#endif
	std::cout << YELLOW "stack.empty ✅" RESET << std::endl;
	stack1.push(b);

#ifdef binary_out
	file_out << stack1.size() << std::endl;
#else
	std::cout << YELLOW "Correction de Stack_size() ✅" RESET << std::endl;
	std::cout << "Stack_size()" << stack1.size() << std::endl;
#endif

#ifdef binary_out
	file_out << stack1.top() << std::endl;
#else
	std::cout << "Stack_top()" << stack1.top() << std::endl;
#endif
	std::cout << YELLOW "Correction de Stack_top() ✅" RESET << std::endl;

	stack1.push(b);
	stack1.push(c);
#ifdef binary_out
	file_out << stack1.size() << std::endl;
#else
	std::cout << "Stack_size()" << stack1.size() << std::endl;
#endif
	std::cout << YELLOW "Correction de Stack_size() ✅" RESET << std::endl;

#ifdef binary_out
	file_out << stack1.top() << std::endl;
#else
	std::cout << "Stack_top()" << stack1.top() << std::endl;
#endif
	std::cout << YELLOW "Correction de Stack_top() ✅" RESET << std::endl;

#ifdef binary_out
	file_out << stack1.size() << std::endl;
#else
	std::cout << "Stack_size()" << stack1.size() << std::endl;
#endif
	std::cout << YELLOW "Correction de Stack_size() ✅" RESET << std::endl;

	for (size_t i = 0; i < 1000; ++i)
		stack2.push(i);

	for (size_t i = 0; i < 1000; ++i) {
#ifdef binary_out
	file_out << stack2.top() << std::endl;
#else
	std::cout << "Stack_top(1000*)" << stack2.top() << std::endl;
#endif
	stack2.pop();
	}
	std::cout << YELLOW "Correction de Stack_top() * 1000 ✅" RESET<< std::endl;
	return ;
}

#ifdef test
int main()
{
	stack_test();
	return 0;
}
#endif

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

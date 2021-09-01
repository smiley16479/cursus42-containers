#include <iostream>
#include "../../colors.h"
namespace ft {

template<typename T>
struct test_trait{
	typedef T hey;
};

template<typename T>
struct test_trait<const T>{
	typedef T ho;
};

template<typename T>
struct test : public test_trait<T>{
	typedef T					value_type;

	T value_;

	test() : value_(value_type()) {std::cout << "it_constructor\n";};
	test(test<T>& i) : value_(i.getT()) {std::cout << "it_parametric_constructor\n";};
	test(T pos) : value_(pos) {std::cout << "it_parametric_constructor\n";};
	~test(){std::cout << "it_destructor\n";};
	T& getT(){return value_;}
};

template<typename T>
class test<const T> : public test_trait<const T> {
	typedef const T Type;
public:
	Type value_;
	test() : value_(NULL) {std::cout << RED"const_it_constructor\n" RESET;};
	test(T pos) : value_(pos) {std::cout << RED"const_it_constructor\n" RESET;};
	test(ft::test<T> pos) : value_(pos.value_) {std::cout << RED"const_it_parametric_constructor\n" RESET;};
	~test(){std::cout << RED"const_it_destructor\n" RESET;};
	Type& getT() {return value_;}
};
}

#include <vector>
void vector_test();
void to_erase();

int main(int argc, char const *argv[])
{
	to_erase();
	return 0;
}

void to_erase()
{

	std::vector<int> v;
	v.push_back(1);
	std::vector<int>::const_iterator it = v.begin();
	// *it = 2;
	std::cout << "Officiel_it : " << *it << std::endl;

	ft::test<int> normalTest(2);
	ft::test<int>::hey HEY;
	ft::test<const int>::ho HO;
	// ft::test<const int> constTest(normalTest); // <- on ne peut tjrs pas initialiser avec un iterator normal
	ft::test<const int> constTest(2);
	// constTest.value_ = 2;

	normalTest.getT() = 3;
	// constTest.getT() = 3;
	std::cout << normalTest.getT() << std::endl;
	std::cout << constTest.getT() << std::endl;

}

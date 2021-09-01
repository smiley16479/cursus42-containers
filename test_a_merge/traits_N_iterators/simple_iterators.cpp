#include <cstddef>
#include <iostream>
#include "../../colors.h"

namespace ft {

template<typename T>
class iterator {

	T* pos_;
	// friend class const_iterator<T>;

public:
	typedef T				value_type;
	// typedef iterator<const T>		const_iterator;

	iterator() : pos_(NULL) {std::cout << "it_constructor\n";};
	iterator(T* pos) : pos_(pos) {std::cout << "it_parametric_constructor\n";};
	~iterator(){std::cout << "it_destructor\n";};
	T* getT() {return pos_;};
	iterator operator++(){std::cout << "test\n" << std::endl; return ++pos_;};
	iterator operator--(){return --pos_;};
	T& operator*(){return *pos_;};
	bool operator!=(iterator& rhs){ return (this->pos_ != rhs.pos_) ? true : false;};
};

	template<typename T>
	std::ostream& operator<<(std::ostream& s , ft::iterator<T>& it) { s << *it; return s;}

template<typename T>
struct const_iterator{

	typedef T					value_type;

	T* pos_;
	const_iterator() : pos_(NULL) {std::cout << "1st_const_it_constructor\n";};
	const_iterator(ft::iterator<T> pos) : pos_(pos.getT()) {std::cout << "1st_const_it_parametric_constructor_1\n";};
	// const_iterator(ft::iterator<const T> pos) : pos_(pos.getT()) {std::cout << "1st_const_it_parametric_constructor_2\n";};
	const_iterator(T* pos) : pos_(pos) {std::cout << "1st_const_it_parametric_constructor\n";};
	~const_iterator(){std::cout << "1st_const_it_destructor\n";};
	const_iterator operator++(){std::cout << "1st_const_test\n" << std::endl; return ++pos_;};
	const_iterator operator--(){return --pos_;};
	const T& operator*(){return *pos_;};
	const T* operator->(){return pos_;};
	bool operator!=(const_iterator& rhs){ return (this->pos_ != rhs.pos_) ? true : false;};
};

template<typename T>
class const_iterator<const T> /* : const_iterator<T> */{

	T* pos_;

public:
	typedef const T					value_type;
	const_iterator() : pos_(NULL) {std::cout << "const_it_constructor\n";};
	const_iterator(ft::iterator<T> pos) : pos_(pos.getT()) {std::cout << "const_it_parametric_constructor_1\n";};
	const_iterator(ft::iterator<const T> pos) : pos_(pos.getT()) {std::cout << "const_it_parametric_constructor_2\n";};
	const_iterator(T* pos) : pos_(pos) {std::cout << "const_it_parametric_constructor\n";};
	~const_iterator(){std::cout << "const_it_destructor\n";};
	const_iterator operator++(){std::cout << "const_test\n" << std::endl; return ++pos_;};
	const_iterator operator--(){return --pos_;};
	const T& operator*(){return *pos_;};
	const T* operator->(){return pos_;};
	bool operator!=(const_iterator& rhs){ return (this->pos_ != rhs.pos_) ? true : false;};
};

/* 
template<typename T>
class iterator<const T> {

	T* pos_;

public:
	typedef T					value_type;
	typedef iterator<const T>	const_iterator;

	iterator() : pos_(NULL) {std::cout << "const_it_constructor\n";};
	iterator(T* pos) : pos_(pos) {std::cout << "const_it_parametric_constructor\n";};
	~iterator(){std::cout << "const_it_destructor\n";};
	iterator operator++(){std::cout << "const_test\n" << std::endl; return ++pos_;};
	iterator operator--(){return --pos_;};
	T& operator*(){return *pos_;};
	bool operator!=(iterator& rhs){ return (this->pos_ != rhs.pos_) ? true : false;};
};
*/

template<typename T>
class vector {

T* array_;
size_t size_;

public:
	typedef ft::iterator<T>				iterator;
	typedef ft::const_iterator<T> 		const_iterator;

vector(): array_(NULL), size_(0) {};
~vector() {	delete [] array_;};

void fullfil(size_t n, T val) {	array_ = new T[n]; for (size_t i = 0; i < n; ++i) array_[i] = val; size_ = n;};
void display() { for (size_t i = 0; i < size_; ++i) std::cout << array_[i] << std::endl;};
iterator begin(){ return iterator(array_);};
iterator end(){ return iterator(&(array_[size_]));};
};
}

#include <vector>
#include <iterator>
void vector_test();

int main(int argc, char const *argv[])
{
	vector_test();
	return 0;
}

void vector_test()
{
	std::cout << YELLOW "Correction des Iterateurs(	OFFICIEL )" RESET << std::endl;

	std::vector<const int> off(5,10);

	std::vector<const int>::iterator off_itest = off.begin();
	std::vector<const int>::const_iterator off_const_test =  off.begin(); //off_itest;
	off_const_test = off_itest;
	*off_const_test = 2;

	// std::vector<int>::iterator off_it = off.begin();
	// std::vector<int>::iterator off_it_end = off.end();
	// for (; off_it != off_it_end; ++off_it)	
	// 	std::cout << *off_it << std::endl;

	std::cout << YELLOW "Correction des Iterateurs( PERSO )" RESET << std::endl;

	ft::vector<const int> a;
	a.fullfil(5,10);
	a.display();

	ft::vector<const int>::iterator itest = a.begin();
	ft::vector<const int>::const_iterator const_test =  a.begin(); //itest;
	const_test = itest;
	*const_test = 2;
	
	ft::iterator<const int> itest = a.begin();
	ft::const_iterator<const int> const_test1 =  a.begin(); //itest;
	*const_test1 = 2;

	// ft::iterator</* const */ int> it = a.begin();
	// ft::iterator</* const */ int> it_end = a.end();
	// for (; it != it_end; ++it)	
	// 	std::cout << *it << std::endl;



	return;
}


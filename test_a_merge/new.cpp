#include <iostream>

template <typename T>
class foo {

	private :
	T _attr;
	T *_ptr;
	
	public:
	typedef T value_type;

	foo (T val) : _attr(val) { return; }
	~foo () {};
	void assign () { 
	_ptr = (T*) ::operator new (sizeof(T));
	new (_ptr) T(_attr);}
	void test_typedef () { foo::value_type i = 3;}
	T& get_attr () const {return _attr;}
	T& get_ptr () const {return *_ptr;}


};
template <typename T>
std::ostream& operator<<(std::ostream &o, typename ::foo<T> const & i) { o << (T)i.get_ptr(); return o;}

int main()
{
	int a = 1;
	foo<int> test(a);

	test.test_typedef();
	foo<int>::value_type *ptr;
	foo<int>::value_type is_int=5;

	std::cout << is_int << std::endl;

	test.assign();
	// std::cout << test.get_ptr() << std::endl;
	std::cout << test << std::endl;
	return 0;
}

#include <iostream>

int& foo(int *&refPtr)
{
	*refPtr = 3;
	return (*refPtr);
}

int& bar(int *refPtr)
{
	// *refPtr = 4;
	return (*refPtr);
}

int main()
{
	int a = 0;
	int *ptr = &a;
	int& ref = *ptr;
	*ptr = foo(ptr);
	*ptr = bar(ptr);
	std::cout << *ptr << "\n";
	return 0;
}

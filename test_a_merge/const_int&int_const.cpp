#include<iostream>
/* DIFFERENCE ENTRE const int et int const idem avec les pointer */
// Yes, they are the same. The rule in C++ is essentially that const applies to the type to its left.
// However, there's an exception that if you put it on the extreme left of the declaration, 
// it applies to the first part of the type.
// For example in int const * you have a pointer to a constant integer. 
// In int * const you have a constant pointer to an integer. You can extrapolate this to 
// pointer to pointers, and the English may get confusing but the principle is the same.

int main(void)
{
	const int a = 1;//  ARE THE SAME
	int const b = 2;//  ARE THE SAME
	int c = 3;

	const int * a_ptr = &a; /* NOT THE SAME */
	int * const b_ptr = &c;  /* NOT THE SAME */// but int *const b_ptr = &a (ou &b); DOESN'T WORK
	std::cout << "a : " << a << ", b : " << b << std::endl;
	// a = 1; 
	// b = 4;
	
	std::cout << "const int * a_ptr : " << a_ptr << ", const int * a_ptr (value): " << *a_ptr <<  std::endl;
	a_ptr = &b;
	std::cout << "const int * a_ptr : " << a_ptr << ", const int * a_ptr (value): " << *a_ptr << std::endl;
}

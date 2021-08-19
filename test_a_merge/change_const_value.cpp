#include <iostream>

int main(void)
{// POUR CHANGER UNE VALEUR DECLARÉE EN CONST
	const int a = 1;
	void * i = (void*)&a;

	std::cout << *(int*)i << std::endl;
	*(int*)i = 2;
	std::cout << *(int*)i << std::endl;
	return 0;
}

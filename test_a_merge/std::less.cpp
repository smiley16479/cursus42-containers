#include <string>
#include <iostream>


template <typename A, typename B, 
          typename U = std::less<char *> >
  
// Function to check if a < b or not
bool f(A a, B b, U u = U())
{
    return u(a, b);
}


int main(/* int argc, char const *argv[] */)
{
	char * str1 = "allo"; //1; (h =>104)
	char * str2 = "alloa"; //2; (a =>97)
	printf("str1_ptr : %p, str2_ptr : %p\n", str1, str2);
	std::cout << std::less<char *>()(str1,str2) << '\n';
	// std::less<char *>(str1, str2);

	return 0;
}

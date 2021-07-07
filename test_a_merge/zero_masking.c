#include <stdio.h>
int main(int argc, char const *argv[])
{
	unsigned int a = 42;
	a ^= a;

	printf("a : %d\n", a);
	return 0;
}

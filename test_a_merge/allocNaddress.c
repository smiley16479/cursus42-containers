#include <stdlib.h>
#include <stdio.h>

int main(/* int argc, char const *argv[] */)
{
	int *i = malloc(4);
	int *j = malloc(4);
	// *i = 2147483647;
	printf("i : %p, j : %p\n", i, j);
	return 0;
}

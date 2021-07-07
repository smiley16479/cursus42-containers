#include <stdio.h>
int main(/* int argc, char const *argv[] */)
{
	int i , j , k;
	i = j = k = 0;
	for (int l = 0, m = 1; k < 10; ++i , ++j, ++k)
		printf ("i ; %d, j ; %d, k ; %d, l ; %d, m ; %d\n", i, j , k , l, m);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
/* 	int *int_ptr = malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		int_ptr[i] = i + 10;
	}
	printf("via [] : %p, via ptr %ld\n", &int_ptr[9] ,(char*)&(int_ptr[9]) - (char*)(int_ptr)); */
	
	char *ptr = "adrien";
	char *ptr2 = ptr + 2;
	ptr += ((size_t)ptr2 - (size_t)ptr);
	write(1, ptr, 1);
	return 0;
}

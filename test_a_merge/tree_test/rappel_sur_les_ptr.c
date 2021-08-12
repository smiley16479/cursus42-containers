// ESSAI de changer le ptr d'une structure en la passant par ptr :
// impossible obliger de mettre dbl ptr
#include <stdio.h>
#include <stdlib.h>

typedef struct test_strcut {
	int *a;
}test;

void changePtr(int **ptr, int* other_ptr)
{
	/* return */ (*ptr) = other_ptr;
}

void changeStrucPtr(test *struct_ptr, int* other_ptr)
{
	/* return */ struct_ptr->a = other_ptr;
}

void changeStrucPtr2(test **struct_ptr, test* other_ptr)
{
	/* return */ *struct_ptr = other_ptr;
}

int main(int argc, char const *argv[])
{
	test *struc1 = malloc(sizeof(test));
	test *struc2 = malloc(sizeof(test));
	int a = 10;
	int *b = &a;
	int c = 20;
	struc1->a = &a;
	struc2->a = &a;
	/* b =  */changePtr(&b, &c);
	changeStrucPtr(struc1, &c);
	// changeStrucPtr(struc1, &c);
	changeStrucPtr2(&struc2, struc1);
	printf("b : ptr::%p value::%d\n", b, *b);
	printf("struc1 : ptr::%p value::%d\n", struc1->a, *struc1->a);
	printf("struc2 : ptr::%p value::%d\n", struc2->a, *struc2->a);

	free(struc1);
	free(struc2);
	return 0;
}

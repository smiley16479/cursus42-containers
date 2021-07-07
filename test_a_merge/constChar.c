#include <stdio.h>

int main()
{
	const char * str;
	char str1[10] = "hey";
	//str1 = "hello";
	str = str1;//"hello c moi";
	char * str_mut = (char*)str;
	printf("ptr : %p, ptr_mut : %p\nstr : %s\n",str, str_mut, str);
	//sprintf(str, "%s\n", "oui nouvelle string");
	printf("%s\n",str);
	return 0;
}

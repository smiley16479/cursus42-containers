// #define test

// #include "map.hpp"
// #include "vector.hpp"
// #include "stack.hpp"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

// If you include don't name it on the compilation cmd
#include "./mes_test/vector_test.cpp"
#include "./mes_test/map_test.cpp"
#include "./mes_test/stack_test.cpp"
	
void	vector_test();
void	stack_test();
int		map_test();


void time_counter(time_t begin, const char *str){
		time_t end = time( NULL);
		unsigned long secondes = (unsigned long) difftime( end, begin );
		printf( "%s finished in %ld sec\n", str, secondes ); 
}

int main(int ac, char const *av[])
{
	time_t begin = time( NULL );
	if (ac == 1){
		begin = time( NULL );
		vector_test();
		time_counter(begin, "vector test");
		begin = time( NULL );
		stack_test();
		time_counter(begin, "stack test");
		begin = time( NULL );
		map_test();
		time_counter(begin, "map test");
	}
	else if (ac > 1 && ac < 5) 
		while (--ac) {
			if (!strcmp(av[ac], "vector"))
				vector_test();
			if (!strcmp(av[ac], "stack"))
				stack_test();
			if (!strcmp(av[ac], "map"))
				map_test();
	}
	else
		std::cout << "seems you're good to check the source code to get how to use it :p" << std::endl;
	return 0;
}


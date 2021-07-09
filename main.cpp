#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <string.h>
#include "test_a_merge/mes_test/map_test.cpp"
#include "test_a_merge/mes_test/vector_test.cpp"
#include "test_a_merge/mes_test/stack_test.cpp"

int main(int ac, char const *av[])
{
	if (ac == 1)
	{
		map_test();
		vector_test();
		stack_test();
		return 0;
	}
	if (ac > 1 && ac < 5) {
		while (ac--)
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


#include <iostream>
#include <string>
#include <deque>
#include <time.h>

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map copy.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#define _MES_TESTS_
/* 
	#define _SOLAL_ 1
 	#include "friend_directory/solalDunckel/includes/map.hpp"
	#include "friend_directory/solalDunckel/includes/stack.hpp"
	#include "friend_directory/solalDunckel/includes/vector.hpp" /* */
#endif

#include <stdlib.h>

#define MAX_RAM  /* 536870912 // */ 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	#ifdef _MES_TESTS_
		std::cout << "test de mes conteneurs, ";
	#elif _SOLAL_
		std::cout << "test des conteneurs de SOLAL, ";
	#else
		std::cout << "test des conteneurs officiels, ";
	#endif
	std::cout << "COUNT : " << COUNT << std::endl;

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ft::map<int, int> map_int;
	time_t begin = time( NULL ), end = time( NULL );
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
std::cout << "1\n";
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	end = time( NULL );
	unsigned long secondes_vector = (unsigned long) difftime( end, begin );
	std::cout << "after_vector : " << secondes_vector/60 << ":" << secondes_vector%60 << "min" << std::endl;
/*
	begin = time( NULL );
	int array[COUNT];
	for (int i = 0; i < COUNT; ++i)
	{
		int int1 = rand(), int2 = rand();
		array[i] = int1;
		// std::cout << "int1 : " << int1 << " / int2 : " << int2 << std::endl;
		map_int.insert(ft::make_pair(int1, int2));
	}
	// std::cout << std::endl;
	// for (int i = 0; i < COUNT; ++i)
	// 	std::cout << "int1 : " << array[i] << " / int2 : " <<  map_int[array[i]] << std::endl;

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		// std::cout << " map_int[" << access << "] : " << map_int[access] << std::endl;
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	end = time( NULL );
	unsigned long secondes_map = (unsigned long) difftime( end, begin );
	std::cout << "after_map : " << secondes_map/60 << ":" << secondes_map%60 << "min" << std::endl;

	begin = time( NULL );

	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	end = time( NULL );
	unsigned long secondes_stack = (unsigned long) difftime( end, begin );
	std::cout << "after_stack : " << secondes_stack/60 << ":" << secondes_stack%60 << "min" << std::endl;
*/
	return (0);
}

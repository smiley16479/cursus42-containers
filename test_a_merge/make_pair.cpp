#include <utility>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	std::pair<int, int> one;
	one = std::make_pair (10.5 , 'A'); // fait la conversion vers <int,int>

	cout << one.first << one.second;
	return 0;
}

// Différence pour le mot clef public protected private devant la class héritée
// https://www.programiz.com/cpp-programming/public-protected-private-inheritance#include <iostream>
#include <iostream>

using namespace std;

class A
{
	private:
		int _a_data2;
	protected:
		int _a_data;
	public:
	A(): _a_data(1), _a_data2(11) {};
	~A() {};
	void print_A(){cout << "A_data : " <<  _a_data << endl;};
};

class B : protected A
{
public:
	int _b_data;

	B(): _b_data(2) {};
	~B() {};
	void print_B(){cout << "B_data : " << _b_data << _a_data /* << _a_data2  */<< endl;};
};

int main(int argc, char const *argv[])
{
	B b;
	A a;
	// cout << "b._a_data " << b._a_data << ", b._b_data " << b._b_data << endl;

	b.print_B();
	return 0;
}

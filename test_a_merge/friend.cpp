// https://simplesnippets.tech/friend-function-friend-class-in-cpp/
// https://docs.microsoft.com/fr-fr/cpp/cpp/friend-cpp?view=msvc-160
#include <iostream>

using namespace std;

/* class A
{
	// protected:
public:
		int _a_data;
	A(): _a_data(1) {};
	~A() {};
	void print_A(){cout << "A\n";};
};

class B
{
friend class A;
public:
	int _b_data;

	B(): _b_data(2) {};
	~B() {};
	void print_B(){cout << "B\n";};
};

int main(int argc, char const *argv[])
{
	B b;
	A a;
	// cout << "b._a_data " << b._a_data << ", b._b_data " << b._b_data << endl;
	cout << "a._a_data " << a._a_data << ", a._b_data " << a._b_data << endl;
	b.
	return 0;
}
 */

class MyClass
{
	// Declare a friend class
	friend class SecondClass;

	public:
		MyClass() : Secret(0){}
		void printMember()
		{
			cout << Secret << endl;
		}
	private:
		int Secret;
};

class SecondClass
{
	public:
		void change( MyClass& yourclass, int x )
		{
			yourclass.Secret = x;
		}
};

int main()
{
	MyClass my_class;
	SecondClass sec_class;
	my_class.printMember();
	sec_class.change( my_class, 5 );
	my_class.printMember();
	
	return 0;
}
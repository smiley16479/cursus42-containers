#ifndef TEST_CLASS_H
#define TEST_CLASS_H
#include <iostream>

class ClassTest
{
public:
	ClassTest( void );
	ClassTest( int const n );
	ClassTest( ClassTest const & src );
	~ClassTest( void );

	ClassTest&   operator=( ClassTest const & rhs );

	int getNb( void ) const;

private:

	int _nb;
	int _nb1;

};

std::ostream &    operator<<( std::ostream & o, ClassTest const & i );

#endif


ClassTest::ClassTest( void ) : _nb( 0 )
{
	std::cout << "ClassTest Default Constructor called" << std::endl;
	return ;
}

ClassTest::ClassTest( int const n ) : _nb( n )
{
	std::cout << "ClassTest Parametric Constructor called" << std::endl;
	return ;
}

ClassTest::ClassTest( ClassTest const & src )
{
	std::cout << "ClassTest Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

ClassTest::~ClassTest()
{
	std::cout << "ClassTest Destructor called" << std::endl;
	return ;
}

int ClassTest::getNb( void ) const
{
	return this->_nb;
}

ClassTest & ClassTest::operator=( ClassTest const & rhs )
{
	std::cout << "ClassTest Assignment operator called" << std::endl;
	if (this != &rhs )
		_nb = rhs._nb;
	return *this;
}

std::ostream & operator<<( std::ostream & o, ClassTest const & i )
{
	o << "The value of _nb is : " << i.getNb();
	return o;
}
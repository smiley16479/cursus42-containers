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
	bool   operator==( ClassTest const & rhs );
	bool   operator<( ClassTest const & rhs );

	int getNb( void ) const;
	int getPtrNb( void ) const;

private:

	int _nb;
	int *_ptr;

};

std::ostream &    operator<<( std::ostream & o, ClassTest const & i );

#endif


ClassTest::ClassTest( void ) : _nb( 0 ), _ptr(new int(0))
{
	std::cout << "ClassTest Default Constructor called" << std::endl;
	return ;
}

ClassTest::ClassTest( int const n ) : _nb( n ), _ptr(new int(n))
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
	delete _ptr;
	_ptr = NULL;
	return ;
}

int ClassTest::getNb( void ) const
{
	return this->_nb;
}

int ClassTest::getPtrNb( void ) const
{
	return *this->_ptr;
}

ClassTest & ClassTest::operator=( ClassTest const & rhs )
{
	std::cout << "ClassTest Assignment operator called" << std::endl;
	if (this != &rhs ) {
		// std::cout << "rhs : " << rhs << "\n";
		_nb = rhs._nb;
		// if (_ptr != NULL)
		// 	delete _ptr;
		_ptr = new int(*(rhs._ptr));
		// std::cout << "this : " << *this << "\n";
	}
	return *this;
}

bool ClassTest::operator==( ClassTest const & rhs )
{
	std::cout << "ClassTest equivalent operator called" << std::endl;
	if (this != &rhs && _nb == rhs._nb && *_ptr == *rhs._ptr)
		return true;
	return false;
}

bool ClassTest::operator<( ClassTest const & rhs )
{
	std::cout << "ClassTest Assignment operator called" << std::endl;
	if (this != &rhs && _nb < rhs._nb && *_ptr < *rhs._ptr) 
		return true;
	return false;
}

std::ostream & operator<<( std::ostream & o, ClassTest const & i )
{
	o << "_nb is : " << i.getNb()/*  << ", _ptr(value) is : " << i.getPtrNb() */;
	return o;
}
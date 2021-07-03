#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <memory>
#include <limits>
#include <stddef.h>
// #include <stack>
// #include </usr/include/c++/6/bits/stl_iterator_base_types.h>
// #include </usr/include/c++/6/bits/stl_algobase.h>


#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#include "colors.h"
#endif


namespace ft {

	template < class _T = int, class Container = ft::vector<_T> >
	class stack
	{


	public :
		// explicit stack (const container_type& ctnr = container_type());
		// bool empty() const; // Test whether container is empty
		// size_type size() const; // Return size
		// (1) value_type& top();
		// (2) const value_type& top() const;  // Access next element
		// void push (const value_type& val); // Insert element
		// void pop(); // Remove top element

	typedef Container	container_type;
	typedef _T 			value_type;

	// Default Constructor
	explicit stack(const container_type& ctnr = container_type())
	// : _c(ctnr) // _size(0), _capacity(vAddedMem), _allocator(const_cast<allocator_type&>(alloc))
	{
		_c = ctnr;
		#ifdef _DEBUG_
		std::cout << "stack Default Constructor called" << std::endl;
		#endif
	}

	bool empty() const {
		if (_c.empty())
			return (true);
		return (false);
	}

	size_type size() const {
		return ( _c.size() );
	}
	
	value_type& top() {
		return ( _c[_c.size() - 1] );
	}

	value_type& top() const {
		return ( _c[_c.size() - 1] );
	}

	void push (const value_type& val) {
		_c.push_back(val);
	}

	void pop() {
		_c.pop_back();
	}

	protected :
	container_type _c;
	};
// (1)
template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c == rhs._c );
  }
// (2)
template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c != rhs._c );
  }
// (3)
template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c < rhs._c );
  }
// (4)
template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c <= rhs._c );
  }
// (5)
template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c > rhs._c );
  }
// (6)
template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	  return ( lhs._c >= rhs._c );
  }

}

#endif
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <limits>
#include <stddef.h>
// #include <vector>
// #include </usr/include/c++/6/bits/stl_iterator_base_types.h>
// #include </usr/include/c++/6/bits/stl_algobase.h>

#include "vector_utils.hpp"
#define vAddedMem 16 // better when power of 2

// #define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#include "colors.h"
#endif

namespace ft {

	template < class _T = int, class _Alloc = std::allocator<_T> > 
	class vector
	{
	private:

	_T *_tab;
	unsigned int _size;
	unsigned int _capacity; // real_size
	unsigned int _Zindx; // Zero index où le vector commence pour améliorer l'insertion (par défault au 1/4 du define vAddedMem)
	_Alloc& _allocator;

	public:

	typedef _Alloc			  allocator_type;		//	Type d'allocateur par default celui de la STD
	typedef _T				  value_type;			//
	typedef	_T*				  pointer;				//	Pointer to element
	typedef	_T&				  reference;			//	Reference to element
	typedef	const _T*		  const_pointer;		//	Pointer to constant element
	typedef	const _T&		  const_reference;		//	Reference to constant element
	typedef size_t			  size_type;			//	Quantities of elements
	typedef	ptrdiff_t		  difference_type;		//	Difference between two pointers
		
// Iterator séparé de vector.hpp et placé ds vector_utils.hpp
	typedef ft::iterator<_T>  iterator;
	typedef iterator	  	  reverse_iterator;
	typedef const iterator	  const_iterator;
	typedef const_iterator	  const_reverse_iterator;

	iterator begin() { return iterator(&_tab[0]); }
	const_iterator begin() const { return iterator(&_tab[0]); }
	iterator end()   { return iterator(&_tab[_size]); }
	const_iterator end() const { return iterator(&_tab[_size]); }
	reverse_iterator rbegin() { return iterator(&_tab[_size]); }
	const_reverse_iterator rbegin() const { return iterator(&_tab[_size]); }
	reverse_iterator rend() { return iterator(&_tab[0]); }
	const_reverse_iterator rend() const { return iterator(&_tab[0]); }

/* List Des 
		// typedef value_type							iterator; // a random access iterator to value_type	convertible to const_iterator
		// typedef const value_type					const_iterator; //	a random access iterator to const value_type	
		// typedef reverse_iterator<iterator>			reverse_iterator;
		// typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		// typedef std::reverse_iterator<iterator>		  reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

//Implemented method and // //NON implemented method
	//  CONSTRUCTORS
		// explicit vector (const allocator_type& alloc = allocator_type()); //default (1)	
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill (2)
		// // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range (3) 🔥
		// vector (const vector& x); // copy (4)
		// vector& operator=(const vector& x) throw ()
		// ~vector();
		
	// CAPACITY
		// size_type size(void) const
		// size_type	max_size(void) const
		// void		resize(size_type n, _T val )
		// size_type capacity() const; //Return size of allocated storage capacity
		// bool empty() const; //Test whether vector is empty
		// void reserve (size_type n); // Request a change in capacity.Requests that the vector capacity be at least enough to contain n elements.

	// ELEMENT ACCESS
		// reference	operator[] (size_type n);
		// const_reference operator[] (size_type n) const;
		// reference at (size_type n);
		// const_reference at (size_type n) const;
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;

	// MODIFIERS
		// // template <class InputIterator>  void assign (InputIterator first, InputIterator last); //range (1) 🔥
		// // void assign (size_type n, const value_type& val); //fill (2) 🔥
		// void push_back (const value_type& val);
		// void pop_back();
		// iterator insert (iterator position, const value_type& val); // single element (1)	
    	// void insert (iterator position, size_type n, const value_type& val); // fill (2)
		// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); //range (3)
		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);
		// void swap (vector& x);
		// void clear();

	// ALLOCATOR
		// allocator_type get_allocator() const; // Returns a copy of the allocator object associated with the vector.

	// NON-MEMBER FUNCTION OVERLOADS
		// std::relational operators (vector)
		// (1)	template <class T, class Alloc>
		//   bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		// (2)	template <class T, class Alloc>
		//   bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		// (3)	template <class T, class Alloc>
		//   bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		// (4)	template <class T, class Alloc>
		//   bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		// (5)	template <class T, class Alloc>
		//   bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		// (6)	template <class T, class Alloc>
		//   bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc> void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	// TEMPLATE SPECIALIZATIONS
		// template < class T, class Alloc = allocator<T> > class vector; // generic template
		// template <class Alloc> class vector<bool,Alloc>;               // bool specialization
 */

	// Default Constructor
	explicit vector(const allocator_type& alloc = allocator_type())
	: _size(0), _capacity(vAddedMem), _allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Default Constructor called" << std::endl;
		#endif
		_tab = const_cast<allocator_type&>(alloc).allocate(_capacity);
	}

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	: _size(n),
	_capacity(_size * 1.5 >= vAddedMem ? _size * 1.5 : vAddedMem),
	_allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Size Constructor called" << std::endl;
		#endif
		_tab = _allocator.allocate(_capacity);
		for (size_t i = 0; i < _size; i++)
			_tab[i] = val; // new(&_tab[i]) _T(val); appelle le constructeur voir exemple 3 https://www.cplusplus.com/reference/new/operator%20new/
	} 

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	: _size(last - first),
	_capacity(_size * 1.5 >= vAddedMem ? _size * 1.5 : vAddedMem),
	_allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Size Constructor called (Not implemented yet)" << std::endl;
		#endif
	}

	vector (const vector& x) 
	: _size(0), _capacity(vAddedMem), _allocator(const_cast<allocator_type&>(x._allocator))
	{*this = x;}

	vector& operator=(const vector& x)
	{
		#ifdef _DEBUG_
		std::cout << "vector Assignment operator called" << std::endl;
		#endif
		if ( this != &x ) {
			this->~vector(); // cannot use "delete this;" bcoz new wasn't use eventhought it is used by the std::allocator
 			_size = x._size;
			_capacity = x._capacity;
			_allocator = x._allocator;
			_tab = _allocator.allocate(_capacity);
			for (size_t i = 0; i < x._size; i++)
				new (&_tab[i]) _T(x._tab[i]);
		}
		return *this;
	}

	~vector()
	{
		#ifdef _DEBUG_
		std::cout << "vector Destructor called" << std::endl;
		#endif
		for (size_t i = 0; i < _size; i++)
			_allocator.destroy(&_tab[i]);
		_allocator.deallocate(_tab, _capacity);
	}

	/* Iterators: */

	/* Capacity: */

	size_type	size(void) const {return _size;}

	size_type	max_size(void) const
	{
		// return (std::numeric_limits<size_t>::max()/* /sizeof(value_type) */); // Returns the maximum finite value representable by the numeric type T.
		return _allocator.max_size();
	}

// Resizes the container so that it contains n elements.
// If n is smaller than the current container size, the content is reduced to its first n elements,
// removing those beyond (and destroying them). If n is greater than the current container size,
// the content is expanded by inserting at the end as many elements as needed to reach a size of n.
// If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
// If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
// Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	void		resize(size_type n, value_type val = value_type())
	{
		#ifdef _DEBUG_
			std::cout << "_size : " << _size << ", n : " << n << std::endl;
		#endif
		if (n < _size) {
			for (size_t i = n; i < _size; i++)
				_allocator.destroy(&_tab[i]);
			_size = n;
		}
		else {
			reserve(n);
			for (size_t i = _size; i < n; ++i)
				_allocator.construct(&_tab[i], val);
			_size = n;
		}
	}

	size_type capacity() const { return _capacity;}

	bool empty() const { return (_size ? false : true); }

// Request a change in capacity, Requests that the vector capacity be at least enough to contain n elements.
// If n is greater than the current vector capacity, the function causes the container to reallocate its 
// storage increasing its capacity to n (or greater). In all other cases, the function call does not cause
// a reallocation and the vector capacity is not affected.
// This function has no effect on the vector size and cannot alter its elements.
	void reserve (size_type n)
	{
		size_type maxSize = max_size();
		if ( n > maxSize )
			throw std::length_error ("_M_fill_insert_(reserve)");
		if ( n > _capacity ) {
			#ifdef _DEBUG_
			std::cout << "_size : " << _size << " n : " << n << std::endl;
			#endif
			size_t capacity = ( n + vAddedMem <= maxSize ) ? n + vAddedMem : n;
			_T* tmpTab_ = _allocator.allocate(capacity);
			for (size_t i = 0; i < _size; ++i)
				tmpTab_[i] = _tab[i];
			// ft::vector<_T, _Alloc >::~vector(); // cannot use "delete this;" bcoz new wasn't use eventhought it is used by the std::allocator
			this->~vector();
			_capacity = capacity;
			_tab = tmpTab_;
		}
		return;
	}

	/* Element access: */

	reference	operator[] (size_type n) {return (_tab[n]);}
	const_reference operator[] (size_type n) const {return (_tab[n]);}
// Returns a reference to the element at position n in the vector.
// The function automatically checks whether n is within the bounds of valid elements in the vector,
// throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size).
// This is in contrast with member operator[], that does not check against bounds.
	reference at (size_type n) {if (n >= _size) throw std::out_of_range ("vector::_M_range_check\n"); else return (_tab[n]);}
	const_reference at (size_type n) const {if (n >= _size) throw std::out_of_range ("vector::_M_range_check\n"); else return (_tab[n]);}
// Access first element
// Returns a reference to the first element in the vector.
// Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
// Calling this function on an empty container causes undefined behavior.
	reference front() {return (_tab[0]);};
	const_reference front() const {return (_tab[0]);};
// Access last element
// Returns a reference to the last element in the vector.
// Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
// Calling this function on an empty container causes undefined behavior.
	reference back() {return (_tab[_size]);};
	const_reference back() const {return (_tab[_size]);};

	/* MODIFIERS */

// Assign vector content
// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
// In the range version (1), the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
// If a reallocation happens,the storage needed is allocated using the internal allocator.
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last) {
		clear();
		for (;first != last; ++first)
			push_back(*first);
	}
	
	void assign (size_type n, const value_type& val) {
		clear();
		while (n--)
			push_back(val);
	}

	void push_back (const value_type& val) {
      if (_size + 1 > _capacity)
		reserve(_capacity * 2);
	else
		_tab[_size++] = val;
	}
// Removes the last element in the vector, effectively reducing the container size by one. This destroys the removed element.
	void pop_back() {
		if (!empty())
			_allocator.destroy(&_tab[--_size]);
	}

// Insert elements
// The vector is extended by inserting new elements before the element at the specified position,
// effectively increasing the container size by the number of elements inserted.
// This causes an automatic reallocation of the allocated storage space if -and only if- the new vector 
// size surpasses the current vector capacity.
// Because vectors use an array as their underlying storage, inserting elements in positions other than
// the vector end causes the container to relocate all the elements that were after position to their new
// positions. This is generally an inefficient operation compared to the one performed for the same
// operation by other kinds of sequence containers (such as list or forward_list).
// The parameters determine how many elements are inserted and to which values they are initialized:
	iterator insert (iterator position, const value_type& val) {
		ptrdiff_t ptr_diff = position.getPtr() - begin().getPtr();
		#ifdef _DEBUG_
		std::cout << RED << "ptr_diff : " << ptr_diff << " size : " << _size << RESET << std::endl;
		#endif
		if ( _size + 1 > max_size() )
			throw std::length_error ("_M_fill_insert_(reserve)");
		size_t capacity;
		if ( _size + 1 > _capacity ) 
			capacity = ( _size + 1 + vAddedMem <= max_size() ) ? _size + 1 + vAddedMem : _size + 1;
		else
			capacity = _capacity;
		_T* tmpTab_ = _allocator.allocate(capacity);
		for (long i = 0; i < ptr_diff; ++i)
			tmpTab_[i] = _tab[i];
		tmpTab_[ptr_diff] = val;
		size_t i = 0;
		for (iterator end = this->end(); position != end; ++position, ++i)
			tmpTab_[ptr_diff + 1 + i] = *position;
		// ft::vector<_T, _Alloc >::~vector(); // cannot use "delete this;" bcoz new wasn't use eventhought it is used by the std::allocator
		this->~vector();
		_capacity = capacity;
		_size += 1;
		_tab = tmpTab_;
		return (&_tab[ptr_diff]);
	}

	void insert (iterator position, size_type n, const value_type& val) {
		for (size_t i = 0; i < n; ++i)
			position = insert(position, val);
	}

	template <class InputIterator> 
	void insert (iterator position, InputIterator first, InputIterator last) {
		for (; first != last; ++first, ++position) {
			#ifdef _DEBUG_
			std::cout << RED << "first : " << first.getPtr() << " last : " << last.getPtr() << RESET << std::endl;
			#endif
			position = insert(position, *first);
		}
	}

// Erase elements
// Removes from the vector either a single element (position) or a range of elements ([first,last)).
// This effectively reduces the container size by the number of elements removed, which are destroyed.
// Because vectors use an array as their underlying storage, erasing elements in positions other than the
// vector end causes the container to relocate all the elements after the segment erased to their new positions.
// This is generally an inefficient operation compared to the one performed for the same operation by other
// kinds of sequence containers (such as list or forward_list).
	iterator erase (iterator position) {
		iterator pos_plus_1 = position;
		return (erase(position, ++pos_plus_1));
	}

	iterator erase (iterator first, iterator last) {
		ptrdiff_t ptr_diff = last.getPtr() - first.getPtr(); // nb d'objet entre first et last
		ptrdiff_t offSet = last.getPtr() - begin().getPtr(); // nb d'objet entre begin et last
		iterator end = this->end();
		_size -= ptr_diff;
		for (; first != end; ++first, ++offSet)
		{
			if (--ptr_diff >= 0)
				_allocator.destroy(&(*first));
			// std::cout << "*first : " << *first << " ptr_diff : " << offSet << std::endl;
			// std::cout << " _tab[offSet] : " << _tab[offSet] << std::endl;
			if (&_tab[offSet] < &*end) {
				*first = _tab[offSet];
				_allocator.destroy(&_tab[offSet]);
			}
		}
		return (last);		
	}

	void swap (vector& x) {
		pointer tab_tmp = _tab;
		_tab = x._tab;
		x._tab = tab_tmp;
		
		unsigned int size_tmp = _size;
		_size = x._size;
		x._size = size_tmp;

		unsigned int capa_tmp = _capacity;
		_capacity = x._capacity;
		x._capacity = capa_tmp;
	}

	void clear() {
		for (iterator it = this->begin(), end = this->end(); it != end; ++it)
			_allocator.destroy(&(*it)); // (it) ne marche pas -> mismatch types ‘_Up*’ and ‘ft::vector<ClassTest>::iterator’
		_size = 0;
	}

	allocator_type get_allocator() const {
		return (_allocator);
	}

	// std::ostream & operator<<(std::ostream & o, ft::vector<_T, _Alloc>::iterator const & i) { o << i.getPtr(); return o;}

}; // Fin de la classe vector

template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		size_t i = 0, j = rhs.size();
		if (lhs.size() == rhs.size()) {
			for (typename ft::vector<T>::iterator it1 = lhs.begin(), it2 = rhs.begin(); i < j; ++i, ++it1, ++it2)
				if (!(*it1 == *it2))
					return (false);
		}
		else
			return (false);
		return (true);
	}

template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		size_t i = 0, j = rhs.size();
			for (typename ft::vector<T>::iterator it1 = lhs.begin(), it2 = rhs.begin(); i < j; ++i, ++it1, ++it2)
				if (*it1 < *it2)
					return (true);
		return (false);
	}

template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}


template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	  x.swap(y);
	  return ;
  }

template <typename _T, typename _Alloc>
	std::ostream & operator<<(std::ostream & o, typename ft::vector<_T, _Alloc>::iterator const & i) { o << (size_t)i.getPtr(); return o;}
	// std::ostream & operator<<(std::ostream & o, typename vector<_T>::iterator const & i) { o << i.getPtr(); return o;}

// template <typename _T, typename _Alloc>
// 	std::ostream & vector<_T, _Alloc>::iterator::operator<<(std::ostream & o, ft::vector<_T, _Alloc>::iterator const & i) { o << i.getPtr(); return o;}

} // Fin du namespace ft



// |.............v....|..................|

/* template <typename _T>
	void cpy_array(_T* tab, bool forward){
				while (forward ? position != end_: position != begin_)
				{
					++position;
					if (++even % 2) {
						cpy_2 = *position;
						*position = cpy_1;
					}
					else
					{
						cpy_1 = *position;
						*position = cpy_2;
					}
				}
		return ;
	} */

#endif
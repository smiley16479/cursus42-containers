#include <memory>
#include <limits>
#include <stddef.h>
// #include <vector>
// #include </usr/include/c++/6/bits/stl_iterator_base_types.h>
// #include </usr/include/c++/6/bits/stl_algobase.h>

#define vAddedMem 16 // better when power of 2

#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#endif

namespace ft {

	template < class _T = int, class _Alloc = std::allocator<_T> > 
	class vector
	{
	private:
			_T *_tab;
			unsigned int _size;
			unsigned int _Rsize; // real_size
			unsigned int _Zindx; // Zero index où le vector commence pour améliorer l'insertion (par défault au 1/4 du define vAddedMem)
			_Alloc& _allocator;
			// vector::size_type i;

	public:

		typedef _Alloc			  allocator_type;		//	Type d'allocateur par default celui de la STD
		typedef _T				  value_type;			//
		typedef	_T*				  pointer;				//	Pointer to element
		typedef	_T&				  reference;			//	Reference to element
		typedef	const _T*		  const_pointer;		//	Pointer to constant element
		typedef	const _T&		  const_reference;		//	Reference to constant element
		typedef size_t			  size_type;			//	Quantities of elements
		typedef	ptrdiff_t		  difference_type;		//	Difference between two pointers


   struct Iterator // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }  
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };  

    private:
        pointer m_ptr;
    };


		typedef value_type							iterator; // a random access iterator to value_type	convertible to const_iterator
		typedef const value_type					const_iterator; //	a random access iterator to const value_type	
		typedef reverse_iterator<iterator>			reverse_iterator;
		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		// typedef std::reverse_iterator<iterator>		  reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

//Implemented method and // //NON implemented method
	//  CONSTRUCTORS
		// explicit vector (const allocator_type& alloc = allocator_type()); //default (1)	
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill (2)
		// // template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range (3)
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
		// template <class InputIterator>  void assign (InputIterator first, InputIterator last); //range (1)
		// void assign (size_type n, const value_type& val); //fill (2)

	// Default Constructor
	explicit vector(const allocator_type& alloc = allocator_type())
	: _size(0), _Rsize(vAddedMem), _Zindx(vAddedMem / 4), _allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Default Constructor called" << std::endl;
		#endif
		_tab = const_cast<allocator_type&>(alloc).allocate(_Rsize);
	}

	explicit vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
	: _size(n),
	_Rsize(_size * 1.5 >= vAddedMem ? _size * 1.5 : vAddedMem),
	_Zindx(vAddedMem / 4),
	_allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Size Constructor called" << std::endl;
		#endif
		_tab = _allocator.allocate(_Rsize);
		for (size_t i = 0; i < _size; i++)
			_tab[i + _Zindx] = val; // new(&_tab[i]) _T(val); appelle le constructeur voir exemple 3 https://www.cplusplus.com/reference/new/operator%20new/
	} 

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	: _size(last - first),
	_Rsize(_size * 1.5 >= vAddedMem ? _size * 1.5 : vAddedMem),
	_Zindx(vAddedMem / 4),
	_allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Size Constructor called (Not implemented yet)" << std::endl;
		#endif
	}

	vector (const vector& x) {*this = x;}

	vector& operator=(const vector& x)
	{
		#ifdef _DEBUG_
		std::cout << "vector Assignment operator called" << std::endl;
		#endif
		if ( this != &x ) {
			ft::vector<_T, _Alloc >::~vector(); // cannot use "delete this;" bcoz new wasn't use eventhought it is used by the std::allocator
 			_size = x._size;
			_Rsize = x._Rsize;
			_Zindx = x._Zindx;
			_allocator = x._allocator;
			_tab = _allocator.allocate(_Rsize);
			for (size_t i = 0; i < x._size; i++)
				new (&_tab[i + _Zindx]) _T(x._tab[i + x._Zindx]);
		}
		return *this;
	}

	~vector()
	{
		#ifdef _DEBUG_
		std::cout << "vector Destructor called" << std::endl;
		#endif
		for (size_t i = 0; i < _size; i++)
			_allocator.destroy(&_tab[i + _Zindx]);
		_allocator.deallocate(_tab, _Rsize);
	}

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
			std::cout << "_size : " << _size << ", _Zindx : " << _Zindx << ", n : " << n << std::endl;
		#endif
		if (n < _size) {
			for (size_t i = n; i < _size; i++)
				_allocator.destroy(&_tab[i + _Zindx]);
			_size = n;
		}
		else {
			reserve(n);
			for (size_t i = _size + _Zindx; i < n; ++i)
				_allocator.construct(&_tab[i + _Zindx], val);
			_size = n;
		}
	}

	size_type capacity() const { return _Rsize;}

	bool empty() const { return (_size ? false : true); }

	void reserve (size_type n)
	{
		size_type maxSize = max_size();
		if ( n > maxSize )
			throw std::length_error ("_M_fill_insert_(reserve)");
		if ( n > _Rsize ) {
			#ifdef _DEBUG_
			std::cout << "_size : " << _size << "_Zindx : " << _Zindx << "n : " << n << std::endl;
			#endif
			size_t capacity = ( n + vAddedMem <= maxSize ) ? n + vAddedMem : n;
			_T* tmpTab_ = _allocator.allocate(capacity);
			for (size_t i = 0; i < _size; ++i)
				tmpTab_[i + _Zindx + vAddedMem / 4] = _tab[i + _Zindx];
			ft::vector<_T, _Alloc >::~vector(); // cannot use "delete this;" bcoz new wasn't use eventhought it is used by the std::allocator
			_Zindx += vAddedMem / 4;
			_Rsize = capacity;
			_tab = tmpTab_;
		}
		return;
	}

	/* Element access: */

	reference	operator[] (size_type n) {return (_tab[n + _Zindx]);}
	const_reference operator[] (size_type n) const {return (_tab[n + _Zindx]);}
// Returns a reference to the element at position n in the vector.
// The function automatically checks whether n is within the bounds of valid elements in the vector,
// throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size).
// This is in contrast with member operator[], that does not check against bounds.
	reference at (size_type n) {if (n >= _size) throw std::out_of_range ("vector::_M_range_check\n"); else return (_tab[n + _Zindx]);}
	const_reference at (size_type n) const {if (n >= _size) throw std::out_of_range ("vector::_M_range_check\n"); else return (_tab[n + _Zindx]);}
// Access first element
// Returns a reference to the first element in the vector.
// Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
// Calling this function on an empty container causes undefined behavior.
	reference front() {return (_tab[_Zindx]);};
	const_reference front() const {return (_tab[_Zindx]);};
// Access last element
// Returns a reference to the last element in the vector.
// Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
// Calling this function on an empty container causes undefined behavior.
	reference back() {return (_tab[_size + _Zindx]);};
	const_reference back() const {return (_tab[_size + _Zindx]);};

	/* MODIFIERS */

// Assign vector content
// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
// In the range version (1), the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
// If a reallocation happens,the storage needed is allocated using the internal allocator.
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last);
	
	void assign (size_type n, const value_type& val);

};
}

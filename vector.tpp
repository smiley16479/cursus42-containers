#include <memory>
#include <limits>
#include <stddef.h>
// #include <vector>
// #include </usr/include/c++/6/bits/stl_iterator_base_types.h>
// #include </usr/include/c++/6/bits/stl_algobase.h>

#define _DEBUG_

#ifdef _DEBUG_
#include <iostream> // A enlever avec les sortie
#endif

namespace ft {

	template < class _T = int, class _Alloc = std::allocator<_T> > 
	class vector
	{

	public:

		typedef _Alloc								  allocator_type;		//	Type d'allocateur par default celui de la STD
		typedef _T									  value_type;			//
		typedef	_T*									  pointer;				//	Pointer to element
		typedef	_T&									  reference;			//	Reference to element
		typedef	const _T*							  const_pointer;		//	Pointer to constant element
		typedef	const _T&							  const_reference;		//	Reference to constant element
		typedef size_t								  size_type;			//	Quantities of elements
		typedef	ptrdiff_t							  difference_type;		//	Difference between two pointers
		// typedef typename std::pointer				  pointer;
		// typedef typename std::const_pointer 		  const_pointer;
		// typedef std::reverse_iterator<iterator>		  reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		
		explicit vector (const allocator_type& alloc = allocator_type()); //default (1)	
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill (2)
		// template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range (3), commnter car interfère av constructor (2)fill
		vector (const vector& x); // copy (4)
		~vector();

		/*//Iterators:
		begin	// Return iterator to beginning (public member function ) If the container is empty, the returned iterator value shall not be dereferenced.
		end		// Return iterator to end (public member function )
		rbegin	// Return reverse iterator to reverse beginning (public member function )
		rend	// Return reverse iterator to reverse end (public member function )
		*/

		//Capacity:
		size_type	size() const;		// Return size (public member function )
		size_type	max_size() const;	// Return maximum size (public member function )
		void		resize (size_type n, value_type val = value_type()); // Change size (public member function )
		/*capacity	// Return size of allocated storage capacity (public member function )
		empty		// Test whether vector is empty (public member function )
		reserve		// Request a change in capacity (public member function )
		*/

		//Element access:
		reference		operator[] (size_type n);	//Access element (public member function )
		const_reference	operator[] (size_type n) const;
		/*at			//Access element (public member function )
		front		//Access first element (public member function )
		back		//Access last element (public member function )
		*/

		/*// Modifiers:
		assign		//Assign vector content (public member function )
		push_back	//Add element at the end (public member function )
		pop_back	//Delete last element (public member function )
		insert		//Insert elements (public member function )
		erase		//Erase elements (public member function )
		swap		//Swap content (public member function )
		clear		//Clear content (public member function )
		*/

		/* //Allocator:
		get_allocator		//Get allocator (public member function ) */

		/* //Non-member function overloads
		relational operators	//Relational operators for vector (function template )
		swap					//Exchange contents of vectors (function template ) */

		/* //Template specializations
		vector<bool>	//Vector of bool (class template specialization ) */

	private:
			_T *_tab;
			unsigned int _size;
			unsigned int _Rsize; // real_size
			allocator_type& _allocator;
			// vector::size_type i;
	};

	template < class _T, class _Alloc >
	vector<_T, _Alloc>::vector(const allocator_type& alloc)
	: _size(0), _Rsize(10), _allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Default Constructor called" << std::endl;
		#endif
		_tab = const_cast<allocator_type&>(alloc).allocate(_Rsize);
	}

	template < class _T, class _Alloc >
	vector<_T, _Alloc>::vector (size_type n, const value_type& val, const allocator_type& alloc)
	: _size(n), _Rsize(_size * 1.5 >= 10 ? _size * 1.5 : 10), _allocator(const_cast<allocator_type&>(alloc))
	{
		#ifdef _DEBUG_
		std::cout << "vector Size Constructor called" << std::endl;
		#endif
		_tab = _allocator.allocate(_Rsize);
		for (size_t i = 0; i < _size; i++)
			_tab[i] = val;
	}

	// template < class _T, class _Alloc > template < class InputIterator >
	// vector<_T, _Alloc >::vector (InputIterator first, InputIterator last, const allocator_type& alloc)
	// : _size(last - first), _Rsize(_size * 1.5 >= 10 ? _size * 1.5 : 10), _allocator(const_cast<allocator_type&>(alloc))
	// {
	// 	#ifdef _DEBUG_
	// 	std::cout << "vector Size Constructor called (Not implemented yet)" << std::endl;
	// 	#endif
	// 	//Not implemented yet
	// }

	template < class _T, class _Alloc >
	vector<_T, _Alloc >::~vector()
	{
		for (size_t i = 0; i < _size; i++)
				_allocator.destroy(&_tab[i]);
		_allocator.deallocate(_tab, _Rsize);
	}
	
	typedef size_t								  size_type;
	template < class _T, class _Alloc >
	size_type	vector<_T, _Alloc >::size(void) const
	{
		return _size;
	}

	template < class _T, class _Alloc >
	size_type	vector<_T, _Alloc >::max_size(void) const
	{
		// return (std::numeric_limits<size_t>::max()/* /sizeof(value_type) */); // Returns the maximum finite value representable by the numeric type T.
		return _allocator.max_size();
	}
	
	// typedef _T									  value_type;
	/* Change size
	Resizes the container so that it contains n elements.
	If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
	If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
	If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
	Notice that this function changes the actual content of the container by inserting or erasing elements from it. */
	template < class _T, class _Alloc >
	void	vector<_T, _Alloc >::resize(size_type n, _T val )
	{
		if (n < _size)
			for (size_t i = n; i < _size; i++)
				_allocator.destroy(_tab[i]);
	}

	template < class _T > using reference = _T&;
	template < class _T, class _Alloc >
	reference< _T >	vector<_T, _Alloc >::operator[] (size_type n)
	{
		return (_tab[n]);
	};
}

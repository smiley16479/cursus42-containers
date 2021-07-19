#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP

namespace ft {


/*   template <class T1, class T2> // pair de Solal
  struct pair {
    typedef T1   first_type;
    typedef T2   second_type;

    pair() : first(), second() {};
    pair (const first_type &a, const second_type &b) : first(a), second(b) {};

    template<class U, class V>
    pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) {};

    ~pair() {};

    pair<T1, T2>  &operator= (const pair<T1, T2> &pr) {
      first = pr.first;
      second = pr.second;
      return *this;
    };

    first_type  first;
    second_type second;
  }; */

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;	// The first template parameter (T1)	Type of member first.
		typedef T2	second_type; //	The second template parameter (T2)	Type of member second.

		pair () : first(), second() {};
		
		template<class U, class V> 
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};

		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		first_type  first;
		second_type second;
	};

	template <class T1, class T2>
	  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template<class T1, class T2>
	struct s_tree
	{
		// typename ft::map< Key, T, Compare, Alloc>:: ;
		// ft::map<Key , T , Compare, Alloc>::
		pair<T1, T2> myPair;
		s_tree* parent;
		s_tree* left;
		s_tree* right;
	};


// ITERATOR
template<typename Key, typename T >
	struct map_iterator
	{

// DEBUT Redefinition des typedef presents ds map.hpp l.49

	typedef Key									key_type;	// The first template parameter (Key)	
	typedef T									mapped_type;	// The second template parameter (T)	
	typedef ft::pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	// typedef	Compare								key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
	//? typedef		value_compare	// Nested function class to compare elements see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	// typedef	Alloc								allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>

	// typedef allocator_type::reference			reference;	// allocator_type::reference for the default allocator: value_type&
	typedef	value_type&							reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&					const_reference;	// allocator_type::const_reference for the default allocator: const value_type&

	typedef	s_tree<Key, T>*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const s_tree<Key, T>*					const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
		//
	// typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	// typedef	const value_type*					const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*


	typedef ft::map_iterator< Key, T >			iterator;
	typedef const iterator						const_iterator;
	typedef iterator	 						reverse_iterator;
	typedef const_iterator						const_reverse_iterator;
		// 
	// typedef	value_type*							iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef	const value_type*					const_iterator; //	a bidirectional iterator to const value_type	
	// typedef	iterator							reverse_iterator; //	reverse_iterator<iterator>	
	// typedef const reverse_iterator				const_reverse_iterator; //	reverse_iterator<const_iterator>	


	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
// FIN Redefinition des typedef presents ds map.hpp l.49


		typedef std::forward_iterator_tag	iterator_category;
		// typedef ft::s_tree<Key, T>*	map_iterator; //AJOUT
		// typedef ft::s_tree<Key, T>*	pointer; //AJOUT
 
		map_iterator() : _ptr(NULL) { std::cout << "test iterator_map default constructor" << std::endl;}
		map_iterator(pointer ptr) : _ptr(ptr) { std::cout << "iterator_map default constructor" << std::endl;}
		// iterator(iterator const & ptr) : _ptr(ptr._ptr) {}
 
		pointer getPtr() const { return _ptr; }
		reference operator*() const { return *_ptr; }
		pointer operator->() { return _ptr; }
		iterator& operator++() {
			if (_ptr->parent && _ptr->parent->left)
				return (_ptr->parent->left);
		}
		iterator& operator=(const iterator & i) { if (this->_ptr != i._ptr) _ptr = i._ptr; return *this;} // <- Le = est foireux
		// iterator& operator++() { ++_ptr; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator& operator--() { --_ptr; return *this; }
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		iterator& operator+=( map_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		iterator& operator-=( map_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		friend bool operator== (const map_iterator& a, const map_iterator& b) { return a._ptr == b._ptr; };
		friend bool operator!= (const map_iterator& a, const map_iterator& b) { return a._ptr != b._ptr; };


// (ITERATORS:) defini ds map.hpp car _mapTree non accessible ds map_utils
/* 		iterator begin() { s_tree<Key, T> temp = _mapTree;
			while (temp->left) temp = temp->left;
			return iterator(temp); }
		const_iterator begin() const { return this->begin();}
		iterator end()   { s_tree<Key, T> temp = _mapTree;
			while (temp->right) temp = temp->right;
			return iterator(temp); }
		const_iterator end() const { return this->end();}
		reverse_iterator rbegin() { return this->end();}
		const_reverse_iterator rbegin() const { return this->end();}
		reverse_iterator rend() { return this->begin();}
		const_reverse_iterator rend() const { return this->begin();} */
	
	    private:
	        pointer _ptr;
			// ft::pair<Key, T> _ptr;
    }; 
 

/* 	iterator begin() { s_tree<Key, T> temp = _mapTree;
		while (temp->left) temp = temp->left;
		return iterator(temp); }
	const_iterator begin() const { return this->begin();}
	iterator end()   { s_tree<Key, T> temp = _mapTree;
		while (temp->right) temp = temp->right;
		return iterator(temp); }
	const_iterator end() const { return this->end();}
	reverse_iterator rbegin() { return this->end();}
	const_reverse_iterator rbegin() const { return this->end();}
	reverse_iterator rend() { return this->begin();}
	const_reverse_iterator rend() const { return this->begin();} */

}

#endif
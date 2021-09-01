#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP

namespace ft {


template <class T>

  struct less {
    typedef bool  result_type;
    typedef T     first_argument_type;
    typedef T     second_argument_type;

    bool operator() (const T &lhs, const T &rhs) const { return lhs < rhs; };
  };

  template <class Compare, class T>
  class Comp {
   public:
    Comp(Compare c) : comp_(c) {};

    bool operator()(const T& x, const T& y) const { return comp_(x.first, y.first); };

    Compare comp_;
  };

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;	// The first template parameter (T1)	Type of member first.
		typedef T2	second_type; //	The second template parameter (T2)	Type of member second.

		pair () : first(), second() {};
		
		template<class U, class V> 
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};

		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		pair<T1, T2>  &operator= (const pair<T1, T2> &pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		};

		first_type  first;
		second_type second;
	};

	template <class T1, class T2>
	  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first==rhs.first && lhs.second==rhs.second); }

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

  template <class T1, class T2>
  ft::pair<T1, T2> make_pair(T1 t, T2 u) {
    return ft::pair<T1, T2>(t, u);
  };

	template<class U>
	struct s_tree
	{// De façon à atteindre la taille d'un noeud de map de STL officielle
    	bool unused_;
    	#ifdef __linux__
    	  int unused2_;
    	#endif

		U myPair;
		s_tree* left;
		s_tree* right;
		s_tree* begin;
	};


// ITERATOR
template<typename Key, typename T >
	class map_iterator
	{
		public:
// DEBUT Redefinition des typedef presents ds map.hpp l.49

	typedef Key										key_type;	// The first template parameter (Key)	
	typedef T										mapped_type;	// The second template parameter (T)	
	typedef ft::pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef	value_type&								reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&
	typedef	s_tree<value_type>*						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const s_tree<value_type>*				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
	typedef	value_type*								pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*						const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef ft::map_iterator< Key, T >				iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::map_iterator< const Key,const T >	const_iterator;	//	a bidirectional iterator to const value_type	
	// typedef iterator	 							reverse_iterator;	//	reverse_iterator<iterator>	
	// typedef const reverse_iterator				const_reverse_iterator;	//	reverse_iterator<const_iterator>	
		// 
	// typedef	value_type*							iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef	const iterator						const_iterator; //	a bidirectional iterator to const value_type	
	// typedef	iterator							reverse_iterator; //	reverse_iterator<iterator>	
	// typedef	const reverse_iterator				const_reverse_iterator; //	reverse_iterator<const_iterator>	


	typedef	ptrdiff_t								difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t									size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
// FIN Redefinition des typedef presents ds map.hpp l.49


		typedef std::bidirectional_iterator_tag		iterator_category;
		// typedef ft::s_tree<Key, T>*	map_iterator; //AJOUT
		// typedef ft::s_tree<Key, T>*	pointer; //AJOUT
 
		map_iterator() : _ptr(NULL), _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		}
		map_iterator(node_pointer ptr) : _ptr(ptr) , _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
		}
		// iterator(iterator const & ptr) : _ptr(ptr._ptr) {}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		pointer operator->() { return &(_ptr->myPair); }

		iterator& operator++() {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this);
		}
		// iterator& operator++() { ++_ptr; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator& operator--() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this); 
		}
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		iterator& operator=(const iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_previous_ptr = i._previous_ptr;
			}
			return *this;
		} // <- Le = est foireux
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		iterator& operator+=( map_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		iterator& operator-=( map_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		/* friend */ bool operator== (/* const map_iterator& a, */ const map_iterator& b) { return /* a. */_ptr == b._ptr; };
		/* friend */ bool operator!= (/* const map_iterator& a, */ const map_iterator& b) { return /* a. */_ptr != b._ptr; };

		node_pointer getLowest(node_pointer node) {
			return _ptr->begin->right;
		}

		node_pointer getHighest(node_pointer node) {
			return _ptr->begin->left;
		}
	    // private:
			node_pointer _ptr;
			node_pointer _previous_ptr;
	}; 

template<typename Key, typename T >
	class map_iterator<const Key, const T>
	{
		public:
// DEBUT Redefinition des typedef presents ds map.hpp l.49

	typedef const Key									key_type;	// The first template parameter (Key)	
	typedef T									mapped_type;	// The second template parameter (T)	
	typedef const ft::pair<key_type, mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	// typedef	Compare								key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
	//? typedef		value_compare	// Nesstreamted function class to compare elements see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	// typedef	Alloc								allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>

	// typedef allocator_type::reference			reference;	// allocator_type::reference for the default allocator: value_type&
	typedef	const value_type&						reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&

	typedef	s_tree<value_type>*						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const s_tree<value_type>*				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
		//
	typedef	value_type*								pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*						const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*


	// typedef ft::map_iterator< Key, T >			iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::map_iterator< Key, T >			iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::map_iterator< const Key, const T >			const_iterator;	//	a bidirectional iterator to const value_type	
	// typedef iterator	 						reverse_iterator;	//	reverse_iterator<iterator>	
	// typedef const reverse_iterator			const_reverse_iterator;	//	reverse_iterator<const_iterator>	
		// 
	// typedef	value_type*						iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef	const iterator					const_iterator; //	a bidirectional iterator to const value_type	
	// typedef	iterator						reverse_iterator; //	reverse_iterator<iterator>	
	// typedef	const reverse_iterator			const_reverse_iterator; //	reverse_iterator<const_iterator>	


	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
// FIN Redefinition des typedef presents ds map.hpp l.49


		typedef std::bidirectional_iterator_tag	iterator_category;
		// typedef ft::s_tree<Key, T>*	map_iterator; //AJOUT
		// typedef ft::s_tree<Key, T>*	pointer; //AJOUT
 
		map_iterator() : _ptr(NULL), _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		}
		map_iterator(ft::map_iterator<const Key , const T>& it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		} 
		map_iterator(ft::map_iterator<const Key , const T>const & it) : _ptr(it._ptr) , _previous_ptr(it._previous_ptr) {
			#ifdef _DEBUG_
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
		} // ft::s_tree<ft::pair<const char, int> >*& // 
		map_iterator(node_pointer ptr) : _ptr(ptr) , _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
		}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		pointer operator->() { return &(_ptr->myPair); }

		iterator& operator++() {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this);
		}
		// iterator& operator++() { ++_ptr; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator& operator--() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this); 
		}
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		iterator& operator=(const iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_previous_ptr = i._previous_ptr;
			}
			return *this;
		} // <- Le = est foireux
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		iterator& operator+=( map_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		iterator& operator-=( map_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		/* friend */ bool operator== (/* const map_iterator& a, */ const map_iterator& b) { return /* a. */_ptr == b._ptr; };
		/* friend */ bool operator!= (/* const map_iterator& a, */ const map_iterator& b) { return /* a. */_ptr != b._ptr; };

		node_pointer getLowest(node_pointer node) {
			return _ptr->begin->right;
		}

		node_pointer getHighest(node_pointer node) {
			return _ptr->begin->left;
		}
	    // private:
			node_pointer _ptr;
			node_pointer _previous_ptr;
	}; 

template<typename Key, typename T >
	class const_map_iterator
	{

	};

template<typename Key, typename T >
	class const_map_iterator<const Key, const T>
	{
public:

	typedef const Key									key_type;	// The first template parameter (Key)	
	typedef const T									mapped_type;	// The second template parameter (T)	
	typedef /* const */ ft::pair<key_type, mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef	const value_type&						reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&

	typedef	s_tree<value_type>*						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const s_tree<value_type>*				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef	value_type*								pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*						const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
	typedef ft::map_iterator< const Key, T >			iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::const_map_iterator< const Key, const T >			const_iterator;	//	a bidirectional iterator to const value_type

	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

		const_map_iterator() : _ptr(NULL), _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "const_map_iterator default constructor" << std::endl;
			#endif
		}
		const_map_iterator(ft::map_iterator<Key , T> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "const_map_iterator (1) constructor" << std::endl;
			#endif
		}
		const_map_iterator(ft::map_iterator<const Key , T> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "const_map_iterator (2) constructor" << std::endl;
			#endif
		}
		const_map_iterator(ft::map_iterator<const Key , const T>& it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "const_map_iterator (3) constructor" << std::endl;
			#endif
		} 
		const_map_iterator(ft::const_map_iterator<const Key , const T>const & it) : _ptr(it._ptr) , _previous_ptr(it._previous_ptr) {
			#ifdef _DEBUG_
				std::cout << "const_map_iterator parametric constructor" << std::endl;
			#endif
		} // ft::s_tree<ft::pair<const char, int> >*& // 
		const_map_iterator(node_pointer ptr) : _ptr(ptr) , _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "const_map_iterator node_pointer parametric constructor" << std::endl;
			#endif
		}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		const_pointer operator->() { return &(_ptr->myPair); }

		const_iterator& operator++() {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this);
		}
		// iterator& operator++() { ++_ptr; return *this; }
		const_iterator operator++(int) { const_iterator tmp = *this; ++(*this); return tmp; }
		const_iterator& operator--() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this); 
		}
		const_iterator operator--(int) { const_iterator tmp = *this; --(*this); return tmp; }
		const_iterator& operator=(const const_iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_previous_ptr = i._previous_ptr;
			}
			return *this;
		} // <- Le = est foireux
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		const_iterator& operator+=( const_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		const_iterator operator+( const_iterator & i ) {const_iterator copie(_ptr); copie += i; return (copie);}
		const_iterator& operator-=( const_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		const_iterator operator-( const_iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}

		node_pointer getLowest(node_pointer node) {
			return _ptr->begin->right;
		}

		node_pointer getHighest(node_pointer node) {
			return _ptr->begin->left;
		}
	    // private:
			const_node_pointer _ptr;
			const_node_pointer _previous_ptr;
	};
	template <typename Key, typename T >
		/* friend */ bool operator== ( ft::const_map_iterator<const Key, const T>& a, ft::const_map_iterator<const Key, const T>& b) { return  a._ptr == b._ptr;/* (a.first == b.first && a.second == b.second); */ };
	template <typename Key, typename T >
		/* friend */ bool operator!= ( ft::const_map_iterator<const Key, const T>& a, ft::const_map_iterator<const Key, const T>& b) { return !(a == b); };

template<typename iterator/* ,typename iterator = map_iterator< Key , T>  */>
	class reverse_iterator//<const Key, const T>
	{
public:

	typedef typename iterator::key_type									key_type;	// The first template parameter (Key)	
	typedef typename iterator::mapped_type								mapped_type;	// The second template parameter (T)	
	typedef typename iterator::value_type	value_type;	// pair<const key_type,mapped_type>	
	typedef	const value_type&						reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&

	typedef	typename iterator::node_pointer						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	typename iterator::const_node_pointer				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef	typename iterator::pointer				pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	typename iterator::const_pointer		const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
	typedef typename iterator::const_iterator		const_iterator;	//	a bidirectional iterator to const value_type

	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

		reverse_iterator() : _ptr(NULL), _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_map default constructor" << std::endl;
			#endif
		}
		// reverse_iterator(ft::map_iterator<key_type , mapped_type> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
		// 	#ifdef _DEBUG_
		// 		std::cout << "reverse_iterator_map default constructor" << std::endl;
		// 	#endif
		// }
		reverse_iterator(ft::map_iterator<const key_type , mapped_type> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_map default constructor" << std::endl;
			#endif
		}
		reverse_iterator(ft::map_iterator<const key_type , const mapped_type>& it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_map default constructor" << std::endl;
			#endif
		} 
		reverse_iterator(ft::reverse_iterator<iterator>const & it) : _ptr(it._ptr) , _previous_ptr(it._previous_ptr) {
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_map parametric constructor" << std::endl;
			#endif
		} // ft::s_tree<ft::pair<const char, int> >*& // 
		reverse_iterator(node_pointer ptr) : _ptr(ptr) , _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_map parametric constructor" << std::endl;
			#endif
		}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		const_pointer operator->() { return &(_ptr->myPair); }

		reverse_iterator& operator++() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this);
		}
		// iterator& operator++() { ++_ptr; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
		reverse_iterator& operator--() {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this); 
		}
		reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }
		reverse_iterator& operator=(const reverse_iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_previous_ptr = i._previous_ptr;
			}
			return *this;
		} // <- Le = est foireux
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		reverse_iterator& operator+=( reverse_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		reverse_iterator operator+( reverse_iterator & i ) {reverse_iterator copie(_ptr); copie += i; return (copie);}
		reverse_iterator& operator-=( reverse_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		reverse_iterator operator-( const_iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}

		node_pointer getLowest(node_pointer node) {
			return _ptr->begin->right;
		}

		node_pointer getHighest(node_pointer node) {
			return _ptr->begin->left;
		}
	    // private:
			node_pointer _ptr;
			node_pointer _previous_ptr;
	};

	template< typename iterator >
	class reverse_iterator<const iterator>
	{
public:

//	typedef const Key									key_type;	// The first template parameter (Key)	
//	typedef /* const */ T									mapped_type;	// The second template parameter (T)	
//	typedef /* const */ ft::pair<key_type, mapped_type>	value_type;	// pair<const key_type,mapped_type>	
//	typedef	const value_type&						reference;	// allocator_type::reference for the default allocator: value_type&
//	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&
//
//	typedef	s_tree<value_type>*						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
//	typedef	const s_tree<value_type>*				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

//DEBUT AJOUT
	typedef typename iterator::key_type									key_type;	// The first template parameter (Key)	
	typedef typename iterator::mapped_type								mapped_type;	// The second template parameter (T)	
	typedef typename iterator::value_type	value_type;	// pair<const key_type,mapped_type>	
	typedef	const value_type&						reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&

	typedef	typename iterator::node_pointer						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	typename iterator::const_node_pointer				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef	typename iterator::pointer				pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	typename iterator::const_pointer		const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
	typedef typename iterator::const_iterator		const_iterator;	//	a bidirectional iterator to const value_type
//FIN AJOUT
	// typedef	value_type*								pointer; //	allocator_type::pointer	for the default allocator: value_type*
	// typedef	const value_type*						const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
	// typedef ft::map_iterator< const Key, T >			iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef ft::const_map_iterator< const Key, const T >			const_iterator;	//	a bidirectional iterator to const value_type

	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

		reverse_iterator() : _ptr(NULL), _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		}
		reverse_iterator(ft::reverse_iterator<iterator> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		}
		// reverse_iterator(ft::reverse_iterator< iterator> it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
		// 	#ifdef _DEBUG_
		// 		std::cout << "iterator_vector default constructor" << std::endl;
		// 	#endif
		// }
		reverse_iterator(ft::reverse_iterator<const iterator>& it) : _ptr(it._ptr), _previous_ptr(it._previous_ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		} 
		// reverse_iterator(ft::const_reverse_iterator<const iterator>const & it) : _ptr(it._ptr) , _previous_ptr(it._previous_ptr) {
		// 	#ifdef _DEBUG_
		// 		std::cout << "iterator_map parametric constructor" << std::endl;
		// 	#endif
		// }
		reverse_iterator(node_pointer ptr) : _ptr(ptr) , _previous_ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
		}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		const_pointer operator->() { return &(_ptr->myPair); }

		reverse_iterator& operator++() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this);
		}
		// iterator& operator++() { ++_ptr; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
		reverse_iterator& operator--() {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this); 
		}
		reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }
		reverse_iterator& operator=(const reverse_iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_previous_ptr = i._previous_ptr;
			}
			return *this;
		} // <- Le = est foireux
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		reverse_iterator& operator+=( reverse_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		reverse_iterator operator+( reverse_iterator & i ) {reverse_iterator copie(_ptr); copie += i; return (copie);}
		reverse_iterator& operator-=( reverse_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		reverse_iterator operator-( reverse_iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}

		node_pointer getLowest(node_pointer node) {
			return _ptr->begin->right;
		}

		node_pointer getHighest(node_pointer node) {
			return _ptr->begin->left;
		}
	    // private:
			const_node_pointer _ptr;
			const_node_pointer _previous_ptr;
	};
	template <typename iterator >
		/* friend */ bool operator== ( ft::reverse_iterator<iterator>& a, ft::reverse_iterator<iterator>& b) { return  a._ptr == b._ptr;/* (a.first == b.first && a.second == b.second); */ };
	template <typename iterator >
		/* friend */ bool operator!= ( ft::reverse_iterator<iterator>& a, ft::reverse_iterator<iterator>& b) { return !(a == b); };
}

#endif
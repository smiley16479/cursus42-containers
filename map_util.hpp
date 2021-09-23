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

  // ALLOCATOR

template <class T>
class allocator {
  public:
    typedef T        value_type;
    typedef T*       pointer;
    typedef const T* const_pointer;
    typedef T&       reference;
    typedef const T& const_reference;
    typedef std::size_t    size_type;
    typedef std::ptrdiff_t difference_type;

    template <class U>
    struct rebind { typedef ft::allocator<U> other; };

    // return address of values
    pointer address (reference value) const { return &value; }
    const_pointer address (const_reference value) const { return &value; }

    allocator() throw() {}
    allocator(const allocator&) throw() {}

    template <class U>
    allocator (const allocator<U>&) throw() {}

    ~allocator() throw() {}

    size_type max_size () const throw() { return std::numeric_limits<std::size_t>::max() / sizeof(T); }

    pointer allocate (size_type num, const void* = 0) {
      return reinterpret_cast<pointer>(::operator new(num * sizeof (T)));
    }

    void construct (pointer p, const T& value) {
      new(p) T(value);
    }

    void destroy (pointer p) {
      p->~T();
    }

    void deallocate (pointer p, size_type) {
      ::operator delete(p);
    }
    bool operator== (const allocator&) throw() { return true; }
    bool operator!= (const allocator &a) throw() { return !operator==(a); }
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
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return lhs.first==rhs.first && lhs.second==rhs.second;}
template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return !(lhs==rhs);}
template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);}
template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return !(rhs<lhs);}
template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return rhs<lhs;}
template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
	return !(lhs<rhs);}

template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u) {
  return ft::pair<T1, T2>(t, u);
};

enum Color {E_RED, E_BLACK, E_DOUBLE_BLACK};

template<class U>
struct s_tree
{
	// typename ft::map< Key, T, Compare, Alloc>:: ;
	// ft::map<Key , T , Compare, Alloc>::
	U myPair;
	int	color;
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

	typedef	s_tree<value_type>*						node_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const s_tree<value_type>*				const_node_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*
		//
	typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*					const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*


	typedef ft::map_iterator< Key, T >			iterator;	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef const iterator					const_iterator;	//	a bidirectional iterator to const value_type	
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


		typedef std::forward_iterator_tag	iterator_category;
		// typedef ft::s_tree<Key, T>*	map_iterator; //AJOUT
		// typedef ft::s_tree<Key, T>*	pointer; //AJOUT
 
		map_iterator() : _ptr(NULL) {
			#ifdef debug
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		}
		map_iterator(node_pointer ptr) : _ptr(ptr), _baseRoot(NULL) {
			#ifdef debug
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
			_baseRoot = get_rootNode(ptr);
		//  _endNode = getHighest(_ptr);
		}
		// iterator(iterator const & ptr) : _ptr(ptr._ptr) {}
 
		node_pointer getPtr() const { return _ptr; }
		reference operator*() const { return _ptr->myPair; }
		pointer operator->() { return &(_ptr->myPair); }

/* 		iterator& operator++() {
			if (_ptr) {
// POUR TOOGLE ENTRE LE DERNIER ELEMENT ET LE END 
				if (_previous_ptr == _endNode) {//std::cout << RED << "POUR TOOGLE ENTRE LE DERNIER ELEMENT ET LE END" << RESET << std::endl;
					_previous_ptr = _endNode->parent;
					_ptr = _endNode;
					return (*this);
				}
// 	POUR ALLER TT A GAUCHE D'UNE BRANCHE DE DROITE OU POUR DESCENDRE D'UNE BRANCHE VERS LA DROITE
				if (_ptr->right && _ptr->right != _previous_ptr && (_ptr = _ptr->right)) {
//std::cout << RED << "TEST1::a_previous_ptr" << _previous_ptr->myPair.first << RESET << std::endl;
					_previous_ptr = _ptr;
					while (_ptr->left) {
						_ptr = _ptr->left;
						_previous_ptr = _ptr;
					}
//std::cout << RED << "TEST1::b_previous_ptr" << _previous_ptr->myPair.first << RESET << std::endl;
					return (*this);
				}
// POUR REMONTER D'UNE BRANCHE
				else if (!_ptr->left && !_ptr->right && _ptr->parent) {
//std::cout << RED << "TEST2::a _previous_ptr" << _previous_ptr->myPair.first << "highest : " << this->getHighest(_ptr)->myPair.first << RESET << std::endl;
					if (_previous_ptr == _endNode) {
						this->_ptr = _previous_ptr->parent;
						return (*this);
					}
					if (_ptr->parent && _ptr->parent->left == _ptr) {
						_ptr = _ptr->parent;
						_previous_ptr = _ptr;
					if (_ptr->left == _endNode) //<- On en a tester les _ptr
//std::cout << RED << "TEST2::b" << RESET << std::endl;
						return (*this);
					}
					else if (_ptr->parent && _ptr->parent->right == _ptr)
					{
//std::cout << RED << "TEST2::c" << RESET << std::endl;
						while (_ptr->parent && _ptr->parent->right == _ptr )
						{
							_ptr = _ptr->parent;
							_previous_ptr = _ptr;
						}
						if (_ptr->parent && _ptr->parent->left == _ptr) {						
							_ptr = _ptr->parent;
							_previous_ptr = _ptr;
						}
						return (*this);
					}
				}
// POUR REMONTER DE TOUS LES NOEUDS DE DROITE
				else if (!_ptr->right) {
//std::cout << RED << "TEST3" << RESET << std::endl;
					while (_ptr->parent != NULL && _ptr->parent->right == _ptr) {
						_previous_ptr = _ptr;
						_ptr = _ptr->parent;
					}
// JUSQU'AU BOUT...Si nécessaire
						if (_ptr->parent && (_ptr = _ptr->parent))
							return (*this);
						else {
							_ptr = _ptr->parent;
							return (*this);
						}
				}
			}
//std::cout << RED << "TEST5 : Return sans rien faire, _ptr->right : " << _ptr->right << RESET << std::endl;
			return (*this);
		} */
    iterator& operator++() {
	#ifdef debug
      std::cout << "ds ++op _ptr:val" << _ptr << ":\n" << /* _ptr->myPair.first << */ ", _baseRoot : " << _baseRoot << std::endl;
    #endif
      if (_ptr->right == _baseRoot)
	  	  _ptr = _baseRoot;
      else if (_ptr->right) {
        _ptr = _ptr->right;
        while (_ptr->left)
          _ptr = _ptr->left;
      }
      else {
        node_pointer tmp = _ptr->parent;
        while (tmp && _ptr == tmp->right) {
          _ptr = tmp;
          tmp = tmp->parent;
		#ifdef debug
	      std::cout << "ds ++op _ptr/val" << _ptr << "/" << _ptr->myPair.first;
		  std::cout << " et tmp : " << tmp << "\n";
		//   std::cout << " et tmp->right:val" << tmp->right << ":" << tmp->right->myPair.first << std::endl;
	    #endif		
        }
        if (/* tmp &&  */_ptr->right != tmp){ //std::cout << " here\n";
          _ptr = tmp;}
      }
      return *this;
	}
		// iterator& operator++() { ++_ptr; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator& operator--() { --_ptr; return *this; }
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		iterator& operator=(const iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef debug
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_endNode = i._endNode;
			}
			return *this;
		} // <- Le = est foireux
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
		node_pointer getLowest(node_pointer node) {
			while (node->parent)
				node = node->parent;
			while (node->left)
				node = node->left;
			return node;
		}

		node_pointer getHighest(node_pointer node) {
			while (node->parent)
				node = node->parent;
			while (node->right)
				node = node->right;
			return node;
		}

		node_pointer get_rootNode(node_pointer &node) {
			#ifdef debug
				std::cout << MAGENTA "get_rootNode : " << node << " data : " << node->myPair.first << " prt : " << node->parent << RESET"\n";
			#endif
	    	node_pointer ptr, previous_ptr;
			ptr = previous_ptr = node;
	    	while (ptr->parent != NULL && ptr->parent != previous_ptr)
	    	    ptr = ptr->parent;
			#ifdef debug
				std::cout << MAGENTA "get_rootNode : " << ptr << " data : " << ptr->myPair.first << " prt : " << ptr->parent << RESET"\n";
			#endif
	    	previous_ptr = ptr;
	    	while (ptr->left != previous_ptr)
	    	{   
	    	    #ifdef debug
	    	        std::cout << MAGENTA "ptr inséré : " << ptr << " data : " << ptr->myPair.first << " prt : " << ptr->parent << RESET"\n";
	    	    #endif
	    	    previous_ptr = ptr;
	    	    ptr = ptr->left;
	    	}
	    	return ptr;
		}

	    // private:
			node_pointer _ptr;
			node_pointer _endNode;
			node_pointer _baseRoot;
			
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
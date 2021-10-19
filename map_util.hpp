#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP
#include "iterator_traits.hpp"
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
	U myPair;
	int	color;
	s_tree* parent;
	s_tree* left;
	s_tree* right;
};


// ITERATOR
  template <class Key, class T, bool isconst = false>
  struct map_iterator {

    typedef map_iterator<Key, T, isconst>   iterator;
    typedef std::ptrdiff_t                  difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ft::pair<const Key, T>          value_type;

    typedef typename choose_type<isconst,
              const value_type&, value_type&>::type       reference;
    
	typedef typename choose_type<isconst,
              const value_type*, value_type*>::type       pointer;
    
	typedef typename choose_type<isconst,
              const s_tree<value_type>*, s_tree<value_type>*>::type	   node_pointer;

    typedef typename choose_type<isconst,
              const s_tree<value_type>* const*, s_tree<value_type>**>::type   nodeDBptr;

// ft::s_tree<ft::pair<const int, int> >* const*


/* // DEBUT Redefinition des typedef presents ds map.hpp l.49

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
// FIN Redefinition des typedef presents ds map.hpp l.49 */

 
		map_iterator() : _ptr(NULL), _baseRoot(NULL), _endPoint(value_type()) {
			#ifdef debug
				std::cout << "iterator_map default constructor" << std::endl;
			#endif
		}
		map_iterator(const node_pointer ptr, const nodeDBptr baseRoot) : _ptr(ptr), _baseRoot(baseRoot), _endPoint(value_type()) {
			#ifdef debug
				std::cout << "iterator_map parametric constructor" << std::endl;
			#endif
		}
    	map_iterator(const map_iterator<Key, T, false> &copy) : _ptr(copy._ptr),  _baseRoot(copy._baseRoot), _endPoint(copy._endPoint) {};
    	map_iterator(const map_iterator<Key, T, true> &copy) : _ptr(copy._ptr),  _baseRoot(copy._baseRoot), _endPoint(copy._endPoint) {}; 
		// node_pointer getPtr() const { return _ptr; }
		reference operator*() const { value_type pair_blanche = _endPoint ; return _ptr ? _ptr->myPair : pair_blanche; }
		pointer operator->() {value_type pair_blanche = _endPoint ; return _ptr ? &(_ptr->myPair) : &pair_blanche; }

    iterator& operator++() {
        // std::cout << /* "ds op++ root-data " << _ptr->data <<  */", root/baseRoot ptr : " <<   _ptr << "/" << *_baseRoot << std::endl;
		if (!_ptr) {
			if (!(_ptr = *_baseRoot))
                return *this;
			while (_ptr && _ptr->left)
				_ptr = _ptr->left;
		}
		if (_ptr && _ptr->right){
			_ptr = _ptr->right;
			while (_ptr->left)
				_ptr = _ptr->left;
		}
		else {
			node_pointer tmp;
			do {
				tmp = _ptr;
				_ptr = _ptr->parent;
			} while (_ptr && (tmp == _ptr->right));
		}
    #ifdef debug
        std::cout << "ds op++ root-data " << _ptr->data << ", root/baseRoot ptr : " <<   _ptr << "/" << _baseRoot << std::endl;
    #endif
    	return *this;
    }
	
	iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
	iterator& operator--() { 
		if (!_ptr) {
			_ptr = *_baseRoot;
			while (_ptr && _ptr->right)
				_ptr = _ptr->right;
		}
		else if (_ptr->left) {
			_ptr = _ptr->left;
			while (_ptr && _ptr->right)
				_ptr = _ptr->right;
		}
		else {
			node_pointer tmp;
			do {
				tmp = _ptr;
				_ptr = _ptr->parent;
			} while (_ptr && tmp == _ptr->left);
		}
		return *this;
	}
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		iterator& operator=(const iterator & i) {
			if (this->_ptr != i._ptr) {
				#ifdef debug
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
				_baseRoot = i._baseRoot;
			}
			return *this;
		}
		iterator& operator+=( map_iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
		iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		iterator& operator-=( map_iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
		iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		bool operator!=(const iterator &b) const { return (this->_ptr != b._ptr && *this->_baseRoot); };
		bool operator==(const iterator &b) const { return (*this != b);};

	    // private:
			node_pointer  _ptr;
			nodeDBptr _baseRoot;
			value_type _endPoint;
			
	}; 

 template <typename Iterator>
  class map_reverse_iterator {
   public:
    typedef map_reverse_iterator    self;
    typedef Iterator            iterator_type;

    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type        value_type;
    typedef typename iterator_traits<iterator_type>::pointer           pointer;
    typedef typename iterator_traits<iterator_type>::reference         reference;
    typedef typename iterator_traits<iterator_type>::difference_type   difference_type;

    map_reverse_iterator() : it_() {
		#ifdef debug
			std::cout << "iterator_map default constructor" << std::endl;
		#endif
	};
    map_reverse_iterator(const iterator_type copy) : it_(copy) {
		#ifdef debug
			std::cout << "reverse_iterator_map Parametric constructor(1)" << std::endl;
		#endif
	};

    template <typename It>
    map_reverse_iterator(const map_reverse_iterator<It> &copy) : it_(copy.base()) {
		#ifdef debug
			std::cout << "reverse_iterator_map Parametric constructor(2)" << std::endl;
		#endif
	};

    virtual ~map_reverse_iterator() {};

    template <class It>
		self &operator=(const map_reverse_iterator<It>& other) {
			this->it_ = other.base();
			return *this;
		}

    iterator_type base() const {
      return it_;
    }

    self     &operator ++ () {
      --it_;
      return *this;
    };
    self     operator ++ (int) {
      self tmp = *this;
      --it_;
      return tmp;
    };
    self     &operator -- () {
      ++it_;
      return *this;
    };
    self     operator -- (int) {
      self tmp = *this;
      ++it_;
      return tmp;
    };
    self     operator + (difference_type n) const {
      map_reverse_iterator tmp(*this);
      tmp.it_ -= n;
      return tmp;
    };
    self     operator += (difference_type n) {
      it_ = it_ - n;
      return *this;
    };
    self     operator - (difference_type n) const {
      map_reverse_iterator tmp(*this);
      tmp.it_ += n;
      return tmp;
    };
    self     operator -= (difference_type n) {
      it_ = it_ + n;
      return *this;
    };
    reference     operator [] (difference_type n) const {
      return *(*this + n);
    };

    reference operator * () const {
      iterator_type tmp = it_;
      return *--tmp;
    };
    pointer   operator -> () const {
      iterator_type tmp = it_;
      return &*--tmp;
    };

    template <class It>
    difference_type     operator - (const map_reverse_iterator<It> &x) {
      return x.base().operator-(it_);;
    };

    friend map_reverse_iterator	operator+(difference_type n, const map_reverse_iterator &rhs) {
      return rhs + n;
    };

    template <class It>
    bool	operator==(const map_reverse_iterator<It> &rhs) const { return it_ == rhs.base(); };

    template <class It>
    bool	operator!=(const map_reverse_iterator<It> &rhs) const { return it_ != rhs.base(); };

    template <class It>
    bool	operator<(const map_reverse_iterator<It> &rhs) const { return it_ > rhs.base(); };

    template <class It>
    bool	operator>(const map_reverse_iterator<It> &rhs) const { return it_ < rhs.base(); };

    template <class It>
    bool	operator<=(const map_reverse_iterator<It> &rhs) const { return it_ >= rhs.base(); };

    template <class It>
    bool	operator>=(const map_reverse_iterator<It> &rhs) const { return it_ <= rhs.base(); };

   private:
    iterator_type it_;
  };

}

#endif
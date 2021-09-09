#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft
{
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



  template <class Key, class T, bool isconst = false>
  struct map_iterator {
    typedef map_iterator<Key, T, isconst>   self;

    typedef std::ptrdiff_t                  difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ft::pair<const Key, T>          value_type;
    typedef typename choose_type<isconst,
              const value_type&, value_type&>::type       reference;
    typedef typename choose_type<isconst,
              const value_type*, value_type*>::type       pointer;
    typedef typename choose_type<isconst,
              const s_tree<value_type>*, s_tree<value_type>*>::type   nodeptr;

    map_iterator() : _ptr(NULL) {};
    map_iterator(nodeptr ptr) : _ptr(ptr) {};
    map_iterator(const map_iterator<Key, T, false> &copy) : _ptr(copy._ptr) {};
    map_iterator(const map_iterator<Key, T, true> &copy) : _ptr(copy._ptr) {};

    virtual ~map_iterator() {};

    self     &operator ++ () {
			if (_ptr)
				_ptr = _ptr->right;
			return (*this);
    };

		self operator++(int) { self tmp = *this; ++(*this); return tmp; }
		self& operator--() {
			if (_ptr)
				_ptr = _ptr->left;
			return (*this); 
		}
		self operator--(int) { self tmp = *this; --(*this); return tmp; }
		self& operator=(const self & i) {
			if (this->_ptr != i._ptr) {
				#ifdef _DEBUG_
					std::cout << "it_operator=\n";
				#endif
				_ptr = i._ptr;
			}
			return *this;
		}

    bool      operator == (const self &rhs) const   { return _ptr == rhs._ptr; };
    bool      operator != (const self &rhs) const   { return _ptr != rhs._ptr; };
    reference operator *  () const                  { return _ptr->myPair; };
    pointer   operator -> () const                  { return &_ptr->myPair; };

    nodeptr _ptr;
  };

 template <typename Iterator>
  class reverse_iterator {
   public:
    typedef reverse_iterator    self;
    typedef Iterator            iterator_type;

    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type        value_type;
    typedef typename iterator_traits<iterator_type>::pointer           pointer;
    typedef typename iterator_traits<iterator_type>::reference         reference;
    typedef typename iterator_traits<iterator_type>::difference_type   difference_type;

    reverse_iterator() : it_() {};
    reverse_iterator(const iterator_type copy) : it_(copy) {};

    template <typename It>
    reverse_iterator(const reverse_iterator<It> &copy) : it_(copy.base()) {};

    virtual ~reverse_iterator() {};

    template <class It>
		self &operator=(const reverse_iterator<It>& other) {
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
      reverse_iterator tmp(*this);
      tmp.it_ -= n;
      return tmp;
    };
    self     operator += (difference_type n) {
      it_ = it_ - n;
      return *this;
    };
    self     operator - (difference_type n) const {
      reverse_iterator tmp(*this);
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
    difference_type     operator - (const reverse_iterator<It> &x) {
      return x.base().operator-(it_);;
    };

    friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs) {
      return rhs + n;
    };

    template <class It>
    bool	operator==(const reverse_iterator<It> &rhs) const { return it_ == rhs.base(); };

    template <class It>
    bool	operator!=(const reverse_iterator<It> &rhs) const { return it_ != rhs.base(); };

    template <class It>
    bool	operator<(const reverse_iterator<It> &rhs) const { return it_ > rhs.base(); };

    template <class It>
    bool	operator>(const reverse_iterator<It> &rhs) const { return it_ < rhs.base(); };

    template <class It>
    bool	operator<=(const reverse_iterator<It> &rhs) const { return it_ >= rhs.base(); };

    template <class It>
    bool	operator>=(const reverse_iterator<It> &rhs) const { return it_ <= rhs.base(); };

   private:
    iterator_type it_;
  };
}

#endif
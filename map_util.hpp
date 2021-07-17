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

	  template <class Key, class T, bool isconst = false>
  struct map_iterator {
    typedef map_iterator<Key, T, isconst>   self;

    typedef std::ptrdiff_t                  difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ft::pair<const Key, T>          value_type;
    typedef typename choose_type<isconst,const value_type&, value_type&>::type       reference;
    typedef typename choose_type<isconst,const value_type*, value_type*>::type       pointer;
    typedef typename choose_type<isconst,const Tree<value_type>*, Tree<value_type>*>::type   nodeptr;

    map_iterator() : ptr_(NULL) {};
    map_iterator(nodeptr ptr) : ptr_(ptr) {};
    map_iterator(const map_iterator<Key, T, false> &copy) : ptr_(copy.ptr_) {};
    map_iterator(const map_iterator<Key, T, true> &copy) : ptr_(copy.ptr_) {};

    virtual ~map_iterator() {};

	    nodeptr ptr_;
  };
}

#endif
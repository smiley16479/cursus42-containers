#ifndef SOLAL_UTIL_4_MAP_HPP
#define SOLAL_UTIL_4_MAP_HPP

namespace ft {
	// ITERATOR


//solal ds map.hpp l.29
    typedef ft::map_iterator<key_type, mapped_type>        iterator;
    typedef ft::map_iterator<key_type, mapped_type, true>  const_iterator;
    // typedef ft::reverse_iterator<iterator>                 reverse_iterator;
    // typedef ft::reverse_iterator<const_iterator>           const_reverse_iterator;

	  template <class Key, class T, bool isconst = false>
  struct map_iterator {
    typedef map_iterator<Key, T, isconst>   self;

    typedef std::ptrdiff_t                  difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ft::pair<const Key, T>          value_type;
    // typedef typename choose_type<isconst,const value_type&, value_type&>::type       reference;
    // typedef typename choose_type<isconst,const value_type*, value_type*>::type       pointer;
    // typedef typename choose_type<isconst,const Tree<value_type>*, Tree<value_type>*>::type   nodeptr;

    map_iterator() : ptr_(NULL) {};
    map_iterator(nodeptr ptr) : ptr_(ptr) {};
    map_iterator(const map_iterator<Key, T, false> &copy) : ptr_(copy.ptr_) {};
    map_iterator(const map_iterator<Key, T, true> &copy) : ptr_(copy.ptr_) {};

    virtual ~map_iterator() {};

	    nodeptr ptr_;
  };
}

#endif
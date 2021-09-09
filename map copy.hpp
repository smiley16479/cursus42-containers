/* 
MAP CONÇU AVEC UNE LISTE CHAINÉE PLUTOT QU'UN ARBRE BINAIRE
*/
#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <limits>
#include <stddef.h>
#include <string>

// #define _DEBUG_
	#include <iostream>
	#include "colors.h"
#ifdef _DEBUG_
#endif

// #include "map_util copy.hpp"
#include "map_util_copy2.hpp"


// TRAIT 
// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html 

// BINARY TREE
// https://www.thegeekstuff.com/2013/02/c-binary-tree/
// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
// https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/

namespace ft {

	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = ft::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
	{

	public:

	typedef Key										key_type;	// The first template parameter (Key)	
	typedef T										mapped_type;	// The second template parameter (T)	
	typedef ft::pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef	Compare									key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
    typedef ft::Comp<Compare, value_type>			value_compare;// Nested function class to compare elements see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	typedef	Alloc									allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
	
	typedef typename allocator_type::reference		reference;	// allocator_type::reference for the default allocator: value_type&
	// typedef	value_type&							reference;	// allocator_type::reference for the default allocator: value_type&
	typedef typename allocator_type::const_reference	const_reference;	// allocator_type::reference for the default allocator: value_type&
	// typedef const value_type&						const_reference;	// allocator_type::const_reference for the default allocator: const value_type&
	typedef	typename allocator_type::pointer		pointer; //	allocator_type::pointer	for the default allocator: value_type*
	// typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	typename allocator_type::const_pointer		const_pointer; //	allocator_type::pointer	for the default allocator: value_type*
	// typedef	const value_type*						const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef ft::map_iterator< Key, T >				iterator;  // a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::map_iterator< Key, T, true >	const_iterator; //	a bidirectional iterator to const value_type	
	
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	// typedef iterator	 						reverse_iterator; //	reverse_iterator<iterator>	
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator; 
	// typedef const_iterator						const_reverse_iterator; //	reverse_iterator<const_iterator>	

	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

// (ITERATORS:) defini ici plutot que ds map_utils.hpp car _listBegin non accessible ds map_utils
		iterator begin() { return iterator(_listBegin->right); }
		iterator end()   { return iterator(_listBegin); }
		const_iterator begin() const { return const_iterator(_listBegin->right);}
		const_iterator end() const { return const_iterator(_listBegin);}
		reverse_iterator rbegin() { return reverse_iterator((this->end()));}
		reverse_iterator rend() { return reverse_iterator(this->begin());}
		const_reverse_iterator rbegin() const { return const_reverse_iterator((this->end()));}
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin());}

//Implemented method and // //NON implemented method
	//  CONSTRUCTORS

	// empty (1)	
	// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	// range (2)	
	// // template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	// copy (3)	
	// map (const map& x);
	// ~map();

	// copy (1)	
		// map& operator= (const map& x);

	// CAPACITY:

	// bool empty() const; // Returns whether the map container is empty (i.e. whether its size is 0).
	// size_type size() const; // Return container size
	// size_type max_size() const; // Return maximum size

	// ELEMENT ACCESS:
	// operator[]

	// MODIFIERS:
	// // single element (1)	// insert : Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
	// // pair<iterator,bool> insert (const value_type& val);
	// // with hint (2)	
	// // iterator insert (iterator position, const value_type& val);
	// // range (3)	
	// // template <class InputIterator>
	// //   void insert (InputIterator first, InputIterator last);

	// Removes from the map container either a single element or a range of elements ([first,last)).
	// This effectively reduces the container size by the number of elements removed, which are destroyed.
	// (1) void erase (iterator position);
	// (2) size_type erase (const key_type& k);
	// (3) void erase (iterator first, iterator last);

	// void swap (map& x); // Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
	// void clear(); // Clear content Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.

	// OBSERVERS:
	// // key_compare key_comp() const; // Returns a copy of the comparison object used by the container to compare keys.
	// // value_compare value_comp() const; // Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.

	// OPERATIONS:

// Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
	// iterator find (const key_type& k);
	// const_iterator find (const key_type& k) const;
	
	// size_type count (const key_type& k) const; //Searches the container for elements with a key equivalent to k and returns the number of matches.

// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
	// iterator lower_bound (const key_type& k);
	// const_iterator lower_bound (const key_type& k) const;

// Returns an iterator pointing to the first element in the container whose key is considered to go after k.
	// iterator upper_bound (const key_type& k);
	// const_iterator upper_bound (const key_type& k) const;

// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	// pair<iterator,iterator>             equal_range (const key_type& k);

	// ALLOCATOR:

// Returns a copy of the allocator object associated with the map.
	// allocator_type get_allocator() const;

// BEGIN IMPLEMENTATION
	// Constructs an empty container, with no elements.
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: _keyCmp(comp), _allocTp(alloc), _size(0), _listBegin(NULL)
	{
		#ifdef _DEBUG_
			std::cout << "Default Map Constructor" << std::endl;
		#endif
		_listBegin  = _alloc_node.allocate(1);
		_allocTp.construct(&_listBegin->myPair, value_type());
		_listBegin->left = _listBegin;
		_listBegin->right = _listBegin;
		_listBegin->begin = _listBegin;
	}

	// Constructs a container with as many elements as the range [first,last), 
	// with each element constructed from its corresponding element in that range.
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: _keyCmp(comp), _allocTp(alloc), _size(0), _listBegin(NULL)
	{
		#ifdef _DEBUG_
			std::cout << "InputIterator Map Constructor" << std::endl;
		#endif
		_listBegin  = _alloc_node.allocate(1);
		_allocTp.construct(&_listBegin->myPair, value_type());
		_listBegin->left = _listBegin;
		_listBegin->right = _listBegin;
		_listBegin->begin = _listBegin;
		for (;first != last; ++first)
			this->insert(*first);
	}

	// Constructs a container with a copy of each of the elements in x.
	map (const map& x) : _keyCmp(x.key_comp()), _allocTp(x.get_allocator()), _size(0)
	{
		#ifdef _DEBUG_
			std::cout << "map copy constructor\n";
		#endif
		_listBegin  = _alloc_node.allocate(1);
		_allocTp.construct(&_listBegin->myPair, value_type());
		_listBegin->left = _listBegin;
		_listBegin->right = _listBegin;
		_listBegin->begin = _listBegin;
		// static typename autre<T1, T2>::_index = new s_tree<T1, T2>;
		s_tree<value_type> *temp = x._listBegin;
		while (temp->right != x._listBegin) {
			this->insert(temp->right->myPair);
			temp = temp->right;
		}
	}

	~map()
	{
		#ifdef _DEBUG_
			std::cout << "Default Map Destructor" << std::endl;
		#endif
		delist();
		delete(_listBegin);
	}

	// Copy container content
	// Assigns new contents to the container, replacing its current content.
	 map& operator= (const map& x)
	{
		#ifdef _DEBUG_
			std::cout << "test operator= entre map<key, T>\n";
		#endif
		typename map<Key, T>::const_iterator it = x.begin();
		typename map<Key, T>::const_iterator end = x.end();
		this->clear();
		this->insert(/* x.begin() */it,/* x.end() */end);
		return (*this);
	}

// CAPACITY:
	bool empty() const { return _size ? false : true;}
	size_type size() const { return _size;}
	size_type max_size() const { return _alloc_node.max_size(); }


// ELEMENT ACCESS:
	mapped_type& operator[] (const key_type& k) {
		#ifdef _DEBUG_
				std::cout << RED "operator[]\n" RESET;
		#endif
		return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
	}

// MODIFIERS:

// The single element versions (1) return a pair, with its member pair::first
// set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map.
// The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
	pair<iterator,bool> insert (const value_type& val) {
		s_tree<value_type> *temp = _listBegin;
		pair<iterator,bool> toReturnPair;
		while (temp->right != _listBegin && key_compare()(temp->right->myPair.first, val.first))
			temp = temp->right;
		#ifdef _DEBUG_
			std::cout << GREEN "val.first : " << val.first << " temp->right->myPair.first : " <<
			temp->right->myPair.first << "\n" RESET;
		#endif
		if (temp->right != _listBegin && val.first == temp->right->myPair.first)
		{ 
			#ifdef _DEBUG_
				std::cout << RED "ds Insert si la clef existe déjà\n" RESET;
			#endif
			// _allocTp.construct(&temp->right->myPair, val); // <-- non on ajoute pas d'élément
			iterator it(temp->right);
			toReturnPair.first = it;
			toReturnPair.second = false;
		} else{
			#ifdef _DEBUG_
				std::cout << RED "ds Insert si on ajout un élément\n" RESET;
			#endif
			return addElementList(temp->right, val);}
		return toReturnPair;
	}

	iterator insert (iterator position, const value_type& val) {
		static_cast<void>(position);
		pair<iterator,bool> toReturnPair = insert(val);
		return toReturnPair.first;
	}

template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {std::cout << "inert input" << std::endl;
		for (; first != last; ++first)
			insert(*first);
	}

	void erase (iterator position) {
		#ifdef _DEBUG_
			std::cout << "erase :" << position._ptr->myPair.first << std::endl;
		#endif
		--_size;//ca deconne surement ici lors des suppression d'iterator...
		s_tree<value_type> *temp = position._ptr;
		position._ptr->left->right = position._ptr->right;
		position._ptr->right->left = position._ptr->left;
		position._ptr = position._ptr->left;
		delete (temp);
	}

	size_type erase (const key_type& k) {
		s_tree<value_type>* node = NULL;
		if ((node = ElemExist(k))){
			erase(iterator(node));
			return 1;
		}
		return 0;
	}
	
	void erase (iterator first, iterator last) {
		while (first != last) {
			// std::cout << "erase first : " << first.getPtr() << std::endl;
			iterator tmp = first++;
			erase(tmp);
		}
	}

// Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
	void swap (map& x) {
		size_type size_tmp = x._size;
		key_compare keyCmp_tmp = x._keyCmp;
		allocator_type allocTp_tmp = x._allocTp;
		s_tree<value_type> *listBegin_tmp = x._listBegin;
		x._size = _size;
		x._keyCmp = _keyCmp;
		x._allocTp = _allocTp;
		x._listBegin = _listBegin;
		_size = size_tmp;
		_keyCmp = keyCmp_tmp;
		_allocTp = allocTp_tmp;
		_listBegin = listBegin_tmp;
	}

// Clear content Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
	void clear() {
		delist();
	}

// OBSERVERS:

// Returns a copy of the comparison object used by the container to compare keys.
	key_compare key_comp() const {
		return key_compare();
	}
// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
	value_compare value_comp() const {
		return value_compare();
	} // --> see ligne 41

	iterator find (const key_type& k) {
		s_tree<value_type>* node = ElemExist(k);
		return node ? iterator(node) : iterator(_listBegin);
	}

	const_iterator find (const key_type& k) const {
		return find(k);
	}

	size_type count (const key_type& k) const {
		// return ElemExist(k) ? 1 : 0;
		s_tree<value_type>	*begin = _listBegin;
		while (begin->right != _listBegin) {
			if (begin->right->myPair.first == k)
				return 1;
			begin = begin->right;
		}
		return 0;
	}

// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
	iterator lower_bound (const key_type& k) {
		s_tree<value_type> *temp = _listBegin;
		while (temp->right != _listBegin && key_compare()(temp->right->myPair.first, k))
			temp = temp->right;
		return iterator(temp->right);
	}
	const_iterator lower_bound (const key_type& k) const {
		return lower_bound(k);
	}

// Returns an iterator pointing to the first element in the container whose key is considered to go after k.
	iterator upper_bound (const key_type& k) { //PAS BON : L'IT RETOURNÉ FONCTIONNE QUE SI LA VALEUR DONNÉE EST DS LA MAP
		s_tree<value_type> *temp = _listBegin;
		while (temp->right != _listBegin && key_compare()(temp->right->myPair.first, k))
			temp = temp->right;
		return iterator(temp->right->right);
	}
	const_iterator upper_bound (const key_type& k) const {
		return upper_bound(k);
	}

// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		// const_iterator const_it = find(k);
		// return ft::make_pair(const_it, const_it);
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	pair<iterator,iterator>             equal_range (const key_type& k) {
		// iterator it = find(k);
		// return ft::make_pair(it, it);
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}

// Returns a copy of the allocator object associated with the map.
	allocator_type get_allocator() const {
		return allocator_type();
	}
  
	private:

	key_compare 	_keyCmp;
	allocator_type 	_allocTp;
	size_type		_size;
	s_tree<value_type>	*_listBegin;

	s_tree<value_type>* ElemExist(const key_type& k) {
		s_tree<value_type>	*begin = _listBegin;
		while (begin->right != _listBegin)
			if (begin->right->myPair.first == k)
				return (begin->right);
			else begin = begin->right;
		return NULL;
	}

	void delist() {
		#ifdef _DEBUG_
			std::cout << "listBegin : " << _listBegin << std::endl;
		#endif
		s_tree<value_type> *to_delete , *to_roll = _listBegin->right;
		while (to_roll != _listBegin) {
			to_delete = to_roll;
			to_roll = to_roll->right;
			delete (to_delete);
		}
		_listBegin->right = _listBegin;
		_listBegin->left = _listBegin;
		_size = 0;
	}

	void printList() const {
		s_tree<value_type>	*begin = _listBegin;
		while (begin->right != _listBegin) {
			#ifdef _DEBUG_
			#endif
			std::cout << "ptr : " << begin->right << " : " << begin->right->myPair.first 
			<< "::" << begin->right->myPair.second << std::endl;
			begin = begin->right;
		}
	}
//https://stackoverflow.com/questions/40035282/c-typedef-typename-classnametemplate/40035372
// TYPE DEFINI SPECIFIQUEMENT POUR L'ALLOCATION DE NOEUDS 
    typename allocator_type::template rebind<s_tree<value_type> >::other _alloc_node;

// Add before the passed element
	pair<iterator,bool> addElementList(s_tree<value_type> *elem, const value_type& val) {
		pair<iterator,bool> toReturnPair;
		elem->left->right = createElementList(val);
		elem->left->right->left = elem->left;
		elem->left->right->right= elem;
		elem->left = elem->left->right;
		iterator it(elem->left);
		toReturnPair.first = it;
		toReturnPair.second = true;
		return toReturnPair;
	}

	s_tree<value_type>* createElementList(const value_type& val)
	{//ALLOUE UN NOEUD, INCREMENTE _SIZE OF MAP, INITIALISE PAIR, METS LES ENFANTS A NULL ET RETURN CE NOEUD
		// s_tree<value_type>* node = new s_tree<value_type>;
		s_tree<value_type>* node  = _alloc_node.allocate(1);
		++_size;
		_allocTp.construct(&node->myPair, val);
		node->left  = NULL;
		node->right = NULL;
		node->begin = _listBegin;
		return node;
	}

	s_tree<value_type>* getLowest() {
			return _listBegin->right;
		}

	s_tree<value_type>* getHighest() {
		return _listBegin->left;
	}

	};

	template<typename Key, typename T>
	std::ostream& operator <<(std::ostream &o, ft::map<Key, T> &x) { o << x.getStr() << std::endl; return o;}

  template <class Key, class T>
  bool operator== (const map<Key, T>& lhs, const map<Key, T>& rhs) {
	#ifdef _DEBUG_
		std::cout << "operator== map" << std::endl;
	#endif
    if (lhs.size() != rhs.size())
      return false;
    typename map<Key, T>::const_iterator it1 = lhs.begin(), lhs_end = lhs.end();
    typename map<Key, T>::const_iterator it2 = rhs.begin(), rhs_end = rhs.end();

    while (it1 != lhs_end && it2 != rhs_end) {
      if (*it1 != *it2)
        return false;
      it1++;
      it2++;
    }
    return (it1 == lhs_end) && (it2 == rhs_end);
  };

  template <class Key, class T>
  bool operator!= (const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(lhs == rhs); };

  template <class Key, class T>
  bool operator<  (const map<Key, T>& lhs, const map<Key, T>& rhs) {
    typename map<Key, T>::const_iterator it1 = lhs.begin(), lhs_end = lhs.end();
    typename map<Key, T>::const_iterator it2 = rhs.begin(), rhs_end = rhs.end();

    while (it1 != lhs_end && it2 != rhs_end) {
      if (*it1 < *it2)
        return true;
      if (*it2 < *it1)
        return false;
      it1++;
      it2++;
    }
    return (it1 == lhs_end) && (it2 != rhs_end);
  };

  template <class Key, class T>
  bool operator<= (const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(rhs < lhs); };

  template <class Key, class T>
  bool operator>  (const map<Key, T>& lhs, const map<Key, T>& rhs) { return rhs < lhs; };

  template <class Key, class T>
  bool operator>= (const map<Key, T>& lhs, const map<Key, T>& rhs) { return !(lhs < rhs); };

}

#endif

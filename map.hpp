#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <limits>
#include <stddef.h>

#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#include "colors.h"
// #include "map_util.hpp"
#endif

// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html 

namespace ft {

	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           > class map
	{

	public:

	template <typename T1, typename T2>
	class pair
	{
		public :

		pair () : t1(), t2() {};

		private :
		T1 t1;
		T2 t2;
	};

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

	// template<class T1, class T2>
/* 	class autre {
		public :
		autre() { 
			_index.myPair.t1 = int(1);
			_index.myPair.t2 = int(2);
			_index.parent	= NULL;
			_index.left  	= NULL;
			_index.right 	= NULL;
		}
		private :
		s_tree _index; // index de recherche rapide
	};  */

	// template<class T1, class T2>
	// autre<T1, T2> _index;

	// template<class T1, class T2>
	// s_tree<T1, T2>* _index;

	public:

	typedef Key									key_type;	// The first template parameter (Key)	
	typedef T									mapped_type;	// The second template parameter (T)	
	typedef pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef	Compare								key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
	//? typedef		value_compare	// Nested function class to compare elements	see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	typedef	Alloc								allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
	typedef	value_type&							reference;	// allocator_type::reference	for the default allocator: value_type&
	typedef const value_type&					const_reference;	// allocator_type::const_reference	for the default allocator: const value_type&
	typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*					const_pointer; //	allocator_type::const_pointer	for the default allocator: const value_type*

	// typedef									iterator	// a bidirectional iterator to value_type	convertible to const_iterator
	// typedef									const_iterator //	a bidirectional iterator to const value_type	
	// typedef									reverse_iterator //	reverse_iterator<iterator>	
	// typedef									const_reverse_iterator //	reverse_iterator<const_iterator>	
	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

	// typename ft::map< Key, T, Compare, Alloc>:: ;

	// typedef typename std::stack<T>::container_type::iterator iterator;
	// typedef typename ft::map< Key, T, Compare, Alloc>::pair<T1, T2> pair;
	// typedef typename ft::map< Key, T, Compare, Alloc>::s_	

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
	: _keyCmp(comp), _allocTp(alloc), _size(0)
	{
		std::cout << "Default Map Constructor" << std::endl;
		_mapTree = new s_tree;
		_mapTree->myPair.t1 = "foo";
		_mapTree->myPair.t2 = int(1);
		_mapTree->parent = NULL;
		_mapTree->left = NULL;
		_mapTree->right = NULL;
	}

	// Constructs a container with as many elements as the range [first,last), 
	// with each element constructed from its corresponding element in that range.
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		// autre<T1, T2>::_index = new s_tree<T1, T2>;
		// _index = new s_tree<T1, T2>;
		std::cout << "InputIterator Map Constructor" << std::endl;
	}

	// Constructs a container with a copy of each of the elements in x.
	map (const map& x)
	{
		// static typename autre<T1, T2>::_index = new s_tree<T1, T2>;
		// _index = new s_tree<T1, T2>;
	}

	~map()
	{
	}

	// Copy container content
	// Assigns new contents to the container, replacing its current content.
	 map& operator= (const map& x)
	{

	}

	bool empty() const { return _size ? true : false;}
	size_type size() const { return _size;}
	size_type max_size() const { return _allocTp.max_size(); }

	private:

	key_compare 	_keyCmp;
	allocator_type 	_allocTp;
	size_type		_size;
	s_tree<Key, T>	*_mapTree;

	};

}

#endif
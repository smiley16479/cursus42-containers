#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <limits>
#include <stddef.h>
#include <string>

#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#include "colors.h"
#include "map_util.hpp"
#endif


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
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
	{

	public:

// Why is there no redefinition error (already difined in map_utils.hpp) if I uncomment this struct ?
/* 	template<class T1, class T2>
	struct s_tree
	{
		// typename ft::map< Key, T, Compare, Alloc>:: ;
		// ft::map<Key , T , Compare, Alloc>::
		pair<T1, T2> myPair;
		s_tree* parent;
		s_tree* left;
		s_tree* right;
	}; */

	typedef Key									key_type;	// The first template parameter (Key)	
	typedef T									mapped_type;	// The second template parameter (T)	
	typedef ft::pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef	Compare								key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
	//? typedef		value_compare	// Nested function class to compare elements see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	typedef	Alloc								allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
	
	// typedef allocator_type::reference			reference;	// allocator_type::reference for the default allocator: value_type&
	typedef	value_type&							reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&					const_reference;	// allocator_type::const_reference for the default allocator: const value_type&
	typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*					const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

	typedef ft::map_iterator< Key, T >			iterator;
	typedef const iterator						const_iterator;
	typedef iterator	 						reverse_iterator;
	typedef const_iterator						const_reverse_iterator;

	// typedef									iterator	// a bidirectional iterator to value_type convertible to const_iterator
	// typedef									const_iterator //	a bidirectional iterator to const value_type	
	// typedef									reverse_iterator //	reverse_iterator<iterator>	
	// typedef									const_reverse_iterator //	reverse_iterator<const_iterator>	
	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

	// typename ft::map< Key, T, Compare, Alloc>:: ;

	// typedef typename std::stack<T>::container_type::iterator iterator;
	// typedef typename ft::map< Key, T, Compare, Alloc>::pair<T1, T2> pair;
	// typedef typename ft::map< Key, T, Compare, Alloc>::s_	

// (ITERATORS:) defini ici plutot que ds map_utils.hpp car _mapTree non accessible ds map_utils
		iterator begin() { s_tree<Key, T> *temp = _mapTree;
			while (temp->left) temp = temp->left;
			return iterator(temp); }
		const_iterator begin() const { return this->begin();}
		iterator end()   { s_tree<Key, T> *temp = _mapTree;
			while (temp->right) temp = temp->right;
			return iterator(temp); }
		const_iterator end() const { return this->end();}
		reverse_iterator rbegin() { return this->end();}
		const_reverse_iterator rbegin() const { return this->end();}
		reverse_iterator rend() { return this->begin();}
		const_reverse_iterator rend() const { return this->begin();}

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
		_mapTree = new s_tree<Key, T>;
		_mapTree->myPair.first = 'f';
		_mapTree->myPair.second = int(2);
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
		std::cout << "Default Map Destructor" << std::endl;
		deltree(_mapTree);
	}

	// Copy container content
	// Assigns new contents to the container, replacing its current content.
	 map& operator= (const map& x)
	{
		// if (_mapTree->left)
		// while (_mapTree->left || _mapTree->right)
	}

// CAPACITY:
	bool empty() const { return _size ? true : false;}
	size_type size() const { return _size;}
	size_type max_size() const { return _allocTp.max_size(); }


// ELEMENT ACCESS:
	// operator[]

// MODIFIERS:

// The single element versions (1) return a pair, with its member pair::first
// set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map.
// The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
	pair<iterator,bool> insert (const value_type& val) {
		s_tree<Key, T> *temp = _mapTree;
		pair<iterator,bool> toReturnPair;
		while (temp) { // Si on tombe sur la même clefs
			if (val.first == temp->myPair.first) { 
				temp->myPair.second = val.second;
				iterator it(temp);
				toReturnPair.first = it;
				toReturnPair.second = false;
				return toReturnPair;
			} // Sinon
			if (std::less<Key>()(val.first, temp->myPair.first)) {
				if (!temp->left) {
					temp->left = addNode(val);
					iterator it(temp->left);
					toReturnPair.first = it;
					toReturnPair.second = true;
					return toReturnPair;
				}
				temp = temp->left;
			}
			else {
				if (!temp->right) {
					temp->right = addNode(val);
					iterator it(temp->right);
					toReturnPair.first = it;
					toReturnPair.second = true;
					return toReturnPair;
				}
				temp = temp->right;
			}
		}
		temp = addNode(val);
		iterator it(temp);
		toReturnPair.first = it;
		toReturnPair.second = false;
		return toReturnPair;
	}

	iterator insert (iterator position, const value_type& val) {
		pair<iterator,bool> toReturnPair = insert(val);
		return toReturnPair.first;
	}

template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		for (; first != last; ++first)
			insert(*first);
	}

	// to erase
	Key getStr() { return _mapTree->myPair.first;}


	void print_preorder(s_tree<Key, T> * tree) {
		if (tree) {
		printf("%d\n",tree->myPair.first);
		print_preorder(tree->left);
		print_preorder(tree->right);
		}
	}
	
	void print_inorder(s_tree<Key, T> * tree) {
		// #ifdef _DEBUG_
		// 	std::cout << "mapTree _ptr : " << tree << std::endl;
		// #endif
		if (tree) {
		print_inorder(tree->left);
		printf("%c\n",tree->myPair.first);
		print_inorder(tree->right);
		}
	}
	
	void print_postorder(s_tree<Key, T> * tree) {
		if (tree) {
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("%d\n",tree->myPair.first);
		}
	}

	void deltree(s_tree<Key, T> * tree) {
		if (tree) {
		  deltree(tree->left);
		  deltree(tree->right);
		  delete (tree);
		}
	}

	s_tree<Key, T>	* getTree(){return _mapTree;}

	private:

	key_compare 	_keyCmp;
	allocator_type 	_allocTp;
	size_type		_size;
	s_tree<Key, T>	*_mapTree;

	s_tree<Key, T>* addNode(const value_type& val) {
		s_tree<Key, T>* node = new s_tree<Key, T>;
		// s_tree<Key, T>* node  = _allocTp.allocate(_size); // <- essai d'ajout d'allocator perso À VIRER
		++_size;
		node->myPair.first = val.first;
		node->myPair.second = val.second;
		node->left  = NULL;
		node->right = NULL;
		return node;
	}

	};

	template<typename Key, typename T>
	std::ostream& operator <<(std::ostream &o, ft::map<Key, T> &x) { o << x.getStr() << std::endl; return o;}

}

#endif
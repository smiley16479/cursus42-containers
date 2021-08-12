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
           class Alloc = ft::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
	{

	public:

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
		iterator begin() { ft::s_tree<value_type> *temp = _mapTree;
			while (temp->left) temp = temp->left;
			return iterator(temp); }
		const_iterator begin() const { return this->begin();}
		iterator end()   { ft::s_tree<value_type> *temp = _mapTree;
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
	: _keyCmp(comp), _allocTp(alloc), _size(0), _mapTree(NULL)
	{
		#ifdef _DEBUG_
			std::cout << "Default Map Constructor" << std::endl;
		#endif
		_mapTree  = _alloc_node.allocate(1);
		_allocTp.construct(&_mapTree->myPair, value_type());
		_mapTree->parent = NULL;
		_mapTree->left = _mapTree;
		_mapTree->right = _mapTree;
	}

	// Constructs a container with as many elements as the range [first,last), 
	// with each element constructed from its corresponding element in that range.
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		// autre<T1, T2>::_index = new s_tree<T1, T2>;
		// _index = new s_tree<T1, T2>;
		std::cout << "InputIterator Map Constructor" << std::endl;
		for (;first != last; ++first)
			createNode(*first);
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
		s_tree<value_type> *temp = _mapTree;
		pair<iterator,bool> toReturnPair;
		if (!_size) { std::cout << RED "ds Insert Si map est vide\n" RESET;
			temp = createNode(val);
			temp->parent = NULL;
			temp->left = NULL;
			temp->right = _mapTree;
			_mapTree->parent = temp;
			_mapTree->left = NULL;
			_mapTree->right = NULL;
			_mapTree = temp;
			iterator it(temp);
			toReturnPair.first = it;
			toReturnPair.second = true;
			return toReturnPair;
		}
		while (temp) { 
			if (val.first == temp->myPair.first) {std::cout << RED "ds Insert Si on tombe sur la même clefs\n" RESET;
				temp->myPair.second = val.second;
				iterator it(temp);
				toReturnPair.first = it;
				toReturnPair.second = false;
				return toReturnPair;
			} // Sinon
			else if (key_compare()(val.first, temp->myPair.first) /* std::less<Key>()(val.first, temp->myPair.first) */) {
				if (!temp->left) { std::cout << RED "ds Insert less\n" RESET;
					return addNode(temp, 0 , val);
/* 					temp->left = createNode(val);
					temp->left->parent = temp;
					iterator it(temp->left);
					toReturnPair.first = it;
					toReturnPair.second = true;
					return toReturnPair; */
				}
				temp = temp->left;
			}
			else {
				if (!temp->right) { std::cout << RED "ds Insert more\n" RESET;
					if (temp->parent == getHighest(_mapTree)){
						s_tree<value_type> *temp1 = temp;
						temp = temp->parent;

						temp->right = createNode(val);
						temp->right->parent = temp;
						iterator it(temp->right);

						temp1->parent = temp->right;
						temp->right->right = temp1;

						toReturnPair.first = it;
						toReturnPair.second = true;
						return toReturnPair;
					} else
						return addNode(temp, 1 , val);
				}
				temp = temp->right;
			}
		} // S'il n'y a pas d'éléments et que temp == NULL
		std::cout << RED "ds Insert S'il n'y a pas d'éléments\n" RESET;
		_mapTree = createNode(val);
		_mapTree->parent = NULL;
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


	void erase (iterator position) { std::cout << "erase :" << position._ptr->myPair.first << std::endl;
		--_size;
		s_tree<value_type> *temp = position._ptr;
		if (position._ptr->left && position._ptr->right) { std::cout << "erase_if\n";
			position._ptr = position._ptr->left;
			while (position._ptr->right)
				position._ptr = position._ptr->right;
			_allocTp.construct(&temp->myPair, position._ptr->myPair);
			if (position._ptr->left)
				position._ptr->left->parent = position._ptr->parent;
			position._ptr->parent->right = position._ptr->left;
			delete (position._ptr);
		}
		else if (!position._ptr->left) { std::cout << "erase_else_if::1\n";//celui la deconne
			if (position._ptr->parent->left == position._ptr) {std::cout << "erase_if\n"; 
				position._ptr->parent->left = position._ptr->right;
			}
			else if (position._ptr->parent->right == position._ptr) {std::cout << "erase_else_if\n";
				position._ptr->parent->right = position._ptr->right;
			}
			if (position._ptr->right) // au cas ou il y ait une feuille droite
				position._ptr->right->parent = position._ptr->parent;
			delete (position._ptr);
		}
		else if (!position._ptr->right) { std::cout << "erase_else_if::2\n";
			s_tree<value_type> *to_erase = position._ptr->left;
			_allocTp.construct(&temp->myPair, temp->left->myPair);
			temp->right = temp->left->right;
			temp->left = temp->left->left;
			if (temp->right)
				temp->right->parent = temp;
			if (temp->left)
				temp->left->parent = temp;
			delete (to_erase);
		}
	}

	size_type erase (const key_type& k) {
		s_tree<value_type>* node = NULL;
		if ((node = nodeExist(_mapTree, k))){
			erase(iterator(node));
			return 1;
		}
		return 0;
	}
	
	void erase (iterator first, iterator last) {
		while (first != last && first != this->end()) {
			std::cout << "erase first : " << first.getPtr() << std::endl;
			iterator tmp = first++;
			erase(tmp);
		}
	}

// Returns a copy of the comparison object used by the container to compare keys.
	key_compare key_comp() const {
		return key_compare();
	}
// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
	// value_compare value_comp() const {
	// 	return value_comp;
	// } --> see ligne 41

	iterator find (const key_type& k) {
		s_tree<value_type>* node = nodeExist(_mapTree, k);
		return node ? iterator(node) : iterator(getHighest(_mapTree)->right);
	}

	const_iterator find (const key_type& k) const {
		return find(k);
	}

	size_type count (const key_type& k) const {
		s_tree<value_type>* node = nodeExist(_mapTree, k);
		return node ? 1 : 0;
	}

// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
	iterator lower_bound (const key_type& k) {
		return --find(k);
	}
	const_iterator lower_bound (const key_type& k) const {
		return --find(k);
	}

// Returns an iterator pointing to the first element in the container whose key is considered to go after k.
	iterator upper_bound (const key_type& k) { //PAS BON : L'IT RETOURNÉ FONCTIONNE QUE SI LA VALEUR DONNÉE EST DS LA MAP
		return (++find(k));
	}
	const_iterator upper_bound (const key_type& k) const {
		return ++find(k);
	}

// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		const_iterator const_it = find(k);
		return ft::make_pair(const_it, const_it);
	}
	pair<iterator,iterator>             equal_range (const key_type& k) {
		iterator it = find(k);
		return ft::make_pair(it, it);
	}

// Returns a copy of the allocator object associated with the map.
	allocator_type get_allocator() const {
		return _allocTp;
	}

	// to erase
	Key getStr() { return _mapTree->myPair.first;}


	void print_preorder(s_tree<value_type> * tree) {
		if (tree) {
		// printf("%d\n",tree->myPair.first);
		print_ptrs(tree);
		print_preorder(tree->left);
		print_preorder(tree->right);
		}
	}

	s_tree<value_type>* nodeExist(s_tree<value_type> * tree, const key_type& k) {
		s_tree<value_type>* end = getHighest(_mapTree)->right;
		while (tree &&  tree != end) {
			if (k == tree->myPair.first)
				return tree;
			if (k < tree->myPair.first)
				tree = tree->left;
			else tree = tree->right;
		}
		return NULL;
	}

	void print_inorder(s_tree<value_type> * tree) {
		// #ifdef _DEBUG_
		// 	std::cout << "inorder _ptr : " << tree;
		// #endif
		if (tree) {
		print_inorder(tree->left);
		print_ptrs(tree);
		// printf("inorder _ptr : %p, %c\n", tree, tree->myPair.first);
		print_inorder(tree->right);
		}
	}
	



	void print_postorder(s_tree<value_type> * tree) {
		if (tree) {
		print_postorder(tree->left);
		print_postorder(tree->right);
		// printf("%d\n",tree->myPair.first);
		print_ptrs(tree);
		}
	}

	void deltree(s_tree<value_type> * tree) {
		if (tree) {
		#ifdef _DEBUG_
			std::cout << "deltree :" << tree << /* " " << tree->myPair.first << "::" << tree->myPair.second << */ std::endl;
		#endif
		  deltree(tree->left);
		  deltree(tree->right);
		  delete (tree);
		}
	}

	void print_ptrs(s_tree<value_type> * tree) {
		if (tree) {
			std::cout << CYAN "_ptr : " << tree << " " << tree->myPair.first << "::" << tree->myPair.second << std::endl << 
			"_ptr_parent : " << tree->parent << "_ptr_left : " << tree->left << 
			"_ptr_right : " << tree->right << RESET << std::endl;
		}
	}

	s_tree<value_type>	* getTree(){return _mapTree;}

	void print2dTree(s_tree<value_type> * r, int space) {
		if (r == NULL)
			return ;
		space += 5;
		print2dTree(r->right, space);
		std::cout << std::endl;
		for (int i = 5; i < space; ++i)
			std::cout << " ";
		std::cout << r->myPair.second << std::endl;
		print2dTree(r->left, space);
	}


	private:

	key_compare 	_keyCmp;
	allocator_type 	_allocTp;
	size_type		_size;
	s_tree<value_type>	*_mapTree;

// TYPE DEFINI SPECIFIQUEMENT POUR L'ALLOCATION DE NOEUDS
    typename allocator_type::template rebind<s_tree<value_type>>::other _alloc_node;

	pair<iterator,bool> addNode(s_tree<value_type> *temp, bool right, const value_type& val) {
		pair<iterator,bool> toReturnPair;
		right ? temp->right = createNode(val) : temp->left = createNode(val);
		right ? temp->right->parent = temp : temp->left->parent = temp;
		iterator it(right ? temp->right : temp->left);
		toReturnPair.first = it;
		toReturnPair.second = true;
		return toReturnPair;
	}

	s_tree<value_type>* createNode(const value_type& val)
	{//ALLOUE UN NOEUD, INCREMENTE _SIZE OF MAP, INITIALISE PAIR, METS LES ENFANTS A NULL ET RETURN CE NOEUD
		// s_tree<value_type>* node = new s_tree<value_type>;
		s_tree<value_type>* node  = _alloc_node.allocate(1);
		++_size;
		_allocTp.construct(&node->myPair, val);
		node->left  = NULL;
		node->right = NULL;
		return node;
	}

	s_tree<value_type>* getLowest(s_tree<value_type>* node) {
			while (node->parent)
				node = node->parent;
			while (node->left)
				node = node->left;
			return node->parent;
		}

	s_tree<value_type>* getHighest(s_tree<value_type>* node) {
			while (node->parent)
				node = node->parent;
			while (node->right)
				node = node->right;
			return node->parent;
	}

	};

	template<typename Key, typename T>
	std::ostream& operator <<(std::ostream &o, ft::map<Key, T> &x) { o << x.getStr() << std::endl; return o;}

}

#endif

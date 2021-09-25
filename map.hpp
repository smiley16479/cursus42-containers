#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <limits>
#include <stddef.h>
#include <string>

#include <iostream>
#include "colors.h"
#include "map_util.hpp"
// #define _DEBUG_
#ifdef _DEBUG_
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

	typedef Key									key_type;	// The first template parameter (Key)	
	typedef T									mapped_type;	// The second template parameter (T)	
	typedef ft::pair<const key_type,mapped_type>	value_type;	// pair<const key_type,mapped_type>	
	typedef s_tree<value_type> 					Node;
	typedef	Compare								key_compare;	// The third template parameter (Compare)	defaults to: less<key_type>
	//? typedef		value_compare	// Nested function class to compare elements see value_comp -> // http://www.cplusplus.com/reference/map/map/value_comp/
	typedef	Alloc								allocator_type;	// The fourth template parameter (Alloc)	defaults to: allocator<value_type>
	
	// typedef allocator_type::reference			reference;	// allocator_type::reference for the default allocator: value_type&
	typedef	value_type&							reference;	// allocator_type::reference for the default allocator: value_type&
	typedef const value_type&					const_reference;	// allocator_type::const_reference for the default allocator: const value_type&
	typedef	value_type*							pointer; //	allocator_type::pointer	for the default allocator: value_type*
	typedef	const value_type*					const_pointer; //	allocator_type::const_pointer for the default allocator: const value_type*

/* 	typedef ft::map_iterator< Key, T >			iterator; //  a bidirectional iterator to value_type convertible to const_iterator
	typedef const iterator						const_iterator; // a bidirectional iterator to const value_type	
	typedef iterator	 						reverse_iterator; // reverse_iterator<iterator>	
	typedef const_iterator						const_reverse_iterator; // reverse_iterator<const_iterator>	 */

	typedef ft::map_iterator< Key, T >				iterator;  // a bidirectional iterator to value_type convertible to const_iterator
	typedef ft::map_iterator< Key, T, true >	const_iterator; //	a bidirectional iterator to const value_type	
	// typedef ft::map_reverse_iterator<iterator>			reverse_iterator;
	// typedef ft::map_reverse_iterator<const_iterator>	const_reverse_iterator;

	typedef	ptrdiff_t							difference_type; //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	typedef	size_t								size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

	// typename ft::map< Key, T, Compare, Alloc>:: ;

	// typedef typename std::stack<T>::container_type::iterator iterator;
	// typedef typename ft::map< Key, T, Compare, Alloc>::pair<T1, T2> pair;
	// typedef typename ft::map< Key, T, Compare, Alloc>::s_	

// (ITERATORS:) defini ici plutot que ds map_utils.hpp car _mapTree non accessible ds map_utils
	iterator begin() {
		Node *n = _mapTree;
		while (n && n->left)
			n = n->left;
		return iterator(n, &_mapTree);
	}
	iterator end()   { return iterator(NULL, &_mapTree); }
	const_iterator begin() const {
		Node *n = _mapTree;
		while (n && n->left)
			n = n->left;
		return const_iterator(n, &_mapTree);
	}
	const_iterator end() const { return const_iterator(NULL, &_mapTree);}
	/* PAS ENCORE AJUSTÉS */
	// reverse_iterator rbegin() { return iterator(_mapTree);}
	// const_reverse_iterator rbegin() const { return iterator(_mapTree);}
	// reverse_iterator rend() { return iterator(_mapTree->left);}
	// const_reverse_iterator rend() const { return iterator(_mapTree->left);}

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
	}

	// Constructs a container with as many elements as the range [first,last), 
	// with each element constructed from its corresponding element in that range.
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: _keyCmp(comp), _allocTp(alloc), _size(0), _mapTree(NULL)
	{
		#ifdef _DEBUG_
			std::cout << "InputIterator Map Constructor" << std::endl;
		#endif
		
		for (;first != last; ++first )
			// createNode(*first);
			insertValueIteratif(make_pair(first->first, first->second));
	}

	// Constructs a container with a copy of each of the elements in x.
	map (const map& x) : _keyCmp(x.key_comp()), _allocTp(x.get_allocator()), _mapTree(NULL), _size(0)
	{
		#ifdef _DEBUG_
			std::cout << "Map Copy Constructor" << std::endl;
		#endif
		// std::cout << "Map copy : _mapTree->left : " << x._mapTree << ":" << x._mapTree->left << std::endl;
		const_iterator it = x.begin(); // <- problem on est ds une infinite loop car x n'a pas été rempli correctement et que (x._mapTree == x._mapTree->left)
		const_iterator end = x.end();
		this->insert(it,end);
	}

	~map()
	{
		#ifdef _DEBUG_
			std::cout << "Default Map Destructor" << std::endl;
			std::cout << "_mapTree : " << (_mapTree /* = this->getRoot(_mapTree->right) */) << "\n";
		#endif
		deleteTree(_mapTree);
	}

	// Copy container content
	// Assigns new contents to the container, replacing its current content.
	 map& operator= (const map& x)
	{
			std::cout << "Map operator=" << std::endl;
		#ifdef _DEBUG_
		#endif
		iterator it = x.begin();
		iterator end = x.end();
		this->clear();
		this->insert(/* x.begin() */it,/* x.end() */end);
		return (*this);
	}

// CAPACITY:
	bool empty() const { return _size ? false :  true;}
	size_type size() const { return _size;}
	size_type max_size() const { return _allocTp.max_size(); }


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
// 		Node *temp = _mapTree;
// 		pair<iterator,bool> toReturnPair;
// 		if (!_size) { std::cout << RED "ds Insert Si map est vide\n" RESET;
// 			temp = createNode(val);
// 			temp->parent = NULL;
// 			temp->left = NULL;
// 			temp->right = _mapTree;
// 			_mapTree->parent = temp;
// 			_mapTree->left = NULL;
// 			_mapTree->right = NULL;
// 			_mapTree = temp;
// 			iterator it(temp);
// 			toReturnPair.first = it;
// 			toReturnPair.second = true;
// 			return toReturnPair;
// 		}
// 		while (temp) { 
// 			if (val.first == temp->myPair.first) {std::cout << RED "ds Insert Si on tombe sur la même clefs\n" RESET;
// 				temp->myPair.second = val.second;
// 				iterator it(temp);
// 				toReturnPair.first = it;
// 				toReturnPair.second = false;
// 				return toReturnPair;
// 			} // Sinon
// 			else if (key_compare()(val.first, temp->myPair.first) /* std::less<Key>()(val.first, temp->myPair.first) */) {
// 				if (!temp->left) { std::cout << RED "ds Insert less\n" RESET;
// 					return addNode(temp, 0 , val);
// /* 					temp->left = createNode(val);
// 					temp->left->parent = temp;
// 					iterator it(temp->left);
// 					toReturnPair.first = it;
// 					toReturnPair.second = true;
// 					return toReturnPair; */
// 				}
// 				temp = temp->left;
// 			}
// 			else {
// 				if (!temp->right) { std::cout << RED "ds Insert more\n" RESET;
// 					if (temp->parent == getHighest(_mapTree)){
// 						Node *temp1 = temp;
// 						temp = temp->parent;

// 						temp->right = createNode(val);
// 						temp->right->parent = temp;
// 						iterator it(temp->right);

// 						temp1->parent = temp->right;
// 						temp->right->right = temp1;

// 						toReturnPair.first = it;
// 						toReturnPair.second = true;
// 						return toReturnPair;
// 					} else
// 						return addNode(temp, 1 , val);
// 				}
// 				temp = temp->right;
// 			}
// 		} // S'il n'y a pas d'éléments et que temp == NULL
// 		std::cout << RED "ds Insert S'il n'y a pas d'éléments\n" RESET;
// 		_mapTree = createNode(val);
// 		_mapTree->parent = NULL;
// 		iterator it(temp);
// 		toReturnPair.first = it;
// 		toReturnPair.second = false;
// 		return toReturnPair;

/* AJOUT */
	#ifdef _DEBUG_
		std::cout << RED "insert(1)\n" RESET;
	#endif
	return insertValueIteratif(val);

	}

	iterator insert (iterator position, const value_type& val) {
		static_cast<void>(position);
		#ifdef _DEBUG_
			std::cout << RED "insert(2)\n" RESET;
		#endif
		return insert(val).first;
	}

template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		#ifdef _DEBUG_
			std::cout << RED "insert(3)\n" RESET;
		#endif
		for (; first != last; ++first)
			insert(*first);
	}


	void erase (iterator position) { 
		#ifdef _DEBUG_
			std::cout << "erase :" << position._ptr->myPair.first << std::endl;
		#endif
		deleteValue(position->first);
	}

	size_type erase (const key_type& k) {
		Node* node = NULL;
		if ((node = nodeExist(_mapTree, k))){
			erase(iterator(node, &_mapTree));
			// std::cout << "smt erased\n";
			return 1;
		}
		// std::cout << "nothong erased\n";
		return 0;
	}
	
	void erase (iterator first, iterator last) {
/*		iterator tmp_last = last;
		print2dTree(_mapTree);
 		std::cout << "tmp_last ptr/val : " << tmp_last._ptr << "/" << tmp_last->first << std::endl;
		std::cout << "size : " << size() << "\n";
		std::cout << "last ptr/val : " << last._ptr << "\n/" 
		<< last->first << "\n/" 
		<< last._ptr->right << std::endl; */
		// int i(0);
		while (first != last) {
			// std::cout << "erase first : " << first.getPtr() << std::endl;
			iterator tmp = first++;
			// if (first == last){
			// 	print2dTree(_mapTree->parent);
			// 	return;
			// 	}
			// std::cout << "erase boucle : " << ++i << "\n";
			// print2dTree(_mapTree);
			erase(tmp);
		}
	}

	// Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
	void swap (map& x) {
		size_type size_tmp = x._size;
		key_compare keyCmp_tmp = x._keyCmp;
		allocator_type allocTp_tmp = x._allocTp;
		Node *mapTree_tmp = x._mapTree;
		x._size = _size;
		x._keyCmp = _keyCmp;
		x._allocTp = _allocTp;
		x._mapTree = _mapTree;
		_size = size_tmp;
		_keyCmp = keyCmp_tmp;
		_allocTp = allocTp_tmp;
		_mapTree = mapTree_tmp;
	}

	void clear() {
		// delist();
		if (_size)
			deleteTree(_mapTree);
		_mapTree = NULL;
		_size = 0;
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
		Node* node = nodeExist(_mapTree, k);
		return node ? iterator(node, &_mapTree) : iterator(NULL, &_mapTree);
	}

	const_iterator find (const key_type& k) const {
		return find(k);
	}

	size_type count (const key_type& k) const {
/* 		Node* node = nodeExist(_mapTree, k);
		return node ? 1 : 0;
 */
		const_iterator it = begin();
		const_iterator it_end = end();
		while (it != it_end) {
			if (it->first == k)
				return 1;
			++it;
		}
		return 0;
	}

// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
	iterator lower_bound (const key_type& k) {
		// return find(k);
		// COpy de map listChainée à modifier
/* 		Node *temp = _mapTree->; 
		while (temp->right != _mapTree && key_compare()(temp->right->myPair.first, k))
			temp = temp->right;
		return iterator(temp->right); */
	
		iterator it = begin();
		iterator it_end = end();
		while (it != it_end && key_compare()(it->first, k))
			++it;
		return(it);
	}

	const_iterator lower_bound (const key_type& k) const {
		return find(k);
	}

// Returns an iterator pointing to the first element in the container whose key is considered to go after k.
	iterator upper_bound (const key_type& k) { //PAS BON : L'IT RETOURNÉ FONCTIONNE QUE SI LA VALEUR DONNÉE EST DS LA MAP
		// return (++find(k));
		iterator it = begin();
		iterator it_end = end();
		while (it != it_end && key_compare()(it->first, k))
			++it;
		return(++it);
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
		return allocator_type();
	}

	// to erase
	Key getStr() { return _mapTree->myPair.first;}


	void print_preorder(Node * tree) {
		if (tree) {
			// printf("%d\n",tree->myPair.first);
			print_ptrs(tree);
			print_preorder(tree->left);
			print_preorder(tree->right);
		}
	}

	Node* nodeExist(Node * tree, const key_type& k) {
		static_cast<void>(tree);
		// Node* end = getHighest(_mapTree)->right;
		Node* start = getLowest(_mapTree);
		while (start &&  start != NULL) {
			if (k == start->myPair.first)
				return start;
			if (k < start->myPair.first)
				start = start->left;
			else start = start->right;
		}
		return NULL;
	}

	void deltree(Node * tree) {
		if (tree) {
			#ifdef _DEBUG_
				std::cout << "deltree :" << tree << /* " " << tree->myPair.first << "::" << tree->myPair.second << */ std::endl;
			#endif
			if (tree->left != _mapTree)
				deltree(tree->left);
			if (tree->right != _mapTree)
				deltree(tree->right);
			delete (tree);
		}
		delete (_mapTree);
	}

	void print_ptrs(Node * tree) {
		if (tree) {
			#ifdef _DEBUG_
				std::cout << CYAN "_ptr : " << tree << " " << tree->myPair.first << "::" << tree->myPair.second << std::endl << 
			#endif
			"_ptr_parent : " << tree->parent << "_ptr_left : " << tree->left << 
			"_ptr_right : " << tree->right << RESET << std::endl;
		}
	}

	Node	* getTree(){return _mapTree;}

	void print2dTree(Node * r, int space = 0) {
		if (r == NULL)
			return ;
		space += 5;
		print2dTree(r->right, space);
		std::cout << std::endl;
		for (int i = 5; i < space; ++i)
			std::cout << " ";
		r->color ? std::cout << r << ":" << r->myPair.second << std::endl : std::cout << RED << r << ":" << r->myPair.second << RESET << std::endl;
		print2dTree(r->left, space);
	}

	// private:

	key_compare 	_keyCmp;
	allocator_type 	_allocTp;
	size_type		_size;
	Node	*_mapTree;

// TYPE DEFINI SPECIFIQUEMENT POUR L'ALLOCATION DE NOEUDS
	typename allocator_type::template rebind<Node>::other _alloc_node;

/* 	pair<iterator,bool> addNode(Node *temp, bool right, const value_type& val) {
		pair<iterator,bool> toReturnPair;
		right ? temp->right = createNode(val) : temp->left = createNode(val);
		right ? temp->right->parent = temp : temp->left->parent = temp;
		iterator it(right ? temp->right : temp->left, &_mapTree);
		toReturnPair.first = it;
		toReturnPair.second = true;
		return toReturnPair;
	} */

	Node* createNode(const value_type& val)
	{//ALLOUE UN NOEUD, (INCREMENTE _SIZE OF MAP,) INITIALISE PAIR, METS LES ENFANTS A NULL ET RETURN CE NOEUD
		// Node* node = new Node;
		Node* node  = _alloc_node.allocate(1);
		// ++_size;
		_allocTp.construct(&node->myPair, val);
		node->parent = node->left = node->right = NULL;
		node->color = E_RED;
		return node;
	}

/* 	Node* insertBST(Node *&node, Node *&ptr)
	{
		if (node == NULL || node == this->_mapTree) {
			++_size;
			return ptr;
		}
		if (ptr->myPair.first < node->myPair.first) {
			node->left = insertBST(node->left, ptr);
			node->left->parent = node;
		} else if (ptr->myPair.first > node->myPair.first) {
			node->right = insertBST(node->right, ptr);
			node->right->parent = node;
		}
		return node;
	}

// VERSION ITERATIF DE insertBST
	Node* insertNode(Node *&node, Node *&ptr)
	{
			// std::cout << RED "#1 _mapTree->parent ptr/val : "  << _mapTree->parent << "/\n";
			// std::cout << _mapTree->parent->myPair.first << RESET "\n";
		#ifdef _DEBUG_
		#endif
		while (!node || node != this->_mapTree)
		// while (node == NULL || node == this->_mapTree)
			if (ptr->myPair.first < node->myPair.first) {
				if (!node->left || node->left == this->_mapTree){
					if (node->left == this->_mapTree) {
						node->left = ptr;
						ptr->parent = node;
						_mapTree->left = ptr;
						ptr->left = _mapTree;
					}
					else {
						node->left = ptr;
						ptr->parent = node;
					}
					#ifdef _DEBUG_
						std::cout << RED "if ptr/val : " << ptr << "/" << ptr->myPair.first << RESET"\n";
					#endif
					return ptr;
				}
				else node = node->left;
			}
			else if (ptr->myPair.first > node->myPair.first) { //std::cout << RED "#2 [_mapTree->parent ptr/val : "  << _mapTree->parent << "/" << _mapTree->parent->myPair.first << ", node ptr/val : "  << node << "/" << node->myPair.first << "]\n" RESET;
				if (!node->right || node->right == this->_mapTree){
					if (node->right == this->_mapTree) { //std::cout << RED "if\n" RESET;
						node->right = ptr;
						ptr->parent = node;
						_mapTree->right = ptr;
						ptr->right = _mapTree;
					}
					else { //std::cout << RED "else\n" RESET;
						node->right = ptr;
						ptr->parent = node;
					}
					// std::cout << RED "if node:val/ptr:val  : " << node << ":" << node->myPair.first << "/" << ptr << ":" << ptr->myPair.first  << RESET "\n";
					// std::cout << RED "if _mapTree->parent ptr/val : "  << _mapTree->parent << "/" << _mapTree->parent->myPair.first << RESET "\n";
					return ptr;
				}
				else node = node->right;
			}
			else {
				// std::cout << RED "else ptr/val : " << ptr << "/" << ptr->myPair.first << RESET"\n";
				return node;
				}
		return node;
	} */

Node *insertBST_iteratif(Node *&root, Node *&ptr) {
	Node *node = root;
	while (node) 
		if (ptr->myPair.first > node->myPair.first) {
			if (!node->right) {
				_size++;
				node->right = ptr;
				ptr->parent = node;
				// std::cout << "#1\n";
				return ptr;
			}
			node = node->right;
		}
		else if (ptr->myPair.first < node->myPair.first) {
			if (!node->left) {
				_size++;
				node->left = ptr;
				ptr->parent = node;
				// std::cout << "#2\n";
				return ptr;
			}
			node = node->left;
		}
		else
			return node;
	_size++;
	// std::cout << "#3\n";
	ptr->color = E_BLACK;
	return (root = ptr);
}

pair<iterator,bool>  insertValueIteratif(const value_type& val) {
	Node *ptr  = createNode(val);
	Node *to_return;
	pair<iterator,bool> toReturnPair;
	if (ptr == (to_return = insertBST_iteratif(_mapTree, ptr))){
		fixInsertRBTree(ptr);
		toReturnPair.second = true;
	}
	else {
		_alloc_node.destroy(ptr);
		_alloc_node.deallocate(ptr, sizeof(Node));
		toReturnPair.second = false;
	}
	toReturnPair.first = iterator(to_return, &_mapTree);
	return (toReturnPair);
}

/* 	pair<iterator,bool> insertValue(const value_type& val) {
		Node *tmp = _mapTree->parent;
		Node *node  = createNode(val);
		pair<iterator,bool> toReturnPair;
		#ifdef _DEBUG_
			std::cout << GREEN "insertValue : node/val :" << node << ":" << node->myPair.first << "\n";
		#endif
		if (!_size && ++_size) {
			// bind_first_node(node); // <- effacé car plus utilisé
			toReturnPair.first = iterator(node);
			toReturnPair.second = true;
			#ifdef _DEBUG_
				std::cout << GREEN "insertValue->bind_first_node _maptree->parent: " << _mapTree->parent << RESET "\n";
			#endif
			return toReturnPair;
		}
		// if ((tmp = insertBST(_mapTree->parent, node)) == node){
		if ((tmp = insertNode(tmp, node)) == node) {
			#ifdef _DEBUG_
				std::cout << GREEN "if insertValue->insertNode node:val/tmp:val  : " << node << ":" << node->myPair.first << "/" << tmp << ":" << tmp->myPair.first  << RESET "\n";
			#endif
			toReturnPair.first = iterator(node);
			toReturnPair.second = true;
			++_size;
		}
		else {
			#ifdef _DEBUG_
				std::cout << GREEN "insertValue->insertNode else node:val/tmp:val  : " << node << ":" << node->myPair.first << "/" << tmp << ":" << tmp->myPair.first  << RESET "\n";
			#endif			
			_alloc_node.destroy(node);
			_alloc_node.deallocate(node, sizeof(Node));
			toReturnPair.first = iterator(tmp);
			toReturnPair.second = false;
		}
		#ifdef _DEBUG_
			std::cout << GREEN "insertValue _mapTree prt/right : " << _mapTree->parent << "/" << _mapTree->parent->right << " node : " << node << RESET "\n";
		#endif
		fixInsertRBTree(tmp);
		return toReturnPair;
	}
 */
//  void insertValue(const value_type& val) {
//      Node * node = createNode(val);
//     if (!_size && ++_size)
//         bind_first_node(node);
//     // std::cout << "root : " << root << " vs getRoot() : " << getRoot(node) << " node inséré : " << node << " data : " << node->data << " prt : " << node->parent << " root_prt : " << root->parent << std::endl;
//     /* root = */ insertBST(_mapTree->parent, node);
//     // std::cout << "root : " << root << " vs getRoot() : " << getRoot(node) << " node inséré : " << node << " data : " << node->data << " prt : " << node->parent << " root_prt : " << root->parent << std::endl;
//     fixInsertRBTree(node);
//     // print2dTree(getRoot(node));
// }

	Node* getLowest(Node* node) {
		Node* ptr = node;

	if (ptr)
		while (ptr->left != NULL)
			ptr = ptr->left;
	return ptr;
	}

	Node* getHighest(Node* node) {
/* 			while (node->parent)
				node = node->parent;
			while (node->right && node->right != _mapTree)
				node = node->right;
			return node; */
/* AJOUT */
Node* ptr = node;
	if (ptr)
		while (ptr->right != NULL)
			ptr = ptr->right;
	return ptr;
	}

	void setColor(Node* node, int color) {
		if (node == NULL)
			return;
		node->color = color;
	}

	void rotateLeft(Node* n)
	{
		if (!n || !n->right) {
			std::cout << "il n'y a pas de fils droit from(leftrotate)\n";
			return ;
		}
		n->right->parent = n->parent;
		if (n->parent == NULL)  // <- ici était le souci
			_mapTree = n->right;    // <- ici était le souci
		else if (n->parent->right == n)
			n->parent->right = n->right;
		else
			n->parent->left = n->right;
	//  (2)
		n->parent = n->right;
		if (n->right && n->right->left)
			n->right->left->parent = n;
		if (n->right)
			n->right = n->right->left;
		n->parent->left = n;
	}

	void rotateRight(Node* n)
	{
		if (!n | !n->left) {
			std::cout << "il n'y a pas de fils gauche from(rightrotate)\n";
			return ;
		}
		n->left->parent = n->parent;
		if (n->parent == NULL)      // <- ici était le souci
			_mapTree = n->left;         // <- ici était le souci
		else if (n->parent->right == n)
			n->parent->right = n->left;
		else
			n->parent->left = n->left;
	//	(2)
		n->parent = n->left;
		if (n->left && n->left->right)
			n->left->right->parent = n;
		if (n->left)
			n->left = n->left->right;
		n->parent->right = n;
		return ;
	}

	void fixInsertRBTree(Node* ptr) {
		Node *parent = NULL;
		Node *grandparent = NULL;
		while (ptr != _mapTree && getColor(ptr) == E_RED && getColor(ptr->parent) == E_RED) {
			parent = ptr->parent;
			grandparent = parent->parent;
			if (parent == grandparent->left) {
				Node *uncle = grandparent->right;
				if (getColor(uncle) == E_RED) {
					setColor(uncle, E_BLACK);
					setColor(parent, E_BLACK);
					setColor(grandparent, E_RED);
					ptr = grandparent;
				} else {
					if (ptr == parent->right) {
						rotateLeft(parent);
						ptr = parent;
						parent = ptr->parent;
					}
					rotateRight(grandparent);
					std::swap(parent->color, grandparent->color);
					ptr = parent;
				}
			} else {
				Node *uncle = grandparent->left;
				if (getColor(uncle) == E_RED) {
					setColor(uncle, E_BLACK);
					setColor(parent, E_BLACK);
					setColor(grandparent, E_RED);
					ptr = grandparent;
				} else {
					if (ptr == parent->left) {
						rotateRight(parent);
						ptr = parent;
						parent = ptr->parent;
					}
					rotateLeft(grandparent);
					std::swap(parent->color, grandparent->color);
					ptr = parent;
				}
			}
		}
		setColor(_mapTree, E_BLACK);
	}

	void fixDeleteRBTree(Node *&node) {
		if (node == NULL)
			return;

		if (node == _mapTree) { 
			/* ajout */
			#ifdef debug
				std::cout << "node est la racine \tfixDeleteRBTree\n";
			#endif
			if (!node->left && !node->right)
			{
				delete(_mapTree);
				_mapTree = NULL;
			}
			else if (!node->left)
			{
				Node *child_right = node->right;
				child_right->parent = NULL;
				delete(_mapTree);
				_mapTree = child_right;
				setColor(_mapTree, E_BLACK);
			}
			else if (!node->right) {
				Node *child_left = node->left;
				child_left->parent = NULL;
				delete(_mapTree);
				_mapTree = child_left;
				setColor(_mapTree, E_BLACK);
			}
			// else if (node->right && (node = node->right))
			//     while (node->left)
			//         node = node->left;
			// delete(_mapTree);
			/* STOP ajout */
			// _mapTree = nullptr;
			return;
		}

		if (getColor(node) == E_RED || getColor(node->left) == E_RED || getColor(node->right) == E_RED) {
			Node *child = node->left != NULL ? node->left : node->right;

			if (node == node->parent->left) {
				node->parent->left = child;
				if (child != NULL)
					child->parent = node->parent;
				setColor(child, E_BLACK);
				delete (node);
			} else {
				node->parent->right = child;
				if (child != NULL)
					child->parent = node->parent;
				setColor(child, E_BLACK);
				delete (node);
			}
		} else {
			Node *sibling = NULL;
			Node *parent = NULL;
			Node *ptr = node;
			setColor(ptr, E_DOUBLE_BLACK);
			while (ptr != _mapTree && getColor(ptr) == E_DOUBLE_BLACK) {
				parent = ptr->parent;
				if (ptr == parent->left) {
					sibling = parent->right;
					if (getColor(sibling) == E_RED) {
						setColor(sibling, E_BLACK);
						setColor(parent, E_RED);
						rotateLeft(parent);
					} else {
						if (getColor(sibling->left) == E_BLACK && getColor(sibling->right) == E_BLACK) {
							setColor(sibling, E_RED);
							if(getColor(parent) == E_RED)
								setColor(parent, E_BLACK);
							else
								setColor(parent, E_DOUBLE_BLACK);
							ptr = parent;
						} else {
							if (getColor(sibling->right) == E_BLACK) {
								setColor(sibling->left, E_BLACK);
								setColor(sibling, E_RED);
								rotateRight(sibling);
								sibling = parent->right;
							}
							setColor(sibling, parent->color);
							setColor(parent, E_BLACK);
							setColor(sibling->right, E_BLACK);
							rotateLeft(parent);
							break;
						}
					}
				} else {
					sibling = parent->left;
					if (getColor(sibling) == E_RED) {
						setColor(sibling, E_BLACK);
						setColor(parent, E_RED);
						rotateRight(parent);
					} else {
						if (getColor(sibling->left) == E_BLACK && getColor(sibling->right) == E_BLACK) {
							setColor(sibling, E_RED);
							if (getColor(parent) == E_RED)
								setColor(parent, E_BLACK);
							else
								setColor(parent, E_DOUBLE_BLACK);
							ptr = parent;
						} else {
							if (getColor(sibling->left) == E_BLACK) {
								setColor(sibling->right, E_BLACK);
								setColor(sibling, E_RED);
								rotateLeft(sibling);
								sibling = parent->left;
							}
							setColor(sibling, parent->color);
							setColor(parent, E_BLACK);
							setColor(sibling->left, E_BLACK);
							rotateRight(parent);
							break;
						}
					}
				}
			}
			if (node == node->parent->left)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
			delete(node);
			setColor(_mapTree, E_BLACK);
		}
	}

	Node* deleteBST(Node *node, const key_type& val) {
		if (node == NULL)
			return node;

		if (val < node->myPair.first)
			return deleteBST(node->left, val);

		if (val > node->myPair.first)
			return deleteBST(node->right, val);

		if (node->left == NULL || node->right == NULL)
			return node;

		Node *temp = getLowest(node->right);
		#ifdef debug
			std::cout << "temp :" << temp << ":" << temp->myPair.first << "\n"; 
		#endif
		// node->myPair.first = temp->myPair.first;
		_allocTp.construct(&node->myPair, temp->myPair);
		return deleteBST(node->right, temp->myPair.first);
	}

	void deleteValue(const key_type& val) {
		Node *node;
		if ((node = deleteBST(_mapTree, val)))
			--_size;
		#ifdef debug
			std::cout << "val :" << val << "\t(deleteValue map.hpp l.1090)\n"; 
		#endif
		fixDeleteRBTree(node);
	}

 void deleteTree(Node *ptr) // changé
{
	if (ptr)
	{
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

	int getColor(Node *&node) {
	if (node == NULL)
		return E_BLACK;
	// std::cout << "getcolor _node.val" << "/" << node->myPair.first << std::endl;

	return (node->color);
}

Node * getRoot(Node *n)
{
	while ( n->parent )
		n = n->parent;
	return n;
}

};

	template<typename Key, typename T>
	std::ostream& operator <<(std::ostream &o, ft::map<Key, T> &x) { o << x.getStr() << std::endl; return o;}

}

#endif

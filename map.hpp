#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <limits>
#include <stddef.h>

#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#include "colors.h"
#include "map_util.hpp"
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

	private:

	template <class T1, class T2>
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

	template<class T1, class T2>
	class autre {
		public :
		autre() { 
			_index.myPair.t1 = int(1);
			_index.myPair.t2 = int(2);
			_index.parent	= NULL;
			_index.left  	= NULL;
			_index.right 	= NULL;
		}
		private :
		s_tree<T1, T2> _index; // index de recherche rapide
	}; 

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
	// typedef									difference_type //	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
	// typedef									size_type //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

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


	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		autre<T1, T2>::_index = new s_tree<T1, T2>;
		// _index = new s_tree<T1, T2>;
		std::cout << "Default Map Constructor" << std::endl;
	}

	map (const map& x)
	{
		static typename autre<T1, T2>::_index = new s_tree<T1, T2>;
		// _index = new s_tree<T1, T2>;
	}

	~map()
	{
	}

	private:

	key_compare _keyCmp;
	allocator_type _allocTp;

	};

}

#endif
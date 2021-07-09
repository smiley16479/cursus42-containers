#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP

namespace ft {

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;	// The first template parameter (T1)	Type of member first.
		typedef T2	second_type; //	The second template parameter (T2)	Type of member second.

	// Constructors:
		// default (1)	
		// pair();
		// copy (2)	
		// template<class U, class V> pair (const pair<U,V>& pr);
		// initialization (3)	
		// pair (const first_type& a, const second_type& b);

	// relational operators (pair)
		// (1)	
		// template <class T1, class T2>
		//   bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
		// (2)	
		// template <class T1, class T2>
		//   bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
		// (3)	
		// template <class T1, class T2>
		//   bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
		// (4)	
		// template <class T1, class T2>
		//   bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
		// (5)	
		// template <class T1, class T2>
		//   bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
		// (6)	
		// template <class T1, class T2>
		//   bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		pair () : first(), second() {};

		T1 first;
		T2 second;
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

/* 	template<class T1, class T2>
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
    }; */
}

#endif
#ifndef MAP_UTIL_HPP
#define MAP_UTIL_HPP

namespace ft {

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
}

#endif
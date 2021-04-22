#include <memory>
// #include <vector>

namespace ft {

	template < class T = int, class Alloc = std::allocator<T> > 
	class vector
	{
	private:
			T *_tab;
			unsigned int _size;
			unsigned int _Rsize; // real_size
			// vector::size_type i;
	public:
		typedef Alloc allocator_type;
		
		explicit vector (const allocator_type& alloc = allocator_type()); //default (1)	
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill (2)
		template <class InputIterator> 
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range (3)
		vector (const vector& x); // copy (4)
		~vector();
	};

	template < class T, class Alloc >
	vector<T, Alloc>::vector(const allocator_type& alloc)
	{
		
	}

	template < class T, class Alloc >
	vector<T, class Alloc >::~vector()
	{
	}

}

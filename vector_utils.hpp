#include <memory> // std::forward_iterator_tag

/* RESSOURCES : */
//  https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
//  https://forum.hardware.fr/hfr/Programmation/C-2/conception-iterator-introduction-sujet_63686_1.htm
// typedef typename explanation : https://www.reddit.com/r/cpp/comments/q1854/typedef_typename_please_help_me_understand/c3tw580?utm_source=share&utm_medium=web2x&context=3
// https://stackoverflow.com/questions/18385418/c-meaning-of-a-statement-combining-typedef-and-typename

namespace ft {

template <typename _T>
 struct iterator // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
		typedef std::forward_iterator_tag	iterator_category;
		typedef	_T*				  pointer;
		typedef	_T&				  reference;

        iterator(pointer ptr) : _ptr(ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		}
        iterator(iterator const & ptr) : _ptr(ptr._ptr) {
			#ifdef _DEBUG_
				std::cout << "iterator_vector const default constructor" << std::endl;
			#endif
		}
		typedef const iterator	  const_iterator;
		// typedef iterator	  	  reverse_iterator;
		// typedef const_iterator	  const_reverse_iterator;

		pointer getPtr() const { return _ptr; }
        reference operator*() const { return *_ptr; }
        pointer operator->() { return _ptr; }
        iterator& operator++() { ++_ptr; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		iterator& operator--() { --_ptr; return *this; }
        iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		// iterator& operator+=( iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
        // iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		// iterator& operator-=( iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
        // iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		iterator& operator+=( int n ) {_ptr += n; return *this;}
        iterator operator+( int n ) {iterator copie(_ptr); copie += n; return (copie);}
		iterator& operator-=( int n ) {_ptr -= n; return *this;}
        iterator operator-( int n ) {iterator copie(_ptr); copie -= n; return (copie);}
        friend bool operator== (const iterator& a, const iterator& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a._ptr != b._ptr; };

    private:
        pointer _ptr;
    };
}
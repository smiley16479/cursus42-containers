#include <memory> // std::forward_iterator_tag
#include "iterator_traits.hpp"

// #define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
#endif
/* RESSOURCES : */
//  https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
//  https://forum.hardware.fr/hfr/Programmation/C-2/conception-iterator-introduction-sujet_63686_1.htm
// typedef typename explanation : https://www.reddit.com/r/cpp/comments/q1854/typedef_typename_please_help_me_understand/c3tw580?utm_source=share&utm_medium=web2x&context=3
// https://stackoverflow.com/questions/18385418/c-meaning-of-a-statement-combining-typedef-and-typename

namespace ft {

template <typename _T>
 struct iterator // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
		typedef std::random_access_iterator_tag	iterator_category;
		typedef	typename ft::iterator<_T>		self;
		typedef	_T*				  pointer;
		typedef	_T&				  reference;

		iterator(): _ptr(NULL) {
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		};
        iterator(pointer ptr) : _ptr(ptr) {
			#ifdef _DEBUG_
				std::cout << "iterator_vector pointer ptr constructor" << std::endl;
			#endif
		}
       iterator(iterator const & ptr) : _ptr(ptr._ptr) {
			#ifdef _DEBUG_
				std::cout << "iterator_vector const constructor" << std::endl;
			#endif
		}
		~iterator() {
			#ifdef _DEBUG_
				std::cout << "it_destructor\n";
			#endif
		};

		// typedef const iterator	  const_iterator;
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

    // private:
        pointer _ptr;
    };

template <typename _T>
 struct const_iterator {
		typedef std::random_access_iterator_tag	iterator_category;
		typedef	typename ft::const_iterator<_T>		self;
		typedef	const _T*				  pointer;
		typedef	const _T&				  reference;

		const_iterator(): _ptr(NULL){};
        const_iterator(ft::iterator<_T> ptr) : _ptr(ptr.getPtr()) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		};
		const_iterator(_T* ptr) : _ptr(ptr) {
			#ifdef _DEBUG_
				std::cout << "1st_const_it_parametric_constructor\n";
			#endif
		};

//        const_iterator(ft::iterator<_T>& ptr) : _ptr(ptr._ptr) {
//			#ifdef _DEBUG_
//				std::cout << "iterator_vector const default constructor" << std::endl;
//			#endif
//		}

		pointer getPtr() const { return _ptr; }
        reference operator*() const { return *_ptr; }
        pointer operator->() { return _ptr; }
        const_iterator& operator++() { ++_ptr; return *this; }
        const_iterator operator++(int) { const_iterator tmp = *this; ++(*this); return tmp; }
		const_iterator& operator--() { --_ptr; return *this; }
        const_iterator operator--(int) { const_iterator tmp = *this; --(*this); return tmp; }
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		// iterator& operator+=( iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
        // iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		// iterator& operator-=( iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
        // iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		const_iterator& operator+=( int n ) {_ptr += n; return *this;}
        const_iterator operator+( int n ) {const_iterator copie(_ptr); copie += n; return (copie);}
		const_iterator& operator-=( int n ) {_ptr -= n; return *this;}
        const_iterator operator-( int n ) {const_iterator copie(_ptr); copie -= n; return (copie);}
        friend bool operator== (const const_iterator& a, const const_iterator& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const const_iterator& a, const const_iterator& b) { return a._ptr != b._ptr; };

    // private:
        pointer _ptr;
};

template <typename _T>
 struct const_iterator <const _T>
    {
		typedef std::random_access_iterator_tag	iterator_category;
		typedef	const_iterator<const _T>	self;
		typedef	const _T*					pointer;
		typedef	const _T&					reference;

		const_iterator(): _ptr(NULL){};
        const_iterator(pointer ptr) : _ptr(ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		}
		const_iterator(ft::iterator<const _T> it) : _ptr(it._ptr) { 
			#ifdef _DEBUG_
				std::cout << "iterator_vector default constructor" << std::endl;
			#endif
		}
        const_iterator(self const & it) : _ptr(it._ptr) {
			#ifdef _DEBUG_
				std::cout << "iterator_vector const default constructor" << std::endl;
			#endif
		}

		pointer getPtr() const { return _ptr; }
        const _T& operator*() const { return *_ptr; }
        const _T* operator->() { return _ptr; }
        self& operator++() { ++_ptr; return *this; }
        self operator++(int) { self tmp = *this; ++(*this); return tmp; }
		self& operator--() { --_ptr; return *this; }
        self operator--(int) { self tmp = *this; --(*this); return tmp; }
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		// iterator& operator+=( iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
        // iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		// iterator& operator-=( iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
        // iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		self& operator+=( int n ) {_ptr += n; return *this;}
        self operator+( int n ) {self copie(_ptr); copie += n; return (copie);}
		self& operator-=( int n ) {_ptr -= n; return *this;}
        self operator-( int n ) {self copie(_ptr); copie -= n; return (copie);}
        friend bool operator== (const self& a, const self& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const self& a, const self& b) { return a._ptr != b._ptr; };

    // private:
        pointer _ptr;
    };

template <typename _T>
 struct reverse_iterator // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
		typedef reverse_iterator					self;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef	_T*									pointer;
		typedef	_T&									reference;

		reverse_iterator(): _ptr(NULL){};
        reverse_iterator(pointer ptr) : _ptr(ptr) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector default constructor" << std::endl;
			#endif
		}
        reverse_iterator(reverse_iterator const & ptr) : _ptr(ptr._ptr) {
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector const default constructor" << std::endl;
			#endif
		}
		reverse_iterator(ft::iterator<_T> ptr) : _ptr(ptr.getPtr()) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector default constructor" << std::endl;
			#endif
		}

		pointer getPtr() const { return _ptr; }
        reference operator*() const { return *_ptr; }
        pointer operator->() { return _ptr; }
        self& operator++() { --_ptr; return *this; }
        self operator++(int) { self tmp = *this; --(*this); return tmp; }
		self& operator--() { ++_ptr; return *this; }
        self operator--(int) { self tmp = *this; ++(*this); return tmp; }
		// iterator& operator=( iterator & i ) {_ptr(i._ptr); return *this;}
		// iterator& operator+=( iterator & i ) {_ptr += (size_t)i._ptr; return *this;}
        // iterator operator+( iterator & i ) {iterator copie(_ptr); copie += i; return (copie);}
		// iterator& operator-=( iterator & i ) {_ptr -= (size_t)i._ptr; return *this;}
        // iterator operator-( iterator & i ) {iterator copie(_ptr); copie -= i; return (copie);}
		self& operator+=( int n ) {_ptr += n; return *this;}
        self operator+( int n ) {self copie(_ptr); copie += n; return (copie);}
		self& operator-=( int n ) {_ptr -= n; return *this;}
        self operator-( int n ) {self copie(_ptr); copie -= n; return (copie);}
        friend bool operator== (const self& a, const self& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const self& a, const self& b) { return a._ptr != b._ptr; };

    private:
        pointer _ptr;
    };

template <typename _T>  //Added
 struct reverse_iterator <const _T>// https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
    {
		typedef reverse_iterator<const _T>			self;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef	const _T*							pointer;
		typedef	const _T&							reference;

		reverse_iterator(): _ptr(NULL){};
        reverse_iterator(pointer ptr) : _ptr(ptr) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector default constructor" << std::endl;
			#endif
		}
        reverse_iterator(reverse_iterator const & ptr) : _ptr(ptr._ptr) {
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector const default constructor" << std::endl;
			#endif
		}
		reverse_iterator(ft::reverse_iterator<_T> ptr) : _ptr(ptr.getPtr()) { 
			#ifdef _DEBUG_
				std::cout << "reverse_iterator_vector default constructor" << std::endl;
			#endif
		}

		pointer getPtr() const { return _ptr; }
        reference operator*() const { return *_ptr; }
        pointer operator->() { return _ptr; }
        self& operator++() { --_ptr; return *this; }
        self operator++(int) { self tmp = *this; --(*this); return tmp; }
		self& operator--() { ++_ptr; return *this; }
        self operator--(int) { self tmp = *this; ++(*this); return tmp; }
		self& operator+=( int n ) {_ptr += n; return *this;}
        self operator+( int n ) {self copie(_ptr); copie += n; return (copie);}
		self& operator-=( int n ) {_ptr -= n; return *this;}
        self operator-( int n ) {self copie(_ptr); copie -= n; return (copie);}
        friend bool operator== (const self& a, const self& b) { return a._ptr == b._ptr; };
        friend bool operator!= (const self& a, const self& b) { return a._ptr != b._ptr; };

    private:
        pointer _ptr;
    };

}
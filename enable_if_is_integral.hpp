#ifndef _ENABLE_IF_IS_INTEGRAL_
  #define _ENABLE_IF_IS_INTEGRAL_

namespace ft {

	  // ENABLE_IF / IS_INTEGRAL

  template<bool B, class T = void>
  struct enable_if {};

  template<class T>
  struct enable_if<true, T> { typedef T type; };

  template <typename T>
  struct is_integral { static const bool value = false; };

  template <>
  struct is_integral<bool> { static const bool value = true; };

  template <>
  struct is_integral<char> { static const bool value = true; };

  template <>
  struct is_integral<short> { static const bool value = true; };

  template <>
  struct is_integral<int> { static const bool value = true; };

  template <>
  struct is_integral<long> { static const bool value = true; };

  template <>
  struct is_integral<long long> { static const bool value = true; };

  template <>
  struct is_integral<unsigned char> { static const bool value = true; };

  template <>
  struct is_integral<unsigned short> { static const bool value = true; };

  template <>
  struct is_integral<unsigned int> { static const bool value = true; };

  template <>
  struct is_integral<unsigned long> { static const bool value = true; };

  template <>
  struct is_integral<unsigned long long> { static const bool value = true; };

  // LEXICOGRAPHICAL_COMPARE / EQUAL

  template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                  InputIterator2 first2, InputIterator2 last2)
  {
    while (first1!=last1)
    {
      if (first2==last2 || *first2<*first1) return false;
      else if (*first1<*first2) return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
  }
  
  template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
  {
    while (first1!=last1) {
      if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
        return false;
      ++first1; ++first2;
    }
    return true;
  }
}

#endif
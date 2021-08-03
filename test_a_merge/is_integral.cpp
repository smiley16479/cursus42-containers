#include <iostream>
#include <type_traits>

// Test sur les is_integral en cpp
// https://runebook.dev/en/docs/cpp/types/is_integral

class A {};
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

namespace ft {
// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1903999-creez-des-templates
  template <typename T> // ne fonctionne pas si cette structure n'est pas prealablement defini
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

  template <class T>
  T fct(T i)
  {
      static_assert(ft::is_integral<T>::value, "Integral required.");
      return i;
  }
}

int main() 
{
    std::cout << std::boolalpha;
    std::cout << "std : " << std::is_integral<A>::value << " / ";
	std::cout << "ft : " << ft::is_integral <A>::value << "\n";
    std::cout << "std : " << std::is_integral<E>::value << " / ";
	std::cout << "ft : " << ft::is_integral <E>::value << "\n";
    std::cout << "std : " << std::is_integral<float>::value << " / ";
	std::cout << "ft : " << ft::is_integral <float>::value << "\n";
    std::cout << "std : " << std::is_integral<int>::value << " / ";
	std::cout << "ft : " << ft::is_integral <int>::value << "\n";
    std::cout << "std : " << std::is_integral<bool>::value << " / ";
	std::cout << "ft : " << ft::is_integral <bool>::value << "\n";
    
    std::cout << "\nfct : \n";
	std::cout << "std : " << f(123) << '\n';
	std::cout << "ft : " << ft::fct(123) << '\n';
}

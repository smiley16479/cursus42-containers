#include <iostream>
#include <type_traits>
template <class T>
   std::enable_if_t<(sizeof(T) <= sizeof(int))> f(T) {
      std::cout << "f() version petite taille" << std::endl;
   }

template <class T>
   std::enable_if_t<(sizeof(T) > sizeof(int))> f(T) {
      std::cout << "f() version grande taille" << std::endl;
   }

class X { char _ [128]; };
int main() {
   f(X{}); // version « grande taille »
   f(3);   // version « petite taille »
}
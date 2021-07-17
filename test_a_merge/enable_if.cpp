// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
#include <vector>
#include <iostream>
#include <type_traits>


/* template <class T>
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
 */


   // AUTRE EXEMPLE 
// ENABLE_IF POUR TYPE RETOURNÉ :
/* template <class T>
   typename std::enable_if<std::is_trivially_copyable<T>::value>::type f(T) {
      // ...
   }
int main() {
   using std::vector;
   vector<int> v;
   f(3);
   // f(v); // serait illégal
} */

// ENABLE_IF POUR PARAMÈTRE SILENCIEUX :
template <class T>
  void f(T, typename std::enable_if<std::is_trivially_copyable<T>::value>::type * = nullptr) {
      // ...
   }
int main() {
   using std::vector;
   vector<int> v;
   f(3);
   // f(v); // serait illégal
}
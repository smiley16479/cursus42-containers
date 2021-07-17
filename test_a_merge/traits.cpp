// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html

#include <limits>
#include <iostream>
using namespace std;
template <class T>
   T abs(const T &val) {
      static_assert(numeric_limits<T>::is_signed, "ne s'applique qu'aux types signés");
      return val < 0? -val : val;
   }

int main() {
   int i = -4;
   cout << abs(i) << endl; // Ok.
   unsigned int ui = 5;
   // ne compilerait pas
   // cout << abs(ui) << endl;
}
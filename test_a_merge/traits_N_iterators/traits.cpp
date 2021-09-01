// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html

#include <limits>
// #include <vector>
#include <iostream>

/* template <class T>
   T abs(const T &val) {
      static_assert(std::numeric_limits<T>::is_signed, "ne s'applique qu'aux types signés");
      return val < 0? -val : val;
   }

int main() {
   int i = -4;
   std::cout << abs(i) << std::endl; // Ok.
   unsigned int ui = 5;
   // ne compilerait pas
   // cout << abs(ui) << endl;
}
 */

//AUTRE EXEMPLE PLUS COMPLET  : https://forum.hardware.fr/hfr/Programmation/C-2/conception-iterator-introduction-sujet_63686_1.htm
/* Description de std::iterator_traits<> 
Rien de très compliqué, on veut juste unifier iterators, pointeurs et const-pointeurs. On fournit 5 typedefs, c'est la projection des typedefs de std::iterator. 
Notez bien les différences sur "pointer" et "reference". */
/* 
    template<typename _Iterator>
    struct iterator_traits
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
    };
    template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef std::random_access_iterator_tag  iterator_category;
      typedef _Tp                              value_type;
      typedef ptrdiff_t                        difference_type;
      typedef _Tp*                             pointer;
      typedef _Tp&                             reference;
    };
    template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef std::random_access_iterator_tag  iterator_category;
      typedef _Tp                              value_type;
      typedef ptrdiff_t                        difference_type;
      typedef const _Tp*                       pointer;
      typedef const _Tp&                       reference;
    };
 */

    namespace My
    {
      template<typename InputIterator>
      typename std::iterator_traits<InputIterator>::difference_type
      distance(InputIterator first, InputIterator last)
      {
        typename std::iterator_traits<InputIterator>::difference_type n = 0;
         while (first != last)
         {
           ++first;
           ++n;
         }
         return n;
      }

      template<typename T>
      struct Forward
        : std::iterator<std::forward_iterator_tag, T>
      {
        Forward(T v) : value(v)
        { }
        bool operator!=(const Forward &other) const
        {
          return this->value != other.value;
        }
        Forward& operator++()
        {
          std::cout << "++Forward\n";
          this->value++;
          return *this;
        }
        private:
          T value;
      };

      template<typename T>
      struct Random
        : std::iterator<std::random_access_iterator_tag, T>
      {
        Random(T v) : value(v)
        { }
        bool operator!=(const Random &other) const
        {
          return this->value != other.value;
        }
        typename std::iterator<std::random_access_iterator_tag, T>::difference_type
        operator-(const Random &other) const
        {
          return this->value - other.value;
        }
        Random& operator++()
        {
          std::cout << "++Random\n";
          this->value++;
          return *this;
        }
        private:
          T value;
      };
    }

    namespace
    {
      template<typename InputIterator, typename Tag>
      struct DistanceWorker
      {
        static typename std::iterator_traits<InputIterator>::difference_type
        distance(InputIterator first, InputIterator last)
        {
          return My::distance(first, last);
        }
      };
      
/* // CELLE CI SERA UTILISÉE SI TU LA DÉCOMMENTE EN CAS DE FORWARD_ITERATOR
//  IL S'AGIT DE SPECIALISATION DE TEMPLATE EN FAIT !!
            template<typename InputIterator>
      struct DistanceWorker<InputIterator, std::forward_iterator_tag>
      {
        static typename std::iterator_traits<InputIterator>::difference_type
        distance(InputIterator first, InputIterator last)
        {
          return My::distance(first, last);
        }
      };
 */

      template<typename InputIterator>
      struct DistanceWorker<InputIterator, std::random_access_iterator_tag>
      {
        static typename std::iterator_traits<InputIterator>::difference_type
        distance(InputIterator first, InputIterator last)
        {
          return last - first;
        }
      };
    }

    namespace My
    {
      template<typename InputIterator>
      typename std::iterator_traits<InputIterator>::difference_type
      distance2(InputIterator first, InputIterator last)
      {
        typedef typename std::iterator_traits<InputIterator>::iterator_category Tag;
        return DistanceWorker<InputIterator, Tag>::distance(first, last);
      }
    }

    int main()
    {
      typedef My::Forward<int> I;
      typedef My::Random<int> R;
      // complexité linéaire : normal
      std::cout << "first <-> last\n"
        << My::distance(I(0), I(3))
        << "\n\n";
      // complexité linéaire : aïe !
      std::cout << "first <-> last\n"
        << My::distance(R(0), R(3))
        << "\n\n";
      // complexité linéaire : normal
      std::cout << "first <-> last\n"
        << My::distance2(I(0), I(3))
        << "\n\n";
      // complexité 1 !
      std::cout << "first <-> last\n"
        << My::distance2(R(0), R(3))
        << "\n\n";
    }



// ENCORE UN AUTRE EXEMPLE (QUI NE FONCTIONNE PAS)
//https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
     
//User always calls this method, general method for distance()

// User needs to satisfy the following 2 criteria: 
// For random access iterator, second iterator position must come 
// after first iterator position/
// For all other kind of iterator, second iterator must be reachable from first iterator
// Both of the iterator must refer to the same container, otherwise result is undefined
/* #include <map>
#include <vector>
#include <iterator>
namespace MY {

    template <typename Iterator>
    typename std::iterator_traits<Iterator>::difference_type
    distance (Iterator pos1, Iterator pos2)
    {
        return distance (pos1, pos2,
                         typename std::iterator_traits<Iterator>
                            ::iterator_category()); 
    }


    //Core implementation ..... distance() for random access iterators
    template <typename RandomAccessIterator>
    typename std::iterator_traits<RandomAccessIterator>::difference_type
    // Note the return type above, it solely depends on Iterators declared typedefs,
    // no so called INT/SHORT here
    distance (RandomAccessIterator first_position, RandomAccessIterator second_position,
               std::random_access_iterator_tag) 
    {std::cout << "RandomAccessIterator\n";
        return second_position - first_position; 
    }


    //distance() for input, forward, and bidirectional iterators
    // Keep in mind that here we are using only Input iterator tags, so
    // forward and bidirectional iterator will also be in this bucket, because we
    // used Inheritance while declare forward and bidirectional iterator tags.

    template <typename lInputIterator>
    typename std::iterator_traits<lInputIterator>::difference_type
    // Note the return type here, truly generic
    distance (lInputIterator first_position, lInputIterator second_position,
              std::input_iterator_tag) 
    {std::cout << "lInputIterator\n";
        // note the type of the temp variable here, truly generic 
        typename std::iterator_traits<lInputIterator>::difference_type diff;
        for (diff=0; first_position != second_position; ++first_position, ++diff) {
             ;
        }
        return diff; 
    }
}

int main(void)
{
  std::vector<int> v;
  for (size_t i = 0; i < 5; i++)
    v.push_back(i);
  std::vector<int>::iterator it_b = v.begin();
  std::vector<int>::iterator it_e = v.end();
  std::cout << distance(it_b, it_e) << std::endl;
  return 0;
}
*/
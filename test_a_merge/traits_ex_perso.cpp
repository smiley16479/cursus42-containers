#include <iostream>

// EXEMPLE PERSO

// TRAITS
/* namespace mes_traits {

  template <typename T>
  struct trait{
      typedef bool    tutu; //pk si on met char la fonction ne retourne pas de size?
      typedef short   toto;
      typedef int     titi;
      typedef toto    type;
  };

  template <typename T>
  struct trait<T&>{
      typedef bool    toto; //pk si on met char la fonction ne retourne pas de size?
      typedef short   titi;
      typedef int     tutu;
      typedef toto    type;
  };

  template <typename T>
  struct trait<T*>{
      typedef bool    titi; //pk si on met char la fonction ne retourne pas de size?
      typedef short   tutu;
      typedef int     toto;
      typedef toto    type;
  };

  template <typename T>
  struct trait<const T*>{
      typedef bool   tutu; //pk si on met char la fonction ne retourne pas de size?
      typedef int    titi;
      typedef size_t toto;
      typedef toto type;
  };
}
// CLASS

template <typename T>
  class traits
  {
    typedef size_t bool_droite;
  private:

  public:
    typedef size_t  toto;
    typedef char    tutu;
    typedef int     titi;
    typedef toto    type;

    traits() {};
    ~traits() {};
    typename mes_traits::trait<T>::type test();
  };

template <typename T>
  class traits<T&>
  {
    typedef size_t bool_droite;
  private:

  public:
    typedef size_t  titi;
    typedef char    toto;
    typedef int     tutu;
    typedef toto    type;

    traits() {};
    ~traits() {};
    typename mes_traits::trait<T&>::type test();
  };

template <typename T>
  class traits<T*>
  {
    typedef size_t bool_droite;
  private:

  public:
    typedef size_t  tutu;
    typedef char    titi;
    typedef int     toto;
    typedef toto    type;

    traits(){};
    ~traits(){};
    typename mes_traits::trait<T*>::type test();
  };

template <typename T>
  class traits<const T*>
  {
    typedef size_t bool_droite;
  private:

  public:
    typedef size_t toto;
    typedef char tutu;
    typedef int titi;
    typedef toto type;
    traits() {};
    ~traits(){};
    typename mes_traits::trait<const T*>::type test();
  };

  template<typename T>
  typename mes_traits::trait<T>::type traits<T>::test(){
    return sizeof(typename mes_traits::trait<T>::type);
  }

  template<typename T>
  typename mes_traits::trait<T*>::type traits<T*>::test(){
    return sizeof(typename mes_traits::trait<T>::type);
  }

  template<typename T>
  typename mes_traits::trait<T&>::type traits<T&>::test(){
    return sizeof(typename mes_traits::trait<T>::type);
  }

  template<typename T>
  typename mes_traits::trait<const T*>::type traits<const T*>::test(){
    return sizeof(typename mes_traits::trait<T>::type);
  }

  template<typename T>
  typename mes_traits::trait<T>::type autonome(){
    return sizeof(typename mes_traits::trait<T>::type);
  }

  // template<typename T>
  // traits<T>::titi traits<T>::test(){
  //   return 800;
  // }

template <typename T>
  struct tabite_traits{
    typedef size_t bool_gauche;

  };

  traits<int> a;
    int main() {

      traits<int&> trait;
      std::cout << trait.test() << std::endl;
      
      std::cout << autonome<const int*>() << std::endl;

      return 0;
    }

 */
/* ET SA VARIANTE SANS TRAITS*/

// CLASS

template <typename T>
  class traits
  {
    // typedef size_t bool_droite;
  private:

  public:
    typedef size_t  toto;
    typedef bool    tutu;
    typedef int     titi;
    typedef toto    type;

    traits() {};
    ~traits() {};
    /* typename mes_traits:: */traits<T>::type test();
  };

template <typename T>
  class traits<T&>
  {
    // typedef size_t bool_droite;
  private:

  public:
    typedef size_t  titi;
    typedef bool    toto;
    typedef int     tutu;
    typedef toto    type;

    traits() {};
    ~traits() {};
    /* typename mes_traits:: */traits<T&>::type test();
  };

template <typename T>
  class traits<T*>
  {
    // typedef size_t bool_droite;
  private:

  public:
    typedef size_t  tutu;
    typedef bool    titi;
    typedef int     toto;
    typedef toto    type;

    traits(){};
    ~traits(){};
    /* typename mes_traits:: */traits<T*>::type test();
  };

template <typename T>
  class traits<const T*>
  {
    // typedef size_t bool_droite;
  private:

  public:
    typedef size_t toto;
    typedef bool tutu;
    typedef int titi;
    typedef toto type;
    traits() {};
    ~traits(){};
    /* typename mes_traits:: */traits<const T*>::type test();
  };

  template<typename T>
  typename /* mes_traits:: */traits<T>::type traits<T>::test(){
    return sizeof(typename /* mes_traits:: */traits<T>::type);
  }

  template<typename T>
  typename /* mes_traits:: */traits<T*>::type traits<T*>::test(){
    return sizeof(typename /* mes_traits:: */traits<T>::type);
  }

  template<typename T>
  typename /* mes_traits:: */traits<T&>::type traits<T&>::test(){
    return sizeof(typename /* mes_traits:: */traits<T>::type);
  }

  template<typename T>
  typename /* mes_traits:: */traits<const T*>::type traits<const T*>::test(){
    return sizeof(typename /* mes_traits:: */traits<T>::type);
  }

  template<typename T>
  typename /* mes_traits:: */traits<T>::type autonome(){
    return sizeof(typename /* mes_traits:: */traits<T>::type);
  }

template <typename T>
  struct tabite_traits{
    typedef size_t bool_gauche;

  };

int main() {
    typedef char foo; //le char n'affiche rien pour tant il marche ici
	std::cout << sizeof(foo) << std::endl;
	std::cout << sizeof(bool) << std::endl;


    traits<int&> trait;
    std::cout << trait.test() << std::endl;
    
    std::cout << autonome<int&>() << std::endl;
	return 0;
}

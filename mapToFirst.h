#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H
#include <iostream>
#include <less.h>
#include <pair.h>

using namespace std;

namespace map {
  template<typename T1, typename T2, template<class> class Order = Less>
  class MapToFirst  {

  public:
    MapToFirst(): pair1(Pair<T1,T2>()), pair2(Pair<T1,T2>()){}
    MapToFirst(Pair<T1,T2>pair1, Pair<T1,T2>pair2): pair1(pair1), pair2(pair2){}
    ~MapToFirst(){}

    bool operator()(Pair<T1,T2> pair1, Pair<T1,T2> pair2) {
      return functor(pair1.first(),pair2.first());
    }

  private:

    Pair<T1,T2> pair1;
    Pair<T1,T2> pair2;
    Order<T1> functor;
  };
}

#endif // MAPTOFIRST_H

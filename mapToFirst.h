#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H
#include <iostream>
#include <less.h>
#include <pair.h>

using namespace std;

namespace mystl {
template<typename T1, typename T2, template<class> class Order = Less>

  /**
   * @brief The MapToFirst class
   *
   * Gibt das Paar zurück, welches der übergebenen Ordnung entspricht.
   *
   * @author François Dubois <siokdub@gmail.com>
   * @author Sebastian Morkisch <semox78@gmail.com>
   */

class MapToFirst  {

public:


    MapToFirst():pair1(Pair<T1,T2>()), pair2(Pair<T1,T2>()){}

    MapToFirst(Pair<T1,T2>pair1, Pair<T1,T2>pair2):pair1(pair1), pair2(pair2){}

    ~MapToFirst(){}

    /**
     * @brief operator ()
     *
     * Überprüft zwei Paare auf Ihre definierte Ordnung. Liefert True bei
     * Einhaltung der Ordnung.
     * @param pair1
     * @param pair2
     * @return bool
     */
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

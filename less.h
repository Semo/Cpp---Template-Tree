#ifndef LESS_H
#define LESS_H

namespace mystl {
template<class T>

  /**
  * @brief The Less class
  *
  * @author François Dubois <siokdub@gmail.com>
  * @author Sebastian Morkisch <semox78@gmail.com>
  */
class Less {

public:

  /**
     * @brief operator ()
     *
     * Liefert True, wenn erster Parameter kleiner als zweiter Parameter ist.
     * @param lhs
     * @param rhs
     * @return
     */
    bool operator()(const T& lhs, const T& rhs) {
        return lhs < rhs;
    }
};
}

#endif // LESS_H

#ifndef GREATER_H
#define GREATER_H

namespace mystl {
  template<class T>

  /**
  * @brief The Greater class
  *
  * @author François Dubois <siokdub@gmail.com>
  * @author Sebastian Morkisch <semox78@gmail.com>
  */

  class Greater {
  public:

    /**
     * @brief operator ()
     *
     * Liefert True, wenn erster Parameter größer als zweiter Parameter ist.
     * @param lhs
     * @param rhs
     * @return
     */
    bool operator()(const T& lhs, const T& rhs) {
      return lhs > rhs;
    }
  };
}

#endif // GREATER_H

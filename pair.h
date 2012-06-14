#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

namespace mystl {

  template<typename T1,typename T2>

  /**
   * @brief The Pair class
   *
   * Repräsentiert ein Key/Value Paar
   *
   * @author François Dubois <siokdub@gmail.com>
   * @author Sebastian Morkisch <semox78@gmail.com>
   */
  class Pair {


  public:

    Pair():key(T1()), value(T2()){}

    Pair(T1 key,T2 value): key(key), value(value) {}

    ~Pair(){}

    //Accessors

    T1 &first(){
      return this->key;
    }

    T2 &second(){
      return this->value;
    }

    const T1& first() const{
      return this->key;
    }
    const T2& second() const{
      return this->value;
    }

    /**
     * @brief operator ==
     *
     * Überprüft die Schlüssel zweier Paare auf Gleichheit.
     * @param rhs
     * @return
     */
    bool operator == (const Pair<T1,T2> & rhs) {
      if(this->first() == rhs.first()) {
          return true;
        }
      return false;

    }

  private:
    T1 key;
    T2 value;

  };

  template<typename T1, typename T2>
  ostream& operator<<(ostream &output, const Pair<T1,T2> &p) {
    output << "<" << p.first() << "," << p.second() << ">";
    return output;
  }

}
#endif // PAIR_H

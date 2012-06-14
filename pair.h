#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

namespace mystl {

template<typename T1,typename T2>
class Pair {


public:

    Pair():key(T1()), value(T2()){}
    Pair(T1 key,T2 value): key(key), value(value) {}
    ~Pair(){}

    const T1& first() const{
        return this->key;
    }
    const T2& second() const{
        return this->value;
    }

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

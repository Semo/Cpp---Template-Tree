#ifndef GREATER_H
#define GREATER_H

namespace mystl {
template<class T>
class Greater {
public:
    bool operator()(const T& lhs, const T& rhs) {
        return lhs > rhs;
    }
};
}

#endif // GREATER_H

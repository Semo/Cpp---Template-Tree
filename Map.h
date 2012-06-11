#ifndef MAP_H
#define MAP_H

#include "Tree.h"
#include "TreeIterator.h"
#include "pair.h"

namespace mystl {

    //     Map<int,string, MapToFirst<int,string,Less> > m;
  template <typename KeyT, typename ValueT, typename OrderT>

  class Map{

  public:

    typedef TreeIterator<KeyT, ValueT> iterator;
    typedef Pair<KeyT, ValueT> value_type;

//    ValueT& operator[](const KeyT&);
    iterator insert(const Pair<KeyT, ValueT>&);
//    iterator find(const KeyT&);
//    iterator begin();
//    iterator end();
//    iterator first();
//    iterator last();
    const KeyT& min();
    const KeyT& max();
//    void clear();

  private:

  };

}

#endif // MAP_H

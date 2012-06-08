#ifndef TREE_H
#define TREE_H

namespace map {

  template<typename T, typename O>
  class TreeNode;

  template<typename T, typename O = Less<T> >
  class TreeIterator;


  template<typename T, typename O = Less<T> >
  class Tree {


  public:

    typedef TreeIterator<T,O> iterator;

    iterator insert(const T& value) {

    }

    void clear();

    iterator begin(){

    }

    iterator end();

    iterator first() {
      return iterator(m_root);
    }

    iterator last();

    iterator find(const T& value);

  private:
    TreeNode<T, O> m_root;
  };
}

#endif // TREE_H

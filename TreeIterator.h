#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "Tree.h"
#include "TreeNode.h"

namespace map {

  template<typename T, typename O>
  class TreeIterator {

  public:
    TreeIterator(TreeNode<T, O>* node){}

    T& operator*() {
    }

    T* operator->(){
    }

    TreeIterator<T, O>& operator++() {
    }

    TreeIterator<T, O>& operator--() {
    }

    bool operator == (const TreeIterator<T, O> & rhs);
    bool operator != (const TreeIterator<T, O> & rhs);

  private:
    Tree<T, O>*  m_tree;
    TreeNode<T, O>* m_current_node;
  };
}

#endif // TREEITERATOR_H

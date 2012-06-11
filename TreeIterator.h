#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "TreeNode.h"
#include "Tree.h"

namespace mystl {

  template<typename T, typename O>
  class TreeIterator {

  public:
    TreeIterator(TreeNode<T,O>* node, Tree<T, O>* tree): m_node(node), m_tree(tree){}

    T& operator*() {
      return m_node->m_value;
    }

    T* operator->() {
      return *(m_node->m_value);
    }

    TreeIterator<T,O>& operator++() {
      TreeNode<T,O>* node;
      if (this->m_node->m_right != 0) {
          node = this->m_node->m_right;
          while (node->m_left != 0)
            node = node->m_left;
        } else  {
          node = this->m_node;
          while (node->m_up != 0 && node->m_up->m_right == node)
            node = node->m_up;
          node = node->m_up;
        }

      this->m_node = node;
      return *this;
    }

    TreeIterator<T,O>& operator--() {
      TreeNode<T, O>* node;
      //new semicool stuff

      if(m_node == 0) {
          m_node =  m_tree->last ().m_node;
        } else if (m_node->m_left != 0) {
          m_node = m_node->m_left;
          while (m_node->m_right != 0) {
              m_node = m_node->m_right;
            }
        } else {
          node = m_node->m_up;
          while (node != 0 && m_node == node->m_left) {
              m_node = node;
              node = node->m_up;
            }
          m_node = node;
        }

      return *this;
    }

    bool operator == (const TreeIterator<T,O> & rhs) {
      if (rhs.m_node == 0 || this->m_node == 0)
        return rhs.m_node == this->m_node;

      return this->m_node->m_value == rhs.m_node->m_value;
    }

    bool operator != (const TreeIterator<T,O> & rhs) {
      if (rhs.m_node == 0 || this->m_node == 0)
        return rhs.m_node != this->m_node;

      return this->m_node->m_value != rhs.m_node->m_value;
    }

  private:
    TreeNode<T,O>* m_node;
    Tree<T,O>* m_tree;
  };
}

#endif // TREEITERATOR_H

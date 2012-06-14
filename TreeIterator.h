#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "TreeNode.h"
#include "Tree.h"

namespace mystl {

  template<typename T, typename O>

  /**
    * @brief The TreeIterator class
    *
    * Diese Klasse ist ein Hilfsmittel, um über die Elemente eines Baumes iterieren zu können.
    * Dafür wird für jede mögliche Operation eine Funktion bereitgestellt.
    */

  class TreeIterator {

  public:

    /**
     * @brief TreeIterator
     *
     * Konstruktor bei dem der Klasse zum iterieren über die Elemente einmal ein Knoten
     * und der Baum übergeben werden.
     * @param node
     * @param tree
     */
    TreeIterator(TreeNode<T,O>* node, Tree<T, O>* tree): m_node(node), m_tree(tree){}

    /**
     * @brief operator *
     *
     * Gibt die Referenz eines Wertes im Baum zurück, um nicht mit Pointern zu arbeiten.
     *
     * @return T&
     */
    T& operator*() {
      return m_node->m_value;
    }

    /**
     * @brief operator ->
     *
     *
     * @return
     */
    T* operator->() {
      return &(m_node->m_value);
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
      return (&this->m_node->m_value) == (&rhs.m_node->m_value);
    }

    bool operator != (const TreeIterator<T,O> & rhs) {
      if (rhs.m_node == 0 || this->m_node == 0)
        return rhs.m_node != this->m_node;
      return (&this->m_node->m_value) != (&rhs.m_node->m_value);
    }

  private:
    TreeNode<T,O>* m_node;
    Tree<T,O>* m_tree;
  };
}

#endif // TREEITERATOR_H

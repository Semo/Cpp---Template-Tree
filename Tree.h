#ifndef TREE_H
#define TREE_H

#include <TreeNode.h>
#include <TreeIterator.h>
#include <iostream>
#include <stack>

using namespace std;

namespace mystl {

  template<typename T, typename O = Less<T> >

  /**
   * @brief The Tree class
   *
   * Schnittstelle des Tree Containers
   *
   * @author François Dubois <siokdub@gmail.com>
   * @author Sebastian Morkisch <semox78@gmail.com>
   */
  class Tree {


  public:
    typedef TreeIterator<T,O> iterator;
    typedef TreeNode<T,O> node;

    /**
     * @brief Tree
     *
     * Der Konstruktor mit einem ersten root-Knoten.
     */
    Tree(): m_root(0){}

    /**
     * @brief insert
     *
     * Einfügen eines neuen Knotens. Falls der hinzuzufügende Knoten einen Schlüssel
     * besitzt, der im Baum schon vorhanden ist, wird der alte Knoten ersetzt.
     * @param value
     * @return iterator des neuen Knotens
     */
    iterator insert(const T& value) {
      if (m_root == 0) {
          m_root = new node(0);
          m_root->m_value = value;
        } else {
          node* foo = m_root->find(value);
          if (foo != 0) {
              foo->m_value = value;
            } else {
              node* pos = m_root;
              bool done = false;
              while (pos != 0 && !done) {
                  O order;
                  bool left = order(value, pos->m_value);
                  if (left) {
                      if (pos->m_left == 0) {
                          pos->m_left = new node(pos);
                          pos->m_left->m_value = value;
                          done = true;
                        }
                      pos = pos->m_left;
                    } else{
                      if (pos->m_right == 0) {
                          pos->m_right = new node(pos);
                          pos->m_right->m_value = value;
                          done  = true;
                        }
                      pos = pos->m_right;
                    }
                }
              iterator it(pos, this);
              return it;
            }

        }
      iterator it(m_root, this);
      return it;

    }

    /**
     * @brief clear
     *
     * Aufruf der Funktion: Löscht den Baum.
     */
    void clear() {
      freeNode(m_root);
      m_root = 0;
    }

    /**
     * @brief begin
     *
     * Setzt den Iterator auf den äußerst links gelegenen letzten Knoten.
     * @return iterator
     */
    iterator begin() {
      node* leftest = m_root;
      if(m_root == 0) {
          iterator i (0, this);
          return i;
        }
      while (leftest->m_left != 0) {
          leftest = leftest->m_left;
        }
      iterator i (leftest, this);
      return i;
    }

    /**
     * @brief end
     *
     * Liefert einen Nullzeiger. Markiert das Ende eines Asts.
     * @return iterator
     */
    iterator end() {
      iterator it (0, this);
      return it;
    }

    /**
     * @brief first
     *
     * Gibt den Zeiger auf den leftest Node zurück
     * @return iterator
     */
    iterator first() {
      node* firstNode;
      firstNode = m_root->findFirst();
      iterator it(firstNode, this);
      return it;
    }

    /**
     * @brief last
     *
     * Gibt den Zeiger auf den rightest Node zurück
     * @return iterator
     */
    iterator last() {
      node* lastNode;
      lastNode = m_root->findLast();
      iterator it(lastNode, this);
      return it;
    }

    /**
     * @brief find
     *
     * Gibt den Zeiger des Knotens zurück, der dem gesuchten Value entspricht
     * @param value
     * @return
     */
    iterator find(const T& value) {
      node* treeNode;
      treeNode = m_root->find(value);
      iterator it(treeNode,this);
      return it;
    }

  private:
    node* m_root;

    /**
     * @brief freeNode
     *
     * Hilfsfunktion zum Löschen der Knoten des Baums
     * @param treeNode
     */
    void freeNode(node* treeNode)
    {
      if (treeNode->m_left != 0)  {
          freeNode(treeNode->m_left);
        }
      if (treeNode->m_right != 0) {
          freeNode(treeNode->m_right);
        }
      delete treeNode;
    }

  };
}


#endif // TREE_H

#ifndef TREE_H
#define TREE_H

#include <TreeNode.h>
#include <TreeIterator.h>
#include <iostream>
#include <stack>

using namespace std;

namespace mystl {

  template<typename T, typename O = Less<T> >
  class Tree {


  public:
    typedef TreeIterator<T,O> iterator;
    typedef TreeNode<T,O> node;

    Tree(): m_root(0){}


    iterator insert(const T& value) {
      if (m_root == 0) {
          m_root = new node();
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
                          pos->m_left = new node();
                          pos->m_left->m_value = value;
                          pos->m_left->m_up = pos;
                          done = true;
                        }
                      pos = pos->m_left;
                    } else{
                      if (pos->m_right == 0) {
                          pos->m_right = new node();
                          pos->m_right->m_value = value;
                          pos->m_right->m_up = pos;
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

    void clear() {
      freeNode(m_root);
      m_root = 0;
    }

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

    iterator end() {
      iterator it (0, this);
      return it;
    }

    iterator first() {
      node* firstNode;
      firstNode = m_root->findFirst();
      iterator it(firstNode);
      return it;
    }

    iterator last() {
      node* lastNode;
      lastNode = m_root->findLast();
      iterator it(lastNode);
      return it;
    }

    iterator find(const T& value) {
      node treeNode;
      treeNode = m_root->find(value);
      iterator it(treeNode);
      return it;
    }

  private:
    node* m_root;

    //TODO refactor Destructor
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

#ifndef TREENODE_H
#define TREENODE_H

namespace map {

  template<typename T, typename O>
  class TreeNode {

    friend class TreeIterator<T, O>;
    friend class Tree<T, O>;

  public:
    T& value() {
      return m_value;
    }

    TreeNode(TreeNode<T,O> parent, T value) {}


    /**
      *
      *
      */
    TreeNode<T, O> *find(const T& value) {
      // ersten knoten setzen
      //      if(m_value == 0) {

      //        }
      if(m_value == value) {
          return this;
          //wenn im  Knoten wert nicht gefunden wurde und wert größer ist als der aktuelle knoten,
          //setze value und suche im linken Teilbaum weiter, sonst im rechten.
        }
      if (m_value > value) {
          find (m_left);
        }
      if (m_value < value) {
          if(m_left == 0) {

            }
          find (m_right);
        }
    }

    /**
      * Root Element zurückliefern.
      */
    TreeNode<T, O> *findFirst();

    TreeNode<T, O> *findLast();

  protected:
    TreeNode<T, O> *m_right;
    TreeNode<T, O> *m_left;
    TreeNode<T, O> *m_up;

  private:
    T m_value;

  };
}

#endif // TREENODE_H

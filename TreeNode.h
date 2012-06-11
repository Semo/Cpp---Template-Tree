#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

template<typename T, typename O>
class TreeIterator;

template<typename T, typename O>
class Tree;


template<typename T, typename O>
class TreeNode {

    friend class TreeIterator<T,O>;
    friend class Tree<T,O>;

    typedef TreeNode<T,O> node;

public:

    ~TreeNode() {
        m_right = 0;
        m_left = 0;
        m_up = 0;

    }

    T& value() {
        return m_value;
    }

    TreeNode<T,O>* find(const T& value) {
        if (m_value == value)
            return this;
        else {
            node* next = 0;
            O order;
            if (order(value, m_value))
                next = this->m_left;
            else
                next = this->m_right;

            if (next != 0)
                return next->find(value);
            else
                return 0;
        }
    }

    TreeNode<T,O>* findFirst() {
        node* firstNode = this;
        while(firstNode->m_left != 0) {
            firstNode = firstNode->m_left;
        }
        return firstNode;
    }

    TreeNode<T,O>* findLast() {
        node* lastNode = this;
        while(lastNode->m_right != 0) {
            lastNode = lastNode->m_right;
        }
        return lastNode;
    }


protected:
    TreeNode<T,O>*  m_right;
    TreeNode<T,O>*  m_left;
    TreeNode<T,O>*  m_up;
    T m_value;
};
}

#endif // TREENODE_H

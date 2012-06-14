#ifndef TREENODE_H
#define TREENODE_H

namespace mystl {

template<typename T, typename O>
class TreeIterator;

template<typename T, typename O>
class Tree;


template<typename T, typename O>

/**
 * @brief The TreeNode class
 *
 * Diese Klasse repräsentiert einen Knoten eines Baumes.
 *
 * @author François Dubois <siokdub@gmail.com>
 * @author Sebastian Morkisch <semox78@gmail.com>
 */
class TreeNode {

    friend class TreeIterator<T,O>;
    friend class Tree<T,O>;

    typedef TreeNode<T,O> node;

public:

    /**
     * @brief TreeNode
     *
     * Konstruktor. Beim Erstellen des Baumes, werden sämtliche Zeiger auf andere Elemente auf
     * Null initialisiert.
     * @param up
     */
    TreeNode(node* up) {

        m_right = 0;
        m_left = 0;
        m_up = up;

    }

    /**
     * @brief value
     *
     * Gibt den Wert des Knotens zurück.
     * @return
     */
    T& value() {
        return m_value;
    }

    /**
     * @brief find
     *
     * Gibt den Knoten zurück, der dem gesuchten Value entspricht
     * oder gibt Null zurück.
     * @param value
     * @return TreeNode
     */
    TreeNode<T,O>* find(const T& value) {
        if (m_value == value) {
            return this;
        }
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

    /**
     * @brief findFirst
     *
     * Gibt den Leftest Node zurück.
     * @return TreeNode
     */
    TreeNode<T,O>* findFirst() {
        node* firstNode = this;
        while(firstNode->m_left != 0) {
            firstNode = firstNode->m_left;
        }
        return firstNode;
    }

    /**
     * @brief findLast
     *
     * Gibt den rightestNode zurück.
     * @return TreeNode
     */
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

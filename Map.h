#ifndef MAP_H
#define MAP_H

#include "Tree.h"
#include "pair.h"
#include "mapToFirst.h"


namespace mystl {

  template <typename KeyT, typename ValueT, typename OrderT = MapToFirst<KeyT, ValueT, Less> >

  /**
   * @brief The Map class
   *
   * Ermöglicht wahlfreien Zugriff auf einzelne Elemente eines Baums mittels
   * Index Operator. In seiner Benutzung verhält es sich, als würde man einen
   * Array benutzen. Für eine vereinfachte Benutzung gibt es hilfsfunktionen,
   * die andere low-level Funktionen benutzen.
   *
   * @author François Dubois <siokdub@gmail.com>
   * @author Sebastian Morkisch <semox78@gmail.com>
   */

  class Map {

  public:

    typedef Pair<KeyT, ValueT> valueType;
    typedef TreeIterator<valueType, OrderT> iterator;

    /**
     * @brief operator []
     *
     * Dient dem speichern eines Wertes an die Stelle von einem geg. Indizee
     * @param key
     * @return iterator mit dem gefundenen/überschriebenen Wert
     */
    ValueT& operator[](const KeyT& key) {
      iterator it = find(key);
      if(it == tree.end()) {
          valueType vt(key,ValueT());
          return this->insert(vt)->second();
        } else {
          return it->second();
        }
    }

    /**
     * @brief find
     *
     * Suche einen Wert im Baum mittels der Referenz eines Keys.
     * @param key
     * @return iterator mit dem gefundenen Wert/ Nulliterator falls Wert unauffindbar
     */
    iterator find(const KeyT& key) {
      valueType vt(key,ValueT());
      return tree.find(vt);
    }

    /**
     * @brief insert
     *
     * Einfügen eines Wertes in den Baum
     * @param key
     * @return iterator mit neuem/überschriebenen Wert
     */
    iterator insert(const valueType& value) {
      return tree.insert(value);
    }

    /**
     * @brief begin
     *
     * Startiterator eines Baumes. --> leftest Node
     * @param key
     * @return iterator
     */
    iterator begin() {
      return tree.begin();
    }

    /**
     * @brief end
     *
     * Der Iterator nach dem letzten Element zeigt auf einen nicht vorhandenen Knoten.
     * Das ist ein Nullzeiger. (Null Iterator --> Ende des Baumes)
     * @return iterator
     */
    iterator end() {
      return tree.end();
    }

    /**
     * @brief first
     *
     * Zeiger auf den leftest Node im Baum. (most left)
     * @return iterator
     */
    iterator first() {
      return tree.first();
    }

    /**
     * @brief last
     *
     * Gibt einen Zeiger auf den rightest Node wieder.
     * @return iterator
     */
    iterator last() {
      return tree.last();
    }

    /**
     * @brief min
     *
     * Gibt den Wert des leftest Node zurück.
     * @return den kleinsten Schlüssel
     */

    const KeyT& min() {
      return first()->first();
    }

    /**
     * @brief max
     *
     * Gibt den Wert des rightest Node zurück.
     * @return den größten Schlüssel
     */
    const KeyT& max() {
      return last()->first();
    }

    /**
     * @brief clear
     *
     * Dient der Löschung des gesamten Baumes.
     */
    void clear() {
      tree.clear();
    }

  private:
    Tree<valueType, OrderT> tree;
    ValueT v;
  };
}

#endif // MAP_H

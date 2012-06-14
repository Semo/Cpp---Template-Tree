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
     * Benutzung des Array-Operators für den Zugriff
     * @param key
     * @return Value of Type
     */
    ValueT& operator[](const KeyT& key) {
//      iterator it = find(key);
//      if(it == tree.end()) {
//          valueType vt(key,ValueT());
//          v = insert(vt)->second();
//          return v;
//        } else {
//          v = it->second();
//          return v;
//        }
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
     * Dient dem Auffinden eines Wertes im Speicherbereich.
     * @param key
     * @return iterator mit dem gefundenen Wert
     */
    iterator find(const KeyT& key) {
      valueType vt(key,ValueT());
      return tree.find(vt);
    }

    /**
     * @brief insert
     *
     * Dient dem Auffinden eines Wertes im Speicherbereich.
     * @param key
     * @return iterator mit dem gefundenen Wert
     */
    iterator insert(const valueType& value) {
      return tree.insert(value);
    }

    /**
     * @brief begin
     *
     * Startwert von dem aus eine Suche im Baum beginnt.
     * @param key
     * @return iterator mit dem ersten gefundenen Wert
     */
    iterator begin() {
      return tree.begin();
    }

    /**
     * @brief end
     *
     * Wenn das Ende eines Astes erreicht wurde, wird ein iterator
     * mit der zuletzt erreichten Stelle returniert, wobei das end Element
     * noch hinter das letzte Element zeigt.
     * @return iterator mit dem letzten gefundenen Wert
     */
    iterator end() {
      return tree.end();
    }

    /**
     * @brief first
     *
     * Erstes Element im Baum, die Wurzel.
     * @return iterator mit der Wurzel des Baumes
     */
    iterator first() {
      return tree.first();
    }

    /**
     * @brief last
     *
     * Gibt einen Iterator mit dem letzten Element zurück, bevor
     * end () erreicht wird.
     * @return iterator mit dem vorletzten Element auf einem Ast
     */
    iterator last() {
      return tree.last();
    }

    /**
     * @brief min
     *
     * min gibt den kleineren zweier Schlüssel zurück.
     * @return
     */
    const KeyT& min() {
      return first()->first();
    }

    /**
     * @brief max
     *
     * max gibt den größeren zweier Schlüssel zurück.
     * @return
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

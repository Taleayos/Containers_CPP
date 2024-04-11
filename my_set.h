#ifndef MY_SET_H_
#define MY_SET_H_

#include "my_tree.h"

namespace my {

template <typename Key, typename Comparator = std::less<Key>>
class Set : public AVLTree<Key, Comparator> {
 public:
  // Внутриклассовые переопределения типов:
  // тип элемента множества
  using key_type = typename AVLTree<Key, Comparator>::key_type;
  // итератор для множества
  using iterator = typename AVLTree<Key, Comparator>::iterator;
  // тип бинарного дерева для множества
  using tree_type = typename AVLTree<Key, Comparator>::tree_type;

  // конструктор по умолчанию
  Set() : tree_type() {}
  // конструктор c инициализацией через список
  Set(std::initializer_list<key_type> const &items) : tree_type(items, true) {}
  // вставляет во множество новый элемент
  std::pair<iterator, bool> Insert(const key_type &key) {
    return tree_type::Insert(key, true);
  }
  // объединяет дерево с элементами другого дерева
  void Merge(tree_type &other) { tree_type::Merge(other, true); }
  // размещает список значений во множество
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args &&...args) {
    return tree_type::Emplace(true, args...);
  }
};

}  // namespace my

#endif  // MY_SET_H_

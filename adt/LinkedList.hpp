#pragma once

#include <initializer_list>
#include <memory>

using std::initializer_list;
using std::make_shared;
using std::shared_ptr;

namespace adt {

template <typename Item>
struct Node {
  Item item;
  shared_ptr<Node<Item>> previous;
  shared_ptr<Node<Item>> next;
  Node() = delete;
  Node(Item const& value) : item{value} {};  // use type traits???
  Node(Item&& value) : item{std::move(value)} {};
};

template <typename Item>
class DoubleLinkedList {
 private:
  shared_ptr<Node<Item>> head_;
  shared_ptr<Node<Item>> tail_;
  size_t size_ = 0;

 public:
  DoubleLinkedList(){};
  DoubleLinkedList(initializer_list<Item> items_list);
  constexpr size_t size() { return size_; }
  constexpr shared_ptr<Node<Item>> tail() { return tail_; }
  void AddToTail(Item const& item);
};
}  // namespace adt

template <typename Item>
adt::DoubleLinkedList<Item>::DoubleLinkedList(initializer_list<Item> items_list) {
  for (auto const& item : items_list) {
    AddToTail(item);
  }
}

template <typename Item>
void adt::DoubleLinkedList<Item>::AddToTail(Item const& item) {
  if (!tail_) {  // empty list
    head_ = make_shared<Node<Item>>(item);
    tail_ = head_;
  } else {
    auto new_node = make_shared<Node<Item>>(item);
    new_node->previous = tail_;
    tail_->next = new_node;
    tail_ = new_node;
  }
  ++size_;
}

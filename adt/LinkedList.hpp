#pragma once

namespace adt {

template <typename Item>
class SinglyLinkedList {
  template <typename Item>
  struct Node {
    using NodeT = Node<Item>;

    Item item;
    std::shared_ptr<NodeT> next;  // use of unique_ptr would make impossible to copy Node

    Node() = delete;
    Node(NodeT const& node) : item{node.item}, next{node.next} {};
    Node(NodeT&& node) noexcept : item{std::move(node.value)}, next{std::move(node.next)} {};

    explicit Node(Item item_copy) : item{std::move(item_copy)}, next{nullptr} {};
    explicit Node(Item&& item_rvalue) : item{item_rvalue}, next{nullptr} {};
  };

  std::shared_ptr<Node<Item>> head_;

 public:
  SinglyLinkedList() = default;
  ~SinglyLinkedList() {
    if (head_) {
      while (head_->next) {
        head_ = std::move(head_->next);
      }
    }
  };

  SinglyLinkedList(std::initializer_list<Item> items_list);

  [[nodiscard]] auto size() const -> size_t;
  [[nodiscard]] auto IsEmpty() const -> bool { return head_ == nullptr; }

  void PushBack(Item item);
  void PushFront(Item item);
};
}  // namespace adt

template <typename Item>
adt::SinglyLinkedList<Item>::SinglyLinkedList(std::initializer_list<Item> items_list) {
  for (const auto* j{std::prev(items_list.end())}; j >= items_list.begin(); --j) {
    PushFront(*j);
  }
}

template <typename Item>
auto adt::SinglyLinkedList<Item>::size() const -> size_t {
  if (IsEmpty()) {
    return 0;
  }
  size_t size{1};
  for (auto temp = head_; temp->next; temp = temp->next) {
    ++size;
  }
  return size;
}

template <typename Item>
void adt::SinglyLinkedList<Item>::PushBack(Item item) {
  if (!head_) {
    head_ = std::make_shared<Node<Item>>(item);
  } else {
    auto temp = head_;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = std::make_shared<Node<Item>>(item);
  }
}

template <typename Item>
void adt::SinglyLinkedList<Item>::PushFront(Item item) {
  auto new_node = std::make_shared<Node<Item>>(item);
  if (!head_) {
    head_ = new_node;
  } else {
    new_node->next = head_;
    head_ = new_node;
  }
}

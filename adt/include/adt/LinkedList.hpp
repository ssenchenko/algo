#pragma once

#include <memory>
#include <utility>

namespace adt {

template <typename Item>
class SinglyLinkedList
{
  template <typename T>
  struct Node
  {
    using SelfT = Node<T>;

    T item;
    std::shared_ptr<SelfT> next; // use of unique_ptr would make impossible to copy Node

    Node() = delete;
    explicit Node(T item_copy) : item{item_copy}, next{nullptr} {};
    explicit Node(T&& item_rvalue) : item{std::move(item_rvalue)}, next{nullptr} {};

    ~Node() = default;

    Node(const SelfT& node) : item{node.item}, next{node.next} {};
    // when we move rvalue, we don't want to keep a pointer because that memory will probably be
    // disposed
    Node(SelfT&& node) noexcept : item{std::move(node.value)}, next{nullptr} {};

    SelfT& operator=(const SelfT& other)
    {
      item = other.item;
      next = other.next;
      return *this;
    };
    SelfT& operator=(SelfT&& other) noexcept
    {
      item = std::move(other.item);
      next = std::move(other.next);
      return *this;
    };
  };

  using NodeT = Node<Item>;

  std::shared_ptr<NodeT> head_;

public:
  SinglyLinkedList() = default;
  ~SinglyLinkedList()
  {
    if (head_) {
      while (head_->next) {
        head_ = std::move(head_->next);
      }
    }
  };
  SinglyLinkedList(const SinglyLinkedList<Item>& other);
  SinglyLinkedList(SinglyLinkedList&& rvalue) noexcept;

  SinglyLinkedList(std::initializer_list<Item> items_list);

  SinglyLinkedList<Item>& operator=(const SinglyLinkedList& other) = delete;
  SinglyLinkedList<Item>& operator=(SinglyLinkedList<Item>&& rvalue) = delete;

  [[nodiscard]] size_t size() const;
  [[nodiscard]] bool IsEmpty() const
  {
    return head_ == nullptr;
  }

  class Iterator;

  Iterator begin()
  {
    return Iterator(head_);
  };
  Iterator end()
  {
    return Iterator(nullptr);
  };

  Iterator PushBack(Item item);
  Iterator PushFront(Item item);

  class Iterator
  {
    std::shared_ptr<NodeT> node_ptr_;

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Item;
    using difference_type = std::ptrdiff_t;
    using pointer = std::shared_ptr<value_type>;
    using reference = value_type&;

    explicit Iterator(std::shared_ptr<NodeT> ptr) : node_ptr_{ptr} {};
    ~Iterator() = default;
    Iterator(const Iterator& other) : node_ptr_{other.node_ptr_} {};
    Iterator(Iterator&& other) noexcept : node_ptr_{std::move(other.node_ptr_)} {};

    Iterator& operator=(Iterator const& other)
    {
      node_ptr_ = other.node_ptr_;
      return *this;
    };
    Iterator& operator=(Iterator&& other) noexcept
    {
      node_ptr_ = std::move(other.node_ptr_);
      return *this;
    }

    reference operator*() const
    {
      return node_ptr_->item;
    };
    pointer operator->() const
    {
      // should be checked!!
      return node_ptr_->item;
    };

    Iterator& operator++()
    {
      node_ptr_ = node_ptr_->next;
      return *this;
    };
    Iterator operator++(int)
    {
      Iterator copy = *this;
      node_ptr_ = node_ptr_->next;
      return copy;
    };

    friend bool operator==(const Iterator& lhs, const Iterator& rhs)
    {
      return lhs.node_ptr_ == rhs.node_ptr_;
    };

    friend bool operator!=(const Iterator& lhs, const Iterator& rhs)
    {
      return lhs.node_ptr_ != rhs.node_ptr_;
    };
  };
};
} // namespace adt

template <typename Item>
adt::SinglyLinkedList<Item>::SinglyLinkedList(const adt::SinglyLinkedList<Item>& other)
{
  if (!other.head_)
    return;
  auto current_other = other.head_;
  head_ = std::make_shared<NodeT>(other.head_->item);
  auto current_this = head_;
  while (current_other->next) {
    current_this->next = std::make_shared<NodeT>(current_other->next->item);
    current_other = current_other->next;
    current_this = current_this->next;
  }
}

template <typename Item>
adt::SinglyLinkedList<Item>::SinglyLinkedList(adt::SinglyLinkedList<Item>&& rvalue) noexcept
{
  auto current = head_;
  while (rvalue.head_) {
    current = std::make_shared<NodeT>(std::move(rvalue.head_)); // moves only item
    rvalue.head_ = rvalue.head_->next;                          // shortens the chain
    // current =
  }
}

template <typename Item>
adt::SinglyLinkedList<Item>::SinglyLinkedList(std::initializer_list<Item> items_list)
{
  // initializer_list doesn't have reverse iterator :(
  for (auto j{std::prev(items_list.end())}; j >= items_list.begin(); --j) {
    PushFront(*j);
  }
}

template <typename Item>
size_t adt::SinglyLinkedList<Item>::size() const
{
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
typename adt::SinglyLinkedList<Item>::Iterator adt::SinglyLinkedList<Item>::PushBack(Item item)
{
  if (!head_) {
    head_ = std::make_shared<NodeT>(item);
    return adt::SinglyLinkedList<Item>::Iterator(head_);
  }
  else {
    auto temp = head_;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = std::make_shared<NodeT>(item);
    return adt::SinglyLinkedList<Item>::Iterator(temp->next);
  }
}

template <typename Item>
typename adt::SinglyLinkedList<Item>::Iterator adt::SinglyLinkedList<Item>::PushFront(Item item)
{
  auto new_node = std::make_shared<Node<Item>>(item);
  if (!head_) {
    head_ = new_node;
  }
  else {
    new_node->next = head_;
    head_ = new_node;
  }
  return adt::SinglyLinkedList<Item>::Iterator(head_);
}

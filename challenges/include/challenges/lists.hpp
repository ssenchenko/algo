#pragma once

#include <memory>
namespace chl {
template <typename T>
struct SinglyLinkedNode
{
  T val;
  std::shared_ptr<SinglyLinkedNode<T>> next;

  using NodePtr = std::shared_ptr<SinglyLinkedNode<T>>;

  SinglyLinkedNode() = delete;
  explicit SinglyLinkedNode(T value) : val{value}, next{nullptr} {};
  SinglyLinkedNode(T value, NodePtr next_node_ptr) : val{value}, next{next_node_ptr} {};

  ~SinglyLinkedNode() = default;
  SinglyLinkedNode(const SinglyLinkedNode<T>& other) : val{other.val}, next{other.next} {};
  SinglyLinkedNode(SinglyLinkedNode<T>&& rvalue) noexcept
      : val{std::move(rvalue.val)}, next{std::move(rvalue.next)} {};

  SinglyLinkedNode<T>& operator=(const SinglyLinkedNode<T>& other)
  {
    if (this != &other) {
      val = other.val;
      next = other.next;
    }
    return *this;
  }

  SinglyLinkedNode<T>& operator=(SinglyLinkedNode<T>&& rvalue) noexcept
  {
    val = std::move(rvalue.val);
    next = std::move(rvalue.next);
    return *this;
  }
};

template <typename T>
using NodePtr = std::shared_ptr<SinglyLinkedNode<T>>;

/**
 * @brief Add two numbers represented as singly linked lists.
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 *  2-> 4-> 3
 * +
 *  5-> 6-> 4
 * =
 *  7-> 0-> 8
 *
 * @param l1 first list-number
 * @param l2 second list-number
 * @return pointer to a list containing the sum list-number
 */
std::shared_ptr<SinglyLinkedNode<int>> AddNumbers(std::shared_ptr<const SinglyLinkedNode<int>> l1,
                                                  std::shared_ptr<const SinglyLinkedNode<int>> l2);
} // namespace chl

#include "challenges/lists.hpp"

#include <gtest/gtest.h>

using chl::AddNumbers, chl::SinglyLinkedNode;

/**
 * @brief Create a List object from a vector.
 *
 * For TEST purposes ONLY
 *
 * @param digits
 * @return std::shared_ptr<SinglyLinkedNode<int>>
 */
std::shared_ptr<SinglyLinkedNode<int>> CreateList(const std::initializer_list<int>& digits)
{
  std::shared_ptr<SinglyLinkedNode<int>> head;
  std::shared_ptr<SinglyLinkedNode<int>> curr;
  for (auto&& d : digits) {
    if (!curr) {
      curr = std::make_shared<SinglyLinkedNode<int>>(d);
    }
    else {
      curr->next = std::make_shared<SinglyLinkedNode<int>>(d);
      curr = curr->next;
    }
    if (!head) {
      head = curr;
    }
  }
  return head;
}

bool AreEqual(std::shared_ptr<const SinglyLinkedNode<int>> lhs,
              std::shared_ptr<const SinglyLinkedNode<int>> rhs)
{
  while (rhs && lhs) {
    if (lhs->val != rhs->val)
      return false;
    lhs = lhs->next;
    rhs = rhs->next;
  }
  if (lhs || rhs)
    return false;
  return true;
}

TEST(AddNumbers, when_same_number_of_digits)
{
  auto l1 = CreateList({2, 4, 3});
  auto l2 = CreateList({5, 6, 4});
  auto expected = CreateList({7, 0, 8});
  EXPECT_TRUE(AreEqual(expected, AddNumbers(l1, l2)));
}

TEST(AddNumbers, when_same_number_of_digits_with_carry_over)
{
  auto l1 = CreateList({2, 4, 9});
  auto l2 = CreateList({5, 6, 4});
  auto expected = CreateList({7, 0, 4, 1});
  EXPECT_TRUE(AreEqual(expected, AddNumbers(l1, l2)));
}

TEST(AddNumbers, when_different_number_of_digits)
{
  auto l1 = CreateList({9, 9, 9, 9, 9, 9, 9});
  auto l2 = CreateList({9, 9, 9, 9});
  auto expected = CreateList({8, 9, 9, 9, 0, 0, 0, 1});
  EXPECT_TRUE(AreEqual(expected, AddNumbers(l1, l2)));
}

TEST(AddNumbers, when_one_list_is_empty)
{
  auto l2 = CreateList({5, 6, 4});
  auto expected = CreateList({5, 6, 4});
  EXPECT_TRUE(AreEqual(expected, AddNumbers(std::shared_ptr<SinglyLinkedNode<int>>(nullptr), l2)));
}

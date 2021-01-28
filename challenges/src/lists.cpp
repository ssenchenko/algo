#include "challenges/lists.hpp"

#include <utility>

using chl::SinglyLinkedNode, chl::NodePtr;

std::shared_ptr<SinglyLinkedNode<int>>
chl::AddNumbers(std::shared_ptr<const SinglyLinkedNode<int>> l1,
                std::shared_ptr<const SinglyLinkedNode<int>> l2)
{
  constexpr int BASE = 10;

  auto AddNumbers = [](int rhn, int lhn) {
    auto res = lhn + rhn;
    auto carry_over = 0;
    if (res >= BASE) {
      carry_over = 1;
      res -= BASE;
    }
    return std::make_pair(res, carry_over);
  };

  auto FinishLastList = [&AddNumbers](std::shared_ptr<const SinglyLinkedNode<int>> source,
                                      std::shared_ptr<SinglyLinkedNode<int>> target,
                                      int num,
                                      int carry_over) {
    while (source->next) {
      source = source->next;
      std::tie(num, carry_over) = AddNumbers(source->val, carry_over);
      target->next = std::make_shared<SinglyLinkedNode<int>>(num);
      target = target->next;
    }
    return std::make_pair(target, carry_over);
  };

  auto CopyList = [&FinishLastList](const std::shared_ptr<const SinglyLinkedNode<int>>& source) {
    auto num = source->val;
    auto current = std::make_shared<SinglyLinkedNode<int>>(num);
    auto head = current;
    FinishLastList(source, current, num, 0);
    return head;
  };

  if (!(l1 || l2)) {
    return nullptr;
  }
  if (!l1) {
    return CopyList(l2);
  }
  if (!l2) {
    return CopyList(l1);
  }

  auto [num, carry_over] = AddNumbers(l1->val, l2->val);
  auto current = std::make_shared<SinglyLinkedNode<int>>(num);
  auto head = current;

  while (l1->next && l2->next) {
    l1 = l1->next;
    l2 = l2->next;
    std::tie(num, carry_over) = AddNumbers(l1->val, l2->val + carry_over);
    current->next = std::make_shared<SinglyLinkedNode<int>>(num);
    current = current->next;
  }

  if (l1->next) {
    std::tie(current, carry_over) = FinishLastList(l1, current, num, carry_over);
  }
  else if (l2->next) {
    std::tie(current, carry_over) = FinishLastList(l2, current, num, carry_over);
  }

  if (carry_over != 0) {
    current->next = std::make_shared<SinglyLinkedNode<int>>(carry_over);
  }

  return head;
}

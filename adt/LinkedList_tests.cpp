#include <gtest/gtest.h>

#include "./LinkedList.hpp"

using namespace adt;

TEST(LinkedList, AddToTail) {
  auto list = adt::DoubleLinkedList<int>();
  list.AddToTail(1);
  ASSERT_EQ(list.size(), 1);
  ASSERT_EQ(list.tail()->item(), 1);
  list.AddToTail(2);
  ASSERT_EQ(list.size(), 2);
  ASSERT_EQ(list.tail()->item(), 2);
}

TEST(LinkedList, InitializerList) {
  adt::DoubleLinkedList<int> list{1, 2};
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.tail()->item(), 2);
}
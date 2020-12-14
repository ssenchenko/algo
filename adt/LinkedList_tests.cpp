#include <gtest/gtest.h>

#include "./LinkedList.hpp"

using namespace adt;

TEST(SinglyLinkedList, DefaultConstructor_CreatesEmptyList) {
  auto list = adt::SinglyLinkedList<int>();
  EXPECT_TRUE(list.IsEmpty());
  EXPECT_EQ(0, list.size());
}

TEST(SinglyLinkedList, PushBack_AddsHead) {
  auto list = adt::SinglyLinkedList<int>();
  list.PushBack(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(1, list.size());
}

TEST(SinglyLinkedList, PushBack_AddsAfterHead) {
  auto list = adt::SinglyLinkedList<int>();
  list.PushBack(1);
  list.PushBack(1);
  list.PushBack(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(3, list.size());
}

TEST(SinglyLinkedList, PushFront_AddsHead) {
  auto list = adt::SinglyLinkedList<int>();
  list.PushFront(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(1, list.size());
}

TEST(SinglyLinkedList, PushFront_AddsBeforeHead) {
  auto list = adt::SinglyLinkedList<int>();
  list.PushFront(1);
  list.PushFront(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(2, list.size());
}

TEST(SinglyLinkedList, InitializerList) {
  adt::SinglyLinkedList<int> list{1, 2};
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(list.size(), 2);
}


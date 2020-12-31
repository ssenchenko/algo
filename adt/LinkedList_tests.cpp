#include <gtest/gtest.h>

#include "./LinkedList.hpp"

using adt::SinglyLinkedList;

TEST(SinglyLinkedList, CreatesEmptyList)
{
  auto list = SinglyLinkedList<int>();
  EXPECT_TRUE(list.IsEmpty());
  EXPECT_EQ(0, list.size());
}

TEST(SinglyLinkedList, PushBackAddsHead)
{
  auto list = SinglyLinkedList<int>();
  auto tail = list.PushBack(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(1, list.size());
  EXPECT_EQ(1, *tail);
}

TEST(SinglyLinkedList, AddsAfterHead)
{
  auto list = SinglyLinkedList<int>();
  list.PushBack(1);
  list.PushBack(1);
  list.PushBack(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(3, list.size());
}

TEST(SinglyLinkedList, PushFrontAddsHead)
{
  auto list = SinglyLinkedList<int>();
  list.PushFront(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(1, list.size());
}

TEST(SinglyLinkedList, AddsBeforeHead)
{
  auto list = SinglyLinkedList<int>();
  list.PushFront(1);
  list.PushFront(1);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(2, list.size());
}

TEST(SinglyLinkedList, InitializerList)
{
  SinglyLinkedList<int> list{1, 2};
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(list.size(), 2);
}

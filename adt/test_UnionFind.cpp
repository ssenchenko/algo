#include <gtest/gtest.h>

#include "./UnionFind.h"

using namespace algo;

TEST(UnionFind, AddAndTestDirectConnection) {
  auto uf = algo::UnionFind<int>();
  uf.Connect({3, 5});
  EXPECT_TRUE(uf.AreConnected({3, 5}));
}

TEST(UnionFind, AddAndTestIndirectConnection) {
  auto uf = algo::UnionFind<int>();
  uf.Connect({1, 2});
  uf.Connect({2, 3});
  uf.Connect({1, 4});
  uf.Connect({3, 5});
  auto connected = uf.AreConnected({1, 5});
  EXPECT_TRUE(connected);
  EXPECT_FALSE(uf.AreConnected({1, 7}));
}
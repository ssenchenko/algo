#include <gtest/gtest.h>

#include "challenges/dp.hpp"

TEST(OddEvenJumps, Example1)
{
  chl::OddEvenJumps test{10, 13, 12, 14, 15};
  std::vector<int> expected_odd{2, 3, 3, 4, -1};
  EXPECT_EQ(test.odd_jumps(), expected_odd);
  std::vector<int> expected_even{-1, 2, -1, -1, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 2);
}

TEST(OddEvenJumps, Example2)
{
  chl::OddEvenJumps test{2, 3, 1, 1, 4};
  std::vector<int> expected{1, 4, 3, 4, -1};
  EXPECT_EQ(test.odd_jumps(), expected);
  std::vector<int> expected_even{2, 2, 3, -1, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 3);
}

TEST(OddEvenJumps, Example3)
{
  chl::OddEvenJumps test{5, 1, 3, 4, 2};
  std::vector<int> expected{-1, 4, 3, -1, -1};
  EXPECT_EQ(test.odd_jumps(), expected);
  std::vector<int> expected_even{3, -1, 4, 4, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 3);
}

TEST(MaxFruitNumber, GatherAll)
{
  std::vector trees{1, 2, 1};
  EXPECT_EQ(3, chl::MaxFruitNumber(trees));
}

TEST(MaxFruitNumber, OmitFirst)
{
  std::vector trees{0, 1, 2, 2};
  EXPECT_EQ(3, chl::MaxFruitNumber(trees));
}

TEST(MaxFruitNumber, OmitFirstAgain)
{
  std::vector trees{1, 2, 3, 2, 2};
  EXPECT_EQ(4, chl::MaxFruitNumber(trees));
}

TEST(MaxFruitNumber, OneMoreExample)
{
  std::vector trees{1, 0, 3, 4, 3};
  EXPECT_EQ(3, chl::MaxFruitNumber(trees));
}

TEST(MaxFruitNumber, LongSequence)
{
  std::vector trees{1, 1, 6, 5, 6, 6, 1, 1, 1, 1};
  EXPECT_EQ(6, chl::MaxFruitNumber(trees));
}

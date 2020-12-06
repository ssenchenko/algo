#include <gtest/gtest.h>

#include <exception>

#include "arrays.hpp"

using namespace std::literals::string_literals;

TEST(Has_All_Unique, EmptyString) { EXPECT_TRUE(chl::HasAllUnique("")); }
TEST(Has_All_Unique, AllUnique) {
  EXPECT_TRUE(chl::HasAllUnique("2"));
  EXPECT_TRUE(chl::HasAllUnique("2dfg$Sp[D"));
}
TEST(Has_All_Unique, NotUnique) { EXPECT_FALSE(chl::HasAllUnique("2dfg$Sp[d")); }

TEST(Has_All_Unique2, EmptyString) { EXPECT_TRUE(chl::HasAllUnique2("")); }
TEST(Has_All_Unique2, AllUnique) {
  EXPECT_TRUE(chl::HasAllUnique2("2"));
  EXPECT_TRUE(chl::HasAllUnique2("2dfg$Sp[D"));
}
TEST(Has_All_Unique2, NotUnique) { EXPECT_FALSE(chl::HasAllUnique2("2dfg$Sp[d")); }

TEST(IsPermutation, DifferentSizes) { EXPECT_FALSE(chl::IsPermutation("wer", "wert")); }
TEST(IsPermutation, Identical) { EXPECT_FALSE(chl::IsPermutation("left", "left")); }
TEST(IsPermutation, OneEmpty) { EXPECT_FALSE(chl::IsPermutation("", "left")); }
TEST(IsPermutation, BothEmpty) { EXPECT_FALSE(chl::IsPermutation("", "")); }
TEST(IsPermutation, Permutation) { EXPECT_TRUE(chl::IsPermutation("felt", "left")); }
TEST(IsPermutation, NotPermutation) { EXPECT_FALSE(chl::IsPermutation("lift", "tiff")); }
TEST(IsPermutation, NotPermutationNewChar) { EXPECT_FALSE(chl::IsPermutation("lift", "shit")); }

TEST(Urlify, SingleSpaces) { EXPECT_EQ(chl::Urlify("Mr John Smith    ", 13), "Mr%20John%20Smith"); }
TEST(Urlify, ManyConsecutiveSpaces) {
  EXPECT_EQ(chl::Urlify("Mr  John Smith      ", 14), "Mr%20%20John%20Smith");
}
TEST(Urlify, OnlySpaces) { EXPECT_EQ(chl::Urlify("      ", 2), "%20%20"); }
TEST(Urlify, NoSpaces) { EXPECT_EQ(chl::Urlify("John", 4), "John"); }
TEST(Urlify, Empty) { EXPECT_EQ(chl::Urlify("", 0), ""); }

TEST(CountUniqueEmails, ItWorks) {
  std::vector<std::string> emails{"test.email+alex@leetcode.com"s,
                                  "test.e.mail+bob.cathy@leetcode.com"s,
                                  "testemail+david@lee.tcode.com"s};
  EXPECT_EQ(chl::CountUniqueEmails(emails), 2);
}

TEST(OddEvenJumps, Example1) {
  chl::OddEvenJumps test{10, 13, 12, 14, 15};
  std::vector<int> expected_odd{2, 3, 3, 4, -1};
  EXPECT_EQ(test.odd_jumps(), expected_odd);
  std::vector<int> expected_even{-1, 2, -1, -1, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 2);
}

TEST(OddEvenJumps, Example2) {
  chl::OddEvenJumps test{2, 3, 1, 1, 4};
  std::vector<int> expected{1, 4, 3, 4, -1};
  EXPECT_EQ(test.odd_jumps(), expected);
  std::vector<int> expected_even{2, 2, 3, -1, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 3);
}

TEST(OddEvenJumps, Example3) {
  chl::OddEvenJumps test{5, 1, 3, 4, 2};
  std::vector<int> expected{-1, 4, 3, -1, -1};
  EXPECT_EQ(test.odd_jumps(), expected);
  std::vector<int> expected_even{3, -1, 4, 4, -1};
  EXPECT_EQ(test.even_jumps(), expected_even);
  EXPECT_EQ(test(), 3);
}

#include <gtest/gtest.h>

#include "arrays.hpp"

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

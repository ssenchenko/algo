#include "./arrays.hpp"

#include <gtest/gtest.h>


TEST(Has_All_Unique, EmptyString) {
  EXPECT_TRUE(chl::HasAllUnique(""));
}

TEST(Has_All_Unique, AllUnique) {
  EXPECT_TRUE(chl::HasAllUnique("2"));
  EXPECT_TRUE(chl::HasAllUnique("2dfg$Sp[D"));
}

TEST(Has_All_Unique, NotUnique) {
  EXPECT_TRUE(chl::HasAllUnique("2dfg$Sp[d"));
}

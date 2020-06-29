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

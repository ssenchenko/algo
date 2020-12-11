#include <gtest/gtest.h>

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

TEST(LicenseKeyFormatting, EqualNoInGroups) {
  EXPECT_EQ("5F3Z-2E9W", chl::LicenseKeyFormatting("5F3Z-2e-9-w", 4));
}
TEST(LicenseKeyFormatting, SmallerNoInGroups) {
  EXPECT_EQ("2-5G-3J", chl::LicenseKeyFormatting("2-5g-3-J", 2));
}
TEST(LicenseKeyFormatting, EmptyInput) { EXPECT_EQ("", chl::LicenseKeyFormatting("---", 3)); }

TEST(BackspaceCompare, Test1) { EXPECT_TRUE(chl::BackspaceCompare("ab#c", "ad#c")); }
TEST(BackspaceCompare, Test2) { EXPECT_TRUE(chl::BackspaceCompare("ab##", "c#d#")); }
TEST(BackspaceCompare, Test3) { EXPECT_TRUE(chl::BackspaceCompare("a##c", "#a#c")); }
TEST(BackspaceCompare, Test4) { EXPECT_FALSE(chl::BackspaceCompare("a#c", "b")); }

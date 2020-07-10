#include <string_view>
#include <string>

#pragma once

namespace chl {

/**
 * @brief Test if string has all unique characters
 *
 * @param str immutable string to test
 * @return true if str has all unique characters
 * @return false if not all characters are unique
 */
bool HasAllUnique(std::string_view str);

/**
 * @brief Test if string has all unique characters. Memory O(1)
 *
 * @param str immutable string to test
 * @return true if str has all unique characters
 * @return false if not all characters are unique
 */
bool HasAllUnique2(std::string_view str);

/**
 * @brief Check if right string is a permutation of left string
 *
 * @param left original string
 * @param right string to check if it is a permutation of left
 * @return true if right is a permutation of left
 * @return false if right is NOT a permutation of left
 */
bool IsPermutation(std::string_view left, std::string_view right);

/**
 * @brief Replace all spaces in string with %20
 *
 * Do it in place.
 * Example:
 * Input:  "Mr John Smith    ", 13
 * Output: "Mr%20John%20Smith"
 * @param original string, that has sufficient space to hold the additional characters
 * @param true_length length of the string without extra spaces in the end
 * @return modified string
 */
std::string Urlify(std::string original, size_t true_length);

}  // namespace chl

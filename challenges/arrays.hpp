#include <string_view>

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

}  // namespace chl

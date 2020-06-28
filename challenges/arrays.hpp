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

}  // namespace chl

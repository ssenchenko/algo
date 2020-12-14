#pragma once

#include <string>
#include <string_view>
#include <vector>

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

/**
 * @brief Clean up email addresses and count unique ones
 *
 * If you add periods ('.') between some characters in the local name part of an email address, mail
 * sent there will be forwarded to the same address without dots in the local name.  For example,
 * "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that
 * this rule does not apply for domain names.)
 *
 * If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
 * This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to
 * my@email.com.  (Again, this rule does not apply for domain names.)
 *
 * It is possible to use both of these rules at the same time.
 *
 * Given a list of emails, we send one email to each address in the list.  How many different
 * addresses actually receive mails?
 *
 * @param emails list of email addresses
 * @return number of unique emails
 */
size_t CountUniqueEmails(const std::vector<std::string>& emails);

/**
 * @brief Format licensing key into groups of K symbols.
 *
 * You are given a license key represented as a string S which consists only alphanumeric character
 * and dashes. The string is separated into N+1 groups by N dashes.
 *
 * Given a number K, we would want to reformat the strings such that each group contains exactly K
 * characters, except for the first group which could be shorter than K, but still must contain at
 * least one character. Furthermore, there must be a dash inserted between two groups and all
 * lowercase letters should be converted to uppercase.
 *
 * Given a non-empty string S and a number K, format the string according to the rules described
 * above.
 *
 * @param source unformatted lincense key
 * @param K number of symbols in a group in formatted license key
 * @return formatted license key
 */
std::string LicenseKeyFormatting(std::string_view source, int K);

/**
 * @brief Compare 2 strings which may contain backspace character.
 *
 * Given two strings S and T, return if they are equal when both are typed into empty text editors.
 * # means a backspace character.
 * Note that after backspacing an empty text, the text will continue empty.
 *
 * @param S first string
 * @param T second string
 * @return true if S == T
*/
bool BackspaceCompare(std::string_view S, std::string_view T);

}  // namespace chl

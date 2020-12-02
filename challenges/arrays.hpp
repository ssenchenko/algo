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
 * @return int
 */
int CountUniqueEmails(const std::vector<std::string>& emails);

/**
 * @brief Find the number of good (see below) starting indices to to reach the last element of the
 * array.
 *
 * You are given an integer array A. From some starting index, you can make a series of jumps. The
 * (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th,
 * ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not
 * the indices.
 *
 * You may jump forward from index i to index j (with i < j) in the following way:
 *
 * During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that
 * A[i] <= A[j] and A[j] is the smallest possible value. If there are multiple such indices j, you
 * can only jump to the smallest such index j. During even-numbered jumps (i.e., jumps 2, 4, 6,
 * ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value. If
 * there are multiple such indices j, you can only jump to the smallest such index j. It may be the
 * case that for some index i, there are no legal jumps. A starting index is good if, starting from
 * that index, you can reach the end of the array (index A.length - 1) by jumping some number of
 * times (possibly 0 or more than once).
 *
 * Implementation with recursion and DP (not a good fit for this challenge)
 *
 * @param A vector of integers
 * @return int
 */
int OddEvenJumps_v1(std::vector<int>& A);

/**
 * @brief Find the number of good (see below) starting indices to to reach the last element of the
 * array.
 *
 * See OddEvenJumps_v1 for detailed description
 *
 * Implementation with Monotonous Stack
 */
class OddEvenJumps_v2 {
  /*
        odd
      5, 1, 3, 4, 2
    5 00 00 00 01 00 | 0
    1    00 00 00 10 | 1
    3       00 10 01 | 1
    4          00 01 | 0
    2             00 | 0

  */
  std::vector<int> input_;

 public:
  // the only constructor needed for unit tests
  OddEvenJumps_v2(std::initializer_list<int> lst) : input_{lst} {};
  // TODO: delete implicit constructors

  int operator()();

  /**
   * @brief Get possible odd jump for each input
   *
   * @return std::vector<int> space of possible odd jumps
   */
  std::vector<int> odd_jumps();

  /**
   * @brief Get possible even jump for each input
   *
   * @return std::vector<int> Space of possible even jumps
   */
  std::vector<int> even_jumps();
};

}  // namespace chl

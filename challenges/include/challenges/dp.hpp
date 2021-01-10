#pragma once

#include <string>
#include <vector>

namespace chl {

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
 */
class OddEvenJumps
{
  std::vector<int> input_;
  size_t input_size_;

  static constexpr int kNoJump = -1;

public:
  // the only constructor needed for unit tests
  OddEvenJumps(std::initializer_list<int> lst) : input_{lst}, input_size_{lst.size()} {};
  OddEvenJumps(const OddEvenJumps &) = delete;

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

  std::string CreateKey(size_t index, short is_odd_jump)
  {
    return std::to_string(index) + "-" + std::to_string(is_odd_jump);
  }
};

/**
 * @brief Find the longest sequence of 2 numbers.
 *
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 *
 * You start at any tree of your choice, then repeatedly perform the following steps:
 *
 *  1) Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
 *  2) Move to the next tree to the right of the current tree.  If there is no tree to the right,
 * stop.
 *
 * Note that you do not have any choice after the initial choice of starting tree: you must
 * perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
 *
 * You have two baskets, and each basket can carry any quantity of fruit, but you want each basket
 * to only carry one type of fruit each.
 *
 * What is the maximum possible amount of fruit you can collect with this procedure?
 *
 * Example:
 * Input: [3,3,3,1,2,1,1,2,3,3,4]
 * Output: 5
 * Explanation: We can collect [1,2,1,1,2].
 *
 * @param tree array of tr
 * @return
 */
int MaxFruitNumber(const std::vector<int> &tree);

} // namespace chl

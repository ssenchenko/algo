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
class OddEvenJumps {
  std::vector<int> input_;
  size_t input_size_;

  static constexpr int kNoJump = -1;

 public:
  // the only constructor needed for unit tests
  OddEvenJumps(std::initializer_list<int> lst) : input_{lst}, input_size_{lst.size()} {};
  OddEvenJumps(const OddEvenJumps&) = delete;

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

  std::string CreateKey(size_t index, short is_odd_jump) {
    return std::to_string(index) + "-" + std::to_string(is_odd_jump);
  }
};

}  // namespace chl
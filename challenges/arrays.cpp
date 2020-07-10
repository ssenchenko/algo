#include "arrays.hpp"

#include <algorithm>
#include <iterator>
#include <map>
#include <set>

bool chl::HasAllUnique(std::string_view str) {
  // Time O(N)
  // Space O(N)
  auto symbols = std::set<char>();
  for (const auto& ch : str) {
    if (symbols.contains(ch)) return false;
    symbols.insert(ch);
  }
  return true;
}

bool chl::HasAllUnique2(std::string_view str) {
  // Time O(N^2)
  // Memory O(1)

  // only to be sure that iterator arithmetics won't create a bug for an empty string case
  if (std::empty(str)) return true;

  auto after_last = std::end(str);
  for (auto it = std::begin(str), last = std::prev(after_last); it < last; ++it) {
    // if symbol at <it> position can be found in [it+1, end_of_string] -> not all unique symbols
    if (std::find(std::next(it), after_last, *it) != after_last) return false;
  }
  return true;
}

bool chl::IsPermutation(std::string_view left, std::string_view right) {
  // time O(N)
  // space O(1) - map for all (printable?) ascii symbols

  // checking for equal length doesn't improve time complexity and is covered by general case below
  // check if strings are identical -- assumption (!!!) that it's not what we're looking for
  if (left == right) return false;

  auto char_counter = std::map<const char, int>();
  // count every character in left
  for (auto ch : left) {
    char_counter.try_emplace(ch, 0);
    ++char_counter[ch];
  };
  // decrease counters for each symbol from right
  for (auto ch : right) {
    // if symbol is not in occurrences, right is not a permutation of left bc it has extra symbols
    if (!char_counter.contains(ch)) return false;
    --char_counter[ch];
  }
  // if counters are not 0, strings are not permutations
  for (auto const& [_, value] : char_counter) {
    if (value != 0) return false;
  }

  return true;
}

std::string chl::Urlify(std::string original, size_t true_length) {
  // Time O(N)
  // Space O(1)

  // start at the end of the string and move forward
  // "Mr John Smith    "
  //                  p
  //              i
  // "Mr John SmitSmith"
  //              p
  //         i

  constexpr std::string_view space {"%20"};
  const auto end = std::rend(original);
  auto insert_at = std::rbegin(original); // p in diagram
  auto it = insert_at; // i in diagram
  // move iterator to the last character of the true string (past additional spaces)
  std::advance(it, std::size(original) - true_length);
//  for (; (it != end) && (*it == ' '); ++it); // this is wrong approach which fails when string is only spaces or ends in spaces
  // now comes the main loop to copy symbols
  for (; it != end; ++it, ++insert_at) {
    if (*it != ' ') {
      *insert_at = *it;
    } else {
      std::copy(std::rbegin(space), std::rend(space), insert_at); // copy with 2 reverse iterators will copy backwards
      std::advance(insert_at, std::size(space) - 1); // -1 bc insert_at will be increased in for loop
    }
  }

  return original;
}

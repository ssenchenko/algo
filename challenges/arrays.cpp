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

  // check if strings are identical
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

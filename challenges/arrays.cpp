#include "arrays.hpp"

#include <algorithm>
#include <iterator>
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

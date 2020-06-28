#include "./arrays.hpp"

#include <algorithm>
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

#include "arrays.hpp"

#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>

using namespace std::literals::string_literals;

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

  constexpr std::string_view space{"%20"};
  const auto end = std::rend(original);
  auto insert_at = std::rbegin(original);  // p in diagram
  auto it{insert_at};                      // i in diagram
  // move iterator to the last character of the true string (past additional spaces)
  std::advance(it, std::size(original) - true_length);
  // for (; (it != end) && (*it == ' '); ++it); // this is wrong approach which fails when string is
  // only spaces or ends in spaces now comes the main loop to copy symbols
  for (; it != end; ++it, ++insert_at) {
    if (*it != ' ') {
      *insert_at = *it;
    } else {
      std::copy(std::rbegin(space), std::rend(space),
                insert_at);  // copy with 2 reverse iterators will copy backwards
      std::advance(insert_at,
                   std::size(space) - 1);  // -1 bc insert_at will be increased in for loop
    }
  }

  return original;
}

size_t chl::CountUniqueEmails(const std::vector<std::string>& emails) {
  // Time O(M*N)
  // Space O(M*N)

  auto get_clean_emails = [](const std::string& email) {
    size_t left{0}, right{0};
    auto clean{""s};
    while (email.at(right) != '+' && email.at(right) != '@') {
      if (email.at(right) == '.') {
        clean += email.substr(left, right - left);
        left = right + 1;
      }
      ++right;
    }
    clean += email.substr(left, right - left);
    while (email.at(right) != '@') ++right;
    clean += email.substr(right, email.size() - right);
    return clean;
  };

  std::set<std::string> unique_emails;
  for (const auto& email : emails) {
    auto clean_email = get_clean_emails(email);
    unique_emails.insert(clean_email);
  }
  return unique_emails.size();
}

int chl::OddEvenJumps::operator()() {
  auto odd = odd_jumps();
  auto even = even_jumps();
  std::map<std::string, short> solutions;
  solutions.insert({CreateKey(input_size_ - 1, 1), 1});
  
  std::function<short (size_t, short)> Jumper = [&](auto index, auto is_odd) {
    auto key = CreateKey(index, is_odd);
    if (auto it = solutions.find(key); it != solutions.end()) return it->second;
    size_t next_jump = is_odd ? odd[index] : even[index];
    short res = 0;
    if (next_jump == input_size_ -1)  res = 1;
    else if ( next_jump != kNoJump) res = Jumper(next_jump, !is_odd);
    solutions[key] = res;
    return res;
  };

  int legal_jumps = 0;
  for (auto i = input_size_; i--;) {
    legal_jumps += Jumper(i, 1);
  }
  return legal_jumps;
}

std::vector<int> chl::OddEvenJumps::odd_jumps() {
  std::vector<int> res(input_size_, kNoJump);
  std::map<int, int> helper;
  for (auto i{input_size_ - 1}; i--;) {
    helper.insert_or_assign(input_[i + 1], i + 1);
    auto jump_it = helper.lower_bound(input_[i]);
    if (jump_it != helper.end()) res[i] = jump_it->second;
  }
  return res;
}

std::vector<int> chl::OddEvenJumps::even_jumps() {
  std::vector<int> res(input_size_, kNoJump);
  std::map<int, int> helper;
  for (auto i{input_size_ - 1}; i--;) {
    helper.insert_or_assign(-input_[i + 1], i + 1);
    auto jump_it = helper.lower_bound(-input_[i]);
    if (jump_it != helper.end()) res[i] = jump_it->second;
  }
  return res;
}

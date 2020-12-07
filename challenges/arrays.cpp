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

std::string chl::LicenseKeyFormatting(std::string_view source, int K) {
  constexpr char kSeparator = '-';

  auto IsLower = [](char c) { return std::islower(static_cast<unsigned char>(c)) != 0; };

  auto ToUpper = [](char c) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  };

  size_t sep_counter{0};
  for (auto sep_pos = source.find(kSeparator); sep_pos != source.npos;
       ++sep_counter, sep_pos = source.find(kSeparator, sep_pos + 1))
    ;
  auto updated_size = source.size() - sep_counter;
  std::string target;
  if (updated_size) {
    auto groups_number = updated_size / K + (updated_size % K ? 1 : 0);
    auto new_size = groups_number - 1 + updated_size;
    target.reserve(new_size);
    target.assign(new_size, kSeparator);
  }
  auto source_it = source.rbegin();
  auto target_it = target.rbegin();
  auto group_counter = K;
  for (auto source_end = source.rend(); source_it != source_end;) {
    if (*source_it == kSeparator) {
      ++source_it;
      continue;
    }
    if (group_counter == 0) {
      group_counter = K;
      ++target_it;
    } else {
      --group_counter;
      *target_it = IsLower(*source_it) ? ToUpper(*source_it) : *source_it;
      ++source_it;
      ++target_it;
    }
  }
  return target;
}

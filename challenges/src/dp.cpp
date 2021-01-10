#include "challenges/dp.hpp"

#include <algorithm>
#include <functional>
#include <map>

int chl::OddEvenJumps::operator()()
{
  auto odd = odd_jumps();
  auto even = even_jumps();
  std::map<std::string, short> solutions;
  solutions.insert({CreateKey(input_size_ - 1, 1), 1});

  std::function<short(size_t, short)> Jumper = [&](auto index, auto is_odd) {
    auto key = CreateKey(index, is_odd);
    if (auto it = solutions.find(key); it != solutions.end()) return it->second;
    size_t next_jump = is_odd ? odd[index] : even[index];
    short res = 0;
    if (next_jump == input_size_ - 1) res = 1;
    else if (static_cast<int>(next_jump) != kNoJump)
      res = Jumper(next_jump, !is_odd);
    solutions[key] = res;
    return res;
  };

  int legal_jumps = 0;
  for (auto i = input_size_; i--;) {
    legal_jumps += Jumper(i, 1);
  }
  return legal_jumps;
}

std::vector<int> chl::OddEvenJumps::odd_jumps()
{
  std::vector<int> res(input_size_, kNoJump);
  std::map<int, int> helper;
  for (auto i{input_size_ - 1}; i--;) {
    helper.insert_or_assign(input_[i + 1], i + 1);
    auto jump_it = helper.lower_bound(input_[i]);
    if (jump_it != helper.end()) res[i] = jump_it->second;
  }
  return res;
}

std::vector<int> chl::OddEvenJumps::even_jumps()
{
  std::vector<int> res(input_size_, kNoJump);
  std::map<int, int> helper;
  for (auto i{input_size_ - 1}; i--;) {
    helper.insert_or_assign(-input_[i + 1], i + 1);
    auto jump_it = helper.lower_bound(-input_[i]);
    if (jump_it != helper.end()) res[i] = jump_it->second;
  }
  return res;
}

int chl::MaxFruitNumber(const std::vector<int> &tree)
{
  // Time O(N)
  // Memory O(1)

  //  0 1 2 3 4 5
  // [3,3,3,1,1,2,1,1,2,3,3,4]
  //               p
  //              s
  //  counter = 2

  auto s{tree.cbegin()}, p{std::next(s)}, end{tree.cend()};
  auto t1{*s}, t2{*s}; // t1 - type in 1st bucket, t2 - type in 2nd bucket
  auto count{0}, counter{1};

  for (; p != end; ++p, ++counter) {
    if (*p != *s) {
      if (t1 == t2) {
        t2 = *p; // 1st time introducing 2nd type
      }
      else if (*p != t1 && *p != t2) { // third type found
        count = std::max(count, counter);
        counter = std::distance(s, p);
        t1 = *s;
        t2 = *p;
      }
      s = p;
    }
  }
  count = std::max(count, counter);
  return count;
}

#include "dp.hpp"

#include <map>
#include <algorithm>
#include <functional>

int chl::OddEvenJumps::operator()() {
  auto odd = odd_jumps();
  auto even = even_jumps();
  std::map<std::string, short> solutions;
  solutions.insert({CreateKey(input_size_ - 1, 1), 1});

  std::function<short(size_t, short)> Jumper = [&](auto index, auto is_odd) {
    auto key = CreateKey(index, is_odd);
    if (auto it = solutions.find(key); it != solutions.end()) return it->second;
    size_t next_jump = is_odd ? odd[index] : even[index];
    short res = 0;
    if (next_jump == input_size_ - 1)
      res = 1;
    else if (next_jump != kNoJump)
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

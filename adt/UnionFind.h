#pragma once

#include <map>
#include <queue>
#include <set>
#include <utility>

namespace algo {

template <class T>
class UnionFind {
 private:
  std::map<T, std::set<T>> items_;

 public:
  UnionFind() : items_{std::map<T, std::set<T>>()} {};
  void Connect(std::pair<T, T> connected);
  void Disconnect(std::pair<T, T> connected);
  bool AreConnected(std::pair<T, T> points);
};

}  // namespace algo

template <class T>
void algo::UnionFind<T>::Connect(std::pair<T, T> connected) {
  const auto [first, second] = connected;
  if (!items_.contains(first)) {
    items_.insert({first, std::set<T>()});
  }
  items_[first].insert(second);
  if (!items_.contains(second)) {
    items_.insert({second, std::set<T>()});
  }
  items_[second].insert(first);
}

template <class T>
void algo::UnionFind<T>::Disconnect(std::pair<T, T> connected) {
  const auto [first, second] = connected;
  items_[first].erase(second);
  items_[second].erase(first);
}

template <class T>
bool algo::UnionFind<T>::AreConnected(std::pair<T, T> points) {
  const auto [start, etalon] = points;
  auto visited{std::set<T>()};  // already checked elements, to avoid loops
  auto bfs_queue{std::queue<T>()};

  bfs_queue.push(start);
  for (; bfs_queue.size(); bfs_queue.pop()) {
    auto current = bfs_queue.front();
    if (items_.contains(current)) {
      if (items_[current].contains(etalon)) {
        return true;
      }
      visited.insert(current);
      for (const auto &item : items_[current]) {
        if (!visited.contains(item)) {
          bfs_queue.push(item);
        }
      }
    } else {
      return false;
    }
  }

  return false;
}

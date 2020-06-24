#pragma once

#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace algo
{

template <class T>
class UnionFind
{
private:
    std::unordered_map<T, std::unordered_set<T>> items_;

public:
    UnionFind() {};
    void Connect(std::pair<T, T> connected);
    void Disconnect(std::pair<T, T> connected);
    bool AreConnected(std::pair<T, T> points);
};

}

template <class T>
void algo::UnionFind<T>::Connect(std::pair<T, T> connected)
{
    if (items_.find(connected.first) == items_.end()) 
    {
        items_.insert({ connected.first, std::unordered_set<T>() });
    }
    items_[connected.first].insert(connected.second);
    if (items_.find(connected.second) == items_.end())
    {
        items_.insert({ connected.second, std::unordered_set<T>() });
    }
    items_[connected.second].insert(connected.first);
}

template <class T>
void algo::UnionFind<T>::Disconnect(std::pair<T, T> connected)
{
    items_[connected.first].erase(connected.second);
    items_[connected.second].erase(connected.first);
}

template <class T>
bool algo::UnionFind<T>::AreConnected(std::pair<T, T> points)
{
    if (items_.count(points.first))
    {
        if (items_[points.first].find(points.second) != items_[points.first].end())
        {
            return true;
        }
        for (const auto& item : items_[points.first])
        {
            if (AreConnected({ item, points.second })) return true; // O(c^N) :(
        }
    }
    return false;
}
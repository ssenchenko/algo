#pragma once

#include <vector>


namespace algo
{

class UnionFind
{
private:
    std::vector<int> items_;

public:
    UnionFind(int number_of_items) : items_(number_of_items) {};
};

}
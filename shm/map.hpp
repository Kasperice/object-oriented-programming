#pragma once
#include <vector>

#include "coordinates.hpp"
#include "island.hpp"

constexpr int NUM_OF_ISLANDS = 10;
constexpr int MAP_RND_DISTRIBUTION_MIN = 1000;
constexpr int MAP_RND_DISTRIBUTION_MAX = 1010;

class Map {
public:
    Map();

    Island* getIsland(const Coordinates& coordinate);

private:
    std::vector<Island> allIslands;
    Island* currentPosition_;
};

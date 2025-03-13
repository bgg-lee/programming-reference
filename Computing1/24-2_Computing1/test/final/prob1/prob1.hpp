#ifndef PROB1_HPP
#define PROB1_HPP

#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

std::vector<std::vector<int>> reconstructShortestPaths(int n, const std::vector<std::vector<int>>& weights);

void printMatrix(std::vector<std::vector<int>>& weight);

#endif // PROB1_HPP

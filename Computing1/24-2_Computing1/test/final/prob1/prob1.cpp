#include "prob1.hpp"

// TODO
std::vector<std::vector<int>> reconstructShortestPaths(int n, const std::vector<std::vector<int>>& weights) {
    
    std::vector<std::vector<int>> dist = weights;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}



/*============= Helper Function for Debugging =============*/
void printMatrix(std::vector<std::vector<int>>& weight) {
    for (const auto& row : weight) {
        for (int val : row) {
            if (val == INF)
                std::cout << "INF ";
            else
                std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

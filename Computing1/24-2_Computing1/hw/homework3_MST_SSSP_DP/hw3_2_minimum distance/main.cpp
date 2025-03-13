// Minimum Distance Tree MST 문제
// 프림스 prims Prims 크루스칼 Kruskal kruskal
#include <iostream> 
#include <vector>
using namespace std; 

#include "functions.hpp"
  
// Driver program to test above functions 
int main() 
{ 
    vector<vector<int>> testCases[] = {
        {{3, 12}, {-2, 5}, {-4, 1}},  // Example Test Case
        {{0, 0}, {1, 1}, {1, 0}, {0, 1}},  // Simple square
        {{1, 2}, {3, 4}, {6, 1}, {5, 3}},  // Random points
        {{-10, -10}, {-5, -5}, {0, 0}, {5, 5}, {10, 10}},  // Symmetric points
        {{100, 100}, {200, 200}, {300, 300}, {400, 400}, {500, 500}},  // Large values
    };

    for (auto& points : testCases) {
        cout << "Minimum Distance (MST): " << minDistance(points) << endl;
    }

    return 0;


// {{3, 12}, {-2, 5}, {-4, 1}}	=18
// {{0, 0}, {1, 1}, {1, 0}, {0, 1}}=	3
// {{1, 2}, {3, 4}, {6, 1}, {5, 3}}	= 8
// {{-10, -10}, {-5, -5}, {0, 0}, {5, 5}, {10, 10}}	= 40
// {{100, 100}, {200, 200}, {300, 300}, {400, 400}, {500, 500}}	= 800
} 
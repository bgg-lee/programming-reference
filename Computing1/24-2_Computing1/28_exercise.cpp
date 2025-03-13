#include <vector>
#include <iostream>
#include <climits>
#include <utility> 
// 아래 header는 내가 추가
#include <algorithm>
using namespace std;
/*//////////////////////// Description ////////////////////////////
There are n cities in a logistics network, numbered from 0 to n−1. 

The edges array represents the logistics routes between cities and the corresponding transportation costs. 

Specifically, edges[i] = [from_i, to_i, weight_i] indicates a bidirectional logistics route between city from_i and city to_i, 
with a transportation cost of weight_i.

When considering each city as a potential logistics hub, 
calculate the number of cities reachable from the hub with a maximum transportation cost of distanceThreshold. 

Identify the city (hub) that can reach the most number of cities. 
If there are multiple such cities, return the city with the largest numerical index.

Constraints:
    2 <= n <= 100
    1 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 3
    0 <= fromi < toi < n
    1 <= weighti, distanceThreshold <= 10^4
    All pairs (fromi, toi) are distinct.
////////////////////////////////////////////////////////////////*/

class Solution {
public:
    /* ///////////////////////////////////// TODO 1 ///////////////////////////////////////
    This function uses the Floyd-Warshall algorithm to compute the shortest paths 
    between all pairs of cities and determine the city that meets the problem's conditions.
    ////////////////////////////////////////////////////////////////////////////////////*/
    int floydWarshall (int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        //Pseudo Code 보고 따라하기 APSP
        //STEP 1
        vector<vector<int>> floyd(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    floyd[i][j] = 0; // 자기자신 Distance 는 0
                }else{
                    floyd[i][j] = 100000; // Default Distance 는 무한대, 적당히 큰 값
                }
            }
        }
        //STEP 2 : Fill Matrix with edge distance
        for(const auto vec : edges){
            int u = vec[0], v = vec[1], w = vec[2];
            floyd[u][v] = w;
            floyd[v][u] = w; // Undirected Graph이다.
        }
        
        //STEP 3 : Update distance using Floyd-Warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]); // 이건가 벼
                }
            }
        }

        //STEP 4 : Find the City with the most reachable cities
        int max_cnt = 0;
        int ans = -1;

        for(int i=n-1;i>=0;i--){
            int cnt = 0;
            for(const int dist : floyd[i]){
                if(dist <= distanceThreshold) cnt++;
            }
            if(cnt > max_cnt){
                max_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }


    /* ///////////////////////////////////// TODO 2 ///////////////////////////////////////
    This function uses the Bellman Ford algorithm to compute the shortest paths 
    between all pairs of cities and determine the city that meets the problem's conditions.
    ////////////////////////////////////////////////////////////////////////////////////*/
    int bellmanFord(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        // Pseudo Code 보고 내가 해보기...
        int max_cnt = 0;
        int ans = -1;
        
        for(int src=0;src<n;src++){
            vector<int> dist(n,1234567890); // 각 Source마다 dist array를 reset한다.
            dist[src] = 0;
            //STEP 1 : Relax all edges ( n-1 times)
            for(int i=0;i<n-1;i++){ // n-1 times 왜 n-1 time이지?
                for(const auto vec : edges){
                    int u = vec[0] , v = vec[1], w = vec[2];
                    dist[u] = min(dist[u],dist[v]+w); 
                    dist[v] = min(dist[v],dist[u]+w); // Undirected graph!! 
                }
            }
            //STEP 2 : Count reachable cities
            int cnt = 0;
            for(const int d : dist){
                if(d <= distanceThreshold) cnt++;
            }
            //STEP 3 : Update the city
            if((cnt > max_cnt)||((cnt==max_cnt)&& src > ans)){
                max_cnt = cnt;
                ans = src;
            }
        }
        return ans;

    }
};

int main() {
    Solution solution;

    int n1 = 4;
    std::vector<std::vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold1 = 4;
    std::cout << "Test Case 1 (Floyd Warshall) Output: " << solution.floydWarshall(n1, edges1, distanceThreshold1) << std::endl; // Expected output: 2
    std::cout << "Test Case 1 (Bellman Ford) Output: " << solution.bellmanFord(n1, edges1, distanceThreshold1) << std::endl; // Expected output: 2


    int n2 = 5;
    std::vector<std::vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int distanceThreshold2 = 2;
    std::cout << "Test Case 2 (Floyd Warshall) Output: " << solution.floydWarshall(n2, edges2, distanceThreshold2) << std::endl; // Expected output: 4
    std::cout << "Test Case 2 (Bellman Ford) Output: " << solution.bellmanFord(n2, edges2, distanceThreshold2) << std::endl; // Expected output: 4

    int n3 = 3;
    std::vector<std::vector<int>> edges3 = {{0, 1, 1}, {1, 2, 1}, {0, 2, 2}};
    int distanceThreshold3 = 2;
    std::cout << "Test Case 3 (Floyd Warshall) Output: " << solution.floydWarshall(n3, edges3, distanceThreshold3) << std::endl; // Expected output: 2
    std::cout << "Test Case 3 (Bellman Ford) Output: " << solution.bellmanFord(n3, edges3, distanceThreshold3) << std::endl; // Expected output: 2

    int n4 = 4;
    std::vector<std::vector<int>> edges4 = {{0, 1, 3}, {2, 3, 1}};
    int distanceThreshold4 = 2;
    std::cout << "Test Case 4 (Floyd Warshall) Output: " << solution.floydWarshall(n4, edges4, distanceThreshold4) << std::endl; // Expected output: 3
    std::cout << "Test Case 4 (Bellman Ford) Output: " << solution.bellmanFord(n4, edges4, distanceThreshold4) << std::endl; // Expected output: 3

    int n5 = 1;
    std::vector<std::vector<int>> edges5 = {};
    int distanceThreshold5 = 0;
    std::cout << "Test Case 5 (Floyd Warshall) Output: " << solution.floydWarshall(n5, edges5, distanceThreshold5) << std::endl; // Expected output: 0
    std::cout << "Test Case 5 (Bellman Ford) Output: " << solution.bellmanFord(n5, edges5, distanceThreshold5) << std::endl; // Expected output: 0

    int n6 = 100;
    std::vector<std::vector<int>> edges6 = {
        {0, 1, 10000}, {0, 2, 5000}, {1, 2, 4000}, {2, 3, 7000}, {3, 4, 2000},
        {4, 5, 8000}, {5, 6, 6000}, {6, 7, 9000}, {7, 8, 3000}, {8, 9, 10000}
    };
    int distanceThreshold6 = 20000;
    std::cout << "Test Case 6 (Floyd Warshall) Output: " << solution.floydWarshall(n6, edges6, distanceThreshold6) << std::endl; // Expected output: 5
    std::cout << "Test Case 6 (Bellman Ford) Output: " << solution.bellmanFord(n6, edges6, distanceThreshold6) << std::endl; // Expected output: 5

    int n7 = 50;
    std::vector<std::vector<int>> edges7 = {
        {0, 1, 300}, {1, 2, 200}, {2, 3, 400}, {3, 4, 500}, {4, 5, 300},
        {5, 6, 600}, {6, 7, 700}, {7, 8, 100}, {8, 9, 200}, {9, 10, 500},
        {10, 11, 400}, {11, 12, 300}, {12, 13, 600}, {13, 14, 700}, {14, 15, 200}
    };
    int distanceThreshold7 = 1500;
    std::cout << "Test Case 7 (Floyd Warshall) Output: " << solution.floydWarshall(n7, edges7, distanceThreshold7) << std::endl; // Expected output: 12
    std::cout << "Test Case 7 (Bellman Ford) Output: " << solution.bellmanFord(n7, edges7, distanceThreshold7) << std::endl; // Expected output: 12
    
    return 0;
}

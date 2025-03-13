/*
///////////// Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 무한대 값 설정
const int INF = numeric_limits<int>::max();

// 그래프의 노드 표현 구조체
struct Edge {
    int to;
    int weight;
};

// 다익스트라 알고리즘 실행 함수
vector<int> dijkstra(int n, vector<vector<Edge>>& adj, int start) {
    vector<int> dist(n, INF); // 최단 거리 저장 배열
    vector<int> parent(n, -1); // 경로 추적 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // 시작 노드 초기화
    dist[start] = 0;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int d = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();

        // 현재 거리가 기존 저장된 거리보다 크면 스킵
        if (d > dist[u]) continue;

        // 인접 노드 탐색
        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                minHeap.push({dist[v], v});
            }
        }
    }
    return dist; // 최단 거리 반환
}

// main 함수: 테스트 실행
int main() {
    int n = 6; // 노드 개수
    vector<vector<Edge>> graph(n);

    // 그래프 추가 (양방향 그래프라면 양쪽에 추가)
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({5, 6});
    graph[3].push_back({5, 7});

    int start = 0; // 시작 노드 (예: 0번 노드에서 시작)
    vector<int> shortestDistances = dijkstra(n, graph, start);

    // 결과 출력
    cout << "start from -> " << start  << endl;
    for (int i = 0; i < n; i++) {
        cout << "NODE " << i << ": ";
        if (shortestDistances[i] == INF)
            cout << "impossible" << endl;
        else
            cout << shortestDistances[i] << endl;
    }

    return 0;
}
*/
/*
////////////// Bellman Ford
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Infinite distance (for initialization)
const int INF = numeric_limits<int>::max();

// Graph edge structure
struct Edge {
    int from, to, weight;
};

// Bellman-Ford Algorithm
bool bellmanFord(int n, vector<Edge>& edges, int start, vector<int>& dist) {
    dist.assign(n, INF); // Initialize distances
    dist[start] = 0;

    // Relax all edges (V-1) times
    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (const Edge& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                updated = true;
            }
        }
        if (!updated) break; // Optimization: Stop if no updates
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
            return false; // Negative cycle detected
        }
    }

    return true;
}

// Main function for testing
int main() {
    int n = 5; // Number of nodes
    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5},
        {1, 4, -4}, {2, 3, -3}, {2, 4, 9}, {3, 1, -2},
        {4, 3, 7}, {3, 0, 2}
    };

    int start = 0;
    vector<int> distances;

    bool success = bellmanFord(n, edges, start, distances);

    if (!success) {
        cout << "Negative cycle detected. No shortest path possible." << endl;
    } else {
        cout << "Shortest distances from source " << start << ":" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": ";
            if (distances[i] == INF)
                cout << "Unreachable" << endl;
            else
                cout << distances[i] << endl;
        }
    }

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Infinite distance (for initialization)
const int INF = numeric_limits<int>::max();

// Dijkstra's Algorithm without Edge struct
vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(n, INF); // Distance array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Initialize start node
    dist[start] = 0;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int d = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();

        // Ignore if we already have a shorter path
        if (d > dist[u]) continue;

        // Relax all adjacent nodes
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first, weight = neighbor.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                minHeap.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Main function for testing
int main() {
    int n = 6; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);

    // Add edges (u, v, weight)
    graph[0] = {{1, 10}, {2, 5}};
    graph[1] = {{2, 8}, {3, 5}, {4, -4}};
    graph[2] = {{1, 3}, {3, 9}, {4, 2}};
    graph[3] = {{4, 4}, {5, 7}};
    graph[4] = {{5, 6}};

    int start = 0;
    vector<int> shortestDistances = dijkstra(n, graph, start);

    // Print shortest distances
    cout << "Shortest distances from source " << start << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (shortestDistances[i] == INF)
            cout << "Unreachable" << endl;
        else
            cout << shortestDistances[i] << endl;
    }

    return 0;
}
*/
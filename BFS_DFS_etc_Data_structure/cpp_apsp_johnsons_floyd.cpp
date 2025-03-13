///////// Johnson's Algorithm
/*
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Bellman-Ford Algorithm to detect negative cycles and get potential values
bool bellmanFord(int n, vector<vector<pair<int, int>>>& adj, vector<int>& h) {
    h.assign(n, INF);
    h[n - 1] = 0;

    for (int i = 0; i < n; i++) {
        bool updated = false;
        for (int u = 0; u < n; u++) {
            for (const auto& edge : adj[u]) {
                int v = edge.first, weight = edge.second;
                if (h[u] != INF && h[v] > h[u] + weight) {
                    h[v] = h[u] + weight;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    for (int u = 0; u < n; u++) {
        for (const auto& edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            if (h[u] != INF && h[v] > h[u] + weight) {
                return false; // Negative cycle detected
            }
        }
    }
    return true;
}

// Dijkstra's Algorithm to compute shortest paths
vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    dist[start] = 0;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int d = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                minHeap.push({dist[v], v});
            }
        }
    }
    return dist;
}

///////// Johnson's Algorithm for APSP
vector<vector<int>> johnson(int n, vector<vector<pair<int, int>>>& adj) {
    vector<vector<int>> allPairsShortestPaths(n, vector<int>(n, INF));
    vector<int> h;

    // Add a new node (n) and connect it to all other nodes with 0 weight edges
    vector<vector<pair<int, int>>> newAdj = adj;
    newAdj.push_back(vector<pair<int, int>>());
    for (int i = 0; i < n; i++) newAdj[n].push_back({i, 0});

    // Step 1: Run Bellman-Ford from the new node
    if (!bellmanFord(n + 1, newAdj, h)) {
        cout << "Negative cycle detected!" << endl;
        return {};
    }

    // Step 2: Reweight the graph to eliminate negative weights
    for (int u = 0; u < n; u++) {
        for (auto& edge : adj[u]) {
            edge.second += h[u] - h[edge.first];
        }
    }

    // Step 3: Run Dijkstra for each node
    for (int u = 0; u < n; u++) {
        vector<int> dists = dijkstra(n, adj, u);
        for (int v = 0; v < n; v++) {
            if (dists[v] != INF) allPairsShortestPaths[u][v] = dists[v] + h[v] - h[u];
        }
    }

    return allPairsShortestPaths;
}

// Test case
int main() {
    int n = 4;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = {{1, 1}, {2, -3}};
    graph[1] = {{2, 2}, {3, 4}};
    graph[2] = {{3, 1}};
    graph[3] = {};

    vector<vector<int>> result = johnson(n, graph);
    if (!result.empty()) {
        cout << "All-pairs shortest paths using Johnson's Algorithm:" << endl;
        for (const auto& row : result) {
            for (int val : row) {
                if (val == INF) cout << "INF ";
                else cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
*/

/*
////////// Floyd Warshall Algorithm
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Floyd-Warshall Algorithm for APSP
vector<vector<int>> floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph; // Copy input graph

    // Main DP loop: Consider each node as an intermediate point
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Detect negative cycles
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            return {};
        }
    }
    return dist;
}

// Test case
int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    vector<vector<int>> result = floydWarshall(n, graph);
    if (!result.empty()) {
        cout << "All-pairs shortest paths using Floyd-Warshall Algorithm:" << endl;
        for (const auto& row : result) {
            for (int val : row) {
                if (val == INF) cout << "INF ";
                else cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
*/
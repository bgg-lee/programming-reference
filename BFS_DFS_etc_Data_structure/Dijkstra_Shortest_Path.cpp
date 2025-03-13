#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>>& edges, int start) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto const x : edges){
        adj[x[0]].push_back({x[1],x[2]}); // { node , weight }
    }

    vector<int> dist(n,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; // MIN-HEAP
    pq.push({0,start});

    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();
        int curr_dist = curr.first;
        int node = curr.second;

        if(curr_dist > dist[node]) continue;

        for(auto const x : adj[node]){
            int new_dist = curr_dist + x.second;
            if(new_dist < dist[x.first]){
                dist[x.first] = new_dist;
                pq.push({new_dist,x.first});
            }
        }
    }
    // for(int i=0;i<dist.size();i++){
    //     if(dist[i]==INT_MAX) dist[i] = -1;
    // }
    for(int &d : dist){
        if(d==INT_MAX) d = -1;
    }
    return dist;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {3, 4, 1},
        {5, 5, 1}
    };
    int start = 0;

    vector<int> result = dijkstra(n, edges, start);
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
    // Expected: [0, 2, 3, 6, 7,-1]
}

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm> // find 용
using namespace std;
/*
Graph이다보니, island / cycle 유의
island 있다면 모든 node에 대해서 bfs-helper 돌리는 형식으로 바꿔야 하고
cycle은 visisted node로 처리 가능
*/
// BFS from given source s
void bfs(vector< vector<int> > & adj, int s) 
{
    // Create a queue for BFS
    queue<int> q;
    q.push(s);
    vector<int> visited = {};
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(find(visited.begin(),visited.end(),curr) != visited.end()) continue;
        visited.push_back(curr);

        cout << curr << " ";
        // 작은 친구를 tree의 left 처럼 먼저 방문하게 하기 위함.
        sort(adj[curr].begin(),adj[curr].end());
        for(auto node : adj[curr]){
            q.push(node);
        }

    }
}
// DFS from given source s
void dfs(vector< vector<int> > & adj, int s) 
{
    // Create a stack for DFS
    stack<int> sta;
    int n = adj.size();
    vector<bool> visited(n,false);
    sta.push(s);
    while(!sta.empty()){
        int curr = sta.top();
        sta.pop();
        if(visited[curr]) continue;
        visited[curr] = true;
        cout << curr << " ";

        sort(adj[curr].rbegin(),adj[curr].rend()); // 방문 순서 control
        for(int node : adj[curr]){
            sta.push(node);
        }
    }
    
}
// Function to add an edge to the graph
void addEdge(vector< vector<int> >& adj, int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}

int main() 
{
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector< vector<int> > adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);
    cout << endl << "DFS starting from 0 : \n";
    dfs(adj,0);
    return 0;
}


// Graph BFT,DFT Traversal을 위한 GPT sol
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>
// using namespace std;

// /* 
//  * 그래프를 인접 리스트로 표현.
//  * V개의 정점(0 ~ V-1) 에 대해 adj[v]는 정점 v와 인접한 정점 리스트를 저장.
//  */

// // 단일 연결 성분(컴포넌트)을 BFS로 순회
// void bfsOneComponent(const vector<vector<int>>& adj, int start, vector<bool>& visited) {
//     queue<int> q;
//     visited[start] = true;
//     q.push(start);

//     cout << "  Component BFS: ";

//     while(!q.empty()) {
//         int cur = q.front();
//         q.pop();
//         cout << cur << " ";

//         // cur과 인접한 정점들 확인
//         for(int nxt : adj[cur]) {
//             if(!visited[nxt]) {
//                 visited[nxt] = true;
//                 q.push(nxt);
//             }
//         }
//     }
//     cout << endl;
// }

// // 전체 그래프에서 BFS (모든 섬 방문)
// void bfsAll(const vector<vector<int>>& adj) {
//     int V = adj.size();
//     vector<bool> visited(V, false);

//     for(int v = 0; v < V; v++) {
//         if(!visited[v]) {
//             // v가 아직 방문되지 않았다면, v를 시작점으로 BFS 수행
//             bfsOneComponent(adj, v, visited);
//         }
//     }
// }

// // 단일 연결 성분(컴포넌트)을 DFS(재귀)로 순회
// void dfsOneComponent(const vector<vector<int>>& adj, int cur, vector<bool>& visited) {
//     visited[cur] = true;
//     cout << cur << " ";

//     for(int nxt : adj[cur]) {
//         if(!visited[nxt]) {
//             dfsOneComponent(adj, nxt, visited);
//         }
//     }
// }

// // 전체 그래프에서 DFS (모든 섬 방문)
// void dfsAll(const vector<vector<int>>& adj) {
//     int V = adj.size();
//     vector<bool> visited(V, false);

//     for(int v = 0; v < V; v++) {
//         if(!visited[v]) {
//             cout << "  Component DFS: ";
//             dfsOneComponent(adj, v, visited);
//             cout << endl;
//         }
//     }
// }

// // 간단한 Undirected Edge 추가 함수
// void addEdge(vector<vector<int>>& adj, int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// int main() {
//     // 6개의 정점을 가진 그래프 예시
//     // 일부러 '섬(Disconnected Components)'를 만들기 위해
//     // 예: {0,1,2}가 하나의 연결성분, {3,4}가 다른 연결성분, {5}는 혼자
//     int V = 6;
//     vector<vector<int>> adj(V);

//     // 첫 번째 컴포넌트: 0 - 1 - 2
//     addEdge(adj, 0, 1);
//     addEdge(adj, 1, 2);
//     // 두 번째 컴포넌트: 3 - 4
//     addEdge(adj, 3, 4);
//     // 세 번째 컴포넌트: 5 단독 (Edge 없음)

//     // BFS로 전체 그래프 탐색
//     cout << "[BFS over entire graph]" << endl;
//     bfsAll(adj);

//     // DFS로 전체 그래프 탐색
//     cout << "[DFS over entire graph]" << endl;
//     dfsAll(adj);

//     return 0;
// }

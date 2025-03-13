// heap 선언할때, 두 번째 요소 기준으로 heap 만드는 방법
// struct CompareSecond {
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
//         return a.second > b.second; // 정점 번호 기준 최소 힙
//     }
// };

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int prim(int n, vector<vector<pair<int, int>>> &graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<bool> inMST(n, false);
    pq.push({0, 0}); // cost & node
    int mst_cost = 0;

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        int w = temp.first;
        int u = temp.second;
        if(inMST[u]) continue; // 기 방문 노드인지 확인
        inMST[u] = true;
        mst_cost += w;

        for(const auto p : graph[u]){
            if(!inMST[p.first]) pq.push({p.second,p.first});
        }
    }
    return mst_cost;
}
int main(){
    int n = 4;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = {{1, 1}, {2, 4}};
    graph[1] = {{0, 1}, {2, 3}, {3, 5}};
    graph[2] = {{0, 4}, {1, 3}, {3, 2}};
    graph[3] = {{1, 5}, {2, 2}};
    cout << "MST COST(Prims) : " << prim(n,graph) << endl; // 6
}
*/

// Kruskal  ------------->  GG 크루스칼 너무 어렵다..
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent, rank_set;  // 🔹 'rank' 대신 'rank_set' 사용하여 충돌 방지

// 🔹 MAKE-SET(v): 모든 정점을 독립적인 집합으로 초기화
void make_set(int n) {
    parent.resize(n);
    rank_set.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 🔹 FIND-SET(u): 정점 u의 대표(루트)를 찾음 (경로 압축 적용)
int find_set(int u) {
    if (parent[u] != u)
        parent[u] = find_set(parent[u]); // 경로 압축
    return parent[u];
}

// 🔹 UNION(u, v): 두 집합을 합침 (랭크 기반)
void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (rank_set[u] > rank_set[v]) swap(u, v); // 작은 랭크를 큰 랭크에 붙임
        parent[u] = v;
        if (rank_set[u] == rank_set[v]) rank_set[v]++;
    }
}

// 🔹 크루스칼 알고리즘 (MST 구하기)
int kruskal(int n, vector<tuple<int, int, int>> &edges) {
    make_set(n);
    sort(edges.begin(), edges.end());  // 가중치 기준 정렬

    int mst_cost = 0;
    vector<pair<int, int>> mst_edges;

    for (auto [w, u, v] : edges) {
        if (find_set(u) != find_set(v)) { // 사이클이 생기지 않는 경우
            union_sets(u, v);
            mst_cost += w;
            mst_edges.push_back({u, v});
        }
    }

    // 🔹 MST 결과 출력
    cout << "MST Edges:\n";
    for (auto [u, v] : mst_edges) {
        cout << u << " - " << v << endl;
    }

    return mst_cost;
}

// 🔹 메인 함수 (그래프 생성 및 크루스칼 실행)
int main() {
    int n = 4; // 정점 개수
    vector<tuple<int, int, int>> edges = { // 가중치, 노드 a, 노드 b
        {1, 0, 1}, {3, 1, 2}, {4, 0, 2}, {2, 2, 3}, {5, 1, 3}
    };

    cout << "Minimum Spanning Tree Cost (Kruskal): " << kruskal(n, edges) << endl;
    return 0;
}





#include <iostream> 
#include <queue>
#include <vector>
#include <climits>
#include "functions.hpp"
#include <tuple> // 내가추가
#include <algorithm> // 내가추가
using namespace std; 

// 거리 함수
int dist(vector<int>& p1, vector<int>& p2){
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
}

// Find_ 함수 (경로 압축 적용) Kruskal 용용
int find_(vector<int>& parent, int x) {
    if (parent[x] != x) parent[x] = find_(parent, parent[x]);
    return parent[x];
}

// Union 함수 (랭크 기반 합치기)  Kruskal 용용
void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find_(parent, x);
    int rootY = find_(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int minDistance(vector<vector<int>>& points){
/*
Solution 1: Prim’s Algorithm (O(N²))
Prim’s Algorithm 개요:
-한 점에서 시작하여 점점 트리를 확장하는 방식.
-각 단계에서 현재 MST에 가장 가까운 노드를 추가.
-Priority Queue (Min-Heap) 또는 배열을 이용하여 최소 비용 간선을 관리.n

Graph 중 Node들이 모~두 연결된 형태의 graph에서 MST를 찾는 문제로 봐도 되겠다.
*/
/*
    int n = points.size();
    vector<int> minDist(n,INT_MAX);
    vector<bool> inMST(n,false);
    int ans = 0;

    minDist[0] = 0; // 시작점 임의선택
    for(int i=0;i<n;i++){
        int idx = -1;
         
        // 현재 MST에 포함되지 않은 노드 중 최소 거리의 노드를 찾기
        for(int j=0; j<n; j++){
            if(!inMST[j] && (idx==-1 || minDist[j] < minDist[idx])){
                idx = j;
            }
        }
        inMST[idx] = true; // MST에 추가
        ans += minDist[idx];

        // 다른 노드들과 거리 갱신
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                minDist[v] = min(minDist[v], dist(points[idx], points[v])); // 새로 추가된 Node와 더 가까운 놈들은 Min 값으로 대체
            }
        }
    }
    return ans;
*/
//내가 다시 함 해보기
    // int n = points.size();
    // vector<int> minDist(n,INT_MAX);
    // vector<bool> visited(n,false);
    // minDist[1] = 0;
    // int ans = 0;
    // for(int i = 0; i < n ; i++){
    //     int idx = -1;
    //     for(int j=0;j<n;j++){
    //         if(!visited[j] && (idx ==-1 || minDist[j] < minDist[idx])){
    //             idx = j;
    //         }
    //     }
    //     visited[idx] = true;
    //     ans += minDist[idx];
    //     // distance update
    //     for(int k=0;k<n;k++){
    //         if(!visited[k]) minDist[k] = min(minDist[k],dist(points[idx],points[k]));
    //     }
    // }
    // return ans;
/*
    어렵다........
    Kruskal’s Algorithm (O(E log E))
    Kruskal’s Algorithm 개요:
    모든 간선을 리스트에 저장 (각 간선은 (거리, 점1, 점2) 형태).
    간선을 가중치 기준으로 정렬.
    Union-Find_를 사용하여 사이클을 방지하며 MST 구성.
*/
    int n = points.size();
    vector<tuple<int,int,int>> edges;

    // 모든 점 사이의 거리 계산하며 edge list 생성
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int d = dist(points[i],points[j]);
            edges.push_back({d,i,j});
        }
    } // N^2
    // edge sort -> 거리기준 정렬
    sort(edges.begin(),edges.end());

    // Union - find_ 초기화
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++) parent[i] = i;

    int ans = 0;
    int cnt = 0;
    for(auto [dist,u,v] : edges){
        if(find_(parent,u) != find_(parent,v)){
            unionSet(parent,rank,u,v);
            ans += dist;
            cnt++;
        }
        if(cnt == n-1) break; // MST 완성 n-1회만 시행
    }

    return ans;
}


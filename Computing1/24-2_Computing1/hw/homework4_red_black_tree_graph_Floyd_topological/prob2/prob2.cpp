// // prob2.cpp
// #include "prob2.hpp"
#include <iostream>             // 그냥 Cout print용, topological sort
// #include <vector>
// #include <queue>


// 풀이 1

// // 너비 우선 탐색(BFS)을 사용하여, start 정점에서
// // 도달할 수 있는 정점(학생) 수를 반환하는 헬퍼 함수
// // adj는 그래프의 인접 리스트, n은 정점(학생) 수
// static int bfsCount(int start, const std::vector<std::vector<int>>& adj, int n) {
//     std::vector<bool> visited(n+1, false); // 방문 여부 체크 (1-based)
//     std::queue<int> q;

//     visited[start] = true;
//     q.push(start);

//     int count = 0; // 도달 가능한 정점(자기 자신 제외) 수
//     while (!q.empty()) {
//         int curr = q.front();
//         q.pop();

//         for (int next : adj[curr]) {
//             if (!visited[next]) {
//                 visited[next] = true;
//                 q.push(next);
//                 count++; 
//             }
//         }
//     }
//     return count;
// }

// // 문제 2: 키 순서를 통해 절대적인 순위를 알 수 있는 학생 수를 구하는 함수
// int findKnownOrderStudents(int n, std::vector<std::pair<int, int>>& comparisons) {
//     // 인접 리스트(키가 더 작은 -> 더 큰)와 역방향 리스트(키가 더 큰 -> 더 작은)를 만든다
//     std::vector<std::vector<int>> adj(n+1);
//     std::vector<std::vector<int>> reverse_adj(n+1);

//     // comparisons에 따라 그래프를 구성
//     // 예: a < b 이면, adj[a].push_back(b), reverse_adj[b].push_back(a)
//     for (auto& comp : comparisons) {
//         int smaller = comp.first;  
//         int taller  = comp.second;
//         adj[smaller].push_back(taller);
//         reverse_adj[taller].push_back(smaller);
//     }

//     int result = 0; // 자신의 순위를 확실히 알 수 있는 학생 수

//     // 모든 학생 i에 대해 검사
//     for (int i = 1; i <= n; i++) {
//         // i보다 키가 큰 학생 수 (i에서 adj로 이동 가능)
//         int tallerCount = bfsCount(i, adj, n);
//         // i보다 키가 작은 학생 수 (i에서 reverse_adj로 이동 가능)
//         int smallerCount = bfsCount(i, reverse_adj, n);

//         // tallerCount + smallerCount == n - 1 이면
//         // 학생 i는 나머지 (n-1)명 모두와의 상대적 순서를 알 수 있음
//         if (tallerCount + smallerCount == n - 1) {
//             result++;
//         }
//     }

//     std::cout << "Number of students who know their exact rank: " << result << std::endl;
//     return result;
// }


// 풀이2
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int findKnownOrderStudents(int n, std::vector<std::pair<int, int>>& comparisons) {
    // Create adjacency lists for both directions
    std::vector<std::vector<int>> shorter(n + 1); // students shorter than i
    std::vector<std::vector<int>> taller(n + 1);  // students taller than i
    
    // Build the graph
    for (const auto& comp : comparisons) {
        int a = comp.first;
        int b = comp.second;
        // a is shorter than b
        taller[a].push_back(b);
        shorter[b].push_back(a);
    }
    
    int knownPositions = 0;
    
    // For each student
    for (int student = 1; student <= n; student++) {
        // Find all students taller than current student using BFS
        std::unordered_set<int> tallerStudents;
        std::queue<int> q;
        q.push(student);
        std::vector<bool> visited(n + 1, false);
        visited[student] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : taller[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    tallerStudents.insert(next);
                    q.push(next);
                }
            }
        }
        
        // Find all students shorter than current student using BFS
        std::unordered_set<int> shorterStudents;
        q = std::queue<int>();
        q.push(student);
        visited = std::vector<bool>(n + 1, false);
        visited[student] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : shorter[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    shorterStudents.insert(next);
                    q.push(next);
                }
            }
        }
        
        // If total number of students we know the relationship with
        // equals n-1, we know our exact position
        if (tallerStudents.size() + shorterStudents.size() == n - 1) {
            knownPositions++;
        }
    }
    cout << knownPositions << endl;
    return knownPositions;
}
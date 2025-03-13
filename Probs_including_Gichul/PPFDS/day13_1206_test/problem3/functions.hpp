#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "utils.hpp"
using namespace std;

class BinaryTree {
private:
    Node* root;
    Node* dllHead;
    Node* dllPrev;

public:
    BinaryTree() : root(nullptr), dllHead(nullptr), dllPrev(nullptr) {}

    void insert(int value) {
        utils::insert(root, value);
    }

    void function3() {
        // Fill this function
        // in-order
        if(!root) return;
        vector<Node*> vec;
        stack<Node*> s;
        Node* curr = root;

        while(!s.empty() || curr ){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            vec.push_back(curr);
            curr = curr->right;
        }
        dllHead = vec[0];
        for(int i=0;i<vec.size()-1;i++){
            vec[i]->right = vec[i+1];
        }
        // vec[vec.size()-1]->right = dllHead;
        for(int i=vec.size()-1;i>=1;i--){
            vec[i]->left = vec[i-1];
        }
        // dllHead->left = vec[vec.size()-1];

    // In-order traversal을 기반으로 doubly linked list 생성
        // if (!root) return; // 트리가 비어 있으면 반환

        // stack<Node*> s;
        // Node* curr = root;

        // while (!s.empty() || curr) {
        //     // 왼쪽 서브트리를 모두 스택에 삽입
        //     while (curr) {
        //         s.push(curr);
        //         curr = curr->left;
        //     }
        //     // 현재 노드 처리
        //     curr = s.top();
        //     s.pop();

        //     // DLL 연결 처리
        //     if (!dllHead) {
        //         // DLL의 첫 번째 노드 설정
        //         dllHead = curr;
        //         dllPrev = curr;
        //     } else {
        //         // 이전 노드와 현재 노드 연결
        //         dllPrev->right = curr;
        //         curr->left = dllPrev;
        //         dllPrev = curr;
        //     }

        //     // 오른쪽 서브트리로 이동
        //     curr = curr->right;
        // }
}

    void print() {
        utils::print(dllHead);
    }
    
    // If you need to construct another functions, write and use here. 
    // However, you can not use those functions in main.cpp.
    // Submit only functions.hpp file.

    // compile command: g++ -o main main.cpp
    // execute command: 
    //              ./main "10 12 15 25 30 36"
    // 25 12 30 10 36 15
};

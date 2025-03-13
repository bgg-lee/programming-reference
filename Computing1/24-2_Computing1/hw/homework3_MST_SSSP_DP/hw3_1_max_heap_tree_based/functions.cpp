#include <iostream> 
#include <climits> 
#include <queue>
#include <cmath>

#include "functions.hpp"

using namespace std; 


MaxHeap::MaxHeap(){
    root = nullptr;     
    last_node = nullptr; // 내가 추가
    heapsize = 0; // 내가 추가
}  

Node * MaxHeap::getMax(){
    return root;
}

void MaxHeap::printHeap(){
    Node * currNode = root;
    queue<Node*> q;

    q.push(root);
    std::cout << "Print Heap: ";
    while (!q.empty() && q.front()){
        std::cout << q.front()->val << " ";
        if (q.front()->left){
            q.push(q.front()->left);
        }

        if (q.front()->right){
            q.push(q.front()->right);
        }

        q.pop();
    }
    std::cout << std::endl;
}

void MaxHeap::swap(Node * a, Node * b){
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}


// Inserts a new key 'k' 
void MaxHeap::enqueue(int k) 
{
// 일단 new node 생성성
    Node* new_node = new Node();
    new_node->val = k;
    heapsize++;
// 1) root가 없다
    if(!root){
        root = new_node;
        last_node = new_node;
        return;
    }
// 2) 이미 root가 있다. 끝자리 찾아가기 BFT로 찾으면 될 거 같은데
// 야 이거 어렵다..
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(!curr->left){
            curr->left = new_node;
            new_node->parent = curr;
            break;
        }
        else if(!curr->right){
            curr->right = new_node;
            new_node->parent = curr;
            break;
        }
        q.push(curr->left);
        q.push(curr->right);
    } // 일단 마지막에 new_node를 집어넣긴 했다.
    last_node = new_node; // last_node는 마지막 '위치'한 node고 heapify up 할 때 값만 바꾸는 거라 last_node는 유지
    // Heap up
    Node* temp = new_node;
    while(temp->parent && temp->parent->val < temp->val){
        swap(temp,temp->parent); //value만 바꿈
        temp = temp->parent;
    }
}

// Removes the root node and heapify
// 얘는 heap - down 함수 따로 빼서 한 번 만들어보기
void MaxHeap::dequeue(){
    // root를 삭제하고, last node를 root자리로 옮기고, 그 놈을 heap-down , last node 위치를 다시 설정해주는 게 문제네
    // 아무 것도 없는 case
    if(!root) return;
    if(root == last_node){
        root = last_node = nullptr; // root node 하나만 있는 경우
    }else{ // node가 어느정도 있는 경우
        // root / last_node swap 후 last node를 끊어낸다.
        swap(root,last_node);
        
        if(last_node == last_node->parent->left){
            last_node->parent->left = nullptr;
        }else{
            last_node->parent->right = nullptr;
        }
        last_node = nullptr;
        // root(last_node 값)를 heap-down
        heap_down(root);

        // 다시 last_node를 설정해주는 작업 BFT 이게 좀 짜친다..
        queue<Node*> q;
        q.push(root);
        Node* curr = nullptr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        last_node = curr;
    }
    heapsize--;
}
// dequeue용 heap_down 함수 필요 --> Scope를 MaxHeap:: 이거 해줘야하고 hpp class 안에도 declare 해줘야 한다!!!!!!!!!!!
void MaxHeap::heap_down(Node* node){
    if(!node) return;
    Node* largest = node;
    if(node->left){
        if(node->left->val > node->val){
            largest = node->left;
        }
    }
    if(node->right){
        if(node->right->val > largest->val){
            largest = node->right;
        }
    }
    // left,right 중 현 node보다 큰 값이 있을 경우 recursive heap-down
    if(largest != node){
        swap(largest,node);
        heap_down(largest);
    }
}

/* // LLM 추천 코드.. 결과는 비슷해보인다.
void MaxHeap::heap_down(Node* node){
    if (!node) return;

    Node* largest = node;

    if (node->left && node->left->val > largest->val) {
        largest = node->left;
    }
    if (node->right && node->right->val > largest->val) {
        largest = node->right;
    }

    if (largest != node) {  // Swap only if needed
        swap(largest, node);
        heap_down(largest);
    }
}

void MaxHeap::enqueue(int k) {
    Node* new_node = new Node();
    new_node->val = k;
    heapsize++;

    if (!root) {
        root = last_node = new_node;
        return;
    }

    // BFS로 new_node 삽입할 위치 찾기
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (!curr->left) {
            curr->left = new_node;
            new_node->parent = curr;
            break;
        } else if (!curr->right) {
            curr->right = new_node;
            new_node->parent = curr;
            break;
        }
        q.push(curr->left);
        q.push(curr->right);
    }

    last_node = new_node;  // last_node 업데이트

    // Heapify-up
    Node* temp = new_node;
    while (temp->parent && temp->val > temp->parent->val) {
        swap(temp, temp->parent);
        temp = temp->parent;
    }
}


*/

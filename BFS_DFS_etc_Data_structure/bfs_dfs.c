#include <stdio.h>
#include <stdlib.h>
// 이진 트리 노드 정의
typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node -> val = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

// BFS (Level Order Traversal)
void bfs(TreeNode* root) {
    if(!root) return;
    int front = 0, rear = 0;
    TreeNode* q[100]; // 임의 설정
    q[rear++] = root;
    while(front < rear){
        TreeNode* temp = q[front++];
        printf("%d ",temp->val);
        if(temp->left) q[rear++] = temp->left;
        if(temp->right) q[rear++] = temp->right;
    }
}

// DFS (Preorder Traversal)
void dfs(TreeNode* root) {
    if(!root) return;
    int idx = 0;
    TreeNode* s[100];
    s[idx++] = root;
    while(idx>0){
        TreeNode* temp = s[--idx];
        printf("%d ",temp->val);
        if(temp->right) s[idx++] = temp->right;
        if(temp->left) s[idx++] = temp->left;
    }
}

// 트리 생성 및 테스트용 main 함수
int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("BFS (Level Order Traversal):\n");
    bfs(root);
    printf("\nDFS (Preorder Traversal):\n");
    dfs(root);
    
    return 0;
}
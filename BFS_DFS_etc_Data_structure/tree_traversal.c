#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int v){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node -> val = v;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

void preorder(TreeNode* root) {
    if(!root) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->left->right = createNode(8);
    root->left->left->right->left = createNode(9);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);
    
    return 0;
}



//      1
//     /\
//    2  3
//   /\  /\
//  4  5 6  7
//   \
//    8
//   /
// 9
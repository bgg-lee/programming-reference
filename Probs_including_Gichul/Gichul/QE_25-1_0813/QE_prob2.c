#include "stdio.h"
#include "stdlib.h"
#include "QE_prob2.h"
/*
 “Write your code or helper function here, if necessary.“
*/
int max(int a, int b){
    if(a>=b) return a;
    else return b;
}
// a
TreeNode *create_node(int val){
/* “Write your code here, if necessary.“ */
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node -> left_child = NULL;
    new_node -> right_sibling = NULL;
    new_node -> parent = NULL;
    new_node -> val = val;
    return new_node;
}

// b
int height(TreeNode *node) {
// root
    if(!node) return -1;
    int left = height(node->left_child);
    if(node->left_child){
        TreeNode* temp = node->left_child->right_sibling;
        int max_val = 0;
        while(temp){
            max_val = max(max_val,height(temp));
            temp = temp->right_sibling;
        }
        if(max_val == 0) return 1+left;
        else return 1+max(left,max_val);
    }
    return 1+left;
}

// int height(TreeNode *node) {
//     // root
//         if(!node) return -1;
//         int left = height(node->left_child);
//         if(node->left_child){
//             int right = height(node->left_child->right_sibling);
//             return 1+max(left,right);
//         }
//         return 1+left;
//     }
    

int n_ary(TreeNode *node) {
/*node BFT로 돌면서 children 수 체크 후 max 비교*/
    if(!node) return 0;
    int ans = 0;
    int front = 0, rear = 0;
    TreeNode* q[100001]; // 임의 설정
    q[rear++] = node;
    while(front < rear){
        TreeNode* temp = q[front++];
        int cnt = 0;
        if(temp->left_child){
            q[rear++] = temp->left_child;
            cnt++;
            TreeNode* nxt = temp->left_child->right_sibling;
            while(nxt){
                q[rear++] = nxt;
                nxt = nxt->right_sibling;
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    return ans;
    // printf("\n");
}

void bfs(TreeNode *node) {
    if(!node) return;
    int front = 0, rear = 0;
    TreeNode* q[100001]; // 임의 설정
    q[rear++] = node;
    while(front < rear){
        TreeNode* temp = q[front++];
        printf("%d ",temp->val);
        //left child 있다
        if(temp->left_child){
            q[rear++] = temp->left_child;
            // right 시블링 다 넣어
            TreeNode* nxt = temp->left_child->right_sibling;
            while(nxt){
                q[rear++] = nxt;
                nxt = nxt->right_sibling;
            }
        }
    }
    printf("\n");
}


// REMOVE this main function for submission
// int main() { 
//     TreeNode *ANode = create_node(1);
//     TreeNode *BNode = create_node(2);
//     TreeNode *CNode = create_node(3);
//     TreeNode *DNode = create_node(4);
//     TreeNode *ENode = create_node(5);
//     TreeNode *FNode = create_node(6);
//     TreeNode *GNode = create_node(7);
//     TreeNode *HNode = create_node(8);
//     TreeNode *INode = create_node(9);
//     TreeNode *JNode = create_node(10);
//     TreeNode *KNode = create_node(11);
//     TreeNode *LNode = create_node(12);

//     ANode->parent = NULL;
//     ANode->right_sibling = NULL;
//     ANode->left_child = BNode;

//     BNode->parent = ANode;
//     BNode->right_sibling = CNode;
//     BNode->left_child = DNode;

//     CNode->parent = ANode;
//     CNode->right_sibling = NULL;
//     CNode->left_child = FNode;

//     DNode->parent = BNode;
//     DNode->right_sibling = ENode;
//     DNode->left_child = NULL;

//     ENode->parent = BNode;
//     ENode->right_sibling = NULL;
//     ENode->left_child = JNode;

//     FNode->parent = CNode;
//     FNode->right_sibling = GNode;
//     FNode->left_child = NULL;

//     GNode->parent = CNode;
//     GNode->right_sibling = HNode;
//     GNode->left_child = KNode;

//     HNode->parent = CNode;
//     HNode->right_sibling = INode;
//     HNode->left_child = NULL;

//     INode->parent = CNode;
//     INode->right_sibling = NULL;
//     INode->left_child = NULL;

//     JNode->parent = ENode;
//     JNode->right_sibling = NULL;
//     JNode->left_child = NULL;
    
//     KNode->parent = GNode;
//     KNode->right_sibling = LNode;
//     KNode->left_child = NULL;

//     LNode->parent = GNode;
//     LNode->right_sibling = NULL;
//     LNode->left_child = NULL;

//     printf("%d\n", height(ANode)); // 3

//     printf("%d\n", n_ary(ANode)); // 4

//     bfs(ANode); // 1 2 3 4 5 6 7 8 9 10 11 12 \n
    
//     return 0;
// }


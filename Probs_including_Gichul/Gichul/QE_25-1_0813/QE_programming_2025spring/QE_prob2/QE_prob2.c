#include "stdio.h"
#include "stdlib.h"
#include "QE_prob2.h"

/*
 
 
 “Write your code or helper function here, if necessary.“



*/

TreeNode *create_node(int val){
/*
 
 “Write your code here, if necessary.“

*/

}

int height(TreeNode *node) {
/*
 
 “Write your code here, if necessary.“

*/
}


int n_ary(TreeNode *node) {
/*
 
 “Write your code here, if necessary.“

*/
}

void bfs(TreeNode *node) {
/*
 
 “Write your code here, if necessary.“

*/
}


// REMOVE this main function for submission
int main() { 
    TreeNode *ANode = create_node(1);
    TreeNode *BNode = create_node(2);
    TreeNode *CNode = create_node(3);
    TreeNode *DNode = create_node(4);
    TreeNode *ENode = create_node(5);
    TreeNode *FNode = create_node(6);
    TreeNode *GNode = create_node(7);
    TreeNode *HNode = create_node(8);
    TreeNode *INode = create_node(9);
    TreeNode *JNode = create_node(10);
    TreeNode *KNode = create_node(11);
    TreeNode *LNode = create_node(12);

    ANode->parent = NULL;
    ANode->right_sibling = NULL;
    ANode->left_child = BNode;

    BNode->parent = ANode;
    BNode->right_sibling = CNode;
    BNode->left_child = DNode;

    CNode->parent = ANode;
    CNode->right_sibling = NULL;
    CNode->left_child = FNode;

    DNode->parent = BNode;
    DNode->right_sibling = ENode;
    DNode->left_child = NULL;

    ENode->parent = BNode;
    ENode->right_sibling = NULL;
    ENode->left_child = JNode;

    FNode->parent = CNode;
    FNode->right_sibling = GNode;
    FNode->left_child = NULL;

    GNode->parent = CNode;
    GNode->right_sibling = HNode;
    GNode->left_child = KNode;

    HNode->parent = CNode;
    HNode->right_sibling = INode;
    HNode->left_child = NULL;

    INode->parent = CNode;
    INode->right_sibling = NULL;
    INode->left_child = NULL;

    JNode->parent = ENode;
    JNode->right_sibling = NULL;
    JNode->left_child = NULL;
    
    KNode->parent = GNode;
    KNode->right_sibling = LNode;
    KNode->left_child = NULL;

    LNode->parent = GNode;
    LNode->right_sibling = NULL;
    LNode->left_child = NULL;

    printf("%d\n", height(ANode));

    printf("%d\n", n_ary(ANode));

    bfs(ANode);
    
    return 0;
}


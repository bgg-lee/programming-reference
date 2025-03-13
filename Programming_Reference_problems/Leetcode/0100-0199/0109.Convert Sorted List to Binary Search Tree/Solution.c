/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* find(struct ListNode* start, struct ListNode* end) {
    struct ListNode* fast = start;
    struct ListNode* slow = start;
    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct TreeNode* bulid(struct ListNode* start, struct ListNode* end) {
    if (start == end) {
        return NULL;
    }
    struct ListNode* node = find(start, end);
    struct TreeNode* ans = malloc(sizeof(struct TreeNode));
    ans->val = node->val;
    ans->left = bulid(start, node);
    ans->right = bulid(node->next, end);
    return ans;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return bulid(head, NULL);
}



/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 /*
struct TreeNode* helper(int arr[],int left, int right){
    if(left > right) return NULL;
    int mid = (left+right)/2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = helper(arr,left,mid-1);
    root->right = helper(arr,mid+1,right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(!head) return NULL;
    if(!head->next){
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = head->val;
        temp->left = NULL; // C 에선 이런 초기화 필요
        temp->right = NULL;
        return temp;
    }
    int arr[100000];
    int idx = 0;
    while(head){
        arr[idx++] = head->val;
        head = head->next;
    }
    return helper(arr,0,idx-1);
}

*/
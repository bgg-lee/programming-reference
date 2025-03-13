#include <vector>         
#include <queue>          
#include <iostream>       
#include <stdio.h>
#include <string>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    /*=============================================== TODO 1 ===============================================
    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

    Constraints:
        0 <= word1.length, word2.length <= 500
        word1 and word2 consist of lowercase English letters.
    =======================================================================================================*/

    int minDistance(const std::string& word1, const std::string& word2) {
        int m = word1.size();
        int n = word2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; 
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; 
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }

        return dp[m][n];
    }

    /*=============================================== TODO 2 ===============================================
    You are given an array of k linked-lists lists, each linked-list is sorted in descending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Definition for singly-linked list is as follows:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    Constraints:
        k == lists.length
        0 <= k <= 104
        0 <= lists[i].length <= 500
        -104 <= lists[i][j] <= 104
        lists[i] is sorted in ascending order.
        The sum of lists[i].length will not exceed 104.
    =======================================================================================================*/
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        std::priority_queue<int> q;

        bool allNull = true;
        for(ListNode* node: lists) {
            if(node != nullptr) {
                allNull = false;
                ListNode* head = node;
                while(head != nullptr) {
                    q.push(head->val);
                    head = head->next;
                }
            }

        }
        
        if(allNull) {
            return nullptr;
        }
        
        ListNode* ans;
        int headVal = q.top();
        q.pop();
        ListNode* head = new ListNode(headVal);
        ans = head;
        while(!q.empty()) {
            ListNode* nextNode = new ListNode(q.top());
            q.pop();
            head->next = nextNode;
            head = head->next;
        }
        return ans;
    }



    /*=============================================== TODO 3 ===============================================
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
    Can you solve it without sorting?

    Constraints:
        1 <= k <= nums.length <= 105
        -104 <= nums[i] <= 104
    =======================================================================================================*/
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> q;
        for(int num: nums) {
            q.push(num);
        }
        k--;
        while(k--) {
            q.pop();
        }
        return q.top();
    }
    
};


////////////////////// DO NOT MODIFY THIS ////////////////////////
ListNode* createList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    if(head == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << "[";
    while (head) {
        if(head->next == nullptr) {
            std::cout << head->val << "]";
            head = head->next;
        }
        else{
            std::cout << head->val << " ";
            head = head->next;
        } 
    }
    std::cout << std::endl;
}
////////////////////// DO NOT MODIFY THIS ////////////////////////

int main() {
    Solution* solution = new Solution();

    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << "Minimum edit distance: " << solution->minDistance(word1, word2) << std::endl; // expected output: 3


    std::string word3 = "intention";
    std::string word4 = "execution";
    std::cout << "Minimum edit distance: " << solution->minDistance(word3, word4) << std::endl; // expected output: 5


    std::vector<ListNode*> lists1 = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    std::cout << "Merged list for [[1,4,5],[1,3,4],[2,6]]: ";
    ListNode* result1 = solution->mergeKLists(lists1);
    printList(result1); // expected output: [6, 5, 4, 4, 3, 2, 1]

    
    std::vector<ListNode*> lists2 = {};
    std::cout << "Merged list for []: ";
    ListNode* result2 = solution->mergeKLists(lists2);
    printList(result2); // nullptr

    
    std::vector<ListNode*> lists3 = {nullptr};
    std::cout << "Merged list for [[]]: ";
    ListNode* result3 = solution->mergeKLists(lists3);
    printList(result3); // nullptr

    std::vector<ListNode*> lists4 = {
        createList({1}),
        nullptr,
        createList({2, 3})
    };
    std::cout << "Merged list for [[1],[],[2,3]]: ";
    ListNode* result4 = solution->mergeKLists(lists4);
    printList(result4); //[3, 2, 1]


    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4, 5};
    int k1 = 2;
    std::cout << "Output: " << solution->findKthLargest(nums1, k1) << std::endl; // expected output : 5


    std::vector<int> nums2 = {7, 10, 4, 3, 20, 15};
    int k2 = nums2.size();
    std::cout << "Output: " << solution->findKthLargest(nums2, k2) << std::endl; // expected output : 3


    std::vector<int> nums3 = {7, 10, 4, 3, 20, 15};
    int k3 = 1;
    std::cout << "Output: " << solution->findKthLargest(nums3, k3) << std::endl; // expected output : 20
    


    delete solution;

    return 0;
}

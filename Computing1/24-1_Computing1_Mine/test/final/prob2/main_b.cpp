#include "prob_2.hpp"


int main() {
    BST* rbtree = new RBTree;
    vector<int> node_value = {10,20,30,15,25,5,1};
    for(auto i:node_value){
        rbtree->insert(i);
    }
    rbtree->search(25);
    return 0;
}
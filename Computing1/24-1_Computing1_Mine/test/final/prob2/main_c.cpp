#include "prob_2.hpp"


int main() {
    vector<int> node_value = {10,20,30,15,25,5,1};
    RBTree* rbtree = new RBTree;
    for(auto i:node_value){
        rbtree->insert(i);
    }
    rbtree->RBCounter();
    return 0;
}
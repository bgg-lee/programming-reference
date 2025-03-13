#include "prob_2.hpp"


int main() {
    BST* tree = new BST;
    vector<int> node_value = {10,20,30,15,25,5,1};
    for(auto i:node_value){
        tree->insert(i);
    }
    tree->search(25);
    return 0;
}
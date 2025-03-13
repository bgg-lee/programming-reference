#include "prob1.hpp"

int main() {
    
    Node* root = new Node{5, false, nullptr, nullptr, nullptr};
    validateRedBlackTree(root);

    delete root;

    return 0;
}

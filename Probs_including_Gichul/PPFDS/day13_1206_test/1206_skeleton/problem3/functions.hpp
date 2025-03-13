#include <iostream>
#include <queue>
#include "utils.hpp"
using namespace std;

class BinaryTree {
private:
    Node* root;
    Node* dllHead;
    Node* dllPrev;

public:
    BinaryTree() : root(nullptr), dllHead(nullptr), dllPrev(nullptr) {}

    void insert(int value) {
        utils::insert(root, value);
    }

    void function3() {
        // Fill this function
    }

    void print() {
        utils::print(dllHead);
    }
    
    // If you need to construct another functions, write and use here. 
    // However, you can not use those functions in main.cpp.
    // Submit only functions.hpp file.

    // compile command: g++ -o main main.cpp
    // execute command: 
    //              ./main "10 12 15 25 30 36"

};

#include <iostream> 

template <typename T>
class Node {
public:
    T data;           
    Node* next;       

    Node(T value) : data(value), next(nullptr) {}  
};


template <typename T>
class SimpleList {
public:
    Node<T>* head;  
    SimpleList() : head(nullptr) {}


};

#include <iostream> 
#include <climits> 
#include <queue>
#include <cmath>
using namespace std; 

#include "functions.hpp"
  
// Driver program to test above functions 
int main() {
    MaxHeap h;

    h.enqueue(10);
    h.enqueue(15);
    h.enqueue(30);
    h.enqueue(40);
    h.enqueue(50);
    h.enqueue(60);
    h.enqueue(70);
    h.enqueue(5);
    h.enqueue(1);
    h.enqueue(100);

    h.printHeap();  // Should print a valid max heap

    return 0;
}

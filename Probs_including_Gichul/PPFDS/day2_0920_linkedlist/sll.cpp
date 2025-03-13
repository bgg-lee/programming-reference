#include <iostream>
using namespace std;

class Node {
public:
    int data; // 노드가 저장하는 데이터
    Node* next; // 다음 노드를 가리키는 포인터

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SingleLinkedList {
public:
    Node* head; // 리스트의 첫 번째 노드를 가리키는 포인터

    SingleLinkedList() {
        head = nullptr;
    }

    // 소멸자에서 동적으로 할당된 모든 노드를 해제
    ~SingleLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;  // 동적으로 할당된 노드를 해제
            current = nextNode;
        }
    }    

    // 리스트의 끝에 노드를 추가
    void append(int data) { /// append(Node data) 등, 다양하게 들어갈 수 있다. -> 문제를 풀 때마다 여러 가정을 해보기
        Node* new_node = new Node(data);

        if (head == nullptr) { // 리스트가 비어있는 경우 /// 이런 Edge Case를 항상 생각하라. Example 몇 개를 돌리며 잡자
            head = new_node;
            return;
        }

        // 리스트의 끝까지 이동
        Node* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    /// Practice
    void insert_front(int data){
        Node* new_node = new Node(data);
        if(!head) head = new_node;
        else{
            new_node->next = head;
            head = new_node;
        }
    }
    ///Practice
    void insert_after_key(int key, int new_data){
        
        Node* curr = head;
        while(curr){
            if(curr->data == key) break;
            curr = curr->next;
        }
        /// key 값에 해당하는 data가 있을 경우
        if(curr){
            Node* new_node = new Node(new_data);
            new_node -> next = curr->next;
            curr->next = new_node;
        /// key 값에 해당하는 data가 없는 경우
        }else return;
    }
    ///Practice
    void insert_before_key(int key, int new_data){
        if(!head) return;

        Node* slow = nullptr;
        Node* fast = head;
        while(fast){
            if(fast->data == key) break;
            slow = fast;
            fast = fast->next;
        }
        /// head에서 key node 발견
        if(fast == head){
            Node* new_node = new Node(new_data);
            new_node->next = head;
            head = new_node;
        }
        /// 중간에서 key node 발견
        else if(fast){
            Node* new_node = new Node(new_data);
            new_node->next = fast;
            slow->next = new_node;
        }
        /// key node 없음
        else return;

    }

    // 리스트에서 특정 값을 가진 노드를 삭제
    void deleteNode(int key) { /// delete 할 때 C, C++은 꼭 memory free를 해야한다. /// + insert 처럼 delete를 LL의 처음,중간,끝에서 아무 곳이나 할 수 있어야함
        Node* current_node = head;
        Node* prev = nullptr;

        // 헤드가 삭제할 노드를 가리키는 경우
        if (current_node != nullptr && current_node->data == key) {
            head = current_node->next;
            delete current_node;
            return;
        }

        // 삭제할 노드를 찾으면서 이동
        while (current_node != nullptr && current_node->data != key) {
            prev = current_node;
            current_node = current_node->next;
        }

        // 노드가 리스트에 없는 경우
        if (current_node == nullptr) {
            return;
        }

        // 노드를 삭제
        prev->next = current_node->next;
        delete current_node;
    }
    /// Practice reverse를 앞에서부터 / *뒤에서부터 바꾸는 걸 다 할 수 있어야 한다.
    /*
    void reverse(void){
        // 앞에서부터 바꾸기
        Node* slow = nullptr;
        Node* curr = head;
        Node* fast = nullptr;
        while(curr){
            fast = curr->next;
            curr->next = slow;
            slow = curr;
            curr = fast;
        }
        head = slow;
    }*/
    void reverse(void){
        // 뒤에서부터 바꾸기
        if(!head||!head->next) return;
        /// Header 저장용
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }

        while(head->next){/// 이게 key point 1
            Node* curr = head;
            Node* prev = nullptr;
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }
            curr->next = prev;
            prev->next = nullptr; /// 이게 key point 2
        }
        head = temp;
    }
    // 리스트를 출력
    void printList() {
        Node* current_node = head;
        while (current_node != nullptr) {
            cout << current_node->data << " -> ";
            current_node = current_node->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    SingleLinkedList sll;
    sll.append(1);
    sll.append(2);
    sll.append(3);
    sll.append(2);
    sll.printList();  
    cout << "After reverse: " << endl;
    sll.reverse();
    sll.printList();  
    cout << endl;
    // sll.deleteNode(2);
    // sll.printList();  // 1 -> 3 -> nullptr

    // sll.deleteNode(1);
    // sll.printList();  // 3 -> nullptr

    // sll.deleteNode(3);
    // sll.printList();  // nullptr

    return 0;
}
/*
    Practice _5-A.c => 음악 playlist를 doubly linked list를 C, C++로 구현하는 거 추천 공부!

    Circular Linked list, last라는 node를 notice 해야 함(node가 next가르키는게 header랑 같은지 check로 last node 확인 가능하긴 함)
    마지막 pointer만 잘 처리해주면 된다.

    Doubly LL : 앞 or 뒤에서부터 traversal 할 수 있다. pointer가 head / tail 혹은 last 모두 있어야 한다.
    constructor에 ptr 2개 다 선언이 필요하다. --> 논자시에 나온 적 있는데 어려웠다.

*/
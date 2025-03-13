#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = nullptr;
        Node(int data):data(data),next(nullptr){}
};

class SLL{
    public:
        Node* head;
        SLL(){
            head = nullptr;
        }
        ~SLL(){
            if(!head) return;
            Node* curr = head;
            while(curr){
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }
        void insert_front(int data){
            Node* new_node = new Node(data);
            if(!head) head = new_node;
            else{
                new_node->next = head;
                head = new_node;
            }
        }
        void printList(){
            Node* current_node = head;
            while (current_node != nullptr) {
                cout << current_node->data << " -> ";
                current_node = current_node->next;
            }
            cout << "nullptr" << endl;
        }        
};
SLL* merge(Node* head1, Node* head2){
    // SLL* m = new SLL();
    // Node* dummy = new Node(0);  // 더미 노드로 시작
    // Node* curr = dummy;

    // while (head1 && head2) {
    //     if (head1->data < head2->data) {
    //         curr->next = new Node(head1->data);  // 새 노드를 생성하여 병합 리스트에 추가
    //         head1 = head1->next;
    //     } else {
    //         curr->next = new Node(head2->data);  // 새 노드를 생성하여 병합 리스트에 추가
    //         head2 = head2->next;
    //     }
    //     curr = curr->next;
    // }

    // // 남아있는 노드를 모두 복사하여 병합 리스트에 추가
    // while (head1) {
    //     curr->next = new Node(head1->data);
    //     curr = curr->next;
    //     head1 = head1->next;
    // }

    // while (head2) {
    //     curr->next = new Node(head2->data);
    //     curr = curr->next;
    //     head2 = head2->next;
    // }

    // m->head = dummy->next;
    // delete dummy;  // 더미 노드 삭제

    // return m;
    SLL *m = new SLL();
    Node* dummy = new Node(999);
    Node* curr = dummy;
    while(head1 && head2){
        if(head1->data < head2->data){
            curr->next = head1;
            head1 = head1->next;
        }else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    /// Empty list 정리
    if(head1){
        curr->next = head1;
    }else curr->next = head2;
    m->head = dummy->next;
    delete dummy;

    return m;
};

int main(){
    SLL l1;
    l1.insert_front(5);
    l1.insert_front(3);
    l1.insert_front(1);
    cout<< "l1:\t";
    l1.printList();
    SLL l2;
    l2.insert_front(4);
    l2.insert_front(2);
    l2.insert_front(1);
    cout<< "l2:\t";
    l2.printList();
    cout<< "merge:\t";
    SLL* test = merge(l1.head,l2.head);
    test->printList();
    delete(test);
    l1.head = nullptr;
    l2.head = nullptr;
    return 0;
}
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
    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) { // 리스트가 비어있는 경우
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

    void insert_head(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }    

    // 주어진 키 이후에 새로운 데이터를 삽입하는 함수
    void insert_after(int key, int data) {
        Node* curr = head;

        // 리스트에서 주어진 키 값을 찾음
        while (curr != nullptr) {
            if (curr->data == key) {
                break;
            }
            curr = curr->next;
        }

        // 키 값이 리스트에 없는 경우
        if (curr == nullptr) {
            cout << "Key " << key << " not found in the list." << endl;
            return;
        }

        // 새로운 노드를 삽입
        Node* newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // 주어진 키 앞에 새로운 노드를 삽입하는 함수
    void insert_before(int key, int data) {
        // 리스트가 비어 있을 때
        if (head == nullptr) {
            return;
        }

        // 키 값이 헤드에 있을 때 (다시 호출?)
        if (head->data == key) {
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
            return;
        }

        // 현재 노드와 이전 노드를 가리키는 포인터 초기화
        Node* curr = head;
        Node* prev = nullptr;

        // 주어진 키를 찾을 때까지 리스트를 순회
        while (curr != nullptr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        // 키가 리스트에서 발견되면 삽입
        if (curr != nullptr) {
            Node* new_node = new Node(data);
            prev->next = new_node;
            new_node->next = curr;
        }
    }

        // 주어진 위치에 새로운 노드를 삽입하는 함수
    void insert_position(int position, int data) {
        Node* newNode = new Node(data);

        // 첫 번째 위치에 삽입하는 경우
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        // 삽입할 위치의 바로 이전 노드를 찾음
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        // 위치가 리스트의 범위를 벗어난 경우
        if (current == nullptr) {
            cout << "Position is out of bounds." << endl;
            delete newNode;  // 메모리 누수 방지
            return;
        }

        // 새로운 노드를 삽입
        newNode->next = current->next;
        current->next = newNode;
    }


    // 리스트에서 특정 값을 가진 노드를 삭제
    void deleteNode(int key) {
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
    sll.printList();  // 1 -> 2 -> 3 -> nullptr

    sll.deleteNode(2);
    sll.printList();  // 1 -> 3 -> nullptr

    sll.deleteNode(1);
    sll.printList();  // 3 -> nullptr

    sll.deleteNode(3);
    sll.printList();  // nullptr

    return 0;
}
#include <iostream>
using namespace std;

// Node 템플릿 클래스 정의
template <typename T>
class Node {
public:
    T data;  // 노드가 저장하는 데이터
    Node* next;  // 다음 노드를 가리키는 포인터

    // 생성자
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Singly Linked List 템플릿 클래스 정의 --> General 한 LL 만들기 가능
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;  // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    // 생성자: 리스트의 시작은 비어 있음
    SinglyLinkedList() {
        head = nullptr;
    }

    // 소멸자: 메모리 해제
    ~SinglyLinkedList() {
        Node<T>* current = head;
        Node<T>* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // 리스트의 끝에 새로운 노드를 추가
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 리스트의 모든 노드를 출력
    void printList() {
        Node<T>* current = head;
        if (current == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // 리스트에서 첫 번째로 발견되는 값을 삭제
    void deleteNode(T key) {
        if (head == nullptr) return;

        // 헤드가 삭제할 노드를 가리키는 경우
        if (head->data == key) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // 삭제할 노드를 찾음
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        // 노드가 없는 경우
        if (current == nullptr) return;

        // 노드를 삭제
        prev->next = current->next;
        delete current;
    }
};

int main() {
    // int 타입의 Singly Linked List 사용 예시
    SinglyLinkedList<int> intList;
    intList.append(10);
    intList.append(20);
    intList.append(30);
    intList.printList(); // 10 -> 20 -> 30 -> nullptr
    intList.deleteNode(20);
    intList.printList(); // 10 -> 30 -> nullptr

    // string 타입의 Singly Linked List 사용 예시
    SinglyLinkedList<string> stringList;
    stringList.append("apple");
    stringList.append("banana");
    stringList.append("cherry");
    stringList.printList(); // apple -> banana -> cherry -> nullptr
    stringList.deleteNode("banana");
    stringList.printList(); // apple -> cherry -> nullptr

    return 0;
}
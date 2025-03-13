#include <iostream>
using namespace std;

// 템플릿을 사용하여 Node 클래스를 정의
template <typename T>
class Node {
public:
    T data;  // 타입이 템플릿 파라미터인 데이터를 저장
    Node* next; // 다음 노드를 가리키는 포인터

    Node(T data) {  // 생성자에서 템플릿 타입 데이터를 받음
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    // int 타입의 Node 생성
    Node<int>* intNode = new Node<int>(5);
    cout << "Integer Node data: " << intNode->data << endl;

    // double 타입의 Node 생성
    Node<double>* doubleNode = new Node<double>(3.14);
    cout << "Double Node data: " << doubleNode->data << endl;

    // string 타입의 Node 생성
    Node<string>* stringNode = new Node<string>("Hello");
    cout << "String Node data: " << stringNode->data << endl;

    // 메모리 해제
    delete intNode;
    delete doubleNode;
    delete stringNode;

    return 0;
}
#include "prob1.hpp"
#include <iostream>
using namespace std;

// 노드를 생성하는 헬퍼 함수
static Node* createNode(int key, bool isRed, Node* parent = nullptr) {
    Node* node = new Node;
    node->key   = key;       // 키 값
    node->isRed = isRed;     // true = Red, false = Black
    node->left  = nullptr;
    node->right = nullptr;
    node->parent= parent;
    return node;
}

// 트리 전체를 삭제하는 헬퍼 함수 (후위 순회)
static void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // [Test 1] Empty Tree
    //  - 빈 트리는 일반적으로 유효한 레드-블랙 트리로 간주됨
    {
        Node* root = nullptr;
        bool valid = validateRedBlackTree(root);
        cout << "Test 1: " << (valid ? "True" : "False") << endl;
        // root가 nullptr이므로 deleteTree 불필요
    }

    // [Test 2] Single Black Root
    //  - 루트만 존재, 루트가 검정인 경우
    {
        Node* root = createNode(10, false); // false=Black
        bool valid = validateRedBlackTree(root);
        cout << "Test 2: " << (valid ? "True" : "False") << endl;
        deleteTree(root);
    }

    // [Test 3] Single Red Root
    //  - 루트만 존재, 루트가 빨강이면 일반적으로 RBT 규칙(루트는 검정)에 위배
    {
        Node* root = createNode(10, true);  // true=Red
        bool valid = validateRedBlackTree(root);
        cout << "Test 3: " << (valid ? "True" : "False") << endl;
        deleteTree(root);
    }

    // [Test 4] Small valid RBT
    //       (20, Black)
    //         /     \
    // (10, Red)   (30, Red)
    //  - 빨강 노드(10, 30)는 자식이 모두 nullptr(Black)로 간주되므로 red-red 위반 없음
    //  - 블랙 높이도 왼/오른 서브트리가 동일
    {
        Node* root  = createNode(20, false);   // Black root
        Node* left  = createNode(10, true,  root); // Red
        Node* right = createNode(30, true,  root); // Red
        root->left  = left;
        root->right = right;

        bool valid = validateRedBlackTree(root);
        cout << "Test 4: " << (valid ? "True" : "False") << endl;
        deleteTree(root);
    }

    // [Test 5] Red-Red Violation
    //       (15, Black)
    //        /
    // (10, Red)
    //   /
    // (5, Red)  <-- Parent/Child 모두 빨강 => 위반
    {
        Node* root     = createNode(15, false); // Black
        Node* left     = createNode(10, true,  root); // Red
        Node* leftLeft = createNode(5,  true,  left); // Red => Violation
        root->left     = left;
        left->left     = leftLeft;

        bool valid = validateRedBlackTree(root);
        cout << "Test 5: " << (valid ? "True" : "False") << endl;
        deleteTree(root);
    }

    // [Test 6] Black-height Mismatch
    //         (40, Black)
    //          /       \
    //   (20, Black)  (60, Black)
    //     /     \
    // (10, Black) (30, Black)
    //   /
    // (7, Black)  <-- 왼쪽 서브트리에만 블랙 노드가 하나 추가되어 블랙 높이 불일치
    {
        Node* root       = createNode(40, false);
        Node* left       = createNode(20, false, root);
        Node* right      = createNode(60, false, root);
        root->left       = left;
        root->right      = right;

        Node* leftLeft   = createNode(10, false, left);
        Node* leftRight  = createNode(30, false, left);
        left->left       = leftLeft;
        left->right      = leftRight;

        // 왼쪽 최하단에 추가 블랙 노드
        Node* extraBlack = createNode(7, false, leftLeft);
        leftLeft->left   = extraBlack;

        bool valid = validateRedBlackTree(root);
        cout << "Test 6: " << (valid ? "True" : "False") << endl;
        deleteTree(root);
    }

    // 프로그램이 여기까지 도달하면 모든 테스트 케이스를 실행한 것
    return 0;
}

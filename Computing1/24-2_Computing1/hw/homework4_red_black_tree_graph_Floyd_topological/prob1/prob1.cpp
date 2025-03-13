#include "prob1.hpp"

// 이 함수는 서브트리의 "블랙 높이(black-height)"를 계산하고,
// 트리가 레드-블랙 규칙을 위배하면 -1을 반환합니다.
// 블랙 높이(black-height) = 어떤 노드에서부터 리프(nullptr)에 이르는 경로에 포함된 블랙 노드 수
// 참고: nullptr는 블랙 리프로 간주하므로 black-height = 1
static int checkBlackHeight(Node* node) {
    // node가 nullptr이면 블랙 리프로 간주 => 블랙 높이는 1
    if (node == nullptr) {
        return 1;
    }

    // 왼쪽 서브트리의 블랙 높이를 구한다
    int leftBH = checkBlackHeight(node->left);
    if (leftBH < 0) {
        // 왼쪽 서브트리가 유효하지 않으면 바로 -1 반환
        return -1;
    }

    // 오른쪽 서브트리의 블랙 높이를 구한다
    int rightBH = checkBlackHeight(node->right);
    if (rightBH < 0) {
        // 오른쪽 서브트리가 유효하지 않으면 -1 반환
        return -1;
    }

    // 레드-레드(parent-child) 위반 확인:
    // 노드가 빨강이면, 자식이 빨강이면 안 된다.
    if (node->isRed) {
        if (node->left  && node->left->isRed)  return -1;
        if (node->right && node->right->isRed) return -1;
    }

    // 왼쪽과 오른쪽의 블랙 높이가 다르면 -1(유효하지 않음) 반환
    if (leftBH != rightBH) {
        return -1;
    }

    // 이 노드가 검정이면 블랙 높이가 +1 증가
    // 이 노드가 빨강이면 그대로
    if (!node->isRed) {
        // 검정 노드
        return leftBH + 1;
    } else {
        // 빨강 노드
        return leftBH;
    }
}
// 문제에선 아래 이것만 나왔었음.
bool validateRedBlackTree(Node* root) {
    // 빈 트리는 유효한 레드-블랙 트리로 간주한다
    if (root == nullptr) {
        return true;
    }

    // 일반적인 레드-블랙 트리 규칙: 루트는 검정이어야 한다
    if (root->isRed) {
        // 루트가 빨강이면 유효하지 않다고 본다
        return false;
    }

    // 블랙 높이를 확인하고, -1이면 트리가 유효하지 않다
    int blackHeight = checkBlackHeight(root);
    return (blackHeight >= 0);
}
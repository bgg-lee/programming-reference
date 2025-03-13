#include <stdio.h>
#include <stdlib.h>

int arraysEqual(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0; // �迭�� ��Ұ� �ٸ��� 0 ��ȯ
    }
    return 1; // ��� ��Ұ� ������ 1 ��ȯ
}

int isArrSubarray(int* subArray, int subArraySize, int** mainArray, int mainArraySize) {
    for (int i = 0; i < mainArraySize; i++) {
        if (arraysEqual(subArray, mainArray[i], subArraySize)) {
            return 1; // subArray�� mainArray�� ��� �� �ϳ��� ��ġ
        }
    }
    return 0; // ��ġ�ϴ� ��Ұ� ����
}


int main() {
    int subArray[] = {1, 2, 3};
    int subArraySize = sizeof(subArray) / sizeof(subArray[0]);
    
    // �� �迭�� ���� ����
    int arr1[] = {1, 2, 3};
    int arr2[] = {2, 3, 1};
    int arr3[] = {2, 1, 3};

    // �迭���� �ּҸ� mainArray�� ����
    int* mainArray[] = {arr1, arr2, arr3};
    int mainArraySize = sizeof(mainArray) / sizeof(mainArray[0]);


    int result = isArrSubarray(subArray, subArraySize, mainArray, mainArraySize);
    if (result) {
        printf("The subArray is a part of mainArray.\n");
    } else {
        printf("The subArray is NOT a part of mainArray.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//�Է¹ޱ�
int main() {
    // ������ ���� ���� �� �Է� �ޱ�
    int integerVar;
    printf("������ �Է��ϼ���: ");
    scanf("%d", &integerVar);
    printf("�Է��� ����: %d\n", integerVar);

    // ������ ���� ���� �� �Է� �ޱ�
    char charVar;
    printf("���ڸ� �Է��ϼ���: ");
    scanf(" %c", &charVar);  // ����: %c ���� �����̽��ٸ� �����Ͽ� ������ ó���մϴ�.
    printf("�Է��� ����: %c\n", charVar);

    // ���ڿ�(�迭) �Է� �ޱ�
    char stringVar[50];  // �ִ� 49���ڱ��� �Է� ���� �� �ֵ��� ����
    printf("���ڿ��� �Է��ϼ���: ");
    scanf("%s", stringVar);  // ������ �������� �ʴ� ���ڿ� �Է�
    printf("�Է��� ���ڿ�: %s\n", stringVar);

    // �������� �޸� �Ҵ��Ͽ� �迭 �Է� �ޱ�
    int arraySize;
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &arraySize);

    int* dynamicArray = (int*)malloc(arraySize * sizeof(int));
    printf("%d���� ������ �Է��ϼ���: ", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &dynamicArray[i]);
    }

    printf("�Է��� �迭: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // �������� �Ҵ��� �޸� ����
    free(dynamicArray);

    return 0;
}


//string ����

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    // ���ڿ� ����
    int len = strlen(str1);
    printf("���ڿ� ����: %d\n", len);

    // ���ڿ� ����
    strcpy(str1, str2);
    printf("����� ���ڿ�: %s\n", str1);

    return 0;
}



// ����

int main() {
    char ch = 'A';

    // ���ĺ����� Ȯ��
    if (isalpha(ch)) {
        printf("%c�� ���ĺ��Դϴ�.\n", ch);
    }

    // �������� Ȯ��
    if (isdigit(ch)) {
        printf("%c�� �����Դϴ�.\n", ch);
    }

    return 0;
}


// ����
int main() {
    double num = 25.0;

    // ������ ���ϱ�
    double sqrtResult = sqrt(num);
    printf("������: %lf\n", sqrtResult);

    // �ﰢ�Լ� ���
    double sinResult = sin(num);
    printf("���� ��: %lf\n", sinResult);

    return 0;
}


#include <stdio.h>
#include <string.h>

int issubstring(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    // 'a'�� �� ���ڿ��� ���, �׻� 'b'�� �κ� ���ڿ��� ����
    if (lenA == 0) return 1;

    for (int i = 0; i <= lenB - lenA; i++) {
        // 'b'���� 'a'�� ��ġ�ϴ� �κ��� ã��
        int match = 1; // ��ġ�ϴ��� ���θ� ����
        for (int j = 0; j < lenA; j++) {
            if (b[i + j] != a[j]) {
                match = 0;
                break; // ��ġ���� ������ ���� ����
            }
        }
        if (match) return 1; // ��ü 'a' ���ڿ��� 'b' ������ ��ġ
    }

    return 0; // ��ġ�ϴ� �κ� ���ڿ��� ����
}

int main() {
    const char* a = "abc";
    const char* b = "abcdbd";

    if (issubstring(a, b)) {
        printf("\"%s\" is a substring of \"%s\".\n", a, b);
    } else {
        printf("\"%s\" is NOT a substring of \"%s\".\n", a, b);
    }

    return 0;
}

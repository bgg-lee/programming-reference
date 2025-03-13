#include <stdio.h>
#include <string.h>

// ����ü�� ����Ͽ� �Ҹ��� ���� ����� �Բ� ��ȯ
typedef struct {
    int found; // ã�Ҵٸ� 1, �ƴϸ� 0
    size_t position; // ������ ��ġ
} CharFindResult;

CharFindResult findCharInString(const char* str, char ch) {
    CharFindResult result;
    // ���ڿ����� ���ڸ� ã�� ��ġ�� ��ȯ
    char* found = strchr(str, ch);
    if (found != NULL) {
        result.found = 1;
        result.position = (size_t)(found - str); 
    } else {
        result.found = 0;
        result.position = 0; // ã�� ���ߴٸ� 0
    }
    return result;
}

int main() {
    char myString[101]; 
    char myChar;

    printf("Enter a string (up to 100 characters): ");
    scanf("%100s", myString);

    printf("Enter a character to find: ");
    scanf(" %c", &myChar); // ���� �Է� ����, ���� ������ ���� �Է� �� ���� ���� ���� ���ø� ����

    CharFindResult result = findCharInString(myString, myChar);

    if (result.found) {
        printf("The character '%c' is found at index %zu.\n", myChar, result.position);
    } else {
        printf("The character '%c' is not found in the string.\n", myChar);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void findLongestWord(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return;
    }

    char word[MAX_LEN], longestWord[MAX_LEN] = "";
    
    while (fscanf(file, "%s", word) == 1) {  // 단어 단위로 읽기
        if (strlen(word) > strlen(longestWord)) {
            strcpy(longestWord, word); // 더 긴 단어로 갱신
        }
    }

    printf("%s\n", longestWord);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid input!\n");
        return 1;
    }
    
    findLongestWord(argv[1]);
    return 0;
}

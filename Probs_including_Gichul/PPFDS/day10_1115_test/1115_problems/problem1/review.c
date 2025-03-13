#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// // int min(int x, int y, int z){
// //     if(x<y && x<z) return x;
// //     if(y<x && y<z) return y;
// //     else return z;
// // }
// // int editDistance(char word1[], char word2[]) {
// //     int n1 = strlen(word1);
// //     int n2 = strlen(word2);

// //     int dp[n1+1][n2+1];

// //     for(int i=0;i<=n1;i++){
// //         for(int j=0;j<=n2;j++){
// //             if(i==0) dp[i][j] = j;
// //             else if(j==0) dp[i][j] = i;
// //             else if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
// //             else{
// //                 dp[i][j] = 1 + min(dp[i-1][j], // Remove
// //                                     dp[i][j-1], // insert
// //                                     dp[i-1][j-1]); // Replace
// //             }
// //         }
// //     }

// //     return dp[n1][n2];

// // }
// // Recursive function to calculate Edit Distance
// int min(int x, int y, int z) {
//     return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
// }

// // Helper function for recursion with explicit indices
// int editDistanceHelper(char word1[], char word2[], int len1, int len2) {
//     // Base Cases
//     if (len1 == 0) return len2; // If word1 is empty, insert all characters of word2
//     if (len2 == 0) return len1; // If word2 is empty, remove all characters of word1

//     // If last characters are the same, move to the next
//     if (word1[len1 - 1] == word2[len2 - 1]) {
//         return editDistanceHelper(word1, word2, len1 - 1, len2 - 1);
//     }

//     // Case 1: Replace the last character
//     int replace = editDistanceHelper(word1, word2, len1 - 1, len2 - 1);

//     // Case 2: Insert a character into word1
//     int insert = editDistanceHelper(word1, word2, len1, len2 - 1);

//     // Case 3: Remove a character from word1
//     int remove = editDistanceHelper(word1, word2, len1 - 1, len2);

//     // Return the minimum of these three operations + 1 for the current operation
//     return 1 + min(replace, insert, remove);
// }

// // Main recursive function to calculate Edit Distance
// int editDistanceRecursive(char word1[], char word2[]) {
//     int len1 = strlen(word1);
//     int len2 = strlen(word2);
//     return editDistanceHelper(word1, word2, len1, len2);
// }

// // Main function for testing

// 내가 시도

int min(int a, int b, int c){
    if(a<b&&a<c) return a;
    else if(b<a&&b<c) return b;
    else return c;
}

int helper(char w1[],char w2[], int l1, int l2){
    int n1 = strlen(w1);
    int n2 = strlen(w2);
    if(l1==n1) return n2-l2;
    if(l2==n2) return n1-l1;
    if(w1[l1]==w2[l2]) return helper(w1,w2,l1+1,l2+1);

    int remove = helper(w1,w2,l1+1,l2);
    int add = helper(w1,w2,l1,l2+1);
    int replace = helper(w1,w2,l1+1,l2+1);

    return 1+min(remove,add,replace);
}

int editDistanceRecursive(char word1[], char word2[]){
    return helper(word1,word2,0,0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <word1> <word2>\n", argv[0]);
        return 1;
    }

    char *word1 = argv[1];
    char *word2 = argv[2];
    int result = editDistanceRecursive(word1, word2);
    printf("Edit Distance: %d\n", result);

    return 0;
}



// int main(int argc, char *argv[]) {
//     if (argc != 3) {
//         printf("Usage: %s <word1> <word2>\n", argv[0]);
//         return 1;
//     }

//     char *word1 = argv[1];
//     char *word2 = argv[2];
//     int result = editDistance(word1, word2);
//     printf("Edit Distance: %d\n", result);

//     return 0;
// }

// int editDistanceIterative(char word1[], char word2[]) {
//     int len1 = strlen(word1);
//     int len2 = strlen(word2);

//     int i = 0, j = 0, edits = 0;

//     // Loop through both strings
//     while (i < len1 && j < len2) {
//         if (word1[i] == word2[j]) {
//             // Characters match, move both pointers
//             i++;
//             j++;
//         } else {
//             // Case 1: Replace
//             int replace = edits + 1;

//             // Case 2: Insert
//             int insert = edits + 1;

//             // Case 3: Remove
//             int remove = edits + 1;

//             // Perform the operation with the minimum cost
//             if (replace <= insert && replace <= remove) {
//                 i++;
//                 j++;
//             } else if (insert < remove) {
//                 j++;
//             } else {
//                 i++;
//             }

//             edits++; // Increment the edit count
//         }
//     }

//     // Handle remaining characters
//     if (i < len1) {
//         edits += (len1 - i); // Remove remaining characters in word1
//     }
//     if (j < len2) {
//         edits += (len2 - j); // Insert remaining characters from word2
//     }

//     return edits;
// }

// int main(int argc, char *argv[]) {
//     if (argc != 3) {
//         printf("Usage: %s <word1> <word2>\n", argv[0]);
//         return 1;
//     }

//     char *word1 = argv[1];
//     char *word2 = argv[2];
//     int result = editDistanceIterative(word1, word2);
//     printf("Edit Distance: %d\n", result);

//     return 0;
// }
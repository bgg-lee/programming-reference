#include <stdio.h>
#include <stdlib.h>


void outerProduct(int *arr1, int n, int *arr2, int m, int (*result)[m]){
    /*Write your code here*/
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[i][j] = arr1[i]*arr2[j];
        }
    }
    ////////////////////////
}

// Do not modify below
int main(int argc, char* argv[]) {
    if (argc < 3) {  
        printf("Usage: ./prob3 <n> <m> <array_A_elements> <array_B_elements>.\n");
        return 0;
    } else if (argc != 3 + atoi(argv[1]) + atoi(argv[2])) {
        printf("Usage: ./prob3 <n> <m> <array_A_elements> <array_B_elements>.\n");
        return 0;
    }

    // Parse dimensions from command-line arguments
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int input_vector_a[n], input_vector_b[m];

    // Reading matrix A
    for (int i = 0; i < n; i++) {
        input_vector_a[i] = atoi(argv[3 + i]);
    }

    // Reading matrix B
    for (int j = 0; j < m; j++) {
        input_vector_b[j] = atoi(argv[3 + n + j]);
    }

    int result[n][m];
    outerProduct(input_vector_a, n, input_vector_b, m, result);

    // Print the result
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
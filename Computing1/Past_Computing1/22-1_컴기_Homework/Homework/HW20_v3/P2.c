#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *input_filename = argv[1]; // name of input file
    // YOUR CODE HERE

    FILE *infile;
    int size;
    int count; 
    
    infile = fopen(input_filename, "r");

    if (infile == NULL) {return 0;}
    else {
        fseek(infile, 0, SEEK_END); // 파일의 끝으로 이동
        size = ftell(infile); // 파일의 현재 위치 
        fseek(infile, 0, SEEK_SET); // 파일의 맨 앞으로 이동 

        int arr[size];

        while (fscanf(infile, "%d", arr) != EOF){
            printf("%d", arr[0]);
        }
    }
    fclose(infile);

    return 0; 
}
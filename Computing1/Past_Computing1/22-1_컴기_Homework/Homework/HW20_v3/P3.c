#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){    
    char *input_filename = argv[1]; // name of input file
    char *output_filename = argv[2]; // name of output file
    // YOUR CODE HERE  // 와일문 쓰고, string으로 바꿔라
    FILE *infile;
    FILE *outfile;
    int size;

    infile = fopen(input_filename, "r");
    outfile = fopen(output_filename, "w");


    if (infile == NULL) {return 0;}
    else {
        // size = ftell(infile);
        // printf("%d\n", size); // 0
        fseek(infile, 0, SEEK_END); // 포인터를 파일의 끝으로 이동
        size = ftell(infile); // 포인터의 현재 위치 // size = 46
        // int size2 = sizeof(infile); 
        fseek(infile, 0, SEEK_SET); // 포인터를 파일의 맨 앞으로 이동 
        // printf("%d\n", size);  // 46
        // printf("%d\n", size2); //8

        // return 0;
        
        int arr[size];
        
        while (fscanf(infile, "%d", arr) != EOF){
            fprintf(outfile, "%d = ", *arr); // 띄어쓰기는 직접 써줘야 함

            int position = 1;
            int *bin = (int*)malloc(sizeof(int)*(position)); // bin[2]
            int number = *arr;

            while(1){
                // fprintf(outfile, "%d", number % 2);
                bin[position] = number % 2; // 8 -> bin[1]=0 -> bin[2]=0 -> bin[3]=0->bin[4]=1
                // printf("%d", bin[position]);
                number = number/2 ; // 8 -> 4 -> 2 -> 1->0
                position++; // 1 -> 2 -> 3 -> 4->5
                bin = realloc(bin, sizeof(int)*(position)); // int*2->int*3->int*4->int*5->int*6
                if (number == 0) break;
            } // {?,0,0,0,1,?}
            // fprintf(outfile, "\n");
            // printf("\n");



            for (int i = position ; i> 0; i--){
                fprintf(outfile, "%d", bin[i]);
            }
            fprintf(outfile,"\n");
            free(bin);
        }
    }
        fclose(infile);
        fclose(outfile);

    return 0;
}





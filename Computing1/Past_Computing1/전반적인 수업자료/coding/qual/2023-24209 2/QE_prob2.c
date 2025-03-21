#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_size(char s[]){
    int stringsize = 0;
    while (s[stringsize]!='\0'){
        stringsize +=1;
    }
    return stringsize;
}

int is_palindrom(char s[]){
    int stringsize = string_size(s);
    int checknum = stringsize/2;
    for (int i=0; i<checknum; i++){
        if (s[i] != s[stringsize-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    // we take really brute-force method. because considering 1024 cases is clearly enough!

    char string[11];
    scanf("%s", string);
    // printf("the string is %s\n", string);
    // printf("the string is %c\n", string[0]);
    int stringsize = string_size(string);
    
    int candidate[1024][11];

    int candidate_count = 0;
    int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
    for (int i0=0; i0<2; i0++) {c0 = i0;
        for (int i1=0; i1<2; i1++) {c1 = i1;
            for (int i2=0; i2<2; i2++) {c2 = i2;
                for (int i3=0; i3<2; i3++) {c3 = i3;
                    for (int i4=0; i4<2; i4++) {c4 = i4;
                        for (int i5=0; i5<2; i5++) {c5 = i5;
                            for (int i6=0; i6<2; i6++) {c6 = i6;
                                for (int i7=0; i7<2; i7++) {c7 = i7;
                                    for (int i8=0; i8<2; i8++) {c8 = i8;
                                        for (int i9=0; i9<2; i9++) {c9 = i9;
                    candidate[candidate_count][0] = c9;
                    candidate[candidate_count][1] = c8;
                    candidate[candidate_count][2] = c7;
                    candidate[candidate_count][3] = c6;
                    candidate[candidate_count][4] = c5;
                    candidate[candidate_count][5] = c4;
                    candidate[candidate_count][6] = c3;
                    candidate[candidate_count][7] = c2;
                    candidate[candidate_count][8] = c1;
                    candidate[candidate_count][9] = c0;
                    candidate[candidate_count][10] = '\0';
                    candidate_count +=1;}}}}}}}}}}

    int max = 0;
    char tempStr[11];
    char maxStr[11];
    int compare_num = 1;
    for (int i=0; i<stringsize; i++){
        compare_num = compare_num * 2;
    }
    // printf("compare_num: %d\n", compare_num);
    
    // printf("candidate examin\n");
    
    // for (int j=0; j<30; j++){for (int i=0; i<10; i++){
    //     printf("%d ", candidate[j][i]);
    // }
    // printf("\n");
    // }


    for (int i=0; i<compare_num; i++){
        char tempStr[11];

        int in_example_count = 0;
        for (int j=0; j<stringsize; j++){
            if (candidate[i][j] == 1){
                tempStr[in_example_count] = string[j];
                in_example_count +=1;}

        }
        tempStr[in_example_count] = '\0';

        if (is_palindrom(tempStr)==1){
            // printf("palindreom: %s\n", tempStr);
            if (string_size(tempStr) > max){
                max = string_size(tempStr);
                for (int k=0; k<10; k++){
                    maxStr[k] = tempStr[k];
                }
            }
        }

    }

    printf("%d\n", stringsize-max);
    printf("%s", maxStr);

    return 0;
}

// int make_locations(){
//     int candidate[1024][11];

//     int candidate_count = 0;
//     int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
//     for (int i0=0; i0<2; i0++) {c0 = i0;
//         for (int i1=0; i1<2; i1++) {c1 = i1;
//             for (int i2=0; i2<2; i2++) {c2 = i2;
//                 for (int i3=0; i3<2; i3++) {c3 = i3;
//                     for (int i4=0; i4<2; i4++) {c4 = i4;
//                         for (int i5=0; i5<2; i5++) {c5 = i5;
//                             for (int i6=0; i6<2; i6++) {c6 = i6;
//                                 for (int i7=0; i7<2; i7++) {c7 = i7;
//                                     for (int i8=0; i8<2; i8++) {c8 = i8;
//                                         for (int i9=0; i9<2; i9++) {c9 = i9;
//                     candidate[candidate_count][0] = c0;
//                     candidate[candidate_count][1] = c1;
//                     candidate[candidate_count][2] = c2;
//                     candidate[candidate_count][3] = c3;
//                     candidate[candidate_count][4] = c4;
//                     candidate[candidate_count][5] = c5;
//                     candidate[candidate_count][6] = c6;
//                     candidate[candidate_count][7] = c7;
//                     candidate[candidate_count][8] = c8;
//                     candidate[candidate_count][9] = c9;
//                     candidate[candidate_count][10] = '\0';
//                     candidate_count +=1;}}}}}}}}}}
// return candidate;
// }

// typedef struct LinkedNode LinkedNode;
// typedef struct SLList SLList;
// struct LinkedNode{
//     char val;
//     LinkedNode *next;
// };

// struct SLList{
//     LinkedNode* first;
//     int size;
// };

// LinkedNode* createNode(char x){
//     LinkedNode* newNode;
//     newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
//     newNode->val = x;
//     newNode->next = NULL;
//     return newNode;
// }

// void addFirst(SLList *LL, char x){
//     LinkedNode* newNode = createNode(x);
//     newNode->next = LL->first;
//     LL->first = newNode;
//     LL->size +=1;

// }

// void addLast(SLList *LL, char x){
//     LinkedNode* newNode = createNode(x);
//     LinkedNode* curr = LL->first;
    
//     if (LL->size ==0){addFirst(LL, x);}
    
//     else{while (curr->next!=NULL){
//         curr = curr->next;
//     }
//     curr->next = newNode;}
//     LL->size +=1;
// }

// void construct_tree(char s[]){
//     int stringsize = string_size(s);
//     SLList* s;

//     int first = 0;
//     int second = 0;
//     for (int i=0; i<stringsize; i++){

//     }

// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int smallest_pos_int( int *a, int N ){
    int* ans = (int*)malloc((N+1)*sizeof(int));
    int idx = 0;
    for(int i=0;i<N;i++){
        if(a[i]>0) ans[idx++] = a[i];
    }
    for(int j=1;j<=N;j++){
        bool cond = false;
        for(int k=0;k<idx;k++){
            if(ans[k]==j){
                cond = true;
                break;
            }
        }
        if(!cond) return j;
    }

    return N+1;
    
}

int main(){
    // int arr[5] = {1,1,2,3,-1};
    int arr[5] = {4,7,-1,3,1}; // 2
    int *a = arr;
    int N = 5;
    printf("%d\n", smallest_pos_int(a, N));

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>

// int smallest_pos_int( int *a, int N ){
//     int *h = (int*)calloc(N+1, sizeof(int));
//     for(int i = 0; i < N; i++){
//         if(a[i]<N+1 && a[i]>0){
//             h[a[i]-1] = 1;
//         }
//     }
//     int ans = 0;
//     while(h[ans]==1){
//         ans++;
//     }
//     return ans+1;
// }

// int main(){
//     int arr[5] = {4,7,-1,3,1};
//     int *a = arr;
//     int N = 5;
//     printf("%d\n", smallest_pos_int(a, N));

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_area_hist(int* heights, int n){
    // Stack-based approach
    int* stack = (int*)malloc(n*sizeof(int));
    int top = -1;
    int max_area=0;
    
    for(int i=0; i<=n; i++){
        // If i==n => height=0 to flush out
        int h = (i==n) ? 0 : heights[i];
        while(top>=0 && h < heights[stack[top]]){
            int height = heights[stack[top--]];
            int left = (top<0) ? 0 : stack[top]+1;
            int width = i - left;
            int area = height*width;
            if(area>max_area) max_area=area;
        }
        stack[++top] = i;
    }
    free(stack);
    return max_area;
}

int maximalRectangle(char** matrix, int rows, int cols){
    if(rows==0 || cols==0) return 0;
    // We'll maintain an array "heights" for each row
    int* heights = (int*)calloc(cols,sizeof(int));
    int max_rect=0;
    
    for(int r=0; r<rows; r++){
        // update heights
        for(int c=0; c<cols; c++){
            if(matrix[r][c]=='1'){
                heights[c] += 1;
            } else {
                heights[c] = 0;
            }
        }
        // compute largest rect in histogram
        int area = max_area_hist(heights, cols);
        if(area>max_rect) max_rect=area;
    }
    free(heights);
    return max_rect;
}

int main(){
    int R=4, C=5;
    // Example
    // 1 0 1 0 0
    // 1 0 1 1 1
    // 1 1 1 1 1
    // 1 0 0 1 0
    char* data[4] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    // Convert to char** matrix
    char** mat = (char**)malloc(R*sizeof(char*));
    for(int i=0;i<R;i++){
        mat[i] = data[i];
    }
    
    int ans = maximalRectangle(mat, R, C);
    printf("Maximal rectangle area: %d\n", ans);
    
    free(mat);
    return 0;
}

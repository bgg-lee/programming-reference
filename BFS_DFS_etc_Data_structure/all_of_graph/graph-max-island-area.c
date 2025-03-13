#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int R2, C2;
char** Grid;
bool** visited2;
int dr4[4] = {1, -1, 0, 0};
int dc4[4] = {0, 0, 1, -1};

typedef struct {
    int r, c;
} Node;

int dfs_area_stack(int sr, int sc){
    Node* stack = (Node*)malloc(R2*C2*sizeof(Node));
    int top = -1;
    top++;
    stack[top].r = sr;
    stack[top].c = sc;
    visited2[sr][sc] = true;
    int area = 0;
    
    while(top >= 0){
        Node curr = stack[top--];
        area++;
        int rr = curr.r, cc = curr.c;
        for(int i=0; i<4; i++){
            int nr = rr + dr4[i];
            int nc = cc + dc4[i];
            if(nr>=0 && nr<R2 && nc>=0 && nc<C2){
                if(Grid[nr][nc] == '1' && !visited2[nr][nc]){
                    visited2[nr][nc] = true;
                    top++;
                    stack[top].r = nr;
                    stack[top].c = nc;
                }
            }
        }
    }
    free(stack);
    return area;
}

int max_area_of_island(char** M, int rows, int cols){
    R2 = rows;
    C2 = cols;
    Grid = M;
    
    visited2 = (bool**)malloc(R2*sizeof(bool*));
    for(int i=0; i<R2; i++){
        visited2[i] = (bool*)calloc(C2, sizeof(bool));
    }
    
    int max_area = 0;
    
    for(int r=0; r<R2; r++){
        for(int c=0; c<C2; c++){
            if(Grid[r][c] == '1' && !visited2[r][c]){
                int area = dfs_area_stack(r, c);
                if(area > max_area){
                    max_area = area;
                }
            }
        }
    }
    
    // cleanup
    for(int i=0; i<R2; i++){
        free(visited2[i]);
    }
    free(visited2);
    return max_area;
}

int main(void){
    int rows = 5, cols = 5;
    char* sample[5] = {
        "11000",
        "11001",
        "00011",
        "00000",
        "10110"
    };
    
    char** M = (char**)malloc(rows*sizeof(char*));
    for(int i=0; i<rows; i++){
        M[i] = sample[i];
    }
    
    int ans = max_area_of_island(M, rows, cols);
    printf("Max area of island: %d\n", ans);
    
    free(M);
    return 0;
}

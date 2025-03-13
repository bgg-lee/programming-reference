#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rows, cols;
char** M;       // 2D grid of '0'/'1'
bool** visited; // 2D array of booleans

// 4-direction moves
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// Stack element
typedef struct {
    int r, c;
} StackItem;

void dfs_stack(int start_r, int start_c) {
    // We'll implement a simple stack
    StackItem* stack = (StackItem*)malloc(rows * cols * sizeof(StackItem));
    int top = -1;
    
    // push (start_r, start_c)
    top++;
    stack[top].r = start_r;
    stack[top].c = start_c;
    visited[start_r][start_c] = true;
    
    while (top >= 0) {
        StackItem curr = stack[top];
        top--;
        int rr = curr.r;
        int cc = curr.c;
        
        for(int i = 0; i < 4; i++){
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                if(M[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    top++;
                    stack[top].r = nr;
                    stack[top].c = nc;
                }
            }
        }
    }
    free(stack);
}

int count_islands_4dir(char** grid, int R, int C) {
    rows = R;
    cols = C;
    M = grid;
    
    // Allocate visited array
    visited = (bool**)malloc(rows * sizeof(bool*));
    for(int i = 0; i < rows; i++){
        visited[i] = (bool*)calloc(cols, sizeof(bool));
    }
    
    int island_count = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(M[r][c] == '1' && !visited[r][c]){
                dfs_stack(r, c);
                island_count++;
            }
        }
    }
    
    // cleanup
    for(int i = 0; i < rows; i++){
        free(visited[i]);
    }
    free(visited);
    return island_count;
}

int main(){
    // Example usage
    int R = 4, C = 4;
    // Sample data
    // row 0: 1100
    // row 1: 1000
    // row 2: 0010
    // row 3: 0001
    char* input[4] = { "1100", "1000", "0010", "0001" };
    
    // Make grid
    char** grid = (char**)malloc(R * sizeof(char*));
    for(int i = 0; i < R; i++){
        grid[i] = input[i];
    }
    
    int ans = count_islands_4dir(grid, R, C);
    printf("Number of Islands (4-dir) = %d\n", ans); // Expect 3
    
    free(grid);
    return 0;
}

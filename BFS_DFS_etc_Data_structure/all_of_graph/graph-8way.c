#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int R, C;
char** Map;
bool** visited;

int dr8[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc8[8] = {0, 0, -1, 1, -1, 1, -1, 1};

typedef struct {
    int r, c;
} StackItem;

void dfs_8dir_stack(int sr, int sc){
    StackItem* stack = (StackItem*)malloc(R*C*sizeof(StackItem));
    int top = -1;
    
    top++;
    stack[top].r = sr;
    stack[top].c = sc;
    visited[sr][sc] = true;
    
    while(top >= 0){
        StackItem cur = stack[top--];
        int rr = cur.r, cc = cur.c;
        
        for(int i=0; i<8; i++){
            int nr = rr + dr8[i];
            int nc = cc + dc8[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C){
                if(Map[nr][nc] == '1' && !visited[nr][nc]){
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

int count_islands_8dir(char** grid, int rows, int cols){
    R = rows; C = cols;
    Map = grid;
    
    // visited 2D
    visited = (bool**)malloc(R*sizeof(bool*));
    for(int i=0; i<R; i++){
        visited[i] = (bool*)calloc(C, sizeof(bool));
    }
    
    int island_count = 0;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(Map[r][c]=='1' && !visited[r][c]){
                dfs_8dir_stack(r, c);
                island_count++;
            }
        }
    }
    
    // cleanup
    for(int i=0; i<R; i++){
        free(visited[i]);
    }
    free(visited);
    return island_count;
}

int main(void){
    int rows = 4, cols = 4;
    char* sample[4] = {
        "1100",
        "0101",
        "1011",
        "0000"
    };
    
    char** grid = (char**)malloc(rows*sizeof(char*));
    for(int i=0; i<rows; i++){
        grid[i] = sample[i];
    }
    
    int ans = count_islands_8dir(grid, rows, cols);
    printf("Number of Islands (8-dir): %d\n", ans);
    
    free(grid);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int NE_R, NE_C;
int** NE_grid;     // we'll store 0/1 as int
bool** NE_visited;

int ne_dr[4] = {1, -1, 0, 0};
int ne_dc[4] = {0, 0, 1, -1};

typedef struct {
    int r, c;
} NE_Node;

void ne_bfs_mark(int sr, int sc){
    NE_Node* queue = (NE_Node*)malloc(NE_R*NE_C*sizeof(NE_Node));
    int front=0, rear=0;
    queue[rear++] = (NE_Node){sr, sc};
    NE_visited[sr][sc] = true;
    
    while(front<rear){
        NE_Node cur = queue[front++];
        int rr=cur.r, cc=cur.c;
        for(int i=0;i<4;i++){
            int nr=rr+ne_dr[i];
            int nc=cc+ne_dc[i];
            if(nr>=0 && nr<NE_R && nc>=0 && nc<NE_C){
                if(NE_grid[nr][nc]==1 && !NE_visited[nr][nc]){
                    NE_visited[nr][nc] = true;
                    queue[rear++] = (NE_Node){nr,nc};
                }
            }
        }
    }
    free(queue);
}

int num_enclaves(int** grid, int R, int C){
    NE_R = R; 
    NE_C = C; 
    NE_grid = grid;
    
    NE_visited = (bool**)malloc(R*sizeof(bool*));
    for(int i=0;i<R;i++){
        NE_visited[i] = (bool*)calloc(C, sizeof(bool));
    }
    
    // 1) BFS/DFS from all border land
    // top row, bottom row
    for(int c=0;c<C;c++){
        if(grid[0][c]==1 && !NE_visited[0][c]){
            ne_bfs_mark(0, c);
        }
        if(grid[R-1][c]==1 && !NE_visited[R-1][c]){
            ne_bfs_mark(R-1, c);
        }
    }
    // left col, right col
    for(int r=0;r<R;r++){
        if(grid[r][0]==1 && !NE_visited[r][0]){
            ne_bfs_mark(r, 0);
        }
        if(grid[r][C-1]==1 && !NE_visited[r][C-1]){
            ne_bfs_mark(r, C-1);
        }
    }
    
    // 2) count unvisited 1 in interior
    int count=0;
    for(int r=0; r<R; r++){
        for(int c=0;c<C;c++){
            if(grid[r][c]==1 && !NE_visited[r][c]){
                count++;
            }
        }
    }
    
    // cleanup
    for(int i=0;i<R;i++){
        free(NE_visited[i]);
    }
    free(NE_visited);
    return count;
}

int main(void){
    int R=4, C=5;
    // Example
    // 0 0 0 1 1
    // 1 0 1 0 1
    // 1 1 0 0 1
    // 0 1 1 1 0
    // We'll store it as int**:
    int** g = (int**)malloc(R*sizeof(int*));
    for(int i=0;i<R;i++){
        g[i] = (int*)malloc(C*sizeof(int));
    }
    // fill sample
    // row 0: 0 0 0 1 1
    g[0][0]=0; g[0][1]=0; g[0][2]=0; g[0][3]=1; g[0][4]=1;
    g[1][0]=1; g[1][1]=0; g[1][2]=1; g[1][3]=0; g[1][4]=1;
    g[2][0]=1; g[2][1]=1; g[2][2]=0; g[2][3]=0; g[2][4]=1;
    g[3][0]=0; g[3][1]=1; g[3][2]=1; g[3][3]=1; g[3][4]=0;
    
    int ans = num_enclaves(g, R, C);
    printf("Number of enclaves: %d\n", ans);
    
    // cleanup
    for(int i=0;i<R;i++){
        free(g[i]);
    }
    free(g);
    return 0;
}

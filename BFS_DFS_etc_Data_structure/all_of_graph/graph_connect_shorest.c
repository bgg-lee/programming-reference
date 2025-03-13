#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int SB_R, SB_C;
char** SB_grid;
bool** SB_visited;

typedef struct {
    int r, c;
} SB_Node;

int sdr[4] = {1, -1, 0, 0};
int sdc[4] = {0, 0, 1, -1};

void sb_dfs_mark(int sr, int sc, SB_Node* island_cells, int* count){
    // Stack-based DFS
    SB_Node* stack = (SB_Node*)malloc(SB_R*SB_C*sizeof(SB_Node));
    int top=0;
    stack[top].r = sr;
    stack[top].c = sc;
    SB_visited[sr][sc] = true;
    
    while(top >= 0){
        SB_Node cur = stack[top--];
        int rr = cur.r, cc = cur.c;
        // add to island_cells array
        island_cells[*count].r = rr;
        island_cells[*count].c = cc;
        (*count)++;
        
        for(int i=0;i<4;i++){
            int nr = rr + sdr[i];
            int nc = cc + sdc[i];
            if(nr>=0 && nr<SB_R && nc>=0 && nc<SB_C){
                if(SB_grid[nr][nc]=='1' && !SB_visited[nr][nc]){
                    SB_visited[nr][nc] = true;
                    top++;
                    stack[top].r = nr;
                    stack[top].c = nc;
                }
            }
        }
    }
    free(stack);
}

int shortestBridge(char** grid, int R, int C){
    SB_R = R; 
    SB_C = C; 
    SB_grid = grid;
    // visited
    SB_visited = (bool**)malloc(R*sizeof(bool*));
    for(int i=0; i<R;i++){
        SB_visited[i] = (bool*)calloc(C,sizeof(bool));
    }
    
    // 1) Find first island
    SB_Node* first_island = (SB_Node*)malloc(R*C*sizeof(SB_Node));
    int first_count=0;
    
    bool found=false;
    for(int r=0; r<R && !found; r++){
        for(int c2=0; c2<C && !found; c2++){
            if(grid[r][c2]=='1'){
                sb_dfs_mark(r, c2, first_island, &first_count);
                found = true; 
            }
        }
    }
    
    // We'll do BFS from these cells
    // queue
    SB_Node* queue = (SB_Node*)malloc(R*C*sizeof(SB_Node));
    int front=0, rear=0;
    
    // Dist array (or we can store distance in visited if we want)
    int** dist = (int**)malloc(R*sizeof(int*));
    for(int i=0;i<R;i++){
        dist[i] = (int*)calloc(C,sizeof(int));
    }
    
    // Initialize queue with all first_island cells, visited = true
    // They are already visited, but let's push them in queue with dist=0
    for(int i=0;i<first_count;i++){
        queue[rear++] = first_island[i];
        dist[first_island[i].r][first_island[i].c] = 0;
    }
    
    // BFS
    while(front<rear){
        SB_Node cur = queue[front++];
        int rr=cur.r, cc=cur.c;
        for(int i=0;i<4;i++){
            int nr=rr+sdr[i];
            int nc=cc+sdc[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C){
                if(!SB_visited[nr][nc]){
                    // if it's '1', we've reached second island
                    if(grid[nr][nc]=='1'){
                        int d = dist[rr][cc];
                        // free resources
                        for(int k=0;k<R;k++){
                            free(dist[k]);
                            free(SB_visited[k]);
                        }
                        free(dist);
                        free(SB_visited);
                        free(first_island);
                        free(queue);
                        return d; // the BFS distance is the # flips
                    }
                    // else if '0', keep expanding
                    SB_visited[nr][nc] = true;
                    dist[nr][nc] = dist[rr][cc] + 1;
                    queue[rear].r = nr;
                    queue[rear].c = nc;
                    rear++;
                }
            }
        }
    }
    
    // should not happen if exactly two islands
    // cleanup
    for(int k=0;k<R;k++){
        free(dist[k]);
        free(SB_visited[k]);
    }
    free(dist);
    free(SB_visited);
    free(first_island);
    free(queue);
    return -1;
}

int main(void){
    int R=4, C=5;
    // Example
    // 01100
    // 01001
    // 00000
    // 10010
    char* data[4] = {
        "01100",
        "01001",
        "00000",
        "10010"
    };
    char** g = (char**)malloc(R*sizeof(char*));
    for(int i=0;i<R;i++){
        g[i] = data[i];
    }
    
    int ans = shortestBridge(g, R, C);
    printf("Shortest Bridge (flips) = %d\n", ans);
    
    free(g);
    return 0;
}

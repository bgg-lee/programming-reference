#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// We'll store shapes as a string of offsets (r,c).
// This is a simplified approach, not as robust as Python sets,
// but demonstrates the concept.

#define MAX_RC 100

int R, C;
char** G;
bool** visited;

// We can hold up to a certain number of cells in an island
// Then store them in a buffer "shape".
typedef struct {
    int r, c;
} Cell;

int dr4_1[4] = {1,-1,0,0};
int dc4_1[4] = {0,0,1,-1};

// This function returns a "shape string".
char* dfs_shape(int sr, int sc){
    // We'll do a simple stack-based DFS
    Cell* stack = (Cell*)malloc(R*C*sizeof(Cell));
    int top = -1;
    top++;
    stack[top].r = sr;
    stack[top].c = sc;
    visited[sr][sc] = true;
    
    // We'll keep track of all (r,c) relative to (sr,sc)
    Cell* coords = (Cell*)malloc(R*C*sizeof(Cell));
    int count = 0;
    
    while(top >= 0){
        Cell curr = stack[top--];
        coords[count].r = curr.r - sr;
        coords[count].c = curr.c - sc;
        count++;
        
        for(int i=0;i<4;i++){
            int nr = curr.r + dr4_1[i];
            int nc = curr.c + dc4_1[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C){
                if(G[nr][nc]=='1' && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    top++;
                    stack[top].r = nr;
                    stack[top].c = nc;
                }
            }
        }
    }
    
    // sort coords by (r,c)
    // simple bubble or qsort
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if((coords[i].r>coords[j].r) ||
               (coords[i].r==coords[j].r && coords[i].c>coords[j].c)){
                Cell tmp = coords[i];
                coords[i] = coords[j];
                coords[j] = tmp;
            }
        }
    }
    
    // Build a string
    // e.g. "(0,0)(0,1)(1,1)"
    char* shape = (char*)malloc(5*count + 10);
    shape[0] = '\0';
    for(int i=0;i<count;i++){
        char buf[20];
        sprintf(buf,"(%d,%d)",coords[i].r, coords[i].c);
        strcat(shape, buf);
    }
    free(stack);
    free(coords);
    return shape;
}

int num_distinct_islands(char** grid, int rows, int cols){
    R = rows; C = cols; G = grid;
    
    visited = (bool**)malloc(R*sizeof(bool*));
    for(int i=0;i<R;i++){
        visited[i] = (bool*)calloc(C,sizeof(bool));
    }
    
    // We'll store up to 100 shapes in a simple array (not robust).
    char* shapes[100];
    int shapeCount = 0;
    
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(G[r][c]=='1' && !visited[r][c]){
                char* s = dfs_shape(r,c);
                // check if s is distinct
                bool dup = false;
                for(int k=0;k<shapeCount;k++){
                    if(strcmp(s, shapes[k])==0){
                        dup = true;
                        break;
                    }
                }
                if(!dup){
                    shapes[shapeCount++] = s;
                } else {
                    free(s);
                }
            }
        }
    }
    // shapeCount is how many distinct shapes
    // Cleanup
    for(int i=0;i<R;i++){
        free(visited[i]);
    }
    free(visited);
    // Free shapes if needed
    for(int i=0;i<shapeCount;i++){
        free(shapes[i]);
    }
    return shapeCount;
}

int main(void){
    int r = 4, c = 4;
    char* data[4] = {
        "1100",
        "0100",
        "0011",
        "1011"
    };
    char** grid = (char**)malloc(r*sizeof(char*));
    for(int i=0;i<r;i++){
        grid[i] = data[i];
    }
    int ans = num_distinct_islands(grid, r, c);
    printf("Number of distinct islands: %d\n", ans);
    free(grid);
    return 0;
}

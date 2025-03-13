#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int R, C;
int** grid;      // We'll store the grid as int** (0 or 1)
int** comp;      // comp[r][c] = label ID of island
int* size_map;   // size_map[id] = size of that island
int label_id = 2;

// 4 directions
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

// We do DFS or BFS to label an island, returning its area
int label_island(int sr, int sc, int label){
    // simple stack
    int stack_cap = R*C;
    int (*stack)[2] = malloc(stack_cap * sizeof(*stack));
    int top = 0;
    stack[top][0] = sr;
    stack[top][1] = sc;
    comp[sr][sc] = label;
    int area = 0;

    while(top >= 0){
        int rr = stack[top][0];
        int cc = stack[top][1];
        top--;
        area++;
        for(int i=0; i<4; i++){
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C){
                if(grid[nr][nc]==1 && comp[nr][nc]==0){
                    comp[nr][nc] = label;
                    top++;
                    stack[top][0] = nr;
                    stack[top][1] = nc;
                }
            }
        }
    }
    free(stack);
    return area;
}

int largest_island_by_adding_one(int** G, int rows, int cols){
    R = rows; 
    C = cols; 
    grid = G;
    
    // allocate comp[][] to store labels, 0 = unvisited
    comp = (int**)malloc(R*sizeof(int*));
    for(int r=0; r<R; r++){
        comp[r] = (int*)calloc(C, sizeof(int));
    }
    
    // 1) label islands
    // We'll also keep track of total # of cells so we can detect "all 1" scenario
    bool has_zero = false;
    int total_ones = 0;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(grid[r][c]==1){
                total_ones++;
            } else {
                has_zero = true;
            }
        }
    }

    if(!has_zero){
        // entire grid is 1 => area = R*C
        // flipping a 0 is not possible or doesn't help
        // just return R*C
        // (Problem statement says "up to one flip", so we can do nothing)
        return R*C;
    }

    // label connected components
    label_id = 2;
    size_map = (int*)calloc(R*C+2, sizeof(int)); // enough capacity
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(grid[r][c]==1 && comp[r][c]==0){
                int area = label_island(r,c, label_id);
                size_map[label_id] = area;
                label_id++;
            }
        }
    }

    if(label_id==2){
        // means no '1' found => flipping a '0' => area=1
        // (If the entire grid was 0, that is the scenario)
        // So return 1
        // but let's handle it anyway:
        return 1;
    }

    // 2) For each '0', sum distinct neighbor IDs
    int max_area = 0;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(grid[r][c]==0){
                int used[4]; // store up to 4 distinct IDs
                int used_count = 0;
                int sum_area = 1; // flipping the '0' -> +1
                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr>=0 && nr<R && nc>=0 && nc<C){
                        int neighbor_id = comp[nr][nc];
                        if(neighbor_id>1){
                            // check if we already used neighbor_id
                            bool found = false;
                            for(int k=0; k<used_count; k++){
                                if(used[k] == neighbor_id){
                                    found = true;
                                    break;
                                }
                            }
                            if(!found){
                                used[used_count++] = neighbor_id;
                                sum_area += size_map[neighbor_id];
                            }
                        }
                    }
                }
                if(sum_area>max_area){
                    max_area = sum_area;
                }
            }
        }
    }

    // cleanup
    for(int r=0; r<R; r++){
        free(comp[r]);
    }
    free(comp);
    free(size_map);

    return max_area;
}

int main(void){
    int rows=3, cols=4;
    // Example grid
    int** G = (int**)malloc(rows*sizeof(int*));
    for(int i=0; i<rows; i++){
        G[i] = (int*)malloc(cols*sizeof(int));
    }
    // fill a sample
    // [1,0,0,1]
    // [1,1,0,0]
    // [0,0,1,1]
    G[0][0]=1; G[0][1]=0; G[0][2]=0; G[0][3]=1;
    G[1][0]=1; G[1][1]=1; G[1][2]=0; G[1][3]=0;
    G[2][0]=0; G[2][1]=0; G[2][2]=1; G[2][3]=1;

    int ans = largest_island_by_adding_one(G, rows, cols);
    printf("Max island area after flipping one '0': %d\n", ans);

    // cleanup
    for(int i=0; i<rows; i++){
        free(G[i]);
    }
    free(G);
    return 0;
}

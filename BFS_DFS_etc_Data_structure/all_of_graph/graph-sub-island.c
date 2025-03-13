#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rows2, cols2;
char** G1;    // grid1
char** G2;    // grid2
bool** visited2;

int dr2[4] = {1, -1, 0, 0};
int dc2[4] = {0, 0, 1, -1};

typedef struct {
    int r, c;
} Node2;

bool dfs_check_subisland(int sr, int sc) {
    // We'll do a stack-based DFS
    Node2* stack = (Node2*)malloc(rows2 * cols2 * sizeof(Node2));
    int top = 0;
    stack[top].r = sr;
    stack[top].c = sc;
    visited2[sr][sc] = true;
    
    bool is_sub = true; // assume it's a valid sub-island unless we find mismatch
    
    while (top >= 0) {
        Node2 cur = stack[top];
        top--;
        int rr = cur.r;
        int cc = cur.c;
        
        // Check mismatch: G2[rr][cc] == '1', but G1[rr][cc] == '0' => not sub-island
        if (G1[rr][cc] == '0') {
            is_sub = false;
        }
        
        // Explore neighbors
        for(int i=0; i<4; i++){
            int nr = rr + dr2[i];
            int nc = cc + dc2[i];
            if(nr>=0 && nr<rows2 && nc>=0 && nc<cols2){
                if(G2[nr][nc]=='1' && !visited2[nr][nc]){
                    visited2[nr][nc] = true;
                    top++;
                    stack[top].r = nr;
                    stack[top].c = nc;
                }
            }
        }
    }
    free(stack);
    return is_sub;
}

int count_sub_islands(char** grid1, char** grid2, int R, int C){
    rows2 = R;
    cols2 = C;
    G1 = grid1;
    G2 = grid2;
    
    // visited array
    visited2 = (bool**)malloc(R * sizeof(bool*));
    for(int i=0; i<R; i++){
        visited2[i] = (bool*)calloc(C, sizeof(bool));
    }
    
    int count = 0;
    
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(G2[r][c]=='1' && !visited2[r][c]){
                // explore the island in grid2
                bool is_sub = dfs_check_subisland(r, c);
                if(is_sub) count++;
            }
        }
    }
    
    // cleanup
    for(int i=0; i<R; i++){
        free(visited2[i]);
    }
    free(visited2);
    
    return count;
}

// Example usage
int main(void){
    int R=4, C=4;
    // Example grid1
    //   1110
    //   1010
    //   1011
    //   1111
    char* data1[4] = {
        "1110",
        "1010",
        "1011",
        "1111"
    };
    // Example grid2
    //   1110
    //   1010
    //   1011
    //   1111
    // => identical, so presumably all islands in grid2 are sub-islands of grid1.
    // Possibly the result is the # of islands in grid2.
    char* data2[4] = {
        "1110",
        "1010",
        "1011",
        "1111"
    };
    // Convert to char**
    char** g1 = (char**)malloc(R*sizeof(char*));
    char** g2 = (char**)malloc(R*sizeof(char*));
    for(int i=0;i<R;i++){
        g1[i] = data1[i];
        g2[i] = data2[i];
    }
    
    int ans = count_sub_islands(g1, g2, R, C);
    printf("Count of sub-islands: %d\n", ans);
    
    free(g1);
    free(g2);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int LIP_R, LIP_C;
int** LIP_mat;
int** LIP_memo; // store best path length from each cell

int dd[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int lip_dfs(int r, int c){
    if(LIP_memo[r][c] != 0){
        return LIP_memo[r][c];
    }
    int best = 1; // at least this cell
    int curr_val = LIP_mat[r][c];
    for(int i=0;i<4;i++){
        int nr = r + dd[i][0];
        int nc = c + dd[i][1];
        if(nr>=0 && nr<LIP_R && nc>=0 && nc<LIP_C){
            if(LIP_mat[nr][nc] > curr_val){
                int cand = 1 + lip_dfs(nr,nc);
                if(cand>best) best = cand;
            }
        }
    }
    LIP_memo[r][c] = best;
    return best;
}

int longestIncreasingPath(int** matrix, int R, int C){
    if(R==0 || C==0) return 0;
    LIP_R = R;
    LIP_C = C;
    LIP_mat = matrix;
    
    // memo
    LIP_memo = (int**)malloc(R*sizeof(int*));
    for(int i=0;i<R;i++){
        LIP_memo[i] = (int*)calloc(C,sizeof(int));
    }
    
    int ans = 0;
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            int length = lip_dfs(r,c);
            if(length>ans) ans = length;
        }
    }
    
    // cleanup
    for(int i=0;i<R;i++){
        free(LIP_memo[i]);
    }
    free(LIP_memo);
    return ans;
}

int main(void){
    int R=3, C=3;
    // e.g. matrix
    // 9 9 4
    // 6 6 8
    // 2 1 1
    int** mat = (int**)malloc(R*sizeof(int*));
    mat[0] = (int*)malloc(C*sizeof(int));
    mat[1] = (int*)malloc(C*sizeof(int));
    mat[2] = (int*)malloc(C*sizeof(int));
    
    mat[0][0]=9; mat[0][1]=9; mat[0][2]=4;
    mat[1][0]=6; mat[1][1]=6; mat[1][2]=8;
    mat[2][0]=2; mat[2][1]=1; mat[2][2]=1;
    
    int ans = longestIncreasingPath(mat, R, C);
    printf("Longest Increasing Path: %d\n", ans);
    
    // cleanup
    for(int i=0;i<R;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}

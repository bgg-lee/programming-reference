// We have an RxC matrix of heights. Water flows from cell to neighbors of 
// equal or lower height. The 'Pacific' is top/left border, 'Atlantic' is bottom/right border.
// We want the list of coordinates (r,c) from which water can reach both the Pacific and Atlantic.
// (Here we just demonstrate printing them.)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int PA_R, PA_C;
int** heights;
bool** pac; 
bool** atl;

int pdr[4] = {1,-1,0,0};
int pdc[4] = {0,0,1,-1};

typedef struct {
    int r, c;
} QNode;

void pa_bfs_from_edge(int sr, int sc, bool** ocean_vis){
    QNode* queue = (QNode*)malloc(PA_R*PA_C*sizeof(QNode));
    int front=0, rear=0;
    ocean_vis[sr][sc] = true;
    queue[rear++] = (QNode){sr,sc};
    
    int base_h = heights[sr][sc];
    while(front<rear){
        QNode cur = queue[front++];
        int rr=cur.r, cc=cur.c;
        for(int i=0;i<4;i++){
            int nr=rr+pdr[i];
            int nc=cc+pdc[i];
            if(nr>=0 && nr<PA_R && nc>=0 && nc<PA_C){
                if(!ocean_vis[nr][nc]){
                    // flow condition: heights[nr][nc] >= heights[rr][cc]
                    if(heights[nr][nc]>=heights[rr][cc]){
                        ocean_vis[nr][nc] = true;
                        queue[rear++] = (QNode){nr,nc};
                    }
                }
            }
        }
    }
    free(queue);
}

int main(void){
    PA_R=5; 
    PA_C=5;
    
    // Example matrix
    //  1  2  2  3  5
    //  3  2  3  4  4
    //  2  4  5  3  1
    //  6  7  1  4  5
    //  5  1  1  2  4
    
    // We'll store in int** "heights"
    heights = (int**)malloc(PA_R*sizeof(int*));
    for(int i=0;i<PA_R;i++){
        heights[i] = (int*)malloc(PA_C*sizeof(int));
    }
    // fill sample
    int data[5][5] = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    for(int r=0;r<PA_R;r++){
        for(int c=0;c<PA_C;c++){
            heights[r][c] = data[r][c];
        }
    }
    
    // Create pac and atl
    pac = (bool**)malloc(PA_R*sizeof(bool*));
    atl = (bool**)malloc(PA_R*sizeof(bool*));
    for(int i=0;i<PA_R;i++){
        pac[i] = (bool*)calloc(PA_C,sizeof(bool));
        atl[i] = (bool*)calloc(PA_C,sizeof(bool));
    }
    
    // BFS from pacific edges
    // top row, left col
    for(int c=0;c<PA_C;c++){
        pa_bfs_from_edge(0, c, pac);
    }
    for(int r=0;r<PA_R;r++){
        pa_bfs_from_edge(r, 0, pac);
    }
    
    // BFS from atlantic edges
    // bottom row, right col
    for(int c=0;c<PA_C;c++){
        pa_bfs_from_edge(PA_R-1, c, atl);
    }
    for(int r=0;r<PA_R;r++){
        pa_bfs_from_edge(r, PA_C-1, atl);
    }
    
    // Intersection
    printf("Coordinates from which water flows to both oceans:\n");
    for(int r=0;r<PA_R;r++){
        for(int c=0;c<PA_C;c++){
            if(pac[r][c] && atl[r][c]){
                printf("(%d, %d) ", r, c);
            }
        }
    }
    printf("\n");
    
    // cleanup
    for(int i=0;i<PA_R;i++){
        free(heights[i]);
        free(pac[i]);
        free(atl[i]);
    }
    free(heights);
    free(pac);
    free(atl);
    
    return 0;
}

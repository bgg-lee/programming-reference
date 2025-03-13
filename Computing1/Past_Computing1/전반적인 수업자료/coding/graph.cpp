#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
python      c++             characteristics
list        vector          a dynamic ordered list
set         unordered_set   a dynamic set of unordered unique values
dictionary  unordered_map   a dynamic set of (key_value) pairs
deque       list            a doubly linked list
*/

class undi_graph{
    public:
    
    int myVNum;
    vector<vector<int>> myEdges;
    vector<vector<int>> neighbors;
    
    undi_graph(const int VNum, vector<vector<int>> &Edges);
    void bfs();
    void dfs(int mode);
    void dfs_help(int mode, int v, vector<bool> &visited);
    void visitAction(int v);
};

undi_graph::undi_graph(const int VNum, vector<vector<int>> &Edges):neighbors(VNum, vector<int>(0)){ // neighbor 정의 평소에 생각 못할듯.!!!!!

    myVNum = VNum;
    vector<vector<int>> newEdge;
    for (auto edge:Edges){
        newEdge.push_back({edge[0], edge[1]});
        newEdge.push_back({edge[1], edge[0]});
    }
    myEdges = newEdge;

    // for (auto edge:myEdges){
    //     cout << "edge:"<< edge[0] << ", " << edge[1] << endl;
    //     neighbors[edge[0]].push_back(edge[1]);
    // }
    myEdges = newEdge;

}

void undi_graph::bfs(){
    list<int> queue;
    vector<bool> visited(myVNum, false);
    for (int i=0; i<myVNum; i++){
        queue.push_back(i);
        int currV;

        while (!queue.empty()){
            currV = queue.front();
            queue.pop_front();
            if (!visited[currV]){
                visited[currV] = true;
                visitAction(currV);
                for (const int& n:neighbors[currV]){
                    queue.push_back(n);
                }
            }
        }
    }

}
void undi_graph::dfs(int mode){
    vector<bool> visited(myVNum, false);
    for (int i=0; i<myVNum; i++){
        dfs_help(mode, i, visited);
    }
}

void undi_graph::dfs_help(int mode, int v, vector<bool> &visited){
    if (!visited[v]){
        visited[v] = true;

        if (mode==0){
            visitAction(v);
            for (int w:neighbors[v]){
                dfs_help(mode, w, visited);
            }
        }
        else if (mode==1){
            for (int w:neighbors[v]){
                dfs_help(mode, w, visited);
            }
            visitAction(v);
        }
        else{
            cout << "invalid mode" << endl;
        }

    }
}

void undi_graph::visitAction(int v){
    cout << v << ", ";
}

int main(){
    int myVNum = 10;
    vector<vector<int>> myEdges{
        {0, 1},  {1, 4}, {1, 5}, {2, 3}, {4, 6}, {5, 6}, {5, 7}, {6, 9}, {7, 8}
    };
    undi_graph myGraph(myVNum, myEdges);

    // for (auto edge: myGraph.myEdges){
    //     cout << "{" << edge[0] << ", " << edge[1] << "}" << endl;
    // }

    cout <<"[BFS]";
    myGraph.bfs();
    cout << endl;

    cout <<"[DFS_preorder]";
    myGraph.dfs(0);
    cout << endl;

    cout <<"[DFS_postorder]";
    myGraph.dfs(1);
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
#define NODE 5 // number of node in graph
using namespace std;

void check(vector<vector<int>> &graph, int u, bool visited[], int rv){
    visited[u] = true;
    for(int v = 0; v<NODE; v++){
        if(graph[u][v] && v!=rv){
            if(!visited[v])
                check(graph, v, visited, rv);
        }
    }
}
bool isConnected(vector<vector<int>> &graph, int v)
{
    bool *visited = new bool[NODE];
    for(int u=0; u<NODE; u++)
    {
        if(u!=v){
            for(int i = 0; i<NODE; i++){
                visited[i] = false;
            }
            check(graph, u, visited, v);
            for(int i=0; i<NODE; i++){
                if(!visited[i] && i!=v){
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> graph(NODE, vector<int>(NODE));
            graph = {{0, 1, 1, 0, 0},
                    {1, 0, 1, 0, 0},
                    {1, 1, 0, 1, 1},
                    {0, 0, 1, 0, 1},
                    {0, 0, 1, 1, 0}};


    // we remove each vertex one by one and check connectivity of graph
    // if graph is disconnected for any vertex we increment count
    int count = 0;
    vector<int> rowArray(NODE);
    vector<int> colArray(NODE);
    for(int i=0; i<NODE; i++){
        for(int col=0; col<NODE; col++){
            rowArray[col] = graph[i][col];
            graph[i][col] = 0;
        }
        // disconnecting the Ith vertex from graph
        for(int row=0; row<NODE; row++){
            colArray[row] = graph[row][i];
            graph[row][i] = 0;
        }
        // check after moving the Ith vertex whether graph is connected or not
        if(!isConnected(graph, i)){
            count++;
        }
        for(int row=0; row<NODE; row++){
            graph[row][i] = colArray[row];
        }
        for(int col =0; col<NODE; col++){
            graph[i][col] = rowArray[col];
        }
    }
    cout<<count;
    return 0;
}

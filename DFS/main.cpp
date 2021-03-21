#include <bits/stdc++.h>

using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void DfsUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DfsUtil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            DfsUtil(*it, visited);
        }
    }
}
void Graph::DFS()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<V; i++)
    {
        if(visited[i]==false)
        {
            DfsUtil(i, visited);
        }
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.DFS();
    return 0;
}

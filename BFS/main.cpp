#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency list
public:
    Graph(int v);
    void addEdge(int v, int w); // function to add edge to graph
    void BFS(int s); // function to finding BFS to given source
};
Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    list<int>::iterator i;
    visited[s] = true;
    q.push(s);
    while(q.empty()==false)
    {
        s = q.front();
        q.pop();
        cout<<s<<" ";
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i]= true;
                q.push(*i);
            }
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
    cout<<"BFS starting from 2 \n";
    g.BFS(2);
    return 0;
}

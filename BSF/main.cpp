#include <bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *adj;
public:
    graph(int n)
    {
        v  = n;
        adj = new list<int>[v];
    }
    void addedge(int u,int v);
    void BFS(int s);
};

void graph::addedge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void graph::BFS(int s)
{
    queue<int> q;
    bool visited[v];
    memset(visited,false,sizeof(visited));
    //visited[s] = true;
    q.push(s);
    cout << "test";
    while(!q.empty())
    {
        cout << "test2";
        int  temp = q.front();
        cout << temp << " ";
        visited[temp] = true;
        list<int>::iterator it;
        for(it= adj[temp].begin(); it!=adj[temp].end(); it++)
            {
                if(!visited[*it])
                q.push(*it);
            }
            q.pop();
    }
}


int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(2,5);
    g.addedge(2,6);
    g.BFS(0);
    return 0;
}

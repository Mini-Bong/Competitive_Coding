#include<bits/stdc++.h> // it will include all header files
using namespace std;
# define INFINITE INT_MAX // Try to make infinite distance of all vertice

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a graph using adjacency list representation
class Graph
{
	int V; // V represent the number of vertice

	list< pair<int, int> > *adj; // For storing weight of every pair of weight graph

public:
	Graph(int V); // Graph constructor

	void addEdge(int u, int v, int w); // This function will add the edges in graph

	void shortestPath(int s); // This function will print the shortest path from the source s
};

// It will allocate the memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from source to all other vertice
void Graph::shortestPath(int source)
{
	// Create a priority queue to store vertice that are being preprocessed.
	priority_queue< iPair, vector <iPair> , greater<iPair> > Pqueue;

	// Create a vector for distances and initialize all
	// distances as infinite (INFINITE)
	vector<int> distance(V, INFINITE);

	// Insert source in priority queue and initialize its distance as 0
	Pqueue.push(make_pair(0, source));
	distance[source] = 0;

	// Loop through until priority queue become empty
	while (!Pqueue.empty())
	{
		// The first vertex in pair is the minimum distance vertex extract from Pqueue
		int u = Pqueue.top().second;
        Pqueue.pop();

		// 'i' is used to get all adjacent vertice of a vertex
		list< pair<int, int> >::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); ++it)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*it).first;
			int weight = (*it).second;

			// If there is shorted path to v through u.
			if (distance[v] > distance[u] + weight)
			{
				// Updating distance of v
				distance[v] = distance[u] + weight;
				pq.push(make_pair(distance[v], v));
			}
		}
	}

	// Print shortest distances stored in distacne[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i){
		cout<<"Shortest Path from A to "<<(char)(i+65)<<"\t\t"<<distance[i]<<"\n";
	}
}

int main()
{
	// create the graph for given figure in question
	int V = 11; // Number of the vertices in the graph
	Graph g(V);

	// making above shown graph
	// I am making vertex A as 0th vertex, B as 1st vertex and so on.
	g.addEdge(0, 1, 3); // A-B 3
	g.addEdge(0, 2, 4); // A-C 4
	g.addEdge(0, 5, 8); // A-F 8 like that all edges
	g.addEdge(1, 3, 6);
	g.addEdge(1, 9, 8);
	g.addEdge(2, 5, 3);
	g.addEdge(3, 4, 3);
	g.addEdge(3, 6, 5);
	g.addEdge(3, 7, 6);
	g.addEdge(4, 6, 4);
	g.addEdge(5, 7, 8);
	g.addEdge(5, 10, 7);
	g.addEdge(6, 9, 8);
	g.addEdge(6, 8, 2);
	g.addEdge(7, 8, 7);
	g.addEdge(8, 9, 6);
	g.addEdge(9, 10, 8);

	g.shortestPath(0); // Calling the function with source as 0, ie, A

	return 0;
}

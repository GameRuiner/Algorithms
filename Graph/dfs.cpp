#include "graph.h"

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFSUtil(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    int v = 2;
    cout << "Following is Depth First Traversal"
            " (starting from vertex" << v << ") \n";
    g.DFS(v);
    cout << "\n";

    return 0;

}

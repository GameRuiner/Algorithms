#include <iostream>
#include <list>
#include "graph.h"

// Time Complexity O(V + E)

void Graph::BFS(int v) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    list<int>::iterator i;

    while (!queue.empty())
    {
        v = queue.front();
        cout << v << " ";
        queue.pop_front();

        for (i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<< v <<" ) \n";
    g.BFS(v);
    cout << "\n";
 
    return 0;
}

//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

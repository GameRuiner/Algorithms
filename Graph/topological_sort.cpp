// Topological sort of a directed graph is a linear ordering of its vertices 
// such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering
// O (|V| + |E|)

#include <bits/stdc++.h>
#include "graph.h"

using namespace std;

// Kahn's algorithm

void Graph::topologicalSort() {
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            in_degree[*itr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    vector<int> top_order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            if(--in_degree[*itr] == 0) {
                q.push(*itr);
            }
        }
        cnt++;
    }

    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++) {
        cout << top_order[i] << " ";
    }
    cout << endl;
}

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort();

    return 0;
}


// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
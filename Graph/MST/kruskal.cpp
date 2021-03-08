//  C++ program for Kruskal's algorithm
//  to find Minimum Spanning Tree of a
//  given connected, undirected and weighted graph
//  Time Complexity: O(ElogE) or O(ElogV)
#include <bits/stdc++.h>
#include "../weighted_graph.h"
#include "subset.h"
using namespace std;

int myComp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void kruskalMST(Graph* graph) {
    int V = graph->V;
    //Edge result[V];
    Edge* result = new Edge[V];
    int e = 0; // index for result[] 
    int i = 0; // index for sorted edges

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle,
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the constructed "
            "MST\n""";
    int minimumCost = 0;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }

    cout << "Minimum Cost Spanning Tree: " << minimumCost
        << endl;
}

int main() {
    int V = 4;
    int E = 5;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);
    
    return 0;
}

//https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/


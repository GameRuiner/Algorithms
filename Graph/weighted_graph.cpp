#include <bits/stdc++.h>
#include "weighted_graph.h"
using namespace std;

struct Graph* createGraph(int V, int E) {
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
};
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
	int V, E;

	struct Edge* edge;
};

struct Graph* createGraph(int V, int E);
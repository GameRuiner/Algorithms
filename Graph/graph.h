#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    public:
        Graph(int V);
        void addEdge(int u, int v);
        void topologicalSort();
        void DFSUtil(int v, bool visited[]);
        void DFS(int v);
        void BFS(int v);      
};
//
// Created by Vinay Saini on 2019-06-21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <queue>

using namespace std;

#define INF (1<<29)
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

class Graph {
public:
    int E, V;
    vector<vector<int>> adj;
    Graph(){};
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        adj.resize(V, vector<int>());
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void addDirectionalEdge(int u, int v) {
        adj[u].push_back(v);
    }
};


int main() {
    int E, V, u, v;
    cin >> V >> E;
    Graph g(E, V);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    return 0;
}
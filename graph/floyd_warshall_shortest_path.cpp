//
// Created by Vinay Saini on 2019-07-01.
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
    int V;
    vector<vector<int>> adj;
    Graph(){};
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>());
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void addDirectionalEdge(int u, int v) {
        adj[u].push_back(v);
    }
    vector<vector<int>> dist;
    bool calculate() {

        for (int i = 0; i < V; ++i) {
            vector<int> temp(V, INF);
            dist.push_back(temp);
        }

        memset(dist, INF , V*sizeof(dist));
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                for (int k = 0; k < V; ++k) {
                    dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                }

            }
        }
    }

    int findShortestDist(int u, int v) {
        return dist[u][v];
    }
};


int main() {
    int V, E, u, v;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Enter input : \n";
    cin >> u >> v;
    cout << dist[u][v] << "\n";
    return 0;
}
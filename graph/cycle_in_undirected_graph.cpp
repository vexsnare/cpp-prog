//
// Created by Vinay Saini on 2019-06-25.
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

    int dfs(int cur, int p, vector<bool> &visited, vector<int> &parent) {
        parent[cur] = p;
        visited[cur] = true;
        int ret = -1;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int nb = adj[cur][i];
            if(nb == p) continue;
            if(visited[nb]) {
                parent[nb] = cur;
                return nb;
            }
            ret = dfs(nb, cur, visited, parent);
            if(ret != -1) break;
        }
        return ret;
    }

    vector<int> findAnyCycle() {
        vector<int> ans;
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                // tail vertex that will hit already visited node
                int vertex = dfs(i, -1, visited, parent);
                // vertex should not be -1 if cycle is found
                if(vertex != -1) {
                    int seen = vertex;
                    do {
                        ans.push_back(vertex);
                        vertex = parent[vertex];
                    }
                    while (vertex != seen);
                    ans.push_back(seen);
                    break;
                }
            }
        }
        return ans;

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
    vector<int> result = g.findAnyCycle();
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
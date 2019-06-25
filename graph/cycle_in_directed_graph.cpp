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

    // Implementation
    int dfs(int cur, int p, vector<int> &black, vector<int> &gray, vector<int> &parent) {
        parent[cur] = p;
        gray[cur] = true;
        int ret = -1;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int nb = adj[cur][i];
            if(black[nb]) continue;
            if(gray[nb]) {
                parent[nb] = cur;
                return nb;
            }
            ret = dfs(nb, cur, black, gray, parent);
            if(ret != -1) break;
        }
        black[cur] = true;
        return ret;
    }

    vector<int> findAnyCycleInDag() {
        // visited
        vector<int> black(V, false);
        //being visited
        vector<int> gray(V, false);
        vector<int> parent(V,-1);
        vector<int> ans;

        for (int i = 0; i < V; ++i) {
            if(!black[i]) {
                int vertex = dfs(i, -1, black, gray, parent);
                if(vertex != -1) {
                    int seen = vertex;
                    do {
                        ans.push_back(vertex);
                        vertex = parent[vertex];
                    } while (vertex != seen);
                    ans.push_back(seen);
                    break;
                }
            }
        }
        return ans;
    }
};


int main() {
    Graph g(4, 6);
    g.addDirectionalEdge(0, 1);
    g.addDirectionalEdge(0, 2);
    g.addDirectionalEdge(2, 0);
    g.addDirectionalEdge(2, 0);
    g.addDirectionalEdge(2, 3);
    g.addDirectionalEdge(3, 3);
    g.addDirectionalEdge(1, 2);

    vector<int> vertexInCycle = g.findAnyCycleInDag();
    for (int i = 0; i < vertexInCycle.size(); ++i) {
        cout << vertexInCycle[i] << " ";
    }
    cout << endl;
    return 0;
}
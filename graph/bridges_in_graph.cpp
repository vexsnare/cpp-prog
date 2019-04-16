#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"

class Graph {
    int E;
    int V;
    vector<vector<int>> edges;
public:

    Graph(int E, int V) {
        this->E = E;
        this->V = V;
        edges.resize(V, vector<int>());
    }
    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // --- dfs
    void go(bool visited[], int x) {
        cout << x << " ";
        visited[x] = true;
        for (int i = 0; i < edges[x].size(); ++i) {
            int adj = edges[x][i];
            if(!visited[adj]) {
                go(visited, adj);
            }
        }
    }
    void dfs(int start) {
        bool visited[E];
        fill(visited, visited + V, false);
        go(visited, start);
        cout << "\n";
    }

    // -- Finding bridges
    void solve(int tin[], int tlow[], int cur, int parent, int time, vector<pair<int, int>> &ans, bool visited[]) {
        tlow[cur] = tin[cur] = time;
        visited[cur] = true;
        for (int i = 0; i < edges[cur].size(); ++i) {
            int nb = edges[cur][i];
            if(parent == nb) continue;
            if(!visited[nb]) {
                solve(tin, tlow, nb, cur, time+1, ans, visited);
            }
            tlow[cur] = min(tlow[cur], tlow[nb]);
            if(tlow[nb] > tin[cur]) {
                ans.push_back({cur, nb});
            }
        }
    }
    vector<pair<int, int>> findBridges() {
        int tin[V];
        int tlow[V];
        bool visited[V];
        fill(visited, visited+V, false);
        vector<pair<int, int>> ans;
        int time = 1;
        solve(tin, tlow, 0, -1, time, ans, visited);
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
    g.dfs(0);
    vector<pair<int, int>> bridges = g.findBridges();
    for (int j = 0; j < bridges.size(); ++j) {
        cout << bridges[j].first << " " << bridges[j].second << "\n";
    }
    return 0;
}
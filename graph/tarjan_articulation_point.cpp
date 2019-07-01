//
// Created by Vinay Saini on 2019-06-18.
//
// https://www.spoj.com/problems/SUBMERGE/

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

vector<int> inT;
vector<int> minT;
vector<bool> visited;

void dfs(int cur, int parent, int time, vector<int> &ans, Graph &g) {
    visited[cur] = true;
    inT[cur] = time;
    minT[cur] = time;
    time++;
    int visitedChilds = 0;
    bool isArticulationPoint = false;
    int mn = 1<<29;
    for (int i = 0; i < g.adj[cur].size(); ++i) {
        int nb = g.adj[cur][i];
        if(nb == parent) continue;
        if(!visited[nb]) {
            visitedChilds++;
            dfs(nb, cur, time, ans, g);
            if (inT[cur] <= minT[nb]) {
                isArticulationPoint = true;
            }
            minT[cur] = min(minT[cur], minT[nb]);
        } else {
            minT[cur] = min(minT[cur], inT[nb]);
        }
    }
    if((isArticulationPoint && parent != -1) || (parent == -1 && visitedChilds > 1)) ans.push_back(cur);
}

vector<int> findArticulationPoints(Graph &g) {
    inT.resize(g.V);
    minT.resize(g.V);
    visited.resize(g.V);
    fill(visited.begin(), visited.end(), false);
    vector<int> articulationPoints;
    dfs(0, -1, 0, articulationPoints, g);
    return articulationPoints;
}

int main() {
    int V, E, u, v;
    cin >> V >> E;
    if(V == 0 || E == 0) break;
    Graph g(V, E);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);
    }
    vector<int> points = findArticulationPoints(g);
    cout << points.size() << "\n";
    for (int j = 0; j < points.size(); ++j) {
        cout << points[j] << " ";
    }
}
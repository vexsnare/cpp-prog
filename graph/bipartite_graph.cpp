//
// Created by Vinay Saini on 2019-07-05.
//
/**
 * Basically two coloring Graph Problem
 * https://www.geeksforgeeks.org/bipartite-graph/
 */
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

    vector<vector<int>> findBipartite() {

        vector<vector<int>> ans;

        vector<int>color(V, -1);
        vector<int> setA;
        vector<int> setB;
        queue<int> q;
        q.push(0);
        color[0] = 1;
        bool isPossible = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int next_color = 1 - color[cur];
            for (int i = 0; i < adj[cur].size(); ++i) {
                int nb = adj[cur][i];
                if(color[nb] == next_color) continue;
                if(color[nb] == -1 ) {
                    color[nb] = next_color;
                    q.push(nb);
                } else {
                    isPossible = false;
                    break;
                }
            }
        }
        if(isPossible) {
            for (int i = 0; i < V; ++i) {
                if(color[i] == 1) setA.push_back(i);
                else setB.push_back(i);
            }
            ans.push_back(setA);
            ans.push_back(setB);
        }
        return ans;
    }
};


int main() {
    int E, V, u, v;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    vector<vector<int>> ans = g.findBipartite();
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
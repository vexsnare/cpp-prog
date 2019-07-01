//
// Created by Vinay Saini on 2019-06-26.
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

    //
    vector<vector<int>> ans;
    void dfs(int cur, int p, int time, vector<bool > &visited, vector<int> &inT,  vector<int> &minT, stack<int> &stk, vector<bool> &onStack) {
        stk.push(cur);
        onStack[cur] = true;
        visited[cur] = true;
        inT[cur] = time;
        minT[cur] = time;
        time++;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int nb = adj[cur][i];
            if(onStack[nb]) {
                minT[cur] = min(minT[cur], inT[nb]);
            } else if (!visited[nb]) {
                dfs(nb, cur, time, visited, inT, minT, stk, onStack);
                minT[cur] = min(minT[cur], minT[nb]);
            }
        }
        if(inT[cur] == minT[cur]) {
            vector<int> v;
            int top;
            do {
                top = stk.top();
                stk.pop();
                onStack[top] = false;
                v.push_back(top);
            } while (top != cur);
            ans.push_back(v);
        }
    }
    vector<vector<int>> findSccTarjan() {
        vector<bool> visited(V, false);
        vector<bool> onStack(V, false);
        vector<int> inT(V);
        vector<int> minT(V);
        vector<int> parent(V, -1);
        stack<int> stk;
        int ans_index = 0;
        for (int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, -1, 0, visited, inT, minT, stk, onStack);
            }
        }
        return ans;
    }
};

int main() {
    int E, V, u, v;
    cin >> V >> E;
    Graph g(V, E);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addDirectionalEdge(u -1, v-1);
    }
    vector<vector<int>> scc = g.findSccTarjan();
    for (int i = scc.size() - 1; i >= 0; --i) {
        if(scc[i].size() > 1) {
            cout << scc[i].size() << "\n";
            sort(scc[i].begin(), scc[i].end());
            for (int j = 0; j < scc[i].size(); ++j) {
                cout << scc[i][j] + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
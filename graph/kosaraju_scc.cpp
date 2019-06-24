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

/**
 *  Kosaraju Algorithm
 *  https://www.youtube.com/watch?v=RpgcYiky7uw&t=1004s
 */
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

    //-------
    void dfs1(int cur, stack<int> &stk, vector<bool> &visited) {
        visited[cur] = true;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int nb = adj[cur][i];
            if(!visited[nb]) {
                dfs1(nb, stk, visited);
            }
        }
        stk.push(cur);
    }
    stack<int> getVertexByFinishTime() {
        vector<bool> visited(V, false);
        stack<int> ans;
        for (int i = 0; i < V; ++i) {
            if(!visited[i]) dfs1(i, ans, visited);
        }
        return ans;
    }
    //----------

    void dfs2(int cur, vector<int> &ans, vector<bool> &visited) {
        if(visited[cur]) return;
        ans.push_back(cur);
        visited[cur] = true;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int nb = adj[cur][i];
            if(!visited[nb]) {
                dfs2(nb, ans, visited);
            }
        }
    }
    vector<vector<int>> getStronglyConnectedComponents(stack<int> &stk) {
        vector<vector<int>> ans;
        vector<bool> visited(V, false);
        while (!stk.empty()) {
            int ele = stk.top();
            if(visited[ele]) {
                stk.pop();
                continue;
            }
            vector<int> components;
            dfs2(ele, components, visited);
            ans.push_back(components);
        }
        return ans;
    }

};



int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    Graph gReverse(n, m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addDirectionalEdge(u -1 , v - 1);
        gReverse.addDirectionalEdge(v - 1, u - 1);
    }
    stack<int> vertexByFinishTime = g.getVertexByFinishTime();
    vector<vector<int>> components = gReverse.getStronglyConnectedComponents(vertexByFinishTime);
    cout << components.size() << endl;
    for (int i = 0; i < components.size(); ++i) {
        vector<int> &component = components[i];
        sort(component.begin(), component.end());
        for (int j = 0; j < component.size() && components.size() > 1; ++j) {
            cout << component[j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
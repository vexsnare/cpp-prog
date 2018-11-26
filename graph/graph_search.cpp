//
// Created by Vinay Saini on 18/01/18.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<int> adj[], bool visited[], int v) {
    cout << v+1 << " -> ";
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); i++) {
        if(!visited[adj[v][i]]) {
            dfs(adj, visited, adj[v][i]);
        }
    }
}

void bfs(vector<int> adj[], bool visited[], int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int cur = q.front();
        cout << cur+1 << " -> ";
        q.pop();
        for(int i = 0; i < adj[cur].size(); i++) {
            int child = adj[cur][i];
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main() {
    int n, m;
    int u, v;
    scanf("%d %d", &n, &m);
    vector<int> ar[n];
    bool visited[n];
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        ar[u-1].push_back(v-1);
        ar[v-1].push_back(u-1);
    }
    cout << "DFS \n";
    memset(visited, false, sizeof visited);
    dfs(ar, visited, 0);
    cout << "\nBFS \n";
    memset(visited, false, sizeof visited);
    bfs(ar, visited, 0);
}




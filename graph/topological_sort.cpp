//
// Created by Vinay Saini on 19/01/18.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topoSort(vector<int> adj[], stack<int> &stack, bool visited[], int v) {
    int i;
    for(i = 0; i < adj[v].size(); i++) {
        if(!visited[adj[v][i]])
            topoSort(adj, stack, visited, adj[v][i] );
    }
    stack.push(v);
    visited[v] = true;
}

int main() {
    int n, m;
    int u, v;
    scanf("%d %d", &n, &m);
    vector<int> adj[n];
    stack<int> stack;
    bool visited[n];
    memset(visited, false, sizeof visited);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            topoSort(adj, stack, visited, i);
        }
    }

    while(!stack.empty()) {
        cout << stack.top() << "->";
        stack.pop();
    }
    return 0;
}
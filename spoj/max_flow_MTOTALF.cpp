//
// Created by Vinay Saini on 2019-05-20.
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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int findMinFlowAndUpdateCapacity(int parent[], int V, int source, int sink, vector<vector<int>> &edges) {
    int minFlow = INF;
    int cur = sink;
    while (cur != source) {
        minFlow = min(minFlow, edges[parent[cur]][cur]);
        cur = parent[cur];
    }
    // update
    cur = sink;
    while (cur != source) {
        int t = edges[parent[cur]][cur];
        edges[parent[cur]][cur] -= minFlow;
        t = edges[parent[cur]][cur];
        edges[cur][parent[cur]] += minFlow;
        cur = parent[cur];
    }
    return minFlow;
}

int findMaxFlow(vector<vector<int>> &edges, int V, int E, int source, int sink) {
    int maxFlow = 0;
    while (true) {
        bool visited[V];
        memset(visited, false, sizeof(visited));

        int parent[V];
        memset(parent, -1, sizeof(parent));

        queue<pair<int, int>> q;
        q.push({source, -1});
        bool reached = false;

        while (!q.empty()) {
            int cur = q.front().first;
            int from = q.front().second;
            parent[cur] = from;
            if(cur == sink) {
                int minFlow = findMinFlowAndUpdateCapacity(parent, V, source, sink, edges);
                maxFlow += minFlow;
                reached = true;
                break;
            }
            q.pop();
            for(int j = 0; j < V; j++) {
                int t = edges[cur][j];
                if(edges[cur][j] > 0 && !visited[j]) q.push({j, cur});
            }
            visited[cur] = true;
        }
        if(!reached) break;
    }
    return maxFlow;
}

int main() {
    int V = 70, E;
    cin >> E;
    int source, sink;
    source = 0;
    sink = 25;
    vector<vector<int> > edges(V, vector<int>(V, -1));


    for (int i = 0; i < E; ++i) {
        char u, v;
        int c;
        cin >> u >> v >> c;
        u -= 'A';
        v -= 'A';
        if(edges[u][v] != -1) {
            edges[u][v] += c;
        } else edges[u][v] = c;
        if(edges[v][u] == -1) edges[v][u] = 0;
    }
    int maxFlow = findMaxFlow(edges, V, E, source, sink);
    printf("%d\n",maxFlow);
    return 0;
}
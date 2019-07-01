//
// Created by Vinay Saini on 2019-06-30.
//
/**
 * Tutorial: https://www.youtube.com/watch?v=johyrWospv0&t=470s
 *https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/AllCyclesInDirectedGraphJohnson.java
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
#include <unordered_set>
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
};


class TarjanScc {
private:
    Graph g;
    vector<bool> visited;
    vector<bool> onStack;
    vector<int> inT;
    vector<int> minT;
    stack<int> stk;
    vector<unordered_set<int>> ans;
public:

    TarjanScc(Graph &g) {
        this->g = g;
        int V  = g.V;
        visited.resize(V, false);
        onStack.resize(V, false);
        inT.resize(V);
        minT.resize(V);
    }

    void dfs(int cur, int time) {
        stk.push(cur);
        onStack[cur] = true;
        visited[cur] = true;
        inT[cur] = time;
        minT[cur] = time;
        time++;
        for (int i = 0; i < g.adj[cur].size(); ++i) {
            int nb = g.adj[cur][i];
            if(onStack[nb]) {
                minT[cur] = min(minT[cur], inT[nb]);
            } else if (!visited[nb]) {
                dfs(nb, time);
                minT[cur] = min(minT[cur], minT[nb]);
            }
        }
        if(inT[cur] == minT[cur]) {
            unordered_set<int> uset;
            int top;
            do {
                top = stk.top();
                stk.pop();
                onStack[top] = false;
                uset.insert(top);
            } while (top != cur);
            ans.push_back(uset);
        }
    }
    vector<unordered_set<int>> findSccTarjan() {
        int V = g.V;
        for (int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, 0);
            }
        }
        return ans;
    }
};

class JohnsonAllCycles {
    Graph g;
    map<int, int> blockMap;
    vector<bool> block;
public:
    JohnsonAllCycles(Graph &g) {
        this->g = g;
        this->block.resize(g.V, false);
    }
    vector<vector<int>> ans;
    int start;

    bool dfs(int cur, vector<int> &cycle) {
        cycle.push_back(cur);
        block[cur] = true;
        bool found = false;
        for (int i = 0; i < g.adj[cur].size(); ++i) {
            int nb = g.adj[cur][i];
            if(nb < start) continue;
            if(nb == start) {
                vector<int> v(cycle);
                v.push_back(start);
                ans.push_back(v);
                found = true;
            }
            else if(block[nb]) {
                continue;
            } else {
                found = dfs(nb, cycle);
            }
        }
        if(!found) {
            for (int i = 0; i < g.adj[cur].size(); ++i) {
                int nb = g.adj[cur][i];
                blockMap[nb] = cur;
            }
        } else {
            block[cur] = false;
            int next = cur;
            while (blockMap.find(next) != blockMap.end()) {
                next = blockMap[next];
                block[next] = false;
            }
        }
        cycle.pop_back();
        return found;
    }
    vector<vector<int>> findAllSimpleCycles(int start) {
        this->start = start;
        vector<int> cycle;
        dfs(start, cycle);
        return ans;
    }

};

// creates a subGraph discarding all vertex's edges less than minVertex
Graph createSubgraph(Graph &g, int minVertex) {
    Graph subGraph(g.V);
    for (int i = 0; i < g.adj.size(); ++i) {
        if(i < minVertex) continue;
        for (int j = 0; j < g.adj[i].size(); ++j) {
            int nb = g.adj[i][j];
            if(nb < minVertex) continue;
            subGraph.addDirectionalEdge(i, nb);
        }
    }
    return subGraph;
}

pair<int, Graph>  findMinimumSccAndCreateGraph(vector<unordered_set<int>> &sccs, Graph &subGraph) {
    int minVertex = INF;
    int index = -1;
    for (int i = 0; i < sccs.size(); ++i) {
        if(sccs[i].size() < 2) continue;
        for(auto itr = sccs[i].begin(); itr != sccs[i].end(); itr++) {
            if((*itr) < minVertex) {
                minVertex = *itr;
                index = i;
            }
        }
    }
    if(index == -1)
        return {-1, NULL};
    unordered_set<int> scc = sccs[index];
    Graph g(subGraph.V);
    for (int i = 0; i < subGraph.V; ++i) {
        if(scc.find(i) == scc.end()) continue;
        for (int j = 0; j < subGraph.adj[i].size(); ++j) {
            int nb = subGraph.adj[i][j];
            if(scc.find(nb) != scc.end()) {
                g.addDirectionalEdge(i, nb);
            }
        }
    }
    return {minVertex, g};
}

int main() {
    int E, V, u, v;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        g.addDirectionalEdge(u, v);
    }
    int startVertex = 0;
    while (startVertex < V) {
        g = createSubgraph(g, startVertex);
        TarjanScc tarjanScc(g);
        vector<unordered_set<int>> sccs = tarjanScc.findSccTarjan();
        pair<int, Graph> sccWithMinVertex = findMinimumSccAndCreateGraph(sccs, g);
        int minVertex = sccWithMinVertex.first;
        Graph minSccGraph = sccWithMinVertex.second;
        JohnsonAllCycles johnsonAllCycles(minSccGraph);
        vector<vector<int>> simpleCycles = johnsonAllCycles.findAllSimpleCycles(minVertex);
        for (int k = 0; k < simpleCycles.size(); ++k) {
            cout << "Cycles: \n";
            for (int l = 0; l < simpleCycles[k].size(); ++l) {
                cout << simpleCycles[k][l] << " ";
            }
            cout << "\n";
        }
        startVertex = minVertex + 1;
    }
    return 0;
}
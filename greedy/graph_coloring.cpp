//
// Created by Vinay Saini on 10/12/18.
//

/**
 * https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
 * https://www.techiedelight.com/greedy-coloring-graph/
 * The graph coloring (also called as vertex coloring) is a way of coloring the vertices of a graph such that no two adjacent vertices share the same color.
 *
 * Unfortunately, there is no efficient algorithm available for coloring a graph with minimum number of colors as the problem is a known NP Complete problem
 */



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
#include <unordered_set>

using namespace std;

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define  INF (1<<29)
#define fill(ar,val) memset(ar,val,sizeof ar)
#define  min(a,b) ((a)<(b)?(a):(b))
#define  max(a,b) ((a)>(b)?(a):(b))
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

class Graph {
public:
    int V;
    vector<int> *adj;
    Graph(int V, int E) {
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int getNextAvailableColor(set<int> &used) {
    int c = 0;
    for(auto itr = used.begin(); itr != used.end(); itr++) {
        if(c != *itr) {
            break;
        }
        c++;
    }
    return c;
}

// vector of size V, vertex (index) - (value) color number
vector<int> colorGraph(Graph g) {
    int colorAr[g.V];
    memset(colorAr, -1, sizeof colorAr);
    for (int i = 0; i < g.V; ++i) {
        set<int> used;
        for (int j = 0; j < g.adj[i].size(); ++j) {
            if(colorAr[g.adj[i][j]] != -1) {
                used.insert(colorAr[g.adj[i][j]]);
            };
        }
        int color = getNextAvailableColor(used);
        colorAr[i] = color;
    }
    vector<int> ret(colorAr, colorAr+g.V);
    return ret;
}

int main() {
    string colors[] = {"red", "yellow", "purple", "green", "blue", "white", "black"};
    int V, E;
    cin >> V >> E;
    Graph g = Graph(V, E);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    vector<int> result = colorGraph(g);

    // display
    for (int i = 0; i < result.size(); ++i) {
        cout << "Color for vertical " << i << " " + colors[result[i]] << "\n";
    }
}

//
// Created by Vinay Saini on 20/01/18.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef pair<int, int> pii;

struct Graph {
    int V, E;
    vector < pair<int, pii> > edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v,int  w) {
        edges.push_back({w, {u, v}});
    }
    int kruskalMST();
};


struct DisjointSets {
    int *parent;
    int *rnk;
    DisjointSets(int n) {
        this->n = n;
        this->parent = new int[n+1];
        this->rnk = new int[n+1];
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
    }
    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (rnk[root_x] > rnk[root_y]) {
            parent[root_y] = root_x;
            rnk[root_x]++;
        } else {
            parent[root_x] = root_y;
            rnk[root_y]++;
        }
    }
};

int Graph::kruskalMST() {
    int mst_wt = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    int edge_in_mst = 0;
    for(int i = 0; i < E && edge_in_mst <= V-1; i++) {
        int r1 = ds.find(edges[i].second.first);
        int r2 = ds.find(edges[i].second.second);
        if(r1 != r2) {
            mst_wt += edges[i].first;
            edge_in_mst++;
            ds.merge(r1, r2);
        }
    }
    return mst_wt;
}

int main() {
    int V = 9, E = 14;
    Graph g(V, E);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << g.kruskalMST() << endl;
    // Output 37
    return 0;
}



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

void input() {
    int n, m;
    int u, v;
    cin >> n >> m;
    vector<bool> visited(n);
    vector< vector<int> > ar(n);
    vector<int> colored(n);
    for (int i = 0; i < n; ++i) {
        ar[i].clear();
        visited[i] = false;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        ar[u-1].push_back(v-1);
        ar[v-1].push_back(u-1);
    }
    int color = 1;
    int count = 1;
    queue<int> q;
    q.push(0);
    colored[0] = color;
    visited[0] = 1;
    while (!q.empty()) {
        int cur = q.front();
        int cur_color = colored[cur];
        q.pop();
        int next_color = 1 - cur_color;
        for (int i = 0; i < ar[cur].size(); ++i) {
            int next = ar[cur][i];
            if(!visited[next]) {
                colored[next] = next_color;
                if(next_color == 1) count++;
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    if(count <= n/2) {
        cout << count <<"\n";
        for (int i = 0; i < n; ++i) {
            if(colored[i] == 1) cout << i + 1 << " ";
        }
    } else {
        cout << n - count <<"\n";
        for (int i = 0; i < n; ++i) {
            if(colored[i] == 0) cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        input();
    }
}



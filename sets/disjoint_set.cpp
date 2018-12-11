
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

using namespace std;

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define  INF (1<<29)
#define fill(ar,val) memset(ar,val,sizeof ar)
#define  min(a,b) ((a)<(b)?(a):(b))
#define  max(a,b) ((a)>(b)?(a):(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

class Set {
    int *parent;
    int *rank;
    int n;
public:
    Set(int n) {
        parent = new int[n];
        rank = new int[n];
        memset(rant, 0, sizeof(rank))
        this->n = n;
    }
    void make_set() {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    void union_set(int x, int y) {
        int p = find_set(x);
        int q = find_set(y);
        if(rank[p] > rank[q]) {
            parent[q] = p;
            rank[p]++;
        } else {
            parent[p] = q;
            rank[q]++;
        }
    }
    int find_set(int x) {
        if(parent[x] != x) {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
};



int main() {
    //initialize
    int N = 10;
    Set st(N);
    st.make_set();

    st.union_set(1 , 3);
    cout << "\n" << st.find_set(1) << " " << st.find_set(3);
    st.union_set(2 , 3);
    cout << "\n" << st.find_set(2) << " " << st.find_set(3);
    st.union_set(5 , 6);
    cout << "\n" << st.find_set(5) << " " << st.find_set(6);
    st.union_set(0 , 6);
    cout << "\n" << st.find_set(0) << " " << st.find_set(6);
    st.union_set(0 , 3);
    cout << "\n" << st.find_set(0) << " " << st.find_set(3);
    cout << "\n" << st.find_set(2) << " " << st.find_set(4);
    return 0;
}
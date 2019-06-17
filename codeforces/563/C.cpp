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

int solve(int ar[], int n) {
    int count = 0;
    int i = 0, j =  0, k = 0, l = 0, m = 0, N = 0;
    while (true) {
        while (i < n && ar[i] != 4) i++;
        if(i >= n) break;
        j = max(j+1, i + 1);
        while (j < n && ar[j] != 8) j++;
        if(j >= n) break;
        k = max( k+1, j + 1);
        while (k < n && ar[k] != 15) k++;
        if(k >= n) break;
        l = max( l+1, k + 1);
        while (l < n && ar[l] != 16) l++;
        if(l >= n) break;
        m = max( m+1, l + 1);
        while (m < n && ar[m] != 23) m++;
        if(m >= n) break;
        N = max( N+1, m + 1);
        while (N < n && ar[N] != 42) N++;
        if(N >= n) break;
        count += 6;
        i++;
    }
    return n - count;
}
int main() {
    int q, n;
    int x;
   // cin >> q;
    //for (int i = 0; i < q; ++i) {
        cin >> n;
        int ar[n];
        for (int j = 0; j < n; ++j) {
            cin >> ar[j];
        }
        cout << solve(ar, n) << "\n";
    //}
    return 0;
}

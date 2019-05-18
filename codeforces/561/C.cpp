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

int search(int x, int ar[], int i, int j) {
    while(i <= j) {
        int m = (i+j)/2;
        if(ar[m] <= x) {
            i = m+1;
        } else j = m - 1;
    }
    return j;
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        ar[i] = abs(ar[i]);
    }
    sort(ar, ar+n);
    long long ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int x = 2*(ar[i]);
        //int pos = upper_bound(ar+(i+1), ar+n, x) - (ar + i + 1);
        int pos = search(x, ar, i+1, n-1);
        ans += pos - i;
    }
    cout << ans;
    return 0;
}
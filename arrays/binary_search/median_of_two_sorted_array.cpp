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

// Watch Tushar roy video if forgot the logic - We do binary search only on first array & get relative partition point on second array
double findMedian(int ar1[], int n1, int ar2[], int n2) {
    if(n1 > n2) {
        return findMedian(ar2, n2, ar1, n1);
    }
    int lo = 0;
    int hi = n1;
    while (lo <= hi) {
        int p1 = (lo+hi)/2;
        int p2 = (n1 + n2 + 1)/2 - p1;

        int ar1Left = p1 == 0 ? -INF : ar1[p1-1];
        int ar1Right = p1 == n1 ? INF : ar1[p1];

        int ar2Left = p2 == 0 ? -INF : ar2[p2-1];
        int ar2Right = p2 == n2 ? INF : ar2[p2];

        if(ar1Left <= ar2Right && ar2Left <= ar1Right) {
            if((n1+n2)%2 == 0) {
                return (max(ar1Left, ar2Left) + min(ar1Right, ar2Right))/2.0;
            }
            return max(ar1Left, ar2Left);
        } else if(ar1Left > ar2Right) {
            hi = p1-1;
        } else lo = p1 + 1;
    }
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int ar1[n1];
    int ar2[n2];
    for (int i = 0; i < n1; ++i) {
        cin >> ar1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> ar2[i];
    }
    sort(ar1, + ar1 + n1);
    sort(ar2, + ar2 + n2);
    double ans = findMedian(ar1, n1, ar2, n2);
    cout << ans;
    return 0;
}

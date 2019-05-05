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

int findMedian(int ar1[], int n1, int ar2[], int n2) {
    int i1 = 0, j1 = n1-1;
    int i2 = 0, j2 = n2-1;
    while (true) {
        int m1 = (i1 + j1)/2;
        int m2 = (i2 + j2)/2;

    }
    int result = 0;
    return result;
}

int main() {
    int n1, n2;
    cin >> n1, n2;
    int ar1[n1];
    int ar2[n2];
    sort(ar1, + ar1 + n1);
    sort(ar2, + ar2 + n2);
    int ans = findMedian(ar1, n1, ar2, n2) {
        cout << ans << "\n";
    }
    return 0;
}

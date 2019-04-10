//
// Created by Vinay Saini on 09/04/19.
//

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

int bit[100];

int update(int ar[], int n, int i, int value) {
    int idx = i + 1;
    int diff = value - bit[idx];
    while(idx <= n) {
        bit[idx] += diff;
        idx += idx & (-idx);
    }
}

void make_bit(int ar[], int n) {
    for (int i = 0; i < n; ++i) {
        int idx = i+1;
        while (idx <= n) {
            bit[idx] += ar[i];
            idx += idx & (-idx);
        }
    }
}

int getSum(int i) {
    int idx = i + 1;
    int sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= idx &(-idx);
    }
    return sum;
}

int getRangeSum(int l, int r) {
    return getSum(r) - getSum(l-1);
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    make_bit(ar, n);

    // ----- Input
    // below are queries to test
    int l, r;
    cin >> l >> r;
    cout << getRangeSum(l, r) << "\n";

    int i, value;
    cin >> i >> value;
    update(ar, n, i, value);

    cout << getRangeSum(0, n-2) << "\n";

    cout << getRangeSum(1, n-1) << "\n";



    return 0;

}
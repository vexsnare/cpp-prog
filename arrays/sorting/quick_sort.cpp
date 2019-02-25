//
// Created by Vinay Saini on 22/02/19.
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

void solve(int ar[], int si, int ei) {
    if(ei <= si)
        return;
    int pivot = ar[ei];
    int j = si-1;
    for (int i = si; i < ei; ++i) {
        if(ar[i] < pivot) {
            swap(ar[i], ar[j+1]);
            j++;
        }
    }
    swap(ar[j+1], ar[ei]);
    solve(ar, si, j);
    solve(ar, j+2, ei);
}

/**
 *
 * @param ar
 * @param n
 * Complexity:
 * Runtime: O(nlog2n) Worst Case: O(n^2)
 * Space: O(1)
 * Randomized : Pick any element randomly in a given range as pivot swap it with last element and continue
 */
void quick_sort(int ar[], int n) {
    solve(ar, 0, n-1);
}

void validate() {
    int ar[] = {1};
    int ar_exp[] = {1};
    quick_sort(ar, 1);
    assert(equal(begin(ar), end(ar), begin(ar_exp)));

    int ar2[] = {1, 2, 3};
    int ar2_exp[] = {1, 2, 3};
    quick_sort(ar2, 3);
    assert(equal(begin(ar2), end(ar2), begin(ar2_exp)));

    int ar3[] = {3, 2, 1};
    int ar3_exp[] = {1, 2, 3};
    quick_sort(ar3, 3);
    assert(equal(begin(ar3), end(ar3), begin(ar3_exp)));

    int ar4[] = {1, 5, 3, 2, 1};
    int ar4_exp[] = {1, 1, 2, 3, 5};
    quick_sort(ar4, 5);
    assert(equal(begin(ar4), end(ar4), begin(ar4_exp)));

    int ar5[] = {-3, -3};
    int ar5_exp[] = {-3, -3};
    quick_sort(ar5, 3);
    assert(equal(begin(ar5), end(ar5), begin(ar5_exp)));

    int ar6[] = {-3, -5};
    int ar6_exp[] = {-5, -3};
    quick_sort(ar6, 2);
    assert(equal(begin(ar6), end(ar6), begin(ar6_exp)));

}

int main() {
    validate();
    cout << "All test cases passed..." << endl;

    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    quick_sort(ar, n);
    for (int i = 0; i < n; ++i) {
        cout << ar[i] << " ";
    }
}




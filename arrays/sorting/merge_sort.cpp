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
    int mi = (si + ei) / 2;

    solve(ar, si, mi);
    solve(ar, mi+1, ei);

    int n = ei-si + 1;
    int temp[n];
    int i = si;
    int j = mi+1;
    int k = 0;
    while (i <= mi || j <= ei) {
        if(i <= mi && j <= ei) {
            if(ar[i] < ar[j]) {
                temp[k++] = ar[i++];
            } else{
                temp[k++] = ar[j++];
            }
        }
        else if(i <= mi) {
            temp[k++] = ar[i++];
        } else {
            temp[k++] = ar[j++];
        }
    }
    for (int k = 0; k < n; ++k) {
        ar[si+k] = temp[k];
    }
}

/**
 *
 * @param ar
 * @param n
 * Complexity:
 * Runtime: O(nlog2n) Worst Case: O(nlogon)
 * Space: O(n)
 */
void merge_sort(int ar[], int n) {
    solve(ar, 0, n-1);
}

void validate() {
    int ar[] = {1};
    int ar_exp[] = {1};
    merge_sort(ar, 1);
    assert(equal(begin(ar), end(ar), begin(ar_exp)));

    int ar2[] = {1, 2, 3};
    int ar2_exp[] = {1, 2, 3};
    merge_sort(ar2, 3);
    assert(equal(begin(ar2), end(ar2), begin(ar2_exp)));

    int ar3[] = {3, 2, 1};
    int ar3_exp[] = {1, 2, 3};
    merge_sort(ar3, 3);
    assert(equal(begin(ar3), end(ar3), begin(ar3_exp)));

    int ar4[] = {1, 5, 3, 2, 1};
    int ar4_exp[] = {1, 1, 2, 3, 5};
    merge_sort(ar4, 5);
    assert(equal(begin(ar4), end(ar4), begin(ar4_exp)));

    int ar5[] = {-3, -3};
    int ar5_exp[] = {-3, -3};
    merge_sort(ar5, 3);
    assert(equal(begin(ar5), end(ar5), begin(ar5_exp)));

    int ar6[] = {-3, -5};
    int ar6_exp[] = {-5, -3};
    merge_sort(ar6, 2);
    assert(equal(begin(ar6), end(ar6), begin(ar6_exp)));

}

int main() {
    validate();
    cout << "All test cases passed..." << endl;

    printf("Custom test: \n");
    int n;
    scanf("%d", &n);
    assert(n > 0);
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    merge_sort(ar, n);
    for (int i = 0; i < n; ++i) {
        cout << ar[i] << " ";
    }
}




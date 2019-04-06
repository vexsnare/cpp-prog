/**
 *
 * https://www.geeksforgeeks.org/longest-consecutive-subsequence/
 * Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 * Input: arr[] = {1, 9, 3, 10, 4, 20, 2};
 * Output: 4
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"

int solve(int ar[], int n) {
    unordered_map<int, int> m;
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int x = ar[i];
        if(m.find(x) == m.end()) {
            int left = 0, right = 0;
            if(m.find(x-1) != m.end()) {
                left = m[x-1];
            }
            if(m.find(x+1) != m.end()) {
                right = m[x+1];
            }
            int len = left + right + 1;
            m[x-left] = len;
            m[x+right] = len;
            ans = max(ans, len);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    cout << solve(ar, 11) << "\n";
    return 0;
}
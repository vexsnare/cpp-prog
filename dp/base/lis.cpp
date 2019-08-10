//
// Created by Vinay Saini on 10/08/19.
//

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
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

int solveLIS(vector<int> &v) {
    int n = v.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> input{3, 1, 5, 10, 2, 3, 10, 1};
    return 0;
}
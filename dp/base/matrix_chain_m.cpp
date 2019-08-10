//
// Created by Vinay Saini on 2019-07-25.
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
#define MAX 100

int memo[MAX][MAX];

int solve(int i, int j, vector<int> &v) {
    if(memo[i][j] != -1) return memo[i][j];
    if(j-i < 2) return 0;
    int ret = INF;
    for (int k = i+1; k < j; ++k) {
        int left = solve(i, k, v);
        int right = solve(k, j, v);
        ret = min(ret, left + right + v[i]*v[k]*v[j]);
    }
    memo[i][j] = ret;
    return ret;
}

int main() {
    // Representing 10*300 300*50, 50*40
    vector<int> input{10, 30, 5, 60};
    memset(memo, -1, MAX*MAX);
    cout << solve(0, input.size()-1, input);
    return 0;
}



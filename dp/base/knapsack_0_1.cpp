//
// Created by Vinay Saini on 2019-07-24.
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

#define MAX 1000

int memo[MAX][MAX];
vector<int> weights;
vector<int> values;

//picking from last
int solve(int w, int n) {
    if(memo[w][n] != -1) return memo[w][n];
    if(n < 0 || w <= 0) return 0;
    int ret = 0;
    if(w >= weights[n]) {
        ret = max(values[n] + solve(w-weights[n], n-1), solve(w, n-1));
    } else {
        ret = solve(w, n-1);
    }
    memo[w][n] = ret;
    return ret;
}

/**
 * https://www.hackerearth.com/practice/notes/the-knapsack-problem/
 * @param W
 * @param weights
 * @param values
 * @return
 */
int knapsack(int W, vector<int> input_weights, vector<int> input_values) {
    memset(memo, -1, MAX*MAX);
    weights = input_weights;
    values = input_values;
    int n = weights.size();
    return solve(W, n-1);
}

int main() {
    int W = 10;
    vector<int> weights{5, 4, 6, 3};
    vector<int> values{10, 40, 30, 50};
    assert(knapsack(W, weights, values) == 90);
    return 0;
}
//
// Created by Vinay Saini on 11/12/18.
//

/**
 * https://www.techiedelight.com/rot-cutting/
 * Given a rod of length n inches and a table of prices pi, i=1,2,…,n, write an algorithm to find the maximum revenue rn obtainable by cutting up the rod and selling the pieces.
 * https://algorithms.tutorialhorizon.com/dynamic-programming-rod-cutting-problem/
 */

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
#define  INF (1<<29)
#define fill(ar,val) memset(ar,val,sizeof ar)
#define  min(a,b) ((a)<(b)?(a):(b))
#define  max(a,b) ((a)>(b)?(a):(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int solve(int prices[], int n) {
    if(n <= 0)
        return 0;
    int dp[n];
    for (int i = 0; i < n; ++i) {
        int rev = prices[i];
        for (int j = 0; j < i; j++) {
            rev = max(rev, prices[j]+dp[i-j-1]);
        }
        dp[i] = rev;
    }
    return dp[n-1];
}

int main() {
    // rod length
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    int max_revanue = solve(prices, n);
    cout << max_revanue << endl;
}
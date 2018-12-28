//
// Created by Vinay Saini on 13/12/18.
//

/**
 * https://leetcode.com/problems/burst-balloons/
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
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

int dp[500][500][2];

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    //corner case;
    
    if(n == 0) return 0;
    for (int i = 0; i < n; ++i) {
        if(i-1 >= 0 && i+1 < n) dp[i][i][0] = ar[i-1]*ar[i]*ar[i+1];
        else if(i-1 >= 0) dp[i][i][0] = ar[i-1]*ar[i]*1;
        else if(i+1 < n) dp[i][i][0] = 1*ar[i]*ar[i+1];
        else dp[i][i][0] = ar[i];
        dp[i][i][1] = i;
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i+j < n; ++i) {
            int maxScore = -INF;
            int leftBalloonNum = i-1 >= 0 ? ar[i-1] : 1;
            int rightBalloonNum = i + j + 1 < n ? ar[i+j+1]: 1;
            for (int k = i; k <= i+j; ++k) {
                int leftScore = k-1 >= i ? dp[i][k-1][0] : 0;
                int rightScore = k+1 <= i+j ? dp[k+1][i+j][0]: 0;
                int score = leftScore + leftBalloonNum * ar[k] * rightBalloonNum + rightScore;
                if(maxScore < score) {
                    maxScore = score;
                    dp[i][i+j][0] = score;
                    dp[i][i+j][1] = k;
                }
            }
        }
    }
    cout << dp[0][n-1][0];
    return 0;
}
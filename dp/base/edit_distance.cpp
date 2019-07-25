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

string str1;
string str2;
int memo[MAX][MAX];

int solve(int n1, int n2) {
    if(n1 < 0 && n2 < 0) {
        return 0;
    }
    if(n1 < 0) return 1+n2;
    if(n2 < 0) return 1+n1;
    if(memo[n1][n2] != -1) return memo[n1][n2];
    if(str1[n1] == str2[n2]) return solve(n1-1, n2-1);
    int ret = 1 + min(min(solve(n1, n2-1), solve(n1-1, n2)), solve(n1-1, n2-1));
    memo[n1][n2] = ret;
    return ret;
}

/**
 * https://www.techiedelight.com/levenshtein-distance-edit-distance-problem
 * @param s1
 * @param s2
 * @return
 */
int findMinEditDistance(string &s1, string &s2) {
    str1 = s1;
    str2 = s2;
    int n1 = s1.length();
    int n2 = s2.length();
    memset(memo, -1, MAX*MAX);
    return solve(n1-1, n2-1);
}

int main() {

    string s1 = "kitten";
    string s2 = "sitting";
    assert(findMinEditDistance(s1, s2) == 3);

    s1 = "kitten";
    s2 = "kitten";
    assert(findMinEditDistance(s1, s2) == 0);


    s1 = "kitten";
    s2 = "";
    assert(findMinEditDistance(s1, s2) == 6);

    return 0;
}
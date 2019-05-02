#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <queue>

using namespace std;

string optimize(string s) {
    if(s.empty()) return s;
    int i = 0;
    for (int j = 1; j < s.length(); ++j) {
        if(s[j] == '*' && s[i] == '*') continue;
        i++;
        s[i] = s[j];
    }
    s.resize(i+1);
    return s;
}

bool isMatch(string str, string pat) {
    pat = optimize(pat);
    int n = str.length();
    int m = pat.length();
    if(n == 0) {
        return m == 1 && pat[0] == '*';
    }
    if(m == 0) {
        return false;
    }

    bool dp[n][m];

    memset(dp, false, sizeof dp);

    // base
    for (int i = 0; i < n; ++i) {
        if(pat[0] == '*') dp[i][0] = true;
        else if(pat[0] == '?') {
            dp[i][0] = i == 0;
        } else dp[i][0] = (i == 0) ? str[i] == pat[0] : false;
    }

    int q = 0;
    int ch = 0;
    for (int j = 0; j < m; ++j) {
        if (pat[j] == '*') {
            dp[0][j] = j > 0 ? dp[0][j-1] : true;
        }
        else if (pat[j] == '?') {
            dp[0][j] = ch+q == 0;
            q++;
        } else {
            dp[0][j] = ch+q == 0 ? pat[j] == str[0] : false;
            ch++;
        }
    }

    // dp
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if(pat[j] == '*') {
                dp[i][j] |= dp[i-1][j] | dp[i][j-1] | dp[i-1][j-1];
            }
            else if(pat[j] == str[i] || pat[j] == '?') {
               dp[i][j] |= dp[i-1][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}

int main() {
    string str;
    string pattern;
    cin >> str >> pattern;
    printf("%s\n", isMatch(str, pattern) ? "YES": "NO");
    return 0;
}

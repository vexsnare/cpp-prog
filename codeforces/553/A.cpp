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

int cost(char c1, char c2) {
    if(c1 > c2) swap(c1, c2);
    return min(c2-c1, 26+c1-c2);
}
int findDiff(string s) {
    string g = "ACTG";
    int diff = 0;
    for (int i = 0; i < 4; ++i) {
        diff += cost(s[i], g[i]);
    }
    return diff;
}

int main() {
    int n;
    cin>>n;
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (int i = 0; i + 3 < s.length(); ++i) {
        int opr = findDiff(s.substr(i, i+4));
        if(opr < ans) ans = opr;
    }
    cout << ans << "\n";
    return 0;
}
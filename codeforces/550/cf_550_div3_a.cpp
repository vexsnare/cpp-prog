//
// Created by Vinay Saini on 11/03/19.
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

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        string ans = "Yes";
        for(int i = 1; i < s.length(); i++) {
            if(s[i]-1 != s[i-1]) {
                ans = "No";
                break;
            };
        }
        cout << ans << "\n";
    }
    return 0;
}
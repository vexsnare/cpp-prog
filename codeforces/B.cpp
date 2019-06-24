//
// Created by Vinay Saini on 2019-06-19.
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

bool isValid(string &s1, string &s2) {
    if(s2.length() < s1.length()) return false;
    int i = 0, j = 0;
    while (j < s2.length()) {
        if(i < s1.length() && s1[i] == s2[j]) {
            j++;
            i++;
        } else if(i-1 >= 0 && s2[j] == s1[i-1]) j++;
        else {
            break;
        }
    }
    return j == s2.length() && i == s1.length();
}

int main() {
    vector<string> v;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n*2; ++i) {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < 2*n; i += 2) {
        if(isValid(v[i], v[i+1])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
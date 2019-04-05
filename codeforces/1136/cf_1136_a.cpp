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
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    int k;
    cin >> k;
    int count = 0;
    for (int j = 0; j < n; ++j) {
        if(v[j].second < k) count++;
        else break;
    }
    cout << n - count << "\n";
    return 0;
}
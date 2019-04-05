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
    int x;
    vector<int> evens;
    vector<int> odds;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(x%2 == 0) {
            evens.push_back(x);
        } else {
            odds.push_back(x);
        }
    }
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    int evens_sz = evens.size();
    int odds_sz = odds.size();
    if(abs(evens_sz - odds_sz) <= 1) {
        cout << "0" << "\n";
    } else {
        int ans = 0;
        if(evens_sz > odds_sz) {
            for (int i = 0; i < evens_sz - odds_sz - 1; ++i) {
                ans += evens[i];
            }
        } else {
            for (int i = 0; i < odds_sz - evens_sz - 1; ++i) {
                ans += odds[i];
            }
        }
        cout << ans  << endl;
    }
    return 0;
}
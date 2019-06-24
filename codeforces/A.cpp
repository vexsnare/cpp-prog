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

int main() {
    int x, d;
    vector<int> v;
    for (int i = 0; i < 3; ++i) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cin >> d;
    v.push_back(d);
    int ans = 0;
    for(int i = 1; i < 3; i++) {
        if(v[i]-v[i-1] < v[3]) {
            ans += v[3]-v[i] + v[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}
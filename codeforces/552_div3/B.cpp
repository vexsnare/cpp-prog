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

int main() {
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    int max = 101;
    int ans = max;
    sort(v.begin(), v.end());
    if(v[0] == v[v.size()-1]) ans = 0;
    else {
        for (int i = 0; i < max; ++i) {
            set<int> diff;
            for (int j = 0; j < n; ++j) {
                int d = abs(v[j] - i);
                if (d != 0) diff.insert(d);
                if (diff.size() > 1) {
                    diff.clear();
                    break;
                }
            }
            if (diff.size() == 1) {
                int d = 0;
                for (auto itr = diff.begin(); itr != diff.end(); itr++) {
                    d = *itr;
                }
                ans = min(d, ans);
            }

        }
        if (ans == max) ans = -1;
    }
    cout << ans << "\n";
    return 0;
}
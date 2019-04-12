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

int solve(int ar[], int n) {
    stack<int> stk;
    int i;
    int ans = 0;
    for (i = 0; i < n; ++i) {
        if (stk.empty() || ar[i] <= ar[stk.top()]) stk.push(i);
        else {
            while (!stk.empty() && ar[stk.top()] < ar[i]) {
                int height = ar[stk.top()];
                stk.pop();
                if(!stk.empty()) {
                    int h = min(ar[i], ar[stk.top()]);
                    ans += (h - height)*(i-stk.top()-1);
                }
            }
            stk.push(i);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", ar+i);
        }
        cout << solve(ar, n) << endl;
    }
    return 0;
}
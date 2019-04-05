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
    int k;
    cin >> k;
    int ans;
    if(n-k < k-1) {
        ans = 4*(n-k) + 3*k;
    } else {
        ans = 4*(k-1) + 3*(n-k+1);
    }
    cout << ans << "\n";
    return 0;
}

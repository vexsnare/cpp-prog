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
#include <bitset>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"

int main() {
    int n, m, x;
    cin >> n >> m;
    int o1 = 0;
    int e1 = 0;
    int o2 = 0;
    int e2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(x % 2 == 0) {
            e1++;
        } else o1++;
    }

    for (int i = 0; i < m; ++i) {
        cin >> x;
        if(x % 2 == 0) {
            e2++;
        } else o2++;
    }
    printf("%d\n", min(e1, o2) + min(o1, e2));
    return 0;
}
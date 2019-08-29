//
// Created by Vinay Saini on 25/08/19.
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
    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        int idx = n%3;
        if(idx == 0) cout << a;
        else if(idx == 1) cout << b;
        else cout << (a^b);
        cout << "\n";
    }
    return 0;
}
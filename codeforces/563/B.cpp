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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int solve(int ar[], int n) {
    int count = 0;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; ++i) {
        if(ar[i] % 3 == 0) {
            count ++;
        } else {
            if(ar[i] % 3 == 1) {
                ones++;
            } else twos++;
        }
    }
    int mn = min(ones, twos);
    count += mn;
    ones -= mn;
    twos -= mn;
    count += ones / 3;
    count += twos / 3;
    return count;
}
int main() {
    int q, n;
    long long x;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        int ar[n];
        for (int j = 0; j < n; ++j) {
            cin >> ar[j];
        }
        cout << solve(ar, n) << "\n";
    }
    return 0;
}

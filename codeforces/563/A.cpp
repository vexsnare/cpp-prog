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

long long solve(long long n) {
    int count = 0;
    while (n > 1) {
        if(n == 1) break;
        if (n % 2 == 0) {
            n /= 2;
            count++;
        } else if (n % 3 == 0) {
            n /= 3;
            count += 2;
        } else if (n % 5 == 0) {
            n /= 5;
            count += 3;
        } else return -1;
    }
    return count;
}
int main() {
    int q;
    long long x;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}

//
// Created by Vinay Saini on 2019-06-18.
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

// Return gcd in long(n), where n = max(x, y)
long long gcd(long long x, long long y) {
    return y == 0 ? x : gcd(y%x, x);
}

// Returns x^n in log2(n)
long long pow(long long x, long long n) {
    if(n == 0) return 1;
    long long ans = pow(x, n/2);
    ans = ans*ans;
    if(n%2 != 0) ans = x*ans;
    return ans;
}

int main() {

    return 0;
}
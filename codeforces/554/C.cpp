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

int _gcd(int a, int b) {
    return b == 0 ? a : _gcd(b, a%b);
}
/**
 * wrong
 * @return
 */
int main() {
    int a, b;
    cin >> a >> b;
    if(b < a) {
        int t = a;
        a = b;
        b = t;
    }
    int ans;
    if(b % a == 0) {
        ans = 0;
    } else {
        int diff = b % a;
        int gcd = _gcd(a, b);
        ans = diff - gcd;
    }
    cout << ans;
    return 0;
}
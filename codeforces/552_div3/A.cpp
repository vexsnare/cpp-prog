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
    int t;
    vector<int> v;
    for (int i = 0; i < 4; ++i) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    long long x,y,z,p;
    x = v[0];
    y = v[1];
    z = v[2];
    long long b = (z + x - y)/2;
    long long a = x - b;
    long long c = z - b;
    cout << a << " " << b << " " << c << "\n";
    return 0;
}
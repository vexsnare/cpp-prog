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

struct Fact {
    int a;
    int b;
    Fact(int a, int b) {
        this-> a = a;
        this-> b = b;
    }
    Fact(){};
};

int main() {
    int n, a, b;
    cin>>n;
    vector<Fact> v;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back(Fact(a, b));
    }
    sort(v.begin(), v.end(), [](const Fact &f1, const Fact &f2) {
        //if(f1.a > f2.a) {
//            if(f1.b <= f2.b) return true;
//            else f1.b - f2.b > f1.a - f2.a;
       // } else {
            return f1.b - f2.b < f1.a - f2.a;

        //}
       // return f1.a == f2.a ? f1.b < f2.b : f1.a > f2.a;
    });
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1ll * (v[i].a) * i + 1ll*(v[i].b)*(n-1-i);
    }
    cout << ans << endl;
    return 0;
}
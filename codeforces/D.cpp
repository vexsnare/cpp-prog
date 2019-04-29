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

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define   REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define  INF (1<<29)
#define 	all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define       min(a,b) ((a)<(b)?(a):(b))
#define         max(a,b) ((a)>(b)?(a):(b))
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<string> vs;

#define MAX 410000

vector<int> genPrimes() {
    vector<int> v;
    bool p[MAX];
    //memset(p, true, sizeof p);
    for (int i = 0; i < MAX; ++i) {
        p[i] = true;
    }
    for (int i = 2; 1ll*i*i < MAX ; ++i) {
        if(p[i]) {
            for (int j = i*i; j < MAX; j += i) {
                p[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if(p[i]) v.push_back(i);
    }
    return v;
}

int main() {
    vector<int> primes = genPrimes();
    int sz = primes.size();
    int n, x;
    cin >> n;
    int one = 0;
    int two = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(x == 1) one++;
        else two++;
    }
    int prefixSum = 0;
    int i = 0;
    while (i < sz && (one > 0 || two > 0)) {
        int diff = primes[i] - prefixSum;
        while (diff >= 2 && two > 0) {
            cout << 2 << " ";
            prefixSum += 2;
            diff -= 2;
            two--;
        }
        while (diff > 0 && one > 0) {
            cout << 1 << " ";
            prefixSum += 1;
            diff -= 1;
            one--;
        }
        if(diff == 0) {
            i++;
        } else break;
    }
    while (one > 0) {
        cout << 1 << " ";
        one--;
    }
    while (two > 0) {
        cout << 2 << " ";
        two--;
    }
    return 0;
}
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
    int n;
    cin >> n;
    vector<string> ar;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ar.push_back(s);
    }
    bool possible = true;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if(ar[i][j] == '.') {
                if(ar[i-1][j] == '.' && ar[i+1][j] == '.' && ar[i][j-1] == '.' && ar[i][j+1] == '.') {
                    ar[i][j] = ar[i-1][j] = ar[i+1][j] = ar[i][j-1] = ar[i][j+1] = '#';
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(ar[i][j] == '.') {
                possible = false;
            }

        }
    }
    if(possible)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
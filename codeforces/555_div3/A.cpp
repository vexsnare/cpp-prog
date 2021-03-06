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

string apply(string s, int i, int j, int ar[]) {
    for (int k = i; k <= j; ++k) {
        s[k] = '0'+ar[s[k]-'0'];
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ar[10];
    vs ans;
    for (int i = 1; i <= 9; ++i) {
        cin >> ar[i];
    }
    string ans = s;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i+l <= n; ++i) {
            string t = apply(s, i, i+l-1, ar);
            if(t > ans) ans = t;
        }
    }
    cout << ans;
    return 0;
}
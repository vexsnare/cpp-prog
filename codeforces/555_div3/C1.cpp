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


int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    int i = 0;
    int j = n-1;
    vector<char> ans;
    int last = -1;
    while (i <= j) {
        if(ar[i] < ar[j] && ar[i] >= last) {
            last = ar[i];
            i++;
            ans.push_back('L');
        } else if(ar[j] > last) {
            last = ar[j];
            j--;
            ans.push_back('R');
        } else break;
    }
    printf("%d\n", ans.size());
    for (int k = 0; k < ans.size(); ++k) {
        cout << ans[k];
    }
    return 0;
}
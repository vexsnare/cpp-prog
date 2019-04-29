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

int ar[27];
int v[27][4];

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        ar[s[i]-'a']++;
    }
    vector<char> last[3];

    for (int i = 0; i < m; ++i) {
        char opr;
        cin >> opr;
        if(opr == '+') {
            char c;
            cin >> c;
            char l;
            cin >> l;
            if(ar[l-'a'] > v[l-'a'][3]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            v[l-'a'][c-'1']++;
            v[l-'a'][3]++;
            last[c-'1'].push_back(l);
        } else if(opr == '-') {
            char c;
            cin >> c;
            char l = last[c-'1'][last[c-'1'].size()-1];
            last[c-'1'].pop_back();
            v[l-'a'][c-'1']--;
            v[l-'a'][3]--;
            if(v[l-'a'][3] <= ar[l-'a']) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}
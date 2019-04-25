#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define print(x) cout<<x<<endl
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,n) for(int (i)=a;(i)<(n);(i)++)
#define INF (1<<29)
#define pb push_back
#define sz size()
#define ln length()
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;


typedef int I;
typedef string STR;
typedef long long LL;
typedef map<I,I> MII;
typedef vector<I> VI;
typedef long double LD;
typedef vector<LL> VLL;
typedef vector<STR> VS;
typedef vector<VI> VVI;
typedef map<STR,I> MSI;
typedef map<I,MII> MMI;
typedef stringstream SS;
typedef map<char,I> MCI;
typedef map<STR,STR> MSS;

int find8(string s, int n) {
    int res = 0;
    REP(i,n) if(s[i] == '8') res++;
    return res;
}
int findLast8(string s, int n) {
    for(int i=n-1;i>=0;i--) if(s[i] == '8') return i;
    return -1;
}

bool calculate(string s, int n, int vm, int pm) {
    VI v;
    REP(i,n) if(s[i] == '8') v.pb(i);
    int j = 0;
    int pmc = pm;
    while(pmc > 0) {
        v[j] = -1;
        --pmc;
        ++j;
    }
    int id = v[j];
    // debug(id);
    if(vm < id - pm) return false;
    return true;
}

int main()
{
    int n, move, e, vm, pm, last8;
    string s;
    cin>>n;
    cin>>s;

    move = n - 11;
    vm = move/2;
    pm = move/2;
    if(move%2 == 1) ++vm;
    e = find8(s,n);
    last8 = findLast8(s,n);
    if(e == 0 || e <= pm || last8 == -1) cout<<"NO\n";
    else if(last8 + 1 <= move) cout<<"NO\n";
    else if(calculate(s,n,vm,pm)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
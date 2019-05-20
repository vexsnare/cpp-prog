//
// Created by Vinay Saini on 26/11/18.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <cmath>
#include <list>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <ctime>

using namespace std;

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define   REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define  INF (1<<29)
#define         pb push_back
#define 	     sz size()
#define         mp make_pair
#define 	all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define       min(a,b) ((a)<(b)?(a):(b))
#define         max(a,b) ((a)>(b)?(a):(b))
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<string> vs;


/**
 * x^n MOD
 * @param x
 * @param n
 * @return
 */
int pow(int x, int n) {
    if (n == 0) return 1;
    int p = pow(x, n/2) % MOD;
    if(n % 2 == 0) {
        return (int)(1ll*p*p)%MOD;
    }
    return (int)(((1ll*p*p)%MOD)*x)%MOD;
}

int rabinKarp(string pattern, string text) {


}

int getHash(string s) {

    int l = s.length();
}

int main() {
    string pattern;
    string text;
    cin >> pattern;
    cin >> text;
    cout << rabinKarp("", "sdsd") << endl;
}

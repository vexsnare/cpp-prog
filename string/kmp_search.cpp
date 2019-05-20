//
// Created by Vinay Saini on 18/01/18.
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

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<string> vs;

vector<int> kmp_search(string text, string pattern) {

}

int main() {
    string pattern;
    string text;
    cin >> pattern;
    cin >> text;
    vector<int> indexes = kmp_search(text, pattern);
    for (int i = 0; i < indexes; ++i) {
        printf("%d\n", indexes[i]);
    }
}


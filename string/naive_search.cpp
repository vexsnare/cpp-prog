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

// O(n x m)
int naive_search(string pattern, string text) {
    if(pattern.length() == 0 || text.length() == 0 || pattern.length() > text.length()) {
        return -1;
    }
    for(int i = 0; i + pattern.length() <= text.length(); i++) {
        int j;
        for(j = 0; j < pattern.length(); j++) {
            if(pattern[j] != text[i+j]) break;
        }
        if(j == pattern.length()) return i;
    }
    return -1;
}

int main() {
    string pattern;
    string text;
    cin >> pattern;
    cin >> text;
    cout << naive_search("", "sdsd") << endl;
}


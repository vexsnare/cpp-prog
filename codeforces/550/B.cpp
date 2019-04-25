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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    n -= 11;
    int turn = (n+1)/2;
    int t = turn;
    int eight = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '8') eight++;
        else if(turn > 0) {
            turn--;
        } else break;
    }
    if(turn > 0) eight -= turn;
    if(eight > n-t) {
        printf("YES\n");
    } else printf("NO\n");
    return 0;
}

//
// Created by Vinay Saini on 2019-05-17.
//

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

#define INF (1<<29)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


int pairs(int n) {
    return ((n)*(n-1))/2;
}
int ar[33];
int main() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ar[s[0]-'a']++;
    }
    for (int i = 0; i < 33; ++i) {
        if(ar[i] > 0) {
            int x = ar[i]/2;
            int y = ar[i] - x;
            result += pairs(x);
            result += pairs(y);
        }
    }
    cout << result << "\n";
    return 0;
}

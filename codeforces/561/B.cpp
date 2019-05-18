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

int find(int x) {
    for(int i = 5; i <= x/5; i++) {
        if(x % i == 0)
            return i;
    }
    return -1;
}
string g[5] = {"aeiou", "uaeio", "ouaei", "iouae", "eioua"};
int main() {
    int n;
    string str = "aeiou";
    cin >> n;
    int x = find(n);
    if(x == -1) {
        cout << -1 << "\n";
    } else {
        int y = n/x;
        string s = "";
        for(int i = 0; i < x; i++) {
            for (int j = 0; j < y; ++j) {
                s += g[i%5][j%5];
            }
        }
        cout << s << "\n";
    }
    return 0;

}

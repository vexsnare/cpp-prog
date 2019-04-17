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
    int n, b, c;
    cin >> n >> b >> c;
    int C = c;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    int steps = 0;
    for (int i = 0; i < n; ++i) {
        if(ar[i] == 0) {
            if(c > 0) c--;
            else if(b > 0) b--;
            else break;
            steps++;
        } else {
           if(c == C) c--;
           else if(b > 0) {
               b--;
               c++;
           } else if(c > 0) c--;
           else break;
           steps++;
        }
    }
    cout << steps << "\n";
    return 0;
}
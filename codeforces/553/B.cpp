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
    int n, m, x;
    cin>>n>>m;
    int XOR = 0;
    int ar[n][m];
    int ii = -1, jj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ar[i][j];
            if(j == 0 ) XOR ^= ar[i][j];
            else if (j > 0 && ar[i][j] != ar[i][j-1] && jj == -1) {
                ii = i;
                jj = j;
            }
        }
    }
    if(XOR > 0) {
        cout << "TAK\n";
        for (int i = 0; i < n; ++i) {
            printf("%d ", 1);
        }
    } else if(ii != -1) {
        cout << "TAK\n";
        for (int i = 0; i < n; ++i) {
            if(i == ii) cout << jj+1 << " ";
            else cout << 1 << " ";
        }
    } else {
        cout << "NIE\n";
    }
}
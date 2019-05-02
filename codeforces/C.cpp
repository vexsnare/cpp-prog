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


int main() {
    int n, z;
    cin >> n >> z;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    sort(ar, ar+n);
    int ans = 0;
    bool visited[n];
    for (int k = 0; k < n; ++k) {
        visited[k] = false;
    }
    //cout << "\n";
    int jj = 1;
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) {
            int j = max(jj, i+1);
            while (j < n) {
                if (ar[j] - ar[i] >= z) {
                    ans++;
                    visited[i] = visited[j] = true;
                    jj = j + 1;
                    break;
                } else j++;
            }
            if(j == n) break;
        }
    }
    cout << ans << endl;
    return 0;
}

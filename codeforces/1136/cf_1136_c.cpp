//
// Created by Vinay Saini on 11/03/19.
//

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

bool not_same(vector<int> &v1, vector<int> &v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); ++i) {
        if(v1[i]!=v2[i]) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ar[i][j];
        }
    }
    int ar2[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ar2[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        int i = k;
        vector<int> v1;
        vector<int> v2;
        int j = 0;
        v1.push_back(ar[i][j]);
        v2.push_back(ar2[i][j]);
        while(i-1 >= 0 && j+1 < m) {
            i--;
            j++;
            v1.push_back(ar[i][j]);
            v2.push_back(ar2[i][j]);
        }
        if(not_same(v1, v2)) {
            cout << "NO";
            return 0;
        }
    }

    for (int k = 1; k < m; ++k) {
        vector<int> v1;
        vector<int> v2;
        int i = n-1;
        int j = k;
        v1.push_back(ar[i][j]);
        v2.push_back(ar2[i][j]);
        while(j+1 < m && i-1 >= 0) {
            i--;
            j++;
            v1.push_back(ar[i][j]);
            v2.push_back(ar2[i][j]);
        }
        if(not_same(v1, v2))  {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;

}

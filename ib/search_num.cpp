
//
// Created by Vinay Saini on 05/03/19.
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

void merge(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    A.resize(n+m);
    int k = A.size()-1;
    int i = n-1;
    int j = m-1;
    while(i >= 0 || j >= 0) {
        if(i >=0 && j >= 0) {
            if(A[i] > B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }
        else if(i >= 0) A[k--] = A[i--];
        else A[k--] = B[j--];
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m, 0);
    for (int j = 0; j < m; ++j) {
        cin >> v2[j];
    }
    merge(v, v2);
    for (int k = 0; k < v.size(); ++k) {
        cout << v[k] << " ";
    }
}
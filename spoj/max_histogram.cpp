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

long long max(long long x, long long y) {
    return x > y ? x : y;
}

long long solve(int ar[], int n) {
    if(n <= 0) return 0;
    stack<int> stk;
    long long max_area = -1;
    int i;
    for (i = 0; i < n; ++i) {
        if(stk.empty() || ar[stk.top()] <= ar[i]) stk.push(i);
        else {
            while (!stk.empty() && ar[stk.top()] > ar[i]) {
                long long height = ar[stk.top()];
                stk.pop();
                long long area = stk.empty() ? height * i : height*(i-stk.top()-1);
                max_area = max(max_area, area);
            }
            stk.push(i);
        }
    }
    while (!stk.empty()) {
        long long height = ar[stk.top()];
        stk.pop();
        long long area = stk.empty() ? height * i : height*(i-stk.top()-1);
        max_area = max(max_area, area);
    }
    return max_area;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int ar[n];
        for(int i = 0;i < n; i++) scanf("%d", ar+i);
        long long ans=solve(ar, n);
        printf("%lld\n",ans);
    }
    return 0;
}
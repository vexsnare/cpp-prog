/**
 * http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Greedy/activity.htm
 * In Activity Selection Problem, we’re given a set of activities and the starting & finishing time of each activity, we need to find the maximum number of activities that can be performed by a single person assuming that a person can only work on a single activity at a time.
 */

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
#define  INF (1<<29)
#define fill(ar,val) memset(ar,val,sizeof ar)
#define  min(a,b) ((a)<(b)?(a):(b))
#define  max(a,b) ((a)>(b)?(a):(b))
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

vector<pair<int, int>> solve(vector<pair<int, int>> v) {
    vector<pair<int, int>> ret;

    sort(v.begin(), v.end(), [](const pair<int, int> l, const pair<int, int> &r) { return l.second < r.second; });

    int j = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (j == -1) {
            ret.push_back(v[i]);
            j = i;
        } else {
            if(v[i].first >= v[j].second) {
                ret.push_back(v[i]);
                j = i;
            }
        }
    }
    return ret;
};

int main() {
    vector<pair<int, int>> v;
    int n, st, ft;
    // No. of activities
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> st >> ft;
        v.push_back({st, ft});
    }
    vector<pair<int, int>> result = solve(v);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].first << "," << result[i].second << endl;
    }
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"


double dist(pair<int,int> p1, pair<int, int> p2) {
    return 1.0*sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

vector<pair<int, int>> find_pair_in_strip(vector<pair<int, int>> strip, double d) {
    vector<pair<int, int>> v;
    sort(strip.begin(), strip.end(), [](const pair<int, int> &p, const pair<int, int> &q) {
        return p.second < q.second;
    });
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i+1; j < i+7 && j < strip.size(); ++j) {
            if(dist(strip[i], strip[j]) < d) {
                v.clear();
                v.push_back(strip[i]);
                v.push_back(strip[j]);
                d = dist(strip[i], strip[j]);
            }
        }
    }
    return v;
}

vector<pair<int, int>> find_closest_pair(pair<int, int> ar[], int l, int r) {
    vector<pair<int, int>> ans;
    if(r-l <= 2) {
        pair<int, int> p;
        pair<int, int> q;
        double d = 1.0 * INT_MAX;
        for (int i = l; i <= r; ++i) {
            for (int j = i+1; j <= r; ++j) {
                if(dist(ar[i], ar[j]) < d) {
                    d = dist(ar[i], ar[j]);
                    p = ar[i];
                    q = ar[j];
                }
            }
        }
        ans.push_back(p);
        ans.push_back(q);
    } else {
        int m = (l+r)/2;
        vector<pair<int, int>> points_left = find_closest_pair(ar, l, m);
        vector<pair<int, int>> points_right = find_closest_pair(ar, m+1, r);
        double d1 = dist(points_left[0], points_left[1]);
        double d2 = dist(points_right[0], points_right[1]);
        // make d1 min
        ans = points_left;
        if(d2 < d1){
            d1 = d2;
            ans = points_right;
        }
        vector<pair<int, int>> strip;
        int i = m-1;
        while(i >= l && ar[m].first - ar[i].first < d1) {
                strip.push_back(ar[i]);
                i--;
        }
        i = m+1;
        while (i <= r && ar[i].first - ar[m].first < d1) {
            strip.push_back(ar[i]);
            i++;
        }
        if(strip.size() >= 1) {
            strip.push_back(ar[m]);
            vector<pair<int, int>> points = find_pair_in_strip(strip, d1);
            if (!points.empty()) {
                ans = points;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    pair<int, int> ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i].first;
        cin >> ar[i].second;
    }
    sort(ar, ar+n);
    vector<pair<int, int>> ans = find_closest_pair(ar, 0, n-1);
    cout <<"("<< ans[0].first <<"," << ans[0].second << ")\n";
    cout <<"("<< ans[1].first <<"," << ans[1].second << ")\n";
    cout << dist(ans[0], ans[1]) << "\n";

    return 0;
}
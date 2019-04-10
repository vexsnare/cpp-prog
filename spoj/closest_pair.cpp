#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <stack>
#include <iomanip>


using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define  INT_MAX (1<<30)

struct Point {
    int x, y;
    int index;
    Point(){};
};

double dist(Point p1, Point p2) {
    return sqrt(1ll*(p1.x-p2.x)*(p1.x-p2.x) + 1ll*(p1.y-p2.y)*(p1.y-p2.y));
}

vector<Point> find_pair_in_strip(vector<Point> strip, double d) {
    vector<Point> v;
    double min = d;
    sort(strip.begin(), strip.end(), [](const Point &p, const Point &q) {
        return p.y < q.y;
    });
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i+1; (strip[j].y - strip[i].y) < min && j < strip.size(); ++j) {
            if(dist(strip[i], strip[j]) < min) {
                v.clear();
                v.push_back(strip[i]);
                v.push_back(strip[j]);
                min = dist(strip[i], strip[j]);
            }
        }
    }
    return v;
}

vector<Point> find_closest_pair(Point ar[], int l, int r) {
    vector<Point> ans;
    if(r-l <= 2) {
        Point p;
        Point q;
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
        vector<Point> points_left = find_closest_pair(ar, l, m);
        vector<Point> points_right = find_closest_pair(ar, m+1, r);
        double d1 = dist(points_left[0], points_left[1]);
        double d2 = dist(points_right[0], points_right[1]);
        // make d1 min
        ans = points_left;
        if(d2 < d1){
            d1 = d2;
            ans = points_right;
        }
        vector<Point> strip;
        int i = m-1;
        while(i >= l && ar[m].x - ar[i].x < d1) {
                strip.push_back(ar[i]);
                i--;
        }
        i = m+1;
        while (i <= r && ar[m].x - ar[i].x < d1) {
            strip.push_back(ar[i]);
            i++;
        }
        if(strip.size() >= 1) {
            strip.push_back(ar[m]);
            vector<Point> points = find_pair_in_strip(strip, d1);
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
    Point ar[n];
    for (int i = 0; i < n; ++i) {
        cin >> ar[i].x;
        cin >> ar[i].y;
        ar[i].index = i;
    }
    sort(ar, ar+n, [](const Point &p, const Point &q){
        return p.x == q.x ? p.y < q.y : p.x < q.x;
    });
    vector<Point> ans = find_closest_pair(ar, 0, n-1);
    if(ans[0].index > ans[1].index) swap(ans[0], ans[1]);
    cout << ans[0].index << " " << ans[1].index << " ";
    //printf("%6f\n", dist(ans[0], ans[1]));
    cout << setprecision(6) << fixed << dist(ans[0], ans[1]);

    return 0;
}
/**
 * Convex Hull
 * MONOTONE CHAIN
 * https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
 * O (nLogn)
 *
 */
/* Input
 * 6
0 0 0 4 -4 0 5 0 0 -6 1 0
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

struct Point {
    int x, y;
    Point(){};
    Point (int x, int y) {
        this-> x = x;
        this-> y = y;
    }
};
class Compare {
public:
    bool operator()(const Point &p, const Point &q) {
        return p.x == q.x ? p.y < q.y : p.x < q.x;
    }
};
int findSide(Point p1, Point q1, Point p) {
    return (p.y - p1.y)*(q1.x - p1.x) - (p.x - p1.x)*(q1.y - p1.y);
}

vector<Point> findPointsInHull(const vector<Point> &points) {
    int n = points.size();
    vector<Point> ans(2*n);
    if(n <= 3) return ans;

    int i = 0;
    for (int j = 0; j < n; ++j) {
        while(i >= 2 && findSide(ans[i-2], ans[i-1], points[j]) >= 0) i--;
        ans[i++] = points[j];
    }
    int k = i;
    for (int j = n-2; j >= 0; --j) {
        while(i >= k+1 && findSide(ans[i-2], ans[i-1], points[j]) >= 0) i--;
        ans[i++] = points[j];
    }
    ans.resize(i-1);
    // add in answer vector
    return ans;
}

/*
 * n - number of points
 */
int main() {
    int n;
    cin >> n;
    vector<Point> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    sort(v.begin(), v.end(), Compare());
    vector<Point> ans = findPointsInHull(v);

    // Print answer
    for (int i = 0; i < ans.size(); ++i) {
        cout << "(" << ans[i].x << "," << ans[i].y << ")" << endl;
     }
    return 0;
}
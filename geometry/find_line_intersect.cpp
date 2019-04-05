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
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// find orientation of a point p from line p1-q1
// this is diff in slope
int findOrientation(Point p1, Point q1, Point p) {
    int o = (p.y - p1.y)*(q1.x - p1.x) - (q1.y - p1.y)*(p.x - p1.x);
    if(o == 0) return o;
    return o > 0 ? 1: 2;
}

bool isOnTheLine(Point p1, Point q1, Point p) {
    return p.x >= min(p1.x, q1.x) && p.x <= max(p1.x, q1.x) &&
            p.y >= min(p1.y, q1.y) && p.y <= max(p1.y, q1.y);
}

bool isIntersect(Point p1, Point q1, Point p2, Point q2) {
    // p1 q1 orientation with p2
    int o1 = findOrientation(p1, q1, p2);
    // p1 q1 orientation with q2
    int o2 = findOrientation(p1, q1, q2);
    // p2 q2 orientation with p1
    int o3 = findOrientation(p2, q2, p1);
    // p2 q2 orientation with q1
    int o4 = findOrientation(p2, q2, q1);

    if(o1 != o2 && o3 != o4) return true;

    if(o1 == 0 && isOnTheLine(p1, q1, p2)) return true;
    if(o2 == 0 && isOnTheLine(p1, q1, q2)) return true;
    if(o3 == 0 && isOnTheLine(p2, q2, p1)) return true;
    if(o4 == 0 && isOnTheLine(p2, q2, q1)) return true;

    return false;
}

int main() {
    // Enter p1, q1 for line 1
    int x, y;
    cin >> x >> y;
    Point p1(x, y);

    cin >> x >> y;
    Point q1(x, y);

    // Enter p2, q2 for line 2
    cin >> x >> y;
    Point p2(x, y);

    cin >> x >> y;
    Point q2(x, y);

    cout << (isIntersect(p1, q1, p2, q2) ? "Yes" : "No") << "\n";

    return 0;
}
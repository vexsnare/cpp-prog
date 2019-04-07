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
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct Rectangle {
    Point p, q;
    Rectangle(Point p1, Point q1) {
        this->p = p1;
        this->q = q1;
    }
};

bool isIntersect(Rectangle r1, Rectangle r2) {
    if(r2.p.x > r1.q.x || r2.q.x < r1.p.x) return false; // check if r2 is out of r1 horizontally
    if(r2.p.y < r1.q.y || r2.q.y > r1.p.y) return false; // check if r2 is out of r1 vertically
    if((r2.p.x > r1.p.x && r2.q.x < r1.q.x) || (r2.q.y > r1.q.y && r2.p.y < r1.p.y)) return false; // r2 is inside r2
    return true;
 }

int main() {
    // rectangle 1
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rectangle1 = Rectangle(Point(x1, y1), Point(x2, y2));

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rectangle2 = Rectangle(Point(x1, y1), Point(x2, y2));

    cout << (isIntersect(rectangle1, rectangle2) ? "Yes": "No")<< "\n";

    return 0;
}
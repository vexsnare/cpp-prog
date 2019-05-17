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

#define INF (1<<29)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

/*
 * https://www.hackerrank.com/challenges/truck-tour/problem
 * Amazon Interview
 */


// https://stackoverflow.com/questions/2286849/algorithm-for-truck-moving-around-a-circle-of-gas-stations
int solve(int petrol[], int dist[], int n) {
    int current_petrol = 0;
    int start;
    int min_petrol = INF;
    for (int i = 0; i < n; ++i) {
        current_petrol += petrol[i] - dist[i];
        if(current_petrol < min_petrol) {
            min_petrol = current_petrol;
            start = (i+1)%n;
        }
    }
    if(current_petrol > 0) return start;
    return -1;
}

int main() {
    int n;
    cin >> n;
    int petrol[n];
    int dist[n];
    int start = solve(petrol, dist, n);
    printf("%d\n", start);
    return 0;
}

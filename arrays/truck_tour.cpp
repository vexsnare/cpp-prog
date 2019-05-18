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


// Sol1:
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

//Sol2:
//https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
int solve2(int petrol[], int dist[], int n) {
    int start = 0;
    int i = 0;
    int current_petrol = 0;
    while(start < n) {
        current_petrol += petrol[i]-dist[i];
        while (current_petrol < 0 && start < i) {
            current_petrol -= petrol[start]-dist[start];
            start++;
        }
        if(current_petrol < 0) {
            current_petrol = 0;
            start++;
            i++;
            continue;
        }
        if(i+1%n == start) {
            return start;
        } else {
            i = (i+1)%n;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    int petrol[n];
    int dist[n];
    for (int i = 0; i < n; ++i) {
        cin >> petrol[i] >> dist[i];
    }
    int start = solve2(petrol, dist, n);
    printf("%d\n", start);
    return 0;
}

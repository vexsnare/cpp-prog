//
// Created by Vinay Saini on 2019-06-19.
//

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
#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, less<int> > pq;
    int x;
    int sum = 0;
    int count = 0;
    deque<int> temp;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(sum + x <= m) {
            cout << count << " ";
        } else {
            int ss = 0;
            while(!temp.empty() && sum + x > m) {
                int t = pq.top();
                sum -= pq.top();
                temp.push_back(pq.top());
                pq.pop();
                count++;
            }
            while(!pq.empty() && sum + x > m) {
                int t = pq.top();
                sum -= pq.top();
                temp.push_front(pq.top());
                pq.pop();
                count++;
            }
            for (int j = 0; j < temp.size(); ++j) {
                sum += temp[j];
                pq.push(temp[j]);
            }
            cout << count << " ";
            count = 0;
        }
        for (int j = 0; j < n && temp[j] < x; ++j) {
            pq.push(temp[j]);
            temp.pop_front();
            sum += temp[j];
        }
        temp.push_front(x);
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"

int setBitCount(int x) {
    bitset<30> b(x);
    return b.count();
}

int main() {
    int x;
    cin >> x;
    vector<int> opr;
    int count = 1;
    while(setBitCount(x + 1) != 1 && count <= 40) {
        if(count%2) {
            int temp = x;
            int pos = 0;
            while (setBitCount(temp+1) != 1) {
                pos++;
                temp = temp >> 1;
            }
            opr.push_back(pos);
            x ^= (1<<pos) - 1;
        } else {
            x += 1;
        }
        count++;
    }
    cout << count-1 << "\n";
    for (int i = 0; i < opr.size(); ++i) {
        cout << opr[i] << " ";
    }
    return 0;
}
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

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int x = a/3;
    x = min (x, b/2);
    x = min (x, c/2);
    ans += x*7;
    a -= x*3;
    b -= x*2;
    c -= x*2;
    int days[] = {0, 1, 2, 0, 2, 1, 0};
    int max_days = -1;
    for (int i = 0; i < 7; ++i) {
        int aa = a;
        int bb = b;
        int cc = c;
        int day = i;
        int temp_days = 0;
        while (aa > 0 || bb > 0 || cc > 0) {
            if(days[day] == 0) {
                if(aa > 0) {
                    aa--;
                    temp_days++;
                } else {
                    break;
                }
            }
            else if(days[day] == 1) {
                if(bb > 0) {
                    bb--;
                    temp_days++;
                } else {
                    break;
                }
            } else if(days[day] == 2) {
                if(cc > 0) {
                    cc--;
                    temp_days++;
                } else {
                    break;
                }
            }
            day++;
            day %= 7;
        }
        max_days = max(max_days, temp_days);
    }
    cout << ans + max_days;
    return 0;
}
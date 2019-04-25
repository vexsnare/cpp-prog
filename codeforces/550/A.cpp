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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ii = 0;
    char max_char = s[0];
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] < max_char) {
            printf("YES\n");
            cout << ii + 1 << " " << i + 1 << "\n";
            return 0;
        }
        if (s[i] > max_char) {
            max_char = s[i];
            ii = i;
        }
    }
    printf("NO");
    return 0;
}
/*
 * Find longest palindrome in O(n)
 * Best explanation
 * https://www.youtube.com/watch?v=nbTSfrEfo6M
 */

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

int solve(string s) {
    int ans = 1;
    int n = s.length();
    int ln[n];
    memset(ln, 0, sizeof(ln));
    int ii = 0; // longest palindrome index
    int rr = 0; // right index of palindrome at ii
    for (int i = 1; i < n; ++i) {
        int mirror_index = 2*ii - i;
        if(i < rr) {
            ln[i] = min(rr-i, ln[mirror_index]);
        }
        int l = i - ln[i] - 1;
        int r = i + ln[i] + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            ln[i]++;
            l--;
            r++;
        }
        r--; // one more because of above condition
        if(r > rr) {
            ii = i;
            rr = r;
            ans = max(ans, ln[i]);
        }
    }
    return ans;

}

int main() {
    string s;
    cin >> s;
    string str = "";
    for (int i = 0; i < s.length(); ++i) {
            str += ';';
            str += s[i];
    }
    str += ';';
    // Adding $ to handle case of even length palindrome
    // ie. AB => $A$B$
    int length = solve(str);
    printf("%d", length);
}
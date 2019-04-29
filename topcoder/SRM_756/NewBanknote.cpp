#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class NewBanknote {
public:

    int countCoins(int ar[], int sz, int x) {
        int ans = 0;
        for (int i = sz-1; i >= 0; --i) {
            if(ar[i] <= x) {
                ans += x / ar[i];
                x %= ar[i];
            }
        }
        return ans;
    }
	vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay) {
        vector<int> result;
        int ar[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
        int sz = 15;
        for (int i = 0; i < amountsToPay.size(); ++i) {
            int minCoins = countCoins(ar, sz, amountsToPay[i]);
            for (int j = 1; j <= 50000; ++j) {
                if(1ll*j*newBanknote > amountsToPay[i]) break;
                minCoins = min(minCoins, countCoins(ar, sz, amountsToPay[i] - j*newBanknote) + j);
            }
            result.push_back(minCoins);
        }
		return result;
	}
};

bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, vector <int> p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    NewBanknote *obj;
    vector <int> answer;
    obj = new NewBanknote();
    clock_t startTime = clock();
    answer = obj->fewestPieces(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p2.size()) > i; ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << p2[i];
        }
        cout << "}" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(answer.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "}" << endl;
    if (hasAnswer) {
        if (answer.size() != p2.size()) {
            res = false;
        } else {
            for (int i = 0; int(answer.size()) > i; ++i) {
                if (answer[i] != p2[i]) {
                    res = false;
                }
            }
        }
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    vector <int> p1;
    vector <int> p2;

    {
        // ----- test 0 -----
        p0 = 4700;
        int t1[] = {53,9400,9401,30000};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {3,2,3,2};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 1234;
        int t1[] = {1233,1234,1235};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {6,1,2};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 1000;
        int t1[] = {1233,100047};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {6,6};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

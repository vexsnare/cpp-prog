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

#define MOD 1000000007

#define IMAX 2147483648
#define min(a,b) ((a)<(b)?(a):(b))



class ETSums {
public:

    int pow(int x, int r) {
        int result = x;
        for (int i = 0; i < r-1; ++i) {
            result *= x;
            result %= MOD;
        }
        return result;
    }

    int counter = 1;
    int NN;
    vector<int> P;
    vector<int> C;
    vector<int> T;
    int dfs(int i) {
        T[i] = counter;
        counter += 1;
        for (int j = 0; j < NN; ++j) {
            if(P[j] == i) {
                dfs(j);
            }
        }
    }

	int findSumOfETSums(int N, vector <int> parent, vector <int> cost, int D, int seed, int MX) {
	    int A[2*N];
	    NN = N;
	    A[0] = seed;
        for (int i = 0; i < 2*N-1; ++i) {
            A[i] = (A[i-1]*1103515245 + 12345) % IMAX;
        }
        P = parent;
        for (int i = P.size(); i < N; ++i) {
            P[i] = (A[i]% min(i, D)) + i - min(i, D);
        }
        C = cost;
        for (int i = C.size(); i < N; ++i) {
            C[i] = A[N+i] % MX;
        }
        T.resize(N);
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < P.size(); ++j) {
               // if(P[j] == i) {
                    ans += (1ll*C[i] * pow(j, T[i]))%MOD;
                //}
            }
        }
        return ans;

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	ETSums *obj;
	int answer;
	obj = new ETSums();
	clock_t startTime = clock();
	answer = obj->findSumOfETSums(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p3;
	int p4;
	int p5;
	int p6;
	
	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {-1,0,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,3,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 0;
	p5 = 5;
	p6 = 405;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	int t1[] = {-1,0,0,1,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5,0,3,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 0;
	p5 = 6;
	p6 = 294;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	int t1[] = {-1,0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {3,2,3,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 0;
	p5 = 4;
	p6 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	int t1[] = {-1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2.clear() /*{}*/;
	p3 = 7;
	p4 = 176;
	p5 = 15;
	p6 = 2425;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100000;
	int t1[] = {-1,0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 0;
	p5 = 1000000000;
	p6 = 412779665;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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

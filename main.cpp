
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
#define  INF (1<<29)
#define fill(ar,val) memset(ar,val,sizeof ar)
#define  min(a,b) ((a)<(b)?(a):(b))
#define  max(a,b) ((a)>(b)?(a):(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main() {
    std::cout << "Hello, World!" << std::endl;
    set<int> s;
    s.insert(4);
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << endl;
    }
    return 0;
}
//
// Created by Vinay Saini on 2019-06-18.
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

/**
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * @param MAX
 * @return primes upto MAX
 */
vector<int> generate_primes(int MAX) {
    assert(MAX <= 1e6);
    int upper_bound = min(MAX+1, 1e6);
    vector<int> result;
    vector<bool> primes(upper_bound, true);
    primes[0] = primes[1] = false;
    for (int i = 0; i*i < upper_bound; ++i) {
        if(primes[i]) {
            for (int j = i*i; j < upper_bound; j+=i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 0; i < upper_bound; ++i) {
       if(primes[i]) {
           result.push_back(i);
       }
    }
    return result;
}


int main() {
    vector<int> primes = generate_primes(7);
    for (int i = 0; i < primes.size(); ++i) {
        cout << primes[i] << " ";
    }
    cout << endl;
    return 0;
}
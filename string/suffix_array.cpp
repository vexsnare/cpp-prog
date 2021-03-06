//
// Created by Vinay Saini on 2019-05-17.
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
struct Tuple {
    int index;
    pair<int, int> p;
    Tuple(int index, pair<int, int> p) {
        this->index = index;
        this->p = p;
    }
    bool operator<(const Tuple& t2) const
    {
        if(p.first == t2.p.first) {
            return p.second < t2.p.second;
        }
        return p.first < t2.p.first;
    }
    Tuple(){};
};

// Or pass this function in sort
bool compareTuple(const Tuple &t1, const Tuple &t2) {
    if(t1.p.first == t2.p.first) {
        return t1.p.second < t2.p.second;
    }
    return t1.p.first < t2.p.first;
}

vector<int> findSuffixArray(string s) {
    int n = s.length();
    int ranks[n];
    struct Tuple metaArray[n];
    for (int i = 0; i < n; ++i) {
        metaArray[i] = Tuple(i, {s[i], i+1 < n ? s[i+1]: -1});
    }
    sort(metaArray, metaArray+n);

    for (int k = 2; k < n; k *= 2) {
        int rank = 0;
        for (int i = 0; i < n; ++i) {
            if(i > 0 && metaArray[i].p.first != metaArray[i-1].p.first || metaArray[i].p.second != metaArray[i-1].p.second) {
                rank++;
            }
            ranks[metaArray[i].index] = rank;
        }

        for (int i = 0; i < n; ++i) {
            metaArray[i].p.first = ranks[metaArray[i].index];
            metaArray[i].p.second = metaArray[i].index + k < n ? ranks[metaArray[i].index + k]: -1;
        }
        sort(metaArray, metaArray + n);
    }
    vector<int> suffixArray;
    for (int i = 0; i < n; ++i) {
        suffixArray.push_back(metaArray[i].index);
    }
    return suffixArray;
}

//LCP Array - O(n) Algo from SuffixArray
//https://codeforces.com/blog/entry/12796#comment-175287
//https://cp-algorithms.com/string/suffix-array.html
vector<int> lcpKasaiAlgo(string s, vector<int> &suffixArray) {
    int n = suffixArray.size();
    int ranks[n];
    for (int i = 0; i < n; ++i) {
        ranks[suffixArray[i]] = i;
    }
    int k = 0;
    vector<int> lcp(n, 0);
    // i is index in original string
    for (int i = 0; i < n; ++i) {
        if(ranks[i] == n-1) {
            lcp[i] = 0;
            continue;
        }
        // Next suffix's Index in original string which is next in suffixArray after i
        int j = suffixArray[ranks[i]+1];
        while (i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        lcp[ranks[i]] = k;
        if(k > 0) k--;
    }
    return lcp;
}

int main() {
    string s = "aabca";
   // cin >> s;
    vector<int> suffixArray = findSuffixArray(s);

    //Print Answer
    for (int i = 0; i < suffixArray.size(); ++i) {
        cout << suffixArray[i] << " ";
    }
    printf("\n");

    vector<int> lcpArray = lcpKasaiAlgo(s, suffixArray);
    //Print LCP Array
    for (int i = 0; i < lcpArray.size() - 1; ++i) {
        cout << lcpArray[i] << " ";
    }

    return 0;
}


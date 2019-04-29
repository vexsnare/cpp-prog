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
#include <bitset>
#include <queue>

using namespace std;

#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define   REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define  INF (1<<29)
#define 	all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define       min(a,b) ((a)<(b)?(a):(b))
#define         max(a,b) ((a)>(b)?(a):(b))
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<string> vs;

#define MAX_CHAR 256

struct Node {
    int start;
    int *end;
    Node *child[MAX_CHAR];

    Node(int start, int *end) {
        this->start = start;
        this->end = end;
        memset(child, NULL, sizeof(child));
    }
    Node *suffixLink = NULL;
};

class SuffixTree {
    int remainingSuffixes = 0;

    int activeLength = 0;
    Node *activeNode = NULL;
    int activeEdge = -1;

    Node *lastCreatedNode = NULL;

    string s;
    Node *root;
    int *end;
public:
    SuffixTree(string s) {
        this->s = s;
        this->end = new int(-1);
        this->root = new Node(-1, end);
        activeNode = root;
    }

    bool walkDown(Node *node) {
        int edgeLength = *(node->end) - node->start + 1;
        if (activeLength >= edgeLength) {
            activeNode = node;
            activeEdge += edgeLength;
            activeLength -= edgeLength;
            return true;
        }
        return false;
    }
    void createSuffixLink(Node *node) {
        if(node == root) return;
        if(lastCreatedNode != NULL) {
            lastCreatedNode->suffixLink = node;
        }
        lastCreatedNode = node;
    }

    void extendTree(int i) {
        remainingSuffixes++;
        *end = i;
        lastCreatedNode = NULL;
        while (remainingSuffixes > 0) {
            if(activeLength == 0) {
                activeEdge = i;
            }
            char activeEdgeChar = s[activeEdge];
            if(activeNode->child[activeEdgeChar] == NULL) {
                activeNode->child[activeEdgeChar] = new Node(i, end);
                createSuffixLink(activeNode);
            } else {
                Node *next = activeNode->child[activeEdgeChar];
                if(walkDown(next)) continue;
                if(s[next->start + activeLength] == s[i]) {
                    activeLength++;
                    createSuffixLink(activeNode);
                    break;
                }
                int *splitEnd = new int(next->start + activeLength - 1);
                Node *split = new Node(next->start, splitEnd);

                Node *leaf = new Node(i, end);
                split->child[s[i]] = leaf;

                next->start = next->start + activeLength;
                split->child[s[next->start]] = next;

                activeNode->child[activeEdgeChar] = split;
                createSuffixLink(split);
            }
            remainingSuffixes--;
            if(activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = i - remainingSuffixes + 1;
            } else {
                activeNode = activeNode->suffixLink != NULL ? activeNode->suffixLink : root;
            }
        }
    }

    void dispLink(Node *current) {
        cout << "[ " << current->start << ", " << *(current->end) << " ] -> ";
        for (int i = current->start; i <= *(current->end); ++i) {
            cout << s[i];
        }

    }

    void print(Node *current) {
        cout << "[ " << current->start << ", " << *(current->end) << " ] -> ";
        for (int i = current->start; i <= *(current->end); ++i) {
            cout << s[i];
        }
        if (current->suffixLink != NULL) {
            printf("\nHas suffix link ----- > to ");
            dispLink(current->suffixLink);
        }
        cout << "\n";
        for (int i = 0; i < MAX_CHAR; ++i) {
            if(current->child[i] != NULL) {
                print(current->child[i]);
            }
        }
    }


    void build() {
        for (int i = 0; i < s.length(); ++i) {
            extendTree(i);
        }
        print(root);
    }
    vector<char> ans;
    string qs;

    bool findNext(int i, Node *current) {
        if(current->child[qs[i]] == NULL) {
            for (int i = 0; i < MAX_CHAR; ++i) {
                if(current->child[i] != NULL && qs[i] < i) {
                    ans.push_back(i);
                    return true;
                }
            }
            return false;
        } else {
            int l = current->start;
            int r = *(current->end);
            for (int k = l; k <= r; ++k) {
                if(qs[i] == s[k]) {
                    ans.push_back(s[k]);
                    i++;
                } else {
                    if(qs[i] < s[k]) {
                        ans.push_back(s[k]);
                        return;
                    } else {
                        found = false;
                        return;
                    }
                }
            }
            findNext(i, current->child[qs[i]]);
        }
    }

};

int main() {
    string s = "$";
    cin >> s;
    SuffixTree suffixTree(s);
    suffixTree.build();
    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        string nextStr = suffixTree.findNext();
        cout << nextStr << endl;
    }

}
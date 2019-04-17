//
// Created by Vinay Saini on 17/04/19.
//
/**
 * Video: Tushor Roy
 * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-6/
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <cstring>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<"\n"
#define MAX_CHAR 256

/**
 * Suffix Tree Node
 */
struct Node {
    struct Node *children[MAX_CHAR];
    struct Node *suffixLink;
    int start;
    int *end;
    int suffixIndex;
};

char text[100];

Node *root = NULL;
Node *lastNewNode = NULL;

Node *activeNode = NULL;
int activeEdge = -1;
int activeLength = 0;

int remainingSuffixCount = 0;
int leafEnd = -1;
Node *rootEnd = NULL;
Node *splitEnd = NULL;
int size = -1;

Node *newNode(int start, int *end) {
    Node *node = new Node();
    int i;
    for (i = 0; i < MAX_CHAR; ++i) {
        node->children[i] = NULL;
    }
    node->suffixLink = root;
    node->start = start;
    node->end = end;

    node->suffixIndex = -1;
    return node;
}

int edgeLength(Node *node) {
    return *(node->end) - (node->start) + 1;
}

int walkDown(Node *node) {
    if(activeEdge >= edgeLength(node)) {
        activeEdge += edgeLength(node);
        activeLength -= edgeLength(node);
        activeNode = node;
        return 1;
    }
    return 0;
}

void extendSuffixTree(int pos) {
    leafEnd = pos;
    remainingSuffixCount++;
    lastNewNode = NULL;
    while (remainingSuffixCount > 0) {
        if(activeLength == 0) {
            activeEdge = pos;
        }
        if(activeNode->children[pos] == NULL) {
            activeNode->children[pos] = newNode(pos, &leafEnd);
            if(lastNewNode != NULL) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;
            }
        } else {
            Node *next = activeNode->children[pos];
            if(walkDown(next)) continue;
            if(text[next->start + activeLength] == text[pos]) {
                if(lastNewNode != NULL && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;
                }
                activeLength++;
                break;
            }
            int *splitEnd = new int;
            *splitEnd = next->start + activeLength - 1;

            Node *split = newNode(next->start, splitEnd);
            activeNode->children[pos] = split;
            split->children[pos] = newNode(pos, &leafEnd);
            next->start  += activeLength;
            split->children[pos] = next;

            if(lastNewNode != NULL) {
                lastNewNode->suffixLink = split;
            }
            lastNewNode = split;
        }
        remainingSuffixCount--;
        if(activeLength > 0  && activeNode == root) {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        } else if(activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

void print(int i, int j) {
    for (int k = i; k <= j; ++k) {
        cout << text[k];
    }
    cout << endl;
}

void setSuffixIndexByDFS(Node *node, int labelHeight) {
    if(node == NULL) return;
    if(node->start != -1) {
        print(node->start, *(node->end));
    }
    int leaf = 1;
    for (int i = 0; i < MAX_CHAR; ++i) {
        if(node->children[i] != NULL) {
            if(leaf == 1 && node->start != -1) {
                printf("[%d]\n",node->suffixIndex);
            }
            leaf = 0;
            setSuffixIndexByDFS(node->children[i], labelHeight + edgeLength(node->children[i]));
        }
        if(leaf == 1) {
            node->suffixIndex = size - labelHeight;
            printf("[%d]\n", node->suffixIndex);
        }
    }
}

void freeSuffixTreeByPostOrder(Node *node) {
    if(node == NULL) return;
    for (int i = 0; i < MAX_CHAR; ++i) {
        if(node->children[i] != NULL) {
            freeSuffixTreeByPostOrder(node->children[i]);
        }
    }
    if(node->suffixIndex == -1) {
        delete node->end;
    }
    delete node;
}

void buildSuffixTree() {
    int size = strlen(text);
    int *rootEnd = new int;
    *rootEnd = -1;

    root = newNode(-1, rootEnd);

    activeNode = root;
    for (int i = 0; i < size ; ++i) {
        extendSuffixTree(i);
    }
    int labelHeight = 0;
    setSuffixIndexByDFS(root, labelHeight);
    freeSuffixTreeByPostOrder(root);
}

int main() {
    strcpy(text, "abcabxabcd$");
    buildSuffixTree();
    return 0;
}
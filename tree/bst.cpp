//
// Created by Vinay Saini on 15/01/19.
//
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

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode (int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BST {

    TreeNode *root;

public:


    BST() {
        root = nullptr;
    }

    void insertValue(TreeNode *cur, int value) {
        if(cur == nullptr) {
            root = new TreeNode(value);
            return;
        }
        if (value < cur->value) {
            if(cur->left == nullptr) cur->left = new TreeNode(value);
            else insertValue(cur->left, value);
        } else {
            if (cur->right == nullptr) cur->right = new TreeNode(value);
            else insertValue(cur->right, value);
        }
    }

    void preOrderTraversal(TreeNode *cur) {
        if (cur == nullptr) {
            cout << endl;
            return;
        }
        cout << cur->value << ", ";
        if(cur->left != nullptr) preOrderTraversal(cur->left);
        if(cur->right != nullptr) preOrderTraversal(cur->right);
    }

    void inOrderTraversal(TreeNode *cur) {
        if (cur == nullptr) {
            cout << endl;
            return;
        }
        if(cur->left != nullptr) inOrderTraversal(cur->left);
        cout << cur->value << ", ";
        if(cur->right != nullptr) inOrderTraversal(cur->right);
    }

    TreeNode* getRoot() {
        return this->root;
    }

    int countNodeOnGivenHeight(TreeNode *cur, int height) {
        if(cur == nullptr) return 0;
        if(height == 0) return 1;
        int leftCount = cur->left == nullptr ? 0 : countNodeOnGivenHeight(cur->left, height - 1);
        int rightCount = cur->right == nullptr ? 0 : countNodeOnGivenHeight(cur->right, height - 1);
        return leftCount + rightCount;
    }

};

int main() {
    BST bst = BST();
    int ar[] = {5, 3, 2 , 4, 7, 6, 8, 1};
    int n = sizeof(ar) / sizeof(int);
    for (int i = 0; i < n; ++i) {
        bst.insertValue(bst.getRoot(), ar[i]);
    }
    bst.preOrderTraversal(bst.getRoot());
    cout << "\n";
    bst.inOrderTraversal(bst.getRoot());
    cout << "\n";
    cout << bst.countNodeOnGivenHeight(bst.getRoot(), 3);


}
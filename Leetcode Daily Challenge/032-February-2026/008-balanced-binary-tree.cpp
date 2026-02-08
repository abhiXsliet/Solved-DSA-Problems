// https://leetcode.com/problems/balanced-binary-tree/




#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int height(TreeNode* root) {
        if (!root) return 0;

        int L = height(root -> left);
        if (L == -1) return -1;

        int R = height(root -> right);
        if (R == -1) return -1;

        if (abs(L - R) > 1) return -1;

        return 1 + max(L, R);
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
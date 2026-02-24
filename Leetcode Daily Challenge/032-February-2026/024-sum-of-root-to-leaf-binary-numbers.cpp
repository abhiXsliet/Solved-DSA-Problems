// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/




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
public:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        // build binary number
        curr = (curr << 1) | node->val;

        // if leaf node
        if (!node->left && !node->right)
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
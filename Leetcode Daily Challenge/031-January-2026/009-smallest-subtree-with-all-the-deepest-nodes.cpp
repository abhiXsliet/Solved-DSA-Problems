// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/




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
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (!root) return {0, NULL};

        auto L = solve(root -> left);
        auto R = solve(root -> right);

        if (L.first == R.first) {
            return {L.first + 1, root};
        } else if (L.first > R.first) {
            return {L.first + 1, L.second};
        } 
        return {R.first + 1, R.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};
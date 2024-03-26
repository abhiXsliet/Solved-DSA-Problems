// https://leetcode.com/problems/invert-binary-tree/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // TC : O(N)
    // SC : O(H) H could be N if the tree is skewed otherwise it will be log(N) if tree is balanced
    TreeNode* solve_1(TreeNode* root) {
        if (!root) return NULL;

        TreeNode* temp = root -> left;
        root -> left   = solve_1(root -> right);
        root -> right  = solve_1(temp);

        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return solve_1(root);
    }
};
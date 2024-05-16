// https://leetcode.com/problems/evaluate-boolean-binary-tree/



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
    // SC : O(H) -> Height of Tree
    bool solve_1(TreeNode* root) {
        if (!root -> left && !root -> right)
            return root -> val;

        if (root -> val == 3) 
            return solve_1(root -> left) & solve_1(root -> right);
        
        // root -> val == 2, so do OR
        return solve_1(root -> left) | solve_1(root -> right);
    }

    // TC : O(N)
    // SC : O(H) -> Height of Tree
    bool solve_2(TreeNode* root) {
        if (!root -> left && !root -> right)
            return root -> val;

        int left  = solve_2(root -> left);
        int right = solve_2(root -> right);

        if (root -> val == 2) {
            return left | right;
        }
        return left & right;
    }
public:
    bool evaluateTree(TreeNode* root) {
        // return solve_1(root);

        return solve_2(root);
    }
};
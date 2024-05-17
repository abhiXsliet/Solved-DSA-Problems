// https://leetcode.com/problems/delete-leaves-with-a-given-value/



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
public:
    // TC : O(N)
    // SC : O(H) -> Height of Tree
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return NULL;

        root -> left  = removeLeafNodes(root -> left , target);
        root -> right = removeLeafNodes(root -> right, target);

        if (!root -> left && !root -> right && root -> val == target) 
            return NULL;

        return root;
    }
};
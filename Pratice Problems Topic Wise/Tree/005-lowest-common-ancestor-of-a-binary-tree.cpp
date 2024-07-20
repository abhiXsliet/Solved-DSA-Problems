// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        if (root -> left == p || root -> right == q) 
            return root;

        TreeNode* lNode = LCA(root -> left , p, q);
        TreeNode* rNode = LCA(root -> right, p, q);

        if (lNode && rNode) return root;

        if (!rNode) return lNode;
        return rNode;
    }
};
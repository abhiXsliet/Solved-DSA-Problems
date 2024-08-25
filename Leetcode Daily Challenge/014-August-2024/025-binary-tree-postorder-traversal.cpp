// https://leetcode.com/problems/binary-tree-postorder-traversal/



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
    void postOrder(TreeNode* root, vector<int>& result) {
        if (!root) return;

        postOrder(root -> left, result);
        postOrder(root -> right, result);
        result.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};
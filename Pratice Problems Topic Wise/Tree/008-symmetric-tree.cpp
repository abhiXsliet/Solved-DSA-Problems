// https://leetcode.com/problems/symmetric-tree/




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
private:
    // TC : O(N)
    // SC : O(H) Due to recursive depth
    bool solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) 
            return true;
        if (!root1 || !root2 || (root1 -> val != root2 -> val))
            return false;
        
        return solve(root1 -> left, root2 -> right) && 
                solve(root1 -> right, root2 -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right);
    }
};
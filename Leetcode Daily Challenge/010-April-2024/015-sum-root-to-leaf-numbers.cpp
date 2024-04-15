// https://leetcode.com/problems/sum-root-to-leaf-numbers/



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
    // SC : O(H) -> Recursive Depth
    int solve(TreeNode* root, int curr) {
        if(!root) return 0;

        curr = curr * 10 + root -> val;
        if (!root -> left && !root -> right) 
            return curr;
        
        int left  = solve(root -> left , curr);
        int right = solve(root -> right, curr);

        return (left + right);
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};
// https://leetcode.com/problems/diameter-of-binary-tree/



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
    // SC : O(H)
    int height(TreeNode* root) {
        if (!root) return 0;

        int left  = height(root -> left);
        int right = height(root -> right);
        
        return 1 + max(left, right);
    }

    // TC : O(N^2)
    // SC : O(H)
    int solve_1(TreeNode* root) {
        if (!root) return 0;

        int option_1 = solve_1(root -> left);
        int option_2 = solve_1(root -> right);
        
        int option_3 = height(root -> left) + height(root -> right);

        return max({option_1, option_2, option_3});
    }

    // TC : O(N)
    // SC : O(H)
    pair<int, int> solve_2(TreeNode* root) {
        if (!root) {
            return {0, 0}; // {diameter, height}
        }

        pair<int, int> left  = solve_2(root -> left);
        pair<int, int> right = solve_2(root -> right);

        // Diameter Lies in the left subtree only
        int option_1 = left.first;
        // Diameter Lies in the right subtree only
        int option_2 = right.first;
        // Height of Left and Right Subtree
        int option_3 = left.second + right.second; 

        return {max({option_1, option_2, option_3}), (1 + max(left.second, right.second))};
    }

    // TC : O(N)
    // SC : O(H)
    int solve_3(TreeNode* root, int& result) {
        if (!root) return 0;

        int left  = solve_3(root -> left , result);
        int right = solve_3(root -> right, result);

        // might be largest diameter found in the either left or right subtree
        result = max(result, left + right); 
        
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // return solve_1(root);

        // return solve_2(root).first;
        
        int result = INT_MIN;
        solve_3(root, result);
        return result;
    }
};
// https://leetcode.com/problems/range-sum-of-bst/



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
    // TC : O(N) -> Going to each node once
    // SC : O(H) -> Recursive Depth
    int solve_brute(TreeNode* root, int low, int high, int& sum) {
        if (root == NULL) return 0;

        solve_brute(root -> left, low, high, sum);

        if (root -> val >= low && root -> val <= high) 
            sum += root -> val;

        solve_brute(root -> right, low, high, sum);

        return sum;
    }
    
    // TC : O(N) -> At worst going to each node once since complexity depends upons given range 
    // SC : O(H) -> Recursive Depth
    int solve_optimal(TreeNode* root, int low, int high, int& sum) {
        if (!root) return 0;

        if (root -> val >= low) 
            solve_optimal(root -> left, low, high, sum);

        if (root -> val >= low && root -> val <= high)
            sum += root -> val;
        
        if (root -> val <= high) 
            solve_optimal(root -> right, low, high, sum);
        
        return sum;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        // return solve_brute(root, low, high, sum);

        return solve_optimal(root, low, high, sum);
    }
};
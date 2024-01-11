// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/



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
    void getMaxDiffUtil(TreeNode* root, TreeNode* child, int& maxDiff) {
        if (root == NULL || child == NULL) return;

        maxDiff = max(maxDiff, abs(root -> val - child -> val));

        getMaxDiffUtil(root, child -> left , maxDiff);
        getMaxDiffUtil(root, child -> right, maxDiff);
    }

    void getMaxDiff(TreeNode* root, int& maxDiff) {
        if (root == NULL) return;

        getMaxDiffUtil(root, root -> left , maxDiff);
        getMaxDiffUtil(root, root -> right, maxDiff);

        getMaxDiff(root -> left , maxDiff);
        getMaxDiff(root -> right, maxDiff);
    }

    // TC : O(N^2) -> Visiting each once more than once
    // SC : O(N)   -> Recursive Depth
    int solve_brute(TreeNode* root) {
        int maxDiff = -1;
        getMaxDiff(root, maxDiff);
        return maxDiff;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    int solve_optimal(TreeNode* root, int minVal, int maxVal) {
        if (root == NULL) {
            return abs(minVal - maxVal);
        }

        int left  = solve_optimal(root -> left , min(minVal, root -> val), max(maxVal, root -> val));
        int right = solve_optimal(root -> right, min(minVal, root -> val), max(maxVal, root -> val));

        return max(left, right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        // return solve_brute(root);

        return solve_optimal(root, root -> val, root -> val);
    }
};
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/



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
    void inorder(TreeNode* root, vector<int>& storeInorder) {
        if (!root) return;

        inorder(root -> left , storeInorder);
        storeInorder.push_back(root -> val);
        inorder(root -> right, storeInorder);
    }

    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    void func(TreeNode* root, int& ans, int& prev) {
        if (!root) return;

        func(root -> left , ans, prev);
        if (prev != -1) {
            ans = min(ans, root -> val - prev);
        }
        prev = root -> val;
        func(root -> right, ans, prev);
    }

    // TC : O(N)
    // SC : O(N)
    int solve_brute(TreeNode* root) {
        vector<int> storeInorder;
        inorder(root, storeInorder);
        int ans = INT_MAX;
        for (int i = 1; i < storeInorder.size(); i++) {
            int diff = storeInorder[i] - storeInorder[i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(TreeNode* root) {
        int ans  = INT_MAX;
        int prev = -1;
        func(root, ans, prev);
        return ans;
    }
public:
    int minDiffInBST(TreeNode* root) {
        // return solve_brute(root);

        return solve_optimal(root);
    }
};
// https://leetcode.com/problems/sum-of-left-leaves/



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
    void approach_1(TreeNode* root, int &sum, bool flag) {
        if (!root) return;
        if (!root -> left && !root -> right && flag) {
            sum += root -> val;
        }
        approach_1(root -> left, sum , 1);
        approach_1(root -> right, sum, 0);
    }

    // TC : O(N)
    // SC : O(H)
    int approach_1_better(TreeNode* root, bool flag) {
        if (!root) return 0;
        if (!root -> left && !root -> right && flag) {
            return root -> val;
        }
        int left  = approach_1_better(root -> left , 1);
        int right = approach_1_better(root -> right, 0);
        return left + right;
    }

    // TC : O(N)
    // SC : O(H)
    int approach_2(TreeNode* root, TreeNode* parent) {
        if (!root) return 0;
        if (!root -> left && !root -> right) {
            if (parent != NULL && parent -> left == root) {
                return root -> val;
            }
        }
        int left  = approach_2(root -> left , root);
        int right = approach_2(root -> right, root);
        return (left + right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // int sum = 0;
        // approach_1(root, sum, 0);
        // return sum;

        // return approach_1_better(root, 0);

        return approach_2(root, NULL);
    }
};
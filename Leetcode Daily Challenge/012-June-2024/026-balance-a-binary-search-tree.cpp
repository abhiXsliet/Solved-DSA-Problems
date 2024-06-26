// https://leetcode.com/problems/balance-a-binary-search-tree/



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
    // TC : O(N) Where N = Number of Nodes
    // SC : O(1)
    void morrisTraversal(TreeNode* root, vector<int>& store) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr -> left == NULL) {
                store.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* leftChild = curr -> left;
                while (leftChild -> right != NULL) {
                    leftChild = leftChild -> right;
                }
                leftChild -> right = curr;

                // Mark NULL : curr -> left to avoid the infinite looping
                TreeNode* temp = curr;
                curr           = curr -> left;
                temp -> left   = NULL;
            }
        }
        return;
    }

    // TC : O(N)
    // SC : O(N)
    TreeNode* buildBalancedBST(vector<int>& store, int left, int right) {
        if (left > right) return NULL;

        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(store[mid]);

        root -> left  = buildBalancedBST(store, left, mid - 1);
        root -> right = buildBalancedBST(store, mid + 1, right);

        return root;
    }

    // TC : O(N)
    // SC : O(N) Where N = No. of Nodes
    TreeNode* approach_1(TreeNode* root) {
        vector<int> store;
        morrisTraversal(root, store);
        return buildBalancedBST(store, 0, store.size() - 1);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        return approach_1(root);     // Making a Completely New Tree

                                     // DSW ALGO : Inplace (modifies the given input in balanced BST)
    }
};
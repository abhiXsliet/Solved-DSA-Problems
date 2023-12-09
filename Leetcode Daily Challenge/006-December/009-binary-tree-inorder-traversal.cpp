// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/




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
    // TC = O(N)
    // SC = O(N) -> Recursive Depth of a skew tree
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;

        inorder(root -> left, result);
        result.push_back(root -> val);
        inorder(root -> right, result);
    }

    vector<int> solve_approach_1(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    // MORIS TRAVERSAL -> Similar result of inorder traversal
    // TC = O(N)
    // SC = O(1)
    vector<int> solve_approach_2(TreeNode* root) {
        vector<int> result;

        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr -> left == NULL) { // L, V, R
                result.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                TreeNode* currLeft = curr -> left;

                while(currLeft -> right != NULL) {
                    currLeft = currLeft -> right;
                }

                currLeft -> right = curr;

                // IMPORTANT: mark the currLeft as NULL
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL; 
            }
        }
        return result;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // return solve_approach_1(root);

        return solve_approach_2(root);
    }
};
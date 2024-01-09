// https://leetcode.com/problems/leaf-similar-trees/



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
    void inorder(TreeNode* root, string& s) {
        if (!root) return;

        inorder(root -> left, s);
        if (root -> left == NULL && root -> right == NULL)
            s += to_string(root -> val) + "_";
        inorder(root -> right, s);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";

        inorder(root1, s1);
        inorder(root2, s2);

        return s1 == s2;
    }
};
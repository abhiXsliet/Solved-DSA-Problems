// https://leetcode.com/problems/construct-string-from-binary-tree/



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
public:
    // TC = O(N)
    // SC = O(N) -> Recursive Depth
    string tree2str(TreeNode* root) {
        if (root == NULL) return "";

        string result = to_string(root -> val);

        string left  = tree2str(root -> left);
        string right = tree2str(root -> right);

        if (root -> left == NULL && root -> right == NULL)
            return result; 

        if (root -> left == NULL) 
            return result + "()" + "(" + right + ")";

        if (root -> right == NULL)
            return result + "(" + left + ")";
        
        return result + "(" + left + ")" + "(" + right + ")";
    }
};
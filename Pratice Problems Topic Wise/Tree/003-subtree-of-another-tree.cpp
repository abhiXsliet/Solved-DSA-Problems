// https://leetcode.com/problems/subtree-of-another-tree/



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
    string solve(TreeNode* root) {
        if (!root) {
            return "NULL";
        }

        string store = "Node" + to_string(root->val) + " ";
        store += "L" + solve(root -> left ) + " ";
        store += "R" + solve(root -> right) + " ";

        return store;
    }

    // TC : O(N)
    // SC : O(N)
    bool solve_1(TreeNode* root, TreeNode* subRoot) {
        string main = solve(root);
        string subM = solve(subRoot);

        if (main.find(subM) != string::npos) return 1;
        return 0;
    }

    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return 1;
        if (!root || !subRoot) return 0;

        return (root -> val == subRoot -> val) && 
            dfs(root -> left, subRoot -> left) && 
            dfs(root -> right, subRoot -> right);
    }

    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    bool solve_2(TreeNode* root, TreeNode* subRoot) {
        if (!root) return 0;
        
        return dfs(root, subRoot) || 
            solve_2(root -> left, subRoot) || 
            solve_2(root -> right, subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // return solve_1(root, subRoot);

        return solve_2(root, subRoot);
    }
};
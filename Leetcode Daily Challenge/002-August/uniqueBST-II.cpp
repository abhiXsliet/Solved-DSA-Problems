// https://leetcode.com/problems/unique-binary-search-trees-ii/



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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;
        if(start > end)
            ans.push_back(NULL);
        if(start == end)
            return {new TreeNode(start)};

        for(int i = start;  i <= end; i++) {
            vector<TreeNode*> leftSubTrees = solve(start, i-1);
            vector<TreeNode*> rightSubTrees = solve(i+1, end);

            for(TreeNode* l : leftSubTrees) {
                for(TreeNode* r : rightSubTrees) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
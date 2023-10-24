// https://leetcode.com/problems/find-largest-value-in-each-tree-row/


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
    // TC = O(N)
    // SC = O(N) -> to return the ans
    vector<int> solve_bfs(TreeNode* root) {
        if (root == NULL) return {};

        queue<TreeNode*> q;
        vector<int> result;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            int maxEle = INT_MIN;
            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                maxEle = max(maxEle, node -> val);

                if (node -> left ) q.push(node -> left );
                if (node -> right) q.push(node -> right);
            }
            result.push_back(maxEle);
        }
        return result;
    }

    // TC = O(N)
    // SC = O(depth) -> recursive call stack
    void solve_dfs(TreeNode* root, int depth, vector<int>& result) {
        if (root == NULL) return;

        if (result.size() == depth) 
            result.push_back(root -> val);
        else 
            result[depth] = max(result[depth], root -> val);

        solve_dfs(root -> left,  depth+1, result);
        solve_dfs(root -> right, depth+1, result);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        // return solve_bfs(root);

        vector<int> result;
        solve_dfs(root, 0, result);
        return result;
    }
};
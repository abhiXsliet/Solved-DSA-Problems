// https://leetcode.com/problems/smallest-string-starting-from-leaf/



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
    // TC : O(N) Where N = No. of Nodes
    // SC : O(H) Where H = Height of Tree
    void dfs(TreeNode* root, string& result, string curr) {
        if(!root) return;

        curr = char(root -> val + 'a') + curr;
        if (!root -> left && !root -> right) {
            if (result == "" || result > curr) {
                result = curr;
            }
            return;
        }

        dfs(root -> left , result, curr);
        dfs(root -> right, result, curr);
    }

    string approach_1(TreeNode* root) {
        string result = "";
        dfs(root, result, "");
        return result;
    }

    // TC : O(N)
    // SC : O(N) Where N = No. of Nodes
    string approach_2(TreeNode* root) {
        queue<pair<TreeNode*, string>> q;
        q.push({root, string(1, char(root -> val + 'a'))});

        string result = "";
        while(!q.empty()) {
            auto[fNode, curr] = q.front();
            q.pop();

            if (!fNode -> left && !fNode -> right) {
                if (result == "" || result > curr) {
                    result = curr;
                }
            }

            if (fNode -> left) {
                q.push({fNode -> left, char(fNode -> left -> val + 'a') + curr});
            }
            if (fNode -> right) {
                q.push({fNode -> right, char(fNode -> right -> val + 'a') + curr});
            }
        }
        return result;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        // return approach_1(root);

        return approach_2(root);
    }
};
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/




#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // TC : O(N)
    // SC : O(N) Due to recursive depth
    TreeNode* solve(vector<int>& pre, vector<int>& post, unordered_map<int, int>& mpp, int &preIdx, int postSt, int postEnd) {
        if (postSt > postEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[preIdx]);
        preIdx ++;
        
        if (postSt == postEnd) {
            return root;
        }

        int pos = mpp[pre[preIdx]];  // Position of left subtree root in postorder

        root ->  left = solve(pre, post, mpp, preIdx, postSt, pos);
        root -> right = solve(pre, post, mpp, preIdx, pos + 1, postEnd - 1); 
        return root;
    }
public:
    // TC : O(N)
    // SC : O(N) Due to map
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[postorder[i]] = i;
        }
        int preIdx = 0;
        return solve(preorder, postorder, mpp, preIdx, 0, n - 1);
    }
};
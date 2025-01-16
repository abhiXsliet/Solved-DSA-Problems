// https://leetcode.com/problems/binary-tree-maximum-path-sum/



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
    int approach_1(TreeNode* root, int &ans) {
        if (!root) return 0;

        int L = approach_1(root -> left , ans);
        int R = approach_1(root -> right, ans);

        ans = max(ans, max(root -> val, 
                       max(L + root -> val, 
                       max(R + root -> val, L + R + root -> val))));

        return max(root -> val, (root -> val) + max(L, R));
    }
public:
    // TC : O(N)
    // SC : O(H)
    int maxPathSum(TreeNode* root) {
        int ans = root -> val;
        approach_1(root, ans);
        return ans;
    }
};
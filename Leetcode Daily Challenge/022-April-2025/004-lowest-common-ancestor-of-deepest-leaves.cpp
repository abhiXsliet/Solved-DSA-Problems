// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/




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
    TreeNode* LCA(TreeNode* root, int maxD, unordered_map<TreeNode*, int> &nodeDepth) {
        if (!root || nodeDepth[root] == maxD)
            return root;
        
        TreeNode* L = LCA(root ->  left, maxD, nodeDepth);
        TreeNode* R = LCA(root -> right, maxD, nodeDepth);

        if (L && R) return root;
        if (!L) return R;
        return L;
    }

    void getDepth(TreeNode* root, int depth, unordered_map<TreeNode*, int> &nodeDepth, int &maxDepth) {
        if (!root) return;

        maxDepth = max(maxDepth, depth);
        nodeDepth[root] = depth;

        getDepth(root  -> left, depth + 1, nodeDepth, maxDepth);
        getDepth(root -> right, depth + 1, nodeDepth, maxDepth);
    }

    // TC : O(N)
    // SC : O(N)
    TreeNode* approach_1(TreeNode* root) {
        unordered_map<TreeNode*, int> nodeDepth;
        int maxDepth = 0;
        getDepth(root, 0, nodeDepth, maxDepth);

        return LCA(root, maxDepth, nodeDepth);
    }

    // TC : O(N)
    // SC : O(maxHeight)
    pair<int, TreeNode*> approach_2(TreeNode* root) {
        if (!root) {
            return {0, NULL};
        }

        auto L = approach_2(root ->  left);
        auto R = approach_2(root -> right);

        if (L.first == R.first) {
            return {1 + L.first, root};
        } else if (L.first > R.first) {
            return {1 + L.first, L.second};
        }
        return {1 + R.first, R.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // return approach_1(root);
        return approach_2(root).second;    // ONE PASS
    }
};
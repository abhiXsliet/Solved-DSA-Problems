// https://leetcode.com/problems/find-largest-value-in-each-tree-row/




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
    // TC : O(N) Where N = No. of Nodes
    // SC : O(1)
    vector<int> approach_1(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int maxVal = INT_MIN;
            int n = q.size();
            while (n --) {
                TreeNode* node = q.front();
                q.pop();

                maxVal = max(maxVal, node -> val);

                if (node -> left) q.push(node -> left);
                if (node ->right) q.push(node ->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(H) Recursive Depth. O(N) for worst (for a skewed tree) 
    //           and O(log n) for best case (for a balanced tree)
    void approach_2(TreeNode* root, vector<int>& result, int level) {
        if (!root) return;

        if (level == result.size()) 
            result.push_back(root -> val);
        else 
            result[level] = max(result[level], root -> val);

        approach_2(root -> left, result, level + 1);
        approach_2(root ->right, result, level + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        return approach_1(root);    // BFS

        vector<int> result;
        approach_2(root, result, 0);    // DFS
        return result;
    }
};
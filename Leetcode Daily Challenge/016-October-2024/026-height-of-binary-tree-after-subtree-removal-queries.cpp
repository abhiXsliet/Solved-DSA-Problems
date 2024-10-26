// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/




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
    // SC : O(N) Recursive Depth
    int maxHeight(TreeNode* root, vector<int> &levelVec, vector<int> &depthVec, 
                               vector<int> &firstMaxAtLevel, vector<int> &secondMaxAtLevel, int l) {
        
        if (!root) return 0;

        levelVec[root -> val] = l;
        depthVec[root -> val] = 1 + max(maxHeight(root -> left , levelVec, depthVec, firstMaxAtLevel, secondMaxAtLevel, l + 1), 
                                        maxHeight(root -> right, levelVec, depthVec, firstMaxAtLevel, secondMaxAtLevel, l + 1));

        if (depthVec[root -> val] > firstMaxAtLevel[l]) {
            secondMaxAtLevel[l] = firstMaxAtLevel[l];
            firstMaxAtLevel[l]  = depthVec[root -> val];
        } else if (depthVec[root -> val] > secondMaxAtLevel[l]) {
            secondMaxAtLevel[l] = depthVec[root -> val];
        }

        return depthVec[root -> val];
    }

    // TC : O(N)
    // SC : O(N) Recursive Depth
    int newSolve(TreeNode* root, int query) {
        if (!root || root -> val == query) return -1;

        int x = 1 + newSolve(root -> left, query);
        int y = 1 + newSolve(root -> right, query);
        return max(x, y);
    }

    // TC : O(N)
    // SC : O(N) Recursive Depth
    int getDepth(TreeNode* &root) {
        if (!root) return -1;
        return 1 + max(getDepth(root -> left), getDepth(root -> right));
    }

    // TC : O(N)
    // SC : O(N) Recursive Depth
    TreeNode* copyTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* copyRoot = new TreeNode(root -> val);
        copyRoot -> left   = copyTree(root -> left);
        copyRoot -> right  = copyTree(root -> right);
        return copyRoot;
    }

    // TC : O(N)
    // SC : O(N) Recursive Depth
    void solve(TreeNode* &root, int &query, int &depth) {
        if (!root) return;
        if (query == root -> val) {
            root = NULL;
            return;
        }
        solve(root ->  left, query, depth);
        solve(root -> right, query, depth);
        depth = getDepth(root);
    }

    // TC : O(N * Q) Where N = No. of Nodes and Q = No. of Queries
    // SC : O(1)
    vector<int> brute(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        for (int query : queries) {
            int depth = 0;
            TreeNode* rootCopy = copyTree(root);
            solve(rootCopy, query, depth);
            ans.push_back(depth);
        }
        return ans;
    }

    // TC : O(N * Q) Where N = No. of Nodes and Q = No. of Queries
    // SC : O(1)
    vector<int> better(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        for (int query : queries) {
            ans.push_back(newSolve(root, query));
        }
        return ans;
    }

    // TC : O(N + Q) Where N = No. of Nodes and Q = No. of Queries
    // SC : O(N)
    vector<int> optimal(TreeNode* root, vector<int>& queries) {
        vector<int> levelVec(100001, -1);  // Level of each node
        vector<int> depthVec(100001, -1);  // Depth of each node

        vector<int> firstMaxAtLevel (100001, 0);    // First  Maximum depth value at each level
        vector<int> secondMaxAtLevel(100001, 0);    // Second Maximum depth value at each level
        int cLvl = 0;   // Current Level

        maxHeight(root, levelVec, depthVec, firstMaxAtLevel, secondMaxAtLevel, cLvl);

        vector<int> ans;
        for (int query : queries) {
            int L = levelVec[query];

            // Depth of each node : L + H - 1
            // firstMaxAtLevel[L] == depthVec[query] : meaning we are deleting the max height
            int depth = L + (firstMaxAtLevel[L] == depthVec[query] ? secondMaxAtLevel[L] : firstMaxAtLevel[L]) - 1;
            ans.push_back(depth);
        }
        return ans;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // return brute(root, queries);     // Simulated as it is

        // return better(root, queries);

        return optimal(root, queries);
    }
};
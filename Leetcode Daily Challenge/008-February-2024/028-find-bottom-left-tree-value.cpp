// https://leetcode.com/problems/find-bottom-left-tree-value/



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
    int maxDepth;
    int bottomLeft;

    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    void solve(TreeNode* root, int currDepth) {
        if (!root) return;

        if (currDepth > maxDepth) {
            maxDepth = currDepth;
            bottomLeft = root -> val;
        }

        solve(root -> left , currDepth + 1);
        solve(root -> right, currDepth + 1);
    }

    // TC : O(N)
    // SC : O(1)
    int approach_1(TreeNode* root) {
        maxDepth = -1;
        solve(root, 0);
        return bottomLeft;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int bottomLeft;

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            bottomLeft = node -> val;

            if (node -> right) 
                q.push(node -> right);

            if (node -> left)
                q.push(node -> left);
        }
        return bottomLeft;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_3(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int bottomLeft;

        while(!q.empty()) {
            
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front(); q.pop();

                bottomLeft = node -> val;

                if (node -> right) 
                    q.push(node -> right);

                if (node -> left)
                    q.push(node -> left);
            }
        }
        return bottomLeft;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        // return approach_1(root);     // DFS

        // return approach_2(root);     // BFS - 1

        return approach_3(root);    // BFS - 2
    }
};
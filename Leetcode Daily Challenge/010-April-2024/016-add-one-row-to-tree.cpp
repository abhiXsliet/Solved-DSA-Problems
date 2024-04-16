// https://leetcode.com/problems/add-one-row-to-tree/



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
    TreeNode* dfs(TreeNode* root, int val, int depth, int curr) {
        if (!root) return NULL;

        if (curr == depth - 1) {
            TreeNode* leftTemp  = root -> left;   // store the left subtree of root
            TreeNode* rightTemp = root -> right;  // store the right subtree of root

            root -> left  = new TreeNode(val);  // create new node in left of root
            root -> right = new TreeNode(val);  // create new node in right of root

            root -> left ->left    = leftTemp;
            root -> right -> right = rightTemp;
        }

        root -> left  
        = dfs(root -> left , val, depth, curr + 1);
        root -> right = dfs(root -> right, val, depth, curr + 1);

        return root;
    }

    // T.C : O(n)
    // S.C : O(1) Auxiliary Space, O(depth) system stack space of recursion
    TreeNode* approach_1(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left   = root;
            return newRoot;
        }

        int curr = 1;
        return dfs(root, val, depth, curr);
    }

    // T.C : O(n)
    // S.C : O(n)
    TreeNode* approach_2(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left   = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        bool rowAdded = 0;

        while(!q.empty()) {
            int n = q.size();
            level++;
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();
                TreeNode* tempL = curr->left;
                TreeNode* tempR = curr->right;
                if(level == depth - 1) {
                    curr->left  = new TreeNode(val);
                    curr->right = new TreeNode(val);
                    curr->left->left   = tempL;
                    curr->right->right = tempR;
                    rowAdded = true;
                }
                if(tempL)
                    q.push(tempL);
                if(tempR)
                    q.push(tempR);
            }
            if(rowAdded)
                break;
        }
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // return approach_1(root, val, depth); // DFS

        return approach_2(root, val, depth);    // BFS
    }
};
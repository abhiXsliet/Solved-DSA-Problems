// https://leetcode.com/problems/same-tree



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
    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    bool approach_1(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        if (!p || !q) return 0;

        if (p -> val != q -> val) 
            return 0;
        
        return ( isSameTree(p -> left , q ->  left) && 
                 isSameTree(p -> right, q -> right) );
    }

    // TC : O(N)
    // SC : O(N)
    bool approach_2(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        if (!p || !q) return 0;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* n1 = q1.front(); q1.pop();
            TreeNode* n2 = q2.front(); q2.pop();

            if (n1 -> val != n2 -> val) 
                return 0;

            if (n1 -> left && n2 -> left) {
                q1.push(n1 -> left);
                q2.push(n2 -> left);
            }
            else if (n1 -> left || n2 -> left) {
                return 0;
            }

            if (n1 -> right && n2 -> right) {
                q1.push(n1 -> right);
                q2.push(n2 -> right);
            }
            else if (n1 -> right || n2 -> right) {
                return 0;
            }
        }
        return 1;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // return approach_1(p, q);    // DFS

        return approach_2(p, q);    // BFS
    }
};
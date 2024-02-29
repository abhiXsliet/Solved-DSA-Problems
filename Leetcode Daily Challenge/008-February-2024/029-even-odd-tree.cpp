// https://leetcode.com/problems/even-odd-tree/



#include <bits/stdc++.h>
using namespace std; 

/* *
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
    // SC : O(N)
    bool approach_1(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int evenLevel = true;
        int previous;

        while (!q.empty()) {

            if (evenLevel) 
                previous = INT_MIN;
            else 
                previous = INT_MAX;

            int n = q.size();
            while (n --) {
                TreeNode* node = q.front(); 
                q.pop();

                if ( evenLevel && ( (node -> val % 2 == 0) || (node -> val <= previous) ) )
                    return false;
                
                if ( !evenLevel && ( (node -> val % 2 != 0) || (node -> val >= previous) ) )
                    return false;

                previous = node -> val;

                if (node -> left)
                    q.push(node -> left);
                
                if (node -> right)
                    q.push(node -> right);
            }

            evenLevel = !evenLevel;
        }
        return true;
    }

    // TC : O(N) visiting each node only once
    // TC : O(N^2) due to .resize()
    // SC : prevLevel max size which will be depth of level (Auxiliary Space)
    // SC : O(Depth) -> Recursive Space
    vector<int> prevLevel;
    bool approach_2(TreeNode* root, int level) {
        if (!root) return 1;

        if (level % 2 == root -> val % 2)
            return false;

        if (level >= prevLevel.size()) {
            prevLevel.resize(level + 1);    // takes O(N)
        }

        if (prevLevel[level] != 0) {
            if (level % 2 == 0 && (root -> val <= prevLevel[level]) 
            || 
            (level % 2 != 0 && root -> val >= prevLevel[level]))
                return false;
        }

        prevLevel[level] = root -> val;


        return approach_2(root -> left, level + 1) && 
               approach_2(root -> right, level + 1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        // return approach_1(root);    // BFS

        return approach_2(root, 0);    // DFS
    }
};
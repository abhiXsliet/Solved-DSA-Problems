// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/



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
    // SC : O(2^L) Max No. of Nodes at last level & L = log(N + 1) - 1 (for perfect bt)
    TreeNode* approach_1(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> storeOddLevelNodes;
            while (n --) {
                TreeNode* fNode = q.front();
                q.pop();
                
                storeOddLevelNodes.push_back(fNode);

                if (fNode -> left) q.push(fNode -> left);
                if (fNode ->right) q.push(fNode ->right);
            }

            int l = 0, r = storeOddLevelNodes.size() - 1;
            if (level % 2) {
                while (l <= r) 
                    swap(storeOddLevelNodes[l++] -> val, storeOddLevelNodes[r--] -> val);
            }
            level ++;
        }
        return root;
    }

    // TC : O(N)
    // SC : O(H) Due to depth of recursion (log(N)) height of perfect bt
    void approach_2(TreeNode* root1, TreeNode* root2, int level) {
        if (!root1 || !root2) return;

        if (level % 2) {
            int temp = root1 -> val;
            root1  -> val = root2 -> val;
            root2 -> val = temp;
        }

        approach_2(root1 ->  left, root2 -> right, level + 1);
        approach_2(root1 -> right, root2 ->  left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        // return approach_1(root);  // BFS   
        
        approach_2(root -> left, root -> right, 1);  // DFS
        return root;
    }
};
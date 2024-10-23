// https://leetcode.com/problems/cousins-in-binary-tree-ii/




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
    void BFS(TreeNode* root, vector<int>& store) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            while (size --) {
                TreeNode* fNode = q.front();
                q.pop();

                sum += (fNode -> val);

                if (fNode ->  left) q.push(fNode -> left);
                if (fNode -> right) q.push(fNode -> right);
            }
            store.push_back(sum);
        }
    }

    // TC : O(N)
    // SC : O(N)
    TreeNode* approach_1(TreeNode* root) {
        vector<int> storeLevelSum;
        BFS(root, storeLevelSum);
        
        // Now modify the value of nodes a/c to their cousins
        queue<TreeNode*> q;
        q.push(root);
        root -> val = 0;    // cousin of root is none
        int idx = 1;
        while (!q.empty()) {
            int level = q.size();
            while (level --) {
                TreeNode* fNode = q.front();
                q.pop();

                int siblingSum = (fNode -> left ? fNode -> left -> val : 0) + (fNode -> right ? fNode -> right -> val : 0);

                if (fNode -> left) {
                    q.push(fNode -> left);
                    fNode -> left -> val = storeLevelSum[idx] - siblingSum;
                }

                if (fNode -> right) {
                    q.push(fNode -> right);
                    fNode -> right -> val = storeLevelSum[idx] - siblingSum;
                }
            }
            idx ++;
        }

        return root;
    }

    // TC : O(N)
    // SC : O(N)
    TreeNode* approach_2(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currLevelSum = root -> val;

        while (!q.empty()) {
            int level = q.size();
            int nextLevelSum = 0;
            while (level --) {
                TreeNode* fNode = q.front();
                q.pop();
                
                fNode -> val = currLevelSum - fNode -> val;

                int siblingSum = (fNode -> left ? fNode -> left -> val : 0) + (fNode -> right ? fNode -> right -> val : 0);
                
                if (fNode -> left) {
                    nextLevelSum += (fNode -> left -> val);
                    fNode -> left -> val = siblingSum;  // store the sibling sum in the nodes of common parent
                    q.push(fNode -> left);
                }

                if (fNode -> right) {
                    nextLevelSum += (fNode -> right -> val);
                    fNode -> right -> val = siblingSum;  // store the sibling sum in the nodes of common parent
                    q.push(fNode -> right);
                }
            }
            currLevelSum = nextLevelSum;
        }

        return root;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // return approach_1(root);    // 2 - Pass : Using BFS

        return approach_2(root);    // 1 - Pass : Using BFS
    }
};
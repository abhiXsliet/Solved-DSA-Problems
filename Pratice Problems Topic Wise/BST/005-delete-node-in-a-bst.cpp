// https://leetcode.com/problems/delete-node-in-a-bst/



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
    int getMini(TreeNode* root) {
        while(root -> left) {
            root = root -> left;
        }
        return root -> val;
    }
public:
/*     
    The time complexity of this code is O(h), where h is the height of the tree. 
    This is because in the worst case, you might have to traverse from the root to the deepest leaf node. 
    In a balanced BST, the height is log(n), so the time complexity can also be represented as O(log n).
    However, in the worst case of a skewed BST, the height is 'n', so the time complexity would be O(n).

 */
    // TC : O(H), O(log(N)) for Balanced BST, O(N) for Skewed BST at worst
    // SC : (Recursive Stack) => O(H), O(log(N)) for Balanced BST, O(N) for Skewed BST at worst
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (root -> val == key) {
            // 0-child
            if (!root -> left && !root -> right) {
                delete root;
                return NULL;
            }

            // 1-child
            if (!root -> left) {    // left child
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            if (!root -> right) {   // right child
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }

            // 2-child
            if (root -> right && root -> left) {
                // find mini from right part or find maxi from left part
                int mini = getMini(root -> right);
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
            }
        }
        else if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        }
        else {
            root -> right = deleteNode(root -> right, key);
        }
        return root;
    }
};
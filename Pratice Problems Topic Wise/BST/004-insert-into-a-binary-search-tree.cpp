// https://leetcode.com/problems/insert-into-a-binary-search-tree/



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
/*     
    The time complexity of this code is O(h), where h is the height of the tree. 
    This is because in the worst case, you might have to traverse from the root to the deepest leaf node. 
    In a balanced BST, the height is log(n), so the time complexity can also be represented as O(log n).
    However, in the worst case of a skewed BST, the height is 'n', so the time complexity would be O(n).

 */
    // TC : O(H), O(log(N)) for balanced bst and O(N) for skewed bst
    // SC : O(1)
    TreeNode* solve_1(TreeNode* root, int k) {
        if (!root) return new TreeNode(k);
        
        TreeNode* curr = root;
        while(1) {
            if (curr -> val > k) {
                if (!curr -> left) {
                    curr -> left = new TreeNode(k);
                    break;
                }
                else curr = curr -> left;
            }
            else if (curr -> val < k){
                if (!curr -> right) {
                    curr -> right = new TreeNode(k);
                    break;
                }
                else curr = curr -> right;
            }
            else return curr;   // root -> val == k
        }
        return root;
    }

    // TC : O(H), O(log(N)) for balanced bst, O(N) for skewed bst
    // SC : Recursive Stack => O(H), O(log(N)) for balanced bst, O(N) for skewed bst 
    TreeNode* solve_2(TreeNode* node, int k) {
        if(!node) return new TreeNode(k);
        
        if (k < node -> val)
            node -> left = solve_2(node -> left, k);
        else if (k > node -> val)
            node -> right = solve_2(node -> right, k);
            
        return node;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // return solve_1(root, val);

        return solve_2(root, val);
    }
};
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Similar Problem : https://leetcode.com/problems/convert-bst-to-greater-tree/


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
    // SC : O(1) but Recursive Depth : O(N)
    void inorder(TreeNode* root, vector<int>& store) {
        if (!root) return;

        inorder(root -> left, store);
        store.push_back(root -> val);
        inorder(root -> right, store);
    }
    
    // TC : O(N)
    // SC : O(N)
    TreeNode* copyTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* copyRoot = new TreeNode(root -> val);
        copyRoot -> left  = copyTree(root -> left);
        copyRoot -> right = copyTree(root -> right);
        return copyRoot;
    }

    // TC : O(N)
    // SC : O(1)
    // This Traversal Modifies the original structre of the tree
    void morrisTraversal_1(TreeNode* root, vector<int>& result) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if (curr -> left == NULL) {
                result.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* currLeft = curr -> left;
                while (currLeft -> right != NULL) {
                    currLeft = currLeft -> right;
                }
                currLeft -> right = curr;

                // Mark NULL currLeft : sice it will again execute the else (curr -> left != NULL)
                TreeNode* temp = curr;
                curr           = curr -> left;
                temp -> left   = NULL;
            }
        }
        return;
    }

    // TC : O(N)
    // SC : O(1)
    // This traversal keeps the structure of the tree intact
    void morrisTraversal_2(TreeNode* root, vector<int>& result){
        TreeNode* curr, *pred;
    
        curr = root;
        while (curr != NULL) {
            if(curr -> left == NULL) {
                result.push_back(curr -> val);
                curr = curr -> right;
            } else {
                //find predecessor(ek baar left jana hota ushke baar right jaate rho jb tk null na mille)
                pred = curr -> left;
                while(pred -> right != NULL && pred -> right != curr) {
                    pred = pred -> right;
                }
    
                if(pred -> right == NULL) {
                    pred -> right = curr;
                    curr = curr -> left;
                } else {
                    pred -> right = NULL;
                    result.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return;
    }

    // TC : O(N^2)
    // SC : O(N) Depth of Recursion
    TreeNode* approach_1(TreeNode* root, vector<int>& store) {
        if (!root) return NULL;

        TreeNode* right = approach_1(root -> right, store);
        TreeNode* left  = approach_1(root -> left, store);

        int sumOfAllGreaterNodes = 0;
        for (int& x : store) {
            if (x > root -> val) {
                sumOfAllGreaterNodes += x;
            }
        }

        root -> val += sumOfAllGreaterNodes;
        return root;
    }

    // TC : O(N*log(N))
    // SC : O(N) Depth of Recursion
    TreeNode* approach_2(TreeNode* root, vector<int>& store, vector<int>& suffixSum) {
        if (!root) return NULL;

        TreeNode* right = approach_2(root -> right, store, suffixSum);
        TreeNode* left  = approach_2(root -> left , store, suffixSum);

        int low = 0, high = store.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (store[mid] == root -> val) {
                root -> val = suffixSum[mid];
                break;
            } else if (store[mid] < root -> val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return root;
    }
    
    // TC : O(N^2)
    // SC : O(N)   Where N = No. of Nodes
    TreeNode* brute(TreeNode* root) {
        vector<int> store;
        inorder(root, store);

        return approach_1(root, store);
    }

    // TC : O(N*log(N)) Where N = No. of Nodes
    // SC : O(N)   
    TreeNode* better(TreeNode* root) {
        vector<int> store;
       
        TreeNode* copyRoot = copyTree(root);

        // inorder(root, store);
        // morrisTraversal_1(copyRoot, store);    // Used copy of given to apply MorrisTraversal : to avoid in the change of structure of tree
        morrisTraversal_2(root, store);           // Used original tree and stucture of the tree didn't changes
        
        vector<int> suffixSum = store;
        
        for (int i = suffixSum.size() - 2; i >= 0; i --) {
            suffixSum[i] += suffixSum[i + 1];
        }

        return approach_2(root, store, suffixSum);
    }

    // TC : O(N)
    // SC : O(1)
    TreeNode* optimal(TreeNode* root, int& sum) {
        if (!root) return NULL;

        TreeNode* right = optimal(root -> right, sum);
        
        root -> val    += sum;
        sum             = root -> val;
       
        TreeNode* left  = optimal(root -> left , sum);

        return root;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        // return brute(root);

        // return better(root);

        int sum = 0;
        return optimal(root, sum);  
    }
};
// https://leetcode.com/problems/delete-nodes-and-return-forest/



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
    void helper(TreeNode* &root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if (!root) return;

        helper(root -> left , st, result);
        helper(root -> right, st, result);
        // POST ORDER
        if (st.count(root -> val)) {
            if (root -> left) 
                result.push_back(root -> left);
            if (root -> right) 
                result.push_back(root -> right);
            delete root;
            root = NULL;
        }
    }

    TreeNode* helper_del(TreeNode* &root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if (!root) return NULL;

        root -> left  = helper_del(root -> left , st, result);
        root -> right = helper_del(root -> right, st, result);
        // POST ORDER
        if (st.count(root -> val)) {
            if (root -> left) 
                result.push_back(root -> left);
            if (root -> right) 
                result.push_back(root -> right);
            delete root;
            root = NULL;
        }
        return root;
    }

    // TC : O(N)
    // SC : O(N) Where N = No. of Nodes
    vector<TreeNode*> way_1(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        
        unordered_set<int> st(begin(to_delete), end(to_delete));
       
        helper(root, st, result);

        if (root) result.push_back(root);
        
        return result;
    }

    // TC : O(N)
    // SC : O(N) Where N = No. of Nodes
    vector<TreeNode*> way_2(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        
        unordered_set<int> st(begin(to_delete), end(to_delete));
       
        helper_del(root, st, result);

        if (root) result.push_back(root);
        
        return result;
    }
public:
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // return way_1(root, to_delete);

        return way_2(root, to_delete);
    }
};
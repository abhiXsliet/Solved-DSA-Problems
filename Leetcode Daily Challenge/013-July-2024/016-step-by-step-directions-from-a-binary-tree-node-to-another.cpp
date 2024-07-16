// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/



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
    TreeNode* LCA(TreeNode* root, int startValue, int destValue) {
        if (!root) return NULL;

        if (root -> val == startValue || root -> val == destValue) 
            return root;

        TreeNode* lNode = LCA(root -> left , startValue, destValue);
        TreeNode* rNode = LCA(root -> right, startValue, destValue);

        if (lNode && rNode) return root;

        if (!rNode) return lNode;
        return rNode;
    }

    bool getPath (TreeNode* node, int target, string& path) {
        if (!node) return false;

        if (node -> val == target)
            return true;

        path.push_back('L');
        if (getPath(node -> left, target, path)) 
            return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(node -> right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    // TC : O(N)
    // SC : O(N)
    string approach_1(TreeNode* root, int startValue, int destValue) {
        TreeNode* node = LCA(root, startValue, destValue);

        string lcaToSrc, lcaToDest;
        getPath(node, startValue, lcaToSrc);
        getPath(node, destValue,  lcaToDest);

        string result;
        for (int i = 0; i < lcaToSrc.length(); i ++) 
            result += 'U';
        
        result += lcaToDest;
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    string approach_2(TreeNode* root, int startValue, int destValue) {
        string lcaToSrc, lcaToDest;
        getPath(root, startValue, lcaToSrc);
        getPath(root, destValue,  lcaToDest);

        int i = 0, m = lcaToSrc.length(), n = lcaToDest.length();
        while (i < m && i < n && lcaToSrc[i] == lcaToDest[i]) 
            i ++;

        // Adding 'U' 
        string result = string((m - i), 'U');

        // Adding remaining uncommon string of lcaToDest
        result += lcaToDest.erase(0, i);
        
        return result;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Brute force Pending

        // return approach_1(root, startValue, destValue);  // find LCA and then get the path to src & dest

        return approach_2(root, startValue, destValue);  // NO LCA : Remove the common from the path of src & dest
    }
};
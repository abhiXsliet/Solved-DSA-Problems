// https://leetcode.com/problems/find-mode-in-binary-search-tree/


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
    void inorder(TreeNode* root, unordered_map<int,int>& store) {
        if (!root) return;

        inorder(root -> left, store);
        store[root -> val]++;
        inorder(root -> right, store);
    }

    // TC = O(N)
    // SC = O(N)
    vector<int> solve_brute(TreeNode* root) {
        unordered_map<int,int> store;
        
        inorder(root, store);
       
        vector<int> result;
    
        int maxFreq = 0;
        for (auto& it : store) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            }
            else if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }

        return result;
    }

    // TC = O(N)
    // SC = O(1)
    void inorder(TreeNode* root, int& currEle, int& currFreq, int& maxFreq, vector<int>& result) {
        
        if (!root) return;

        inorder(root -> left, currEle, currFreq, maxFreq, result);
        
        if (root -> val == currEle) {
            currFreq++;
        } else {
            currEle  = root -> val;
            currFreq = 1;
        }

        if (currFreq > maxFreq) {
            result = {};
            maxFreq = currFreq;
        }

        if (currFreq == maxFreq) {
            result.push_back(root -> val);
        }

        inorder(root -> right, currEle, currFreq, maxFreq, result);
    }

    vector<int> solve_optimal(TreeNode* root) {
        vector<int> result;

        int currEle  = 0;
        int currFreq = 0;
        int maxFreq  = 0;

        inorder(root, currEle, currFreq, maxFreq, result);

        return result;
    }
public:
    vector<int> findMode(TreeNode* root) {
        // return solve_brute(root);

        return solve_optimal(root);
    }
};
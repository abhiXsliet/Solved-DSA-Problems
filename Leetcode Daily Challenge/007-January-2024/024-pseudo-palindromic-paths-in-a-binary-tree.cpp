// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/



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
    void solve_1(TreeNode* root, vector<int>& count, int& result) {
        if (!root) return;

        count[root -> val] ++;

        if (root -> left == NULL && root -> right == NULL) {
            int oddFreqCnt = 0;
            for (int val : count) {
                if (val % 2 != 0) {
                    oddFreqCnt ++;
                }
            }

            if (oddFreqCnt <= 1) result ++;
        }
        
        solve_1(root -> left , count, result);
        solve_1(root -> right, count, result);

        count[root -> val] --;
    }

    // TC : O(N)
    // SC : O(H) -> Recursive Depth
    void solve_2(TreeNode* root, int count, int& result) {
        if (!root) return;

        count = (count ^ (1 << root -> val));

        if (root -> left == NULL && root -> right == NULL) {
            if ((count & (count - 1)) == 0) {
                result ++;
            }
        }
        
        solve_2(root -> left , count, result);
        solve_2(root -> right, count, result);
    }

    int solve_approach_1(TreeNode* root) {
        vector<int> count(10, 0);
        int result = 0;
        solve_1(root, count, result);
        return result;
    }

    int solve_approach_2(TreeNode* root) {
        int result = 0;
        solve_2(root, 0, result);
        return result;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // return solve_approach_1(root);

        return solve_approach_2(root);
    }
};
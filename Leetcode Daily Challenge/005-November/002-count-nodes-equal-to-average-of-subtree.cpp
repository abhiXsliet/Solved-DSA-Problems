// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/


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
    int findSum(TreeNode* root, int& count) {
        if (!root) return 0;

        count++;
        int lSum = findSum(root -> left,  count);
        int rSum = findSum(root -> right, count);

        return (lSum + rSum + root -> val);
    }

    int dfs(TreeNode* root, int& result) {
        if(!root) return NULL;

        int count  = 0;
        int sum    = findSum(root, count);

        if (root -> val == sum / count) 
            result += 1;

        dfs (root -> left,  result);
        dfs (root -> right, result);

        return result;
    }
        
    pair<int, int> optimal_solve(TreeNode* root, int& result) {
        if (!root) 
            return {0, 0};     // {sum, cntOfNodes}

        auto p1 = optimal_solve(root -> left,  result);
        auto p2 = optimal_solve(root -> right, result);

        int totSum = p1.first + p2.first + root -> val;
        int totCnt = p1.second + p2.second + 1;

        int average = totSum / totCnt;

        if (average == root -> val) {
            result += 1;
        }

        return {totSum, totCnt};
    }

    int solve_brute(TreeNode* root) {
        int result = 0;
        return dfs(root, result);
    }

    // TC = O(N)
    int solve_optimal(TreeNode* root) {
        int result = 0;
        optimal_solve(root, result);
        return result;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        // return solve_brute(root);

        return solve_optimal(root);
    }
};
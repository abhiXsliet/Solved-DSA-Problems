// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/



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
    // SC : O(N) Due to recursive depth
    TreeNode* solve(string &s, int n, int &i, int depth) {
        if (i >= n) return NULL;

        // count dashes for depth
        int j = i;
        while (j < n && s[j] == '-') j ++;

        int dashCnt = (j - i);

        if (dashCnt != depth) return NULL;   

        i = j;  // adjust i after dash counting

        // make number
        int number = 0;
        while (i < n && isdigit(s[i])) {
            number = number * 10 + s[i] - '0';
            i ++;
        }

        TreeNode* root = new TreeNode(number);

        root -> left  = solve(s, n, i, depth + 1);
        root -> right = solve(s, n, i, depth + 1);

        return root;
    }
public:
    TreeNode* recoverFromPreorder(string s) {
        int index = 0;
        return solve(s, s.length(), index, 0);
    }
};
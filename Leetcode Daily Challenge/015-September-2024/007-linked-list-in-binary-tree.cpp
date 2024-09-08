// https://leetcode.com/problems/linked-list-in-binary-tree/




#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool check(ListNode* head, TreeNode* root) {
        if (!head) return 1;
        if (!root) return 0;

        if (root -> val != head -> val) 
            return 0;
        
        return check(head -> next, root -> left) || check(head -> next, root -> right);
    }

    // TC : O(MN) from every node of root we are checking whole LL of length (M)
    // SC : O(M + N) Recursive Depth
    bool approach_1(ListNode* head, TreeNode* root) {
        if (!root) return 0;

        return check(head, root) || 
               approach_1(head, root -> left) || 
               approach_1(head, root -> right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return approach_1(head, root);      // DFS
    }
};
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // TC : O(log(N))
    // SC : O(log(N)) -> Space Used By Recursive Call Stack
    TreeNode* buildTree(vector<int>& sorted, int low, int high) {
        if (low > high) return NULL;

        int mid = (low + high) >> 1;
        TreeNode* root = new TreeNode(sorted[mid]);

        root -> left  = buildTree(sorted, low, mid - 1);
        root -> right = buildTree(sorted, mid + 1, high);

        return root;
    }

    // TC : O(N)
    // SC : O(N)
    TreeNode* approach_1(ListNode* head) {
        vector<int> sorted;
        ListNode* temp = head;
        while (temp != NULL) {
            sorted.push_back(temp -> val);
            temp = temp -> next;
        }

        return buildTree(sorted, 0, sorted.size() - 1);
    }

    // TC : O(N)
    // SC : O(1)
    pair<ListNode*, ListNode*> getMiddle(ListNode* head) {
        if (!head || !head -> next) 
            return {head, head};

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast -> next != NULL) {
            prev = slow;
            slow = slow -> next; 
            fast = fast -> next -> next;
        }
        
        return {prev, slow};
    }

    // TC : O(N)
    // SC : O(1)
    TreeNode* approach_2(ListNode* head) {
        if (!head) return NULL;

        if (!head -> next) 
            return new TreeNode(head -> val);
        
        ListNode* mid  = getMiddle(head).second;    // slow points to mid
        TreeNode* root = new TreeNode(mid -> val);
        ListNode* prev = getMiddle(head).first;     // prev points to previous node of slow
        prev -> next   = NULL;
        
        root -> left   = approach_2(head);
        root -> right  = approach_2(mid -> next);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // return approach_1(head);   // Store all elements in vector

        return approach_2(head);      // Find mid using tortoise and hare approach and then use it
    }
};
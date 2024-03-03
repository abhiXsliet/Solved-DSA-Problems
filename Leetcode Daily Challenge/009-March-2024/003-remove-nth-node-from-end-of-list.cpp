// https://leetcode.com/problems/remove-nth-node-from-end-of-list/



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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Define a dummy node to handle edge cases where the head itself is removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Get the length of the linked list
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Calculate the position of the node to remove
        int target_pos = len - n;

        // Reset temp to the head of the list
        temp = dummy;

        // Move temp to the node just before the target node
        for (int i = 0; i < target_pos; ++i) {
            temp = temp->next;
        }

        // Remove the target node
        ListNode* to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;

        // Get the new head after potential modifications
        head = dummy->next;
        delete dummy;

        return head;
    }
};

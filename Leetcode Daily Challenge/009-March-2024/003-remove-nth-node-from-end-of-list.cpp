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
private:
    int getLen(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len ++;
            head = head -> next;
        }
        return len;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* solve_approach_1(ListNode* head, int n) {
        // Define a dummy node to handle edge cases where the head itself is removed
        ListNode* dummy = new ListNode(0);
        dummy -> next   = head;

        // Get the length of the linked list
        int len = getLen(head);

        // Calculate the position of the node to remove
        int target_pos = len - n;

        // Reset temp to the head of the list
        ListNode* temp = dummy;

        // Move temp to the node just before the target node
        for (int i = 0; i < target_pos; ++i) {
            temp = temp -> next;
        }

        // Remove the target node
        ListNode* to_delete = temp -> next;
        temp -> next        = temp -> next -> next;
        delete to_delete;

        // Get the new head after potential modifications
        head = dummy -> next;
        delete dummy;
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* solve_approach_2(ListNode* head, int n) {
        int len = getLen(head);

        // Delete the head node itself
        if (len == n) {
            ListNode* temp = head -> next;
            delete (head);
            return temp;
        }

        // Calculate the position of the node to remove
        int target_pos = len - n;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(target_pos --) {
            prev = temp;
            temp = temp -> next;
        }

        // Remove the target node
        prev -> next = temp -> next;
        delete temp;
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* solve_approach_3(ListNode* head, int n) {
        ListNode* temp = head;
        for (int i = 1; i <= n; i++) {
            temp = temp -> next;
        }

        if (temp == NULL) {
            ListNode* temp = head -> next;
            delete (head);
            return temp;
        }

        ListNode* prev = head;
        while(temp -> next != NULL) {
            prev = prev -> next;
            temp = temp -> next;
        }

        ListNode* nodeToDel = prev -> next;
        prev -> next = prev -> next -> next;
        delete nodeToDel;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return solve_approach_1(head, n);

        // return solve_approach_2(head, n);

        return solve_approach_3(head, n);   // ONE PASS
    }
};
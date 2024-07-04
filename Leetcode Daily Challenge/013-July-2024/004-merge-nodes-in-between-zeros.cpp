// https://leetcode.com/problems/merge-nodes-in-between-zeros/



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
    // TC : O(N)
    // SC : O(1)
    ListNode* approach_1(ListNode* head) {
        ListNode* prev = head -> next;
        ListNode* curr = head -> next;
        while (curr != NULL) {
            int sum = 0;
            while (curr -> val != 0) {
                sum += curr -> val;
                curr = curr -> next;
            }
            prev -> val = sum;
            curr = curr -> next;
            prev -> next = curr;
            prev = prev -> next;
        }
        return head -> next;
    }

    // TC : O(N)
    // SC : O(N) : Recursive Depth
    ListNode* approach_2(ListNode* head) {
        head = head -> next;
        if (head == NULL) 
            return head;
            
        ListNode* curr = head;
        int sum = 0;
        
        while (curr != NULL && curr -> val != 0) {
            sum += curr -> val;
            curr = curr -> next;
        }

        head -> val  = sum;
        head -> next = approach_2(curr);
        return head;
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        // return approach_1(head);

        return approach_2(head);
    }
};
// https://leetcode.com/problems/partition-list/



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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallPtr = small;
        ListNode* large = new ListNode(0);
        ListNode* largePtr = large;

        while(head != NULL) {
            if(head -> val < x) {
                smallPtr -> next = head;
                smallPtr = smallPtr -> next;

            } else {
                largePtr -> next = head;
                largePtr = largePtr -> next;
            }
            head = head -> next;
        }

        smallPtr -> next = large -> next;
        largePtr -> next = NULL;

        return small -> next;
    }
};
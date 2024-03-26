// https://leetcode.com/problems/intersection-of-two-linked-lists/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len ++;
            head = head -> next;
        }
        return len;
    }

    // TC : O(N + M) Where N = length of LL-1 & M = length of LL-2
    // SC : O(1)
    ListNode* solve_1(ListNode* headA, ListNode* headB) {
                int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = abs(lenA - lenB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if (lenA > lenB) {
            int k = diff;
            while (k--) {
                tempA = tempA -> next;
            }
        }
        else {
            int k = diff;
            while (k--) {
                tempB = tempB -> next;
            }
        }

        while(tempA != tempB) {
            tempA = tempA -> next;
            tempB = tempB -> next;
            if (!tempA || !tempB)
                return NULL;
        }
        return tempA;
    }

    // TC : O(N + M) Where N = length of LL-1 & M = length of LL-2
    // SC : O(1)
    // Approach : if the 2nd pointer of smaller length becomes null then switch it to the head of A
    ListNode* solve_2(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB) {
            tempA = tempA == NULL ? headB : tempA -> next;
            tempB = tempB == NULL ? headA : tempB -> next;
        }
        return tempA;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return solve_1(headA, headB);

        return solve_2(headA, headB);       // POINTER SWITCHING 
    }
};
// https://leetcode.com/problems/middle-of-the-linked-list/



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
    ListNode* approach_1(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        
        while (temp != NULL) {
            cnt ++;
            temp = temp -> next;
        }

        temp = head;
        int len = cnt / 2;

        for (int i = 0; i < len; i++) {
            if (temp -> next != NULL)
                temp = temp -> next;
        }
        return temp;
    }

    // TC : O(N)
    ListNode* approach_2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast -> next != NULL)
                fast = fast -> next;
        }
        return slow;
    }
public:
    ListNode* middleNode(ListNode* head) {
        // return approach_1(head);

        return approach_2(head);
    }
};
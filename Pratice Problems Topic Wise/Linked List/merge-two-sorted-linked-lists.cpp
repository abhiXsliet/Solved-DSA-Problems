// https://leetcode.com/problems/merge-two-sorted-lists/



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
    // ITERATIVE : Try to put the nodes from one LL to other
    // TC : O(N + M)
    // SC : O(1)
    ListNode* solve_1(ListNode* list1, ListNode* list2) {
        if (list1 -> next == NULL) {
            list1 -> next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = list1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = list2 -> next;

        while (list1 -> next != NULL && curr2 != NULL) {
            if ((curr2 -> val >= curr1 -> val) && (curr2 -> val <= next1 -> val)) {
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else {
                // shift the poistion in list1
                curr1 = next1;
                next1 = next1 -> next;

                if (next1 == NULL) {
                    curr1 -> next = curr2;
                    return list1;
                }
            }
        }

        return list1;
    }

    // TC : O(M + N)
    // SC : O(M + N)
    ListNode* solve_approach_2(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1 -> val <= list2 -> val) {
            list1 -> next = solve_approach_2(list1 -> next, list2);
            return list1;
        }
        else {
            list2 -> next = solve_approach_2(list1, list2 -> next);
            return list2;
        }
    }

    ListNode* solve_approach_1(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1 -> val <= list2 -> val) {
            return solve_1(list1, list2);
        }
        else return solve_1(list2, list1);
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // return solve_approach_1(list1, list2);

        return solve_approach_2(list1, list2);
    }
};
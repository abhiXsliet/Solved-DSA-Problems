// https://leetcode.com/problems/merge-in-between-linked-lists/



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
    // TC : O(M + N) Where M = list1 length & N = list2 length
    // SC : O(1)
    ListNode* solve_1(ListNode* list1, ListNode* list2, int a, int b) {
        ListNode* prev = list1;
        ListNode* forw = list1;

        for (int i = 1; i < a; i++) {
            prev = prev -> next;
        }

        for (int i = 0; i < b; i++) {
            forw = forw -> next;
        }

        ListNode* temp = list2;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        prev -> next = list2;
        temp -> next = forw -> next;
        forw -> next = NULL;
        return list1;
    }
    
    // TC : O(M + N)
    // SC : O(1)
    ListNode* solve_2(ListNode* list1, ListNode* list2, int a, int b) {
        ListNode* prev = list1;
        ListNode* forw = list1;

        for (int i = 1; i <= b; i++) {
            if (i < a) 
                prev = prev -> next;
            forw = forw -> next;
        }

        prev -> next = list2;
        while(prev -> next) {
            prev = prev -> next;
        }

        prev -> next = forw -> next;
        forw -> next = NULL;
        return list1;
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // return solve_1(list1, list2, a, b);

        return solve_2(list1, list2, a, b);
    }
};
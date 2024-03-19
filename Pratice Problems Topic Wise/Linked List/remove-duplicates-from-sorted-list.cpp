// https://leetcode.com/problems/remove-duplicates-from-sorted-list/



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
    // SC : O(N) Where N = Length of the given linked list
    ListNode* solve_approach_1(ListNode* head) {
        set<int> st;
        ListNode* temp = head;
        
        while (temp != NULL) {
            st.insert(temp -> val);
            temp = temp -> next;
        }
        
        ListNode* dummy   = new ListNode(0);
        ListNode* current = dummy;
        
        for(int val : st) {
            ListNode* newNode = new ListNode(val);
            current -> next   = newNode;
            current = current -> next;
        }
        return dummy -> next;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return solve_approach_1(head);
    }
};
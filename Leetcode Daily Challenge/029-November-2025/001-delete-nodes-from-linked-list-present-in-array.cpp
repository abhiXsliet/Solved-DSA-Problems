// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/




#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->next = NULL;
        this->val = val;
    }
};

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        // Remove leading nodes
        while (head && st.count(head->val)) {
            head = head->next; // no delete
        }

        ListNode* curr = head;

        // Remove remaining nodes
        while (curr && curr->next) {
            if (st.count(curr->next->val)) {
                curr->next = curr->next->next; // skip the node
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
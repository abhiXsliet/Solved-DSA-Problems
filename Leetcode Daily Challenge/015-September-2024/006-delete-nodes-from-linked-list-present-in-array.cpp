// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/



#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // TC : O(N + M) Where N = nums.size() and M = No. of nodes of LL
    // SC : O(N)
    ListNode* way_1(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        ListNode* curr = NULL;
        ListNode* forw = head;

        while (curr == NULL && st.count(forw -> val)) {
            head = head -> next;
            forw = head;
        }

        while (forw && !st.count(forw -> val)) {
            curr = forw;
            forw = forw -> next;

            while (forw && st.count(forw -> val)) {
                if (forw -> next) {
                    curr -> next = forw -> next;
                    forw -> next = NULL;
                    forw = curr -> next;
                } else {
                    forw = NULL;
                    curr -> next = NULL;
                }
            } 
        }

        return head;
    }

    // TC : O(N + M) Where N = nums.size() and M = No. of Nodes of LL
    // SC : O(N)
    ListNode* way_2(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        while (st.count(head -> val)) { // deleting intial nodes
            ListNode* temp = head;
            head = head -> next;
            delete (temp);
        }

        ListNode* curr = head;

        while (curr && curr -> next) {
            if (st.count(curr -> next -> val)) {
                ListNode* temp = curr -> next;
                curr -> next = curr -> next -> next;
                delete (temp);
            } else {
                curr = curr -> next;
            }
        }

        return head;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // return way_1(nums, head);

        return way_2(nums, head);   // one pointer and removed dangling nodes
    }
};
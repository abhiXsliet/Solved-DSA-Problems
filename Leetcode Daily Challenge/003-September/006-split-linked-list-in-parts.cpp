// https://leetcode.com/problems/split-linked-list-in-parts/



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
    // TC = O(N)
    // SC = O(K)
    vector<ListNode*> solve(ListNode* head, int k) {
        ListNode* curr = head;
        int length = 0;
        while(curr) {
            length++;
            curr = curr -> next;
        }

        int eachBucketNodes = length / k;
        int remainderNodes  = length % k;
        
        curr = head;
        ListNode* prev = NULL;
        vector<ListNode*> ans(k, NULL);

        for (int i = 0; i < k && curr; i++) {
            ans[i] = curr;

            for (int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = NULL;
            remainderNodes--;
        }

        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        return solve(head, k);

    }
};
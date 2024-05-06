// https://leetcode.com/problems/remove-nodes-from-linked-list/



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
    // SC : O(N)
    ListNode* approach_1(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* curr = head;
        while(curr) {
            stk.push(curr);
            curr = curr -> next;
        }

        ListNode* resHead = stk.top();
        ListNode* maxNode = stk.top();
        stk.pop();

        while(!stk.empty()) {
            ListNode* curr = stk.top();
            stk.pop();
            if (curr -> val < maxNode -> val) { // skip this node
                continue;
            }
            else {
                ListNode* newNode = new ListNode(curr -> val);
                newNode -> next   = resHead;
                resHead = newNode;
                maxNode = newNode;
            }
        }

        return resHead;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    ListNode* approach_2(ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode* nextNode = approach_2(head -> next);

        if (head -> val < nextNode -> val) {
            delete head;
            return nextNode;
        }

        head -> next = nextNode;
        return head;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* fowd = curr -> next;
            curr -> next   = prev;
            prev           = curr;
            curr           = fowd;
        }
        return prev;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_3(ListNode* head) {
        head = reverse(head);
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        int maxN = -1;

        while(curr) {
            maxN = max(maxN, curr -> val);
            if (curr -> val < maxN) {
                prev -> next   = curr -> next;
                ListNode* temp = curr;
                curr = curr -> next;
                delete (temp);
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return reverse(head);
    }
public:
    ListNode* removeNodes(ListNode* head) {
        // return approach_1(head);     // Creating New LL

        // return approach_2(head);     // Modifying original LL

        return approach_3(head);
    }
};
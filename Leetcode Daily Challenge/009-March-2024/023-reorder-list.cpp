// https://leetcode.com/problems/reorder-list/



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
    // SC : O(N) Where N = No. of Nodes
    void brute(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        while(temp != NULL) {
            store.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = store.size();
        temp = head;
        for (int i = n - 1; i > n/2; i--) {
            ListNode* nextNod = temp -> next;
            ListNode* newNode = new ListNode(store[i]);
            temp    -> next   = newNode;
            newNode -> next   = nextNod;
            temp              = temp -> next -> next;
        }
        if (n % 2) 
            temp -> next = NULL;
        else 
            temp -> next -> next = NULL;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head -> next) 
            return head;

        ListNode* last = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return last;
    }

    // TC : O(N)
    // SC : O(N)
    void better_1(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* temp = head;
        while(temp) {
            stk.push(temp);
            temp = temp -> next;
        }   
        
        temp = head;
        int n = stk.size();
        int k = n / 2;

        while (k--) {
            ListNode* topNode  = stk.top(); stk.pop();
            ListNode* nextNode = temp -> next;
            temp -> next       = topNode;
            topNode -> next    = nextNode;
            temp               = temp -> next -> next;
        }

        if (n % 2)
            temp -> next = NULL;
        else 
            temp -> next -> next = NULL;
    }

    // TC : O(N)
    // SC : O(1)
    void better_2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev = slow;
        slow = slow -> next;
        prev -> next = NULL;

        ListNode* revNode = reverse(slow);
        ListNode* temp    = head;
       
        while(temp && revNode) {
            ListNode* nextNod = temp -> next;
            
            temp -> next      = revNode;
            temp              = temp -> next;
            revNode           = revNode -> next;
            
            temp -> next      = nextNod;
            temp              = temp -> next;
        }
    }

    // TC : O(N)
    // SC : O(1)
    void optimal(ListNode* head, ListNode* &curr) {
        if (!head) return;

        optimal(head -> next, curr);
        
        ListNode* nextNode = curr -> next;
        
        if (curr -> next == NULL) return;
        else if (head == curr) {
            head -> next = NULL;
            return;
        }
        curr -> next       = head;
        head -> next       = (nextNode == head) ? NULL : nextNode;
        curr               = nextNode;
    }
public:
    void reorderList(ListNode* head) {
        // brute(head);

        // better_1(head);

        // better_2(head);

        optimal(head, head);
    }
};
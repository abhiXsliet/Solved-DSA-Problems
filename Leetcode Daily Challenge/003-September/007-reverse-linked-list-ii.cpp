// https://leetcode.com/problems/reverse-linked-list-ii/


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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr) {
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    // TC = O(N), SC = O(1)
    ListNode* solve_approach_1(ListNode* &head, int left, int right) {
        
        if (head == NULL || head -> next == NULL) return head;
        if (left == right) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        
        int cnt = 1;
        ListNode* leftNode        = NULL; 
        ListNode* beforeLeftNode  = NULL; 
        ListNode* afterRightNode  = NULL; 

        // assign above pointer with nodes
        while(temp) {
            prev = temp;
            temp = temp -> next;
            cnt++;
            if (cnt == left) {
                beforeLeftNode = prev;
                leftNode       = temp;

            } else if (left == 1) {
                beforeLeftNode = head;
            }
            if (cnt == right) {
                afterRightNode    = temp -> next;
                temp -> next = NULL;
            }
        }
        
        // reverse the nodes from left to right
        ListNode* reversedNodes = NULL; 
        if(left > 1) {
            reversedNodes = reverse(leftNode);
            beforeLeftNode -> next = reversedNodes;
        }
        else if(left == 1) {
            reversedNodes = reverse(beforeLeftNode);
            head          = reversedNodes;
        }
        
        // handle after nodes of right and connect it with reversed nodes
        temp = head;
        while(temp -> next) {
            temp = temp -> next;
        }
        temp -> next = afterRightNode;
        
        return head;
    }

    // TC = O(N), SC = O(1)
    ListNode* solve_approach_2(ListNode* &head, int left, int right) {
        if (head == NULL || head -> next == NULL) 
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev -> next;
        }

        ListNode* curr = prev -> next;

        for (int i = 1; i <= right - left; i++) {
            ListNode* temp       = prev -> next;
            prev -> next         = curr -> next;
            curr -> next         = curr -> next -> next;
            prev -> next -> next = temp;
        }

        return dummy -> next;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // return solve_approach_1(head, left, right);

        return solve_approach_2(head, left, right);
    }
};
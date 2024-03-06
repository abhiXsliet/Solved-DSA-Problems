// https://leetcode.com/problems/linked-list-cycle/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  
private:
    // TC = O(N)
    // SC = O(N)
    bool solve(ListNode* head) {
        unordered_map<ListNode*, bool> visited;

        if (head == NULL) 
            return false;

        ListNode* temp = head;
        while(temp != NULL) {
            if(visited[temp]) 
                return true;

            visited[temp] = 1;

            temp = temp -> next;
        }
        return false;
    }

    // TC = O(N)
    // SC = O(1)
    // Floyd Cycle Detection Algo
    bool solve_optimal(ListNode* head) {
        if(head == NULL) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        if(slow -> next == NULL || fast -> next == NULL) 
            return false;

        while(slow != NULL && fast != NULL) {
            fast = fast -> next;

            if (fast != NULL) 
                fast = fast -> next;

            if (slow == fast){
                // cout << slow -> val << endl;
                return true;
            } 
            
            slow = slow -> next;
        }
        return false;
    }

    
public:
    bool hasCycle(ListNode *head) {
        // return solve(head);

        return solve_optimal(head);
    }
};
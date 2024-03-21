// https://leetcode.com/problems/reverse-linked-list/



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
    // SC : O(N) -> Recursive Depth
    ListNode* solve_approach_1(ListNode* head) {
        //base case
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        //recursive call
        ListNode* chotaList = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return chotaList;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* solve_approach_2(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;
        else {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* forw = head -> next;

            while (curr != NULL) {
                forw = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return solve_approach_1(head);   // RECURSIVE

        return solve_approach_2(head);   // ITERATIVE
    }
};
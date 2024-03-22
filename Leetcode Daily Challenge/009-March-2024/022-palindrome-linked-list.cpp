// https://leetcode.com/problems/palindrome-linked-list/



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
    bool solve_brute(ListNode* head) {
        if (!head) return true;
        vector<int> store;
        while(head != NULL) {
            store.push_back(head -> val);
            head = head -> next;
        }

        int n = store.size();
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            if (store[i] == store[j]) {
                i ++;
                j --;
            }
            else return false;
        }
        return true;
    }

    int getLen(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len ++;
            head = head -> next;
        }
        return len;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        
        return prev;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_better_1(ListNode* head) {
        int len = getLen(head);

        if (len == 1) return head;

        int n = (len + 1)/2;
        
        ListNode* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp -> next;
        }   
        // reverse the nodes from the temp to nullptr
        ListNode* reversed = reverse(temp);

        temp = head;
        for (int i = 0; i < n - 1; i++) {
            temp = temp -> next;
        }
        temp -> next = reversed;

        ListNode* p1 = head;
        ListNode* p2 = head;

        for (int i = 0; i < n; i++) {
            p2 = p2 -> next;
        }

        for (int i = 0; i < n; i++) {
            if (p1 && p2 && p1 -> val == p2 -> val) {
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            else if (!p2) return true;
            else return false;
        }

        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_better_2(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast -> next) {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = NULL;

        // reverse the nodes from the slow to nullptr
        ListNode* tail = reverse(slow);

        while (head && tail) {
            if (head -> val != tail -> val)
                return false;
            head = head -> next;
            tail = tail -> next;
        }
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_optimal_1(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // REVERSE : FIRST HALF TILL MID
        while(fast && fast -> next) {
            fast = fast -> next -> next;

            ListNode* temp = slow -> next;
            slow -> next   = prev;
            prev = slow;
            slow = temp;
        }
        if (fast) { // odd case 
            slow = slow -> next;
        }
        while (prev && slow) {
            if (prev -> val != slow -> val)
                return false;
            prev = prev -> next;
            slow = slow -> next;
        }
        return true;
    }

    // TC : O(N)
    // SC : O(Recursive Depth)
    bool solve_optimal_2(ListNode* head, ListNode* &start) {
        if (!head) return true;

        bool ans = solve_optimal_2(head -> next, start);
        
        if (head -> val != start -> val)
            return false;
        start = start -> next;

        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        // return solve_brute(head);

        // return solve_better_1(head);

        // return solve_better_2(head);

        // return solve_optimal_1(head);        // No need to call REVERSE fn

        return solve_optimal_2(head, head);     // No Modification in given LL
    }
};
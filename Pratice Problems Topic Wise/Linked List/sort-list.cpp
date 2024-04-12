// https://leetcode.com/problems/sort-list/



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
    // TC : O(N*log(N))
    // SC : O(N) Where N = length of the given linked list
    ListNode* solve_approach_1(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        while(temp != NULL) {
            store.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(begin(store), end(store));

        ListNode* dummy   = new ListNode(0);
        ListNode* current = dummy;
        
        for(auto& i : store) {
            ListNode* newNode = new ListNode(i);
            current -> next = newNode;
            current = current -> next;
        }
        return dummy -> next;
    }
    
    ListNode* getMiddle(ListNode* &head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    // TC : O(N1 + N2) Where N1 = length of left  list
    // SC : O(N1 + N2) Where N2 = length of right list 
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* temp = new ListNode(-1);
        ListNode* merged = temp;
        while(left != NULL && right != NULL) {
            if (left -> val < right -> val) {
                temp -> next = new ListNode(left -> val);
                left = left -> next;
            }
            else {
                temp -> next = new ListNode(right -> val);
                right = right -> next;
            }
            temp = temp -> next;
        }
        while(left != NULL) {
            temp -> next = new ListNode(left -> val);
            left = left -> next;
            temp = temp -> next;
        }
        while(right != NULL) {
            temp -> next = new ListNode(right -> val);
            right  = right -> next;
            temp = temp -> next;
        }
        return merged -> next;
    }


    // The double pointer-to-pointer `current` manages the next pointer of the node in the merged list, 
    // enabling efficient updates to next pointers, in-place modifications of LL without node creation, 
    // ans achieving a SC of O(1) for the merge operation.
    // TC : O(N1 + N2) => O(N)
    // SC : O(1)
    ListNode* merge(ListNode* &left, ListNode* &right) {
        ListNode* mergedList = NULL;
        ListNode** current = &mergedList;

        while(left != NULL && right != NULL) {
            if(left -> val <= right -> val) {
                *current = left;
                left = left -> next;
            }else {
                *current = right;
                right = right -> next;
            }
            current = &((*current) -> next);
        }

        if(left != NULL) {
            *current = left;
            left = left -> next;
        } 
        if(right != NULL) {
            *current = right;
            right = right -> next;
        }

        return mergedList;
    }

    // TC : O(N * log(N))
    // SC : O(log(N)) due to maximum depth of recursive calls stack
    ListNode* mergeSort(ListNode* &head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode* middle = getMiddle(head);
        ListNode* middleNext = middle -> next;
        middle -> next =  NULL;

        ListNode* left  = mergeSort(head);
        ListNode* right = mergeSort(middleNext);

        // return (mergeList(left, right)); // SC : O(N1 + N2)
        return (merge(left, right));      // SC : O(1)
    }
public:
    ListNode* sortList(ListNode* head) {
        // return solve_approach_1(head);

        return mergeSort(head);      // MERGE SORT
    }
};
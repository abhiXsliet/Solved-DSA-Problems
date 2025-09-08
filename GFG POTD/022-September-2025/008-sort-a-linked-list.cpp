// https://www.geeksforgeeks.org/problems/sort-a-linked-list/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    // Merge two sorted lists
    Node* merge(Node* l1, Node* l2) {
        Node dummy(-1);
        Node* tail = &dummy;

        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        else    tail->next = l2;

        return dummy.next;
    }

    // Find middle of list
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next; // fast one step ahead

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

  public:
    // TC : O(N * log(N))
    // SC : O(log(N)) Recursive call stack
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        // split list
        Node* mid   = getMid(head);
        Node* right = mid->next;
        mid -> next = NULL;

        Node* left = mergeSort(head);
        right = mergeSort(right);

        // merge sorted halves
        return merge(left, right);
    }
};
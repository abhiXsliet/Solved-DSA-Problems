// https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    Node* approach_1(Node* head, int k) {
        Node* temp1  = head;
        Node* temp2  = head;
        int nodesCnt = 1;
        
        while (temp2 -> next && temp2 -> next -> next) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next -> next;
            nodesCnt += 2;
        }
        
        if (temp2 -> next) nodesCnt += 1;
        if (k > nodesCnt) return head;

        temp2 = temp1;
        int midPosition = (nodesCnt + 1) / 2;
        if (k >= midPosition) k = (nodesCnt + 1 - k);
        
        int reqMoves    = (nodesCnt + 1 - k);
        int remainMoves = (reqMoves - midPosition);
        // move to the kth nodes from the back
        while (temp2 -> next && remainMoves --) temp2 = temp2 -> next;
        
        int cnt = k;
        temp1 = head;
        // move to the kth node from the start
        while (temp1 -> next && cnt -- > 1) temp1 = temp1 -> next;
        
        swap(temp1 -> data , temp2 -> data);
        return head;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_2(Node* head, int k) {
        Node* curr   = head;
        Node* first  = NULL;
        Node* second = head;
        int cnt = 1;
        
        while (curr) {
            if (cnt == k) first  = curr;
            if (cnt  > k) second = second -> next;
            
            curr = curr -> next;
            cnt += 1;
        }
        
        if (!first) return head;    // k > nodesCnt
        
        swap(first -> data, second -> data);
        return head;
    }
  public:
    Node* swapKth(Node* head, int k) {
        // return approach_1(head, k);
        return approach_2(head, k);     // single traversal
    }
};
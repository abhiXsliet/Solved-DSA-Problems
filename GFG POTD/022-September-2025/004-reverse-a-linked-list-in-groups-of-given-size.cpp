// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1/




#include <bits/stdc++.h>
using namespace std;

// Node is defined as
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  private:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    Node* getKthNode(Node* head, int k) {
        Node* temp = head;
        for (int i = 1; i < k && temp; i ++) {
            temp = temp -> next;
        }
        return temp;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_1(Node* head, int k) {
        Node* temp = head, *prev = NULL;
        while (temp) {
            Node* kthNode = getKthNode(temp, k);
            
            if (!kthNode) {
                if (prev) prev -> next = reverse(temp); 
                break;
            } 
            
            Node* nextNode = kthNode -> next;   // preserve next node
            kthNode -> next = NULL;             // break link to reverse k-nodes
            
            reverse(temp);
            
            if (temp == head) {     // first reversal
                head = kthNode;
            } else {
                prev -> next = kthNode;
            }
            
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
    
    // TC : O(N)
    // SC : O(N - k) Recursive Stack Space
    Node* approach_2(Node* head, int k) {
        if (!head || !head -> next) return head;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;
        
        int count  = k;
        while (curr && count --) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        
        if (forw) {
            head -> next = approach_2(forw, k);
        }
        
        return prev;
    }
  public:
    Node *reverseKGroup(Node *head, int k) {
        // return approach_1(head, k);  // Iterative
        return approach_2(head, k);  // Recursive
    }
};
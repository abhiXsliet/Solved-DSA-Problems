// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1/




#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
    Node (int x) {
        data = x;
        next = NULL;
        prev = NULL;
    } 
};

class Solution{
    public:
    // TC : O(N)
    // SC : O(1)
    Node* reverse(Node *head) {
        Node* prevN = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* nextN = curr -> next;
            curr -> next = prevN;
            curr -> prev = nextN;
            
            // update the prev and curr
            prevN = curr;
            curr = nextN;
        }
        
        // update the head
        head = prevN;
        
        return head;
    }
};



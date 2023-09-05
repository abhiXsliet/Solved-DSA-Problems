// https://leetcode.com/problems/copy-list-with-random-pointer/


#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    // TC = O(N)
    // SC = O(N) where N is the no.s of nodes
    Node* solve(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mpp;

        Node* newHead = NULL;
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* temp = new Node(curr -> val);
            // store new nodes repective of their old nodes
            mpp[curr] = temp; 

            if (newHead == NULL) 
                newHead = temp;
            else 
                prev -> next = temp;
        
            prev = temp;
            curr = curr -> next;
        }

        curr = head;
        Node* newCurr = newHead;
        while (curr) {
            if (curr -> random == NULL) 
                newCurr -> random = NULL;
            else 
                newCurr -> random = mpp[curr -> random];

            curr    = curr -> next;
            newCurr = newCurr -> next;
        }

        return newHead;
    }

    // TC = O(N)
    // SC = O(N) to return ans but extra-space is O(1)
    Node* solve_optimal(Node* head) {
        if (head == NULL) return NULL;

        // Step-1 : Create new Nodes and insert b/w origin LL
        Node* curr = head;
        while (curr) {
            Node* currNext = curr -> next;          
            curr -> next   = new Node(curr -> val); // A -> x -> B ->
            curr -> next -> next = currNext;

            curr = currNext;
        }

        // Step-2 : Deep Copy Random Pointers
        curr = head;
        while (curr && curr -> next) {
            
            if (curr -> random == NULL)
                curr -> next -> random = NULL;
            else 
                curr -> next -> random = curr -> random -> next;

            curr = curr -> next -> next;
        }

        // Step-3 : Separate the LL
        Node* newHead = head -> next;
        Node* newCurr = newHead;
        curr = head;

        while (curr && newCurr) {
            curr -> next = curr -> next == NULL ? NULL : curr -> next -> next;

            newCurr -> next = newCurr -> next == NULL ? NULL : newCurr -> next -> next;

            curr    = curr -> next;
            newCurr = newCurr -> next;
        }
        return newHead;
    }
public:
    Node* copyRandomList(Node* head) {
        // return solve(head);

        return solve_optimal(head);
    }
};
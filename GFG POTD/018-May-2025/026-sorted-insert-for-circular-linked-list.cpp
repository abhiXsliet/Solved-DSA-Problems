// https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1




#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int d) {
        if(head == NULL) {
            Node* newNode = new Node(d);
            return newNode -> next = newNode;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        
        if (head -> data <= d) {
            while (curr -> data <= d) {
                prev = curr;
                curr = curr -> next;
                if (curr == head) 
                    break;
            }
            
            Node* nodeToInsert = new Node(d);
            prev -> next = nodeToInsert;
            nodeToInsert -> next = curr;
        }
        else if (head -> data > d) {
            Node* nodeToInsert = new Node(d);
            prev = nodeToInsert;
            prev -> next = curr;
            
            while(curr -> next != head) {
                curr = curr -> next;
            }
            
            curr -> next = prev;
            head = prev;
        }
        return head;
    }
};
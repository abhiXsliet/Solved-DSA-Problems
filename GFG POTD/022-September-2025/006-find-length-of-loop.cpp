// https://www.geeksforgeeks.org/problems/find-length-of-loop/1/




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
  public:
    // TC : O(N)
    // SC : O(1)
    int lengthOfLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (fast == slow) {
                int cycleNodes = 1;
                slow = slow -> next;
                while (slow != fast) {
                    slow = slow -> next;
                    cycleNodes += 1;
                }
                return cycleNodes;
            }
        }
        
        return 0;
    }
};
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1/




#include <bits/stdc++.h>
using namespace std;

//  Node is defined as
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    Node* approach_1(Node* head) {
        int cnt[3] = {0};
        Node* temp = head;
        
        while(temp) {
            cnt[temp -> data] ++;
            temp = temp -> next;
        }
        
        temp = head;
        int i = 0;
        
        while (1) {
            while (temp && cnt[i] --) {
                temp -> data = i;
                temp = temp -> next;
            }
            i ++;
            if (i == 3) break;
        }
        
        return head;
    }
  public:
    Node* segregate(Node* head) {
        return approach_1(head);
    }
};
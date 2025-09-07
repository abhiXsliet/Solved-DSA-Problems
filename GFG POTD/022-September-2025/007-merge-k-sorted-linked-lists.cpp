// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/




#include <bits/stdc++.h>
using namespace std;
 
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    Node* approach_1(vector<Node*> &arr) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (Node* head : arr) {
            Node* temp = head;
            while (temp) {
                pq.push(temp -> data);
                temp = temp -> next;
            }
        }
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while (!pq.empty()) {
            temp -> next = new Node(pq.top());
            temp = temp -> next;
            pq.pop();
        }
        
        return dummy -> next;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    Node* approach_2(vector<Node*> &arr) {
        auto cmp = [&](Node* a, Node* b) {
            return a -> data > b -> data;  
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        for (Node* v : arr) {
            if (v != NULL) {
                pq.push(v);
            }
        }
        
        Node* head = NULL, *temp = NULL;
        
        while (!pq.empty()) {
            Node* topN = pq.top();
            pq.pop();
            
            if (topN -> next) pq.push(topN -> next);
            
            if (!head) {
                head = topN;
                temp = head;
            } else {
                temp -> next = topN;
                temp = temp -> next;
            }
        }
        
        return head;
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};
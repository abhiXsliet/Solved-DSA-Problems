// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1



//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
// } Driver Code Ends

/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

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
    // SC : O(N) Recursive Stack Space
    Node* approach_2(Node* head, int k) {
        if (!head || !head -> next) return head;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;
        
        // Reverse first k group
        int count  = k;
        while (curr && count --) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        
        // Rest k group will reversed by recursion
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
//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
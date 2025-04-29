// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    Node* approach_1(Node* head) {
        int zeros = 0, ones = 0, twos = 0;
        Node* temp = head;
        while (temp) {
            if (temp -> data == 0) zeros += 1;
            else if (temp -> data == 1) ones += 1;
            else twos += 1;
            temp = temp -> next;
        }
        
        Node* dummy = new Node(-1);
        temp = dummy;
        while (zeros --) {
            temp -> next = new Node(0);
            temp = temp -> next; 
        }
        while (ones --) {
            temp -> next = new Node(1);
            temp = temp -> next; 
        }
        while (twos --) {
            temp -> next = new Node(2);
            temp = temp -> next; 
        }
        return dummy -> next;       
    }
  public:
    Node* segregate(Node* head) {
        return approach_1(head); // cnt 0, 1, 2s or make an array of len-3
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
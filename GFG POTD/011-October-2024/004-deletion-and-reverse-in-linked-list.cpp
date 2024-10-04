// https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}
// } Driver Code Ends

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        Node* tail = head;
    
        // Iterate until we reach back to head
        do {
            next = curr -> next;  // Store the next node
            curr -> next = prev;  // Reverse the current node's pointer
            prev = curr;          // Move prev to current
            curr = next;          // Move to next node
        } while (curr != head);
    
        // After the loop, prev is the new head
        // Set the last node's next pointer to the new head
        tail -> next = prev;
    
        return prev; // Return new head
    }
    
    // TC : O(N)
    // SC : O(N)
    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node *prev = NULL, *curr = head;

        // If the node to delete is the head
        if (curr -> data == key) {

            // Find the last node
            while (curr -> next != head) {
                curr = curr -> next;
            }

            // Update head and tail
            curr -> next = head -> next;
            Node* toDelete = head;
            head = head -> next;
            delete toDelete;
            return head;
        }

        // Traverse the list to find the node to delete
        prev = head;
        curr = head->next;

        while (curr != head) {
            if (curr -> data == key) {
                prev -> next = curr -> next; // Bypass the node to delete
                delete curr; // Free memory
                return head; // Return unchanged head
            }
            prev = curr;
            curr = curr -> next;
        }

        return head; // Return unchanged head if key not found
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
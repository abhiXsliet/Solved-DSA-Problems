// https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if (!head -> next) return {head, NULL};
        
        Node* newH1 = head;
        Node* newH2 = head -> next;
        Node* temp1 = newH1;
        Node* temp2 = newH2;

        while(temp1 && temp1 -> next && temp2 && temp2 -> next) {
            temp1 -> next = temp1 -> next -> next;
            temp2 -> next = temp2 -> next -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        if (temp1) temp1 -> next = NULL;
        if (temp2) temp2 -> next = NULL;
        
        return {newH1, newH2};
    }
};


//{ Driver Code Starts.
void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}
// } Driver Code Ends
// https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
// } Driver Code Ends
// User function Template for C++

/* Linked List node structure
struct Node {
    int data;
    struct Node *next;
};
*/

class Solution {
  private: 
    void getNodes(Node* head, vector<int>& store) {
        while(head) {
            store.push_back(head -> data);
            head = head -> next;
        }
        vector<int> duplicateFree;
        int n = store.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && store[j] == store[i]) {
                j++;
            }
            if (j == i + 1) { // No duplicates for store[i]
                duplicateFree.push_back(store[i]);
            }
            i = j; // Move to the next new element
        }
        store = duplicateFree;
    }
    
    Node* buildLL(vector<int>& store) {
        if (store.empty()) return NULL;
        
        Node* head = new Node(store[0]);
        Node* temp = head;
        for (int i = 1; i < store.size(); i ++) {
            temp -> next = new Node(store[i]);
            temp = temp  -> next;
        }
        return head;
    }
    
    // TC : O(N)
    // SC : O(N)
    Node* approach_1(struct Node* head) {
        vector<int> store;
        getNodes(head, store);
        return buildLL(store);
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_2(struct Node* head) {
        if (!head -> next) return head;
        
        Node* dummy   = new Node(0);
        dummy -> next = head;
        Node* prev    = dummy;
        Node* curr    = head;
    
        while (curr != NULL && curr -> next != NULL) {
            if (curr -> data == curr -> next -> data) {
                int value = curr -> data;
                while (curr != NULL && curr -> data == value) {
                    curr = curr -> next;
                }
                prev -> next = curr;
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }

        return dummy -> next;
    }
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // return approach_1(head);
        
        return approach_2(head);
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
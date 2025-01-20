// https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  private:
    Node* solve(Node* first, Node* second) {
        if (!first -> next) {
            first -> next = second;
            return first;
        }
        
        Node* curr1 = first;
        Node* next1 = first -> next;
        Node* curr2 = second;
        Node* next2 = NULL;
        
        while (next1 && curr2) {
            // Adding a node in the middle of two nodes of first ll
            if ((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;
                
                curr1 = curr2;
                curr2 = next2;
            } else {    // move ahead in first ll 
                curr1 = next1;
                next1 = next1 -> next;
                if (!next1) {
                    curr1 -> next = curr2;
                    break;
                }
            }
        }
        return first;
    }
    
    // TC : O(M + N)
    // SC : O(1)
    // HINT : Try to put the nodes from one LL to other
    Node* approach_1(Node* head1, Node* head2) {
        if (head1 -> data <= head2 -> data) {
            return solve(head1, head2);
        }
        return solve(head2, head1);
    }
    
    // TC : O(M + N)
    // SC : O(1)
    Node* approach_2(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        
        if (head1 -> data <= head2 -> data) {
            head1 -> next  = approach_2(head1 -> next, head2);
            return head1;
        } // else
        head2 -> next  = approach_2(head1, head2 -> next);
        return head2;
    }
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // return approach_1(head1, head2);    // Iterative
        
        return approach_2(head1, head2);    // Recursive
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
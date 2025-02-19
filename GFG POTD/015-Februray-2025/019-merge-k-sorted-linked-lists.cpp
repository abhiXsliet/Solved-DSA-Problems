// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1




//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}
// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  private:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a -> data > b -> data;
        }  
    };
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        /*
                // syntax - 1
        auto cmp = [&](Node* a, Node* b) {
            return a -> data > b -> data;
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        */
    
        // syntax - 2
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        
        for (int i = 0; i < n; i ++) {
            if (arr[i] != NULL) {
                pq.push(arr[i]);
            }
        }
        
        Node* head = NULL;
        Node* temp = NULL;
        
        while (!pq.empty()) {
            Node* topN = pq.top();
            pq.pop();
            
            if (topN -> next) {
                pq.push(topN -> next);
            }
            
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
};
//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}
// } Driver Code Ends
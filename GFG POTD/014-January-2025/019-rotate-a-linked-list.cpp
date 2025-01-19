// https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1




//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
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
    int getLen(Node* head) {
        Node* temp = head;
        int cnt = 0;
        while (temp) {
            temp = temp -> next;
            cnt ++;
        }
        return cnt;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_1(Node* head, int k) {
        int len = getLen(head);
        if (len <= k) k %= len;
        if (k == 0) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 0;
        while (curr -> next && cnt != k) {
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }
        
        if (prev) prev -> next = NULL;
        
        Node* temp = curr;
        while (temp -> next) {
            temp = temp -> next;
        }
        temp -> next = head;
        return curr;
    }
    
    // TC : O(N)
    // SC : O(1)
    Node* approach_2(Node* head, int k) {
        if (!head || k == 0) return head;
        
        Node* curr = head;
        int len = 1;
        while (curr -> next) {
            curr = curr -> next;
            len += 1;
        }
        
        k %= len;
        if (k == 0) return head;
        
        curr -> next = head;    // make the list circular
        curr = head;
        for (int i = 1; i < k; i ++) {  // skip k-nodes
            curr = curr -> next;
        }

        head = curr -> next;
        curr -> next = NULL;
        return head;
    }
  public:
    Node* rotate(Node* head, int k) {
        // return approach_1(head, k);  // BRUTE
        return approach_2(head, k);  // Optimal : make the list circular
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}
// } Driver Code Ends
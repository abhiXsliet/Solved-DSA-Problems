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
    // TC : O(N)
    // SC : O(1)
    Node* brute(Node* head, int k) {
        int cnt = 1;
        Node* ptr = head;
        while (ptr -> next != NULL) {
            ptr = ptr -> next;
            cnt ++;
        }
        
        if (cnt == k) return head;
        
        Node* temp = head;
        Node* prev = NULL;
        while (k --) {
            prev = head;
            head = head -> next;
        }
        
        prev -> next = NULL;
        Node* temp_2 = head;
        while(temp_2 -> next != NULL) {
            temp_2 = temp_2 -> next;
        }
        temp_2 -> next = temp;
        return head;
    }
    
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        return brute(head, k);
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
    }
    return 1;
}
// } Driver Code Ends
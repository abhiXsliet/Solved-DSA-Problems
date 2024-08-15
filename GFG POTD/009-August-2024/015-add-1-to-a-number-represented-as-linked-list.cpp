// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1



//{ Driver Code Starts
// Initial template for C++
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
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}
// } Driver Code Ends
// User function template for C++

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
  private:
    Node* revList(Node* head) {
        if (!head || !head->next)
            return head;
        
        Node* newHead = revList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
  public:
    // TC : O(N)
    // SC : O(1)
    Node* addOne(Node* head) {
        int carry = 1;  
        Node* reversedLL = revList(head);
        Node* temp = reversedLL;
        
        while (temp) {
            int sum = carry + temp->data;
            carry   = sum / 10;
            temp -> data = sum % 10;
            
            if (!temp->next && carry > 0) {
                temp->next = new Node(carry);
                carry = 0;
            }
            temp = temp->next;
        }
        
        return revList(reversedLL);
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
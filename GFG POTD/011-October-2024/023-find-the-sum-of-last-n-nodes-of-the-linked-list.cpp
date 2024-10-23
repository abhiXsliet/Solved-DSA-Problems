// https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1



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

// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as
    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    
    // TC : O(N)
    // SC : O(N) Recursive Depth
    Node* reverse(Node* head) {
        if (!head || !head -> next) 
            return head;
        
        Node* newH = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return newH;
    }
    
    // TC : O(N)
    // SC : O(N) recursive call stack
    void solve(Node* head, int n, int &result, int &cnt) {
        if (head == NULL) return;

        solve(head -> next, n, result, cnt);
        cnt += 1;
        if (cnt <= n) result += head -> data;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(struct Node* head, int n) {
        Node* reversedHead = reverse(head);
        int sum = 0;
        int k = n;
        Node* temp = reversedHead;
        while (k -- && temp) {
            sum += temp -> data;
            temp = temp -> next;
        }
        return sum;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(struct Node* head, int n) {
        int result = 0;
        int cnt = 0;
        solve(head, n, result, cnt);
        return result;
    }
    
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // return approach_1(head, n);  // Reverse and sum till n nodes
        return approach_2(head, n);  // Recursive
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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
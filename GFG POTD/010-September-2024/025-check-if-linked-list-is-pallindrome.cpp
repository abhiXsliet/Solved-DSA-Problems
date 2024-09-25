// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1




//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
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
    Node* reverseIt(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    Node* reverseRe(Node* head) {
        if (!head || !head -> next)
            return head;
            
        Node* headN = reverseRe(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return headN;
    }
    
    // TC : O(N) Where N = No. of Nodes
    // SC : O(1)
    bool way_1(Node* head) {
        if (!head -> next) 
            return head;
        
        Node* prev = NULL;
        Node* slow = head;
        Node* fast = head;
        
        while (fast -> next && fast -> next -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if (fast -> next) { // Even nodes
            prev = slow;
            slow = slow -> next;
        } else {    // Odd Nodes
            slow = slow -> next;
        }
        
        prev -> next = NULL;
        Node* revH = reverseIt(head);   // Reversing Recursively

        while(revH && slow) {
            if (revH -> data != slow -> data) {
                return false;
            }
            revH = revH -> next;
            slow = slow -> next;
        }
        
        return true;
    }
    
    // TC : O(N)
    // SC : O(N) Recursive Depth
    bool way_2(Node* &h1, Node* h2) {
        if (!h2) return 1;
        
        bool ans = way_2(h1, h2 -> next);
        if (h1 -> data != h2 -> data)
            return false;
        h1 = h1 -> next;
        return ans;
    }
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // return way_1(head); // reversed first half and checked palindrome
        
        return way_2(head, head);   // Recursively : No Modification in LL
    }
};


//{ Driver Code Starts.
/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}
// } Driver Code Ends
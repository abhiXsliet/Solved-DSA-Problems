// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1




//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

vector<int> take() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

Node* inputList(int size, vector<int> v) {
    if (size == 0)
        return NULL;

    int val = v[0];

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  private:
    int getLen(Node* head) {
        Node* curr = head;
        int cnt = 0;
        while(curr) {
            curr = curr -> next;
            cnt += 1;
        }
        return cnt;
    }
    
    int getIntersection(Node* head1, Node* head2, int diff) {
        Node* curr1 = head1;
        Node* curr2 = head2;
        for (int i = 0; i < diff; i ++) {
            if (!curr1) return -1;
            curr1 = curr1 -> next;
        }
        
        while (curr1 && curr2) {
            if (curr1 == curr2) 
                return curr1 -> data;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        return -1;
    }
    
    // TC : O(M * N)
    // SC : O(1)
    int brute(Node* head1, Node* head2) {
        while (head2) {
            Node *temp = head1;
            while (temp) {
                // if both Nodes are same
                if (temp == head2)
                    return head2 -> data;
                temp = temp->next;
            }
            head2 = head2->next;
        }
          
        // intersection is not present between the lists
        return -1;
    }
    
    // TC : O(M + N)
    // SC : O(M + N)
    int better(Node* head1, Node* head2) {
        unordered_set<Node *> visitedNodes;
    
        // Traverse the first list and store all nodes in a set
        Node *curr1 = head1;
        while (curr1) {
            visitedNodes.insert(curr1);
            curr1 = curr1->next;
        }
    
        // Traverse the second list and check if any node is in the set
        Node *curr2 = head2;
        while (curr2) {
            if (visitedNodes.find(curr2) != visitedNodes.end()) {
                 // Intersection point found
                return curr2 -> data;
            }
            curr2 = curr2->next;
        }
    
        return -1;
    }
    
    // TC : O(M + N)
    // SC : O(1)
    int optimal_1(Node* head1, Node* head2) {
        int len1 = getLen(head1);
        int len2 = getLen(head2);
        
        if (len1 > len2) {
            int diff = len1 - len2;
            return getIntersection(head1, head2, diff);
        } else {
            int diff = len2 - len1;
            return getIntersection(head2, head1, diff);
        }
    }
    
    // TC : O(M + N)
    // SC : O(1)
    int optimal_2(Node* head1, Node* head2) {
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        if (!curr1 || !curr2) return -1;
        
        while (curr1 != curr2) {
            curr1 = curr1 ? curr1 -> next : head2;
            curr2 = curr2 ? curr2 -> next : head1;
        }
        
        return curr1 -> data;
    }
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // return brute(head1, head2);
        
        // return better(head1, head2); // HashMap to store LL1 then iterate on LL2 and find in HashMap
        
        // return optimal_1(head1, head2); // Find the D in LL1 & LL2: Iterate D in LL1/LL2 then Iterate in both 
        
        return optimal_2(head1, head2); // Iterate in both LL same time, if one ptr becomes NULL then point it to head again
    }
};


//{ Driver Code Starts.
/* Driver program to test above function*/
int main() {
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    cin.ignore();
    while (T--) {

        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1




//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int getLength(Node* head){
        int cnt = 0;  
 	    while(head != NULL) {
 	        head = head -> next;
 	        cnt ++;
 	    }
 	    return cnt;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    // TC : O(N + M)
    // SC : O(N + M) Where N & M are the length of the two ll respectively
    Node* subLinkedList(Node* h1, Node* h2) {
        //removing zeros
        while(h1 != NULL && h1 -> data == 0) h1 = h1 -> next;
        while(h2 != NULL && h2 -> data == 0) h2 = h2 -> next;
        
        //finding length of LL
        int s1 = getLength(h1), s2 = getLength(h2);
        
        if(s1 == 0 && s2 == 0) return new Node(0);
        
        //making l1 list size largest.
        if(s2 > s1){
            Node* temp = h1; h1 = h2; h2 = temp; //swap the list
        }
        if(s1 == s2){
            Node* curr1 = h1, *curr2=h2;
            while(curr1 -> data == curr2 -> data){
                curr1 = curr1 -> next; curr2 = curr2 -> next;
                
                //if reached end => both ll are same
                if(curr1 == NULL)
                    return new Node(0);
            }
            if(curr2 -> data > curr1 -> data){
                Node* temp = h1; h1 = h2; h2 = temp; //swap the list
            }
        }
        
        //reverse the list for subtraction
        h1 = reverse(h1); h2 = reverse(h2);
        Node* ans = NULL;
        
        while(h1 != NULL){
            int n1 = h1 -> data; int n2 = 0;
            if(h2 != NULL)  n2 = h2 -> data;
            
            if(n1 < n2){
                if(h1 -> next != NULL){
                    h1 -> next -> data -= 1;
                }
                n1 += 10;
            }
        
            //store the difference
            Node* curr = new Node(n1-n2);
            curr -> next = ans;
            ans = curr;
            
            h1 = h1 -> next;
            if(h2 != NULL)
                h2 = h2 -> next;
        }
            
        // remove zeros from end;
        while(ans != NULL && ans -> next != NULL )
        {
            if(ans -> data == 0){
               ans = ans -> next;
            }
            else break;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends